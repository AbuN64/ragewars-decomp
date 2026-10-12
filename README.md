# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████▒▒▒▒░░░░░]  58.50% (~79.64%)  4,012,045 of 6,857,872 bytes</code><br><code>de       [███████████▒▒▒▒▒░░░░]  59.90% (~80.95%)  828,287 of 1,382,608 bytes</code><br><code>eu       [██████████▒▒▒▒░░░░░░]  54.04% (~74.81%)  749,868 of 1,387,504 bytes</code><br><code>eu-x     [██████████▒▒▒▒░░░░░░]  53.04% (~74.95%)  699,178 of 1,318,176 bytes</code><br><code>us       [████████████▒▒▒▒░░░░]  62.09% (~82.79%)  858,756 of 1,382,992 bytes</code><br><code>us-rev1  [████████████▒▒▒▒░░░░]  63.17% (~84.47%)  875,956 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒░░░░░]  51.28% (~77.62%)  566,724 of 1,104,944</code><br><code>data      [██████████████████░░]  94.20%  261,563 of 277,664</code><br><code>functions [███████████▒▒▒▒▒▒░░░]  57.21% (~85.49%)  2,094 of 3,660</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒░░░░░]  50.99% (~76.90%)  567,016 of 1,111,992</code><br><code>data      [█████████████░░░░░░░]  66.36%  182,852 of 275,512</code><br><code>functions [███████████▒▒▒▒▒░░░░]  56.90% (~84.90%)  2,089 of 3,671</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒░░░░░]  50.85% (~76.80%)  566,188 of 1,113,244</code><br><code>data      [████████████░░░░░░░░]  64.89%  132,990 of 204,932</code><br><code>functions [███████████▒▒▒▒▒▒░░░]  59.02% (~88.20%)  2,092 of 3,544</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒░░░░]  53.65% (~80.61%)  569,976 of 1,062,244</code><br><code>data      [██████████████████░░]  90.03%  288,780 of 320,748</code><br><code>functions [████████████▒▒▒▒▒░░░]  60.01% (~89.53%)  2,071 of 3,451</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒░░░░]  54.84% (~80.96%)  620,188 of 1,130,808</code><br><code>data      [███████████████████░]  99.99%  255,768 of 255,784</code><br><code>functions [████████████▒▒▒▒▒▒░░]  62.14% (~91.90%)  2,195 of 3,532</code></pre> |
<!-- /progress -->

## Development & Contributions

Contributions and corrections are welcome. Run `make check` before opening a pull request.

For detailed instructions please see [CONTRIBUTING.md](CONTRIBUTING.md).

## AI Usage

### Workflow

AI is used in the decompilation process and every function is verified by compiling it against the original ROM. A match can still be a fakematch or use odd C semantics. I try to mark these in source as they are discovered.

I turned these efforts into a repeatable process with [AbuCakeUnbake64](https://github.com/AbuN64/cake-unbake-64). It is built so AI can drive it against any N64 ROM.

### Personal Thoughts

AI suits decompilation well. Every function is checked deterministically against the original ROM so correctness is always provable. Decompiled code is plain source built with the original toolchain so nothing opaque runs on the player's machine and the only attack surface is the build tooling. Readable source can be ported, fixed and preserved long after its tools are gone.

While recompilations can be a fine short-term way to play a favourite game, I believe AI-driven recomps are junk and should be avoided entirely. Used this way AI carries more security risk and is more likely to leave the scene littered with broken and abandoned ports. For games as compact as most N64 titles it makes more sense to point AI at a proper decompilation instead.

## License

[CC0 1.0](LICENSE)

## Dependencies

- [AbuCakeUnbake64](https://github.com/AbuN64/cake-unbake-64)
- [GCC 2.8.1 for mips-nintendo-nu64](https://github.com/pmret/gcc-papermario) at `d97824ffc7517675646960442b3f512a473e4404`, the compiler of toolchain `gcc-2.8.1`, assembled by SN ASN64 version 2.81