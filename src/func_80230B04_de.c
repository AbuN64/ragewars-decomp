#include "span_1000/code_8022F3E8.h"
#include "types.h"
#include "common/draft_fields_func_80230B04_de.h"




extern s32 func_8022AB20_de(void *arg0, s16 arg1);
extern s32 func_80214178_de(void *, void *, s32);

void func_80230B04_de(void *arg0, void *arg1) {
    s16 temp_a1;
    s32 temp_v1;
    void *temp_a0;

    temp_a0 = ((struct MeasuredRecAt1D8V1 *)(arg0))->value;
    if (!(((struct MeasuredRecAt6AC *)(temp_a0))->value & 0x2000)) {
        temp_a1 = ((struct MeasuredRecAt62EV2 *)(temp_a0))->value;
        if (temp_a1 != 0) {
            if (temp_a1 == 2) {
                temp_v1 = ((struct MeasuredRecAt13CV2 *)(arg1))->value;
                if (temp_v1 == 1) {
                    func_80214178_de(arg0, arg1, 5);
                } else if (temp_v1 == temp_a1) {
                    func_80214178_de(arg0, arg1, 9);
                } else {
                    goto check_height;
                }
            } else {
                goto check_state;
            }
        } else {
check_height:
            if (!(((struct MeasuredRecAt40 *)(arg1))->value > D_800C2F14_de)) {
                func_80214178_de(arg0, arg1, 9);
            } else {
                func_80214178_de(arg0, arg1, 5);
            }
        }
        goto done;
check_state:
        if (func_8022AB20_de(temp_a0, temp_a1) == 1) {
            func_80214178_de(arg0, arg1, 7);
        } else {
            func_80214178_de(arg0, arg1, 5);
        }
done:
        ;
    }
}
