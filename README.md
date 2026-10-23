# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  96.93% (~98.69%)  40,658,878 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  96.70% (~99.26%)  8,112,235 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  95.38% (~97.11%)  8,001,441 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  95.31% (~97.17%)  7,995,189 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  98.52% (~99.94%)  8,264,481 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  98.77% (~99.99%)  8,285,532 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [█████████████████▒▒░]  87.45% (~99.87%)  968,008 of 1,106,828</code><br><code>data      [███████████████████░]  99.96%  243,488 of 243,584</code><br><code>functions [███████████████████░]  95.75% (~99.97%)  4,060 of 4,240</code><br><code>blobs     [███████████████████░]  98.00% (~99.10%)  6,864,451 of 7,004,340</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.73% (~99.71%)  965,060 of 1,112,684</code><br><code>data      [███████████████████░]  99.96%  258,628 of 258,720</code><br><code>functions [███████████████████░]  95.27% (~99.92%)  4,051 of 4,252</code><br><code>blobs     [███████████████████░]  96.57% (~96.58%)  6,757,561 of 6,997,012</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [█████████████████▒▒░]  86.39% (~99.71%)  961,508 of 1,112,984</code><br><code>data      [███████████████████░]  99.94%  188,996 of 189,092</code><br><code>functions [███████████████████░]  95.29% (~99.92%)  4,052 of 4,252</code><br><code>blobs     [███████████████████░]  96.57% (~96.69%)  6,824,493 of 7,066,340</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [█████████████████▒▒░]  88.94% (~99.87%)  974,804 of 1,095,916</code><br><code>data      [███████████████████░]  99.96%  270,880 of 270,976</code><br><code>functions [███████████████████░]  96.25% (~99.97%)  4,039 of 4,196</code><br><code>blobs     [███████████████████░]  99.95%  6,998,605 of 7,001,524</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [██████████████████▒▒]  90.89% (~100.00%)  1,027,016 of 1,129,952</code><br><code>data      [███████████████████░]  99.94%  240,312 of 240,452</code><br><code>functions [███████████████████▒]  96.84% (~100.00%)  4,212 of 4,349</code><br><code>blobs     [████████████████████]  100.00%  6,998,012 of 6,998,012</code></pre> |
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

