#include "types.h"

/* Steps an object's nesting count at 0x1C up and back down while it is nonzero, each step bracketed by func_802BCF30_de and __osRestoreInt: going up past one calls func_802BB2A0_de, and coming down to anything but zero calls func_802BB420_de. */
typedef struct Object {
    char pad0[0x1C];
    s32 depth;
} Object;

extern s32 func_802BCF30_de(void);
extern void __osRestoreInt(s32);
extern void func_802BB2A0_de(Object *, s32, s32);
extern void func_802BB420_de(Object *, s32, s32);

void func_802566E8_de(Object *obj) {
    s32 mask;
    s32 mask2;

    if (obj->depth == 0) {
        return;
    }
    mask = func_802BCF30_de();
    if (++obj->depth != 1) {
        __osRestoreInt(mask);
        func_802BB2A0_de(obj, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    mask2 = func_802BCF30_de();
    if (--obj->depth != 0) {
        __osRestoreInt(mask2);
        func_802BB420_de(obj, 0, 1);
        return;
    }
    __osRestoreInt(mask2);
}
