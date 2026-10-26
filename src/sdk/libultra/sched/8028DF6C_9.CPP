#include "include_asm.h"
#include "COMMON/LONE/D_80106248.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "sdk/AUDIO_2/802BF400.H"
#include "sdk/SCHED/8028DF6C_7.H"
#include "sdk/libgultra/libasm_802BD1A8_3.h"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
extern s32 D_80142C30;

s32 func_802BD170_de(s32);

extern s32 func_802BD170_de(s32);
extern s32 D_800CD704;
extern void func_802BB5F0_de(void *arg0, s32 arg1);
void __scYield(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjectLinks2F8 *) ((s8 *) arg0))->unk_2F4);
    if ((((struct IntegerState14 *) ((s8 *) temp_a0))->unk_10) == 1) {
        (((struct IntegerState14 *) ((s8 *) temp_a0))->unk_4) = (s32) ((((struct IntegerState14 *) ((s8 *) temp_a0))->unk_4) | 0x10);
        func_802BA120_de();
    }
}

void func_8028FC10_de(void *arg0) {
    Node_func_8028FC10_de *node = 0;
    s32 value1 = 0;
    s32 value2 = 0;
    s32 flags;

    while (osRecvMesg(&((OSSched *)arg0)->commandQueue, &node, 0) != -1) {
        if (node->type == 1 && (node->flags & 0x20) && D_800CD704 == 0) {
            D_800CD704 = 2;
            func_802BB5F0_de(&D_80106248, D_800CD8B8_de);
        }
        __scAppendList(arg0, node);
    }

    if (((OSSched *)arg0)->doAudio != 0 &&
        ((OSSched *)arg0)->curRSPTask != 0) {
        __scYield(arg0);
        return;
    }

    flags = (((OSSched *)arg0)->curRSPTask == 0) * 2 |
            (((OSSched *)arg0)->curRDPTask == 0);
    if (((s32 (*)(void *, s32 *, s32 *, s32))func_8028F544_de)(arg0, &value1, &value2, flags) != flags) {
        ((void (*)(void *, s32, s32))func_8028FA60_de)(arg0, value1, value2);
    }
}

int func_8028FD44_de(int arg0) {
    return arg0 + 0x40;
}
