#include "span_16E000/code_804264F0.h"
#include "types.h"
/* Reports every set entry of each ready slot to the handler, stopping after two slots. */





extern State_func_80428214_de D_801462C8;
extern void func_8042854C_de(s32, s32, s32);

void func_80428214_de(void) {
    State_func_80428214_de *st;
    s32 n;
    s32 k;
    s32 i;
    State_func_80428214_de *base;
    s32 j;

    k = 0;
    st = &D_801462C8;
    for (n = 0; n < 4; n++) {
        if (st->slots[n].ready == 1) {
            j = 0;
            for (i = 0; i < 0x16; i++) {
                if (((base = &D_801462C8)->slots[n].flags[i] == 1) && (i != 0)) {
                    func_8042854C_de(j, i, k);
                    j++;
                }
            }
            k++;
            if (k >= 2) {
                return;
            }
        }
    }
}
