#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"

/* Resets the controller and profile state for a new session: reinitialises the input buffers and stream through func_80285AC4_de, func_802BAC60_de, func_802BB550_de, func_802B7880_de, func_802BAD80_de and func_802BB420_de, then for slots 3 down to 0 clears the slot's three state words, refreshes its pad through func_80264788_de and counts the profiles func_8044B008_de accepts in D_800D0E52, remembering the lowest accepted slot in D_8010F320; finally checks the profile just below slot 0 with mode 4, marks the session reset and returns the remembered slot. */


extern char D_8010EC90[];
extern char D_8010ACC0[];
extern signed char D_8010BBB8;
extern char D_8010FC00[];
extern char D_8010BBD8[];
extern char D_8010FBC0[];
extern char D_8010B304[];
extern char D_800CBC11[];
extern char D_8010BBE0[];
extern s32 D_800CBC1C;

extern u8 D_800D0E52;

extern s32 D_8010BC28[];
extern s32 D_8010B310[];
extern ControllerProfile D_8010F328[];
extern signed char D_800CBC10;

extern void func_80285AC4_de(char *, char *, s32);
extern void func_802BAC60_de(char *, char *, s32);
extern void func_802BB550_de(s32, char *, s32);
extern void func_802B7880_de(char *, char *, char *);
extern void func_802BAD80_de(s32);
extern void func_802BB420_de(char *, s32, s32);
extern void func_80264788_de(s32);
extern s32 func_8044B008_de(ControllerProfile *, s32);

s16 func_8044AE70_de(void) {
    s32 i;

    func_80285AC4_de(D_8010EC90, D_8010ACC0, 8);
    D_8010BBB8 = 2;
    func_802BAC60_de(D_8010FC00, D_8010BBD8, 1);
    func_802BAC60_de(D_8010FBC0, D_8010B304, 1);
    func_802BB550_de(5, D_8010FC00, 1);
    func_802B7880_de(D_8010FC00, D_800CBC11, D_8010BBE0);
    func_802BAD80_de(0);
    D_800CBC1C = -1;
    func_802BB420_de(D_8010FBC0, 0, 1);
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
