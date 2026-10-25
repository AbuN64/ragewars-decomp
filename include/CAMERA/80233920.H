#ifndef CAMERA_80233920_H
#define CAMERA_80233920_H
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/SHAREDPLAYER.H"
/* XYZ minimum and maximum bounds, copied as a single record. */
typedef struct ViewFlags { s32 flags; } ViewFlags;
struct ObjRecAt260 {
    char pad0[0x260];
    struct Triple unk260;
};
/* Color keyframe payload in a 0x64-byte model-section record. */
typedef struct ColorBlendRecord {
    u8 color[4];
    u8 heldColor[4];
    u32 n, heldN;
    f32 a, b, heldA, heldB;
    u8 unknown20[4];
    f32 period;
    u8 unknown28[0x64 - 0x28];
} ColorBlendRecord;
struct Overlay {
    char pad0[0x538];
    f32 timer;
    char pad53C[8];
    u32 state;
    char pad548[2];
    u8 alphaMax;
    u8 fadeIn;
    u8 hold;
    u8 fadeOut;
    char pad54E[3];
    u8 alpha;
};
struct ObjRecAtE4V1 {
    char pad0[0xA8];
    CVector3 unkA8;
    char padA8[0xB4 - 0xA8 - sizeof(CVector3)];
    f32 unkB4;
    char padB4[0xB8 - 0xB4 - sizeof(f32)];
    s32 unkB8;
    char padB8[0xBC - 0xB8 - sizeof(s32)];
    f32 unkBC;
    char padBC[0xCC - 0xBC - sizeof(f32)];
    s32 unkCC;
    char padCC[0xD0 - 0xCC - sizeof(s32)];
    f32 unkD0;
    char padD0[0xE0 - 0xD0 - sizeof(f32)];
    s32 unkE0;
    char padE0[0xE4 - 0xE0 - sizeof(s32)];
    f32 unkE4;
};
struct State44 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    union {s32 i; f32 f;} unk_20;
    CVector3 v;
    f32 unk_30;
    s32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    s32 unk_40;
};
struct ThreeChannels {
    char pad0[0x520];
    u8 first;
    u8 second;
    u8 third;
};
typedef union Rotation { f32 f[4]; u32 word[4]; } Rotation;
typedef union TransformVector { CVector3 value; u32 word[3]; } TransformVector;
extern void func_80233B14_de(Overlay *overlay);
extern void func_80233930_de(CShake *arg0, CVector3 position, CVector3 *out);
#endif
