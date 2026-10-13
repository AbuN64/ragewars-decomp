#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022C894.h"
#include "types.h"
#include "shared/level_actor.h"
/** Scales the floats at 0x6C0 and 0x6C4 of the first object and the float at 0x20 of the second by D_800C7E90. */








void func_8022D010_de(void *arg0, void *arg1) {
    Actor_func_8022D290_de *actor = arg0;
    Actor_func_8024A7A0_de *other = arg1;
    actor->unk_0x06C0 = actor->unk_0x06C0 * (D_800C7E90);
    actor->unk_0x06C4 = actor->unk_0x06C4 * (D_800C7E90);
    other->position1.y = other->position1.y * (D_800C7E90);
}
