#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B369C.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B4730.h"
#include "TYPES.H"

extern s32 D_002B5570;
extern s32 D_002B5730;

void func_802B53E0_de(void *arg0, void *a, void *b, s32 c);
s32 func_802B0340_de(s32 a, s32 b, s32 c, s32 d, s32 e);

void func_802B450C_de(ALResampler_s *arg0, s32 arg1) {
    s32 result;
    f32 k;

    func_802B53E0_de(arg0, &D_002B5570, &D_002B5730, 1);
    result = func_802B0340_de(0, 0, arg1, 1, 0x20);
    k = D_800C75E0_de;
    arg0->state = (void *)result;
    arg0->delta = 0;
    arg0->first = 1;
    arg0->motion = 0;
    arg0->upitch = 0;
    arg0->ctrlList = 0;
    arg0->ctrlTail = 0;
    arg0->ratio = k;
}

extern s32 D_002B6380;
extern s32 D_002B6480;
void func_802B4598_de(ALSave *arg0) {
    func_802B53E0_de(arg0, (s32) &D_002B6380, (s32) &D_002B6480, 3);
    arg0->dramout = 0;
    arg0->first = 1;
}
