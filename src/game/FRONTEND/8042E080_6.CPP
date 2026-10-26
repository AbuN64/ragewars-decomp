#include "include_asm.h"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/NAME.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8042E080_12.H"
#include "RENDER_2/8025DE50_5.H"

/* Animates the two menu panels through open, close and countdown states and updates the active team menu. */

extern void SmXlate_SwitchScreen(s32);
extern void MarkMenuEventHandled(void);
extern void Tsmos_ActivateControllerState(void);
extern void SmpFlicker_RestoreFlickerValue(void *);
extern void SmpFlicker_StartFlicker(void *, s32);

extern s32 SmpFlicker_IsFlickerIdle(void *);
s32 Frontend_UpdatePakScreenPanels(s32 unused0, s32 unused1, s32 arg2) {
    s32 readyState;
    s32 openFramesLeft;
    s32 closeFramesLeft;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_v0;
    MenuWidget *closeTop;
    MenuWidget *closeBottom;
    MenuWidget *openTop;
    MenuWidget *openBottom;

    if (D_800E28E0 < 2) {
        readyState = D_800E54A4->ready;
        switch (readyState) {
        case 1:
            openTop = D_800E54A4->top;
            openTop->x = (u16) (openTop->x + (u16) D_800E54A4->topStep);
            openBottom = D_800E54A4->bottom;
            openBottom->x = (u16) (openBottom->x - (u16) D_800E54A4->bottomStep);
            openFramesLeft = D_800E54A4->timer - 1;
            D_800E54A4->timer = openFramesLeft;
            if (openFramesLeft <= 0) {
                SoundElement_PlayFlatSound(0xE79);
                /* unk28 is the panel's item handle, kept untyped in the animation state */
                Frontend_SetWidgetFlag08((func_8041F2A0_Item *) D_800E54A4->title, 1);
                SmpFlicker_StartFlicker(D_800E54A4->music, 4);
                D_800E54A4->ready = 4;
                D_800E54A4->timer = 4;
            }
            break;
        case 2:
            closeTop = D_800E54A4->top;
            closeTop->x = (u16) (closeTop->x - (u16) D_800E54A4->topStep);
            closeBottom = D_800E54A4->bottom;
            closeBottom->x = (u16) (closeBottom->x + (u16) D_800E54A4->bottomStep);
            closeFramesLeft = D_800E54A4->timer - 1;
            D_800E54A4->timer = closeFramesLeft;
            if (closeFramesLeft <= 0) {
                D_800E54A4->ready = 3;
                MarkMenuEventHandled();
                SmXlate_SwitchScreen(D_800E54A4->focus);
                return 0;
            }
            break;
        case 3:
            Tsmos_ActivateControllerState();
            break;
        case 4:
            D_800E54A4->timer = RW_CLAMP(D_800E54A4->timer - 1, 0, D_800E54A4->timer);
            if ((D_800E54A4->timer <= 0) && (SmpFlicker_IsFlickerIdle(D_800E54A4->music) != 0)) {
                SmpFlicker_RestoreFlickerValue(D_800E54A4->music);
                D_800E54A4->ready = 3;
            }
            break;
        case 5:
            SoundElement_PlayFlatSound(0xE78);
            D_800E54A4->ready = 2;
            D_800E54A4->timer = 4;
            Frontend_SetWidgetFlag08((func_8041F2A0_Item *) D_800E54A4->title, 0);
            break;
        }
        if (D_800E54A4->ready == 3) PAKInterface_UpdatePlayerPanelAnimations(arg2);
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC85C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E93EC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE22C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DDBAC[1] = {
    0x00000000,
};
#endif
