# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████▒▒▒▒▒░░░░]  59.28% (~80.62%)  4,065,677 of 6,857,872 bytes</code><br><code>de       [████████████▒▒▒▒░░░░]  60.68% (~81.95%)  839,051 of 1,382,608 bytes</code><br><code>eu       [██████████▒▒▒▒▒░░░░░]  54.81% (~75.78%)  760,568 of 1,387,504 bytes</code><br><code>eu-x     [██████████▒▒▒▒▒░░░░░]  53.85% (~76.08%)  709,942 of 1,318,176 bytes</code><br><code>us       [████████████▒▒▒▒░░░░]  62.86% (~83.71%)  869,456 of 1,382,992 bytes</code><br><code>us-rev1  [████████████▒▒▒▒▒░░░]  63.94% (~85.38%)  886,660 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒░░░░░]  52.25% (~78.86%)  577,428 of 1,104,944</code><br><code>data      [██████████████████░░]  94.22%  261,623 of 277,664</code><br><code>functions [███████████▒▒▒▒▒▒░░░]  58.87% (~86.20%)  2,155 of 3,660</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒░░░░░]  51.95% (~78.12%)  577,720 of 1,111,992</code><br><code>data      [█████████████░░░░░░░]  66.36%  182,848 of 275,512</code><br><code>functions [███████████▒▒▒▒▒▒░░░]  58.56% (~85.61%)  2,150 of 3,671</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒░░░░░]  51.82% (~78.13%)  576,892 of 1,113,244</code><br><code>data      [████████████░░░░░░░░]  64.92%  133,050 of 204,932</code><br><code>functions [████████████▒▒▒▒▒░░░]  60.75% (~88.96%)  2,153 of 3,544</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒░░░░]  54.66% (~81.80%)  580,680 of 1,062,244</code><br><code>data      [██████████████████░░]  90.03%  288,776 of 320,748</code><br><code>functions [████████████▒▒▒▒▒▒░░]  61.77% (~90.26%)  2,132 of 3,451</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████▒▒▒▒▒░░░░]  55.79% (~82.08%)  630,892 of 1,130,808</code><br><code>data      [███████████████████░]  99.99%  255,768 of 255,784</code><br><code>functions [████████████▒▒▒▒▒▒░░]  63.87% (~92.61%)  2,256 of 3,532</code></pre> |
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