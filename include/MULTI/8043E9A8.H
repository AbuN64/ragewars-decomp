#ifndef MULTI_8043E9A8_H
#define MULTI_8043E9A8_H
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/ITEMRECAT20V1.H"

struct HolderMultiIsPlayerItemAvailable {
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
extern s32 Initial_RequestTransitionWithPakDisabled(void *arg0, Outer8043E56C *arg1);
extern s32 Initial_OpenDialogAfterTimerReset(void *arg0, Arg1Struct *arg1);
extern void Initial_ProbeMenuControllerPak(struct Shared_PakMenu *arg0);
extern s32 Initial_OpenDialogWithControllerPak(void *arg0, Obj8043EB20 *arg1);
extern void Initial_EnableMenuControllerPak(void *arg0);

extern s32 func_8043ED48_de(void);
extern void Initial_SelectInitialController(void *arg0, struct ObjRecAt20V2 *menu);
extern s32 Initial_RequestSessionTransition(void);
#endif
