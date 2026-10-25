#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "SCENE/802C0390_23.H"
#include "sdk/os.h"

#if !(defined(VERSION_DE))
extern u32 __osDisableInt(void);


void func_802BB850_eu(s32 arg0) {
    u32 mask;
    s32 *p;

    mask = __osDisableInt();
    p = &D_800D5258;
    *p |= arg0;
    __osRestoreInt(mask);
}
#endif
