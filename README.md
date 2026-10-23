# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  97.05% (~98.69%)  40,706,818 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  96.82% (~99.25%)  8,122,411 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  95.49% (~97.11%)  8,010,861 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  95.42% (~97.17%)  8,004,609 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.62% (~99.94%)  8,273,141 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.89% (~99.99%)  8,295,796 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  88.37% (~99.87%)  977,404 of 1,105,964</code><br><code>data      [███████████████████░]  99.92%  244,268 of 244,448</code><br><code>functions [███████████████████░]  95.99% (~99.97%)  4,070 of 4,240</code><br><code>blobs     [███████████████████░]  98.00% (~99.10%)  6,864,451 of 7,004,340</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.57% (~99.71%)  973,704 of 1,111,824</code><br><code>data      [███████████████████░]  99.93%  259,404 of 259,580</code><br><code>functions [███████████████████░]  95.48% (~99.92%)  4,061 of 4,253</code><br><code>blobs     [███████████████████░]  96.57% (~96.58%)  6,757,561 of 6,997,012</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.23% (~99.71%)  970,152 of 1,112,124</code><br><code>data      [███████████████████░]  99.90%  189,772 of 189,952</code><br><code>functions [███████████████████░]  95.50% (~99.92%)  4,062 of 4,253</code><br><code>blobs     [███████████████████░]  96.57% (~96.69%)  6,824,493 of 7,066,340</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  89.75% (~99.87%)  984,220 of 1,096,588</code><br><code>data      [███████████████████░]  99.93%  270,124 of 270,304</code><br><code>functions [███████████████████░]  96.47% (~99.97%)  4,051 of 4,199</code><br><code>blobs     [███████████████████░]  99.95%  6,998,605 of 7,001,524</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████████▒▒]  91.80% (~100.00%)  1,037,344 of 1,129,956</code><br><code>data      [███████████████████░]  99.91%  240,248 of 240,448</code><br><code>functions [███████████████████▒]  97.08% (~100.00%)  4,224 of 4,351</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

