#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/8043D54C.H"
#include "OVLGAME/SHAREDRECAT224.H"
#include "TYPES.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "MENU/PLAYERSETTINGS.H"
#include "MENU/MISC/8043DF84_3.H"

#if defined(VERSION_EU)
unsigned int D_auto_rodata_unresolved_800EE97C[9] = {
    0x00000000, 0x0043EA68, 0x0043EA98, 0x0043EAC8, 0x0043EAF8, 0x0043EB28, 0x0043EB58, 0x0043EB88,
    0x0043EBB8,
};
#endif

#if defined(VERSION_US_REV1)
/* Selects a field's text according to its type and option byte. */
#include "TYPES.H"

extern char *D_800D3D14;
extern char *D_800D3D18;
extern char *D_800D3D1C;
extern char *D_800D3D20;
extern char *D_800D3D24;
extern char *D_800D3D28;
extern char *D_800D3D2C;
extern char *D_800D3D30;
extern char *D_800D3D34;
extern char *D_800D3D38;
extern char *D_800D3D3C;
extern char *D_800D3D40;
extern char *D_800D3D44;
extern char *D_800D3D48;
extern char *D_800D3D4C;
extern char *D_800D3D50;
#include "MENU/OPTION_TEXT_TYPE.H"


s32 Confirming_SelectToggleRowText(func_8043DD30_S1 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    switch (temp_v0) {
    case 2:
    default:
        if (D_801462C8.menuToggles[0] != 0) {
            arg0->unk14 = &D_800D3D14;
        } else {
            arg0->unk14 = &D_800D3D18;
        }
        break;
    case 3:
        if (D_801462C8.menuToggles[1] != 0) {
            arg0->unk14 = &D_800D3D1C;
        } else {
            arg0->unk14 = &D_800D3D20;
        }
        break;
    case 4:
        if (D_801462C8.menuToggles[2] != 0) {
            arg0->unk14 = &D_800D3D24;
        } else {
            arg0->unk14 = &D_800D3D28;
        }
        break;
    case 5:
        if (D_801462C8.menuToggles[3] != 0) {
            arg0->unk14 = &D_800D3D2C;
        } else {
            arg0->unk14 = &D_800D3D30;
        }
        break;
    case 6:
        if (D_801462C8.menuToggles[4] != 0) {
            arg0->unk14 = &D_800D3D34;
        } else {
            arg0->unk14 = &D_800D3D38;
        }
        break;
    case 7:
        if (D_801462C8.menuToggles[5] != 0) {
            arg0->unk14 = &D_800D3D3C;
        } else {
            arg0->unk14 = &D_800D3D40;
        }
        break;
    case 8:
        if (D_801462C8.menuToggles[6] != 0) {
            arg0->unk14 = &D_800D3D44;
        } else {
            arg0->unk14 = &D_800D3D48;
        }
        break;
    case 9:
        if (D_801462C8.menuToggles[8] != 0) {
            arg0->unk14 = &D_800D3D4C;
        } else {
            arg0->unk14 = &D_800D3D50;
        }
        break;
    }
    return 0;
}
#endif

/* note: Clears eight status bytes and selects the first available profile. */
void func_8025E384_de(void);
unsigned int Control_IsAButtonPressed(void *);
extern s32 D_8010F328;
extern s32 D_80146302;
extern struct SharedRecAt148 D_80142622[];










void Confirming_SelectConfirmingController(func_80250BD4_S1 *menuOwner) {
    Shared_func_8043DEDC_S3 *settings;
    s8 *status;
    s32 *profile;
    s32 i;

    i = 7;
    status = (s8 *)&D_80142622[0];
    for (; i >= 0; i--) {
        ((SharedRecAt148 *)status)->unk148 = 0;
        status -= 0x96;
    }
    i = 0;
    settings = (Shared_func_8043DEDC_S3 *)&D_80146302;
    for (; i < 4; i++) {
        profile = (s32 *)((char *)&D_8010F328 + i * 0x224);
        if (Control_IsAButtonPressed(profile) != 0) {
            settings->unk78 = 1;
            settings->unk7F = i;
            menuOwner->unk20 = profile;
            break;
        }
    }
    func_8025E384_de();
}

/** Dispatches to func_80264770_de or func_80264788_de with a byte read from arg0->unk20->unk4, chosen by arg1. */

extern void Control_EnableControllerPak(s32 arg);
extern void Control_DisableControllerPak(s32 arg);






void Confirming_SetMenuControllerPakEnabled(void *arg0, s32 arg1) {
    s32 val;
    MenuRecAt20V2 *menu = arg0;

    val = menu->widget->unk4;
    if (arg1 != 0) {
        Control_EnableControllerPak(val);
    } else {
        Control_DisableControllerPak(val);
    }
}

#include "COMMON/SESSIONHANDLERROW.H"
extern f32 D_800DE324_de;

void Confirming_InitMatchCounters(f32 duration, s32 mode, s32 option, s32 teams, s32 last) {
    s32 i;
    CGameStatus *state = &D_801462C8.counters;
    CGameStatus *result;
    state->m_bFragTagOn = option;
    state->teams = teams;
    state->m_CTFPlayerWithFlag = 0;
    state->timeLimit = duration * D_800DE320;
    state->mask = 0xA00;
    state->mode = mode;
    state->elapsed = 0;
    state->m_bCTFOn = last;
    for (i = 0; i < 5; i++) {
        state->scores[i] = 0;
        state->counts[i] = 0;
    }
    result = &D_801462C8.counters;
    result->round = 0;
    result->state = 0;
    if (result->timeLimit == 0.0f) {
        result->timeLimit = D_800DE324_de;
    }
}
