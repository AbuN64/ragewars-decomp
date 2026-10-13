# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████▒▒░░░]  77.86% (~85.40%)  5,339,909 of 6,857,872 bytes</code><br><code>de       [███████████████▒▒░░░]  79.14% (~86.60%)  1,094,283 of 1,382,608 bytes</code><br><code>eu       [██████████████▒▒░░░░]  73.27% (~80.63%)  1,016,700 of 1,387,504 bytes</code><br><code>eu-x     [██████████████▒▒░░░░]  73.30% (~81.21%)  966,250 of 1,318,176 bytes</code><br><code>us       [████████████████▒░░░]  80.96% (~88.17%)  1,119,792 of 1,382,992 bytes</code><br><code>us-rev1  [████████████████▒▒░░]  82.42% (~90.17%)  1,142,884 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [███████████████▒░░░░]  75.41% (~84.73%)  834,968 of 1,107,140</code><br><code>data      [██████████████████░░]  94.13% (~94.14%)  259,315 of 275,468</code><br><code>functions [████████████████▒░░░]  81.34% (~88.28%)  2,978 of 3,661</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [██████████████▒▒░░░░]  74.99% (~84.18%)  833,928 of 1,111,992</code><br><code>data      [█████████████░░░░░░░]  66.33%  182,772 of 275,512</code><br><code>functions [████████████████▒░░░]  80.84% (~87.68%)  2,968 of 3,671</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████████▒▒░░░░]  74.84% (~84.20%)  833,180 of 1,113,232</code><br><code>data      [████████████░░░░░░░░]  64.92%  133,070 of 204,944</code><br><code>functions [████████████████▒▒░░]  83.83% (~91.19%)  2,971 of 3,544</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [███████████████▒▒░░░]  78.29% (~87.65%)  833,376 of 1,064,440</code><br><code>data      [█████████████████░░░]  89.91%  286,416 of 318,552</code><br><code>functions [█████████████████▒░░]  85.34% (~92.38%)  2,946 of 3,452</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████████▒▒░░░]  78.45% (~87.95%)  887,116 of 1,130,796</code><br><code>data      [███████████████████░]  99.98%  255,768 of 255,796</code><br><code>functions [█████████████████▒░░]  87.31% (~94.96%)  3,084 of 3,532</code></pre> |
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