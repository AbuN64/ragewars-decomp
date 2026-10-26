#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/LABEL.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SCREEN.H"
#include "COMMON/REQUESTRECAT10.H"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "FRONTEND/8043A0B0_11.H"

extern struct Screen42 *D_800E59E0;
extern void SmpOverlay_SetSlotValue(struct SlotsRecAt5CV1 *, s32, s32);
extern void Frontend_SetPreviewTransformUpdate(struct Object49C *, s32);
s32 func_8043AB40_de(void *unused0, void *unused1, s32 arg2) {
    s32 player;
    s32 i;
    s32 delay;
    u8 *settings;
    struct Screen42 *screen;
    player = arg2 & 0xFFFF;
    MarkMenuEventHandled();
    if (D_800E59E0->entries[player].state != 1) return 0;
    if (D_800E59E0->entries[player].selection != 5) return 0;
    {
        D_800E59E0->entries[player].state = 2;
        SmpOverlay_SetSlotValue(D_800E59E0->entries[0].slots, player, 1);
        for (i = 0; i < 6; i++) {
            Frontend_SetWidgetFlag08(func_8040EC30_de(D_800E59E0->entries[0].window, D_800E59EE[player][i].value), 1);
        }
        Frontend_FindKeyIndex(D_801462C8.playerSettings[player].character);
        settings = (u8 *)D_800E59E0 + (player * sizeof(struct Entry42) + 8);
        { void *panel = settings; settings = (u8 *)g_playerSettings; Frontend_SetPreviewTransformUpdate(panel, 0); }
        if (func_8043BA24_de() != 0) return 0;
        {
            func_8043B854_de();
            screen = D_800E59E0;
            screen->state = 5;
            screen->next = 4;
            switch (settings[-0xC3]) {
            case 0: delay = 20; break;
            case 3: delay = 10; break;
            case 2: delay = 15; break;
            default: return 0;
            }
            screen->delay = delay;
        }
    }
    return 0;
}
