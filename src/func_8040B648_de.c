#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"
#include "stddef.h"
/* Starts the configured action using the actor resource or the shared fallback. */
void func_80442574_de(void *, s32, void *, s32, s32); /* extern */
extern s32 D_800E28C0;
extern char D_8014561C;
extern s32 D_8014ADA0;
extern s32 D_8014D480;
extern s32 D_8015375C;
s32 func_8040B648_de(s32 arg0, ActionRecAt24 *arg1) {
    void *var_a0;
    ObjRecAt5DC *temp_v0;
    D_800E28C0 = 1;
    D_8014D480 = 0;
    if (D_8015375C != 0) {
        D_8014ADA0 = 1;
    } else {
        temp_v0 = arg1->unk1C;
        if (temp_v0 != NULL) {
            var_a0 = temp_v0->unk5DC + 0x554;
        } else {
            var_a0 = &D_8014561C;
        }
        func_80442574_de(var_a0, arg1->unk24, arg1->unk1C, arg1->unk20, 0);
    }
    return 1;
}
