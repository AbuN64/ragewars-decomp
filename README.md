# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████████░░]  91.97% (~93.92%)  38,576,531 of 41,943,040 bytes</code><br><code>de       [██████████████████▒░]  94.39% (~97.13%)  7,918,134 of 8,388,608 bytes</code><br><code>eu       [█████████████████▒░░]  89.16% (~91.04%)  7,480,114 of 8,388,608 bytes</code><br><code>eu-x     [█████████████████▒░░]  88.26% (~90.30%)  7,403,894 of 8,388,608 bytes</code><br><code>us       [█████████████████▒░░]  89.68% (~91.28%)  7,523,338 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.36% (~99.87%)  8,251,051 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.12% (~99.96%)  952,888 of 1,106,440</code><br><code>data      [█████████████████░░░]  89.30%  217,878 of 243,976</code><br><code>functions [███████████████████░]  95.37% (~99.97%)  4,042 of 4,238</code><br><code>blobs     [███████████████████░]  95.81% (~96.91%)  6,711,080 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.71% (~99.83%)  953,412 of 1,112,292</code><br><code>data      [████████████████░░░░]  83.24%  215,710 of 259,116</code><br><code>functions [██████████████████▒░]  94.98% (~99.95%)  4,036 of 4,249</code><br><code>blobs     [█████████████████░░░]  89.90% (~89.91%)  6,290,800 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.18% (~99.83%)  947,724 of 1,112,592</code><br><code>data      [███████████████░░░░░]  75.85%  143,742 of 189,488</code><br><code>functions [███████████████████░]  95.01% (~99.95%)  4,037 of 4,249</code><br><code>blobs     [█████████████████░░░]  89.04% (~89.15%)  6,292,236 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.68% (~99.96%)  960,628 of 1,095,488</code><br><code>data      [██████████████████░░]  92.55%  251,206 of 271,408</code><br><code>functions [███████████████████░]  95.87% (~99.97%)  4,020 of 4,193</code><br><code>blobs     [█████████████████░░░]  89.85%  6,291,312 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████████▒▒▒]  88.74% (~100.00%)  1,002,424 of 1,129,524</code><br><code>data      [███████████████████░]  95.66%  230,507 of 240,964</code><br><code>functions [███████████████████▒]  96.27% (~100.00%)  4,183 of 4,345</code><br><code>blobs     [████████████████████]  100.00%  6,997,928 of 6,997,928</code></pre> |
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

