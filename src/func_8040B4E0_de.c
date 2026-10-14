#include "span_16E000/code_8040B45C.h"
#include "types.h"





extern s32 D_8015375C;
extern s32 D_80153784;
extern s32 D_800E28C8;
extern char D_0044EE88;
extern char D_8014561C;
extern s32 func_80406178_de(Action_func_8040B4E0_de *action, s32 channel, s32 arg2);
extern void func_80442574_de(void *dst, void *text, void *arg2, void *arg3, void *arg4);

/* Starts the action's channel (D_800E28C8 in demo mode, else the record's inner value) through func_80406178_de; on success loads the record's actor resource into D_8014561C and latches D_80153784, otherwise loads the shared fallback text with the actor as extra argument. Returns 1. */
s32 func_8040B4E0_de(s32 arg0, Action_func_8040B4E0_de *arg1) {
    s32 channel;

    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = arg1->unk20->unk4;
    }
    if (func_80406178_de(arg1, channel, 1) == 0) {
        func_80442574_de(&D_8014561C, &D_0044EE88, arg1->unk1C, arg1->unk20, arg1->unk24);
    } else {
        D_80153784 = 1;
        func_80442574_de(&D_8014561C, arg1->unk24, arg1->unk1C, arg1->unk20, 0);
    }
    return 1;
    /* FAKEMATCH: preserve the return-value load before the epilogue register restores. */
    do {
    } while (0);
}
