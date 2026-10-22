# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████████░░]  91.43% (~92.10%)  38,349,939 of 41,943,040 bytes</code><br><code>de       [██████████████████▒░]  93.97% (~95.36%)  7,883,510 of 8,388,608 bytes</code><br><code>eu       [█████████████████░░░]  88.34% (~88.79%)  7,410,822 of 8,388,608 bytes</code><br><code>eu-x     [█████████████████░░░]  87.71% (~88.28%)  7,358,353 of 8,388,608 bytes</code><br><code>us       [█████████████████░░░]  89.09% (~89.55%)  7,474,007 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.02% (~98.53%)  8,223,247 of 8,388,608 bytes</code></pre>

<img src="docs/overview-us-rev1.svg" width="720">

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████████▒░░░]  82.34% (~85.87%)  909,900 of 1,105,028 (10,692 asm)</code><br><code>data      [██████████████████░░]  92.19%  226,242 of 245,388</code><br><code>functions [██████████████████▒░]  93.22% (~95.29%)  3,966 of 4,254 (42 asm)</code><br><code>blobs     [███████████████████░]  95.81% (~96.91%)  6,711,080 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████████▒░░░]  82.24% (~85.59%)  913,636 of 1,110,880 (10,808 asm)</code><br><code>data      [██████████████░░░░░░]  71.46%  186,194 of 260,528</code><br><code>functions [██████████████████▒░]  93.02% (~95.11%)  3,963 of 4,260 (43 asm)</code><br><code>blobs     [█████████████████░░░]  89.90% (~89.91%)  6,290,800 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████████████▒░░░]  81.84% (~85.36%)  909,476 of 1,111,180 (10,808 asm)</code><br><code>data      [██████████████░░░░░░]  71.47%  136,449 of 190,900</code><br><code>functions [██████████████████▒░]  93.13% (~95.20%)  3,962 of 4,254 (43 asm)</code><br><code>blobs     [█████████████████░░░]  89.04% (~89.15%)  6,292,236 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [████████████████▒░░░]  84.41% (~87.89%)  923,532 of 1,094,076 (9,204 asm)</code><br><code>data      [█████████████████░░░]  87.59%  238,971 of 272,820</code><br><code>functions [██████████████████▒░]  93.72% (~95.79%)  3,941 of 4,205 (41 asm)</code><br><code>blobs     [█████████████████░░░]  89.85%  6,291,312 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████████░░░]  85.48% (~89.23%)  964,364 of 1,128,112 (10,812 asm)</code><br><code>data      [███████████████████░]  99.33%  240,763 of 242,376</code><br><code>functions [██████████████████▒░]  94.66% (~96.73%)  4,118 of 4,350 (43 asm)</code><br><code>blobs     [████████████████████]  100.00%  6,997,928 of 6,997,928</code></pre> |
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

