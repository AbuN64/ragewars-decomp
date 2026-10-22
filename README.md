# Turok: Rage Wars decompilation

A matching decompilation of *Turok: Rage Wars* for the Nintendo 64.

> **This repository contains no game content.** You must supply a legally acquired cartridge dump. Builds are verified against its SHA256.

## Progress

<!-- progress -->
<pre><code>all      [██████████████████░░]  91.36% (~92.08%)  38,321,795 of 41,943,040 bytes</code><br><code>de       [██████████████████▒░]  93.91% (~95.34%)  7,877,862 of 8,388,608 bytes</code><br><code>eu       [█████████████████░░░]  88.27% (~88.77%)  7,405,174 of 8,388,608 bytes</code><br><code>eu-x     [█████████████████░░░]  87.65% (~88.26%)  7,352,705 of 8,388,608 bytes</code><br><code>us       [█████████████████░░░]  89.02% (~89.53%)  7,468,371 of 8,388,608 bytes</code><br><code>us-rev1  [███████████████████░]  97.96% (~98.51%)  8,217,683 of 8,388,608 bytes</code></pre>

<img src="docs/overview-us-rev1.svg" width="720">

| de (NUS-NRWD-0, Germany). Censored German release. SHA256 `9dc401252bacb2ad7412ef003f97f28cb225d76b3cc76f430fbc27fa05067ca8` |
|---|
| <pre><code>code      [████████████████▒░░░]  81.83% (~85.75%)  904,252 of 1,105,028 (10,692 asm)</code><br><code>data      [██████████████████░░]  92.19%  226,242 of 245,388</code><br><code>functions [██████████████████▒░]  93.08% (~95.25%)  3,960 of 4,254 (42 asm)</code><br><code>blobs     [███████████████████░]  95.81% (~96.91%)  6,711,080 of 7,004,336</code></pre> |

| eu (NUS-NRWP-0, Europe). PAL release. SHA256 `d763cbbe485a5f9e1b7be97d5ac16735087e23d0bb62c05dc844e01b7e1156d1` |
|---|
| <pre><code>code      [████████████████▒░░░]  81.73% (~85.47%)  907,988 of 1,110,880 (10,808 asm)</code><br><code>data      [██████████████░░░░░░]  71.46%  186,194 of 260,528</code><br><code>functions [██████████████████▒░]  92.88% (~95.09%)  3,957 of 4,260 (43 asm)</code><br><code>blobs     [█████████████████░░░]  89.90% (~89.91%)  6,290,800 of 6,997,008</code></pre> |

| eu-x (NUS-NRWX-0, Europe). PAL multi-language release. SHA256 `511f6c876586bf401faf01a270c67f26fcb7db55ed3f35759c71ab15a29de750` |
|---|
| <pre><code>code      [████████████████▒░░░]  81.33% (~85.24%)  903,828 of 1,111,180 (10,808 asm)</code><br><code>data      [██████████████░░░░░░]  71.47%  136,449 of 190,900</code><br><code>functions [██████████████████▒░]  92.99% (~95.15%)  3,956 of 4,254 (43 asm)</code><br><code>blobs     [█████████████████░░░]  89.04% (~89.15%)  6,292,236 of 7,066,336</code></pre> |

| us (NUS-NRWE-0, North America). First NTSC release (black cartridge). SHA256 `0433043aaba2649bdd1fe717c4020550ac663c0362527aa082490f5977a3e46b` |
|---|
| <pre><code>code      [████████████████▒░░░]  83.89% (~87.76%)  917,884 of 1,094,076 (9,204 asm)</code><br><code>data      [█████████████████░░░]  87.59%  238,983 of 272,820</code><br><code>functions [██████████████████▒░]  93.57% (~95.74%)  3,935 of 4,205 (41 asm)</code><br><code>blobs     [█████████████████░░░]  89.85%  6,291,312 of 7,001,520</code></pre> |

| us-rev1 (NUS-NRWE-1, North America). Revised NTSC release (grey cartridge). SHA256 `5dfbae59e4a3860b740ccbb28f33aad624315e30bfca6d60abd62d12a89e0089` |
|---|
| <pre><code>code      [████████████████▒░░░]  84.98% (~89.11%)  958,716 of 1,128,112 (10,812 asm)</code><br><code>data      [███████████████████░]  99.36%  240,847 of 242,376</code><br><code>functions [██████████████████▒░]  94.52% (~96.68%)  4,112 of 4,350 (43 asm)</code><br><code>blobs     [████████████████████]  100.00%  6,997,928 of 6,997,928</code></pre> |
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

