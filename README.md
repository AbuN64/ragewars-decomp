# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [█████████████████░░░]  86.98% (~88.84%)  36,483,452 of 41,943,040 bytes</code><br><code>de       [██████████████████░░]  91.00% (~93.35%)  7,634,421 of 8,388,608 bytes</code><br><code>eu       [█████████████████░░░]  85.57% (~87.09%)  7,178,758 of 8,388,608 bytes</code><br><code>eu-x     [█████████████████░░░]  85.18% (~86.83%)  7,145,741 of 8,388,608 bytes</code><br><code>us       [█████████████████░░░]  86.32% (~87.84%)  7,241,115 of 8,388,608 bytes</code><br><code>us-rev1  [█████████████████░░░]  86.82% (~89.07%)  7,283,417 of 8,388,608 bytes</code></pre>

<img src="docs/overview-us-rev1.svg" width="720">

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████████▒░░░]  81.32% (~85.23%)  898,664 of 1,105,028 (10,692 asm)</code><br><code>data      [█████████████████░░░]  89.18%  218,858 of 245,388</code><br><code>functions [██████████████████▒░]  92.85% (~95.11%)  3,950 of 4,254 (42 asm)</code><br><code>blobs     [██████████████████░░]  92.52% (~94.71%)  6,480,611 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████████▒░░░]  81.37% (~85.11%)  903,960 of 1,110,880 (10,808 asm)</code><br><code>data      [█████████████░░░░░░░]  68.39%  178,194 of 260,528</code><br><code>functions [██████████████████░░]  92.67% (~94.97%)  3,948 of 4,260 (43 asm)</code><br><code>blobs     [█████████████████░░░]  86.84% (~88.07%)  6,076,412 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████████████░░░░]  80.97% (~84.88%)  899,800 of 1,111,180 (10,808 asm)</code><br><code>data      [█████████████░░░░░░░]  67.33%  128,537 of 190,900</code><br><code>functions [██████████████████▒░]  92.78% (~95.03%)  3,947 of 4,254 (43 asm)</code><br><code>blobs     [█████████████████░░░]  86.28% (~87.62%)  6,097,212 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [████████████████▒░░░]  83.52% (~87.39%)  913,868 of 1,094,076 (9,204 asm)</code><br><code>data      [████████████████░░░░]  84.54%  230,643 of 272,820</code><br><code>functions [██████████████████▒░]  93.36% (~95.62%)  3,926 of 4,205 (41 asm)</code><br><code>blobs     [█████████████████░░░]  86.78% (~88.01%)  6,076,412 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [████████████████▒░░░]  84.62% (~88.74%)  954,700 of 1,128,112 (10,812 asm)</code><br><code>data      [███████████████████░]  95.76%  232,113 of 242,376</code><br><code>functions [██████████████████▒░]  94.32% (~96.57%)  4,103 of 4,350 (43 asm)</code><br><code>blobs     [█████████████████░░░]  86.83% (~88.86%)  6,076,412 of 6,997,928</code></pre> |
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

