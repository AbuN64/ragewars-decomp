# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████████░░]  91.70% (~93.75%)  38,462,403 of 41,943,040 bytes</code><br><code>de       [██████████████████▒░]  94.24% (~97.15%)  7,905,542 of 8,388,608 bytes</code><br><code>eu       [█████████████████▒░░]  88.61% (~90.52%)  7,433,498 of 8,388,608 bytes</code><br><code>eu-x     [█████████████████▒░░]  87.98% (~90.09%)  7,380,665 of 8,388,608 bytes</code><br><code>us       [█████████████████▒░░]  89.37% (~91.07%)  7,497,419 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.29% (~99.93%)  8,245,279 of 8,388,608 bytes</code></pre>

<img src="docs/overview-us-rev1.svg" width="720">

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████████▒▒▒░]  84.38% (~99.49%)  933,664 of 1,106,440 (10,864 asm)</code><br><code>data      [██████████████████░░]  92.02%  224,510 of 243,976</code><br><code>functions [██████████████████▒░]  94.33% (~99.57%)  4,014 of 4,255 (43 asm)</code><br><code>blobs     [███████████████████░]  95.81% (~96.91%)  6,711,080 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████████▒▒▒░]  84.31% (~98.67%)  937,868 of 1,112,292 (10,980 asm)</code><br><code>data      [██████████████░░░░░░]  71.25%  184,638 of 259,116</code><br><code>functions [██████████████████▒░]  94.39% (~99.38%)  4,022 of 4,261 (44 asm)</code><br><code>blobs     [█████████████████░░░]  89.90% (~89.91%)  6,290,800 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████████████▒▒▒░]  83.89% (~99.10%)  933,408 of 1,112,592 (10,980 asm)</code><br><code>data      [██████████████░░░░░░]  71.15%  134,829 of 189,488</code><br><code>functions [██████████████████▒░]  94.45% (~99.64%)  4,019 of 4,255 (44 asm)</code><br><code>blobs     [█████████████████░░░]  89.04% (~89.15%)  6,292,236 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.57% (~99.59%)  948,456 of 1,095,488 (9,376 asm)</code><br><code>data      [█████████████████░░░]  87.49%  237,459 of 271,408</code><br><code>functions [███████████████████░]  95.14% (~99.61%)  4,002 of 4,206 (42 asm)</code><br><code>blobs     [█████████████████░░░]  89.85%  6,291,312 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.47% (~99.70%)  988,036 of 1,129,524 (10,984 asm)</code><br><code>data      [███████████████████░]  99.23%  239,123 of 240,964</code><br><code>functions [███████████████████░]  95.70% (~99.86%)  4,164 of 4,351 (44 asm)</code><br><code>blobs     [████████████████████]  100.00%  6,997,928 of 6,997,928</code></pre> |
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

