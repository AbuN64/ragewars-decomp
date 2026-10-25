#ifndef COMMON_FIELD_VEC_B0_H
#define COMMON_FIELD_VEC_B0_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Field_Vec_B0;
typedef struct Field_Vec_B0 Field_Vec_B0;

struct Field_void_68;
struct Field_void_68 {
    char pad[0x68];
    void * value;
};

struct func_802169AC_S4;
typedef struct func_802169AC_S4 func_802169AC_S4;

struct func_80216F44_S1;
typedef struct func_80216F44_S1 func_80216F44_S1;

struct Field_s32_788;
typedef struct Field_s32_788 Field_s32_788;

struct func_802169AC_S3;
typedef struct func_802169AC_S3 func_802169AC_S3;

struct s_CTargetInfo;
typedef struct s_CTargetInfo CTargetInfo;

struct func_80216F44_S1;
struct func_80216F44_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x6C - 0x10 - sizeof(f32)];
    f32 unk6C;
};

struct func_802172D0_S3;
struct func_802172D0_S3 {
    char pad0[0x8];
    char unk8;
    char pad8[0xD0 - 0x8 - sizeof(char)];
    void * unkD0;
};

struct func_802169AC_S4;
struct func_802169AC_S4 {
    char pad0[0xE4];
    u16 unkE4;
    char padE4[0x2E0 - 0xE4 - sizeof(u16)];
    s32 unk2E0;
};

extern float D_800C21DC_de;

struct Actor_func_80214DD4_de;
typedef struct Actor_func_80214DD4_de Actor_func_80214DD4_de;


struct AudioStateA4;
struct AudioStateA4 {
    char pad0[0x98];
    s32 field98;
    char pad9C[4];
    s32 fieldA0;
};

struct Source_func_802164A8_de;
struct Source_func_802164A8_de {
    char pad0[8];
    Triple position;
    char pad14[4];
    s32 *kind;
    char pad1c[0x50];
    f32 height;
    char pad70[0x90];
    s32 flags;
    char pad104[0x98];
    s32 active;
};

struct CActor_t;
typedef struct CActor_t CActor_t;

struct Actor_func_80214DD4_de;
struct s_CTargetInfo;
struct s_CTargetInfo {
    s32 kind;
    struct Actor_func_80214DD4_de *target;
    f32 m_DeltaAngle;
    CVector3 m_vTargetPos;
    CVector3 m_vDeltaTargetPos;
    f32 m_DistFrom;
    CVector3 m_vXZTargetPos;
    CVector3 m_vXZDeltaTargetPos;
    f32 m_XZDistFrom;
};

struct Field_Vec_34;
struct Field_Vec_34 {
    char pad[0x34];
    CVector3 value;
};

struct Field_f32_9C;
struct Field_f32_9C {
    char pad[0x9C];
    f32 value;
};

struct Field_void_68;
typedef struct Field_void_68 Field_void_68;

struct Field_Vec_C;
typedef struct Field_Vec_C Field_Vec_C;

struct Field_f32_24;
typedef struct Field_f32_24 Field_f32_24;

struct AudioStateA4;
typedef struct AudioStateA4 AudioStateA4;

struct OffsetResult;
struct OffsetResult {
    CVector3 first;
    CVector3 first_normalized;
    f32 first_length;
    CVector3 flat;
    CVector3 flat_normalized;
    f32 flat_length;
    f32 height;
};

struct Func802172C4Value;
typedef struct Func802172C4Value Func802172C4Value;


struct ObjectLinks1230;
struct ObjectLinks1230 {
    char pad0[0x100];
    u32 unk_100;
    char pad100[0x5D8 - 0x100 - sizeof(u32)];
    char * unk_5D8;
    char pad5D8[0x122C - 0x5D8 - sizeof(char*)];
    u32 unk_122C;
};

struct CTeamSelectTeam_t;
struct CTeamSelectTeam_t {
    s32 unk0;
    s32 unk4;
    f32 x;
    f32 y;
    f32 z;
};

struct Field_Vec_34;
typedef struct Field_Vec_34 Field_Vec_34;

struct func_802169AC_S1;
struct func_802169AC_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x68 - 0x4 - sizeof(s32)];
    void * unk68;
    char pad68[0x94 - 0x68 - sizeof(void*)];
    s8 unk94;
};

extern float D_800C21C8_de;

struct func_80216A6C_S1;
typedef struct func_80216A6C_S1 func_80216A6C_S1;

struct Field_Vec_0;
struct Field_Vec_0 {
    CVector3 value;
};


struct Dest_func_802164A8_de;
typedef struct Dest_func_802164A8_de Dest_func_802164A8_de;

struct CActor_t;
struct CActor_t {
    u8 type;
    u8 pad001[0x1B];
    CVector3 position;
    u8 pad028[0xBC];
    u16 objectId;
    u8 pad0E6[0x10A];
    s32 eventValue;
    u8 pad1F4[0xA8];
    s32 eventCount;
};


struct Field_f32_24;
struct Field_f32_24 {
    char pad[0x24];
    f32 value;
};

struct Func802172C4Value;
struct Func802172C4Value {
    int words[2];
};

struct Source_func_802164A8_de;
typedef struct Source_func_802164A8_de Source_func_802164A8_de;

struct func_80216D3C_S2;
struct func_80216D3C_S2 {
    char pad0[0x44];
    Output80216D3C unk44;
};

struct Field_f32_9C;
typedef struct Field_f32_9C Field_f32_9C;

struct RecCode80213ED4;
typedef struct RecCode80213ED4 RecCode80213ED4;

struct Location;
struct Location {
    CVector3 pos;
    s32 room;
    f32 heading; /* 0x10 */
    u16 flags; /* 0x14 */
};

struct func_80216D3C_S2;
typedef struct func_80216D3C_S2 func_80216D3C_S2;

struct func_80216D30_S1;
struct func_80216D30_S1 {
    char pad0[0x78];
    int unk78;
    char pad78[0x7C - 0x78 - sizeof(int)];
    int unk7C;
};

struct func_802169AC_S3;
struct func_802169AC_S3 {
    char pad0[0x788];
    s32 unk788;
    char pad788[0x794 - 0x788 - sizeof(s32)];
    void * unk794;
};

struct Field_Vec_28;
typedef struct Field_Vec_28 Field_Vec_28;

extern void func_802172C4_de(void *arg0, void *arg1, Func802172C4Value arg2);

struct Field_s32_788;
struct Field_s32_788 {
    char pad[0x788];
    s32 value;
};

struct Tracker;
typedef struct Tracker Tracker;

struct func_80216D30_S1;
typedef struct func_80216D30_S1 func_80216D30_S1;

struct Field_Vec_28;
struct Field_Vec_28 {
    char pad[0x28];
    CVector3 value;
};

struct Field_void_794;
typedef struct Field_void_794 Field_void_794;

extern float D_800C21CC_de;

struct Field_void_88;
struct Field_void_88 {
    char pad[0x88];
    void * value;
};

struct func_802172D0_S1;
struct func_802172D0_S1 {
    char pad0[0xFC];
    void * unkFC;
};

struct Cursor802171C8;
typedef struct Cursor802171C8 Cursor802171C8;

struct Cursor802171C8;
struct Cursor802171C8 {
    void *base;
    u16 *cur;
};

extern s16 func_802171C8_de(Cursor802171C8 *arg0);


struct func_802169AC_S1;
typedef struct func_802169AC_S1 func_802169AC_S1;

extern float D_800C21E4_de;

struct Location;
typedef struct Location Location;

struct LevelActor;
struct RouteChaseBot;

struct func_802172D0_S1;
typedef struct func_802172D0_S1 func_802172D0_S1;

struct Field_Vec_B0;
struct Field_Vec_B0 {
    char pad[0xB0];
    CVector3 value;
};

struct func_802169AC_S2;
typedef struct func_802169AC_S2 func_802169AC_S2;

struct CTeamSelectTeam_t;
typedef struct CTeamSelectTeam_t CTeamSelectTeam;

struct func_80216A6C_S1;
struct func_80216A6C_S1 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x70 - 0xC - sizeof(f32)];
    f32 unk70;
};

struct Actor_func_80214DD4_de;
struct Tracker;
struct Tracker {
    s32 flags;
    s32 active;
    u8 pad8[0x2C];
    s8 mode; /* 0x34 */
    u8 pad35[2];
    s8 unk37;
    u8 pad38[0x30];
    struct Actor_func_80214DD4_de *self;
    CVector3 offset;
    struct Actor_func_80214DD4_de *lockedTarget; /* 0x78 */
    f32 targetTimer; /* 0x7C */
    struct Actor_func_80214DD4_de *anchor;
    u8 pad84[4];
    struct Actor_func_80214DD4_de *target;
    f32 angle;
    f32 height;
    s8 slot;
    u8 pad95[7];
    f32 homeYaw; /* 0x9C */
    u8 padA0[0x10];
    CVector3 homePos;
    s32 homeRoom;
    u8 padC0[0xE];
    s8 team;
};



struct Field_void_88;
typedef struct Field_void_88 Field_void_88;


struct Field_void_794;
struct Field_void_794 {
    char pad[0x794];
    void * value;
};

struct RecCode80213ED4;
struct RecCode80213ED4 {
    char pad0[0x48];
    CVector3 unk48;
    char pad48[0x60 - 0x48 - sizeof(CVector3)];
    f32 unk60;
};

struct Field_s8_94;
struct Field_s8_94 {
    char pad[0x94];
    s8 value;
};

struct Field_s8_94;
typedef struct Field_s8_94 Field_s8_94;

struct func_80216D3C_S1;
typedef struct func_80216D3C_S1 func_80216D3C_S1;

struct func_802172D0_S3;
typedef struct func_802172D0_S3 func_802172D0_S3;

struct Dest_func_802164A8_de;
struct Dest_func_802164A8_de {
    char pad0[0x40];
    f32 value;
    char pad44[4];
    Triple old_position;
    Triple position;
    f32 height;
    char pad64[0x69];
    u8 timer;
    char padce[0x2E];
    func_80205628_S3 *aux;
    char pad100[8];
    void (*callback)(Source_func_802164A8_de *, struct Dest_func_802164A8_de *);
};

struct Field_s8_CE;
struct Field_s8_CE {
    char pad[0xCE];
    s8 value;
};

struct func_802169AC_S2;
struct func_802169AC_S2 {
    char pad0[0x18];
    s32 * unk18;
    char pad18[0xE4 - 0x18 - sizeof(s32*)];
    u16 unkE4;
    char padE4[0x100 - 0xE4 - sizeof(u16)];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    void * unk1D8;
};

struct Field_Vec_C;
struct Field_Vec_C {
    char pad[0xC];
    CVector3 value;
};

struct ObjectLinks1230;
typedef struct ObjectLinks1230 ObjectLinks1230;

struct OffsetResult;
typedef struct OffsetResult OffsetResult;

struct Field_Vec_0;
typedef struct Field_Vec_0 Field_Vec_0;

struct Field_s8_CE;
typedef struct Field_s8_CE Field_s8_CE;

struct func_80216D3C_S1;
struct func_80216D3C_S1 {
    char pad0[0x78];
    struct Actor_func_80214DD4_de *lockedTarget; /* 0x78 */
    char pad78[0x7C - 0x78 - sizeof(s32)];
    f32 unk7C;
    char pad7C[0x80 - 0x7C - sizeof(f32)];
    s32 unk80;
    char pad80[0x88 - 0x80 - sizeof(s32)];
    s32 unk88;
};
#endif
