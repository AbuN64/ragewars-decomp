# Phase 1: map every line, then the foundations

## Goal

Every byte of the cartridge is assigned to a function, a data row, a blob (graphics, audio, models, world, text) or fill,
and every function has C, matching or not. On top of that, the engine **foundations** are finished first as real,
matching, cleanly named C: random numbers, timing and frame pacing, controller and pak input, audio, and the display
list (graphics) layer. They are the parts a native port touches first and the parts every other system calls.

The foundation set is a floor, not a cap: the real clean C required before this phase is done is at least the larger of
the category minimums (every function of the set below) and 10% of the function bytes. A version already far past that
floor does not wait on it. For us-rev1 the first cut is 362 functions, 117,248 bytes (10.4%): random numbers 6
functions, timing 29, input 32, audio 171, graphics 124.

## Done when

- The README progress block shows the ROM at `~100.00%` (every byte has a source row) for the version.
- No function is still assembly only: every one has C, at least under `NON_MATCHING`.
- Every foundation function matches (no `NON_MATCHING`, no `FAKEMATCH`) and its body names no placeholder
  (`func_XXXXXXXX`, `D_XXXXXXXX`, `unkXX`).

## Order of attack

1. Mapping: data and blob rows before functions. They are mechanical (sizes and formats are in the bytes) and every
   later step needs the boundaries.
2. Drafts: a first C body for every function, compiled with `-DNON_MATCHING` in every version that holds it. A draft
   never changes the ROM, so its only proof is that the unit compiles. Land drafts in batches per file.
3. Foundations, smallest category first: random numbers, timing, input, audio, graphics. Inside a category, the
   functions the port reaches first come first.
4. For each foundation function: match it (hand C, `make`, compare the object with `objdump`), then name it and
   everything it owns, then move it to the file the evidence names.

## Membership of the foundation set

A function is a foundation when it is game code (not the SDK, which the port replaces) and one of these holds: it lives
in an audio, graphics, RSP or scheduler unit; its name says it reads controllers, plays sound, builds display lists or
paces frames; or it is a small direct caller (1 KB or less) of the SDK's controller, audio, video, RSP, timer or
scheduler interface. Larger callers of those interfaces are game logic that uses them. Per-effect sound triggers are game
content. The random number generator is the linear congruential step `x = x * 0xA84A5B53 + 0x58348C2D` and its seeders.

## Rules

- A header or type change is never part of a draft batch: it can change bytes, so it goes through `make check`.
- Raw offsets and casts are allowed inside `NON_MATCHING` only; matched code uses typed fields.
- A function given up on still lands its best body under `NON_MATCHING` with a comment of how close it got.
