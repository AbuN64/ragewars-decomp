#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Calls func_802B2378 on the word at offset 0x24 of the structure D_800E28BC points to and
   returns zero. */


extern struct func_80207B5C_S2 *D_800E28BC;
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_802B2378(s32);
#else
extern void func_802AD2A8(s32);
#endif

s32 func_8040A5E8_de(void) {
    
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_802B2378
#else
func_802AD2A8
#endif
(D_800E28BC->unk24);
    return 0;
}
