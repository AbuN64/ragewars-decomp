#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80217388.h"
#include "common/reset_storage.h"
#include "types.h"
#include "common/unused.h"










/** Reset the object and initialize its four descending-offset records. */
void func_80218E98_de(char *arg0) {
    TeamMenu *menu = (TeamMenu *)arg0;
    s32 i;
    s32 minus_one = -1;
    f32 scale = *(&D_800C22A8_de + 1);
    f32 value = *(&D_800C9178_de + 1);

    menu->state = 0;
    menu->unused = 0;
    menu->open = 0;
    menu->reset = 0;
    menu->spin = 0;
    menu->cursor = minus_one;
    menu->count = 4;
    menu->hover = minus_one;

    for (i = 0; i < 4; i++, arg0 += 0x14) {
        f32 scaled = i * scale;
        ((SlotRecAt10 *)(arg0 + 0x1C))->unused2 = 0;
        ((SlotRecAt10 *)(arg0 + 0x1C))->scale = value;
        ((SlotRecAt10 *)(arg0 + 0x1C))->angle = -scaled;
    }
}
