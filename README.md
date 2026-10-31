# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [███████████████████░]  99.89%  41,900,686 of 41,943,040 bytes</code><br><code>de       [███████████████████░]  99.87%  8,378,086 of 8,388,608 bytes</code><br><code>eu       [███████████████████░]  99.81%  8,372,850 of 8,388,608 bytes</code><br><code>eu-x     [███████████████████░]  99.81%  8,373,170 of 8,388,608 bytes</code><br><code>us       [███████████████████░]  99.99%  8,388,056 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  99.99%  8,388,524 of 8,388,608 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#ragewars-decomp-us-rev1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████████████]  100.00%  1,109,460 of 1,109,460</code><br><code>data      [███████████████████░]  99.99%  254,986 of 254,998</code><br><code>functions [████████████████████]  100.00%  4,249 of 4,249</code><br><code>blobs     [███████████████████░]  99.84%  6,977,352 of 6,988,486</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████████████]  100.00%  1,114,888 of 1,114,888</code><br><code>data      [███████████████████░]  99.99%  334,088 of 334,100</code><br><code>functions [████████████████████]  100.00%  4,254 of 4,254</code><br><code>blobs     [███████████████████░]  99.77%  6,903,682 of 6,919,428</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████████████████]  100.00%  1,115,612 of 1,115,612</code><br><code>data      [███████████████████░]  99.98%  241,728 of 241,756</code><br><code>functions [████████████████████]  100.00%  4,256 of 4,256</code><br><code>blobs     [███████████████████░]  99.78%  6,995,638 of 7,011,048</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [████████████████████]  100.00%  1,160,704 of 1,160,704</code><br><code>data      [███████████████████░]  99.99%  208,124 of 208,136</code><br><code>functions [████████████████████]  100.00%  4,325 of 4,325</code><br><code>blobs     [███████████████████░]  99.99%  6,999,036 of 6,999,576</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [████████████████████]  100.00%  1,132,592 of 1,132,592</code><br><code>data      [███████████████████░]  99.99%  237,600 of 237,616</code><br><code>functions [████████████████████]  100.00%  4,355 of 4,355</code><br><code>blobs     [███████████████████░]  99.99%  6,998,140 of 6,998,208</code></pre> |
<!-- /progress -->

## Development & Contributions

Contributions and corrections are welcome. Run `make check` before opening a pull request.

For detailed instructions please see [CONTRIBUTING.md](CONTRIBUTING.md).

## License

[CC0 1.0](LICENSE)

## Dependencies

<!-- dependencies -->
- [GCC 2.8.1](https://github.com/pmret/gcc-papermario)
- [abumas](https://github.com/AbuN64/mas-n64)
<!-- /dependencies -->

