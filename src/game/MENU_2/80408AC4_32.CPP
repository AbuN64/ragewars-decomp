#include "include_asm.h"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
typedef struct Func_8042D9F0_State {
    void *unk0;
    void *unk4;
    void *unk8;
    s32 unkC;
    char pad10[4];
    char unk14[0xC];
    s32 unk20;
} Func_8042D9F0_State;
typedef struct { char pad0[0x10]; u8 unk10; char pad11[0x27]; void *unk38; } Func_8042D9F0_Part;
extern Func_8042D9F0_State *D_800E5430;
extern char D_800E1B60[];
extern void *func_8025305C_de(s32 size);
extern void func_802A2360_de(void);
extern void *func_8041A280_de(s32 a, s32 b);
extern void func_8041A47C_de(void *p);
extern void func_8041B110_de(s32 a);
extern void *func_8040EC30_de(s32 owner, s32 id);
extern void *func_80419E54_de(s32 a, s32 b);
extern void func_802A0C08_de(void *a, void *b, s32 c);
/* Builds the 0x24-byte state D_800E5430 from the resources 0x392 to 0x397, hooks its list at 0x14 into the part func_8040EC30_de returns for 0x397 and registers it with func_802A0C08_de; returns zero. */
s32 func_8042D9F0_de(s32 arg0) {
    Func_8042D9F0_Part *part;
    D_800E5430 = (Func_8042D9F0_State *)func_8025305C_de(0x24);
    func_802A2360_de();
    D_800E5430->unk0 = func_8041A280_de(0x392, 0x393);
    func_8041A47C_de(D_800E5430->unk0);
    func_8041B110_de(0x396);
    part = (Func_8042D9F0_Part *)func_8040EC30_de(arg0, 0x394);
    D_800E5430->unk8 = part;
    part->unk10 = 0xF;
    D_800E5430->unk4 = func_80419E54_de(0x395, 0x6E);
    D_800E5430->unkC = 3;
    part = (Func_8042D9F0_Part *)func_8040EC30_de(arg0, 0x397);
    part->unk38 = D_800E5430->unk14;
    D_800E5430->unk20 = 1;
    func_802A0C08_de(D_800E5430->unk14, D_800E1B60, 1);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8042D9F0_de);
#endif
#endif
