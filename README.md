# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████████░░]  91.46% (~92.10%)  38,363,899 of 41,943,040 bytes</code><br><code>de       [██████████████████▒░]  94.01% (~95.36%)  7,886,190 of 8,388,608 bytes</code><br><code>eu       [█████████████████░░░]  88.37% (~88.79%)  7,413,582 of 8,388,608 bytes</code><br><code>eu-x     [█████████████████░░░]  87.75% (~88.28%)  7,361,161 of 8,388,608 bytes</code><br><code>us       [█████████████████░░░]  89.13% (~89.55%)  7,476,791 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.06% (~98.53%)  8,226,175 of 8,388,608 bytes</code></pre>

<img src="docs/overview-us-rev1.svg" width="720">

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████████▒░░░]  82.62% (~85.94%)  914,240 of 1,106,440 (10,692 asm)</code><br><code>data      [██████████████████░░]  92.05%  224,582 of 243,976</code><br><code>functions [██████████████████▒░]  93.32% (~95.29%)  3,971 of 4,255 (42 asm)</code><br><code>blobs     [███████████████████░]  95.81% (~96.91%)  6,711,080 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████████▒░░░]  82.53% (~85.65%)  917,992 of 1,112,292 (10,808 asm)</code><br><code>data      [██████████████░░░░░░]  71.24%  184,598 of 259,116</code><br><code>functions [██████████████████▒░]  93.12% (~95.11%)  3,968 of 4,261 (43 asm)</code><br><code>blobs     [█████████████████░░░]  89.90% (~89.91%)  6,290,800 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████████████▒░░░]  82.13% (~85.43%)  913,832 of 1,112,592 (10,808 asm)</code><br><code>data      [██████████████░░░░░░]  71.19%  134,901 of 189,488</code><br><code>functions [██████████████████▒░]  93.23% (~95.20%)  3,967 of 4,255 (43 asm)</code><br><code>blobs     [█████████████████░░░]  89.04% (~89.15%)  6,292,236 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [████████████████▒░░░]  84.69% (~87.95%)  927,872 of 1,095,488 (9,204 asm)</code><br><code>data      [█████████████████░░░]  87.47%  237,415 of 271,408</code><br><code>functions [██████████████████▒░]  93.81% (~95.79%)  3,946 of 4,206 (41 asm)</code><br><code>blobs     [█████████████████░░░]  89.85%  6,291,312 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████████░░░]  85.76% (~89.29%)  968,704 of 1,129,524 (10,812 asm)</code><br><code>data      [███████████████████░]  99.33%  239,351 of 240,964</code><br><code>functions [██████████████████▒░]  94.75% (~96.73%)  4,123 of 4,351 (43 asm)</code><br><code>blobs     [████████████████████]  100.00%  6,997,928 of 6,997,928</code></pre> |
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

