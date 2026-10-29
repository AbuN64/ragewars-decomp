#ifndef COMMON_WORLDRECAT1B6A4_H
#define COMMON_WORLDRECAT1B6A4_H
struct LevelBitRecord;
#ifndef SPAN_1000_CODE_8028B64C_H
#define SPAN_1000_CODE_8028B64C_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"




extern void Scene_ClearActorLinksById(void *scene, s32 linkId);




struct ObjectSceneRegisterActorInSceneLists;
typedef struct ObjectSceneRegisterActorInSceneLists ObjectSceneRegisterActorInSceneLists;

struct ObjCode8028B64C;
struct ObjCode8028B64C {
    char pad[0xC50];
    ActorLinkedControllerView *actors[0x80];
    int count;
};

struct ObjCode8028B64C;
typedef struct ObjCode8028B64C ObjCode8028B64C;

extern ActorLinkedControllerView *Scene_ResolveActorLinkGroup(ObjCode8028B64C *obj, int id);


struct ScenePlayerObjectListView;
struct ScenePlayerObjectListView {
    char pad0[0x1B664];
    Player *objects[16];
    s32 count;
};

struct SceneTriggerCounterOwnerView;
typedef struct SceneTriggerCounterOwnerView SceneTriggerCounterOwnerView;

extern s32 Scene_TestLevelRecordStateBit(void *world, struct LevelBitRecord *levelBitRecord);


struct World;

struct SceneCounterPairView;
typedef struct SceneCounterPairView SceneCounterPairView;




extern int g_vertexLightingMode;






struct WorldCode8028B64C;
typedef struct WorldCode8028B64C WorldCode8028B64C;

struct SceneNearestActorView;
typedef struct SceneNearestActorView SceneNearestActorView;

struct SceneNearestActorView;
struct SceneNearestActorView {
    u8 pad0[0x8];
    f32 x;
    f32 y;
    f32 z;
    u8 pad14[0x4];
    s32 *kind;
    u8 pad1C[0xC8];
    u16 team;
    u8 padE6[0x8E];
    s32 active;
    u8 pad178[0x2C];
    s8 state; /* 0x1A4 */
    u8 pad1A5[0x2E8 - 0x1A5];
};

struct WorldSceneFindNearestMatchingActor;
typedef struct WorldSceneFindNearestMatchingActor WorldSceneFindNearestMatchingActor;

struct SceneNearestActorView;
struct WorldSceneFindNearestMatchingActor;
struct WorldSceneFindNearestMatchingActor {
    u8 pad0[0x138];
    struct SceneNearestActorView *objects;
    u8 pad13C[0x4];
    s32 count;
};

extern SceneNearestActorView *Scene_FindNearestMatchingActor(WorldSceneFindNearestMatchingActor *world, SceneNearestActorView *self, s32 team, s32 kind, s32 activeOnly);

struct SceneDefinitionActorView;
struct SceneDefinitionActorView {
    char pad[0x18];
    MenuActorInputView *def;
};

struct SceneDefinitionActorView;
typedef struct SceneDefinitionActorView SceneDefinitionActorView;

struct WorldCode8028B64C;
struct WorldCode8028B64C {
    char pad[0x1B664];
    SceneDefinitionActorView *list[16];
    s32 count;
};

extern SceneDefinitionActorView *Scene_FindTypeFourteenActorByDefinitionId(WorldCode8028B64C *world, s32 id);

struct SceneCounterPairView;
struct SceneCounterPairView {
    unsigned char padding_0[32];
    s32 unk_20;
    unsigned char padding_24[44];
    s32 unk_50;
};




struct ScenePositionEntry;
struct ScenePositionEntry {
    char pad[8];
    f32 x;
    f32 y;
    f32 z;
};

struct ScenePositionEntry;
struct OwnerCode8028B64C;
struct OwnerCode8028B64C {
    char pad[0x1024];
    struct ScenePositionEntry *entries[0x20];
    s32 count;
};

struct ScenePositionEntry;
struct OwnerCode8028B64C;
extern struct ScenePositionEntry *Scene_FindNearestListedEntry(struct OwnerCode8028B64C *owner, struct ScenePositionEntry *pos);




struct World;

extern SceneDefinitionActorView *Scene_FindSwitchByDefinitionId(World *world, s32 id);



struct ObjectSceneRegisterActorInSceneLists;
struct MemoryUsageStats;
struct ObjectSceneRegisterActorInSceneLists {
    char pad0[0x18];
    struct MemoryUsageStats *descriptor;
    char pad1C[0xE4 - 0x1C];
    u16 model;
    char padE6[0x100 - 0xE6];
    s32 flags;
    char pad104[0x23E - 0x104];
    signed char slot;
};



struct SceneActorCategoryListsView;
struct SceneActorCategoryListsView {
    char pad0[0x144];
    ObjectSceneRegisterActorInSceneLists *listA[512];
    s32 countA;
    ObjectSceneRegisterActorInSceneLists *listB[128];
    s32 countB;
    char padB4C[0xC50 - 0xB4C];
    ObjectSceneRegisterActorInSceneLists *all[128];
    s32 countAll;
    ObjectSceneRegisterActorInSceneLists *type1[64];
    s32 countType1;
    s32 padF58;
    ObjectSceneRegisterActorInSceneLists *flagged[32];
    s32 countFlagged;
    ObjectSceneRegisterActorInSceneLists *type5[16];
    s32 countType5;
    ObjectSceneRegisterActorInSceneLists *model64F[32];
    s32 count64F;
    ObjectSceneRegisterActorInSceneLists *model64D[4];
    s32 count64D;
};




struct SceneTriggerCounterOwnerView;
struct SceneTriggerCounterOwnerView {
    u8 pad0[0x80];
    void *resource;
    u8 pad84[0x2C];
    Table *list;
};

extern s32 Scene_GetTriggerCounterById(SceneTriggerCounterOwnerView *counterOwner, s32 counterId);


struct SceneActorCategoryListsView;
typedef struct SceneActorCategoryListsView SceneActorCategoryListsView;





struct ScenePlayerObjectListView;
typedef struct ScenePlayerObjectListView ScenePlayerObjectListView;

extern Player *Scene_FindNearestObjectToFirstPlayer(ScenePlayerObjectListView *world);












/* Shared object layout established by level-bits consumers. */
struct LevelBitRecord {
    u8 padding000[0x19E];
    u16 bitIndex; /* 0x19E */
};

#endif
#endif
