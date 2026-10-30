"""Unit tests for tools/regenerate: ssh is a fake that runs the "rig" as a directory on this machine, so the whole
flow takes seconds. Scratch directories live under the repository's ignored build/ folder, never /tmp."""
import importlib.machinery
import importlib.util
import os
import shutil
import subprocess
import tempfile
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
SCRIPT = os.path.join(ROOT, "tools", "regenerate")
SCRATCH = os.path.join(ROOT, "build")

FAKE_SSH = """#!/bin/sh
# ssh HOST COMMAND...: run COMMAND in the fake rig home.
shift
export HOME="$FAKE_RIG_HOME"
case "$*" in *"git archive"*) [ -n "$FAKE_COPY_FAIL" ] && { echo "ssh: connection unexpectedly closed" >&2; exit 255; };; esac
cd "$HOME" && exec sh -c "$*"
"""

FAKE_SLOT = """#!/bin/sh
# The rig's finish slot: record that the job ran in it, then run the job and pass its status through.
echo ran >> "$HOME/finish/slot.log"
exec "$@"
"""

CONFIG = """[rig]
host = "rig"
repo = "code/rig"
warm = "finish/regen/tree"
seed_tree = "code/seed"
seed_link = ["roms"]
slot = "~/finish/slot"
build = [%s]
"""


def git(cwd, *args):
    return subprocess.run(["git", *args], cwd=cwd, check=True, capture_output=True, text=True,
                          env=dict(os.environ, GIT_AUTHOR_NAME="t", GIT_AUTHOR_EMAIL="t@t",
                                   GIT_COMMITTER_NAME="t", GIT_COMMITTER_EMAIL="t@t")).stdout


def load_script():
    loader = importlib.machinery.SourceFileLoader("regenerate", SCRIPT)
    module = importlib.util.module_from_spec(importlib.util.spec_from_loader("regenerate", loader))
    loader.exec_module(module)
    return module


class Regenerate(unittest.TestCase):
    build = ('"mkdir -p build && echo run >> build/log", "printf \'built from %s\\n\' \\"$(cat src.txt)\\" > README.md", '
             '"echo state > docs/state.txt", "rm -f docs/gone.txt"')

    def setUp(self):
        os.makedirs(SCRATCH, exist_ok=True)
        self.dir = tempfile.mkdtemp(prefix="regenerate-test-", dir=SCRATCH)
        self.addCleanup(shutil.rmtree, self.dir, True)
        self.home = os.path.join(self.dir, "home")
        self.tree = os.path.join(self.dir, "tree")
        bin_dir = os.path.join(self.dir, "bin")
        for path in (bin_dir, os.path.join(self.home, "finish"), os.path.join(self.home, "code/seed/roms"),
                     self.tree + "/tools", self.tree + "/config/regenerate", self.tree + "/docs"):
            os.makedirs(path)
        for path, body in ((bin_dir + "/ssh", FAKE_SSH), (self.home + "/finish/slot", FAKE_SLOT)):
            with open(path, "w") as handle:
                handle.write(body)
            os.chmod(path, 0o755)
        git(self.home, "init", "-q", "code/rig")
        git(self.home + "/code/rig", "commit", "-q", "--allow-empty", "-m", "rig")
        shutil.copy(SCRIPT, self.tree + "/tools/regenerate")
        self.write("config/regenerate/rig.toml", CONFIG % self.build)
        self.write(".gitignore", "build/\n")
        self.write(".gitattributes",
                   "README.md generated=tools/regenerate\ndocs/** generated=tools/regenerate\n"
                   "keep.txt merge=union\n")
        self.write("src.txt", "one\n")
        self.write("README.md", "stale\n")
        self.write("docs/state.txt", "stale\n")
        self.write("docs/gone.txt", "no longer generated\n")
        git(self.tree, "init", "-q")
        git(self.tree, "add", "-A")
        git(self.tree, "commit", "-q", "-m", "base")
        self.env = dict(os.environ, PATH=bin_dir + ":" + os.environ["PATH"], FAKE_RIG_HOME=self.home)
        self.warm = self.home + "/finish/regen/tree"

    def write(self, name, text):
        path = os.path.join(self.tree, name)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w") as handle:
            handle.write(text)

    def read(self, name, base=None):
        with open(os.path.join(base or self.tree, name)) as handle:
            return handle.read()

    def regenerate(self, **extra):
        return subprocess.run([self.tree + "/tools/regenerate"], cwd=self.tree, capture_output=True,
                              text=True, env=dict(self.env, **extra))

    def test_ships_exact_state_and_copies_back_only_declared_paths(self):
        self.write("src.txt", "two\n")  # uncommitted edit must reach the rig
        self.write("untracked.txt", "kept\n")
        done = self.regenerate()
        self.assertEqual(done.returncode, 0, done.stderr)
        self.assertEqual(self.read("README.md"), "built from two\n")
        self.assertEqual(self.read("docs/state.txt"), "state\n")
        self.assertEqual(self.read("untracked.txt"), "kept\n")
        self.assertEqual(self.read("src.txt"), "two\n")
        self.assertFalse(os.path.exists(self.tree + "/docs/gone.txt"), "stale generated file survives")
        self.assertEqual(git(self.tree, "diff", "--cached", "--name-only"), "", "real index touched")
        self.assertEqual([n for n in os.listdir(self.tree) if n.startswith(".regenerate")], [])

    def test_the_warm_tree_is_reused_and_left_clean(self):
        self.assertEqual(self.regenerate().returncode, 0)
        self.write("src.txt", "two\n")
        done = self.regenerate()
        self.assertEqual(done.returncode, 0, done.stderr)
        self.assertEqual(self.read("README.md"), "built from two\n")
        self.assertEqual(self.read("build/log", self.warm), "run\nrun\n")  # one tree: its ignored build state stayed
        self.assertEqual(git(self.warm, "status", "--porcelain"), "")
        self.assertEqual(os.listdir(self.home + "/finish/regen"), ["tree", "tree.lock"])
        self.assertEqual(git(self.home + "/code/rig", "for-each-ref", "refs/regenerate"), "", "scratch ref left")

    def test_seed_is_linked_when_the_tree_is_created(self):
        self.write("config/regenerate/rig.toml", CONFIG % '"readlink roms > README.md", "echo ok > docs/state.txt"')
        self.assertEqual(self.regenerate().returncode, 0)
        self.assertEqual(self.read("README.md"), self.home + "/code/seed/roms\n")

    def test_build_failure_exits_nonzero_with_rig_message_and_writes_nothing(self):
        self.write("config/regenerate/rig.toml",
                   CONFIG % '"echo partial > README.md", "echo rig says no >&2; false"')
        done = self.regenerate()
        self.assertEqual(done.returncode, 1)
        self.assertIn("rig says no", done.stderr)
        self.assertEqual(self.read("README.md"), "stale\n")
        self.assertEqual(self.read("docs/gone.txt"), "no longer generated\n")
        self.assertEqual(git(self.warm, "status", "--porcelain"), "", "a failed build left the warm tree dirty")
        self.write("config/regenerate/rig.toml", CONFIG % self.build)  # and the next run still works
        self.assertEqual(self.regenerate().returncode, 0)
        self.assertEqual(self.read("README.md"), "built from one\n")

    def test_copy_back_failure_writes_nothing(self):
        done = self.regenerate(FAKE_COPY_FAIL="1")
        self.assertEqual(done.returncode, 1)
        self.assertIn("connection unexpectedly closed", done.stderr)
        self.assertEqual(self.read("README.md"), "stale\n")
        self.assertEqual(self.read("docs/state.txt"), "stale\n")

    def test_undeclared_tree_fails(self):
        self.write(".gitattributes", "keep.txt merge=union\n")
        done = self.regenerate()
        self.assertEqual(done.returncode, 1)
        self.assertIn("generated=tools/regenerate", done.stderr)

    def test_build_runs_inside_the_slot_and_its_failure_passes_through(self):
        self.assertEqual(self.regenerate().returncode, 0)
        self.assertEqual(self.read("finish/slot.log", self.home), "ran\n")
        self.write("config/regenerate/rig.toml", CONFIG % '"exit 7"')
        done = self.regenerate()
        self.assertEqual((done.returncode, "failed (7)" in done.stderr), (1, True))

    def test_slot_command_bound_and_message_tail(self):
        module = load_script()
        rig = {"slot": "~/finish/slot", "build": ["a", "b"], "warm": "w", "repo": "r", "seed_tree": "s"}
        self.assertTrue(module.build_command(rig, "c0ffee").startswith("~/finish/slot sh -c "))
        bounded = module.build_command(dict(rig, timeout_seconds=90), "c0ffee")
        self.assertTrue(bounded.startswith("~/finish/slot timeout 90 sh -c "))
        self.assertNotIn("timeout", module.build_command(rig, "c0ffee"))
        self.assertEqual(module.tail("\n".join(map(str, range(100))), 3), "...\n97\n98\n99")


if __name__ == "__main__":
    unittest.main()
