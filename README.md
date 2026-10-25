# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  99.10% (~99.72%)  41,569,148 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  98.24% (~99.66%)  8,241,656 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  98.87% (~99.48%)  8,293,967 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  98.78% (~99.51%)  8,286,868 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  99.66% (~99.94%)  8,360,901 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████▒]  99.96% (~100.00%)  8,385,756 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [███████████████████░]  96.00% (~99.80%)  1,061,764 of 1,105,984</code><br><code>data      [███████████████████░]  99.84%  244,050 of 244,424</code><br><code>functions [███████████████████░]  98.75% (~99.95%)  4,189 of 4,242</code><br><code>blobs     [███████████████████░]  98.50% (~99.60%)  6,899,554 of 7,004,344</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [███████████████████░]  95.04% (~99.58%)  1,056,360 of 1,111,456</code><br><code>data      [███████████████████░]  99.82%  259,500 of 259,944</code><br><code>functions [███████████████████░]  98.21% (~99.88%)  4,177 of 4,253</code><br><code>blobs     [███████████████████░]  99.44%  6,957,915 of 6,997,016</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████████████▒░]  94.84% (~99.60%)  1,054,828 of 1,112,132</code><br><code>data      [███████████████████░]  99.77%  189,510 of 189,940</code><br><code>functions [███████████████████░]  98.26% (~99.88%)  4,181 of 4,255</code><br><code>blobs     [███████████████████░]  99.37% (~99.49%)  7,022,338 of 7,066,344</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [███████████████████░]  97.56% (~99.66%)  1,069,872 of 1,096,604</code><br><code>data      [███████████████████░]  99.94%  270,132 of 270,284</code><br><code>functions [███████████████████░]  99.30% (~99.92%)  4,171 of 4,200</code><br><code>blobs     [███████████████████░]  99.98%  7,000,705 of 7,001,528</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████████████▒]  99.74% (~100.00%)  1,127,108 of 1,129,960</code><br><code>data      [████████████████████]  100.00%  240,440 of 240,440</code><br><code>functions [███████████████████▒]  99.95% (~100.00%)  4,351 of 4,353</code><br><code>blobs     [████████████████████]  100.00%  6,998,016 of 6,998,016</code></pre> |
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

