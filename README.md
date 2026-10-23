# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  96.84% (~98.69%)  40,621,384 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  96.61% (~99.26%)  8,104,775 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  95.32% (~97.11%)  7,996,585 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  95.22% (~97.17%)  7,988,201 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.41% (~99.94%)  8,255,865 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.65% (~99.99%)  8,275,958 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.77% (~99.87%)  960,448 of 1,106,824</code><br><code>data      [████████████████████]  100.00%  243,588 of 243,588</code><br><code>functions [███████████████████░]  95.58% (~99.97%)  4,052 of 4,239</code><br><code>blobs     [███████████████████░]  98.00% (~99.10%)  6,864,451 of 7,004,340</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.28% (~99.71%)  960,108 of 1,112,680</code><br><code>data      [████████████████████]  100.00%  258,724 of 258,724</code><br><code>functions [███████████████████░]  95.15% (~99.92%)  4,045 of 4,251</code><br><code>blobs     [███████████████████░]  96.57% (~96.58%)  6,757,561 of 6,997,012</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.75% (~99.71%)  954,416 of 1,112,976</code><br><code>data      [████████████████████]  100.00%  189,100 of 189,100</code><br><code>functions [███████████████████░]  95.17% (~99.92%)  4,045 of 4,250</code><br><code>blobs     [███████████████████░]  96.57% (~96.69%)  6,824,493 of 7,066,340</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  88.15% (~99.87%)  966,092 of 1,095,916</code><br><code>data      [████████████████████]  100.00%  270,976 of 270,976</code><br><code>functions [███████████████████░]  96.06% (~99.97%)  4,031 of 4,196</code><br><code>blobs     [███████████████████░]  99.95%  6,998,605 of 7,001,524</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████████▒▒]  90.06% (~100.00%)  1,017,636 of 1,129,944</code><br><code>data      [███████████████████░]  99.85%  240,118 of 240,460</code><br><code>functions [███████████████████▒]  96.68% (~100.00%)  4,203 of 4,347</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

