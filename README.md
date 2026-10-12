# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████▒░░░░░]  73.30% (~76.43%)  5,026,545 of 6,857,872 bytes</code><br><code>de       [██████████████▒░░░░░]  74.79% (~77.94%)  1,034,051 of 1,382,608 bytes</code><br><code>eu       [█████████████▒░░░░░░]  68.64% (~71.68%)  952,344 of 1,387,504 bytes</code><br><code>eu-x     [█████████████▒░░░░░░]  68.41% (~71.65%)  901,798 of 1,318,176 bytes</code><br><code>us       [███████████████▒░░░░]  76.68% (~79.58%)  1,060,460 of 1,382,992 bytes</code><br><code>us-rev1  [███████████████▒░░░░]  77.74% (~81.06%)  1,077,892 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  69.91% (~73.85%)  772,464 of 1,104,964</code><br><code>data      [██████████████████░░]  94.22% (~94.22%)  261,587 of 277,644</code><br><code>functions [████████████████░░░░]  80.23%  2,939 of 3,663</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  69.23% (~73.03%)  769,868 of 1,111,996</code><br><code>data      [█████████████░░░░░░░]  66.23% (~66.23%)  182,476 of 275,508</code><br><code>functions [███████████████░░░░░]  79.68%  2,926 of 3,672</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  69.11% (~72.94%)  770,016 of 1,114,140</code><br><code>data      [████████████░░░░░░░░]  64.59% (~64.59%)  131,782 of 204,036</code><br><code>functions [███████████████░░░░░]  79.75%  2,930 of 3,674</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████████▒░░░░░]  72.68% (~76.47%)  772,092 of 1,062,244</code><br><code>data      [█████████████████░░░]  89.90% (~89.90%)  288,368 of 320,748</code><br><code>functions [████████████████░░░░]  84.18%  2,905 of 3,451</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████▒░░░░░]  72.73% (~76.80%)  823,424 of 1,132,124</code><br><code>data      [████████████████████]  100.00% (~100.00%)  254,468 of 254,468</code><br><code>functions [████████████████░░░░]  82.00%  3,039 of 3,706</code></pre> |
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