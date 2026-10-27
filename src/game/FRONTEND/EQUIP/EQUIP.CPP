#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "TYPES.H"
#include "FRONTEND/8043A0B0_10.H"

/* Fills player p's column values on the screen D_800E59E0 from what the player owns: unless the
   entry's mode word (0x4D4) is 0, it scans the 4 rows of D_800E5BC4 for column 1, the 3 rows of
   D_800E5B14 for column 4 and the 8 rows of D_800E5B44 for column 5, and writes the index of each
   row whose item is marked owned at 0x4C of the player's 150-byte record in D_80146398 into the
   entry's next value slot (0x4B8 plus four per slot), starting at slot 0, 4 and 2, or at 0, 2 and
   1 in mode 1. */







extern struct ScreenFrontendLoadEquipmentSelections *D_800E59E0;
extern u8 g_playerSettings[];
extern struct Shape_typemap_165 D_800E5BC4[];
extern struct Shape_typemap_165 D_800E5B14[];
extern struct Shape_typemap_165 D_800E5B44[];

void Frontend_LoadEquipmentSelections(s32 player) {
    struct Shape_typemap_165 *source;
    u8 *record;
    s32 column;
    s32 count;
    s32 slot;
    s32 i;

    if (D_800E59E0->entries[player].mode == 0) {
        return;
    }
    record = &g_playerSettings[player * 150];
    for (column = 0; column < 8; column++) {
        if (D_800E59E0->entries[player].mode == 1) {
            switch (column) {
            case 1:
                source = D_800E5BC4;
                count = 4;
                slot = 0;
                break;
            case 4:
                source = D_800E5B14;
                count = 3;
                slot = 2;
                break;
            case 5:
                source = D_800E5B44;
                count = 8;
                slot = 1;
                break;
            default:
                continue;
            }
        } else {
            switch (column) {
            case 1:
                source = D_800E5BC4;
                count = 4;
                slot = 0;
                break;
            case 4:
                source = D_800E5B14;
                count = 3;
                slot = 4;
                break;
            case 5:
                source = D_800E5B44;
                count = 8;
                slot = 2;
                break;
            default:
                continue;
            }
        }
        for (i = 0; i < count; i++) {
            if ((record + source[i].field_8)[0x4C] == 1) {
                D_800E59E0->entries[player].values[slot++] = i;
            }
        }
    }
}

#if !(defined(VERSION_EU) || defined(VERSION_US)) || defined(NON_MATCHING)
#include "TYPES.H"

/* Rebuilds the loadout of every active player whose entry on the screen D_800E59E0 is in mode 2:
   clears the 22 owned bytes at 0x4C and level bytes at 0x62 of the player's 150-byte record in
   D_80146398, then for columns 0 and 1 (16-byte table D_800E5BC4, level column + 1), 2 and 3
   (D_800E5B44, level column + 3) and 4 (D_800E5B14, level 4) marks the item of the row the entry's
   value for that column selects as owned at that level, and finally marks item 0 owned at level
   0. */

/* US and EU keep their asm: their jump table sits inside literals_Frontend_MoveEquipmentColumn's rodata, which has no
 * unit of its own yet. */
void Frontend_ApplySelectedPlayerLoadouts(void) {
    u8 *record;
    struct Shape_typemap_165 *source;
    struct Shape_typemap_165 *row;
    s32 level;
    s32 item;
    s32 i;
    s32 column;

    for (i = 0; i < 4; i++) {
        record = &g_playerSettings[i * 150];
        if (record[0x78] != 1) {
            continue;
        }
        if (D_800E59E0->entries[i].mode != 2) {
            continue;
        }
        for (column = 0; column < 22; column++) {
            (record + column)[0x4C] = 0;
            (record + column)[0x62] = 0;
        }
        for (column = 0; column < 6; column++) {
            switch (column) {
            case 0:
            case 1:
                source = D_800E5BC4;
                level = column + 1;
                break;
            case 4:
                source = D_800E5B14;
                level = 4;
                break;
            case 2:
            case 3:
                source = D_800E5B44;
                level = column + 3;
                break;
            default:
                continue;
            }
            item = source[D_800E59E0->entries[i].values[column]].field_8;
            row = source + D_800E59E0->entries[i].values[column];
            (record + item)[0x4C] = 1;
            (record + row->field_8)[0x62] = level;
        }
        record[0x4C] = 1;
        record[0x62] = 0;
    }
}
#else
INCLUDE_ASM("ovl_80400000", Frontend_ApplySelectedPlayerLoadouts);
#endif
