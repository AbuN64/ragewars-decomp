#include "include_asm.h"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJB.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"
#include "MENU/8044ACCC.H"
#include "COMMON/SHAREDPLAYER.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_3.H"

/* Initializes camera transforms, viewport state, clipping records, and resource lists. */

 
void func_80238EB8_de(void *);                               /* extern */
void Gsky_SetGameplayMode(void *, s32);                         /* extern */
void Gsky_ResetFadeState(void *);                            /* extern */
void Gsky_InitializeMessageEntryPool(void *);                            /* extern */
void Graphu64_IdentityMatrix(void *);                            /* extern */
void Menu_InitMenuMessageList(void *);                    /* extern */


extern s32 D_800E28D0;






/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x20, 0x24], gap at: 0x18. */
void Pools_InitializeGameplayCamera(GameplayCamera *arg0) {
    f32 temp_f21;
    f32 zero;
    s16 temp_a0;
    s32 var_a1;
    Floats *temp_v0;
    Floats *temp_v0_2;
    Floats *temp_v0_3;
    Floats *temp_v0_4;
    Floats *temp_v0_5;

    func_80238EB8_de(((void *)&((GameplayCamera *)arg0)->unk24));
    Graphu64_IdentityMatrix(((GameplayCamera *)arg0)->viewOrient);
    Graphu64_IdentityMatrix(((GameplayCamera *)arg0)->viewProjection);
    zero = 0.0f;
    temp_f21 = 1.0f;
    temp_v0 = ((void *)&((GameplayCamera *)arg0)->orientation);
    temp_v0->unk8 = zero;
    temp_v0->unk4 = zero;
    arg0->orientation.x = zero;
    arg0->orientation.w = temp_f21;
    Graphu64_IdentityMatrix(((GameplayCamera *)arg0)->inverseViewOrient);
    arg0->viewWidth = (f32) D_800E28D0;
    arg0->viewHeight = (f32) D_800E28D4;
    arg0->unk518 = -1;
    arg0->viewLeft = zero;
    arg0->viewTop = zero;
    arg0->unk520 = 0;
    arg0->unk524 = 0;
    arg0->unk521 = 0;
    arg0->unk525 = 0;
    arg0->unk522 = 0;
    arg0->unk526 = 0;
    arg0->unk523 = 0;
    arg0->unk527 = 0;
    arg0->unk51C = temp_f21;
    arg0->fogNear = 0x3E3;
    arg0->unk540 = 0x3E3;
    arg0->unk548 = 0;
    arg0->dirty = 0;
    arg0->pixelXScale = temp_f21;
    arg0->pixelYScale = temp_f21;
    arg0->farPlane = (f32) 1024.0f;
    arg0->unk52C = (f32) 1024.0f;
    arg0->unk530 = (f32) 47.5f;
    arg0->unk534 = (f32) 47.5f;
    Gsky_ResetFadeState(arg0);
    temp_v0_2 = ((void *)&((GameplayCamera *)arg0)->padA0);
    arg0->shakeHorizontal = zero;
    arg0->shakeVertical = zero;
    temp_v0_2->unk8 = zero;
    temp_v0_2->unkC = zero;
    temp_v0_2->unk10 = zero;
    temp_v0_2->unk14 = temp_f21;
    temp_v0_3 = ((void *)&((GameplayCamera *)arg0)->unkB8);
    temp_v0_3->unk4 = zero;
    temp_v0_3->unk8 = zero;
    temp_v0_3->unkC = zero;
    temp_v0_3->unk10 = zero;
    temp_v0_4 = ((void *)&((GameplayCamera *)arg0)->unkCC);
    temp_v0_4->unk4 = zero;
    temp_v0_4->unk8 = zero;
    temp_v0_4->unkC = zero;
    temp_v0_4->unk10 = zero;
    temp_v0_5 = ((void *)&((GameplayCamera *)arg0)->unkE0);
    temp_v0_5->unk4 = zero;
    temp_v0_5->unk8 = zero;
    temp_v0_5->unkC = zero;
    temp_v0_5->unk10 = zero;
    Gsky_SetGameplayMode(arg0, 0);
    temp_a0 = D_800E28D0 * 2;
    for (var_a1 = 0; var_a1 < 2; var_a1++) {
        ((RacerViewport *)arg0)->viewports[var_a1].vscale[0] = temp_a0;
        ((RacerViewport *)arg0)->viewports[var_a1].vscale[1] = temp_a0;
        ((RacerViewport *)arg0)->viewports[var_a1].vscale[2] = 0x3FF;
        ((RacerViewport *)arg0)->viewports[var_a1].vscale[3] = 0;
        ((RacerViewport *)arg0)->viewports[var_a1].vtrans[0] = temp_a0;
        ((RacerViewport *)arg0)->viewports[var_a1].vtrans[1] = temp_a0;
        ((RacerViewport *)arg0)->viewports[var_a1].vtrans[2] = 0;
        ((RacerViewport *)arg0)->viewports[var_a1].vtrans[3] = 0;
    }
    Menu_InitMenuMessageList(((void *)&((GameplayCamera *)arg0)->messageList));
    Graphu64_IdentityMatrix(((GameplayCamera *)arg0)->faceScreen);
    Graphu64_IdentityMatrix(((GameplayCamera *)arg0)->faceScreenUpright);
    arg0->fadeEnabled = 0;
    arg0->monochrome = 0;
    arg0->kickStep = 0x32;
    arg0->unk126 = 0;
    D_800FF224_de = 0;
    func_80255CA0_de(&((GameplayCamera *)arg0)->objects, 0, 4);
    Gsky_InitializeMessageEntryPool(arg0);
}

#include "TYPES.H"
typedef struct DraftListA370 { void *head, *tail; s32 count, a, b; } DraftListA370;
typedef struct DraftEntryA370 { void *next, *prev; s32 a, b, c; f32 value; DraftListA370 lists[3]; } DraftEntryA370;
typedef struct DraftActorA370 { void *next, *prev; s32 index; u8 rest[0xECC]; } DraftActorA370;
typedef struct DraftSmallA370 { u8 data[0x40]; } DraftSmallA370;
typedef struct DraftOwnerA370 {
    DraftActorA370 **handle, *actors; s32 count;
    DraftListA370 active, free;
    s32 word34, word38, word3C;
    u8 parts[8]; s32 word48; u8 rest[0xF18 - 0x4C];
    DraftSmallA370 **smallHandle, *small; s32 smallCount;
    DraftListA370 smallList;
    DraftEntryA370 entries[8];
    DraftListA370 entryList, spareList;
    s32 empty;
} DraftOwnerA370;
extern f32 D_800C32EC_de;
extern char g_camerasText[];
extern char D_800C32DC_de[];
extern void func_8025E3F0_de(void *);
extern void Cache_DrainAndCompactResources(s32);
extern void Cache_ReleaseResource(s32, void *);
extern void *Cache_AllocateResource(s32, s32, s32, char *);
static inline void resetDraftList(DraftListA370 *list) {
    list->tail = 0;
    list->count = 0;
    list->a = 0;
    list->b = 0;
}
static inline void resetDraftEntry(DraftEntryA370 *entry, f32 value) {
    entry->a = 0;
    entry->b = 0;
    entry->c = 0;
    entry->value = value;
    resetDraftList(&entry->lists[0]);
    resetDraftList(&entry->lists[1]);
    resetDraftList(&entry->lists[2]);
}
void Items_ResetActorPools(DraftOwnerA370 *owner, s32 actorCount)
{
    s32 i;
    f32 initialValue;
    if (actorCount > 4) actorCount = 4;
    owner->word34 = 0;
    owner->word38 = 0;
    owner->word48 = 0;
    Pools_InitializeGameplayCamera(owner->parts);
    owner->word38 = 2;
    func_80255CA0_de(&owner->entryList, 0, 4);
    func_80255CA0_de(&owner->spareList, 0, 4);
    initialValue = D_800C32EC_de;
    for (i = 0; i < 8; i++) {
        resetDraftEntry(&owner->entries[i], initialValue);
        func_80255D14_de(&owner->entryList, &owner->entries[i]);
    }
    func_80255CA0_de(&owner->active, 0, 4);
    func_80255CA0_de(&owner->free, 0, 4);
    func_80255CA0_de(&owner->smallList, 0, 4);
    owner->empty = 1;
    func_8025E3F0_de(owner->parts);
    Cache_DrainAndCompactResources(0);
    if (owner->handle) {
        Cache_ReleaseResource(0, owner->handle);
        owner->handle = 0; owner->actors = 0; owner->count = 0;
    }
    Cache_DrainAndCompactResources(0);
    if (owner->smallHandle) {
        Cache_ReleaseResource(0, owner->smallHandle);
        owner->smallHandle = 0; owner->small = 0; owner->smallCount = 0;
    }
    if (actorCount) {
        owner->count = actorCount;
        owner->handle = Cache_AllocateResource(0, actorCount * 0xED8, 0x23, g_camerasText);
        owner->actors = *owner->handle;
        XPlus_FillMemory(owner->actors, 0, actorCount * 0xED8);
        for (i = 0; i < owner->count; i++) {
            owner->actors[i].index = i;
            func_80255D14_de(&owner->active, &owner->actors[i]);
        }
        func_8025E3F0_de(owner->actors);
        owner->empty = 0;
    }
    owner->smallCount = 16;
    owner->smallHandle = Cache_AllocateResource(0, 0x400, 0x23, D_800C32DC_de);
    owner->small = *owner->smallHandle;
    XPlus_FillMemory(owner->small, 0, 0x400);
    for (i = 0; i < owner->smallCount; i++) {
        func_80255D14_de(&owner->smallList, &owner->small[i]);
    }
}

/* Resets a 0x1208-byte actor: clears it through XPlus_FillMemory, initialises its three lists at 0xC,
   0x20 and 0xF24 through func_80255CA0_de, sets its words at 0x1200 and 0x38 to 1 and 2, clears those at
   0 to 8 and 0xF18 to 0xF20, and resets the parts at offset 0x40 through Pools_InitializeGameplayCamera and
   Camera_UpdateViewProjectionAndEffects. */

void Pools_InitializeGameplayCamera(GameplayCamera *arg0);

extern void Camera_UpdateViewProjectionAndEffects(void *);

/* Updates each of the group's items (count at 0x8, 0xED8-byte records from the address at 0x4) through
   the block at 0x570 of each, then the group's own block at 0x5B0, all with func_8044A7D0_de. */


extern void Pool_InitEntryPool(char *);

void Items_ResetPlayers(func_8044B27C_S1 *actor) {
    char *parts;

    XPlus_FillMemory(actor, 0, 0x1208);
    func_80255CA0_de(&actor->unkC, 0, 4);
    func_80255CA0_de(&actor->unk20, 0, 4);
    func_80255CA0_de(&actor->unkF24, 0, 4);
    parts = &actor->unk40;
    actor->unk1200 = 1;
    actor->unk0 = 0;
    actor->unk4 = 0;
    actor->unk8 = 0;
    actor->unkF18 = 0;
    actor->unkF1C = 0;
    actor->unkF20 = 0;
    actor->unk38 = 2;
    Pools_InitializeGameplayCamera(parts);
    Camera_UpdateViewProjectionAndEffects(parts);
}

void Pools_InitGroupPools(Triple *group) {
    int i;

    for (i = 0; i < group->z; i++) {
        Pool_InitEntryPool((char *)(i * 0xED8 + group->y + 0x570));
    }
    Pool_InitEntryPool((char *)group + 0x5B0);
}

/* Detaches the object at offset 0xC of an owner: when there is one, finalises it through
   Pools_InitializeGameplayCamera and removes it from the lists at offsets 0xC and 0x20 through func_80255ED8_de and
   func_80255D14_de. Returns the object. */



/* Calls func_80255ED8_de on offset 0x20 of an object and func_80255CB8_de on offset 0xC with the second
   argument. */



void *Pools_RecycleModel(struct Draw *owner) {
    void *object = owner->model;

    if (object != 0) {
        Pools_InitializeGameplayCamera(object);
        func_80255ED8_de(&owner->model, object);
        func_80255D14_de(&owner->recycled, object);
    }
    return object;
}

void Pools_TransferPoolEntry(char *object, void *value) {
    func_80255ED8_de(object + 0x20, value);
    func_80255CB8_de(object + 0xC, value);
}
