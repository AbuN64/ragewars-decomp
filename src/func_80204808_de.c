#include "span_1000/code_80203F04.h"
#include "span_1000/code_80246E34.h"
#include "common/types_1dc8418c21db.h"
#include "span_C76B0/data.h"
#include "types.h"

/* Supplies the nonnegative blend remaining after the incoming strength is
 * scaled, then applies the actor animation using the original lookup. */
struct InputRecAt40 {
    char pad0[0x40];
    f32 strength;
};
extern f32 D_800C1A74_de;
extern f32 D_800C1A78_de;
extern s32 D_800D15E0;
extern f32 D_800D15F0;
extern void func_8024A1D0_de(Actor_func_8024A1D0_de *, void *, Lookup *);

void func_80204808_de(Actor_func_8024A1D0_de *actor, struct InputRecAt40 *input, Lookup *lookup) {
    f32 remaining = D_800C1A78_de - input->strength * D_800C1A74_de;
    D_800D15E0 = 1;
    if (remaining < 0.0f) {
        remaining = 0.0f;
    }
    D_800D15F0 = remaining;
    func_8024A1D0_de(actor, input, lookup);
}
