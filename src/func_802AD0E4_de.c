#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "span_1000/code_80233920.h"
#include "span_1000/code_802AB3FC.h"
#include "types.h"
#include "shared/menu_match_globals.h"
extern void func_80237E80_de(void *, void *, void *);
extern s32 func_8025DE54_de(s16 arg0, Vec3 position, s32 arg4, s32 arg5);


/** Apply optional resource, sound, and callback effects for an actor. */
void func_802AD0E4_de(void *arg0, void *resource, s32 sound, s32 callback) {
    if (((Shared_ActorView *)arg0)->message != 0) {
        func_802391AC_de(((Shared_ActorView *)arg0)->message,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            func_80237E80_de(&D_80145088,
                          ((Shared_ActorView *)arg0)->message,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[D_80145088.settings.language]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        func_8025DE54_de((s16)sound,
                      ((LevelActor *)arg0)->position0, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
}
