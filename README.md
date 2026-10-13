# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [█████████████▒▒▒░░░░]  69.94% (~83.87%)  4,796,717 of 6,857,872 bytes</code><br><code>de       [██████████████▒▒▒░░░]  71.13% (~85.08%)  983,543 of 1,382,608 bytes</code><br><code>eu       [█████████████▒▒░░░░░]  65.43% (~79.05%)  907,964 of 1,387,504 bytes</code><br><code>eu-x     [█████████████▒▒░░░░░]  65.04% (~79.54%)  857,342 of 1,318,176 bytes</code><br><code>us       [██████████████▒▒▒░░░]  73.27% (~86.77%)  1,013,320 of 1,382,992 bytes</code><br><code>us-rev1  [██████████████▒▒▒░░░]  74.61% (~88.73%)  1,034,548 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████▒▒▒░░░░]  65.41% (~82.83%)  724,248 of 1,107,140</code><br><code>data      [██████████████████░░]  94.12% (~94.13%)  259,295 of 275,468</code><br><code>functions [█████████████▒▒▒▒░░░]  65.03% (~87.73%)  2,381 of 3,661</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████▒▒▒░░░░]  65.20% (~82.19%)  725,120 of 1,111,992</code><br><code>data      [█████████████░░░░░░░]  66.36%  182,844 of 275,512</code><br><code>functions [████████████▒▒▒▒▒░░░]  64.77% (~87.16%)  2,378 of 3,671</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████▒▒▒░░░░]  65.06% (~82.24%)  724,292 of 1,113,232</code><br><code>data      [████████████░░░░░░░░]  64.92%  133,050 of 204,944</code><br><code>functions [█████████████▒▒▒▒▒░░]  67.18% (~90.66%)  2,381 of 3,544</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████▒▒▒▒░░░]  68.28% (~85.83%)  726,872 of 1,064,440</code><br><code>data      [█████████████████░░░]  89.92%  286,448 of 318,552</code><br><code>functions [█████████████▒▒▒▒▒░░]  68.27% (~91.80%)  2,357 of 3,452</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████▒▒▒▒░░░]  68.87% (~86.18%)  778,780 of 1,130,796</code><br><code>data      [███████████████████░]  99.98%  255,768 of 255,796</code><br><code>functions [██████████████▒▒▒▒░░]  70.38% (~94.33%)  2,486 of 3,532</code></pre> |
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