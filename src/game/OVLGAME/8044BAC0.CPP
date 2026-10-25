#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/LEVEL_TRACK.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PACKED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/LEVEL_INPUT.H"
#include "COMMON/UNUSED.H"
#include "sdk/PFS/8044BAC0.H"
#include "sdk/os.h"
#include "COMMON/PAKQUEUESTATE.H"
#include "AUDIO_4/802BFE60.H"

/* Resets the controller and profile state for a new session: reinitialises the input buffers and stream through func_80285AC4_de, osCreateMesgQueue, func_802BB550_de, func_802B7880_de, func_802BAD80_de and func_802BB420_de, then for slots 3 down to 0 clears the slot's three state words, refreshes its pad through func_80264788_de and counts the profiles func_8044B008_de accepts in D_800D0E52, remembering the lowest accepted slot in D_8010F320; finally checks the profile just below slot 0 with mode 4, marks the session reset and returns the remembered slot. */


extern char D_8010EC90[];
extern signed char D_8010BBB8;
extern char D_8010FC00[];



extern ControllerProfile D_8010F328[];
extern signed char D_800CBC10;

extern void func_80285AC4_de(char *, char *, s32);
extern void osSetEventMesg(s32, char *, s32);
extern void func_802B7880_de(char *, char *, char *);
extern void func_80264788_de(s32);

s16 func_8044AE70_de(void) {
    s32 i;

    func_80285AC4_de(D_8010EC90, D_8010ACC0, 8);
    D_8010BBB8 = 2;
    osCreateMesgQueue(D_8010FC00, D_8010BBD8, 1);
    osCreateMesgQueue(&D_8010FBC0, D_8010B304, 1);
    osSetEventMesg(5, D_8010FC00, 1);
    func_802B7880_de(D_8010FC00, D_800CBC11, D_8010BBE0);
    func_802BAD80_de(0);
    D_800CBC1C = -1;
    osSendMesg(&D_8010FBC0, 0, 1);
    D_8010F320 = -1;
    D_800D0E52 = 0;
    for (i = 3; i >= 0; i--) {
        D_8010BBF0[i] = 0;
        D_8010BC28[i] = 0;
        D_8010B310[i] = 0;
        func_80264788_de(i);
        if (func_8044B008_de(&D_8010F328[i], i) != 0) {
            D_8010F320 = i;
            D_800D0E52++;
        }
    }
    func_8044B008_de(&D_8010F328[i], 4);
    D_800CBC10 = 1;
    return D_8010F320;
}

extern u8 D_8010FBE3[];

s32 func_8044B008_de(ControllerProfile *profile, s32 port) {
    s32 i;
    s32 connected;
    profile->port = port;
    profile->connected = 0;
    profile->pakActive = 0;
    profile->mode = 0;
    profile->reset = 0;
    profile->unk8 = 0;
    profile->unkC = 0;
    profile->unk10 = 0;
    profile->stickX = 0;
    profile->stickY = 0;
    profile->previousStickX = 0;
    profile->previousStickY = 0;
    profile->inputPreviousButtons = 0;
    profile->inputButtons = 0;
    profile->inputPressedButtons = 0;
    profile->inputHistory[0] = 0;
    profile->inputHistory[1] = 0;
    profile->inputHistory[2] = 0;
    for (i = 0; i < 32; i++) {
        profile->buttonHistory[i].taps = 0;
        profile->buttonHistory[i].age = 0;
        profile->buttonHistory[i].repeat = 48;
        profile->buttonHistory[i].held = 0;
    }
    connected = ((D_8010FBE3[port * 4] >> 3) ^ 1) & 1;
    profile->pakAmount = 0;
    profile->pakTimer = 0;
    profile->connected = connected;
    func_80285AC4_de((char *)&profile->effectPool, (char *)profile->effectNodes, 3);
    return profile->connected;
}

#if defined(VERSION_US)
char rodata_unresolved_8044B248[8] =
    "CMiscVar";
#endif
