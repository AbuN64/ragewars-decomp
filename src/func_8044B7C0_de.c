#include "types.h"
#include "audio_callbacks.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_80245BC0_de_closed.h"
#include "shared/func_80286080_de_closed.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_80447BB0.h"
#include "span_16E000/code_8044ACCC.h"
extern void func_80449E18_de(Node_func_80449E18_de *);
extern void func_80253908_de(s32 unusedHeap);
extern s32 func_80254284_de(s32,void **,s32,void *);
extern void **func_80254408_de(s32,s32,s32,s32,s32,s32,void *);
extern void func_80286AA8_de(void *,s32,s32);
extern int func_8028FE28_de(int *,int,int);
extern s32 func_8028FE3C_de(s32,s32,s32,s32 *);
extern s32 D_00285160;
extern s32 D_800CD764_de;
extern char D_800F41F0;
void func_8044B7C0_de(LevelCode8044ACCC *arg0, s32 arg1) {
    s32 *sp20;
    s32 *sp24;
    void **temp_v0_10;
    void **temp_v0_5;
    void **temp_v0_9;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v1;

    func_8028D64C_de(arg0);
    arg0->unk0 = 0;
    func_8044D1B4_de((char *)arg0);
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk1B40C = -1;
    arg0->unk1B31C = 0;
    arg0->unk1B308 = 0;
    arg0->unk1B614 = 0;
    arg0->unk1B618 = 0;
    arg0->unk1B61C = 0;
    arg0->unk1B660 = 0;
    arg0->unk1B6A4 = 0;
    arg0->unk1B6AC = 0;
    /* The global is the holder storage; its canonical scalar declaration is incomplete. */
    ((void (*)(void *))func_80449E18_de)(&D_80145040);
    /* The original resource API passes the unused arena argument. */
    func_80253908_de(0);
    func_80254284_de(0, (void **)&sp20, arg1, &D_800C4F50_de);
    temp_v0 = func_8028FE28_de(sp20, arg1, 5);
    arg0->unk1C = temp_v0;
    func_80254284_de(0, (void **)(arg0->pad40 + 0xC), temp_v0, &D_800C4F60_de);
    temp_v0_2 = func_8028FE28_de(sp20, arg1, 3);
    arg0->unk20 = temp_v0_2;
    func_80254284_de(0, (void **)(arg0->pad40 + 0x10), temp_v0_2, &D_800C4F70_de);
    arg0->unk94 = (s32) *func_80254408_de(0, (s32)sp20, 2, arg1, (s32)arg0, (s32)&D_00285160, &D_800C4F84_de);
    temp_v0_3 = func_8028FE28_de(sp20, arg1, 0);
    arg0->unk24 = temp_v0_3;
    func_80254284_de(0, (void **)(arg0->pad40 + 0x14), temp_v0_3, &D_800C4F94_de);
    arg0->unk78 = (s32) *func_80254408_de(0, (s32)sp20, 1, arg1, (s32)arg0, (s32)&D_0044D934, &D_800C4FA4_de);
    arg0->unkB4 = func_80254408_de(0, (s32)sp20, 4, arg1, (s32)arg0, (s32)&D_0044D804, &D_800C4FB4_de);
    arg0->unk98 = (s32) *func_80254408_de(0, (s32)sp20, 0xA, arg1, (s32)arg0, (s32)&D_00285160, &D_800C4F84_de);
    temp_v0_4 = func_8028FE28_de(sp20, arg1, 9);
    arg0->unk28 = temp_v0_4;
    func_80254284_de(0, (void **)(arg0->pad40 + 0x18), temp_v0_4, &D_800C4FC8_de);
    arg0->unk70 = (s32) *func_80254408_de(0, (s32)sp20, 0xB, arg1, (s32)arg0, (s32)&D_00285160, &D_800C4FD8_de);
    temp_v1 = (s32) *func_80254408_de(0, (s32)sp20, 0xC, arg1, (s32)arg0, (s32)&D_00285160, &D_800C4FEC_de);
    arg0->unk80 = &D_800F91F0;
    arg0->unkA0 = temp_v1;
    arg0->unk38 = func_8028FE3C_de((s32)sp20, arg1, 6, (s32 *)(arg0->pad40 + 0x4));
    arg0->unk84 = &D_800F41F0;
    arg0->unk3C = func_8028FE3C_de((s32)sp20, arg1, 7, (s32 *)(arg0->pad40 + 0x8));
    temp_v0_5 = func_80254408_de(0, (s32)sp20, 8, arg1, (s32)arg0, (s32)&D_00285160, &D_800C4FFC_de);
    arg0->unk10C = temp_v0_5;
    arg0->unk90 = (s32) *temp_v0_5;
    arg0->unkA4 = (s32) *func_80254408_de(0, (s32)sp20, 0xD, arg1, (s32)arg0, (s32)&D_00285160, &D_800C5008_de);
    arg0->unkAC = (s32) *func_80254408_de(0, (s32)sp20, 0xE, arg1, (s32)arg0, (s32)&D_00285160, &D_800C5010_de);
    arg0->unkA8 = (s32) *func_80254408_de(0, (s32)sp20, 0xF, arg1, (s32)arg0, (s32)&D_00285160, &D_800C5018_de);
    arg0->unk9C = (s32) *func_80254408_de(0, (s32)sp20, 0x11, arg1, (s32)arg0, (s32)&D_00285160, &D_800C5028_de);
    temp_v0_6 = func_8028FE28_de(sp20, arg1, 0x10);
    arg0->unk2C = temp_v0_6;
    func_80254284_de(0, (void **)(arg0->pad40 + 0x1C), temp_v0_6, &D_800C5038_de);
    temp_v0_7 = func_8028FE28_de(sp20, arg1, 0x12);
    arg0->unk34 = temp_v0_7;
    func_80254284_de(0, (void **)arg0->pad74, temp_v0_7, &D_800C504C_de);
    func_80403BE0_de();
    temp_v0_8 = (s32) *func_80254408_de(0, (s32)sp20, 0x13, arg1, (s32)arg0, (s32)&D_00285160, &D_800C505C_de);
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = -1;
    arg0->unkB0 = temp_v0_8;
    if (*sp20 >= 0x16) {
        arg0->unkC = func_8028FE28_de(sp20, arg1, 0x15);
        temp_v0_9 = /* This callee returns its allocated resource handle, not an integer ID. */
            ((void **(*)(s32,void **,s32,void *,s32))func_802540F4_de)(0, (void **)&sp24, arg0->unkC, &D_800C5070_de, 1);
        if (temp_v0_9 != 0) {
            arg0->unk10 = (s32) (((*sp24 * 4) + 0xF) & ~7);
            func_80253838_de(0, temp_v0_9);
        } else {
            arg0->unkC = 0;
        }
    }
    if (*sp20 >= 0x18) {
        temp_v0_10 = func_80254408_de(0, (s32)sp20, 0x17, arg1, (s32)arg0, (s32)&D_00285160, &D_800C5098_de);
        func_8020A604_de(*temp_v0_10);
        func_80253838_de(0, temp_v0_10);
    }
    /* The state setup API passes the unused level number in a1. */
    ((void (*)(char *,s32))func_8044CFF8_de)((char *)arg0, arg1);
    D_800CD764_de = 1;
    func_8044B600_de(arg0, arg0->pad1B410 + 0x40, 0xDAC);
    func_8044B600_de(arg0, arg0->pad1B410 + 0x5C, 0xDAD);
    func_8044B600_de(arg0, arg0->pad1B410 + 0x78, 0xDAE);
    func_8044B600_de(arg0, arg0->pad1B410 + 0x94, 0xDAF);
    func_8044B600_de(arg0, arg0->pad1B410 + 0xB0, 0xDB0);
    arg0->unkF0 = 0;
    arg0->unkF4 = 0;
    arg0->unkFC = 0;
    arg0->unkF8 = 0;
    arg0->unk88 = 0;
    arg0->unk120 = 0;
    arg0->unk124 = 0;
    func_80286AA8_de(arg0, 0, 0);
}
