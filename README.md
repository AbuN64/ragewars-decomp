# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [█████████████▒▒▒░░░░]  65.80% (~81.83%)  4,512,685 of 6,857,872 bytes</code><br><code>de       [█████████████▒▒▒░░░░]  67.12% (~83.07%)  928,067 of 1,382,608 bytes</code><br><code>eu       [████████████▒▒▒░░░░░]  61.27% (~77.05%)  850,164 of 1,387,504 bytes</code><br><code>eu-x     [████████████▒▒▒░░░░░]  60.65% (~77.38%)  799,538 of 1,318,176 bytes</code><br><code>us       [█████████████▒▒▒░░░░]  69.29% (~84.79%)  958,408 of 1,382,992 bytes</code><br><code>us-rev1  [██████████████▒▒▒░░░]  70.42% (~86.66%)  976,508 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████▒▒▒▒░░░░]  60.31% (~80.27%)  666,444 of 1,104,944</code><br><code>data      [██████████████████░░]  94.22%  261,623 of 277,664</code><br><code>functions [████████████▒▒▒▒▒░░░]  62.67% (~86.91%)  2,294 of 3,660</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████▒▒▒░░░░░]  60.01% (~79.70%)  667,316 of 1,111,992</code><br><code>data      [█████████████░░░░░░░]  66.36%  182,848 of 275,512</code><br><code>functions [████████████▒▒▒▒▒░░░]  62.40% (~86.35%)  2,291 of 3,671</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [███████████▒▒▒▒░░░░░]  59.86% (~79.67%)  666,488 of 1,113,244</code><br><code>data      [████████████░░░░░░░░]  64.92%  133,050 of 204,932</code><br><code>functions [████████████▒▒▒▒▒░░░]  64.72% (~89.81%)  2,294 of 3,544</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [████████████▒▒▒▒░░░░]  63.03% (~83.21%)  669,632 of 1,062,244</code><br><code>data      [██████████████████░░]  90.03%  288,776 of 320,748</code><br><code>functions [█████████████▒▒▒▒▒░░]  65.80% (~90.98%)  2,271 of 3,451</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [████████████▒▒▒▒░░░░]  63.73% (~83.65%)  720,740 of 1,130,808</code><br><code>data      [███████████████████░]  99.99%  255,768 of 255,784</code><br><code>functions [█████████████▒▒▒▒▒░░]  67.89% (~93.48%)  2,398 of 3,532</code></pre> |
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