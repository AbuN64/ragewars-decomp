# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [████████████▒▒▒▒▒░░░]  60.07% (~86.51%)  4,119,992 of 6,857,872 bytes</code><br><code>de       [████████████▒▒▒▒▒░░░]  61.39% (~87.42%)  848,836 of 1,382,608 bytes</code><br><code>eu       [███████████▒▒▒▒▒░░░░]  57.08% (~83.03%)  792,000 of 1,387,504 bytes</code><br><code>eu-x     [███████████▒▒▒▒▒░░░░]  56.33% (~83.58%)  742,572 of 1,318,176 bytes</code><br><code>us       [████████████▒▒▒▒▒░░░]  61.53% (~87.82%)  850,963 of 1,382,992 bytes</code><br><code>us-rev1  [████████████▒▒▒▒▒▒░░]  63.87% (~90.57%)  885,621 of 1,386,592 bytes</code><br><code>perfect  [░░░░░░░░░░░░░░░░░░░░]   0.46%  32,144 of 6,857,872 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#nus-nrwe-1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒▒░░░]  53.13% (~85.66%)  587,824 of 1,106,284</code><br><code>data      [██████████████████░░]  94.45%  261,012 of 276,324</code><br><code>functions [█████████████▒▒▒▒▒░░]  65.43% (~94.05%)  2,266 of 3,463</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒▒░░░]  52.71% (~85.10%)  586,200 of 1,111,940</code><br><code>data      [██████████████░░░░░░]  74.68%  205,800 of 275,564</code><br><code>functions [█████████████▒▒▒▒▒░░]  65.03% (~93.64%)  2,252 of 3,463</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒▒░░░]  52.75% (~85.04%)  586,756 of 1,112,256</code><br><code>data      [███████████████░░░░░]  75.66%  155,816 of 205,920</code><br><code>functions [█████████████▒▒▒▒▒░░]  65.34% (~93.95%)  2,261 of 3,460</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒▒░░░]  54.05% (~87.31%)  590,972 of 1,093,356</code><br><code>data      [█████████████████░░░]  89.76%  259,991 of 289,636</code><br><code>functions [█████████████▒▒▒▒▒░░]  66.05% (~94.86%)  2,265 of 3,429</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████▒▒▒▒▒▒░░░]  55.78% (~88.55%)  630,548 of 1,130,220</code><br><code>data      [███████████████████░]  99.49%  255,073 of 256,372</code><br><code>functions [█████████████▒▒▒▒▒▒░]  67.47% (~96.53%)  2,355 of 3,490</code></pre> |
<!-- /progress -->

## Development & Contributions

Contributions and corrections are welcome. Run `make check` before opening a pull request.

For detailed instructions please see [CONTRIBUTING.md](CONTRIBUTING.md).

## License

[CC0 1.0](LICENSE)

## Dependencies

<!-- dependencies -->
| Tool | Used for | Pinned archive |
|---|---|---|
| GCC 2.7.2 (KMC) | compiles C (`gcc-2.7.2-kmc`) | [gcc-2.7.2-linux.tar.gz](https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz) sha256 `ff3e299c1d95` |
| GCC 2.8.1 (SN64) | compiles C (`gcc-2.8.1-sn64`) | [linux.tar.gz](https://github.com/pmret/gcc-papermario/releases/download/master/linux.tar.gz) sha256 `1156cf0d6a88` |
| n64link (SN ASN64-compatible assembler and linker) | assembles and links every unit | [n64link-v0.2.0-linux-x86_64.tar.gz](https://github.com/AbuN64/mas-n64/releases/download/v0.2.0/n64link-v0.2.0-linux-x86_64.tar.gz) sha256 `061d7bc69f21` |
<!-- /dependencies -->

