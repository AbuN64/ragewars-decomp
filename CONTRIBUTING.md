# Contributing to Turok: Rage Wars

## Install

```sh
python3 -m pip install git+https://github.com/AbuN64/cake-unbake-64
```

## New project

Run these commands inside this repo.
Put your own ROM dumps at these paths.

- `roms/baserom.de.z64`
- `roms/baserom.eu.z64`
- `roms/baserom.eu-x.z64`
- `roms/baserom.us.z64`
- `roms/baserom.us-rev1.z64`

```sh
unbake setup
```

Setup shows compiler evidence and asks for one confirmation of the whole proposal.
Try measures compiler candidates and records exact equivalence.
It prints the policy path and names any missing input.
It checks every ROM before the project is ready.

```sh
make check
```

Plain `make` and `make check` cover every version.
Use `VERSION=<version>` to select one version.
Compiler files live in `tools`.
The Makefile verifies their SHA-256 hashes during installation.

## Next command

```sh
unbake map
unbake solve
unbake next
unbake draft FUNCTION
unbake try FILE
unbake submit FILE
```

Map reads the whole program across every version.
Solve builds shared types from the measured facts.
Use the item suggested by `next`.
Use the file printed by `draft`.
Draft states which containing version it uses.
It uses the shared type context.
Edit that file and run `try` again.
Submit the tried file after it matches every holding version or passes the owner fuzzy bar.
The fuzzy bar requires at least 90% exact words in every containing version.
It accepts register and order differences or relocations.
Source must pass the checks.
Passing drafts publish under `NON_MATCHING` while their assembly rows remain.
Submit proves the ROMs before it publishes the C.
Exact matches feed proven facts back into solve.
Affected neighbours are marked for another draft.

Every command ends with the next command to run.
`unbake next` prints it again.
