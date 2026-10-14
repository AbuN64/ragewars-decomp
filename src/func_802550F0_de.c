#include "span_1000/code_802BB15C.h"
#include "span_1000/code_802508E0.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80254CE4.h"
#include "types.h"

extern void func_802BAC60_de(void *arg0, s32 arg1, s32 arg2);
extern void func_802A001C_de(void *arg0, s32 arg1, s32 arg2);
extern void func_802BAC90_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_802BB750_de(s32 arg0);
extern s32 D_800CD8AC_de;
extern s32 D_00255280;

void func_802550F0_de(s32 arg0, s32 arg1) {
    func_802BAC60_de((void *)(arg0 + 0x230), arg0 + 0x248, 0x80);
    func_802A001C_de((void *)(arg0 + 0x448), arg1, 0x1000);
    func_802BAC90_de(arg0, arg1, &D_00255280, arg0, arg0 + 0x1448, D_800CD8AC_de);
    func_802BB750_de(arg0);
}

extern void func_802BAC60_de(void *arg0, s32 arg1, s32 arg2);
extern s32 func_802BB5F0_de(s32 *, s32);
extern void func_802BB160_de(s32 *arg0, void *arg1, s32 arg2);

extern s32 D_800CD704;






s32 func_80255170_de(s32 *arg0, void *arg1) {
    char sp10[0x18];
    s32 sp28;
    s32 sp2C;
    s32 temp;

    func_802BAC60_de(sp10, (s32) &sp28, 1);
    temp = D_800CD8B8_de;
    ((ResourceLoadRequest *)arg1)->replyQueue = sp10;
    D_800CD704 = 2;
    func_802BB5F0_de(arg0, temp);
    func_802BB160_de((s32 *)&((ResourceLoadWorker *)arg0)->requests, arg1, 1);
    func_802BB2A0_de(sp10, (s32) &sp2C, 1);
    return 1;
}

s32 func_802551FC_de(s32 arg0, void *arg1, s32 arg2) {
    (((struct Shape_typemap_30 *) ((s8 *) arg1))->field_20) = arg2;
    return ~func_802BB420_de(arg0 + 0x230, (s32) arg1, 0) != 0;
}

extern s32 func_802BB5F0_de(s32 *, s32);
extern s32 D_800CD8AC_de;





s32 func_80255228_de(s32 *arg0) {
    if (((ResourceLoadWorker *)arg0)->requests.validCount != 0) {
        do {
            func_802BB5F0_de(arg0, D_800CD8B8_de);
        } while (((ResourceLoadWorker *)arg0)->requests.validCount != 0);
    }
    return func_802BB5F0_de(arg0, D_800CD8AC_de);
}
