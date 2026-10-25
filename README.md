# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  98.69% (~99.72%)  41,394,396 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  97.84% (~99.67%)  8,207,462 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  98.45% (~99.48%)  8,259,011 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  98.37% (~99.51%)  8,252,298 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  99.25% (~99.94%)  8,326,333 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████▒]  99.53% (~100.00%)  8,349,292 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████████████▒░]  92.87% (~99.80%)  1,027,188 of 1,105,976</code><br><code>data      [████████████████████]  100.00%  244,436 of 244,436</code><br><code>functions [███████████████████░]  97.26% (~99.95%)  4,126 of 4,242</code><br><code>blobs     [███████████████████░]  98.50% (~99.60%)  6,899,550 of 7,004,340</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [██████████████████▒░]  91.86% (~99.58%)  1,021,336 of 1,111,832</code><br><code>data      [████████████████████]  100.00%  259,572 of 259,572</code><br><code>functions [███████████████████░]  96.68% (~99.88%)  4,113 of 4,254</code><br><code>blobs     [███████████████████░]  99.44%  6,957,911 of 6,997,012</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████████████▒░]  91.70% (~99.60%)  1,019,816 of 1,112,120</code><br><code>data      [████████████████████]  100.00%  189,956 of 189,956</code><br><code>functions [███████████████████░]  96.75% (~99.88%)  4,117 of 4,255</code><br><code>blobs     [███████████████████░]  99.37% (~99.49%)  7,022,334 of 7,066,340</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████████████▒░]  94.39% (~99.66%)  1,035,144 of 1,096,596</code><br><code>data      [████████████████████]  100.00%  270,296 of 270,296</code><br><code>functions [███████████████████░]  97.78% (~99.92%)  4,107 of 4,200</code><br><code>blobs     [███████████████████░]  99.98%  7,000,701 of 7,001,524</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████████████▒]  96.52% (~100.00%)  1,090,636 of 1,129,952</code><br><code>data      [████████████████████]  100.00%  240,452 of 240,452</code><br><code>functions [███████████████████▒]  98.41% (~100.00%)  4,284 of 4,353</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

