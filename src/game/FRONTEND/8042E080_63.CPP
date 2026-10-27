#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "stddef.h"
#include "FRONTEND/8042E080_63.H"

/* Checks that every active player on the selected team has the configured value. */
extern s32 D_80102B08[]; extern s8 D_80102B0D[];
extern s32 D_80102B08[]; extern s8 D_800FEB0E[];
s32 Frontend_CheckOwnedProfileIds(s32 player) {
    s32 profileOffset;
    s32 profileIndex;
    s32 allMatch;
    allMatch = 1;
    profileIndex = 0;
    profileOffset = 0;
    do {
        if ((*(D_800FEB0E + profileOffset) == 0) && (*(D_80102B0D + profileOffset) == player) && (*(s32 *)((char *)D_80102B08 + profileOffset) != D_800E54A4->players[player].profile)) {
            allMatch = 0;
        }
        profileIndex += 1;
        profileOffset += 0x190;
    } while (profileIndex < 4);
    return allMatch;
}
