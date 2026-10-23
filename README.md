# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████████░░]  91.87% (~93.83%)  38,534,555 of 41,943,040 (189,357 none) bytes</code><br><code>de       [██████████████████▒░]  94.45% (~97.21%)  7,923,586 of 8,388,608 (19,966 none) bytes</code><br><code>eu       [█████████████████▒░░]  88.79% (~90.67%)  7,448,750 of 8,388,608 (76,470 none) bytes</code><br><code>eu-x     [█████████████████▒░░]  88.15% (~90.19%)  7,394,785 of 8,388,608 (56,555 none) bytes</code><br><code>us       [█████████████████▒░░]  89.51% (~91.12%)  7,508,919 of 8,388,608 (34,477 none) bytes</code><br><code>us-rev1  [███████████████████░]  98.44% (~99.97%)  8,258,515 of 8,388,608 (1,889 none) bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.02% (~99.96%)  951,848 of 1,106,440 (10,864 asm) (360 none)</code><br><code>data      [██████████████████░░]  91.96%  224,370 of 243,976 (19,606 none)</code><br><code>functions [███████████████████░]  95.28% (~99.97%)  4,038 of 4,238 (43 asm) (1 none)</code><br><code>blobs     [███████████████████░]  95.81% (~96.91%)  6,711,080 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.70% (~99.83%)  953,284 of 1,112,292 (10,980 asm) (1,828 none)</code><br><code>data      [██████████████░░░░░░]  71.19%  184,474 of 259,116 (74,642 none)</code><br><code>functions [██████████████████▒░]  94.96% (~99.95%)  4,035 of 4,249 (44 asm) (2 none)</code><br><code>blobs     [█████████████████░░░]  89.90% (~89.91%)  6,290,800 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.17% (~99.83%)  947,596 of 1,112,592 (10,980 asm) (1,828 none)</code><br><code>data      [██████████████░░░░░░]  71.11%  134,761 of 189,488 (54,727 none)</code><br><code>functions [██████████████████▒░]  94.98% (~99.95%)  4,036 of 4,249 (44 asm) (2 none)</code><br><code>blobs     [█████████████████░░░]  89.04% (~89.15%)  6,292,236 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.64% (~99.96%)  960,124 of 1,095,488 (9,376 asm) (360 none)</code><br><code>data      [█████████████████░░░]  87.42%  237,291 of 271,408 (34,117 none)</code><br><code>functions [███████████████████░]  95.82% (~99.97%)  4,018 of 4,193 (42 asm) (1 none)</code><br><code>blobs     [█████████████████░░░]  89.85%  6,291,312 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████████▒▒▒]  88.64% (~100.00%)  1,001,320 of 1,129,524 (10,984 asm)</code><br><code>data      [███████████████████░]  99.21%  239,075 of 240,964 (1,889 none)</code><br><code>functions [███████████████████▒]  96.22% (~100.00%)  4,181 of 4,345 (44 asm)</code><br><code>blobs     [████████████████████]  100.00%  6,997,928 of 6,997,928</code></pre> |
<!-- /progress -->

## Development & Contributions

Contributions and corrections are welcome. Run `make check` before opening a pull request.

For detailed instructions please see [CONTRIBUTING.md](CONTRIBUTING.md).

## License

[CC0 1.0](LICENSE)

## Dependencies

<!-- dependencies -->
- [GCC 2.8.1](https://github.com/pmret/gcc-papermario)
- [n64link](https://github.com/AbuN64/mas-n64)
<!-- /dependencies -->

