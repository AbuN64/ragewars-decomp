#ifndef FRONTEND_8041BEA8_6_H
#define FRONTEND_8041BEA8_6_H
#include "COMMON/LABEL.H"
extern void func_8041CDDC_de(ObjRecAt48C *arg0, CVector3 v);
extern void func_8041CE18_de(Unk8041CE88 *arg0);
extern void func_8041C610_de(struct Unk8041CE88 * arg0);
extern void func_8041CE08_de(ObjRecAt498 *arg0, s32 arg1);
extern void func_8041CDB0_de(ObjRecAt480 *arg0, CVector3 v);
typedef struct Obj8041CAD8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s32 unk10;
    char pad14[0x18 - 0x14];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    char pad24[0x1E0 - 0x24];
    s32 unk1E0;
    s32 unk1E4;
    s32 unk1E8;
    char pad1EC[0x274 - 0x1EC];
    s16 unk274;
    char pad276[0x478 - 0x276];
    s32 unk478;
    char pad47C[0x480 - 0x47C];
    CVector3 unk480;
    CVector3 unk48C;
    f32 unk498;
    s32 unk49C;
    s32 unk4A0;
} Obj8041CAD8;
extern void func_8041CAD8_de(Obj8041CAD8 *, s32, s32, s32, s32, CVector3, CVector3, f32, s32);
#endif
