# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  96.31% (~98.26%)  40,396,863 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  95.51% (~98.25%)  8,012,006 of 8,388,608 bytes</code><br><code>eu       [██████████████████▒░]  94.66% (~96.54%)  7,941,290 of 8,388,608 bytes</code><br><code>eu-x     [██████████████████▒░]  94.59% (~96.63%)  7,935,585 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.30% (~99.90%)  8,246,474 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████▒]  98.48% (~100.00%)  8,261,508 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.12% (~99.96%)  952,888 of 1,106,440</code><br><code>data      [████████████████████]  100.00%  243,976 of 243,976</code><br><code>functions [███████████████████░]  95.37% (~99.97%)  4,042 of 4,238</code><br><code>blobs     [███████████████████░]  96.78% (~97.87%)  6,778,854 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.71% (~99.83%)  953,412 of 1,112,292</code><br><code>data      [████████████████████]  100.00%  259,116 of 259,116</code><br><code>functions [██████████████████▒░]  94.98% (~99.95%)  4,036 of 4,249</code><br><code>blobs     [███████████████████░]  95.87% (~95.88%)  6,708,570 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.18% (~99.83%)  947,724 of 1,112,592</code><br><code>data      [████████████████████]  100.00%  189,488 of 189,488</code><br><code>functions [███████████████████░]  95.01% (~99.95%)  4,037 of 4,249</code><br><code>blobs     [███████████████████░]  95.92% (~96.03%)  6,778,181 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.68% (~99.96%)  960,628 of 1,095,488</code><br><code>data      [███████████████████░]  99.99%  271,392 of 271,408</code><br><code>functions [███████████████████░]  95.87% (~99.97%)  4,020 of 4,193</code><br><code>blobs     [███████████████████░]  99.89%  6,994,262 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████████▒▒▒]  88.74% (~100.00%)  1,002,424 of 1,129,524</code><br><code>data      [████████████████████]  100.00%  240,880 of 240,880</code><br><code>functions [███████████████████▒]  96.27% (~100.00%)  4,183 of 4,345</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

