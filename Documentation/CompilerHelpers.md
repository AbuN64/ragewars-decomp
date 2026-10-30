# Compiler Helpers

## Rules
- Matching code MUST NOT declare gcc's 64-bit helpers (such as func_802C6A00(u64)) as extern functions; it SHOULD be written as plain 64-bit C so that gcc emits the __udivdi3, __floatdisf and __cmpdi2 calls itself.
- Compiler-generated helper calls (__udivdi3, __cmpdi2, __floatdisf) MUST be aliased to their func_ addresses in an authored symbol file wired into every link, and MUST NOT be added to splat/undefined_funcs_auto.txt, which splat regenerates.
- Assembly that contains no cvt, mtc1, dmtc1, mfc1 or trunc and repeatedly calls the same few routines SHOULD be treated as compiler-lowered 64-bit conversions; func_802BFEB0 is the game's own osGetTime and MUST NOT be treated as a compiler helper.
