#include "COMMON/ENTRYRECATE.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"
#include "MENU/802ABDBC_16.H"
#include "COMMON/CHANNEL.H"
#include "include_asm.h"
#include "COMMON/RESPONSE.H"
#include "MENU/CODE_802AE254.H"

/* 802ABDBC_16.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

extern void Player_AddAmmo(void *, s16, s16);

/** Apply a three-channel effect descriptor and its optional payloads. */
s32 Pickup_ApplyAmmoBundle(ActorPickupCanCollect *player, MultiChannelItemEffect *ammoBundle) {
    void *resource;
    s32 sound;
    s32 callback;

    Player_AddAmmo(player, 0, ammoBundle->effect.index);
    Player_AddAmmo(player, 1, ammoBundle->effect.argument);
    Player_AddAmmo(player, 2, ammoBundle->third);

    resource = ammoBundle->effect.resource;
    sound = ammoBundle->effect.sound;
    callback = ammoBundle->effect.callback;
    if (player->owner != 0) {
        Gsky_StartFade(player->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            Camera_PostScreenMessage(&D_80145088,
                          player->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[g_languageIndex]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        SoundElement_PlaySoundAtPosition(sound,
                      player->position, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
    return 1;
}

void *Pickup_FindBonusEntry(s32 arg0) {
    char *v1;
    s32 i;
    Shared_struct_D_800D34C0_0x18 *record;

    v1 = (char *)g_pickupAmmoDefinitions;
    i = 0xF;
    do {
        record = (Shared_struct_D_800D34C0_0x18 *)v1;
        i -= 1;
        if (record->id != arg0) {
            v1 += 0x18;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}

/** Apply optional resource, sound, and callback effects for an actor. */
void Pickup_ShowFeedback(void *arg0, void *resource, s32 sound, s32 callback) {
    if (((Shared_ActorView *)arg0)->message != 0) {
        Gsky_StartFade(((Shared_ActorView *)arg0)->message,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            Camera_PostScreenMessage(&D_80145088,
                          ((Shared_ActorView *)arg0)->message,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[D_80145088.settings.language]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        SoundElement_PlaySoundAtPosition((s16)sound,
                      ((LevelActor *)arg0)->position0, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
}

s32 Pickup_ToggleEffectAndFlash(Shared_ActorView *arg0) {
    f32 value;
    f32 input;
    f32 threshold;
    u32 converted;

    arg0->field16D4 =
        arg0->field16D4 == 0;
    if (arg0->message != 0) {
        input = D_800C62E0;
        ((RacerViewport *)arg0->message)->pad124 = 0;
        value = Graphu64_RandomFloat(input);
        threshold = (&D_800C62E0)[1];
        if (!(threshold <= value)) {
            converted = (s32)value;
        } else {
            converted = (s32)(value - threshold) | 0x80000000;
        }
        Gsky_StartFade(arg0->message, 0xFF, 0xFF, 0xFF,
                      0xFF, (u8)converted, 1, 0);
    }
    return 1;
}

/* CODE_802AE254.CPP */
/** Return the one status used by callers. */
int Pickup_HandleItemUpdate(void) {
    return 1;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802AD19C[1] = {
    0x5F437572,
};
#endif

#if defined(VERSION_DE)
unsigned int func_802AD264_de_padding_ADE6C[1] = {
    0x00000000,
};
#endif
