#include "include_asm.h"
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
#include "SDK/AUDIO_2/802BF400.H"
#include "SDK/SCHED/8028DF6C_7.H"
#include "sdk/libgultra/libasm_802BD1A8_3.h"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
extern s32 D_80142C30;
extern s32 D_80142C38;
void __scAppendList(OSSched *arg0, void *arg1) {
    void *temp_v0;

    if ((((struct OSScTask_s *)arg1)->list.type) == 2) {
        temp_v0 = arg0->audioListTail;
        if (temp_v0 != 0) {
            ((struct OSScTask_s *)temp_v0)->next = arg1;
        } else {
            arg0->audioListHead = arg1;
        }
        arg0->audioListTail = arg1;
        arg0->doAudio = 1;
    } else {
        temp_v0 = arg0->gfxListTail;
        if (temp_v0 != 0) {
            ((struct OSScTask_s *)temp_v0)->next = arg1;
        } else {
            arg0->gfxListHead = arg1;
        }
        arg0->gfxListTail = arg1;
    }
    ((struct OSScTask_s *)arg1)->next = 0;
    ((struct OSScTask_s *)arg1)->state = (((struct OSScTask_s *)arg1)->flags) & 3;
}

void *func_8028F9AC_de(struct OSScTask_s *arg0) {
    s32 f1a;
    s32 f1b;
    void *v2;

    if (arg0 == 0) {
        return 0;
    }
    f1a = (s32)arg0->framebuffer;
    if (f1a == D_80142C38) {
        return 0;
    }
    v2 = func_802BA310_de();
    f1b = (s32)arg0->framebuffer;
    if (f1b == (s32)v2) {
        return 0;
    }
    if (f1b != D_80142C30) {
        return arg0;
    }
    return 0;
}

s32 func_8028FA0C_de(void *arg0, void *arg1) {
    if ((((s32)((struct OSScTask_s *)arg1)->state)) & 3) {
        return 0;
    }
    if ((((struct OSScTask_s *)arg1)->list.type) != 1) {
        return 1;
    }
    if (((((s32)((struct OSScTask_s *)arg1)->flags)) & 0x60) != 0x60) {
        return 1;
    }
    osViSwapBuffer(((s32)((struct OSScTask_s *)arg1)->framebuffer));
    return 1;
}


#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C52B4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5674);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5384);
#endif
