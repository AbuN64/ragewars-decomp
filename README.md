# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████▒▒▒▒▒▒▒░░░]  52.33% (~86.17%)  3,588,904 of 6,857,872 bytes</code><br><code>de       [██████████▒▒▒▒▒▒▒░░░]  53.43% (~86.85%)  738,748 of 1,382,608 bytes</code><br><code>eu       [█████████▒▒▒▒▒▒▒░░░░]  49.16% (~82.47%)  682,152 of 1,387,504 bytes</code><br><code>eu-x     [█████████▒▒▒▒▒▒▒░░░░]  47.88% (~83.02%)  631,160 of 1,318,176 bytes</code><br><code>us       [███████████▒▒▒▒▒▒░░░]  55.23% (~88.31%)  763,851 of 1,382,992 bytes</code><br><code>us-rev1  [███████████▒▒▒▒▒▒▒░░]  55.74% (~90.03%)  772,993 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████▒▒▒▒▒▒▒▒░░░░]  43.09% (~84.91%)  476,344 of 1,105,268</code><br><code>data      [██████████████████░░]  94.61%  262,404 of 277,340</code><br><code>functions [███████████▒▒▒▒▒▒▒░░]  59.44% (~93.36%)  2,052 of 3,452</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████▒▒▒▒▒▒▒▒░░░░]  42.82% (~84.40%)  476,228 of 1,111,912</code><br><code>data      [██████████████░░░░░░]  74.72%  205,924 of 275,592</code><br><code>functions [███████████▒▒▒▒▒▒▒░░]  58.97% (~92.85%)  2,040 of 3,459</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████▒▒▒▒▒▒▒▒░░░░]  42.70% (~84.35%)  474,952 of 1,112,248</code><br><code>data      [███████████████░░░░░]  75.85%  156,208 of 205,928</code><br><code>functions [███████████▒▒▒▒▒▒▒░░]  59.09% (~93.14%)  2,043 of 3,457</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [████████▒▒▒▒▒▒▒▒▒░░░]  44.55% (~87.55%)  474,064 of 1,064,056</code><br><code>data      [██████████████████░░]  90.86%  289,787 of 318,936</code><br><code>functions [████████████▒▒▒▒▒▒░░]  60.21% (~94.46%)  2,025 of 3,363</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████▒▒▒▒▒▒▒▒░░░]  45.79% (~87.86%)  517,632 of 1,130,220</code><br><code>data      [███████████████████░]  99.60%  255,361 of 256,372</code><br><code>functions [████████████▒▒▒▒▒▒▒░]  61.23% (~95.72%)  2,136 of 3,488</code></pre> |
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