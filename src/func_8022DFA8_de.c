#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022D944.h"
#include "types.h"
/* Updates a player's charge effect: cancels the charge and moves its effect to state 3 when the
   current weapon's entry in D_800D052C has no ammunition, the charge is off, or D_801468F4 is set with
   the player's controller flag at 0x8F; while the button at 0x5E4 is held and charging it targets
   D_800C7EF4, then runs the effect through func_80219480_de, eases the level toward the target by half
   through func_80274870_de and clears a level below D_800C7EF8 once the target is zero. */

extern void *D_800D052C[];
extern s32 D_801468F4;


extern void func_80219480_de(void *, void *);
extern void func_80274870_de(f32 *, f32, f32);








void func_8022DFA8_de(void *arg0) {
    f32 target;
    char *effect;
    s32 state;

    target = 0.0f;
    effect = &((ObjectLinks87C *)(arg0))->unk_878;
    if (((struct Shape_typemap_14 *)(D_800D052C[((ObjectLinks87C *)(arg0))->unk_62E]))->field_8 <= 0
        || ((ObjectLinks87C *)(arg0))->unk_7E8 == 0
        || (D_801468F4 != 0 && ((struct ObjRecAt8F *) ((ObjectLinks87C *) arg0)->unk_5D8)->unk8F != 0)) {
        do {
            ((ObjectLinks87C *)(arg0))->unk_7E8 = 0;
            state = ((Shared_Effect *)(effect))->state;
        } while (0);
        if (state != 0 && state != 3) {
            ((Shared_Effect *)(effect))->state = 3;
        }
    }
    if (((ObjectLinks87C *)(arg0))->unk_5E4 != 0 && ((ObjectLinks87C *)(arg0))->unk_7E8 != 0) {
        target = D_800C7EF4;
        ((ObjectLinks87C *)(arg0))->unk_7E8 = 1;
    }
    ((ObjectLinks87C *)(arg0))->unk_7F0 = target;
    func_80219480_de(&((ObjectLinks87C *)(arg0))->unk_878, arg0);
    func_80274870_de(&((ObjectLinks87C *)(arg0))->unk_7EC, target, 0.5f);
    if (target == 0.0f && ((ObjectLinks87C *)(arg0))->unk_7EC < D_800C7EF8) {
        ((ObjectLinks87C *)(arg0))->unk_7EC = 0.0f;
    }
}
