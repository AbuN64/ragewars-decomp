#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"
#include "AUDIO_3/802BFD40.H"

extern char D_800C7440;
extern char g_audioSeqplayerText;








void *func_802B16E0_de(void *seqPlayer, s32 noteKey, s32 noteVelocity, s32 channelNumber) {
    s32 high;
    s32 low;
    s32 middle;
    u8 x;
    u8 y;
    ALInstrument *table;
    ALSound_s *entry;
    u8 *bounds;

    table = ((ALSeqPlayer *)seqPlayer)->chanState[channelNumber & 0xFF].instrument;
    high = table->soundCount;
    low = 1;
    if (table == 0) {
        Audio_Assert(&D_800C7440, &g_audioSeqplayerText, 0x376);
    }

    if (high > 0) {
        x = noteKey;
        y = noteVelocity;
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
