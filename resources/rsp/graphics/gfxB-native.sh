#!/bin/sh
set -eu
armips=${ARMIPS:-build/rsp-resources/armips-build/armips}
out=${RSP_GFX_B_OUT:-build/rsp-resources/gfxB}
mkdir -p "$out"
cpp -P -Iresources/rsp/graphics/PR -Iresources/rsp/graphics/rsp -Iresources/rsp/graphics -D_LANGUAGE_ASSEMBLY -DF3DEX_GBI_2 -DCFG_NoN=0 -DCFG_OLD_TRI_WRITE=1 -DBUG_CLIPPING_FAIL_WHEN_SUM_ZERO=1 -DBUG_FAIL_IF_CARRY_SET_AT_INIT=1 resources/rsp/graphics/l3dex2.s > "$out/gfxB.S"
"$armips" "$out/gfxB.S" -strequ CODE_FILE "$out/gfxB.code" -strequ DATA_FILE "$out/gfxB.data" -strequ ID_STR 'RSP Gfx ucode L3DEX       fifo 2.05  Yoshitaka Yasumoto 1998 Nintendo.' -sym2 "$out/gfxB.sym"
python3 - "$out" <<'PY_CHECK'
from pathlib import Path
import sys
rom = Path('roms/baserom.us-rev1.z64').read_bytes()
for name, start, end in [('gfxB.code', 0xDECA0, 0xDFE30), ('gfxB.data', 0xE1070, 0xE1460)]:
    actual = (Path(sys.argv[1]) / name).read_bytes()
    assert len(actual) == end - start and actual == rom[start:end], name
    print(f'{name}: {len(actual)} assembled bytes exactly match ROM {start:X}-{end:X}')
PY_CHECK
