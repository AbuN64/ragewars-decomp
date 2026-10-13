#include "span_16E000/code_8040C780.h"
/* Handles Controller Pak menu confirmations and returns focus to an enabled widget for the active channel. */
#include "span_16E000/code_8042F988.h"
s32 func_80299B4C_de();                                /* extern */
s32 func_8040EBD0_de(void *);                          /* extern */
Node_func_8040EF84_de *func_8041B7FC_de(s32, s32);                      /* extern */
void func_8041B8DC_de(s32, s32, void *);                  /* extern */
void func_80433BCC_de(s32);                               /* extern */
void func_80433D38_de(s32);                               /* extern */
void func_80434250_de(s32, s32);                            /* extern */
void func_80434E34_de(s32);                               /* extern */
extern char *D_800E54A4;                    

s32 func_804303F8_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0;
    Node_func_8040EF84_de *var_s0;
    Node_func_8040EF84_de *var_s0_2;
    Node_func_8040EF84_de *var_s0_3;

    temp_s1 = arg2 & 0xFFFF;
    temp_v0 = ((PakMenuController *)D_800E54A4)->players[temp_s1].state;
    switch (temp_v0) {
    case 12:
        temp_s0 = func_8029DB58_de(arg4);
        if (temp_s0 < func_80299B4C_de()) {
            ((PakMenuController *)D_800E54A4)->players[temp_s1].nameTimer = 0;
            ((PakMenuController *)D_800E54A4)->players[temp_s1].namePhase = 2;
        }
        if (arg3 == 1) {
            func_8029973C_de();
            ((PakMenuController *)D_800E54A4)->players[temp_s1].namePhase = arg3;
            func_80434E34_de(temp_s1);
            func_8025DF34_de(0xE81);
            return 0;
        }
        return 0;
    case 4:
        if (arg3 == 1) {
            func_8029973C_de();
            func_80434250_de(temp_s1, 0);
            ((PakMenuController *)D_800E54A4)->selected[temp_s1] = 0;
            func_8025DF34_de(0xE74);
            return 0;
        }
        return 0;
    case 13:
        if ((((PakMenuController *)D_800E54A4)->players[temp_s1].sub == 6) && (arg3 == 1)) {
            func_8029973C_de();
            var_s0 = func_8041B7FC_de(((PakMenuController *)D_800E54A4)->root, temp_s1)->ref2C;
loop_11:
            if (func_8040EBD0_de(var_s0) != 0) {
                var_s0 = var_s0->ref2C;
                goto loop_11;
            }
            func_8041B8DC_de((((PakMenuController *)D_800E54A4)->root), temp_s1, var_s0);
            func_8025DF34_de(0xE74);
            return 0;
        }
        return 0;
    case 22:
        if (arg3 == 1) {
            var_s0_2 = func_8041B7FC_de(((PakMenuController *)D_800E54A4)->root, temp_s1)->ref2C;
loop_16:
            if (func_8040EBD0_de(var_s0_2) != 0) {
                var_s0_2 = var_s0_2->ref2C;
                goto loop_16;
            }
            func_8041B8DC_de((((PakMenuController *)D_800E54A4)->root), temp_s1, var_s0_2);
            func_80433BCC_de(temp_s1);
        }
        goto block_24;
    case 27:
        if (arg3 == 1) {
            var_s0_3 = func_8041B7FC_de(((PakMenuController *)D_800E54A4)->root, temp_s1)->ref2C;
loop_21:
            if (func_8040EBD0_de(var_s0_3) != 0) {
                var_s0_3 = var_s0_3->ref2C;
                goto loop_21;
            }
            func_8041B8DC_de((((PakMenuController *)D_800E54A4)->root), temp_s1, var_s0_3);
            func_80433D38_de(temp_s1);
        }
block_24:
        func_8029973C_de();
        break;
    }
    return 0;
}
