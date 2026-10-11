# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [█████████████▒░░░░░░]  67.20% (~68.76%)  4,608,355 of 6,857,872 bytes</code><br><code>de       [█████████████▒░░░░░░]  67.65% (~69.20%)  935,356 of 1,382,608 bytes</code><br><code>eu       [████████████▒░░░░░░░]  63.61% (~65.20%)  882,551 of 1,387,504 bytes</code><br><code>eu-x     [████████████▒░░░░░░░]  63.14% (~64.76%)  832,327 of 1,318,176 bytes</code><br><code>us       [██████████████▒░░░░░]  70.61% (~72.00%)  976,536 of 1,382,992 bytes</code><br><code>us-rev1  [██████████████▒░░░░░]  70.79% (~72.45%)  981,585 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  66.60% (~68.52%)  735,928 of 1,104,964</code><br><code>data      [██████████████▒░░░░░]  71.83% (~71.92%)  199,428 of 277,644</code><br><code>functions [███████████████░░░░░]  78.84%  2,888 of 3,663</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  66.63% (~68.59%)  740,932 of 1,111,996</code><br><code>data      [██████████▒░░░░░░░░░]  51.40% (~51.49%)  141,619 of 275,508</code><br><code>functions [███████████████░░░░░]  78.68%  2,889 of 3,672</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  66.57% (~68.46%)  741,628 of 1,114,140</code><br><code>data      [████████▒░░░░░░░░░░░]  44.45% (~44.57%)  90,699 of 204,036</code><br><code>functions [███████████████░░░░░]  78.77%  2,894 of 3,674</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  68.70% (~70.49%)  729,808 of 1,062,244</code><br><code>data      [███████████████▒░░░░]  76.92% (~77.00%)  246,728 of 320,748</code><br><code>functions [████████████████░░░░]  82.53%  2,848 of 3,451</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  68.51% (~70.53%)  775,616 of 1,132,124</code><br><code>data      [████████████████▒░░░]  80.94% (~80.97%)  205,969 of 254,468</code><br><code>functions [████████████████░░░░]  80.17%  2,971 of 3,706</code></pre> |
<!-- /progress -->

## Development & Contributions

Contributions and corrections are welcome. Run `make check` before opening a pull request.

For detailed instructions please see [CONTRIBUTING.md](CONTRIBUTING.md).

## AI Usage

### Workflow

AI is used in the decompilation process and every function is verified by compiling it against the original ROM. A match can still be a fakematch or use odd C semantics. I try to mark these in source as they are discovered.

I turned these efforts into a repeatable process with [AbuCakeUnbake64](https://github.com/melalawi/abu-cake-unbake-64). It is built so AI can drive it against any N64 ROM.

### Personal Thoughts

AI suits decompilation well. Every function is checked deterministically against the original ROM so correctness is always provable. Decompiled code is plain source built with the original toolchain so nothing opaque runs on the player's machine and the only attack surface is the build tooling. Readable source can be ported, fixed and preserved long after its tools are gone.

While recompilations can be a fine short-term way to play a favourite game, I believe AI-driven recomps are junk and should be avoided entirely. Used this way AI carries more security risk and is more likely to leave the scene littered with broken and abandoned ports. For games as compact as most N64 titles it makes more sense to point AI at a proper decompilation instead.

## License

[CC0 1.0](LICENSE)

## Dependencies

- [AbuCakeUnbake64](https://github.com/melalawi/abu-cake-unbake-64)
- [GCC 2.8.1 for mips-nintendo-nu64](https://github.com/pmret/gcc-papermario) at `d97824ffc7517675646960442b3f512a473e4404`, the compiler of toolchain `gcc-2.8.1`, assembled by SN ASN64 version 2.81