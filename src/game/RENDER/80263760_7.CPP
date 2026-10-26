#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "AUDIO_4/802BFE60.H"
#include "sdk/os.h"

/* Reinitializes a present controller pak entry under the pak queue lock, resets its counters and label, retries initialization, and releases the lock; an unsigned pointer local and a queue address relative to the adjacent status byte separate address lifetimes and preserve register scheduling. */



extern u8 D_800CBC10;


extern s8 D_8010BBB8;

extern char D_8010FC00;


extern s32 Rumble_InitPoolNodes(void *, void *, s32);

extern s32 func_802B7FD8_de(void *, void *, s32);

#if defined(VERSION_EU)

#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)

#elif defined(VERSION_US)

#else

#endif




extern void func_8029A650_de(void *arg0);








void Control_ResetControllerPak(ControllerProfile *pakProfile) {

    u32 address=(u32)pakProfile;
    char *o=(char *)address;

    if (D_800CBC10 != 0 && ((Obj80264124 *)address)->flags != 0) {
        if (osRecvMesg(&D_8010FBC0, 0, 1) == 0) {
            D_800CBC1C = func_802BAD80_de(0);
        }
        Control_ReadControllerStates();
        D_8010BBB8 = 2;
        ((Obj80264124 *)o)->state = 0;
        ((Obj80264124 *)o)->amount = 0;
        ((Obj80264124 *)o)->timer = 0;
        Rumble_InitPoolNodes(o + 0x140, o + 0x16C, 3);
        func_802B7FD8_de(&D_8010FC00, o + 0xD8, pakProfile->port);
        
#if defined(VERSION_EU)
func_802B7EF0_eu
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#if defined(VERSION_EU) || defined(VERSION_US)
func_802B7F30_eu_x
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
((u32 (*)(void *))func_802B7F30_eu_x)
#endif
#elif defined(VERSION_US)
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
func_802B7B80_us
#elif defined(VERSION_US)
((u32 (*)(void *))func_802B7B80_us)
#endif
#else
#if defined(VERSION_DE)
((u32 (*)(void *))func_802B7C50_de)
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_802B7C50_de
#endif
#endif
(((Obj80264124 *)o)->status);
        
#if defined(VERSION_EU)
func_802B7EF0_eu
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#if defined(VERSION_EU) || defined(VERSION_US)
func_802B7F30_eu_x
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
((u32 (*)(void *))func_802B7F30_eu_x)
#endif
#elif defined(VERSION_US)
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
func_802B7B80_us
#elif defined(VERSION_US)
((u32 (*)(void *))func_802B7B80_us)
#endif
#else
#if defined(VERSION_DE)
((u32 (*)(void *))func_802B7C50_de)
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_802B7C50_de
#endif
#endif
(((Obj80264124 *)o)->status);
        if (func_802B7FD8_de(&D_8010FC00, o + 0xD8, pakProfile->port) == 0) {
            ((Obj80264124 *)o)->active = 1;
        }
        D_8010BBB8 = 2;
        D_800CBC1C = -1;
        osSendMesg(&((PakQueueState *)&D_8010BBB8)->queue, 0, 1);
    }
}

/** Report whether flag 0x1000 is set in the word at offset 0xB4. */
int Control_IsStartPressed(Shared_Effect *object) {
    int flags = object->state & 0x1000;
    return flags != 0;
}

int Control_IsStartButtonSet(Shared_Effect *effect) {
    int flag = effect->state & 0x1000;
    return flag != 0;
}

/** Return the high bit of the byte at object offset 0xB6. */
unsigned int Control_IsAButtonPressed(struct ControllerProfile *profile) {
    return ((u8)(profile->pressedButtons >> 8)) >> 7;
}

/** Report whether any of the selected object flag bytes are set. */
int Control_IsLeftPressed(struct ControllerProfile *object) {
    return (object->buttonState & 0x20202) != 0;
}

/** Report whether any selected status bit is set. */
int Control_IsRightPressed(struct ControllerProfile *object) {
    return (object->buttonState & 0x40101) != 0;
}

int Control_IsNavUp(void *controllerProfile) {
    ControllerProfile *profile = controllerProfile;
    int flag = profile->buttonState & 0x10808;
    return flag != 0;
}

int Control_IsNavDown(void *controllerProfile) {
    ControllerProfile *profile = controllerProfile;
    int flag = profile->buttonState & 0x80404;
    return flag != 0;
}

int Control_IsButtonBSet(Shared_Effect *effect) {
    int flag = effect->state & 0x4000;
    return flag != 0;
}

int Control_IsButtonAPressed(struct ControllerProfile *controllerProfile) {
    return ((u8)(controllerProfile->pressedButtons >> 8)) >> 7;
}

void Control_CommitControllerInputs(void) {
    s32 i;
    ControllerProfile *p;
    s32 temp;
    s32 one;

    if (D_800CBC10 != 0) {
        i = 0;
        one = 1;
        p = D_8010F328;
        for (; i < 4; i++, p += 1) {
            Control_CommitProfileInput(p);
            temp = func_802A23B4_de();
            if (temp != one) {
                continue;
            }
            if (func_802A23A4_de() != temp) {
                continue;
            }
            func_8029A650_de(p);
        }
        Control_CommitProfileInput(&D_8010B0E0);
    }
}

/** Shift the trailing state-history slots down and clear the newest slot. */
void Control_CommitProfileInput(void *controllerProfile) {
    ControllerProfile *o = controllerProfile;
    u8 t_c4;
    u8 t_c5;
    s32 t_b0;
    s32 t_18;
    u32 t_1c;
    s32 t_20;
    s32 t_24;
    s32 t_28;

    t_c4 = o->stickX;
    t_c5 = o->stickY;
    t_b0 = o->buttons;
    t_18 = o->inputButtons;
    t_1c = o->inputPressedButtons;
    t_20 = o->inputHistory[0];
    t_24 = o->inputHistory[1];
    t_28 = o->inputHistory[2];
    o->inputPressedButtons = 0;
    o->inputHistory[0] = 0;
    o->inputHistory[1] = 0;
    o->inputHistory[2] = 0;
    o->previousStickX = t_c4;
    o->previousStickY = t_c5;
    o->previousButtons = t_b0;
    o->buttons = t_18;
    o->pressedButtons = t_1c;
    o->history[0] = t_20;
    o->history[1] = t_24;
    o->buttonState = t_28;
}

s32 Control_AcquireControllerLock(s32 arg0) {

    s32 result;

    result = osRecvMesg(&D_8010FBC0, 0, arg0) == 0;
    if (result != 0) {
        D_800CBC1C = func_802BAD80_de(0);
    }
    return result;
}

void Control_ReleasePakLock(void) {

    D_800CBC1C = -1;
    osSendMesg(&D_8010FBC0, 0, 1);
}

/** Fetch-and-clear: return the old slot value, then zero it. */
s32 Control_TakePakChange(s32 controllerPort) {
    s32 old;

    if (Control_IsControllerPakEnabled(controllerPort) == 0) {
        return 0;
    }
    old = D_8010BBF0[controllerPort];
    D_8010BBF0[controllerPort] = 0;
    return old;
}

s32 Control_PeekPakChange(s32 controllerPort) {
    if (Control_IsControllerPakEnabled(controllerPort) == 0) {
        return 0;
    }
    return D_8010BBF0[controllerPort];
}

int Control_IsControllerConnected(int arg0) {
    return ((D_8010FBE3[arg0 * 4] >> 3) ^ 1) & 1;
}

int Control_IsControllerPakPresent(int arg0) {
    return D_8010BBE2[arg0 * 4] & 1;
}

s32 Control_AnyControllerConnected(void) {
    s32 i = 0;
    while (1) {
        if (!(((D_8010FBE3[i * 4] >> 3) ^ 1) & 1)) {
            i += 1;
            if (i >= 4) {
                return 0;
            }
        } else {
            return 1;
        }
    }
}

s32 Control_CountConnectedControllers(void) {
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    do {
        if (((D_8010FBE3[i * 4] >> 3) ^ 1) & 1) {
            count += 1;
        }
        i += 1;
    } while (i < 4);
    return count;
}

s32 Control_FindConnectedControllerPort(s32 arg0) {
    s32 var_a1;
    s32 var_v1;

    var_a1 = 0;
    var_v1 = 0;
loop_1:
    if (((D_8010FBE3[var_v1 * 4] >> 3) ^ 1) & 1) {
        var_a1 += 1;
    }
    if ((var_a1 - 1) != arg0) {
        var_v1 += 1;
        if (var_v1 >= 4) {
            return -1;
        }
        goto loop_1;
    }
    return var_v1;
}

s32 Control_IsAnyControllerPakEnabled(void) {
    s32 i = 0;
    while (1) {
        if (D_8010B308[i] == 0) {
            i += 1;
            if (i >= 4) {
                return 0;
            }
        } else {
            return 1;
        }
    }
}

int Control_IsControllerPakEnabled(int arg0) {
    return D_8010B308[arg0];
}

void Control_EnableControllerPak(int controllerPort) {
    D_8010B308[controllerPort] = 1;
}

void Control_DisableControllerPak(int controllerPort) {
    D_8010B308[controllerPort] = 0;
}

void Control_EnableAllControllerPaks(void)
{
  int new_var2;
  s8 *new_var;
  s32 var_v1;
  s8 *var_v0;
  new_var2 = 1;
  var_v1 = 3;
  new_var = &D_8010B30B;
  var_v0 = new_var;
  do
  {
    *var_v0 = new_var2;
    var_v1 -= 1;
    var_v0 -= 1;
  }
  while (var_v1 >= 0);
}

void Control_DisableAllControllerPaks(void) {
    s32 var_v1;
    s8 *var_v0;
    var_v1 = 3;
    var_v0 = &D_8010B30B;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}
