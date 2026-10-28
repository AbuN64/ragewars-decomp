#ifndef SYSTEM_802A6AC0_H
#define SYSTEM_802A6AC0_H
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/ITEMRECAT20V1.H"
struct StateFrontendScrollResultsBackward {
    char pad[0xE8];
    s32 count;
};
struct ObjRecAt3CV1 {
    char pad0[0x14];
    f32 unk14;
    char pad14[0x24 - 0x14 - sizeof(f32)];
    f32 unk24;
    char pad24[0x34 - 0x24 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
};
struct ObjRecAt18V6 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
};
struct Input_func_802A65E0_de {
    char pad0[0x5DC];
    struct View *view; /* 0x5DC: viewport owner used by the toggle-menu renderer */
    char pad5E0[0x6AC - 0x5E0];
    s32 held;
    s32 pressed;
};
struct Sprite {
    s32 format;
    char *data;
    s32 field8;
    s32 fieldC;
    f32 width;
    f32 height;
    f32 extentX;
    f32 extentY;
    f32 step;
};
struct ToggleMenu {
    u8 state;
    u8 timer;
    MenuItem items[4];
    u16 selected;
    s16 blink;
    s32 frame;
};
struct ObjectLinks7598 {
    char pad0[0x7588];
    char unk_7588;
    char pad7588[0x7594 - 0x7588 - sizeof(char)];
    void * unk_7594;
};
struct ObjectState30_2 {
    unsigned char padding_0[4];
    s32 unk_4;
    unsigned char padding_8[16];
    s16 unk_18;
    unsigned char padding_1A[2];
    s32 unk_1C;
    f32 unk_20;
    s32 unk_24;
    f32 unk_28;
    s32 unk_2C;
};
struct ObjectLinks14_2 {
    char pad0[0x4];
    void * next;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    f32 unk_8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unk_C;
    char padC[0x10 - 0xC - sizeof(f32)];
    s32 unk_10;
};
struct MenuCode802A6AC0 {
    EntryItemMenuAdvanceSelection entries[4];
    char padE0[0xE4 - 0xE0];
    u16 cursor;
};
struct State802A6FE0 {
    u8 pad0[8];
    Node802A697C *node;
    u8 padC[0x10];
    void *object;
    u8 pad20[4];
    f32 value;
    u8 pad28[0x14];
    u32 flags;
};
struct CallbackState1C {
    unsigned char padding_0[24];
    void (*callback)(void *);
};
extern void Fx_AccumulateEffectComponents(ObjRecAt3CV1 *arg0);
extern void Fx_AddTimedCallback(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern void Fx_ClampScalarRange(f32 *arg0);
#endif
