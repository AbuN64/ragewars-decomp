#ifndef COMMON_ACTORREC_H
#define COMMON_ACTORREC_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
struct ActorRec;
typedef struct ActorRec ActorRec;

extern float D_800C1DB8_de;

struct ObjNavComputeScaledPointCentroid;
struct ObjNavComputeScaledPointCentroid {
    char pad0[0x38];
    s32 count;
    char pad3C[0x138-0x3C];
    CVector3 points[10];
    CVector3 result;
    char pad1BC[0x1C4-0x1BC];
    s32 infoIndex;
};

extern float D_800C1E40_de;

struct Stage;
struct Stage {
    s32 to;
    s32 from;
    f32 distance;
};

struct Stage;
typedef struct Stage Stage;

struct SelectionNavAppendDirectionalRouteStage;
struct SelectionNavAppendDirectionalRouteStage {
    char pad0[0xC];
    s32 node;
    char pad10[4];
    s32 ids[4];
    char pad24[0x14];
    s32 objectCount;
    Player *objects[33];
    Stage stages[10];
    CVector3 dirs[10];
    CVector3 result;
    s32 stageCount;
    s32 id;
    s32 lastNode;
    s32 failed;
};


/* The trajectory mode belongs to the full instance, beyond its 20-byte header. */
typedef struct BallisticInstance {
    InstanceHdr header;
    u8 pad014[0x62E - 0x14];
    s16 trajectoryMode;
} BallisticInstance;

struct ActorRec;
struct ActorRec {
    BallisticInstance *instance;
    u8 pad004[0x248 - 4];
    f32 field248;
    f32 field24C;
    f32 field250;
    f32 field254;
    union {
        struct { f32 field258; f32 field25C; f32 field260; };
        CVector3 destination;
    };
    f32 field264;
    s32 field268;
    s32 field26C;
    s32 field270;
    s32 field274;
    f32 field278;
    f32 field27C;
    f32 field280;
    s32 field284;
};


struct SelectionNavAppendDirectionalRouteStage;
typedef struct SelectionNavAppendDirectionalRouteStage SelectionNavAppendDirectionalRouteStage;

extern float D_800C1E48_de;

struct WeightSource;

struct func_8020DCA0_S1;
typedef struct func_8020DCA0_S1 func_8020DCA0_S1;

extern float D_800C1E58_de;

extern float D_800C1E44_de;

struct ObjNavFindSpecialLinkedCandidate;
struct ObjNavFindSpecialLinkedCandidate {
    char pad0[0x14];
    int nodes[4];
    char pad24[0x1BC - 0x24];
    int hits;
    int node;
    char pad1C4[4];
    int pending;
};

struct func_8020DCA0_S1;

struct ObjNavFindSpecialLinkedCandidate;
typedef struct ObjNavFindSpecialLinkedCandidate ObjNavFindSpecialLinkedCandidate;

struct ObjNavComputeScaledPointCentroid;
typedef struct ObjNavComputeScaledPointCentroid ObjNavComputeScaledPointCentroid;

extern float D_800C1E50_de;

struct WeightSource;
typedef struct WeightSource WeightSource;


/* Resource sections returned by Render_GetPackSection, selectors 1 and 2. */
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
typedef struct BallisticResourceKeys {
    s32 tag;
    s32 count;
    u32 keys[1];
} BallisticResourceKeys;
typedef struct BallisticResourceRecords {
    s32 tag;
    s32 count;
    BallisticParamsHolder records[1];
} BallisticResourceRecords;

extern s32 *D_8013D534;
#endif
