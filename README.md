# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [█████████████▒░░░░░░]  67.95% (~71.38%)  4,660,150 of 6,857,872 bytes</code><br><code>de       [█████████████▒░░░░░░]  68.08% (~71.43%)  941,301 of 1,382,608 bytes</code><br><code>eu       [████████████▒░░░░░░░]  64.04% (~67.38%)  888,618 of 1,387,504 bytes</code><br><code>eu-x     [████████████▒░░░░░░░]  63.59% (~67.13%)  838,190 of 1,318,176 bytes</code><br><code>us       [██████████████▒░░░░░]  71.07% (~74.32%)  982,935 of 1,382,992 bytes</code><br><code>us-rev1  [██████████████▒░░░░░]  72.78% (~76.44%)  1,009,106 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  66.65% (~70.83%)  736,476 of 1,104,964</code><br><code>data      [██████████████▒░░░░░]  73.77% (~73.84%)  204,825 of 277,644</code><br><code>functions [███████████████░░░░░]  78.92%  2,891 of 3,663</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  66.68% (~70.83%)  741,472 of 1,111,996</code><br><code>data      [██████████▒░░░░░░░░░]  53.41% (~53.47%)  147,146 of 275,508</code><br><code>functions [███████████████░░░░░]  78.76%  2,892 of 3,672</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  66.61% (~70.80%)  742,168 of 1,114,140</code><br><code>data      [█████████▒░░░░░░░░░░]  47.06% (~47.14%)  96,022 of 204,036</code><br><code>functions [███████████████░░░░░]  78.85%  2,897 of 3,674</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  68.76% (~72.96%)  730,348 of 1,062,244</code><br><code>data      [███████████████▒░░░░]  78.75% (~78.80%)  252,587 of 320,748</code><br><code>functions [████████████████░░░░]  82.61%  2,851 of 3,451</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  68.62% (~73.11%)  776,912 of 1,132,124</code><br><code>data      [██████████████████░░]  91.25% (~91.25%)  232,194 of 254,468</code><br><code>functions [████████████████░░░░]  80.28%  2,975 of 3,706</code></pre> |
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