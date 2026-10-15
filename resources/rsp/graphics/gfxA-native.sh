#!/bin/sh
set -eu
armips=${ARMIPS:-build/rsp-resources/armips-build/armips}
out=${RSP_GFX_A_OUT:-build/rsp-resources/gfxA}
mkdir -p "$out"
cpp -P -Iresources/rsp/graphics/PR -Iresources/rsp/graphics/rsp -Iresources/rsp/graphics -D_LANGUAGE_ASSEMBLY -DF3DEX_GBI_2 -DCFG_NoN=1 -DCFG_OLD_TRI_WRITE=1 -DBUG_CLIPPING_FAIL_WHEN_SUM_ZERO=1 -DBUG_FAIL_IF_CARRY_SET_AT_INIT=1 resources/rsp/graphics/f3dex2.s > "$out/gfxA.S"
"$armips" "$out/gfxA.S" -strequ CODE_FILE "$out/gfxA.code" -strequ DATA_FILE "$out/gfxA.data" -strequ ID_STR 'RSP Gfx ucode F3DEX.NoN   fifo 2.05  Yoshitaka Yasumoto 1998 Nintendo.' -sym2 "$out/gfxA.sym"
python3 - "$out" <<'PY_CHECK'
from pathlib import Path
import sys
rom = Path('roms/baserom.us-rev1.z64').read_bytes()
for name, start, end in [('gfxA.code', 0xDD910, 0xDECA0), ('gfxA.data', 0xE0C50, 0xE1070)]:
    actual = (Path(sys.argv[1]) / name).read_bytes()
    assert len(actual) == end - start and actual == rom[start:end], name
    print(f'{name}: {len(actual)} assembled bytes exactly match ROM {start:X}-{end:X}')
PY_CHECK
