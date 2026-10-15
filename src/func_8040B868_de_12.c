#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BA23C.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"
#include "stddef.h"
/* Selects the video mode and applies framebuffer and display configuration; the mode-to-word-array cast preserves configuration-store and mode-load scheduling. */
s32 func_80265350_de(); /* extern */
                                 /* extern */
void func_8040C484_de(s32, s32, s32, s32, s32, s32); /* extern */
extern s32 D_80000300;
extern s32 D_800CC374;
extern s32 D_800E28D0,D_800E28D4;
extern s32 D_800E28D8;
extern u8 D_800E28DB;
extern struct ShapeRecAt18V2 D_800DE8A8[];
extern struct ShapeRecAt18V2 D_800DE934[];
extern Rec_func_8024C92C_de D_800DE9C0[];
extern char D_800E2A14;
extern char D_800E2A18;
extern char D_800E2A1C;
extern char D_800E2A20;
extern u8 D_80146848;
static inline void set_config(int a,int b,int c,int d,int e) {
        D_800DE898 = a;
        D_800CC370 = b;
        D_800CC374 = c;
        D_800CC378 = d;
        D_800CC37C = e;
}
static inline void set_mode(s32 *var_s0) {
        D_800E28D0 = (s32) var_s0[0];
        D_800E28D4 = (s32) var_s0[1];
        func_8040C484_de(var_s0[0], var_s0[1], var_s0[2], var_s0[3], var_s0[4], var_s0[5]);
}
void func_8040BBB0_de(void) {
    char *var_v0;
    s32 var_a0;
    s32 temp_v0;
    s32 var_v1;
    struct ShapeRecAt18V2 *var_s0;
    var_s0 = NULL;
    D_80141000 = 2;
    if (D_800E28D8 == -1) {
        if (func_80265350_de() != 0x400000) {
            D_800E28D8 = 1;
        } else {
            D_800E28D8 = 0;
        }
        D_80146848 = D_800E28DB;
    }
    switch(D_80000300) {
    case 1: var_s0=&D_800DE8A8[D_800E28D8];break;
    case 0:case 2:var_s0=&D_800DE934[D_800E28D8];break;
    }
    if (var_s0 != NULL) {
        Rec_func_8024C92C_de config=D_800DE9C0[D_800E28D8];
        set_config(config.x,config.y,config.z,config.pad0,config.pad1);
        set_mode((s32 *)var_s0);
        var_a0 = 0x80;
        if (D_800DE898 != 0) {
            var_a0 = 0x40;
        }
        func_802BA700_de(var_a0);
        func_802BA700_de(0x20);
        func_802BA700_de(2);
    }
}
