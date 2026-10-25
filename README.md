# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  99.11% (~99.72%)  41,572,200 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  98.25% (~99.66%)  8,242,384 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  98.87% (~99.48%)  8,294,547 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  98.79% (~99.51%)  8,287,448 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  99.67% (~99.94%)  8,361,485 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████▒]  99.97% (~100.00%)  8,386,336 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [███████████████████░]  96.06% (~99.80%)  1,062,480 of 1,105,976</code><br><code>data      [███████████████████░]  99.84%  244,062 of 244,432</code><br><code>functions [███████████████████░]  98.65% (~99.95%)  4,185 of 4,242</code><br><code>blobs     [███████████████████░]  98.50% (~99.60%)  6,899,554 of 7,004,344</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [███████████████████░]  95.09% (~99.58%)  1,056,932 of 1,111,448</code><br><code>data      [███████████████████░]  99.82%  259,508 of 259,952</code><br><code>functions [███████████████████░]  98.09% (~99.88%)  4,172 of 4,253</code><br><code>blobs     [███████████████████░]  99.44%  6,957,915 of 6,997,016</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████████████▒░]  94.89% (~99.60%)  1,055,400 of 1,112,124</code><br><code>data      [███████████████████░]  99.77%  189,518 of 189,948</code><br><code>functions [███████████████████░]  98.14% (~99.88%)  4,176 of 4,255</code><br><code>blobs     [███████████████████░]  99.37% (~99.49%)  7,022,338 of 7,066,344</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [███████████████████░]  97.61% (~99.66%)  1,070,444 of 1,096,596</code><br><code>data      [███████████████████░]  99.94%  270,144 of 270,292</code><br><code>functions [███████████████████░]  99.19% (~99.92%)  4,166 of 4,200</code><br><code>blobs     [███████████████████░]  99.98%  7,000,705 of 7,001,528</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████████████▒]  99.79% (~100.00%)  1,127,680 of 1,129,952</code><br><code>data      [████████████████████]  100.00%  240,448 of 240,448</code><br><code>functions [███████████████████▒]  99.83% (~100.00%)  4,346 of 4,353</code><br><code>blobs     [████████████████████]  100.00%  6,998,016 of 6,998,016</code></pre> |
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

