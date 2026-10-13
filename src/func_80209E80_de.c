#include "span_1000/code_80209AE8.h"
#include "types.h"
#include "span_1000/code_8022C894.h"


extern s32 D_800C87F0;
extern char D_800F3D20;












void func_80209E80_de(void *arg0)
{
    /* Dispatch the current actor mode through its per-type behavior table. */
    void *state;
    s32 mode;
    s32 type;
    Actor_func_8022D290_de *actor;

    state = arg0;
    if (state == 0) {
        return;
    }
    actor = *(Actor_func_8022D290_de **)state;
    if (0.0f < actor->unk_0x11D8) {
        return;
    }

    mode = actor->unk_0x0594;
    type = actor->unk_0x062E;
    mode -= 1;
    {
        u32 dispatch = *(&D_800C87F0 + mode + type * 2);
        if (dispatch >= 9) {
            return;
        }
        switch (dispatch) {
        case 0: goto case_0;
        case 1: goto case_0;
        case 2: goto case_0;
        case 3: goto case_0;
        case 4: goto case_1;
        case 5: goto case_3;
        case 6: goto case_5;
        case 7: goto case_4;
        case 8: goto case_2;
        }
    }
case_0:
        func_8020A6D8_de(state, &D_800F3D20 + type * 0x38 + mode * 0x1C);
        goto dispatched;
case_1:
        func_8020A7B0_de(state, &D_800F3D20 + type * 0x38 + mode * 0x1C);
        goto dispatched;
case_2:
        ((ObjectLinks2EC *)state)->unk_240 = 1;
        goto dispatched;
case_3:
        func_8020A028_de(state, &D_800F3D20 + type * 0x38);
        goto dispatched;
case_4:
        func_8020A2D4_de(state, &D_800F3D20 + type * 0x38);
        goto dispatched;
case_5:
        func_8020A458_de(state, &D_800F3D20 + type * 0x38);
case_6:
case_7:
case_8:
dispatched:

    if (((ObjectLinks2EC *)state)->unk_240 > 0) {
        ((Actor_func_8022D290_de *)(*(void **)state))->unk_0x06B0 |= 0x4000;
        ((Actor_func_8022D290_de *)(*(void **)state))->unk_0x06AC |= 0x4000;
        ((ObjectLinks2EC *)state)->unk_240 -= 1;
    }
}
