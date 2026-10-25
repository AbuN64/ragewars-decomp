#ifndef COMMON_ACTORRESOURCEHEADER_H
#define COMMON_ACTORRESOURCEHEADER_H
#include "TYPES.H"
/* Section one of the resource selected by an actor's resource key. */
/* Section zero of the resource selected by an actor's resource key. */
typedef struct ActorResourceHeader {
    u8 unknown0[0x1E];
    u16 particleScale; /* Float encoded in its high sixteen bits. */
} ActorResourceHeader;
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"

struct LookupRecAtC;
struct LookupRecAtC {
    u32 pad0[3];
    void **value;
};

extern float D_800C3B60_de;

struct Body_func_8024C6E8_de;
typedef struct Body_func_8024C6E8_de Body_func_8024C6E8_de;



struct LevelActor;

extern float D_800C3BA8;



struct Node75;

extern float D_800C3B7C;



struct ObjectList;
typedef struct ObjectList ObjectList;


struct Camera;
typedef struct Camera Camera;

struct Body_func_8024C6E8_de;
struct Body_func_8024C6E8_de {
    char pad0[0x30];
    CVector3 velocity;
};



struct ObjRecAt17C;
struct ObjRecAt17C {
    char pad0[0x17C];
    s32 unk17C;
};

struct ObjectList;
struct ObjectList {
    char pad0[4];
    char *objects;
    s32 count;
};

struct ObjRecAt2E0;
struct ObjRecAt2E0 {
    char pad0[0x2E0];
    unsigned int unk2E0;
};

extern float D_800C3BA0_de;

struct Scratch;
struct Scratch {
    f32 first[4];
    f32 second[4];
    f32 in[4];
    f32 out[4];
    CVector3 position;
    f32 positionPadding;
    char matrix[0x40];
};

struct SourceRecAt18;
struct SourceRecAt18 {
    char pad0[0x12];
    s8 charges;
    char pad13;
    s8 owner;
    char pad15[3];
    CVector3 position;
};


struct Scratch;
typedef struct Scratch Scratch;


struct ObjRecAt17C;
typedef struct ObjRecAt17C ObjRecAt17C;

struct Camera;
struct Camera {
    char pad0[8];
    s32 matrices;
    char pad1[4];
    s32 style;
};

union func_8024C33C_S1_U8;
union func_8024C33C_S1_U8 {
    f32 v0;
    char v1;
};

struct SourceRecAt18;
typedef struct SourceRecAt18 SourceRecAt18;


extern float D_800C8C44;

extern float D_800C8C70;


struct ObjectLinks1DC_3;
typedef struct ObjectLinks1DC_3 ObjectLinks1DC_3;

struct ObjectLinks1DC_3;
struct ObjectLinks1DC_3 {
    char pad0[0x8];
    CVector3 unk_8;
    char pad14[0xC4 - 0x14];
    s32 resource;
    char padC8[8];
    s32 resourceFlags;
    char padD4[0x100 - 0xD4];
    s32 unk_100;
    f32 animationTime;
    char pad108[0x1D8 - 0x108];
    char * unk_1D8;
};

struct LookupRecAtC;
typedef struct LookupRecAtC LookupRecAtC;


extern float D_800C3B98;

struct ObjectLinks24;
typedef struct ObjectLinks24 ObjectLinks24;

union func_8024C33C_S1_U8;
typedef union func_8024C33C_S1_U8 func_8024C33C_S1_U8;







struct Rec_func_8024C92C_de;


struct ObjectLinks24;
struct ObjectLinks24 {
    char * unk_0;
    char pad0[0x4 - 0x0 - sizeof(char*)];
    char * unk_4;
    void *translationFrames; /* 0x8 */
    void * unk_C;
    char padC[0x10 - 0xC - sizeof(void*)];
    s32 unk_10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk_14;
    s32 translationFirst; /* 0x18 */
    s32 translationNext; /* 0x1C */
    f32 unk_20;
};


extern float D_800C3B90;

struct ObjRecAt2E0;
typedef struct ObjRecAt2E0 ObjRecAt2E0;

struct Shared_Func80243A80Actor;

extern float D_800C3B88;


extern void func_8024C104_eu(void);
extern void func_8024C10C_eu(void);
extern void func_8024C134_eu_x(void);
extern void func_8024C13C_eu_x(void);
/* Section five of an actor frame resource describes its rendering mode. */
struct ActorFrameMetadata {
    u8 reserved0[0x6E];
    u8 renderMode; /* 0x6E */
};

extern void func_8026F898_de(f32 *, f32 *, f32 *);
extern void Render_DrawResourceModel(s32, s32, void *, s32, void *, s32, s32);

extern CVector3 *Nav_GetNodeEdgeCross(CVector3 *out, Node75 *node);

extern char D_800C3AE8_de;
extern char D_0026D814;
extern char D_800C3B28;
extern char D_800C3B3C;
#endif
