#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"







extern PakDirectoryRecAt4 *D_800E2854;

/* Counts empty Controller Pak note slots on channel ch when the pak is ready and returns its error status, or -2 when not ready. */
s32 func_804050CC_de(s32 ch, s32 *count) {
    s32 i;

    if (D_801534F0[ch] != 3) {
        return -2;
    }
    *count = 0;
    if (D_80153500[ch] == 0) {
        for (i = 0; i < 16; i++) {
            if (D_800E2854[ch].notes[i].file_size == 0) {
                (*count)++;
            }
        }
    }
    return D_80153500[ch];
}
