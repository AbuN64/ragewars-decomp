#include "COMMON/ITEMRECAT20V1.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_33.H"

/* Updates the four player control rows, their visibility, and the selected player label. */
extern s32 Control_IsControllerConnected(s32);
extern void Frontend_SetWidgetFlag100(MenuWidget *record, int enable);
extern struct Shared_Item *SmpOverlay_GetSlotValue(void *, s32);
void PAKInterface_UpdatePlayerControlRows(s32 player) {
    struct Shared_Item *item;
    struct func_8028469C_S2 *label;
    u16 id;
    s32 i;
    i = 0;
    do {
        if (i == 1) goto row_one;
        if (i < 2) {
            if (i == 0) goto row_zero;
#if defined(VERSION_DE)
            id = 0x296 + 6;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            id = 0x299 + 6;
#elif defined(VERSION_EU_X)
            id = 0x29F + 6;
#endif
            goto row_done;
        }
        if (i == 2) goto row_two;
#if defined(VERSION_DE)
        id = 0x296 + 6;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x299 + 6;
#elif defined(VERSION_EU_X)
        id = 0x29F + 6;
#endif
        goto row_done;
    row_zero:
#if defined(VERSION_DE)
        id = 0x296;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x299;
#elif defined(VERSION_EU_X)
        id = 0x29F;
#endif
        goto row_done;
    row_one:
#if defined(VERSION_DE)
        id = 0x296 + 2;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x299 + 2;
#elif defined(VERSION_EU_X)
        id = 0x29F + 2;
#endif
        goto row_done;
    row_two:
#if defined(VERSION_DE)
        id = 0x296 + 4;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        id = 0x299 + 4;
#elif defined(VERSION_EU_X)
        id = 0x29F + 4;
#endif
    row_done:
        item = Frontend_FindWidgetByResourceId(D_800E54A4->window, id);
        if (Control_IsControllerConnected(i) == 1) {
            Frontend_SetWidgetFlag100(item, 0);
        } else {
            Frontend_SetWidgetFlag100(item, 1);
        }
        label = item->label;
        if (player != -1 && item == SmpOverlay_GetSlotValue(D_800E54A4->list, player)) {
            label->unk38 = D_800E54A4->players[player].slots[D_800E54A4->players[player].chosen];
        } else {
            label->unk38 = 0;
        }
        i += 1;
    } while (i < 4);
}
