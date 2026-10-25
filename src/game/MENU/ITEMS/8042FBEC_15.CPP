#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "TYPES.H"
extern f32 D_800E2390;

typedef struct FlagOwner_func_8043FC50_eu {
    char pad0[0x30];
    u32 flags;
} FlagOwner_func_8043FC50_eu;

typedef struct Holder_func_8043FC50_eu {
    char pad0[0xC];
    FlagOwner_func_8043FC50_eu *owner;
} Holder_func_8043FC50_eu;

void func_8043FC50_eu(Holder_func_8043FC50_eu *arg0) {
    D_801462C8.counters.countdown = D_800E2390;
    arg0->owner->flags &= 0xFBFFFFFF;
}
#else
INCLUDE_ASM("ovl_80400000", func_8043FC50_eu);
#endif
#endif
