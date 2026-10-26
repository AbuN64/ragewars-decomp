#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"
#include "AUDIO_3/802BFD40.H"

extern char D_800C7440;
extern char g_audioSeqplayerText;








void *func_802B16E0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 high;
    s32 low;
    s32 middle;
    u8 x;
    u8 y;
    ALInstrument *table;
    ALSound_s *entry;
    u8 *bounds;

    table = ((ALSeqPlayer *)arg0)->chanState[arg3 & 0xFF].instrument;
    high = table->soundCount;
    low = 1;
    if (table == 0) {
        Audio_Assert(&D_800C7440, &g_audioSeqplayerText, 0x376);
    }

    if (high > 0) {
        x = arg1;
        y = arg2;
        do {
            middle = (low + high) / 2;
            entry = table->soundArray[middle - 1];
            bounds = (u8 *)entry->keyMap;
            if (x >= bounds[2] && x <= bounds[3] &&
                y >= bounds[0] && y <= bounds[1]) {
                return entry;
            }
            if (x < bounds[2] ||
                (y < bounds[0] && x <= bounds[3])) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        } while (low <= high);
    }
    return 0;
}
