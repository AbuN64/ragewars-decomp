#include "include_asm.h"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
#ifdef NON_MATCHING
typedef struct { char pad0[0x60]; s32 start; u8 count; } Func_804476B8_List;
typedef struct { u16 cells[0x80]; u8 current; u8 bits[1]; } Func_804476B8_Rec;
extern s32 func_804488A4_de(Func_804476B8_List *list, Func_804476B8_Rec *rec, s32 mode);
/* Counts (up to 2) the cells holding the 16-bit key shifted into arg1's high half, over the groups 0..count-1 of the list whose bit is set in the record's mask (or the group named by the key's high byte); switches the record's current group through func_804488A4_de first; returns the count, an error from func_804488A4_de, or 2 once two cells are found. */
s32 func_804476B8_de(Func_804476B8_List *arg0, s32 arg1, Func_804476B8_Rec *arg2) {
    s32 key;
    s32 group;
    s32 found;
    s32 first;
    s32 index;
    s32 result;
    u32 maskIndex;
    s32 hi;
    u16 *cell;
    group = 0;
    found = 0;
    key = (arg1 >> 16) & 0xFFFF;
    hi = key >> 8;
    maskIndex = ((key & 0xFF) >> 2) + ((hi & 7) << 5);
    if (arg0->count != 0) {
        do {
            first = 1;
            if ((group & 0xFF) == 0) {
                first = arg0->start;
            }
            if ((group & 0xFF) == hi || ((arg2->bits[maskIndex] >> ((group & 0xFF) & 7)) & 1)) {
                if ((group & 0xFF) != arg2->current) {
                    result = func_804488A4_de(arg0, arg2, 0);
                    if (result != 0 && result != 3) {
                        return result;
                    }
                    arg2->current = group;
                }
                if (found >= 2) {
                    return 2;
                }
                cell = &arg2->cells[first];
                for (index = first; index < 0x80; index++) {
                    if (*cell++ == key) {
                        found++;
                    }
                    if (found >= 2) {
                        break;
                    }
                }
                if (found >= 2) {
                    return 2;
                }
            }
            group++;
        } while ((group & 0xFF) < arg0->count);
    }
    return found;
}
#else
INCLUDE_ASM("ovl_80400000", func_804476B8_de);
#endif
#endif

#if defined(VERSION_EU)
unsigned char D_auto_func_80447818_de_padding_1BEA78[8] = { 0x8C, 0x82, 0x01, 0xCC, 0x14, 0x40, 0x00, 0x03 };
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_80447818_de_padding_1AD818);
#endif
