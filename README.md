# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  99.53% (~99.74%)  41,749,584 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  98.76% (~99.68%)  8,284,953 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  99.51% (~99.52%)  8,348,270 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  99.45% (~99.55%)  8,343,273 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  99.97%  8,386,841 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  99.97%  8,386,247 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [███████████████████░]  99.96% (~99.97%)  1,106,744 of 1,107,144</code><br><code>data      [███████████████████░]  99.63%  242,357 of 243,254</code><br><code>functions [███████████████████░]  99.95% (~99.97%)  4,248 of 4,250</code><br><code>blobs     [███████████████████░]  98.47% (~99.57%)  6,899,564 of 7,006,434</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [███████████████████░]  99.97%  1,112,364 of 1,112,620</code><br><code>data      [███████████████████░]  99.62%  257,791 of 258,768</code><br><code>functions [███████████████████░]  99.97%  4,251 of 4,252</code><br><code>blobs     [███████████████████░]  99.44%  6,957,923 of 6,997,028</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [███████████████████░]  99.97%  1,113,116 of 1,113,372</code><br><code>data      [███████████████████░]  99.43%  187,623 of 188,696</code><br><code>functions [███████████████████░]  99.97%  4,253 of 4,254</code><br><code>blobs     [███████████████████░]  99.37% (~99.49%)  7,022,342 of 7,066,348</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [███████████████████░]  99.97%  1,097,512 of 1,097,768</code><br><code>data      [███████████████████░]  99.74%  268,420 of 269,108</code><br><code>functions [███████████████████░]  99.97%  4,200 of 4,201</code><br><code>blobs     [███████████████████░]  99.98%  7,000,717 of 7,001,540</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████████████░]  99.97%  1,130,080 of 1,130,336</code><br><code>data      [███████████████████░]  99.12%  237,951 of 240,056</code><br><code>functions [███████████████████░]  99.97%  4,354 of 4,355</code><br><code>blobs     [████████████████████]  100.00%  6,998,024 of 6,998,024</code></pre> |
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

