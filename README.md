# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████▒▒▒▒▒░░░░]  58.20% (~79.45%)  3,991,389 of 6,857,872 bytes</code><br><code>de       [███████████▒▒▒▒▒░░░░]  59.62% (~80.77%)  824,367 of 1,382,608 bytes</code><br><code>eu       [██████████▒▒▒▒▒░░░░░]  53.74% (~74.61%)  745,592 of 1,387,504 bytes</code><br><code>eu-x     [██████████▒▒▒▒▒░░░░░]  52.72% (~74.73%)  694,902 of 1,318,176 bytes</code><br><code>us       [████████████▒▒▒▒▒░░░]  61.78% (~82.55%)  854,480 of 1,382,992 bytes</code><br><code>us-rev1  [████████████▒▒▒▒▒░░░]  62.89% (~84.37%)  872,048 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒░░░░]  50.94% (~77.39%)  562,804 of 1,104,944</code><br><code>data      [██████████████████▒░]  94.20% (~94.21%)  261,563 of 277,664</code><br><code>functions [███████████░░░░░░░░░]  57.19%  2,093 of 3,660</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒░░░░]  50.64% (~76.68%)  563,096 of 1,111,992</code><br><code>data      [█████████████░░░░░░░]  66.24% (~66.24%)  182,496 of 275,512</code><br><code>functions [███████████░░░░░░░░░]  56.88%  2,088 of 3,671</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒░░░░]  50.51% (~76.57%)  562,268 of 1,113,244</code><br><code>data      [████████████░░░░░░░░]  64.72% (~64.72%)  132,634 of 204,932</code><br><code>functions [███████████░░░░░░░░░]  59.00%  2,091 of 3,544</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒░░░░]  53.29% (~80.33%)  566,056 of 1,062,244</code><br><code>data      [█████████████████░░░]  89.92% (~89.92%)  288,424 of 320,748</code><br><code>functions [███████████░░░░░░░░░]  59.98%  2,070 of 3,451</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒░░░░]  54.50% (~80.84%)  616,268 of 1,130,808</code><br><code>data      [████████████████████]  100.00% (~100.00%)  255,780 of 255,784</code><br><code>functions [████████████░░░░░░░░]  62.12%  2,194 of 3,532</code></pre> |
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