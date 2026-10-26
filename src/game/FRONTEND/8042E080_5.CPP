#include "include_asm.h"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/NAME.H"
#include "TYPES.H"

/* Runs the block D_800E54A4 points to on event 1: in phase 3 at 0x4C it counts each player's timer
   at 0x14 of its 2920-byte record at 0x58 down and, when one expires, marks it -1 and resets that
   player through Pak_ProbeStatus and PAKInterface_ResolvePlayerPakState between Tsmos_DeactivateControllerState and Tsmos_ActivateControllerState; then it
   advances the menu at 0x8 with Frontend_DrawMenuImage and func_8043C2A4_de while func_8043C308_de reports 1, and
   once it reports 2 in phase 5 at 0x54 calls MarkMenuEventHandled and moves on through Frontend_ContinueCupOrOpenResults,
   Frontend_OpenControllerModeResults or func_804389F0_de as the cartridge's jump table jtbl_800E1BB0 chooses for option
   byte D_801462D5 up to 4. Returns zero. */





extern void Tsmos_DeactivateControllerState();
extern void Tsmos_ActivateControllerState();
extern void Pak_ProbeStatus(s32);
extern void PAKInterface_ResolvePlayerPakState(s32);
extern s32 func_8043C308_de(void *);
extern void Frontend_DrawMenuImage(void *);
extern void func_8043C2A4_de(void *);
extern void MarkMenuEventHandled();
extern void Frontend_ContinueCupOrOpenResults();
extern void Frontend_OpenControllerModeResults();
extern void func_804389F0_de();

s32 Frontend_UpdatePakScreenExit(void *unused0, void *unused1, s32 event) {
    s32 i;
    u32 option;

    if (event != 1) {
        return 0;
    }
    if (D_800E54A4->ready == 3) {
        for (i = 0; i < 4; i++) {
            if (D_800E54A4->players[i].back > 0 && --D_800E54A4->players[i].back == 0) {
                D_800E54A4->players[i].back = -1;
                Tsmos_DeactivateControllerState();
                Pak_ProbeStatus(i);
                PAKInterface_ResolvePlayerPakState(i);
                Tsmos_ActivateControllerState();
            }
        }
    }
    if (func_8043C308_de(D_800E54A4->menu) != 1) {
        return 0;
    }
    Frontend_DrawMenuImage(D_800E54A4->menu);
    func_8043C2A4_de(D_800E54A4->menu);
    if (func_8043C308_de(D_800E54A4->menu) != 2) {
        return 0;
    }
    if (D_800E54A4->phase != 5) {
        return 0;
    }
    MarkMenuEventHandled();
    option = D_801462C8.controllerMode;
    if (option >= 5) {
        goto done;
    }
    switch (option) {
        case 0: goto option_a;
        case 1: goto option_c;
        case 2: goto option_b;
        case 3: goto option_c;
        case 4: goto option_c;
        }
option_a:
    Frontend_ContinueCupOrOpenResults();
    return 0;
option_b:
    Frontend_OpenControllerModeResults();
    return 0;
option_c:
    func_804389F0_de();
done:
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC844[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E93D4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE214[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DDB94[1] = {
    0x00000000,
};
#endif
