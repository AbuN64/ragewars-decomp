#include "shared/world.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80293A04.h"
#include "types.h"
#include "common/unused.h"
#include "span_C76B0/data.h"
#include "common/types_8fd754e1e915.h"
#include "n64sdk.h"
#include "gbi.h"

/** Perform no work for callers at VRAM 0x80293DDC. */
void func_80293DE8_de(void) {
}

extern s32 D_800E28C8;

extern s32 D_80146D60;

extern s32 D_8014AD94;

extern void func_8040C428_de(s32 arg0);
extern void func_80298368_de(s32 arg0);

void func_80293DF0_de(void *arg0) {
    D_800E28C8 = -1;
    D_80146D70 = 0;
    func_8040C428_de(0);
    D_800CD774 = 1;
    D_80146D60 = 1;
    D_800E28CC = 1;
    D_8014AD94 = 0;
    ((func_80293378_S1 *)(arg0))->unk26DC4 = D_800C54C0_de;
    func_80298368_de(0x1D);
}

s32 func_802647C4_de();
void func_80293E6C_de(void *arg0) {
    if (D_8014ADA0 != 0) {
        func_80293824_de(arg0, 1);
        func_802647C4_de();
    }
}

/** Thin wrapper around func_80293CE4_de. */
void func_80293E9C_de(void) {
    func_80293CE4_de();
}


extern void func_80293334_de(void *arg0, void *arg1, void *arg2);
extern void func_8044A370_de(void *arg0, s32 arg1);
extern void func_80296004_de(unsigned int value);
extern u8 D_801468A0;


void func_80293EB8_de(void *arg0) {
    s8 *p1;
    s8 *p2;
    int new_var;

    func_8025E2D4_de(0);
    new_var = 0x5D8;
    p1 = ((s8 *)(&D_801468A0)) - new_var;
    ((struct IntegerStateB0 *) ((char *) (&D_801468A0)))->unk_AC = 0;
    ((struct IntegerStateB0 *) ((char *) (&D_801468A0)))->unk_88 = 0;
    p1[0xB2] = 1;
    p1[0x1D] = 0;
    p1[0x1E] = 1;
    func_80293334_de(arg0, 0, 0);
    func_80286AA8_de(&D_8011FE88, 0, 0);
    p2 = ((s8 *)(&D_801468A0)) - 0x1818;
    func_8044A370_de(p2, 1);
    ((IntegerState164 *)(p2))->unk_160 = 0;
    func_80296004_de(0);
}

struct func_80293B0C_S1;




extern s32 D_800CD77C;
extern u32 func_80265350_de(void);
extern s32 func_80293904_de(s32 arg0, u32 arg1, s32 arg2, s32 arg3);

void func_80293F44_de(void *arg0) {
    s32 var_a2;
    s32 call_result;
    u32 result;

    result = func_80265350_de();
    var_a2 = 4;
    if ((result > 0x400000U) && (D_800D29C8 != 0)) {
        var_a2 = 3;
    }
    if (((func_80293B0C_S1 *)(arg0))->unk26DB0.v0 > D_800C54C4_de) {
        D_800CD77C = 0;
    }
    if (D_800CD77C != 0) {
        call_result = func_80293904_de((s32)arg0, 0x41400000U, var_a2, -1);
    } else {
        call_result = func_80293904_de((s32)arg0, 0x41400000U, var_a2, var_a2);
    }
    if (call_result != 0) {
        D_800CD77C = 0;
    }
}

/* Emits a set-color-image display list command for the current frame buffer, then draws image 0x388
 * scaled to fill the screen dimensions over the image's returned width and height, when both are nonzero. */




extern void func_802A9234_de(s32);

extern void func_802AAC28_de(s32 image, s32 frame, s32 x, s32 y, f32 scaleX, f32 scaleY, s32 flags);
extern Gfx *D_80110634;
extern Frame *D_8011BDC0;
extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_80293FF0_de(void) {
    s32 width;
    s32 height;
    Gfx *cmd;

    width = 0;
    height = 0;
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)D_8011BDC0->colorImage);
    func_802AA950_de(0x388, 0, &width, &height);
    if ((width != 0) && (height != 0)) {
        func_802A9234_de(0xFA);
        func_802AAC28_de(0x388, 0, 0, 0, (f32)D_800E28D0 / (f32)width, (f32)D_800E28D4 / (f32)height, 1);
    }
}
