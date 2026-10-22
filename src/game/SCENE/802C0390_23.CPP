#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "SCENE/802C0390_23.H"
#include "sdk/os.h"

#if !(defined(VERSION_DE))
extern u32 func_802BCF30_de(void);


void func_802BB850_eu(s32 arg0) {
    u32 temp_v0;
    s32 *p;

    temp_v0 = func_802BCF30_de();
    p = &D_800D5258;
    *p |= arg0;
    __osRestoreInt(temp_v0);
}
#endif
