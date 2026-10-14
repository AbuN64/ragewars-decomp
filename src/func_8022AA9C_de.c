#include "span_1000/code_8022A274.h"
#include "span_1000/code_8021CD70.h"
#include "types.h"

extern void *D_800D052C[];

s32 func_8022AA9C_de(AimPlayer *arg0, s32 arg1) {
    void *p = D_800D052C[arg1];
    if (arg0->unk594 == 1) {
        return ((GlobalState *)p)->field20;
    }
    return ((GlobalState *)p)->field24;
}
