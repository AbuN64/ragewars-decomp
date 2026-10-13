#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022AE90.h"
#include "types.h"

/** Start the actor effect and attach optional source-specific resources; the European cartridges pick
    each resource from a per-language table. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)




extern Game_func_8022B7F8_de D_80145088;
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
extern char D_80145088;
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

extern f32 D_800C2D1C_de;

extern s32 func_8025DF34_de(s32);
extern void func_80237E80_de(void *arg0, void *arg1, void *arg2);
extern void func_802BD320_de(void *arg0, void *arg1, void *arg2);






void func_8022B7F8_de(void *arg0, void *arg1) {
    Shared_ActorView *state = arg0;
    Shared_ActorView *source = arg1;
    void *owner;
    void *payload;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Game_func_8022B7F8_de *game;
    MenuSettings *settings;
#endif

    if (state->pending != 0.0f) {
        return;
    }

    func_8025DF34_de(0xB45);
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
    func_80237E80_de(game, owner, D_800D31B4_de[settings->language]);
#else
    func_80237E80_de(&D_80145088, owner, D_800D31B4_de);
#endif
    if (source == 0) {
        return;
    }
    if (((Actor_func_8024A7A0_de *)source)->kind != 1) {
        return;
    }
    if ((((Actor_func_8024A7A0_de *)source)->flags & 0x300000) == 0) {
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
    func_80237E80_de(game, state->message, payload);
#else
    func_80237E80_de(&D_80145088, state->message, payload);
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    func_80237E80_de(game, state->message, D_800E1154[settings->language]);
#else
    func_80237E80_de(&D_80145088, state->message, D_800E1154);
#endif
#else
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    func_80237E80_de(game, state->message, D_800D31C0[settings->language]);
#else
    func_80237E80_de(&D_80145088, state->message, D_800D31C0);
#endif
#endif
}
