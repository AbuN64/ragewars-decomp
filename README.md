# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  99.42% (~99.73%)  41,700,528 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  98.65% (~99.67%)  8,275,524 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  99.29% (~99.49%)  8,329,411 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  99.23% (~99.51%)  8,324,496 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  99.92% (~99.96%)  8,382,489 of 8,388,608 bytes</code><br><code>us-rev1  [████████████████████]  100.00%  8,388,608 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [███████████████████░]  99.06% (~99.90%)  1,095,560 of 1,105,900</code><br><code>data      [███████████████████░]  99.84%  244,122 of 244,508</code><br><code>functions [███████████████████░]  99.50% (~99.92%)  4,226 of 4,247</code><br><code>blobs     [███████████████████░]  98.50% (~99.60%)  6,899,554 of 7,004,344</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [███████████████████░]  98.23% (~99.71%)  1,091,780 of 1,111,408</code><br><code>data      [███████████████████░]  99.81%  259,524 of 259,992</code><br><code>functions [███████████████████░]  99.03% (~99.83%)  4,213 of 4,254</code><br><code>blobs     [███████████████████░]  99.44%  6,957,915 of 6,997,016</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [███████████████████░]  98.23% (~99.63%)  1,092,456 of 1,112,116</code><br><code>data      [███████████████████░]  99.76%  189,510 of 189,956</code><br><code>functions [███████████████████░]  99.15% (~99.83%)  4,219 of 4,255</code><br><code>blobs     [███████████████████░]  99.37% (~99.49%)  7,022,338 of 7,066,344</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [███████████████████░]  99.53% (~99.85%)  1,091,408 of 1,096,536</code><br><code>data      [███████████████████░]  99.93%  270,184 of 270,352</code><br><code>functions [███████████████████░]  99.73% (~99.92%)  4,188 of 4,199</code><br><code>blobs     [███████████████████░]  99.98%  7,000,705 of 7,001,528</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [████████████████████]  100.00%  1,129,960 of 1,129,960</code><br><code>data      [████████████████████]  100.00%  240,440 of 240,440</code><br><code>functions [████████████████████]  100.00%  4,353 of 4,353</code><br><code>blobs     [████████████████████]  100.00%  6,998,016 of 6,998,016</code></pre> |
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

