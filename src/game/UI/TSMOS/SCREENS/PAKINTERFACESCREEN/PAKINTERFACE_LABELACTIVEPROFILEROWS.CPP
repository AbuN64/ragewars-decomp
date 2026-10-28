#include "COMMON/NAME.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "FRONTEND/PAKINTERFACE_LABELACTIVEPROFILEROWS.H"

/* Labels player p's roster rows: for each of the four 400-byte records of D_80102B00 whose byte
   0xE is clear and whose owner byte 0xD is p, when the matching 150-byte status record at 0xD0 of
   D_801462C8 has byte 0x78 equal to one and byte 0x91 clear, points the text at 0x38 of the next
   row item (0x2BA, 0x2E5, 0x2E6, then 0x2E7) of the window at 0xC of p's 2920-byte record at 0x58
   of the block D_800E54A4 points to at that record. Adapted from PAKInterface_CopyActiveProfilesToPakSlots with the copy
   replaced by the row label. */
extern u8 D_80102B00[];
extern s8 D_80102B0D[];
extern s8 D_800FEB0E[];
extern struct MatchSetupGlobals D_801462C8;
extern struct Label *Node_FindWidgetByResourceId(void *, s32);
void PAKInterface_LabelActiveProfileRows(s32 player) {
    struct MatchSetupGlobals *globals;
    s32 row;
    s32 id;
    s32 i;
    row = 0;
    globals = &D_801462C8;
    for (i = 0; i < 4; i++) {
        switch (row) {
        case 0:
#if defined(VERSION_DE)
            id = 0x2AA;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x2BA;
#elif defined(VERSION_EU_X)
            id = 0x2C2;
#endif
            break;
        case 1:
#if defined(VERSION_DE)
            id = 0x2AB;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x2E5;
#elif defined(VERSION_EU_X)
            id = 0x2C6;
#endif
            break;
        case 2:
#if defined(VERSION_DE)
            id = 0x2AC;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x2E6;
#elif defined(VERSION_EU_X)
            id = 0x2C7;
#endif
            break;
        default:
#if defined(VERSION_DE)
            id = 0x2AC + 1;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x2E6 + 1;
#elif defined(VERSION_EU_X)
            id = 0x2C7 + 1;
#endif
            break;
        }
        if (D_800FEB0E[i * 400] == 0 && D_80102B0D[i * 400] == player &&
            globals->status[i].active == 1 && globals->status[i].m_IsBot == 0) {
            Node_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget, id)->text = &D_80102B00[i * 400];
            row++;
        }
    }
}
