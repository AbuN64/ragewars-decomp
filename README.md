# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  98.34% (~99.72%)  41,250,764 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  97.50% (~99.67%)  8,179,246 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  98.12% (~99.49%)  8,231,355 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  98.01% (~99.51%)  8,222,510 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.92% (~99.94%)  8,298,117 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████▒]  99.17% (~100.00%)  8,319,536 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████████████▒░]  90.32% (~99.80%)  998,964 of 1,105,968</code><br><code>data      [████████████████████]  100.00%  244,444 of 244,444</code><br><code>functions [███████████████████░]  96.67% (~99.95%)  4,100 of 4,241</code><br><code>blobs     [███████████████████░]  98.50% (~99.60%)  6,899,550 of 7,004,340</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  89.37% (~99.63%)  993,672 of 1,111,824</code><br><code>data      [████████████████████]  100.00%  259,580 of 259,580</code><br><code>functions [███████████████████░]  96.12% (~99.90%)  4,088 of 4,253</code><br><code>blobs     [███████████████████░]  99.44%  6,957,911 of 6,997,012</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  89.02% (~99.60%)  990,020 of 1,112,112</code><br><code>data      [████████████████████]  100.00%  189,964 of 189,964</code><br><code>functions [███████████████████░]  96.12% (~99.88%)  4,089 of 4,254</code><br><code>blobs     [███████████████████░]  99.37% (~99.49%)  7,022,334 of 7,066,340</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████████████▒░]  91.82% (~99.66%)  1,006,920 of 1,096,588</code><br><code>data      [████████████████████]  100.00%  270,304 of 270,304</code><br><code>functions [███████████████████░]  97.18% (~99.92%)  4,081 of 4,199</code><br><code>blobs     [███████████████████░]  99.98%  7,000,701 of 7,001,524</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████████▒▒]  93.88% (~100.00%)  1,060,872 of 1,129,944</code><br><code>data      [████████████████████]  100.00%  240,460 of 240,460</code><br><code>functions [███████████████████▒]  97.79% (~100.00%)  4,256 of 4,352</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

