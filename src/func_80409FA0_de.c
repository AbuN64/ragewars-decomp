#include "span_16E000/code_80409A88.h"
#include "types.h"
#include "stddef.h"
/* Searches the sixteen controller-pak notes for the requested name and returns the matching index when requested. */
extern void func_80405338_de(s32,s32,s32 *),func_80405648_de(s32,void *,s32);
extern s32 func_802A037C_de(void *,void *);
s32 func_80409FA0_de(void *unused, void *arg1, s32 arg2, s32 *arg3) {
    char sp10[16];
    s32 sp20;
    s32 var_s0;
    for(var_s0=0;var_s0<16;var_s0++) {
        func_80405338_de(arg2,var_s0,&sp20);
        func_80405648_de(sp20,&sp10,16);
        if(func_802A037C_de(&sp10,arg1)==0) {
            if(arg3) *arg3=var_s0;
            return 1;
        }
    }
    return 0;
}
