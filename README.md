# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  96.66% (~98.58%)  40,545,962 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  96.57% (~99.27%)  8,100,891 of 8,388,608 bytes</code><br><code>eu       [██████████████████▒░]  94.98% (~96.82%)  7,968,246 of 8,388,608 bytes</code><br><code>eu-x     [██████████████████▒░]  94.90% (~96.90%)  7,961,380 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.32% (~99.90%)  8,247,697 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████▒]  98.55% (~100.00%)  8,267,748 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.41% (~99.96%)  956,176 of 1,106,436</code><br><code>data      [████████████████████]  100.00%  243,980 of 243,980</code><br><code>functions [███████████████████░]  95.44% (~99.97%)  4,045 of 4,238</code><br><code>blobs     [███████████████████░]  98.00% (~99.10%)  6,864,447 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.01% (~99.83%)  956,704 of 1,112,292</code><br><code>data      [████████████████████]  100.00%  259,116 of 259,116</code><br><code>functions [███████████████████░]  95.05% (~99.95%)  4,040 of 4,250</code><br><code>blobs     [███████████████████░]  96.21% (~96.22%)  6,732,234 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.47% (~99.83%)  951,012 of 1,112,588</code><br><code>data      [████████████████████]  100.00%  189,492 of 189,492</code><br><code>functions [███████████████████░]  95.08% (~99.95%)  4,040 of 4,249</code><br><code>blobs     [███████████████████░]  96.24% (~96.35%)  6,800,684 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.79% (~99.96%)  961,780 of 1,095,488</code><br><code>data      [████████████████████]  100.00%  271,408 of 271,408</code><br><code>functions [███████████████████░]  95.92% (~99.97%)  4,023 of 4,194</code><br><code>blobs     [███████████████████░]  99.89%  6,994,317 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [█████████████████▒▒▒]  89.29% (~100.00%)  1,008,656 of 1,129,516</code><br><code>data      [████████████████████]  100.00%  240,888 of 240,888</code><br><code>functions [███████████████████▒]  96.43% (~100.00%)  4,190 of 4,345</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

