#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/WORLD.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECATE.H"
#include "MENU/802ABDBC.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

void *func_802AC91C_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D31D0;
    i = 3;
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





void *func_802AC950_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D3230;
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





void *func_802AC984_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D32A8;
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





void *func_802AC9B8_de(s32 arg0) {
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





void *func_802AC9EC_de(s32 arg0) {
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





void *func_802ACA20_de(s32 arg0) {
    char *v1;
    s32 i;

    v1 = &D_800D3390;
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

extern int InstHdr_GetActorType(void *arg0);
extern s32 func_802AB6EC_de(void *arg0, void *arg1, s32 arg2);
extern void func_80290548_de(void *arg0);
extern void func_8028B898_de(void *arg0, void *arg1, s32 arg2);
extern void func_80278E04_de(s32 arg0, s32 arg1, void *arg2);





void func_802ACA54_de(void *arg0, void *arg1) {
    u16 temp_v0;
    u16 temp_v1;

    temp_v1 = ((struct Shared_ProjectileView *)(arg1))->flags;
    if (temp_v1 & 8) {
        if (((struct Shared_ProjectileView *)(arg1))->stateFlags & 1) {
            goto block_4;
        }
    } else if (!(temp_v1 & 1)) {
block_4:
        if (func_802AB6EC_de(arg0, arg1, InstHdr_GetActorType(arg1)) != 0) {
            temp_v0 = ((struct Shared_ProjectileView *)(arg1))->flags | 1;
            ((struct Shared_ProjectileView *)(arg1))->flags = temp_v0;
            if (temp_v0 & 8) {
                func_80290548_de(arg1);
                return;
            }
            func_8028B898_de(&g_world, arg1, 1);
            func_80278E04_de(((struct Shared_ProjectileView *)(arg1))->source, 0x400, arg0);
        }
    }
}

#include "COMMON/MENU_MATCH_GLOBALS.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif
extern void Player_AddAmmo(void *, s16, s16);
extern s32 SoundElement_PlaySoundAtPosition(s16 arg0, CVector3 position, s32 arg4, s32 arg5);


/** Apply an effect descriptor's optional setup, resource, sound, and callback. */
s32 func_802ACB18_de(void *arg0, void *arg1) {
    void *resource;
    s32 sound;
    s32 callback;
    if (((struct EntryRecAtE *)(arg1))->index != -1) {
        Player_AddAmmo(arg0, ((struct EntryRecAtE *)(arg1))->index,
                      ((struct EntryRecAtE *)(arg1))->argument);
    }

    resource = ((EntryRecAtE *)arg1)->resource;
    sound = ((struct EntryRecAtE *)(arg1))->sound;
    callback = ((struct EntryRecAtE *)(arg1))->callback;
    if (((struct Actor_func_802AB400_de *)(arg0))->owner != 0) {
        Sky_StartFade(((struct Actor_func_802AB400_de *)(arg0))->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            Camera_PostScreenMessage(&D_80145088,
                          ((struct Actor_func_802AB400_de *)(arg0))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[g_languageIndex]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        SoundElement_PlaySoundAtPosition(sound,
                      ((Actor_func_802AB400_de *)arg0)->position, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
    return 1;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif
extern s32 Player_GetMaxHealth(void *arg0);
extern s32 SoundElement_PlaySoundAtPosition(s16 arg0, CVector3 position, s32 arg4, s32 arg5);


/** Advance a timed effect and apply its optional resource, sound, and callback. */
s32 func_802ACC04_de(void *arg0, void *arg1) {
    s32 result;
    void *resource;
    s32 sound;
    s32 callback;

    result = 0;
    if (((struct Actor_func_802AB400_de *)(arg0))->count > 0) {
        s32 limit;

        ((struct Actor_func_802AB400_de *)(arg0))->count +=
            ((struct TimedItemEffect *)(arg1))->amount << 8;
        limit = Player_GetMaxHealth(arg0);
        if (((struct Actor_func_802AB400_de *)(arg0))->count < limit) {
            limit = ((struct Actor_func_802AB400_de *)(arg0))->count;
        }
        result = 1;
        ((struct Actor_func_802AB400_de *)(arg0))->count = limit;
        ((struct Actor_func_802AB400_de *)(arg0))->active = limit;
    }

    if (result != 0) {
        resource = ((EntryRecAtE *)arg1)->resource;
        sound = ((struct TimedItemEffect *)(arg1))->sound;
        callback = ((struct TimedItemEffect *)(arg1))->callback;
        if (((struct Actor_func_802AB400_de *)(arg0))->owner != 0) {
            Sky_StartFade(((struct Actor_func_802AB400_de *)(arg0))->owner,
                          0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (resource != 0) {
                Camera_PostScreenMessage(&D_80145088,
                              ((struct Actor_func_802AB400_de *)(arg0))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[g_languageIndex]);
#else
                          *(void **)resource);
#endif
            }
        }
        if (sound != 0) {
            SoundElement_PlaySoundAtPosition(sound,
                          ((Actor_func_802AB400_de *)arg0)->position, 0, -1);
        }
        if (callback != 0) {
            func_8025E11C_de(callback);
        }
    }
    return result;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif
extern s32 SoundElement_PlaySoundAtPosition(s16 arg0, CVector3 position, s32 arg4, s32 arg5);




/** Apply an accumulating effect descriptor and its optional payloads. */
s32 func_802ACD28_de(void *arg0, void *arg1) {
    void *resource;
    s32 sound;
    s32 callback;
    s32 amount;

    amount = ((struct Actor_func_802AB400_de *)(arg0))->fraction +
             (u16)((struct EntryRecAtE *)(arg1))->index;
    ((struct Actor_func_802AB400_de *)(arg0))->fraction = amount;
    if ((s16)amount >= 100) {
        ((struct Actor_func_802AB400_de *)(arg0))->fraction = amount - 100;
        if (((struct Actor_func_802AB400_de *)(arg0))->lives < 9) {
            ((struct Actor_func_802AB400_de *)(arg0))->lives =
                (u16)((struct Actor_func_802AB400_de *)(arg0))->lives + 1;
        }
    }

    resource = ((EntryRecAtE *)arg1)->resource;
    sound = ((struct EntryRecAtE *)(arg1))->sound;
    callback = ((struct EntryRecAtE *)(arg1))->callback;
    if (((struct Actor_func_802AB400_de *)(arg0))->owner != 0) {
        Sky_StartFade(((struct Actor_func_802AB400_de *)(arg0))->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            Camera_PostScreenMessage(&D_80145088,
                          ((struct Actor_func_802AB400_de *)(arg0))->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[g_languageIndex]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        SoundElement_PlaySoundAtPosition(sound,
                      ((Actor_func_802AB400_de *)arg0)->position, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
    return 1;
}

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#include "TYPES.H"

extern void D_002AD1B4(void);
extern void D_002AD264(void);
#include "COMMON/MENU_MATCH_GLOBALS.H"
extern void func_802A6FB8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6, void (*arg7)(void), void (*arg8)(void));

typedef struct func_802ADE28_S1 func_802ADE28_S1;
typedef struct func_802ADE28_S2 func_802ADE28_S2;
typedef struct RecCode80213ED480216BF4 RecCode80213ED480216BF4;
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
struct RecCode80213ED480216BF4 {
    char pad0[0xC];
    f32 unkC;
};

/** Apply a scripted effect command and its optional sound callbacks. */
s32 func_802ACE38_de(ActivationActor *arg0, ActivationSlot *arg1, func_802ADE28_S1 *arg2) {
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
        func_802A6FB8_de(&arg0->unkD40, 1, 0, 0x7FD,
                       0, 0, 0, D_002AD1B4, D_002AD264);
        break;
    
    default: break;
    }

    resource = arg1->resource;
    sound = arg1->unk6;
    callback = arg1->unk8;
    if (arg0->unk5DC != 0) {
        Sky_StartFade(arg0->unk5DC,
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
        func_8025E11C_de(callback);
    }
    return 1;
}
#endif
