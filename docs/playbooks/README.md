# Playbooks

How this decompilation is worked, in four phases. Each playbook says what the phase is for, the measurement that ends
it, the order of attack, and the source rules that hold throughout. Numbers quoted here are examples taken when the
playbook was written; the current values are in the progress block of the README and in `progress.json`.

| Playbook | Phase | Ends when |
|---|---|---|
| [1-map-and-foundations](1-map-and-foundations.md) | Every ROM byte assigned; every function has C; the engine foundations are real, named C | ROM mapped 100%, every function has C, the foundation set matches and is named |
| [2-port-shell-and-oracle](2-port-shell-and-oracle.md) | A native build and a reference that replay the same controller input | Both replay a boot movie |
| [3-coverage-by-play](3-coverage-by-play.md) | One version, every reachable function executed and behaving like the original | Reachable function coverage 100%, no behaviour difference |
| [4-staged-releases](4-staged-releases.md) | Releases in stages, each gated by measured coverage | Each stage's thresholds hold |

Throughout every phase:

- **Real C, no cheating.** Shipped C is what the original programmers plausibly wrote. No inline assembly, `.word`,
  pragmas or section tricks in ROM-path C; a near miss stays under `NON_MATCHING` with its best body and a comment of
  how close it is. A match that only holds through a trick carries a `FAKEMATCH` comment and still counts as open.
- **One body serves both goals.** A function lands once, in its real file, as C that builds the original bytes (or,
  under `NON_MATCHING`, behaves like the original) and also compiles for the native port. There is never a port-only copy.
- **Clean names and structure.** Functions, globals, fields, locals and types get names from the evidence (debug
  symbols left in the cartridges, assertion strings, call context). Functions move to the file their evidence names.
- **us-rev1 first.** The revised NTSC release is the reference; a body is written so every version that holds the
  function builds from it, version differences behind `VERSION_*` conditions.
- `make check` stays green for all five versions after every change.
