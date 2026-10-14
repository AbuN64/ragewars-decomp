#include "span_1000/code_8028308C.h"
#include "types.h"
#include "stddef.h"
/* Apply resource indices and dispatch the optional object effect. */
void func_8025DE54_de(s32, s32, s32, s32, s32, s32); /* extern */
s32 func_80268BE0_de(void *, s8); /* extern */
void func_8027DAD0_de(void *, s32, s32); /* extern */
void func_802843B8_de(void *, s32); /* extern */
void func_802A4598_de(void *, void *, s8); /* extern */
extern char D_8013B1A8;
extern char D_801379C0;
void func_80283920_de(Obj_func_80283920_de *arg0, Params_func_80283920_de *arg1) {
    s32 temp_t0;
    s8 temp_a1;
    s8 temp_a2;
    u16 temp_v1;
    func_8027DAD0_de(arg0, 0, 0);
    temp_a2 = arg1->unk6;
    if (temp_a2 != -1) {
        func_802A4598_de(&D_801379C0, arg0, temp_a2);
    }
    temp_a1 = arg1->unk7;
    arg0->unk138 = temp_a1 == -1 ? 0 : func_80268BE0_de(&D_8013B1A8, temp_a1);
    if (!(arg0->unk5C & 0x200000) && (temp_t0 = arg1->unkC, (temp_t0 != 0))) {
        switch(arg0->unk4) {
        case 0x22: case 0x5f: case 0x60:
            func_802843B8_de(arg0,temp_t0); break;
        default:
            func_8025DE54_de(temp_t0,arg0->unk8,arg0->unkC,arg0->unk10,0,-1); break;
        }
    }
}
