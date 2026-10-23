# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  96.87% (~98.69%)  40,632,020 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  96.64% (~99.26%)  8,106,931 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  95.33% (~97.11%)  7,997,473 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  95.25% (~97.17%)  7,990,353 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.44% (~99.94%)  8,258,021 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.69% (~99.99%)  8,279,242 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.96% (~99.87%)  962,608 of 1,106,828</code><br><code>data      [████████████████████]  100.00%  243,584 of 243,584</code><br><code>functions [███████████████████░]  95.63% (~99.97%)  4,055 of 4,240</code><br><code>blobs     [███████████████████░]  98.00% (~99.10%)  6,864,451 of 7,004,340</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.36% (~99.71%)  961,000 of 1,112,684</code><br><code>data      [████████████████████]  100.00%  258,720 of 258,720</code><br><code>functions [███████████████████░]  95.17% (~99.92%)  4,047 of 4,252</code><br><code>blobs     [███████████████████░]  96.57% (~96.58%)  6,757,561 of 6,997,012</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  85.94% (~99.71%)  956,572 of 1,112,980</code><br><code>data      [████████████████████]  100.00%  189,096 of 189,096</code><br><code>functions [███████████████████░]  95.20% (~99.92%)  4,047 of 4,251</code><br><code>blobs     [███████████████████░]  96.57% (~96.69%)  6,824,493 of 7,066,340</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  88.35% (~99.87%)  968,248 of 1,095,916</code><br><code>data      [████████████████████]  100.00%  270,976 of 270,976</code><br><code>functions [███████████████████░]  96.11% (~99.97%)  4,033 of 4,196</code><br><code>blobs     [███████████████████░]  99.95%  6,998,605 of 7,001,524</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████████▒▒]  90.35% (~100.00%)  1,020,924 of 1,129,948</code><br><code>data      [███████████████████░]  99.85%  240,114 of 240,456</code><br><code>functions [███████████████████▒]  96.73% (~100.00%)  4,206 of 4,348</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

