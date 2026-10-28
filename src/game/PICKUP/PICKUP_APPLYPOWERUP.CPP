#include "include_asm.h"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/WORLD.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECATE.H"
#include "MENU/PICKUP_APPLYPOWERUP.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

void *Pickup_FindPowerupEntry(s32 itemId) {
    char *v1;
    s32 i;

    v1 = &g_pickupPowerupDefinitions;
    i = 3;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != itemId) {
            v1 += 0x18;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}





void *Pickup_FindAmmoEntry(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &g_pickupWeaponDefinitions;
    i = 5;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x14;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}





void *Pickup_FindHealthEntry(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &g_pickupHealthDefinitions;
    i = 7;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x18;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}





void *Pickup_FindSingleEntry(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D3368;
    i = 1;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x14;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}





void *Pickup_FindTargetedEntry(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D33C0;
    i = 0xF;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x10;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}





void *Pickup_FindSpecialEntry(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &g_pickupSpecialDefinitions;
    i = 2;
    do {
        i -= 1;
        if (((struct EntryRecAtE *)(v1))->id != arg0) {
            v1 += 0x10;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}

extern int InstHdr_GetActorType(void *prop);
extern s32 Pickup_DispatchHandler(void *actor, void *target, s32 arg2);
extern void SetN64_RecycleGlobalEffectNode(void *node);
extern void Scene_SetLevelRecordStateBit(void *arg0, void *levelBitRecord, s32 arg2);
extern void Link_DispatchObjectLinks(s32 arg0, s32 arg1, void *actor);





void Pickup_TryCollectActor(void *actor, void *pickup) {
    u16 collectedFlags;
    u16 pickupFlags;

    pickupFlags = ((struct Shared_ProjectileView *)(pickup))->flags;
    if (pickupFlags & 8) {
        if (((struct Shared_ProjectileView *)(pickup))->stateFlags & 1) {
            goto block_4;
        }
    } else if (!(pickupFlags & 1)) {
block_4:
        if (Pickup_DispatchHandler(actor, pickup, InstHdr_GetActorType(pickup)) != 0) {
            collectedFlags = ((struct Shared_ProjectileView *)(pickup))->flags | 1;
            ((struct Shared_ProjectileView *)(pickup))->flags = collectedFlags;
            if (collectedFlags & 8) {
                SetN64_RecycleGlobalEffectNode(pickup);
                return;
            }
            Scene_SetLevelRecordStateBit(&g_world, pickup, 1);
            Link_DispatchObjectLinks(((struct Shared_ProjectileView *)(pickup))->source, 0x400, actor);
        }
    }
}

#include "COMMON/MENU_MATCH_GLOBALS.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif
extern void Player_AddAmmo(void *, s16, s16);
extern s32 SoundElement_PlaySoundAtPosition(s16 track, CVector3 position, s32 arg4, s32 ownerId);


/** Apply an effect descriptor's optional setup, resource, sound, and callback. */
s32 Pickup_ApplyAmmo(void *player, void *pickupEntry) {
    void *resource;
    s32 sound;
    s32 callback;
    if (((struct EntryRecAtE *)(pickupEntry))->index != -1) {
        Player_AddAmmo(player, ((struct EntryRecAtE *)(pickupEntry))->index,
                      ((struct EntryRecAtE *)(pickupEntry))->argument);
    }

    resource = ((EntryRecAtE *)pickupEntry)->resource;
    sound = ((struct EntryRecAtE *)(pickupEntry))->sound;
    callback = ((struct EntryRecAtE *)(pickupEntry))->callback;
    if (((struct ActorPickupCanCollect *)(player))->owner != 0) {
        Gsky_StartFade(((struct ActorPickupCanCollect *)(player))->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            Camera_PostScreenMessage(&D_80145088,
                          ((struct ActorPickupCanCollect *)(player))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[g_languageIndex]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        SoundElement_PlaySoundAtPosition(sound,
                      ((ActorPickupCanCollect *)player)->position, 0, -1);
    }
    if (callback != 0) {
        SoundElement_PlayDialogGroup(callback);
    }
    return 1;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif
extern s32 Player_GetMaxHealth(void *player);


/** Advance a timed effect and apply its optional resource, sound, and callback. */
s32 Pickup_ApplyHealth(void *player, void *arg1) {
    s32 result;
    void *resource;
    s32 sound;
    s32 callback;

    result = 0;
    if (((struct ActorPickupCanCollect *)(player))->count > 0) {
        s32 limit;

        ((struct ActorPickupCanCollect *)(player))->count +=
            ((struct TimedItemEffect *)(arg1))->amount << 8;
        limit = Player_GetMaxHealth(player);
        if (((struct ActorPickupCanCollect *)(player))->count < limit) {
            limit = ((struct ActorPickupCanCollect *)(player))->count;
        }
        result = 1;
        ((struct ActorPickupCanCollect *)(player))->count = limit;
        ((struct ActorPickupCanCollect *)(player))->active = limit;
    }

    if (result != 0) {
        resource = ((EntryRecAtE *)arg1)->resource;
        sound = ((struct TimedItemEffect *)(arg1))->sound;
        callback = ((struct TimedItemEffect *)(arg1))->callback;
        if (((struct ActorPickupCanCollect *)(player))->owner != 0) {
            Gsky_StartFade(((struct ActorPickupCanCollect *)(player))->owner,
                          0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (resource != 0) {
                Camera_PostScreenMessage(&D_80145088,
                              ((struct ActorPickupCanCollect *)(player))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[g_languageIndex]);
#else
                          *(void **)resource);
#endif
            }
        }
        if (sound != 0) {
            SoundElement_PlaySoundAtPosition(sound,
                          ((ActorPickupCanCollect *)player)->position, 0, -1);
        }
        if (callback != 0) {
            SoundElement_PlayDialogGroup(callback);
        }
    }
    return result;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif




/** Apply an accumulating effect descriptor and its optional payloads. */
s32 Pickup_ApplyLifePoints(void *arg0, void *arg1) {
    void *resource;
    s32 sound;
    s32 callback;
    s32 amount;

    amount = ((struct ActorPickupCanCollect *)(arg0))->fraction +
             (u16)((struct EntryRecAtE *)(arg1))->index;
    ((struct ActorPickupCanCollect *)(arg0))->fraction = amount;
    if ((s16)amount >= 100) {
        ((struct ActorPickupCanCollect *)(arg0))->fraction = amount - 100;
        if (((struct ActorPickupCanCollect *)(arg0))->lives < 9) {
            ((struct ActorPickupCanCollect *)(arg0))->lives =
                (u16)((struct ActorPickupCanCollect *)(arg0))->lives + 1;
        }
    }

    resource = ((EntryRecAtE *)arg1)->resource;
    sound = ((struct EntryRecAtE *)(arg1))->sound;
    callback = ((struct EntryRecAtE *)(arg1))->callback;
    if (((struct ActorPickupCanCollect *)(arg0))->owner != 0) {
        Gsky_StartFade(((struct ActorPickupCanCollect *)(arg0))->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            Camera_PostScreenMessage(&D_80145088,
                          ((struct ActorPickupCanCollect *)(arg0))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[g_languageIndex]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        SoundElement_PlaySoundAtPosition(sound,
                      ((ActorPickupCanCollect *)arg0)->position, 0, -1);
    }
    if (callback != 0) {
        SoundElement_PlayDialogGroup(callback);
    }
    return 1;
}

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#include "TYPES.H"

extern void D_002AD1B4(void);
extern void D_002AD264(void);
#include "COMMON/MENU_MATCH_GLOBALS.H"

typedef struct func_802ADE28_S1 func_802ADE28_S1;
typedef struct func_802ADE28_S2 func_802ADE28_S2;
typedef struct ActivationSlot ActivationSlot;
typedef struct ActivationActor ActivationActor;
struct func_802ADE28_S1 {
    char pad0[0x18];
    func_802ADE28_S2 *unk18;
};
typedef struct EffectAmount { char pad[0xC]; f32 amount; } EffectAmount;
struct func_802ADE28_S2 { char pad[0x14]; EffectAmount payload; };
struct ActivationSlot {
    void **resource;
    u16 unk4;
    char pad4[0x6 - 0x4 - sizeof(u16)];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
};
struct ActivationActor {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5DC - 0x10 - sizeof(s32)];
    void* unk5DC;
    char pad5DC[0x670 - 0x5DC - sizeof(void*)];
    f32 unk670;
    char pad670[0x674 - 0x670 - sizeof(f32)];
    f32 unk674;
    char pad674[0x678 - 0x674 - sizeof(f32)];
    f32 unk678;
    char pad678[0xD40 - 0x678 - sizeof(f32)];
    char unkD40;
};

/** Apply a scripted effect command and its optional sound callbacks. */
s32 Pickup_ApplyPowerup(ActivationActor *arg0, ActivationSlot *arg1, func_802ADE28_S1 *arg2) {
    void **resource;
    EffectAmount *state_value;
    s32 sound;
    s32 callback;
    s16 command;

    state_value = &arg2->unk18->payload;
    command = arg1->unk4 - 0x708;
    switch (command) {
    case 0:
        arg0->unk670 = 120.0f;
        break;
    case 1:
        arg0->unk674 = 120.0f;
        break;
    case 2:
    case 3:
        arg0->unk678 += state_value->amount;
        break;
    case 7:
        ItemMenu_SetEntry(&arg0->unkD40, 1, 0, 0x7FD,
                       0, 0, 0, D_002AD1B4, D_002AD264);
        break;
    
    default: break;
    }

    resource = arg1->resource;
    sound = arg1->unk6;
    callback = arg1->unk8;
    if (arg0->unk5DC != 0) {
        Gsky_StartFade(arg0->unk5DC,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            Camera_PostScreenMessage(&D_80145088,
                          arg0->unk5DC,
                          *resource);
        }
    }
    if (sound != 0) {
        SoundElement_PlaySoundAtPosition(sound,
                      *(CVector3 *)&arg0->unk8, 0, -1);
    }
    if (callback != 0) {
        SoundElement_PlayDialogGroup(callback);
    }
    return 1;
}
#endif
