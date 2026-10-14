#include "shared/level_actor.h"
#include "span_1000/code_80204E78.h"
#include "span_1000/code_80246E34.h"
#include "types.h"

extern void func_8026DC24_de(void **, s32, s32, void *, s32, s32);
extern s32 D_800D297C;

/* Draw callback installed by func_8020520C_de; the animation lookup is
 * the same third callback argument consumed by func_8024A1D0_de. */
void func_80205628_de(void *arg0, void *arg1, void *arg2) {
    LevelActor *actor = arg0;
    SpawnDispatchOwner *owner = arg1;
    Lookup *lookup = arg2;

    actor->mask = 1 << owner->spawn;
    if (lookup->unk0 != 0) {
        func_8026DC24_de(lookup->value, actor->fieldB4, 1,
                        &actor->lighting[D_800D297C], 0, owner->remaining);
    }
}
