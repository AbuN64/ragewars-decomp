struct SharedPlayer;
#ifndef UNBAKE_SPAN_1000_CODE_8022D944_H
#define UNBAKE_SPAN_1000_CODE_8022D944_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct func_8022E42C_S1;
struct func_8022E42C_S1 {
    char pad0[0x8];
    func_8020E674_S1_U8 unk8;
    char pad14[0x70 - 0x14];
    f32 unk70;
};

extern f32 func_8022DBC4_de(f32 arg0);

struct Shared_ActorView;
extern s32 func_8022DC1C_de(struct Shared_ActorView *arg0);

struct func_8022E578_S2;
struct func_8022E578_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x5DC - 0x8 - sizeof(f32)];
    s32 unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(s32)];
    void * unk16E0;
};

struct Shape_typemap_14;
struct Shape_typemap_14 {
    unsigned char padding_0[8];
    short field_8;
};

struct Marker;
typedef struct Marker Marker;

struct func_8022E3B4_S2;
typedef struct func_8022E3B4_S2 func_8022E3B4_S2;

extern void func_8022E0B0_de(void *arg0, void *arg1);

struct Entry_func_8022E130_de;
struct Entry_func_8022E130_de {
    char pad[0x52];
    u16 flags;
};

struct func_8022D960_S1;
typedef struct func_8022D960_S1 func_8022D960_S1;

struct func_8022E694_S2;
struct func_8022E694_S2 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x20 - 0xC - sizeof(f32)];
    s32 unk20;
};

struct Object126;
typedef struct Object126 Object126;

struct func_8022DBF0_S1;
typedef struct func_8022DBF0_S1 func_8022DBF0_S1;

struct func_8022DC34_S2;
struct func_8022DC34_S2 {
    char pad0[0x650];
    s16 unk650;
    char pad650[0x718 - 0x650 - sizeof(s16)];
    f32 unk718;
    char pad718[0x71C - 0x718 - sizeof(f32)];
    s32 unk71C;
};

extern int func_8022E694_de(struct SharedPlayer *arg0);

extern float func_8022E588_de(void * arg0, float * arg1);

struct ObjRecAt724;
typedef struct ObjRecAt724 ObjRecAt724;

extern float D_800C2E0C_de;

extern void func_8022DC14_de(void);

struct func_8022E280_S1;
typedef struct func_8022E280_S1 func_8022E280_S1;

extern float D_800C7EF8;

extern u8 func_8022E758_de(s32 arg0, s32 arg1);

struct Actor126;
typedef struct Actor126 Actor126;

extern float D_800C7EC0;

struct func_8022D960_S3;
struct func_8022D960_S3 {
    char pad0[0x34];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
};

struct func_8022E694_S2;
typedef struct func_8022E694_S2 func_8022E694_S2;

extern void func_8022D954_de(void);

extern float D_801370C4;

struct ObjRecAt1AV1;
typedef struct ObjRecAt1AV1 ObjRecAt1AV1;

extern void func_8022DA84_de(void *arg0);

extern float D_800C7F10;

struct ObjRecAt724;
struct ObjRecAt724 {
    char pad0[0x650];
    s16 unk650;
    char pad650[0x724 - 0x650 - sizeof(s16)];
    f32 unk724;
};

struct func_8022E694_S3;
typedef struct func_8022E694_S3 func_8022E694_S3;

struct func_8022E3B4_S2;
struct func_8022E3B4_S2 {
    char pad0[0x20];
    void * unk20;
    char pad20[0x2C - 0x20 - sizeof(void*)];
    void * unk2C;
};

struct Player;
extern void func_8022DC00_de(struct Player *arg0);

struct func_8022E280_S1;
struct func_8022E280_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x5D4 - 0x8 - sizeof(Vec3)];
    s32 unk5D4;
    char pad5D4[0x6C0 - 0x5D4 - sizeof(s32)];
    s32 unk6C0;
    char pad6C0[0x6C4 - 0x6C0 - sizeof(s32)];
    s32 unk6C4;
    char pad6C4[0x6C8 - 0x6C4 - sizeof(s32)];
    s32 unk6C8;
    char pad6C8[0x6CC - 0x6C8 - sizeof(s32)];
    s32 unk6CC;
    char pad6CC[0x6D0 - 0x6CC - sizeof(s32)];
    s32 unk6D0;
    char pad6D0[0x6D4 - 0x6D0 - sizeof(s32)];
    s32 unk6D4;
    char pad6D4[0x6D8 - 0x6D4 - sizeof(s32)];
    s32 unk6D8;
    char pad6D8[0x6DC - 0x6D8 - sizeof(s32)];
    s32 unk6DC;
    char pad6DC[0x6E4 - 0x6DC - sizeof(s32)];
    s32 unk6E4;
    char pad6E4[0x6E8 - 0x6E4 - sizeof(s32)];
    Vec3 unk6E8;
    char pad6E8[0x6F8 - 0x6E8 - sizeof(Vec3)];
    Vec3 unk6F8;
    char pad6F8[0x708 - 0x6F8 - sizeof(Vec3)];
    s32 unk708;
    char pad708[0x70C - 0x708 - sizeof(s32)];
    s32 unk70C;
    char pad70C[0x710 - 0x70C - sizeof(s32)];
    s32 unk710;
    char pad710[0x714 - 0x710 - sizeof(s32)];
    s32 unk714;
    char pad714[0x724 - 0x714 - sizeof(s32)];
    s32 unk724;
    char pad724[0x728 - 0x724 - sizeof(s32)];
    s32 unk728;
    char pad728[0x72C - 0x728 - sizeof(s32)];
    s32 unk72C;
    char pad72C[0x730 - 0x72C - sizeof(s32)];
    s32 unk730;
    char pad730[0x734 - 0x730 - sizeof(s32)];
    s32 unk734;
    char pad734[0x738 - 0x734 - sizeof(s32)];
    s32 unk738;
    char pad738[0x73C - 0x738 - sizeof(s32)];
    s32 unk73C;
    char pad73C[0x740 - 0x73C - sizeof(s32)];
    f32 unk740;
    char pad740[0x744 - 0x740 - sizeof(f32)];
    func_8022E280_S1_U744 unk744;
    char pad744[0x748 - 0x744 - sizeof(func_8022E280_S1_U744)];
    Vec3 unk748;
    char pad748[0x754 - 0x748 - sizeof(Vec3)];
    f32 unk754;
    char pad754[0x758 - 0x754 - sizeof(f32)];
    s32 unk758;
    char pad758[0x75C - 0x758 - sizeof(s32)];
    s32 unk75C;
    char pad75C[0x780 - 0x75C - sizeof(s32)];
    f32 unk780;
    char pad780[0x784 - 0x780 - sizeof(f32)];
    f32 unk784;
    char pad784[0x11B4 - 0x784 - sizeof(f32)];
    s32 unk11B4;
    char pad11B4[0x11B8 - 0x11B4 - sizeof(s32)];
    s32 unk11B8;
    char pad11B8[0x1450 - 0x11B8 - sizeof(s32)];
    s32 unk1450;
};

struct ObjRecAt1AV1;
struct ObjRecAt1AV1 {
    char pad0[0x18];
    s8 unk18;
    char pad18[0x19 - 0x18 - sizeof(s8)];
    s8 unk19;
    char pad19[0x1A - 0x19 - sizeof(s8)];
    s8 unk1A;
};

struct ObjRecAt1CV2;
struct ObjRecAt1CV2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    void * unk8;
    char pad8[0x1C - 0x8 - sizeof(void*)];
    void * unk1C;
};

extern float D_800C2DCC_de;

struct func_8022DC0C_S1;
typedef struct func_8022DC0C_S1 func_8022DC0C_S1;

struct func_8022DC34_S2;
typedef struct func_8022DC34_S2 func_8022DC34_S2;

struct func_8022DE48_S1;
typedef struct func_8022DE48_S1 func_8022DE48_S1;

struct func_8022DE48_S4;
struct func_8022DE48_S4 {
    char pad0[0xE8];
    f32 unkE8;
};

struct func_8022E42C_S1;
typedef struct func_8022E42C_S1 func_8022E42C_S1;

struct func_8022D960_S2;
typedef struct func_8022D960_S2 func_8022D960_S2;

struct func_8022D960_S3;
typedef struct func_8022D960_S3 func_8022D960_S3;

extern void func_8022E940_de(void);

extern float D_800C7EE0;

extern void func_8022DA04_de(void *arg0);

extern void func_8022DBE4_de(struct Player *arg0);

struct func_8022DD84_S1;
typedef struct func_8022DD84_S1 func_8022DD84_S1;

struct Marker;
struct Marker {
    char pad0[0xC];
    f32 scale;
    s16 x;
    s16 y;
    s16 z;
    s16 active;
};

struct Actor126;
struct Actor126 {
    u8 pad0[0x100];
    s32 flags;
    u8 pad104[0xD0];
    f32 value1D4;
    u8 pad1D8[0x47A];
    s16 state652;
    u8 pad654[0xD4];
    f32 offset728;
};

struct func_8022DE48_S1;
struct func_8022DE48_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x6EC - 0x18 - sizeof(void*)];
    f32 unk6EC;
    char pad6EC[0x6F4 - 0x6EC - sizeof(f32)];
    f32 unk6F4;
    char pad6F4[0x718 - 0x6F4 - sizeof(f32)];
    f32 unk718;
    char pad718[0x720 - 0x718 - sizeof(f32)];
    f32 unk720;
    char pad720[0x780 - 0x720 - sizeof(f32)];
    f32 unk780;
};

struct ObjectLinks87C;
typedef struct ObjectLinks87C ObjectLinks87C;

struct func_8022DBD4_S1;
typedef struct func_8022DBD4_S1 func_8022DBD4_S1;

extern float D_800C2E00_de;

struct ObjectLinks87C;
struct ObjectLinks87C {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x5E4 - 0x5D8 - sizeof(char*)];
    s32 unk_5E4;
    char pad5E4[0x62E - 0x5E4 - sizeof(s32)];
    s16 unk_62E;
    char pad62E[0x7E8 - 0x62E - sizeof(s16)];
    s32 unk_7E8;
    char pad7E8[0x7EC - 0x7E8 - sizeof(s32)];
    f32 unk_7EC;
    char pad7EC[0x7F0 - 0x7EC - sizeof(f32)];
    f32 unk_7F0;
    char pad7F0[0x878 - 0x7F0 - sizeof(f32)];
    char unk_878;
};

struct func_8022E694_S3;
struct func_8022E694_S3 {
    char pad0[0x5EC];
    s32 unk5EC;
    char pad5EC[0x6F8 - 0x5EC - sizeof(s32)];
    Triple unk6F8;
};

struct func_8022DD84_S1;
struct func_8022DD84_S1 {
    char pad0[0x650];
    u16 unk650;
    char pad650[0x720 - 0x650 - sizeof(u16)];
    f32 unk720;
};

struct func_8022D960_S1;
struct func_8022D960_S1 {
    char pad0[0x7F4];
    s32 unk7F4;
    char pad7F4[0x7F8 - 0x7F4 - sizeof(s32)];
    f32 unk7F8;
    char pad7F8[0x7FC - 0x7F8 - sizeof(f32)];
    s32 unk7FC;
    char pad7FC[0x800 - 0x7FC - sizeof(s32)];
    func_8020E674_S1_U8 unk800;
};

extern float D_800C2DC8_de;

extern s32 func_8022E640_de(struct SharedPlayer *arg0);

extern void func_8022E260_de(void * arg0, int arg1, int arg2);

struct Object126;
struct Object126 {
    u8 pad0[0x1C];
    f32 x;
    u8 pad20[4];
    f32 y;
    u8 pad28[0x44];
    f32 angle;
};

extern void func_8022DB04_de(Actor126 *actor, Object126 *arg1);

struct func_8022D960_S2;
struct func_8022D960_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
};

struct func_8022E578_S2;
typedef struct func_8022E578_S2 func_8022E578_S2;

struct func_8022DC0C_S1;
struct func_8022DC0C_S1 {
    char pad0[0x718];
    f32 unk718;
};

struct func_80204468_S3;
extern s32 func_8022E130_de(struct func_80204468_S3 *object);

extern float D_800C7EC8;

struct func_8022DE48_S4;
typedef struct func_8022DE48_S4 func_8022DE48_S4;

struct func_8022DBD4_S1;
struct func_8022DBD4_S1 {
    char pad0[0x708];
    float unk708;
    char pad708[0x70C - 0x708 - sizeof(float)];
    float unk70C;
    char pad70C[0x710 - 0x70C - sizeof(float)];
    float unk710;
    char pad710[0x714 - 0x710 - sizeof(float)];
    int unk714;
};

extern void func_8022E890_de(void *unused0, s32 *arg1);

struct func_8022DBF0_S1;
struct func_8022DBF0_S1 {
    char pad0[0x708];
    float unk708;
    char pad708[0x70C - 0x708 - sizeof(float)];
    float unk70C;
    char pad70C[0x710 - 0x70C - sizeof(float)];
    int unk710;
    char pad710[0x714 - 0x710 - sizeof(int)];
    int unk714;
};

struct func_8022D9F4_S1;
typedef struct func_8022D9F4_S1 func_8022D9F4_S1;

extern s32 func_8022E5EC_de(struct SharedPlayer *arg0);

struct ObjRecAt1CV2;
typedef struct ObjRecAt1CV2 ObjRecAt1CV2;

extern void func_8022DD94_de(struct Shared_ActorView *arg0);

extern float D_800C7EF4;

struct func_8022D9F4_S1;
struct func_8022D9F4_S1 {
    char pad0[0x11B4];
    s32 unk11B4;
};

extern void func_8022DFA8_de(void *arg0);

#endif
