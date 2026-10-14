# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [████████████▒▒▒▒▒░░░]  62.61% (~86.38%)  4,293,813 of 6,857,872 bytes</code><br><code>de       [████████████▒▒▒▒▒░░░]  63.34% (~87.07%)  875,769 of 1,382,608 bytes</code><br><code>eu       [███████████▒▒▒▒▒░░░░]  59.41% (~82.65%)  824,405 of 1,387,504 bytes</code><br><code>eu-x     [███████████▒▒▒▒▒░░░░]  58.53% (~83.21%)  771,609 of 1,318,176 bytes</code><br><code>us       [█████████████▒▒▒▒░░░]  65.38% (~88.55%)  904,260 of 1,382,992 bytes</code><br><code>us-rev1  [█████████████▒▒▒▒▒░░]  66.18% (~90.27%)  917,770 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [███████████▒▒▒▒▒▒░░░]  55.49% (~85.17%)  613,372 of 1,105,268</code><br><code>data      [██████████████████░░]  94.61%  262,397 of 277,340</code><br><code>functions [█████████████▒▒▒▒▒░░]  68.13% (~93.71%)  2,352 of 3,452</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [███████████▒▒▒▒▒░░░░]  55.62% (~84.62%)  618,480 of 1,111,912</code><br><code>data      [██████████████░░░░░░]  74.72%  205,925 of 275,592</code><br><code>functions [█████████████▒▒▒▒▒░░]  67.85% (~93.17%)  2,347 of 3,459</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [███████████▒▒▒▒▒░░░░]  55.33% (~84.58%)  615,408 of 1,112,248</code><br><code>data      [███████████████░░░░░]  75.85%  156,201 of 205,928</code><br><code>functions [█████████████▒▒▒▒▒░░]  67.86% (~93.46%)  2,346 of 3,457</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [███████████▒▒▒▒▒▒░░░]  57.74% (~87.86%)  614,472 of 1,064,056</code><br><code>data      [██████████████████░░]  90.86%  289,788 of 318,936</code><br><code>functions [█████████████▒▒▒▒▒░░]  69.16% (~94.82%)  2,326 of 3,363</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████▒▒▒▒▒▒░░░]  58.60% (~88.16%)  662,412 of 1,130,220</code><br><code>data      [███████████████████░]  99.60%  255,358 of 256,372</code><br><code>functions [██████████████▒▒▒▒▒░]  70.15% (~96.07%)  2,447 of 3,488</code></pre> |
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