#include "include_asm.h"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "MENU_2/804366D0_2.H"

#ifdef NON_MATCHING
extern struct State_func_804366B8_de *D_800E5690;
extern s32 D_800D34A4, D_800D34B0, D_800D3470_de, D_800D3474, D_800D34B4, D_800D34B8, D_800D34BC;
extern s32 func_8025305C_de(s32);
extern s32 func_8041A280_de(s32, s32);
extern void func_8041B110_de(s32);
extern s32 func_8041ABC0_de(s32, s32);
extern void func_8041AD34_de(s32, s32);
extern s32 func_8041A580_de(s32, s32, s32);
extern s32 func_80419E54_de(s32, s32);
extern s32 func_8040EC30_de(s32, s32);
#define ST ((s32 *)D_800E5690)
/* 100/114 words; remaining: scheduling: the target stores each handle before loading the second argument and keeps the argument move in the call delay slot */
s32 func_804364E4_de(s32 arg0) {
    s32 t;
    D_800E5690 = (struct State_func_804366B8_de *)func_8025305C_de(0x64);
    ST[0] = func_8041A280_de(0x5B, 0x5C);
    func_8041B110_de(0x5E);
    t = func_8041ABC0_de(0x64, 0x65);
    ST[5] = t;
    func_8041AD34_de(t, D_800D34A4);
    func_8041AD34_de(ST[5], D_800D34B0);
    t = func_8041ABC0_de(0x61, 0x63);
    ST[4] = t;
    func_8041AD34_de(t, D_800D3470_de);
    func_8041AD34_de(ST[4], D_800D3474);
    ST[2] = func_8041A580_de(0x66, 0x67, 0xF8);
    ST[3] = func_8041A580_de(0x6A, 0x6B, 0xF8);
    t = func_8041ABC0_de(0x68, 0x69);
    ST[6] = t;
    func_8041AD34_de(t, D_800D34B4);
    func_8041AD34_de(ST[6], D_800D34B8);
    func_8041AD34_de(ST[6], D_800D34BC);
    func_8041B110_de(0x60);
    ST[1] = func_80419E54_de(0x5D, 0x6E);
    ST[9] = 3;
    ST[8] = -1;
    ST[0xB] = func_8040EC30_de(arg0, 0x5F);
    ST[0xA] = 0;
    func_804366B8_de(0);
    return 0;
}
#undef ST
#else
INCLUDE_ASM("ovl_80400000", func_804364E4_de);
#endif

/* Stores arg0 into its own D_80146417 entry and pushes the five settings of slot arg0 of the D_80102C89 table into the objects D_800E5690 holds through func_8041AD10_de and func_8041A6EC_de. */


extern struct State_func_804366B8_de *D_800E5690;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern u8 D_80146417[];
extern void func_8041AD10_de(void *, s32);
extern void func_8041A6EC_de(void *, s32);

void func_804366B8_de(s32 arg0) {
    u8 *slot = &D_80146417[arg0 * 0x96];

    *slot = arg0;
    func_8041AD10_de(D_800E5690->a, D_80102C89[arg0 * 0x190]);
    func_8041AD10_de(D_800E5690->b, D_800FEC8A[arg0 * 0x190]);
    func_8041A6EC_de(D_800E5690->c, D_800FEC8B[arg0 * 0x190]);
    func_8041A6EC_de(D_800E5690->d, D_800FEC8C[arg0 * 0x190]);
    func_8041AD10_de(D_800E5690->e, D_800FEC8D[arg0 * 0x190]);
}

/* Reads five settings from the objects D_800E5690 holds through func_8041AD04_de and func_8041A6E0_de into slot arg0 of the D_80102C89 table and copies them into the matching bytes of the arg0 entry of D_80146398. */


extern struct State_func_804366B8_de *D_800E5690;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern u8 D_80146398[];
extern s32 func_8041AD04_de(void *);
extern s32 func_8041A6E0_de(void *);

void func_804367A8_de(s32 arg0) {
    u8 *config;

    config = D_80146398 + arg0 * 0x96;
    D_80102C89[arg0 * 0x190] = func_8041AD04_de(D_800E5690->a);
    do {
        D_800FEC8A[arg0 * 0x190] = func_8041AD04_de(D_800E5690->b);
        D_800FEC8B[arg0 * 0x190] = func_8041A6E0_de(D_800E5690->c);
        D_800FEC8C[arg0 * 0x190] = func_8041A6E0_de(D_800E5690->d);
        D_800FEC8D[arg0 * 0x190] = func_8041AD04_de(D_800E5690->e);
    } while (0);
    config[0x7B] = D_80102C89[arg0 * 0x190];
    config[0x7D] = D_800FEC8A[arg0 * 0x190];
    config[0x79] = D_800FEC8B[arg0 * 0x190];
    config[0x7A] = D_800FEC8C[arg0 * 0x190];
    config[0x82] = D_800FEC8D[arg0 * 0x190];
}
