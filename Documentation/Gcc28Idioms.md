# Gcc28Idioms

## Rules
- A `bnel` with a flag store in the delay slot before a shared failure tail SHOULD be written success-path first with `else { flag = 1; }` as the last arm directly before the code it falls into, not `goto fail`.
- Loop constants (float literals, `&local`) reloaded every iteration indicate a loop built with `goto`; a `for` loop hoists them into saved registers and SHOULD be used only when the target hoists them.
- A base register holding `symbol+K` with `-K` offsets SHOULD be reproduced by a pointer to a sub-struct at +K or a pointer-cast view of the symbol, and a repeated `lui/lwc1` pair per access indicates a scalar global declared `extern f32`.
- A loop pointer kept at the struct base with +off field loads SHOULD be reproduced by advancing the pointer in both arms of the loop body so loop.c leaves the address givs unreduced.
- Two registers swapped between short-lived values are global-alloc priority and SHOULD NOT be chased with the permuter or declaration order.
- When hoisted loop invariants get each other's callee-saved registers, the C SHOULD write the tail the original wrote in each branch in every branch, because GCC 2.8 ranks by reference count before cross-jumping merges the copies.
- When the target's `addu rd, idx, base` puts the scaled index first, the address SHOULD be written `(T *)((i << k) + (u32)base)` and disclosed in the note.
- A read-only table SHOULD be declared `const` when the target schedules its load above a store through a pointer.
- `x |= A; other = ...; x |= B;` through a pointer SHOULD be used when the target folds both flag updates into one `ori`.
- Float constants MUST be written as float literals read from the ROM, not through `extern f32 D_xxx`, casts or table pointers, so the pinned compiler places them in its constant pool and hoists them.
- A duplicated constant in the target's pool (the same value twice) MUST be reproduced by writing the literal at each use, not through a shared local.
- A float clamp whose target computes MIN in place and recomputes the subtraction in MAX's other arm SHOULD be written with a statement-expression MIN, `({ f32 _m = (a); if (!(_m <= (b))) _m = (b); _m; })`, under the ordinary `?:` MAX macro.
- A clamp whose branches the target threads SHOULD use the plain `?:` macro, and neither a `static inline` helper nor a `?:` MIN macro reproduces the in-place form.
