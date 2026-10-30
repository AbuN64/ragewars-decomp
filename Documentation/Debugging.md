# Debugging

## Rules
- Guest debugging MUST use gdb on the recompiled host executable, because N64Recomp emits every guest function as a host symbol, so `break *func_XXXXXXXX` is a guest breakpoint with no relink.
- Guest arguments MUST be read from the System V registers at a function entry (`$rdi` is the RDRAM base, `$rsi` is the `recomp_context`), because generated functions carry no DWARF locals.
- Guest RDRAM words MUST be read as four host bytes reversed, and the caller MUST come from the host backtrace, because `ctx->r31` is not maintained and is 0 at every entry.
