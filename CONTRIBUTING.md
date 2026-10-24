# Contributing to Turok: Rage Wars

## Build

You need GNU Make, curl, tar, sha256sum, python3, cpp, the MIPS binutils (`mips-linux-gnu-as`, `-ld`, `-objcopy`)
and splat:

```sh
python3 -m pip install "splat64[mips]==0.50.0" "spimdisasm==1.42.4"
```

Put your own big-endian cartridge dumps at these paths:

- `roms/baserom.de.z64`
- `roms/baserom.eu.z64`
- `roms/baserom.eu-x.z64`
- `roms/baserom.us.z64`
- `roms/baserom.us-rev1.z64`

```sh
make
```

`make` (the same as `make check`) splits each dump into `asm/<version>/` with splat the first time (`make extract`
does it again), then builds every version and verifies each ROM's SHA-1. The compilers and n64link are downloaded
into `tools/` and checked against their pinned SHA-256 hashes. Tool commands default to conventional names; put
other paths in `local.mk`.

## Pull requests

Run `make` before opening a pull request; every version must still match.

## How the work is organised

The decompilation and its native port are worked in four phases: map every byte and finish the engine foundations,
start the port shell and the reference, drive one version to full coverage by play, then release in stages gated by
coverage. The playbooks in [docs/playbooks](docs/playbooks/README.md) describe each phase, the measurement that ends it
and the source rules that hold throughout.
