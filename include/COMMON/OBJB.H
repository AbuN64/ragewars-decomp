#ifndef COMMON_OBJB_H
#define COMMON_OBJB_H
#include "TYPES.H"
#include "COMMON/LEVEL_TRACK.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PACKED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/LEVEL_INPUT.H"

struct Shared_Placed;



struct ItemsPendingState;

struct ObjB;
typedef struct ObjB ObjB;

struct World;


struct CROMLevel_t;
struct CROMLevel_t {
    f32 m_GridDistance;
    char pad4[0xA - 0x4];
    u8 m_DirectionalLight[3];
    u8 m_AmbientLight[3];
    char pad10;
    signed char m_Direction[3];
};
struct CROMLevel_t;
struct SceneRecAt1B2B4;

struct func_8044B27C_S1;

struct func_8044CBE0_S1;
typedef struct func_8044CBE0_S1 func_8044CBE0_S1;

struct func_8044B27C_S1;
typedef struct func_8044B27C_S1 func_8044B27C_S1;



struct Bucket;
typedef struct Bucket Bucket;

struct SceneRecAt1B2B4;
typedef struct SceneRecAt1B2B4 SceneRecAt1B2B4;

struct Level_func_8044CD8C_de;

struct CDLight_t;
typedef struct CDLight_t CDLight;

typedef IntrusiveList ListRec;

struct Bucket;
struct Bucket {
    struct Bucket *prev;
    struct Bucket *next;
    struct Record14 *object;
    f32 remaining;
};

struct Floats;
typedef struct Floats Floats;

struct ItemsSelectionState;
typedef struct ItemsSelectionState ItemsSelectionState;

struct Node_Items_FindPlacedObjectsByKey;

struct ObjA;
typedef struct ObjA ObjA;


struct Face;
struct Face {
    char pad0[0xE];
    u8 flags;
    u8 hidden;
    char pad10[3];
    u8 group;
};

struct Face;
typedef struct Face Face;




struct func_8044CBE0_S1;

struct ItemsPreviewStateB;

struct World;


struct Node_Items_FindPlacedObjectsByKey;
typedef struct Node_Items_FindPlacedObjectsByKey Node_Items_FindPlacedObjectsByKey;

struct ItemsPreviewStateB;
typedef struct ItemsPreviewStateB ItemsPreviewStateB;




struct CDLight_t;
/* One of the dynamic-light pool's eight 0x18-byte records, threaded through its lists by m_pPrev (+0) and m_pNext (+4). */
struct CDLight_t {
    struct CDLight_t *m_pPrev;
    struct CDLight_t *m_pNext;
    void *m_pROMLight;
    f32 m_ColorFade;
    s16 x, y, z;
    s16 m_bEnabled;
};
struct CGameDynamicLight_t;

extern float g_lightDirectionLength;

struct ObjA;

struct Level_func_8044CD8C_de;
typedef struct Level_func_8044CD8C_de Level_func_8044CD8C_de;



struct Face;
struct WorldRecAt1B40C;
struct WorldRecAt1B40C {
    char pad0[0x80];
    void *tree;
    char pad84[0x11C0 - 0x84];
    s32 nfaces;
    s32 nedges;
    void *verts;
    void *edgeData;
    struct Face *faces;
    struct Face *edges;
    IntrusiveList listA;
    IntrusiveList listB;
    Bucket buckets[0x30];
    char pad1500[0x1B40C - 0x1500];
    s32 group;
};



struct Shared_Placed;


extern short D_8010F320;

struct ItemsSelectionState;



struct ObjRecAt8C8;
struct EntryCode8044ACCC {
    char pad0[0x228];
};




struct ItemsPendingState;
typedef struct ItemsPendingState ItemsPendingState;

struct ObjRecAt8C8;
typedef struct ObjRecAt8C8 ObjRecAt8C8;


struct Floats;
struct Floats {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};



struct ItemsHandleOwner;
struct ItemsHandleOwner {
    char pad[0x11BC];
    s32 first;
    s32 second;
};
typedef struct ItemsHandleOwner ResourceHandleOwner;

struct WorldRecAt1B40C;
typedef struct WorldRecAt1B40C WorldRecAt1B40C;

struct ObjB;
struct ObjB {
    s8 pad0;
    s8 type;
    char pad2[0x60 - 2];
    void **block;
    char pad64[0x1C8 - 0x64];
};

struct Shared_World;
extern void **func_802540F4_de(s32,void **,s32,void *,s32);
extern s32 D_0044D804;
extern s32 D_0044D934;
extern char g_cartridgeIndex;
extern char D_800C4F60_de;
extern char g_textureSetsIndex;
extern char D_800C4F84_de;
extern char g_objectsIndex;
extern char D_800C4FA4_de;
extern char g_particleEffects;
extern char D_800C4FC8_de;
extern char g_particleSwooshes;
extern char D_800C4FEC_de;
extern char g_warpDests;
extern char g_curves;
extern char g_rumbleLabels;
extern char D_800C5018_de;
extern char g_graphicsetType;
extern char g_graphicsetIndex;
extern char D_800C504C_de;
extern char g_linkGroupTypes;
extern char g_constructBlLevelDataIndex;
extern char g_bloodlustWeaponData;

extern void Geometry_ExpandModelWithSentinel(s32, s32);
extern u8 g_constructMapObjectIndex[];
extern u8 g_constructMapSimpModelsIndex[];
extern u8 g_constructMapSimpleModel[];

typedef struct CollisionBuildVertex {
    f32 x;
    f32 y;
    f32 z;
    f32 ceiling;
} CollisionBuildVertex;
typedef union CollisionBuildTriangle { struct {
    u16 kind;
    u16 flags;
    CollisionBuildVertex *v[3];
    union CollisionBuildTriangle *adj[3];
    s32 mask;
} fields; CGameRegion canonical; s32 words[8]; } CollisionBuildTriangle;
typedef Packed CollisionBuildFace;
extern void SetN64_TransposeRecords(void *src, void *dst, s32 arg2);

extern void *memcpy(void *, const void *, unsigned int);
extern s32 D_80141060;
extern void Ovlgame_InitActorParts(SharedPlayer *player, InputRecAt27 *rec, s32 mode, s32 index);
#endif
