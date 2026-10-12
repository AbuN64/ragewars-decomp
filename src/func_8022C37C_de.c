#include "span_16E000/code_80400000.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"

extern u8 D_801462DE;


extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_802A9234_de(u8 arg0);
void func_802AAC28_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);






void func_8022C37C_de(struct SharedPlayer *arg0, struct ScreenRectangle *arg1) {
    f32 x, y;
    f32 sx, sy;
    f32 bx, by, cz;
    f32 t1, t2;
    f32 w;
    f32 screenX, screenY;

    func_802A9234_de(D_801462DE);

    x = arg1->x;
    sx = x / (f32) D_800E28D0;
    bx = sx * D_800C2D38_de;

    y = arg1->y;
    sy = y / (f32) D_800E28D4;
    by = sy * D_800C2D38_de;

    cz = sy * D_800C2D3C_de;

    t1 = arg1->width + x;
    t2 = arg1->height + y;
    w = arg0->views5E8.view7BC_101.unk7BC;

    screenX = t1 + bx;
    screenY = t2 + by;

    func_802AAC28_de(0x201, (s32) w, (s16) (s32) screenX, (s16) (s32) screenY, sx, cz, 1);
}
