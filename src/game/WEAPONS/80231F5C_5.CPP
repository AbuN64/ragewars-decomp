#include "include_asm.h"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

void func_80232744_de(void *arg0, s32 arg1, s32 arg2) {
    AiTarget *target = arg0;
    func_8021A9A4_de(target->player, arg2);
}

/** Return the value pointed to by the indexed pointer table entry. */
int func_80232764_de(int arg0) {
    return *D_800CB358_de[arg0];
}

s32 func_80232780_de(s32 arg0) {
    if (arg0 < 7) {
        if (arg0 >= 3) {
            return 1;
        }
    }
    return 0;
}

/** Return whether the encoded type belongs to this caller's accepted set. */
s32 func_802327A0_de(s32 arg0) {
    {
        arg0 -= 2;
        if ((unsigned int)arg0 >= 14) {
            goto case_default;
        }
        switch (arg0) {
        case 0: goto case_2;
        case 1: goto case_default;
        case 2: goto case_default;
        case 3: goto case_default;
        case 4: goto case_default;
        case 5: goto case_2;
        case 6: goto case_2;
        case 7: goto case_2;
        case 8: goto case_default;
        case 9: goto case_default;
        case 10: goto case_default;
        case 11: goto case_2;
        case 12: goto case_2;
        case 13: goto case_2;
        }
    }
case_2:
case_7:
case_8:
case_9:
case_13:
case_14:
case_15:
    return 1;
case_default:
    return 0;
}

s32 func_802327D4_de(s32 arg0) {
    if (arg0 < 0xD) {
        if (arg0 >= 0xA) {
            return 1;
        }
    }
    return 0;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_OPTIONSSCREEN.H"
extern Shared_MenuData D_80145040;
extern Profile D_80102B00[];
extern char *D_800E0D44[];
extern char *D_800DCC68[];
extern s32 func_8022F55C_de(Profile *, s32);
extern s32 func_8022A5A0_de(Shared_MenuData *, PlayerRecAt1450V1 *);
extern void func_80239908_de(Shared_MenuObject *, void *, char *, s32, f32);

s32 func_80232790_eu(PlayerRecAt1450V1 *pThis) {
    s32 result;
    Shared_Game *settings;
    if (pThis->shield > 0.0f) {
        return 0;
    }
    if (pThis->isBot != 0) {
        return 1;
    }
    settings = &D_80145040.game;
    if (settings->controllerMode != 1) {
        return 1;
    }
    result = func_8022F55C_de(&D_80102B00[pThis->character], pThis->weapon);
    if (result == 0) {
        func_8025DF34_de(0xD4D);
        if (pThis->hud != 0) {
            s32 player = func_8022A5A0_de(&D_80145040, pThis);
            func_80239908_de(&D_80145040.object, pThis->hud,

#if defined(VERSION_EU_X)
                            D_800DCC68[settings->language],
#else
                            D_800E0D44[settings->language],
#endif
                            player, D_800C8100);
        }
    }
    return result;
}
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)

void func_80232878_eu(void *arg0, void *arg1) {
    func_802325FC_de(arg0, arg1);
    func_80214178_de(arg0, arg1, 0);
}
#endif
