# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  98.19% (~99.73%)  41,185,780 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  97.34% (~99.68%)  8,166,082 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  97.97% (~99.50%)  8,218,831 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  97.87% (~99.53%)  8,210,378 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.76% (~99.97%)  8,284,953 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████▒]  99.00% (~100.00%)  8,305,536 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  89.13% (~99.87%)  985,800 of 1,105,968</code><br><code>data      [████████████████████]  100.00%  244,444 of 244,444</code><br><code>functions [███████████████████░]  96.25% (~99.97%)  4,082 of 4,241</code><br><code>blobs     [███████████████████░]  98.50% (~99.60%)  6,899,550 of 7,004,340</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  88.24% (~99.71%)  981,148 of 1,111,824</code><br><code>data      [████████████████████]  100.00%  259,580 of 259,580</code><br><code>functions [███████████████████░]  95.72% (~99.92%)  4,071 of 4,253</code><br><code>blobs     [███████████████████░]  99.44%  6,957,911 of 6,997,012</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.93% (~99.71%)  977,896 of 1,112,120</code><br><code>data      [████████████████████]  100.00%  189,956 of 189,956</code><br><code>functions [███████████████████░]  95.74% (~99.92%)  4,072 of 4,253</code><br><code>blobs     [███████████████████░]  99.37% (~99.49%)  7,022,334 of 7,066,340</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████████████▒░]  90.62% (~99.87%)  993,756 of 1,096,588</code><br><code>data      [████████████████████]  100.00%  270,304 of 270,304</code><br><code>functions [███████████████████░]  96.76% (~99.97%)  4,063 of 4,199</code><br><code>blobs     [███████████████████░]  99.98%  7,000,701 of 7,001,524</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████████▒▒]  92.64% (~100.00%)  1,046,880 of 1,129,952</code><br><code>data      [████████████████████]  100.00%  240,452 of 240,452</code><br><code>functions [███████████████████▒]  97.35% (~100.00%)  4,236 of 4,351</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

