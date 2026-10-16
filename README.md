# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [████████████▒▒▒▒▒░░░]  60.34% (~86.67%)  4,138,316 of 6,857,872 bytes</code><br><code>de       [████████████▒▒▒▒▒░░░]  61.41% (~87.42%)  849,080 of 1,382,608 bytes</code><br><code>eu       [███████████▒▒▒▒▒░░░░]  57.05% (~83.02%)  791,688 of 1,387,504 bytes</code><br><code>eu-x     [███████████▒▒▒▒▒░░░░]  56.30% (~83.57%)  742,256 of 1,318,176 bytes</code><br><code>us       [████████████▒▒▒▒▒░░░]  62.90% (~88.63%)  869,979 of 1,382,992 bytes</code><br><code>us-rev1  [████████████▒▒▒▒▒▒░░]  63.84% (~90.56%)  885,313 of 1,386,592 bytes</code><br><code>perfect  [░░░░░░░░░░░░░░░░░░░░]   0.03%  2,664 of 6,857,872 bytes</code></pre>

<a href="https://itsmo.me/attic/cake-unbake/#nus-nrwe-1"><img src="docs/overview-us-rev1.svg" width="720"></a>

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒▒░░░]  53.10% (~85.64%)  586,988 of 1,105,260</code><br><code>data      [██████████████████░░]  94.49%  262,092 of 277,348</code><br><code>functions [█████████████▒▒▒▒▒░░]  65.49% (~94.26%)  2,261 of 3,452</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒▒░░░]  52.68% (~85.09%)  585,860 of 1,111,912</code><br><code>data      [██████████████░░░░░░]  74.68%  205,828 of 275,592</code><br><code>functions [████████████▒▒▒▒▒▒░░]  64.98% (~93.75%)  2,248 of 3,459</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒▒░░░]  52.72% (~85.03%)  586,416 of 1,112,232</code><br><code>data      [███████████████░░░░░]  75.67%  155,840 of 205,944</code><br><code>functions [█████████████▒▒▒▒▒░░]  65.28% (~94.04%)  2,257 of 3,457</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [██████████▒▒▒▒▒▒▒░░░]  54.53% (~87.97%)  580,292 of 1,064,056</code><br><code>data      [██████████████████░░]  90.82%  289,687 of 318,936</code><br><code>functions [█████████████▒▒▒▒▒▒░]  66.42% (~95.30%)  2,234 of 3,363</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [███████████▒▒▒▒▒▒░░░]  55.76% (~88.54%)  630,208 of 1,130,188</code><br><code>data      [███████████████████░]  99.49%  255,105 of 256,404</code><br><code>functions [█████████████▒▒▒▒▒▒░]  67.40% (~96.58%)  2,351 of 3,488</code></pre> |
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

