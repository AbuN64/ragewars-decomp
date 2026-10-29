#ifndef MENU_SCENE_RESOURCE_PREVIEW_AND_COLLISION_VIEWS_H
#define MENU_SCENE_RESOURCE_PREVIEW_AND_COLLISION_VIEWS_H
#include "TYPES.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJB.H"
#include "COMMON/PACKED.H"
#include "COMMON/SHAREDPLAYER.H"
/* The resource header is followed by count input records or runtime actors. */
typedef struct LevelBlock {
    s32 size;
    s32 count;
    LevelActor objects[1];
} LevelBlock;
struct ItemsPendingState {
    char p[0x11C0];
    s32 firstPendingCount;
    s32 secondPendingCount;
    char q[8];
    s32 firstPendingEntries;
    s32 secondPendingEntries;
};
struct SceneLightLoadView {
    char pad0[0x1B2B0];
    struct CROMLevel_t *light;
    s16 dir[3];
};
struct MenuPlayerPoolView {
    s32 actorHandle;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 actors;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 actorCount;
    char pad8[0xC - 0x8 - sizeof(s32)];
    IntrusiveList active;
    IntrusiveList available;
    char pad34[0x38 - 0x34];
    s32 unk38;
    char pad38[0x40 - 0x38 - sizeof(s32)];
    char cameraStorage;
    char pad40[0xF18 - 0x40 - sizeof(char)];
    s32 unkF18;
    char padF18[0xF1C - 0xF18 - sizeof(s32)];
    s32 unkF1C;
    char padF1C[0xF20 - 0xF1C - sizeof(s32)];
    s32 unkF20;
    char padF20[0xF24 - 0xF20 - sizeof(s32)];
    IntrusiveList auxiliaryEntries;
    char padF24[0x1200 - 0xF24 - sizeof(IntrusiveList)];
    s32 unk1200;
};
struct SceneGridCellLoadView {
    char pad0[0x30];
    s32 key;
    char pad34[0x64 - 0x34];
    s32 file;
    void *grid;
};
struct Node_Items_FindPlacedObjectsByKey {
    s32 index;
    s32 link[2];
};
struct SceneResourceOwnerView {
    char pad0[0xB8];
    void * unkB8;
    void * unkBC;
    void * unkC0;
    void * unkC4;
    void * unkC8;
    void * unkCC;
    void * unkD0;
    void * unkD4;
    char padD4[0x10];
    void * unkE8;
    void * unkEC;
    void * firstOptionalResource;
    void * secondOptionalResource;
    char padF4[0x4];
    void * thirdOptionalResource;
    void * unk100;
    char pad100[0x1B3FC];
    IntrusiveList allocations;
};
struct ItemsPreviewStateB {
    char pad[0x3C];
    int resource;
    char pad40[8];
    int bank;
    char pad4c[0x1B3C0];
    int selection;
    char pad1b410[12];
    int changed;
};
struct ObjA {
    s8 pad0;
    s8 type;
    char pad2[0x20 - 2];
    void **block;
    char pad24[0xE8 - 0x24];
};
struct ItemsSelectionState {
    char pad[0x1B2B0];
    ResourceSmpFlickerCreateFlickerWidget *input;
    char pad1b2b4[0x15C];
    int mode;
    int active;
    char pad1b418[0x20];
    int selection;
};
struct MenuEntryPoolCountView {
    struct EntryCode8044ACCC entries[4];
    IntrusiveList free;
    IntrusiveList active;
    s16 count;
};
typedef struct CollisionBuildHeader {
    s32 count;
    s32 offsets[5];
} CollisionBuildHeader;
typedef struct CollisionBuildList {
    s32 kind;
    s32 count;
    CollisionBuildFace items[0];
} CollisionBuildList;
typedef union CollisionBuildMeshHandle {
    struct CacheResourceBlockView canonical;
    struct { void *data; s32 size,refs,flags; } payload;
} CollisionBuildMeshHandle;
typedef struct CollisionBuildVertexList { s32 kind,count; CollisionBuildVertex items[0]; } CollisionBuildVertexList;
typedef struct CollisionBuildTriangleList { s32 kind,count; CollisionBuildTriangle items[0]; } CollisionBuildTriangleList;
typedef struct CollisionBuildWorld {
    char pad0[0x84];
    int *tree;
    char pad88[0x1B2FC - 0x88];
    f32 minY;
    char pad1B300[0x1B40C - 0x1B300];
    s32 group;
} CollisionBuildWorld;
struct LevelCode8044ACCC {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 bloodlustDirectoryKey;
    s32 bloodlustDirectorySize;
    s32 unk14;
    s32 unk18;
    s32 levelDirectoryKey;
    s32 textureDirectoryKey;
    s32 objectDirectoryKey;
    s32 binaryDirectoryKey;
    s32 graphicsetDirectoryKey;
    char pad30[4];
    s32 sectionEighteenKey;
    s32 sectionSixAddress;
    s32 sectionSevenAddress;
    char pad40[48];
    s32 particleSwooshes;
    char pad74[4];
    s32 geometry;
    char pad7C[4];
    void *placedActorStorage;
    void *collisionStorage;
    s32 unk88;
    char pad8C[4];
    s32 warpDestinations;
    s32 objectTypes;
    s32 sectionTenObjectTypes;
    s32 graphicsetTypes;
    s32 sectionTwelveData;
    s32 curves;
    s32 sectionFifteenData;
    s32 rumbleLabels;
    s32 linkGroupTypes;
    void *particleEffectHandle;
    char padB8[56];
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
    s32 unkFC;
    char pad100[12];
    void *warpDestinationsHandle;
    char pad110[16];
    s32 unk120;
    s32 unk124;
    char pad128[111072];
    s32 unk1B308;
    char pad1B30C[16];
    s32 unk1B31C;
    char pad1B320[236];
    s32 visibilityGroup;
    char pad1B410[516];
    s32 spawnOffsetX;
    s32 spawnOffsetY;
    s32 spawnOffsetZ;
    char pad1B620[64];
    s32 unk1B660;
    char pad1B664[64];
    s32 selectedActorCount;
    char pad1B6A8[4];
    s32 sceneLoadResetState;
};
struct ItemsPreviewStateA {
    char pad0[4];
    s32 loaded;
    char pad8[48];
    s32 directoryKey;
    char pad3C[8];
    s32 resourceFlags;
};
#endif
