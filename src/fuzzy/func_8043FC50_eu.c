#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "types.h"
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
    D_801468B0 = D_800E2390;
    arg0->owner->flags &= 0xFBFFFFFF;
}
