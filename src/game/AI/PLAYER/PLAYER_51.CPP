#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "TYPES.H"
#include "sdk/AUDIO/802BD1A8_19.H"
#include "RENDER/8025DE50_5.H"
#include "COMMON/CHANNEL.H"

/** Start the actor effect and attach optional source-specific resources; the European cartridges pick
    each resource from a per-language table. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)




extern void *D_800D31B4_de[];
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void *D_800E1144[];
#else
extern void *D_800D31BC[];
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void *D_800E1154[];
#else
extern void *D_800D31C0[];
#endif
#else
extern void *D_800D31B4_de;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void *D_800E1144;
#else
extern void *D_800D31BC;
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void *D_800E1154;
#else
extern void *D_800D31C0;
#endif
#endif







void Player_StartSourceEffect(void *actor, void *effectSource) {
    Shared_ActorView *state = actor;
    Shared_ActorView *source = effectSource;
    void *owner;
    void *payload;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    MenuMatchGlobals *game;
    MenuSettings *settings;
#endif

    if (state->pending != 0.0f) {
        return;
    }

    SoundElement_PlayFlatSound(0xB45);
    state->pending = D_800C2D1C_de;
    state->parent = source;
    owner = state->message;
    if (owner == 0) {
        return;
    }

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    game = &D_80145088;
    settings = &game->settings;
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Camera_PostScreenMessage(game, owner, D_800D31B4_de[settings->language]);
#else
    Camera_PostScreenMessage(&D_80145088, owner, D_800D31B4_de);
#endif
    if (source == 0) {
        return;
    }
    if (((LevelActor *)source)->kind != 1) {
        return;
    }
    if ((((LevelActor *)source)->flags & 0x300000) == 0) {
        return;
    }

    payload = state->effectPayload;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    func_802BD320_de(payload, D_800E1144[settings->language],
#else
    func_802BD320_de(payload, D_800E1144,
#endif
#else
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    func_802BD320_de(payload, D_800D31BC[settings->language],
#else
    func_802BD320_de(payload, D_800D31BC,
#endif
#endif
                  source->controls->pad84);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Camera_PostScreenMessage(game, state->message, payload);
#else
    Camera_PostScreenMessage(&D_80145088, state->message, payload);
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Camera_PostScreenMessage(game, state->message, D_800E1154[settings->language]);
#else
    Camera_PostScreenMessage(&D_80145088, state->message, D_800E1154);
#endif
#else
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Camera_PostScreenMessage(game, state->message, D_800D31C0[settings->language]);
#else
    Camera_PostScreenMessage(&D_80145088, state->message, D_800D31C0);
#endif
#endif
}
