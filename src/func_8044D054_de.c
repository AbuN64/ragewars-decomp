#include "span_16E000/code_8044ACCC.h"
#include "span_16E000/code_8044ACCC.h"
#include "common/unused.h"
#include "types.h"

/* Loads a selected resource into the shared buffer and releases the temporary allocation. */

struct State_func_8044D054_de;

s32 *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32); /* extern */
extern void func_80253838_de(void *, void *); /* extern */
extern s32 func_80264B6C_de(void); /* extern */
extern void *func_802BD3A0_de(void *, const void *, int); /* extern */
extern char D_00285160;
extern char D_800C50B0_de;

void func_8044D054_de(State_func_8044D054_de *arg0) {
    s32 *temp_v0;
    s32 temp_a1;

    if (func_80264B6C_de() == 0) {
        temp_v0 = func_8025193C_de(0, arg0->unk38, arg0->unk38, arg0->unk44, 0, 0, &D_00285160, &D_800C50B0_de, 1);
        func_802BD3A0_de(&D_800F91F0, (const void *)*temp_v0, 0x5800);
        func_80253838_de(0, temp_v0);
        arg0->unk4 = 1;
    }
}
