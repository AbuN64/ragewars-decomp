#!/bin/sh
set -eu
armips=${ARMIPS:-build/rsp-resources/armips-build/armips}
out=${RSP_AUDIO_OUT:-build/rsp-resources}
mkdir -p "$out"
"$armips" resources/rsp/audio.s -strequ CODE_FILE "$out/audio.code" -strequ DATA_FILE "$out/audio.data" -sym2 "$out/audio.sym"
python3 - "$out" <<'PY'
from pathlib import Path
import sys
rom = Path('roms/baserom.us-rev1.z64').read_bytes()
for name, start, end in [('audio.code', 0xDFE30, 0xE0C50), ('audio.data', 0xE1460, 0xE1720)]:
    actual = (Path(sys.argv[1]) / name).read_bytes()
    assert len(actual) == end - start and actual == rom[start:end], name
    print(f'{name}: {len(actual)} assembled bytes exactly match ROM {start:X}-{end:X}')
PY
