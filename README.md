# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [█████████████████▒░░]  89.98% (~92.04%)  37,740,536 of 41,943,040 (941,976 none) bytes</code><br><code>de       [██████████████████▒░]  92.17% (~95.10%)  7,732,545 of 8,388,608 (196,679 none) bytes</code><br><code>eu       [█████████████████░░░]  87.01% (~88.94%)  7,299,582 of 8,388,608 (221,766 none) bytes</code><br><code>eu-x     [█████████████████░░░]  86.90% (~89.02%)  7,290,420 of 8,388,608 (154,868 none) bytes</code><br><code>us       [█████████████████░░░]  87.12% (~88.82%)  7,308,289 of 8,388,608 (227,547 none) bytes</code><br><code>us-rev1  [███████████████████░]  96.67% (~98.31%)  8,109,700 of 8,388,608 (141,116 none) bytes</code></pre>

<img src="docs/overview-us-rev1.svg" width="720">

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████████▒▒▒▒]  84.76% (~100.00%)  937,880 of 1,106,440 (10,864 asm)</code><br><code>data      [███░░░░░░░░░░░░░░░░░]  19.38%  47,297 of 243,976 (196,679 none)</code><br><code>functions [██████████████████▒▒]  94.71% (~100.00%)  4,014 of 4,238 (43 asm)</code><br><code>blobs     [███████████████████░]  95.81% (~96.91%)  6,711,080 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████████▒▒▒░]  84.93% (~99.41%)  944,688 of 1,112,292 (10,980 asm) (6,552 none)</code><br><code>data      [███░░░░░░░░░░░░░░░░░]  16.94%  43,902 of 259,116 (215,214 none)</code><br><code>functions [██████████████████▒░]  94.65% (~99.69%)  4,022 of 4,249 (44 asm) (13 none)</code><br><code>blobs     [█████████████████░░░]  89.90% (~89.91%)  6,290,800 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████████████▒▒▒░]  84.18% (~99.39%)  936,652 of 1,112,592 (10,980 asm) (6,720 none)</code><br><code>data      [████░░░░░░░░░░░░░░░░]  21.81%  41,340 of 189,488 (148,148 none)</code><br><code>functions [██████████████████▒░]  94.58% (~99.78%)  4,019 of 4,249 (44 asm) (9 none)</code><br><code>blobs     [█████████████████░░░]  89.04% (~89.15%)  6,292,236 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.84% (~99.86%)  951,412 of 1,095,488 (9,376 asm) (1,512 none)</code><br><code>data      [███░░░░░░░░░░░░░░░░░]  16.71%  45,373 of 271,408 (226,035 none)</code><br><code>functions [███████████████████░]  95.49% (~99.97%)  4,004 of 4,193 (42 asm) (1 none)</code><br><code>blobs     [█████████████████░░░]  89.85%  6,291,312 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████████▒▒▒]  87.80% (~100.00%)  991,732 of 1,129,524 (10,984 asm)</code><br><code>data      [████████░░░░░░░░░░░░]  41.43%  99,848 of 240,964 (141,116 none)</code><br><code>functions [███████████████████▒]  95.85% (~100.00%)  4,165 of 4,345 (44 asm)</code><br><code>blobs     [████████████████████]  100.00%  6,997,928 of 6,997,928</code></pre> |
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

