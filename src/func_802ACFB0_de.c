#include "span_1000/code_80233920.h"
#include "span_1000/code_802AB3FC.h"
#include "types.h"

#include "shared/menu_match_globals.h"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
extern void func_80222BE8_de(void *, s16, s16);
extern void func_80237E80_de(void *, void *, void *);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);







/** Apply a three-channel effect descriptor and its optional payloads. */
s32 func_802ACFB0_de(Actor_func_802AB400_de *arg0, MultiChannelItemEffect *arg1) {
    void *resource;
    s32 sound;
    s32 callback;

    func_80222BE8_de(arg0, 0, arg1->effect.index);
    func_80222BE8_de(arg0, 1, arg1->effect.argument);
    func_80222BE8_de(arg0, 2, arg1->third);

    resource = arg1->effect.resource;
    sound = arg1->effect.sound;
    callback = arg1->effect.callback;
    if (arg0->owner != 0) {
        func_802391AC_de(arg0->owner,
                      0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (resource != 0) {
            func_80237E80_de(&D_80145088,
                          arg0->owner,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                          ((void **)resource)[D_80152789]);
#else
                          *(void **)resource);
#endif
        }
    }
    if (sound != 0) {
        func_8025DE54_de(sound,
                      arg0->position, 0, -1);
    }
    if (callback != 0) {
        func_8025E11C_de(callback);
    }
    return 1;
}
