# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████▒░░░░]  75.97% (~84.53%)  5,209,973 of 6,857,872 bytes</code><br><code>de       [███████████████▒▒░░░]  77.14% (~85.66%)  1,066,679 of 1,382,608 bytes</code><br><code>eu       [██████████████▒░░░░░]  71.31% (~79.70%)  989,472 of 1,387,504 bytes</code><br><code>eu-x     [██████████████▒▒░░░░]  71.25% (~80.22%)  939,282 of 1,318,176 bytes</code><br><code>us       [███████████████▒▒░░░]  79.21% (~87.44%)  1,095,568 of 1,382,992 bytes</code><br><code>us-rev1  [████████████████▒░░░]  80.69% (~89.45%)  1,118,972 of 1,386,592 bytes</code></pre>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████████▒▒░░░░]  72.92% (~83.56%)  807,408 of 1,107,140</code><br><code>data      [██████████████████░░]  94.12%  259,271 of 275,468</code><br><code>functions [███████████████▒▒░░░]  76.97% (~88.14%)  2,818 of 3,661</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [██████████████▒▒░░░░]  72.54% (~83.01%)  806,704 of 1,111,992</code><br><code>data      [█████████████░░░░░░░]  66.33%  182,768 of 275,512</code><br><code>functions [███████████████▒▒░░░]  76.57% (~87.55%)  2,811 of 3,671</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████████▒▒░░░░]  72.42% (~83.04%)  806,256 of 1,113,232</code><br><code>data      [████████████░░░░░░░░]  64.90%  133,026 of 204,944</code><br><code>functions [███████████████▒▒▒░░]  79.43% (~91.05%)  2,815 of 3,544</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [███████████████▒▒░░░]  76.01% (~86.71%)  809,156 of 1,064,440</code><br><code>data      [█████████████████░░░]  89.91%  286,412 of 318,552</code><br><code>functions [████████████████▒▒░░]  80.82% (~92.26%)  2,790 of 3,452</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████████▒▒░░░]  76.33% (~87.06%)  863,204 of 1,130,796</code><br><code>data      [███████████████████░]  99.98%  255,768 of 255,796</code><br><code>functions [████████████████▒▒░░]  82.92% (~94.84%)  2,929 of 3,532</code></pre> |
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