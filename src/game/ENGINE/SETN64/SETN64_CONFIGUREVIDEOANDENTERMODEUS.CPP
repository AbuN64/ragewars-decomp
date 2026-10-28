#include "include_asm.h"
#include "COMMON/OBJRECAT26DD8.H"
#include "RENDER/SETN64_INITIALIZETRANSITIONMODE.H"
#include "TYPES.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GROUP.H"
#include "RENDER/SETN64_ENTERPENDINGSESSIONMODE.H"
#include "RENDER/SETN64_CONFIGUREVIDEOANDENTERMODEUS.H"

/* 802944E8_5.CPP */
/** Perform the no-op callback at VRAM 0x80294ABC. */
void SetN64_InitializeTransitionMode(void) {
}

#if defined(VERSION_US)
extern s32 D_800E28D8;
extern char D_auto_800D3460[], D_800D4530[];
extern f32 rodata_func_8029499C_us_800C5410;
extern void *D_auto_rodata_unresolved_800CD698[];
extern void osViSetMode(void *);
extern void osViSetYScale(f32);
extern void osViSetSpecialFeatures(s32);
extern void Cinema_EndSequence(void);
#define SCR_W(state, off) (*(s32 *)((char *)(state) + (off)))
/* Per-frame screen step: when the flag at 0x26DD0 is set it switches the video mode (label chosen by D_800E28D8, Y scale from a constant, mode 2); in state 2 of D_80142CA8 with that flag clear it latches 0x26DBC into 0x26DB8, clears 0x26DB0, runs the reset calls and dispatches the 12-byte table row D_auto_rodata_unresolved_800CD698 for that value. */
void SetN64_ConfigureVideoAndEnterModeUs(char *state) {
    void (*handler)(char *);
    s32 mode;
    if (SCR_W(state, 0x26DD0) != 0) {
        char *label = D_auto_800D3460;
        if (D_800E28D8 == 0) {
            label = D_800D4530;
        }
        osViSetMode(label);
        osViSetYScale(rodata_func_8029499C_us_800C5410);
        osViSetSpecialFeatures(2);
    }
    if (D_80142CA8 == 2 && SCR_W(state, 0x26DD0) == 0) {
        mode = SCR_W(state, 0x26DBC);
        SCR_W(state, 0x26DB0) = 0;
        SCR_W(state, 0x26DB8) = mode;
        Cinema_EndSequence();
        SoundElement_StopAudioExceptKey(-1);
        Control_SetControllerMode(0);
        handler = (void (*)(char *))D_auto_rodata_unresolved_800CD698[SCR_W(state, 0x26DB8) * 3];
        if (handler != 0) {
            handler(state);
        }
    }
}
#endif

/* 802944E8_7.CPP */
#if !(defined(VERSION_US))
extern Entry80294AC4 D_800CD788[];

void SetN64_EnterPendingSessionMode(void *gameSession) {
    void (*callback)(void *gameSession);
    s32 index;

    if ((D_80142CA8 == 2) &&
        (((struct GameSession *)gameSession)->transitionBlocked == 0)) {
        index = ((struct GameSession *)gameSession)->target;
        ((struct GameSession *)gameSession)->transitionTime = 0;
        ((struct GameSession *)gameSession)->mode = index;
        Cinema_EndSequence();
        SoundElement_StopAudioExceptKey(-1);
        Control_SetControllerMode(0);
        callback = D_800CD788[((struct GameSession *)gameSession)->mode].callback;
        if (callback != 0) {
            callback(gameSession);
        }
    }
}
#endif

/* 802944E8_9.CPP */
void SetN64_DrawTransitionMode(void) {
}
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void SetN64_InitializeMode18(void) {
}
#endif
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void SetN64_UpdateMode18(void) {
}
#endif
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void SetN64_DrawMode18(void) {
}
#endif
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void SetN64_InitializeMode19(void) {
}
#endif
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void SetN64_UpdateMode19(void) {
}
#endif
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void SetN64_DrawMode19(void) {
}
#endif

#if defined(VERSION_US)
/** Perform no operation. */
void func_80294AB0_us(void) {
}
#endif
