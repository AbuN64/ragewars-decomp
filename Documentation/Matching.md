# Matching

## Rules
- An exact function that keeps a dead store, dead read or FAKEMATCH MUST be treated as open work and MUST NOT be reported as done.
- A dead-looking line MAY be accepted as original source only when another version's debug build proves the original had it, and it MUST then be recorded in the decomp journal compiler-quirks post.
- Matched C MUST NOT cheat: it MUST NOT add assembly, .word data, pragmas, section directives or INCLUDE_ASM, and MUST NOT edit build infrastructure to force a match.
- A match MUST be proven by make check against the ROM SHA-1 of every version before it is pushed.
- Landed C MUST NOT use cast or view macros such as FIELD_VIEW, hack unions or type-punning casts that read a global through a different type to force exact codegen.
- A global used both as a scalar and as an aggregate MUST get the one real struct inferred from every user's offsets, sizes and neighbouring D_ symbols, declared once in the owning header and accessed by plain member access.
- When no single struct makes every user exact, the global SHOULD keep its original per-file declarations and be listed in GAPS with the evidence.
