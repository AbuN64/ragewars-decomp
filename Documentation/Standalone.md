# Standalone

## Rules
- Decomp game repos (RageWars, BattleTanx) MUST build standalone with their own Makefile and toolchain and MUST NOT depend on decomp tool repos: no tool pins, no wheel URLs, no calls to the generator from CI.
- A tool release MUST NOT require a commit in a game repo; game CI SHOULD run only `make check`.
- A decompiler or generic decomp tool MUST NOT live in a game repo; build toolchain pieces (compilers, assembler, n64link linker) MAY.
- A hand commit to a game repo MUST pass the game policy check (sync --check, audit, verify) before push.
- A decomp game repo SHOULD need no Python: its Makefile MUST be generated and committed, and `make check` alone MUST produce byte-identical ROMs from make, a toolchain and ROMs.
- Where Python is hard to avoid (splat extraction), the trade-off (committed extracted asm versus one optional step) MUST be raised with the owner rather than decided silently.
