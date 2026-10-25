#ifndef COMMON_FIELD_VEC_B0_H
#define COMMON_FIELD_VEC_B0_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"






struct s_CTargetInfo;
typedef struct s_CTargetInfo CTargetInfo;




extern float D_800C21DC_de;

struct Actor_func_80214DD4_de;
typedef struct Actor_func_80214DD4_de Actor_func_80214DD4_de;



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



extern float D_800C21C8_de;




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



struct Func802172C4Value;
struct Func802172C4Value {
    int words[2];
};

struct Source_func_802164A8_de;
typedef struct Source_func_802164A8_de Source_func_802164A8_de;




struct Location;
struct Location {
    CVector3 pos;
    s32 room;
    f32 heading; /* 0x10 */
    u16 flags; /* 0x14 */
};





extern void func_802172C4_de(void *arg0, void *arg1, Func802172C4Value arg2);


struct Tracker;
typedef struct Tracker Tracker;




extern float D_800C21CC_de;



struct Cursor802171C8;
typedef struct Cursor802171C8 Cursor802171C8;

struct Cursor802171C8;
struct Cursor802171C8 {
    void *base;
    u16 *cur;
};

extern s16 func_802171C8_de(Cursor802171C8 *arg0);



extern float D_800C21E4_de;

struct Location;
typedef struct Location Location;

struct LevelActor;
struct RouteChaseBot;




struct CTeamSelectTeam_t;
typedef struct CTeamSelectTeam_t CTeamSelectTeam;


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




struct ObjectLinks1230;
typedef struct ObjectLinks1230 ObjectLinks1230;

struct OffsetResult;
typedef struct OffsetResult OffsetResult;



#endif
