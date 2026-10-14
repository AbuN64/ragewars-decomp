#!/bin/sh
# Run from the repository root; bounded native resource build only.
set -eu
out=${RSP_BOOT_OUT:-build/rsp-resources}
mkdir -p "$out"
mips-linux-gnu-as -EB -mips1 -o "$out/boot.o" resources/rsp/boot.s
mips-linux-gnu-ld -EB -T resources/rsp/boot.ld -o "$out/boot.elf" "$out/boot.o"
mips-linux-gnu-objcopy -O binary -j .rsp.boot "$out/boot.elf" "$out/boot.bin"
python3 - "$out/boot.bin" <<'PY'
import sys
from pathlib import Path
actual = Path(sys.argv[1]).read_bytes()
expected = Path('roms/baserom.us-rev1.z64').read_bytes()[0xDD840:0xDD910]
assert len(actual) == 208 and actual == expected, 'linked boot differs from ROM'
print('RSP boot: 208 linked bytes exactly match ROM DD840-DD910')
PY
