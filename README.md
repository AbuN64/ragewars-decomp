# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  97.08% (~98.69%)  40,722,134 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  96.86% (~99.25%)  8,125,599 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  95.53% (~97.11%)  8,014,049 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  95.45% (~97.17%)  8,007,169 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.66% (~99.94%)  8,276,329 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.93% (~99.99%)  8,298,988 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  88.66% (~99.87%)  980,608 of 1,105,964</code><br><code>data      [███████████████████░]  99.91%  244,252 of 244,448</code><br><code>functions [███████████████████░]  96.08% (~99.97%)  4,074 of 4,240</code><br><code>blobs     [███████████████████░]  98.00% (~99.10%)  6,864,451 of 7,004,340</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.86% (~99.71%)  976,908 of 1,111,824</code><br><code>data      [███████████████████░]  99.92%  259,388 of 259,580</code><br><code>functions [███████████████████░]  95.57% (~99.92%)  4,065 of 4,253</code><br><code>blobs     [███████████████████░]  96.57% (~96.58%)  6,757,561 of 6,997,012</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.46% (~99.71%)  972,708 of 1,112,120</code><br><code>data      [███████████████████░]  99.90%  189,776 of 189,956</code><br><code>functions [███████████████████░]  95.57% (~99.92%)  4,065 of 4,253</code><br><code>blobs     [███████████████████░]  96.57% (~96.69%)  6,824,493 of 7,066,340</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████████████▒░]  90.04% (~99.87%)  987,424 of 1,096,588</code><br><code>data      [███████████████████░]  99.92%  270,108 of 270,304</code><br><code>functions [███████████████████░]  96.57% (~99.97%)  4,055 of 4,199</code><br><code>blobs     [███████████████████░]  99.95%  6,998,605 of 7,001,524</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████████▒▒]  92.08% (~100.00%)  1,040,548 of 1,129,952</code><br><code>data      [███████████████████░]  99.91%  240,236 of 240,452</code><br><code>functions [███████████████████▒]  97.17% (~100.00%)  4,228 of 4,351</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

