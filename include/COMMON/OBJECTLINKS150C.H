#ifndef COMMON_OBJECTLINKS150C_H
#define COMMON_OBJECTLINKS150C_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"

struct ObjectLinks150C;
typedef struct ObjectLinks150C ObjectLinks150C;

struct IntegerState1504;

struct IntegerState1504;
typedef struct IntegerState1504 IntegerState1504;

struct ObjectRecAtBC;
struct ObjectRecAtBC {
    f32 falloff;
    f32 value;
    CVector3 direction; /* 0x08 */
    CVector3 axis; /* 0x14 */
    f32 inverse[16]; /* 0x20: world to volume, func_8026EF58_de(inverse, transform) */
    f32 transform[16]; /* 0x60: volume to world */
    Box bounds; /* 0xA0: func_80275954_de over the 8 corners */
    u8 flagB8;
    u8 flagB9;
    u8 animatedLight; /* 0xBA: func_80278890_de */
    u8 shape; /* 0xBB */
    u8 animationSeed; /* 0xBC */
    u8 fieldBD; /* 0xBD: Lighting_DecodeBoxTransform */
};
/* A world sector's light volumes: section 2 of its model pack. */
typedef struct LightVolumeList {
    s32 stride;
    s32 count;
    struct ObjectRecAtBC volumes[1];
} LightVolumeList;

struct ObjectRecAt8;

struct ObjRecAt6V2;


struct ObjectLinks150C;


struct FloatState64;
typedef struct FloatState64 FloatState64;

struct Record14;
typedef struct Record14 Record14;

struct Record14;
struct Record14 {
    u32 coordinates[3];
    u16 lifetime;
    u8 flags;
    u8 kind;
    u8 state;
    u8 active;
    u8 mode;
    u8 reserved13;
};

struct ObjectState104;

struct func_80278EEC_S1;
typedef struct func_80278EEC_S1 func_80278EEC_S1;

struct ObjectState104;
typedef struct ObjectState104 ObjectState104;

struct ObjRecAt6V2;
typedef struct ObjRecAt6V2 ObjRecAt6V2;


struct FloatState64;

struct func_80278EEC_S1;

struct Trigger;

struct ObjectRecAt8;
typedef struct ObjectRecAt8 ObjectRecAt8;


struct LevelActor;




struct ObjectRecAtBC;
typedef struct ObjectRecAtBC ObjectRecAtBC;


struct WorldRecAt1B40C;
extern s32 Scene_QueueTriggerTimer(struct WorldRecAt1B40C *arg0, Record14 *arg1);
#endif
