#include "include_asm.h"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/LABEL.H"
#include "RENDER_2/8025DE50_5.H"

/* Steps the record screen's transition state machine: slides the two panels in or out, swaps the
   visible item groups as each phase's timer runs out, and while idle (state 3) pulses the cursor's
   style from the elapsed time and moves the cursor to the node now under focus. */
#include "TYPES.H"





/* The hub spells D_800E3590 as the padded menu block; this unit's view of it is the published
   MenuRecAt108 struct, so each member use casts D_800E3590 to that view. */

extern void MarkMenuEventHandled(void);
extern void func_802998A8_de(void);

extern void func_80419F24_de(s32 fade);
extern s32 func_80419F38_de(s32 fade);
extern void SmpFlicker_StartFlicker(s32 fade, s32 speed);
extern NodeFrontendAnimateSlotSelectionMenu *SmpOverlay_GetSlotValue(void *handle, s32 arg1);

/* Frontend_ShowUnlockedEntries is declared by span code_8041BEA8.h; no local extern needed. */

s32 Frontend_AnimateSlotSelectionMenu(s32 unused0, s32 unused1, s32 arg2) {
    NodeFrontendAnimateSlotSelectionMenu *node;

    switch (((MenuRecAt108 *) D_800E3590)->state) {
    case 1:
        ((MenuRecAt108 *) D_800E3590)->left->x += ((MenuRecAt108 *) D_800E3590)->leftStep;
        ((MenuRecAt108 *) D_800E3590)->right->x -= ((MenuRecAt108 *) D_800E3590)->rightStep;
        if (--((MenuRecAt108 *) D_800E3590)->timer <= 0) {
            SoundElement_PlayFlatSound(0xE79);
            /* NodeFrontendAnimateSlotSelectionMenu is the hub Item view's twin (style at 0x10, x/y at 0x14/0x16);
               E8D8 speaks Item, so the node slots cast to it here. */
            Frontend_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupA, 1);
            SmpFlicker_StartFlicker(((MenuRecAt108 *) D_800E3590)->fade, 4);
            ((MenuRecAt108 *) D_800E3590)->state = 4;
            ((MenuRecAt108 *) D_800E3590)->timer = 4;
        }
        break;
    case 2:
        ((MenuRecAt108 *) D_800E3590)->left->x -= ((MenuRecAt108 *) D_800E3590)->leftStep;
        ((MenuRecAt108 *) D_800E3590)->right->x += ((MenuRecAt108 *) D_800E3590)->rightStep;
        if (--((MenuRecAt108 *) D_800E3590)->timer <= 0) {
            ((MenuRecAt108 *) D_800E3590)->state = 3;
            MarkMenuEventHandled();
            func_802998A8_de();
            return 0;
        }
        break;
    case 4:
        if (func_80419F38_de(((MenuRecAt108 *) D_800E3590)->fade) != 0) {
            func_80419F24_de(((MenuRecAt108 *) D_800E3590)->fade);
            ((MenuRecAt108 *) D_800E3590)->state = 6;
            ((MenuRecAt108 *) D_800E3590)->timer = 4;
            Frontend_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupB, 1);
            Frontend_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupC, 1);
        }
        break;
    case 5:
        SoundElement_PlayFlatSound(0xE78);
        ((MenuRecAt108 *) D_800E3590)->state = 2;
        ((MenuRecAt108 *) D_800E3590)->timer = 4;
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupB, 0);
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupC, 0);
        Frontend_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->groupA, 0);
        break;
    case 6:
        ((MenuRecAt108 *) D_800E3590)->styleValue += ((MenuRecAt108 *) D_800E3590)->styleStep;
        ((MenuRecAt108 *) D_800E3590)->groupC->style += ((MenuRecAt108 *) D_800E3590)->alphaStep;
        Frontend_ShowUnlockedEntries(((MenuRecAt108 *) D_800E3590)->styleValue);
        if (--((MenuRecAt108 *) D_800E3590)->timer <= 0) {
            ((MenuRecAt108 *) D_800E3590)->groupC->style = 100;
            Frontend_ShowUnlockedEntries(0x6E);
            ((MenuRecAt108 *) D_800E3590)->state = 3;
            Frontend_SetWidgetFlag08((func_8041F2A0_Item *) ((MenuRecAt108 *) D_800E3590)->cursor, 1);
        }
        break;
    case 7:
        break;
    }

    if (((MenuRecAt108 *) D_800E3590)->state == 3) {
        ((MenuRecAt108 *) D_800E3590)->clock += arg2;
        ((MenuRecAt108 *) D_800E3590)->cursor->style = Math_Cosf((f32) ((MenuRecAt108 *) D_800E3590)->clock * 0.0033333334f) * 30.0f + 220.0f;
        node = SmpOverlay_GetSlotValue(((MenuRecAt108 *) D_800E3590)->handle, 0);
        if (node != ((MenuRecAt108 *) D_800E3590)->focus) {
            SoundElement_PlayFlatSound(0xE7E);
            if (((MenuRecAt108 *) D_800E3590)->focus != 0) {
                ((MenuRecAt108 *) D_800E3590)->focus->style = 0x6E;
            }
            ((MenuRecAt108 *) D_800E3590)->focus = node;
            node->style = 0xE1;
            func_8041D960_de();
            Frontend_UpdateFocusCaption();
            ((MenuRecAt108 *) D_800E3590)->cursor->x = node->x - 2;
            ((MenuRecAt108 *) D_800E3590)->cursor->y = node->y;
        }
    }
    return 0;
}

#if !(defined(VERSION_EU) || defined(VERSION_US))
unsigned int rodata_unresolved_800E14FC[1] = {
    0x00000000,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_US)
const unsigned int rodata_unresolved_800E14FC[1] = {
    0x00000000,
};
#endif
