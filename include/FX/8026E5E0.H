#ifndef FX_8026E5E0_H
#define FX_8026E5E0_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
struct ObjRecAt4V7 {
    u32 unk0;
    u16 unk4;
    char pad4[0xE];
};
struct func_8026E5E0_S1 {
    char pad0[0xC];
    u32 unkC;
    u16 bone;
    u16 reserved;
};
struct AttachmentTable {
    s32 stride;
    u8 pad4[0x6A];
    u8 bytes[1];
};
struct func_8026E5E0_S3 {
    char pad0[0x18];
    s32 *unk18;
    char pad18[0x188];
    s8 unk1A4;
    char pad1A4[0xB];
    f32 unk1B0;
    char pad1B0[0x24];
    ObjRecAt650 *unk1D8;
    char pad1D8[0x6C];
    Triple unk248;
    Triple unk254;
    Triple unk260;
    char pad268[0x74];
    s32 unk2E0;
};
#endif
