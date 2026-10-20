# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████████░░]  91.21% (~91.93%)  38,260,201 of 41,943,040 bytes</code><br><code>de       [██████████████████▒░]  93.76% (~95.18%)  7,865,391 of 8,388,608 bytes</code><br><code>eu       [█████████████████░░░]  88.13% (~88.63%)  7,393,546 of 8,388,608 bytes</code><br><code>eu-x     [█████████████████░░░]  87.50% (~88.11%)  7,340,233 of 8,388,608 bytes</code><br><code>us       [█████████████████░░░]  88.88% (~89.38%)  7,456,403 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  97.80% (~98.35%)  8,204,628 of 8,388,608 bytes</code></pre>

<img src="docs/overview-us-rev1.svg" width="720">

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████████▒░░░]  81.43% (~85.28%)  899,916 of 1,105,028 (10,692 asm)</code><br><code>data      [█████████████████░░░]  89.18%  218,858 of 245,388</code><br><code>functions [██████████████████▒░]  92.90% (~95.13%)  3,952 of 4,254 (42 asm)</code><br><code>blobs     [███████████████████░]  95.80% (~96.90%)  6,710,329 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████████▒░░░]  81.48% (~85.16%)  905,224 of 1,110,880 (10,808 asm)</code><br><code>data      [█████████████░░░░░░░]  68.39%  178,194 of 260,528</code><br><code>functions [██████████████████▒░]  92.72% (~95.00%)  3,950 of 4,260 (43 asm)</code><br><code>blobs     [█████████████████░░░]  89.89% (~89.90%)  6,289,936 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████████████░░░░]  81.09% (~84.93%)  901,064 of 1,111,180 (10,808 asm)</code><br><code>data      [█████████████░░░░░░░]  67.33%  128,537 of 190,900</code><br><code>functions [██████████████████▒░]  92.83% (~95.06%)  3,949 of 4,254 (43 asm)</code><br><code>blobs     [█████████████████░░░]  89.01% (~89.14%)  6,290,440 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [████████████████▒░░░]  83.64% (~87.44%)  915,120 of 1,094,076 (9,204 asm)</code><br><code>data      [████████████████░░░░]  84.54%  230,643 of 272,820</code><br><code>functions [██████████████████▒░]  93.41% (~95.64%)  3,928 of 4,205 (41 asm)</code><br><code>blobs     [█████████████████░░░]  89.84%  6,290,448 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [████████████████▒░░░]  84.73% (~88.79%)  955,952 of 1,128,112 (10,812 asm)</code><br><code>data      [███████████████████░]  95.76%  232,113 of 242,376</code><br><code>functions [██████████████████▒░]  94.36% (~96.59%)  4,105 of 4,350 (43 asm)</code><br><code>blobs     [███████████████████░]  99.97%  6,996,371 of 6,997,928</code></pre> |
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

