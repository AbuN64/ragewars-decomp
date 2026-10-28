#ifndef SCENE_RESOURCE_BINDING_AND_FADE_VIEWS_H
#define SCENE_RESOURCE_BINDING_AND_FADE_VIEWS_H
#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Manager {
    char queue[0x92C];
    IntrusiveList pending;
    IntrusiveList active;
    char padActive[0x20 - sizeof(IntrusiveList)];
    char lock[0x18];
    char unk978[0x24];
    s32 mask;
};
struct ObjectState13 {
    unsigned char padding_0[18];
    signed char unk_12;
};
struct OwnerStaticInstanceDrawGeometryVariant {
    char pad0[0x20];
    s32 field20;
    char pad24[4];
    char transform[0xA8];
    s32 flagsD0;
    char padD4[6];
    u8 colorFrame;
};
struct ObjectLinksDC {
    char pad0[0x18];
    char * unk_18;
    char pad18[0xD8 - 0x18 - sizeof(char*)];
    unsigned short unk_D8;
};
struct Shape_func_802BC570_de {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};
/* Shared object layout established by resource-binding consumers. */
struct ResourceBinding {
    u8 padding000[1];
    s8 variant; /* 0x01 */
    u8 padding002[0x1E];
    s32 *resource; /* 0x20: loaded resource descriptor */
    u8 padding024[4];
    u8 transform[0x8C]; /* 0x28 */
    void *loadedResource; /* 0xB4 */
    u8 runtimeState[0x18]; /* 0xB8 */
    s32 registrationFlags; /* 0xD0 */
    u8 padding0D4[4];
    u16 status; /* 0xD8 */
    u8 colorFrame; /* 0xDA */
};
/* Actor resource fade selects the near/far value using its frame threshold. */
struct ResourceFadeDefinition {
    u8 reserved0[0xE];
    s8 nearValue; /* 0xE */
    s8 farValue; /* 0xF */
    u8 reserved10[0x14];
    u32 threshold; /* 0x24 */
};
struct NodePair80253E04 {
    Node80253610 *first;
    Node80253610 *second;
};
/* Resource manager slot and its wait queue (D_801005A8 / D_80101140). */
typedef struct ResourceLockState {
    s32 slot;
    u8 reserved4[0xB98 - 4];
    OSMesgQueue waitQueue;
} ResourceLockState;
extern int Statinst_SelectDistanceVariant(void *object);
extern void Statinst_RefreshResourceUsage(void *resourceBinding);
extern s8 Statinst_SelectGameModeVariant(struct LevelActor *actor);
extern void Statinst_DrawForGameMode(void *);
extern CachedResource *Cache_RequestPairedResource(s32 unused, s32 key, CachedResource *first, CachedResource *second, s32 mode, void *owner, void *tag, void *spare, s32 async);
#endif
