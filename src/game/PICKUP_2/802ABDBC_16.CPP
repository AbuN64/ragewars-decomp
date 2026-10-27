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

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

extern void Player_AddAmmo(void *, s16, s16);




/** Apply a three-channel effect descriptor and its optional payloads. */
s32 Pickup_ApplyAmmoBundle(ActorPickupCanCollect *arg0, MultiChannelItemEffect *arg1) {
    void *resource;
    s32 sound;
    s32 callback;

    Player_AddAmmo(arg0, 0, arg1->effect.index);
    Player_AddAmmo(arg0, 1, arg1->effect.argument);
    Player_AddAmmo(arg0, 2, arg1->third);

    resource = arg1->effect.resource;
    sound = arg1->effect.sound;
    callback = arg1->effect.callback;
    if (arg0->owner != 0) {
        Sky_StartFade(arg0->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            Camera_PostScreenMessage(&D_80145088,
                          arg0->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[g_languageIndex]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        SoundElement_PlaySoundAtPosition(sound,
                      arg0->position, 0, -1);
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

    v1 = (char *)D_800D34C0;
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
        Sky_StartFade(((Shared_ActorView *)arg0)->message,
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
        value = GraphU64_RandomFloat(input);
        threshold = (&D_800C62E0)[1];
        if (!(threshold <= value)) {
            converted = (s32)value;
        } else {
            converted = (s32)(value - threshold) | 0x80000000;
        }
        Sky_StartFade(arg0->message, 0xFF, 0xFF, 0xFF,
                      0xFF, (u8)converted, 1, 0);
    }
    return 1;
}
