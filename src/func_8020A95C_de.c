#include "span_1000/code_80209AE8.h"
#include "types.h"

void func_8020A95C_de(void *object, void *settings) {
    AiController *arg0 = object;
    AiConfig *arg1 = settings;
    f32 k = D_800C6E20;

    arg0->unk2E4 = arg1->unk0;
    arg0->unk2E4 = (s32) ((f32) arg0->unk2E4 + (func_80274564_de(k) * (f32) arg1->unk4));
    arg0->unk2E8 = arg1->unk8;
    arg0->unk2E8 = (s32) ((f32) arg0->unk2E8 + (func_80274564_de(k) * (f32) arg1->unkC));
    if (arg1->unk18 == 0x64) {
        arg0->unk240 = 1;
    }
}
