# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████▒░░░░░]  73.64% (~76.73%)  5,049,953 of 6,857,872 bytes</code><br><code>de       [███████████████▒░░░░]  75.08% (~78.20%)  1,038,083 of 1,382,608 bytes</code><br><code>eu       [█████████████▒░░░░░░]  68.96% (~71.97%)  956,876 of 1,387,504 bytes</code><br><code>eu-x     [█████████████▒░░░░░░]  68.76% (~71.96%)  906,330 of 1,318,176 bytes</code><br><code>us       [███████████████▒░░░░]  77.01% (~79.88%)  1,064,992 of 1,382,992 bytes</code><br><code>us-rev1  [███████████████▒░░░░]  78.15% (~81.40%)  1,083,672 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████████▒░░░░░]  70.27% (~74.18%)  776,496 of 1,104,964</code><br><code>data      [██████████████████░░]  94.22% (~94.22%)  261,587 of 277,644</code><br><code>functions [████████████████░░░░]  80.37%  2,944 of 3,663</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  69.64% (~73.40%)  774,400 of 1,111,996</code><br><code>data      [█████████████░░░░░░░]  66.23% (~66.23%)  182,476 of 275,508</code><br><code>functions [███████████████░░░░░]  79.87%  2,933 of 3,672</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████▒░░░░░░]  69.52% (~73.30%)  774,548 of 1,114,140</code><br><code>data      [████████████░░░░░░░░]  64.59% (~64.59%)  131,782 of 204,036</code><br><code>functions [███████████████░░░░░]  79.94%  2,937 of 3,674</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████████▒░░░░░]  73.11% (~76.85%)  776,624 of 1,062,244</code><br><code>data      [█████████████████░░░]  89.90% (~89.90%)  288,368 of 320,748</code><br><code>functions [████████████████░░░░]  84.38%  2,912 of 3,451</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████▒░░░░░]  73.24% (~77.22%)  829,204 of 1,132,124</code><br><code>data      [████████████████████]  100.00% (~100.00%)  254,468 of 254,468</code><br><code>functions [████████████████░░░░]  82.22%  3,047 of 3,706</code></pre> |
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