#include "include_asm.h"
#include "COMMON/STATEPAIR.H"
#include "TYPES.H"
#include "RESMGR/802A2230_4.H"
#include "SCENE/802508E0_13.H"

/* Advances the object's state timer at 0x48 while its state at 0x5C is 0 or 1, and after ten ticks invokes that state's transition, func_802A1D14_de(obj) or func_802A1D7C_de(obj, obj); returns 0. */




extern void func_802A1D7C_de(struct CommandListController *, struct CommandListController *);


s32 func_802A1FE8_de(struct CommandListController *obj) {
    struct CommandListController *self = obj; /* FAKEMATCH: copy-only local steers obj into a1 */

    switch (obj->state) {
    case 0:
        if (++obj->progress > 10) {
            func_802A1D14_de(obj);
        }
        break;
    case 1:
        if (++obj->progress > 10) {
            func_802A1D7C_de(obj, self);
        }
        break;
    case 2:
        break;
    }
    return 0;
}

s32 func_802A206C_de(void *arg0) {
    func_802547E4_de(arg0);
    return 0;
}

#if defined(VERSION_US)
unsigned int func_802A206C_de_padding_A2BCC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802A206C_de_padding_A2DDC[1] = {
    0x00000000,
};
#endif
