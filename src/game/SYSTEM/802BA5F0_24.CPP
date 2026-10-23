#include "include_asm.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "sdk/os.h"

/** Returns D_800D8440. */
extern void *D_800D8440;

void *func_802BA640_de(void) {
    return D_800D8440;
}

extern void *D_800D4414;
extern u32 func_802BCF30_de(void);

void func_802BA650_de(s32 arg0, s32 arg1, s16 arg2) {
    u32 temp_v0;
    RecCode802BA23C *rec;

    temp_v0 = func_802BCF30_de();
    rec = D_800D4414;
    rec->f10 = arg0;
    rec->f14 = arg1;
    rec->f2 = arg2;
    __osRestoreInt(temp_v0);
}

#if defined(VERSION_US)
char rodata_unresolved_802BA5D8[8] =
    "m_OnEnem";
#endif
