#ifndef COMMON_COLORENTRY_H
#define COMMON_COLORENTRY_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern float D_800C52F8_de;

struct func_8028D35C_S1;
struct func_8028D35C_S1 {
    char pad0[0x1C];
    s32 unk1C;
    char pad1C[0x4C - 0x1C - sizeof(s32)];
    s32 * unk4C;
    char pad4C[0x1B40C - 0x4C - sizeof(s32*)];
    s32 unk1B40C;
};

struct State_func_8028D67C_de;
typedef struct State_func_8028D67C_de State_func_8028D67C_de;

struct State_func_8028D67C_de;
struct State_func_8028D67C_de {
    char pad[0xB4C];
    s32 values[64];
    s32 unkC4C;
    char padc50[0x1A6CC];
    f32 unk1B31C;
};

struct func_8028D658_S1;
struct func_8028D658_S1 {
    char pad0[0x4];
    State_func_8028D67C_de unk4;
};

struct func_8028D7A0_S1;
typedef struct func_8028D7A0_S1 func_8028D7A0_S1;

struct ColorEntry;
struct ColorEntry {
    f32 value;
    u8 red;
    u8 green;
    u8 blue;
    u8 pad;
};

struct func_8028D628_S1;
struct func_8028D628_S1 {
    char pad0[0x944];
    int unk944;
    char pad944[0xB48 - 0x944 - sizeof(int)];
    int unkB48;
    char padB48[0xC4C - 0xB48 - sizeof(int)];
    int unkC4C;
    char padC4C[0xE50 - 0xC4C - sizeof(int)];
    int unkE50;
    char padE50[0xF54 - 0xE50 - sizeof(int)];
    int unkF54;
    char padF54[0xFDC - 0xF54 - sizeof(int)];
    int unkFDC;
    char padFDC[0x1020 - 0xFDC - sizeof(int)];
    int unk1020;
    char pad1020[0x10A4 - 0x1020 - sizeof(int)];
    int unk10A4;
    char pad10A4[0x10B8 - 0x10A4 - sizeof(int)];
    int unk10B8;
    char pad10B8[0x10BC - 0x10B8 - sizeof(int)];
    int unk10BC;
    char pad10BC[0x1504 - 0x10BC - sizeof(int)];
    int unk1504;
};




struct Object_func_8028CE94_de;
struct StridedTable;
struct Object_func_8028CE94_de {
    char pad[0xA8];
    struct StridedTable *unkA8;
    struct StridedTable *unkAC;
};

struct Object_func_8028CE94_de;
typedef struct Object_func_8028CE94_de Object_func_8028CE94_de;

struct Container;
typedef struct Container Container;

struct RecordRecAtE4;
typedef struct RecordRecAtE4 RecordRecAtE4;

struct Sub18;
struct Sub18 {
    s32 unk0;
    char pad4[8];
    s16 unkC;
};
struct RecordRecAtE4;
struct Sub18;
struct RecordRecAtE4 {
    char pad0[0x18];
    struct Sub18 *unk18;
    char pad1C[0xC8];
    u16 unkE4;
    char padE6[0x2E8 - 0xE6];
};

struct Container;
struct RecordRecAtE4;
struct Container {
    char pad0[0x138];
    struct RecordRecAtE4 *unk138;
    s32 unk13C;
    s32 unk140;
};


struct func_8028CD44_S1;
typedef struct func_8028CD44_S1 func_8028CD44_S1;

struct Owner_func_8028D888_de;
typedef struct Owner_func_8028D888_de Owner_func_8028D888_de;






struct func_8028D578_S1;
struct func_8028D578_S1 {
    char pad0[0x88];
    void * unk88;
    char pad88[0xF8 - 0x88 - sizeof(void*)];
    s32 unkF8;
};

struct ColorEntry;
typedef struct ColorEntry ColorEntry;

struct func_8028CE54_S1;
typedef struct func_8028CE54_S1 func_8028CE54_S1;

struct func_8028D628_S1;
typedef struct func_8028D628_S1 func_8028D628_S1;

struct func_8028D728_S2;
struct func_8028D728_S2 {
    char pad0[0x138];
    void * unk138;
    char pad138[0x140 - 0x138 - sizeof(void*)];
    u32 unk140;
};

struct ObjRecAt78V1;
struct ObjRecAt78V1 {
    char pad0[0x78];
    void * unk78;
};

struct ObjRecAt10BC;
typedef struct ObjRecAt10BC ObjRecAt10BC;

struct ObjRecAt10BC;
struct ObjRecAt10BC {
    char pad0[0x10BC];
    int unk10BC;
};

struct func_8028CE54_S1;
struct func_8028CE54_S1 {
    char pad0[0xA4];
    char * unkA4;
};

struct func_8028D35C_S1;
typedef struct func_8028D35C_S1 func_8028D35C_S1;

struct func_8028D268_S3;
typedef struct func_8028D268_S3 func_8028D268_S3;

struct func_8028D578_S1;
typedef struct func_8028D578_S1 func_8028D578_S1;

struct func_8028CD44_S1;
struct func_8028CD44_S1 {
    char pad0[0x138];
    s32 unk138;
    char pad138[0x140 - 0x138 - sizeof(s32)];
    s32 unk140;
};

struct ObjRecAt7C;
struct ObjRecAt7C {
    char pad0[0x7C];
    void * unk7C;
};

struct func_8028D7A0_S1;
struct func_8028D7A0_S1 {
    char pad0[0x11C0];
    s32 unk11C0;
    char pad11C0[0x11C4 - 0x11C0 - sizeof(s32)];
    s32 unk11C4;
    char pad11C4[0x11C8 - 0x11C4 - sizeof(s32)];
    s32 unk11C8;
    char pad11C8[0x11CC - 0x11C8 - sizeof(s32)];
    s32 unk11CC;
    char pad11CC[0x11D0 - 0x11CC - sizeof(s32)];
    s32 unk11D0;
    char pad11D0[0x11D4 - 0x11D0 - sizeof(s32)];
    s32 unk11D4;
};

struct ObjRecAt78V1;
typedef struct ObjRecAt78V1 ObjRecAt78V1;

struct func_8028D0E4_S1;
struct func_8028D0E4_S1 {
    char pad0[0x1B410];
    s32 unk1B410;
    char pad1B410[0x1B414 - 0x1B410 - sizeof(s32)];
    s32 unk1B414;
    char pad1B414[0x1B418 - 0x1B414 - sizeof(s32)];
    f32 unk1B418;
};

struct func_8028D268_S3;
struct func_8028D268_S3 {
    char pad0[0x38];
    char unk38;
};

extern float D_800C5300_de;

struct Owner_func_8028D888_de;
struct Owner_func_8028D888_de {
    char pad0[0x944];
    s32 unk944;
    char pad948[0xC4C - 0x948];
    s32 unkC4C;
    char padC50[0x10BC - 0xC50];
    s32 unk10BC;
    char pad10C0[0x1500 - 0x10C0];
    s32 prevCount;
    s32 count;
    Triple entries[1];
};

struct func_8028D728_S2;
typedef struct func_8028D728_S2 func_8028D728_S2;

struct func_8028D0E4_S1;
typedef struct func_8028D0E4_S1 func_8028D0E4_S1;

struct ObjRecAt7C;
typedef struct ObjRecAt7C ObjRecAt7C;

struct func_8028D658_S1;
typedef struct func_8028D658_S1 func_8028D658_S1;

/* Clip section 1 has a stride/count header and 0x38-byte pose records.
 * Position is used to select the nearest frame; the remaining pose data is
 * consumed by the animation routines reached through func_8028D244_de. */
typedef struct AnimationPoseFrame {
    CVector3 position;
    u8 poseData[0x38 - sizeof(CVector3)];
} AnimationPoseFrame;

typedef struct AnimationPoseFrameSet {
    s32 stride;
    s32 count;
    AnimationPoseFrame frames[1];
} AnimationPoseFrameSet;
#endif
