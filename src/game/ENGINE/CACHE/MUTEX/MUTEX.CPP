#include "include_asm.h"
#include "TYPES.H"
#include "sdk/os.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CARTRIDGEREADWORKER.H"

#if !defined(VERSION_US)
/* Steps an object's nesting count at 0x1C up and back down while it is nonzero, each step bracketed by func_802BCF30_de and __osRestoreInt: going up past one calls func_802BB2A0_de, and coming down to anything but zero calls func_802BB420_de. */
typedef struct Object {
    char pad0[0x1C];
    s32 depth;
} Object;


void Mutex_WaitUntilReleased(Object *obj) {
    s32 mask;
    s32 mask2;

    if (obj->depth == 0) {
        return;
    }
    mask = __osDisableInt();
    if (++obj->depth != 1) {
        __osRestoreInt(mask);
        osRecvMesg(obj, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    mask2 = __osDisableInt();
    if (--obj->depth != 0) {
        __osRestoreInt(mask2);
        osSendMesg(obj, 0, 1);
        return;
    }
    __osRestoreInt(mask2);
}
#endif

void Mutex_InitializeQueueLock(void *menuRules) {
    (((struct MenuRules *) ((s8 *) menuRules))->locked) = 0;
    osCreateMesgQueue(menuRules, menuRules + 0x18, 1);
}
