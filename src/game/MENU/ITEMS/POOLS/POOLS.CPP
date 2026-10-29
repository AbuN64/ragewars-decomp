#include "include_asm.h"
#include "COMMON/LONE/HUD_REFERENCE_VIEWPORT_HEIGHT.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJB.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "RESMGR/X_PLUS.H"
#include "MENU/SCENE_RESOURCE_PREVIEW_AND_COLLISION_VIEWS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "SYSTEM/LIST.H"
#include "SYSTEM/LIST.H"

/* Initializes camera transforms, viewport state, clipping records, and resource lists. */


void Sky_InitializeLensFlareState(void *);                               /* extern */
void Gsky_SetGameplayMode(void *, s32);                         /* extern */
void Gsky_ResetFadeState(void *);                            /* extern */
void Gsky_InitializeMessageEntryPool(void *);                            /* extern */
void Graphu64_IdentityMatrix(void *);                            /* extern */
void Menu_InitMenuMessageList(void *);                    /* extern */


extern s32 g_hudReferenceViewportWidth;






/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x20, 0x24], gap at: 0x18. */
void Pools_InitializeGameplayCamera(GameplayCamera *camera) {
    f32 unitValue;
    f32 zero;
    s16 viewportExtent;
    s32 viewportIndex;
    Floats *orientationValues;
    Floats *transformDefaults;
    Floats *firstEffectDefaults;
    Floats *secondEffectDefaults;
    Floats *thirdEffectDefaults;

    Sky_InitializeLensFlareState(((void *)&((GameplayCamera *)camera)->bobSuppressed));
    Graphu64_IdentityMatrix(((GameplayCamera *)camera)->viewOrient);
    Graphu64_IdentityMatrix(((GameplayCamera *)camera)->viewProjection);
    zero = 0.0f;
    unitValue = 1.0f;
    orientationValues = ((void *)&((GameplayCamera *)camera)->orientation);
    orientationValues->unk8 = zero;
    orientationValues->unk4 = zero;
    camera->orientation.x = zero;
    camera->orientation.w = unitValue;
    Graphu64_IdentityMatrix(((GameplayCamera *)camera)->inverseViewOrient);
    camera->viewWidth = (f32) g_hudReferenceViewportWidth;
    camera->viewHeight = (f32) g_hudReferenceViewportHeight;
    camera->unk518 = -1;
    camera->viewLeft = zero;
    camera->viewTop = zero;
    camera->unk520 = 0;
    camera->unk524 = 0;
    camera->unk521 = 0;
    camera->unk525 = 0;
    camera->unk522 = 0;
    camera->unk526 = 0;
    camera->unk523 = 0;
    camera->unk527 = 0;
    camera->unk51C = unitValue;
    camera->fogNear = 0x3E3;
    camera->unk540 = 0x3E3;
    camera->unk548 = 0;
    camera->dirty = 0;
    camera->pixelXScale = unitValue;
    camera->pixelYScale = unitValue;
    camera->farPlane = (f32) 1024.0f;
    camera->unk52C = (f32) 1024.0f;
    camera->unk530 = (f32) 47.5f;
    camera->unk534 = (f32) 47.5f;
    Gsky_ResetFadeState(camera);
    transformDefaults = ((void *)&((GameplayCamera *)camera)->padA0);
    camera->shakeHorizontal = zero;
    camera->shakeVertical = zero;
    transformDefaults->unk8 = zero;
    transformDefaults->unkC = zero;
    transformDefaults->unk10 = zero;
    transformDefaults->unk14 = unitValue;
    firstEffectDefaults = ((void *)&((GameplayCamera *)camera)->shakeAxisX);
    firstEffectDefaults->unk4 = zero;
    firstEffectDefaults->unk8 = zero;
    firstEffectDefaults->unkC = zero;
    firstEffectDefaults->unk10 = zero;
    secondEffectDefaults = ((void *)&((GameplayCamera *)camera)->shakeAxisY);
    secondEffectDefaults->unk4 = zero;
    secondEffectDefaults->unk8 = zero;
    secondEffectDefaults->unkC = zero;
    secondEffectDefaults->unk10 = zero;
    thirdEffectDefaults = ((void *)&((GameplayCamera *)camera)->shakeAxisZ);
    thirdEffectDefaults->unk4 = zero;
    thirdEffectDefaults->unk8 = zero;
    thirdEffectDefaults->unkC = zero;
    thirdEffectDefaults->unk10 = zero;
    Gsky_SetGameplayMode(camera, 0);
    viewportExtent = g_hudReferenceViewportWidth * 2;
    for (viewportIndex = 0; viewportIndex < 2; viewportIndex++) {
        ((RacerViewport *)camera)->viewports[viewportIndex].vscale[0] = viewportExtent;
        ((RacerViewport *)camera)->viewports[viewportIndex].vscale[1] = viewportExtent;
        ((RacerViewport *)camera)->viewports[viewportIndex].vscale[2] = 0x3FF;
        ((RacerViewport *)camera)->viewports[viewportIndex].vscale[3] = 0;
        ((RacerViewport *)camera)->viewports[viewportIndex].vtrans[0] = viewportExtent;
        ((RacerViewport *)camera)->viewports[viewportIndex].vtrans[1] = viewportExtent;
        ((RacerViewport *)camera)->viewports[viewportIndex].vtrans[2] = 0;
        ((RacerViewport *)camera)->viewports[viewportIndex].vtrans[3] = 0;
    }
    Menu_InitMenuMessageList(((void *)&((GameplayCamera *)camera)->messageList));
    Graphu64_IdentityMatrix(((GameplayCamera *)camera)->faceScreen);
    Graphu64_IdentityMatrix(((GameplayCamera *)camera)->faceScreenUpright);
    camera->fadeEnabled = 0;
    camera->monochrome = 0;
    camera->kickStep = 0x32;
    camera->unk126 = 0;
    g_cameraFramingTransitionTimer = 0;
    List_InitializeIntrusive(&((GameplayCamera *)camera)->objects, 0, 4);
    Gsky_InitializeMessageEntryPool(camera);
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
extern f32 k_menuInitialCounterValue;
extern char g_camerasText[];
extern char g_screenMessageAllocationLabel[];
extern void SoundElement_SetListenerCamera(void *);
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
void Pools_ResetActorPools(DraftOwnerA370 *owner, s32 actorCount)
{
    s32 i;
    f32 initialValue;
    if (actorCount > 4) actorCount = 4;
    owner->word34 = 0;
    owner->word38 = 0;
    owner->word48 = 0;
    Pools_InitializeGameplayCamera(owner->parts);
    owner->word38 = 2;
    List_InitializeIntrusive(&owner->entryList, 0, 4);
    List_InitializeIntrusive(&owner->spareList, 0, 4);
    initialValue = k_menuInitialCounterValue;
    for (i = 0; i < 8; i++) {
        resetDraftEntry(&owner->entries[i], initialValue);
        List_AppendIntrusive(&owner->entryList, &owner->entries[i]);
    }
    List_InitializeIntrusive(&owner->active, 0, 4);
    List_InitializeIntrusive(&owner->free, 0, 4);
    List_InitializeIntrusive(&owner->smallList, 0, 4);
    owner->empty = 1;
    SoundElement_SetListenerCamera(owner->parts);
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
            List_AppendIntrusive(&owner->active, &owner->actors[i]);
        }
        SoundElement_SetListenerCamera(owner->actors);
        owner->empty = 0;
    }
    owner->smallCount = 16;
    owner->smallHandle = Cache_AllocateResource(0, 0x400, 0x23, g_screenMessageAllocationLabel);
    owner->small = *owner->smallHandle;
    XPlus_FillMemory(owner->small, 0, 0x400);
    for (i = 0; i < owner->smallCount; i++) {
        List_AppendIntrusive(&owner->smallList, &owner->small[i]);
    }
}

/* Resets a 0x1208-byte actor: clears it through XPlus_FillMemory, initialises its three lists at 0xC,
   0x20 and 0xF24 through List_InitializeIntrusive, sets its words at 0x1200 and 0x38 to 1 and 2, clears those at
   0 to 8 and 0xF18 to 0xF20, and resets the parts at offset 0x40 through Pools_InitializeGameplayCamera and
   Camera_UpdateViewProjectionAndEffects. */

void Pools_InitializeGameplayCamera(GameplayCamera *camera);

extern void Camera_UpdateViewProjectionAndEffects(void *);

/* Updates each of the group's items (count at 0x8, 0xED8-byte records from the address at 0x4) through
   the block at 0x570 of each, then the group's own block at 0x5B0, all with func_8044A7D0_de. */


extern void Pool_InitEntryPool(char *);

void Pools_ResetPlayers(MenuPlayerPoolView *actor) {
    char *parts;

    XPlus_FillMemory(actor, 0, 0x1208);
    List_InitializeIntrusive(&actor->active, 0, 4);
    List_InitializeIntrusive(&actor->available, 0, 4);
    List_InitializeIntrusive(&actor->auxiliaryEntries, 0, 4);
    parts = &actor->cameraStorage;
    actor->unk1200 = 1;
    actor->actorHandle = 0;
    actor->actors = 0;
    actor->actorCount = 0;
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
   Pools_InitializeGameplayCamera and removes it from the lists at offsets 0xC and 0x20 through List_RemoveIntrusive and
   List_AppendIntrusive. Returns the object. */



/* Calls List_RemoveIntrusive on offset 0x20 of an object and List_PrependIntrusive on offset 0xC with the second
   argument. */



void *Pools_RecycleModel(struct Draw *owner) {
    void *object = owner->model;

    if (object != 0) {
        Pools_InitializeGameplayCamera(object);
        List_RemoveIntrusive(&owner->model, object);
        List_AppendIntrusive(&owner->recycled, object);
    }
    return object;
}

void Pools_TransferPoolEntry(char *object, void *value) {
    List_RemoveIntrusive(object + 0x20, value);
    List_PrependIntrusive(object + 0xC, value);
}
