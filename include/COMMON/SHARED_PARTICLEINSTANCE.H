#ifndef COMMON_SHARED_PARTICLEINSTANCE_H
#define COMMON_SHARED_PARTICLEINSTANCE_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
struct Actor_func_80281A9C_de;
typedef struct Actor_func_80281A9C_de Actor_func_80281A9C_de;

struct Shared_ParticleInstance;
struct Shared_ParticleInstance {
    char pad0[0x4];
    u16 type;
    char pad6[0x2];
    CVector3 pos;
    s32 unk14;
    char pad18[0x4];
    CVector3 velocity;
    char pad28[0x10];
    s32 unk38;
    char pad3C[0x14];
};

struct func_8027EB00_S2;
struct func_8027EB00_S2 {
    char pad0[0x8];
    char unk8;
    char pad8[0x110 - 0x8 - sizeof(char)];
    s32 unk110;
    s32 unk114;
    void *unk118;
};

struct Actor_func_8027B428_de;
typedef struct Actor_func_8027B428_de Actor_func_8027B428_de;

struct Actor_func_8027B428_de;
struct Shape_func_8021A2D4_de_2;
struct Actor_func_8027B428_de {
    char pad0[4];
    u16 type;
    char pad6[0x12];
    struct Shape_func_8021A2D4_de_2 *descriptor;
    char pad1C[0x110];
    func_8024E8F0_S1 *owner;
};

struct Parent;
typedef struct Parent Parent;


struct EntryRecAt4V4;
struct EntryRecAt4V4 {
    s16 kind;
    char pad[2];
    s16 id;
};


union func_80282E6C_S1_U8;
union func_80282E6C_S1_U8 {
    Triple v0;
    CVector3 v1;
};

union func_8027C5A0_S1_U118;
union func_8027C5A0_S1_U118 {
    void * v0;
    s32 * v1;
};

union func_8027C5A0_S1_U118;
typedef union func_8027C5A0_S1_U118 func_8027C5A0_S1_U118;

struct func_8027C5A0_S1;
struct func_8027C5A0_S1 {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    func_8027C5A0_S1_U118 unk118;
    char pad118[0x12C - 0x118 - sizeof(func_8027C5A0_S1_U118)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
};

struct func_8027D950_S1;
typedef struct func_8027D950_S1 func_8027D950_S1;

struct Shared_ParticleInstance;
typedef struct Shared_ParticleInstance Shared_ParticleInstance;

struct Shared_ParticleOwner;
typedef struct Shared_ParticleOwner Shared_ParticleOwner;

struct EntryRecAt4V4;
typedef struct EntryRecAt4V4 EntryRecAt4V4;

struct RecordRecAt2C;
struct RecordRecAt2C {
    char pad[0x20];
    EntryRecAt4V4 *first[3];
    EntryRecAt4V4 *second[3];
};

struct NodeCode8027A0F4;
typedef struct NodeCode8027A0F4 NodeCode8027A0F4;

struct func_8027EB00_S2;
typedef struct func_8027EB00_S2 func_8027EB00_S2;

extern int D_801042C4;

struct Actor_func_8027DAD0_de;
typedef struct Actor_func_8027DAD0_de Actor_func_8027DAD0_de;

struct ActorCode8027A0F4;
typedef struct ActorCode8027A0F4 ActorCode8027A0F4;

struct Shared_ParticleInstance;

struct Shared_ParticleInstance;

struct ActorDef;
struct ActorDef {
    s32 flags;
    char pad4[0x10];
    s32 large;
    char pad18[0xC];
    ObjRecAt18V3 *size;
};
struct ActorDef;
struct ActorCode8027A0F4;
struct ActorCode8027A0F4 {
    Shared_ParticleInstance instance;
    char pad50[0xC8];
    struct ActorDef *def;
    char pad11C[0x24];
    f32 damage;
    char pad144[8];
    s16 health;
    char pad14E[0xA];
    f32 radius;
};

struct Shared_Particle;

struct Shared_ParticleTarget;
struct Shared_ParticleTarget {
    u8 kind;
    char reserved1[0x17];
    s32 *category;
    char reserved1C[0x98];
    struct UnitMtx *drawMatrices;
    struct UnitMtx *bones;
    char padBC[0x44];
    s32 flags;
    char pad104[0x6C];
    s32 unk170;
    s32 unk174;
    char pad178[0x2C];
    s8 unk1A4;
    char reserved1A5[0xE3];
    void (*callback)(struct Shared_ParticleTarget *, s32 *, void *);
    char reserved28C[0x1158];
    s32 extraUses;
};

struct func_80282E6C_Table;
struct func_80282E6C_Table {
    char pad[0xA8];
    u16 unkA8;
};

extern float D_800C4E60_de;

struct Object_func_80281A9C_de;
typedef struct Object_func_80281A9C_de Object_func_80281A9C_de;

struct Object_func_80281A9C_de;
struct Object_func_80281A9C_de {
    char pad0[8];
    CVector3 position;
    char pad14[0x160];
    s32 count;
};

struct World_func_80281A9C_de;
struct World_func_80281A9C_de {
    char pad0[0xE54];
    Object_func_80281A9C_de *objects[64];
    s32 objectCount;
};

struct Shared_Particle;
typedef struct Shared_Particle Shared_Particle;

struct func_8027C324_S1;
typedef struct func_8027C324_S1 func_8027C324_S1;

union func_8027C324_S1_U118;
union func_8027C324_S1_U118 {
    s32 * v0;
    void * v1;
};

struct func_80282E6C_S1;
typedef struct func_80282E6C_S1 func_80282E6C_S1;

struct Ground;
struct Ground {
    s32 found;
    char pad4[8];
    f32 height;
    char pad10[0xE0];
    CVector3 normal;
};

extern int D_8010029C;

struct func_80282E6C_Table;
typedef struct func_80282E6C_Table func_80282E6C_Table;

struct func_8027D950_S1;
struct func_8027D950_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    s32 unk10;
    char pad10[0x1D0 - 0x10 - sizeof(s32)];
    func_80209DAC_S2_U93 unk1D0;
};

struct Parent;
struct Parent {
    char pad0[8];
    CVector3 position;
    char pad14[0x60];
    f32 transform[16];
    void *skeleton;
    char padB8[0x48];
    s32 flags;
    char pad104[0xD4];
    func_80228774_S5 *model;
};

struct Actor_func_8027DAD0_de;
struct Parent;
struct Actor_func_8027DAD0_de {
    char pad0[4];
    u16 type;
    char pad6[2];
    CVector3 position;
    s32 unk14;
    char pad18[4];
    CVector3 heading;
    char pad28[0x28];
    CVector3 offset;
    s32 flags;
    char pad60[0xCC];
    struct Parent *owner;
    char pad130[4];
    struct Parent *parent;
    char pad138[0x3C];
    CVector3 facing;
    char pad180[0x51];
    s8 bone;
};

struct func_8027DAA4_S1;
struct func_8027DAA4_S1 {
    char pad0[0x160];
    char unk160;
};


struct func_80282E6C_S3;
struct func_80282E6C_S3 {
    char pad0[0x140];
    char unk140;
};

union func_80282E6C_S1_U8;
typedef union func_80282E6C_S1_U8 func_80282E6C_S1_U8;

struct func_80282E6C_S1;
struct func_80282E6C_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x8 - 0x4 - sizeof(u16)];
    func_80282E6C_S1_U8 unk8;
    char pad8[0x118 - 0x8 - sizeof(func_80282E6C_S1_U8)];
    void * unk118;
    char pad118[0x12C - 0x118 - sizeof(void*)];
    void * unk12C;
    char pad12C[0x1D0 - 0x12C - sizeof(void*)];
    s8 unk1D0;
};

struct func_80282E6C_S5;
struct func_80282E6C_S5 {
    char pad0[0x70];
    u16 unk70;
    char pad70[0x8C - 0x70 - sizeof(u16)];
    u16 unk8C;
};

union func_8027C324_S1_U118;
typedef union func_8027C324_S1_U118 func_8027C324_S1_U118;

struct Shared_ParticleOwner;
struct Shared_ParticleOwner {
    u8 kind;
    char pad1[0xFF];
    s32 flags;
    char pad104[0xD4];
    PlayerRecAt122C *state;
};

struct Shared_ParticleColors;
struct Shared_ParticleColors {
    char pad0[0x6];
    u8 prim[3];
    u8 env[3];
};
struct Shared_ParticleFade;
struct Shared_ParticleFade {
    char pad0[0x5];
    s8 rangeMode;
    char pad6[0x3];
    s8 fadeIn;
    s8 fadeOut;
    char padB[0x3];
    s8 unkE;
};
struct Shared_ParticleColors;
struct Shared_ParticleDesc;
struct Shared_ParticleFade;
/* The oscillator controller is reached through descriptor byte0x2C.
 * The ROM reads its signed ramp byte at0x18. */
struct Shared_ParticleOscillation {
    char reserved[0x18];
    s8 ramp;
};
/* Descriptor distance range: scalars read at +0x1C/+0x20 by the particle transform. */
struct Shared_ParticleDistanceRange {
    u8 reserved0[0x18];
    f32 shadowSize;
    f32 minimum;
    f32 maximum;
};
/* Two 24-byte directional-light records occupy particle +0xE0..+0x110. */
#include "COMMON/PARTICLE_LIGHTING.H"
/* Fourteen event slots: paired parameters followed by parallel ID arrays. */
struct Shared_ParticleEvents {
    struct IntPair parameters[14];
    u16 particles[14];
    u16 effects[14];
    u16 sounds[14];
};
struct Shared_ParticleDesc {
    s32 flags;
    char pad4[0x4];
    s8 animMode;
    char pad9;
    s8 clampToGround;
    char padB[5];
    s16 unk10;
    char pad12[2];
    s32 renderModel;
    struct Shared_ParticleEvents *events;
    char pad1C[8];
    struct Shared_ParticleDistanceRange *distanceRange;
    char pad28[4];
    struct Shared_ParticleOscillation *oscillation;
    char pad30[0x4];
    struct Shared_ParticleColors *colors;
    struct Shared_ParticleFade *fade;
};
struct Shared_Particle;
struct Shared_ParticleDesc;
struct Shared_ParticleOwner;
struct Shared_ParticleTarget;
struct Shared_ParticleView {
    u32 unknown0[2];
    s32 unk8;
    u32 unknownC[6];
    s32 unk24;
    u32 unknown28[62];
    s32 grayscale;
    u32 unknown124;
    CVector3 unk128;
    u32 unknown134[59];
    Matrix viewMtx;
    u32 unknown260[36];
    f32 clipMatrix[4][4];
    u32 unknown330[8];
    CVector3 clipMin;
    CVector3 clipMax;
    u32 unknown368[112];
    f32 fadeRange;
};
struct Shared_Particle {
    Shared_ParticleInstance inst;
    CVector3 attachmentPosition;
    s32 flags;
    PackedMatrixWords mtx[2];
    struct Shared_ParticleLighting lighting[2];
    s32 resource; /* 0x110 */
    s32 resourceSize; /* 0x114 */
    struct Shared_ParticleDesc *desc;
    s32 model;
    char pad120[0xC];
    struct Shared_ParticleOwner *owner;
    s32 ownerId;
    struct Shared_ParticleTarget *target;
    s32 handle;
    char pad13C[4];
    f32 time;
    f32 frame;
    f32 unk148;
    s16 life;
    s8 unk14E;
    s8 unk14F;
    CVector3 size;
    CVector3 growth;
    CVector3 prevPos;
    CVector3 direction; /* unit travel direction: aligns direction-frame particles, offsets space -8, axis of the wobble */
    CVector3 rot;
    CVector3 rotSpeed;
    f32 alpha;
    /* Two phase/speed/amplitude triples occupy the existing oscillator words. */
    f32 phaseA;
    f32 phaseB;
    f32 phaseSpeedA;
    f32 phaseSpeedB;
    f32 amplitudeA;
    f32 amplitudeB;
    s32 unk1B4;
    s8 mode0;
    s8 unk1B9;
    s8 unk1BA;
    char pad1BB;
    f32 unk1BC;
    char pad1C0[4];
    f32 rotationScale;
    char pad1C8[8];
    s8 space; /* reference frame the particle is placed in (-8..2): func_8027D97C_de picks its parent transform, func_8027DD48_de its ground clamp */
    s8 shake; /* decaying shake strength 0..127 (flags 0x20000): swings the drawn particle about a pivot */
    u8 prim[3];
    u8 env[3];
    u8 opacity;
    u8 drawWhenHidden;
    u8 reserved1DA[2];
};

struct func_8027C808_S1;
typedef struct func_8027C808_S1 func_8027C808_S1;

struct func_80282E6C_S3;
typedef struct func_80282E6C_S3 func_80282E6C_S3;

struct func_8027C808_S1;
struct func_8027C808_S1 {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    func_8027C5A0_S1_U118 unk118;
    char pad118[0x12C - 0x118 - sizeof(func_8027C5A0_S1_U118)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
    char pad134[0x18C - 0x134 - sizeof(s32)];
    char unk18C;
    char pad18C[0x1BA - 0x18C - sizeof(char)];
    s8 unk1BA;
    char pad1BA[0x1C4 - 0x1BA - sizeof(s8)];
    s32 unk1C4;
};

struct func_8027D950_S2;
typedef struct func_8027D950_S2 func_8027D950_S2;

struct func_80282E6C_S5;
typedef struct func_80282E6C_S5 func_80282E6C_S5;

struct func_80282E6C_S2;
typedef struct func_80282E6C_S2 func_80282E6C_S2;

struct NodeCode8027A0F4;
struct NodeCode8027A0F4 {
    char pad0[0x5C];
    s32 flags;
    char pad60[0xD0];
    s32 *counter;
    char pad134[4];
    s32 resource;
    char pad13C[0x9D];
    u8 marker;
    char pad1DA[0xA];
    void *handle;
    char pad1E8[4];
    struct NodeCode8027A0F4 *next;
};

struct Shared_ParticleTarget;
typedef struct Shared_ParticleTarget Shared_ParticleTarget;

struct func_8027D950_S2;
struct func_8027D950_S2 {
    char pad0[0xE54];
    char unkE54;
    char padE54[0xE94 - 0xE54 - sizeof(char)];
    char unkE94;
};

struct RecordRecAt2C;
typedef struct RecordRecAt2C RecordRecAt2C;

struct func_8027C5A0_S1;
typedef struct func_8027C5A0_S1 func_8027C5A0_S1;

struct func_8027C324_S1;
struct func_8027C324_S1 {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    func_8027C324_S1_U118 unk118;
    char pad118[0x12C - 0x118 - sizeof(func_8027C324_S1_U118)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
    char pad134[0x18C - 0x134 - sizeof(s32)];
    char unk18C;
    char pad18C[0x1B9 - 0x18C - sizeof(char)];
    s8 unk1B9;
    char pad1B9[0x1C4 - 0x1B9 - sizeof(s8)];
    s32 unk1C4;
};

struct func_80282E6C_S2;
struct func_80282E6C_S2 {
    char pad0[0x8];
    CVector3 unk8;
    char pad8[0x698 - 0x8 - sizeof(CVector3)];
    void * unk698;
    char pad698[0x11EC - 0x698 - sizeof(void*)];
    f32 unk11EC;
};

struct func_8027DAA4_S1;
typedef struct func_8027DAA4_S1 func_8027DAA4_S1;

struct Ground;
typedef struct Ground Ground;

struct Actor_func_80281A9C_de;
struct Actor_func_80281A9C_de {
    char pad0[4];
    u16 type;
    char pad6[2];
    CVector3 position;
    char pad14[0x118];
    SharedPlayer *owner;
    char pad130[0x1C];
    s16 crowded;
};

struct World_func_80281A9C_de;
typedef struct World_func_80281A9C_de World_func_80281A9C_de;

typedef struct SteeringSound {u32 header[2];s32 handle,id;} SteeringSound;
typedef struct SteeringTarget {u8 pad0[0x248];CVector3 position;} SteeringTarget;
typedef struct SteeringSettings {u8 pad0[0x10];u16 acceleration,speed;} SteeringSettings;
typedef struct SteeringDescriptor {u8 pad0[0x30];SteeringSettings *motion;} SteeringDescriptor;
typedef struct SteeringParticle {u8 pad0[8];CVector3 position;u8 pad14[8];CVector3 velocity;u8 pad28[0x34];u32 flags;u8 pad60[0xB8];SteeringDescriptor *descriptor;u8 pad11C[0x18];SteeringTarget *target;u8 pad138[8];f32 time;u8 pad144[0x30];CVector3 direction;u8 pad180[0x5C];SteeringSound *sound;} SteeringParticle;
extern void *func_8025C95C_de(void *,s32,CVector3 *,void *,s32);

typedef struct { f32 x, y, z; } AccelSteeringVec;
typedef struct { char pad[16]; u16 accel, limit; } AccelSteeringParams;
typedef struct { char pad[48]; AccelSteeringParams *params; } AccelSteeringLink;
typedef struct { char pad[8]; AccelSteeringVec point; } AccelSteeringTarget;
typedef struct {
    char pad[28];
    AccelSteeringVec velocity;
    char gap[0x118 - 40];
    AccelSteeringLink *link;
    char gap2[0x134 - 0x11c];
    AccelSteeringTarget *target;
    char gap3[0x140 - 0x138];
    f32 distance;
    char gap4[0x174 - 0x144];
    AccelSteeringVec direction;
} AccelSteeringObj;
void func_8027A948_de(AccelSteeringObj *, AccelSteeringVec *);
#endif
