#ifndef MULTI_8043E9A8_H
#define MULTI_8043E9A8_H
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Holder_func_8043F048_de {
    char pad[0x1C];
    struct PlayerRecAt64E *player;
    char pad20[0x30 - 0x20];
    f32 fade;
    f32 alpha;
};
struct Obj8043ECE8 {
    s16 unk0;
    u8 pad2[10];
    struct Flagged *unkC;
};
struct ItemRecAt18V2 {
    char pad[0x14];
    s32 resource;
    struct ItemDef *def;
};
struct Obj8043EB20 {
    u8 pad0[0x1C];
    s32 unk1C;
    Inner8043E56C *unk20;
};
struct MenuRecAt14 {
    char pad[0x14];
    struct Variable *unk14;
};
extern s32 func_8043EA4C_de(void *arg0, Outer8043E56C *arg1);
extern s32 func_8043EA00_de(void *arg0, Arg1Struct *arg1);
extern void func_8043E948_de(struct Shared_PakMenu *arg0);
extern s32 func_8043E9A8_de(void *arg0, Obj8043EB20 *arg1);
extern void func_8043E97C_de(void *arg0);
#endif
