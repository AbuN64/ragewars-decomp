#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Releases the object D_800E4F60 holds through func_802547E4_de, calls func_802A2360_de and
   func_80422020_de, clears D_800E4F60 and returns zero. */
extern void *D_800E4F60;
extern void func_802547E4_de(void *);
extern void func_802A2360_de();
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_80422020_de();
#else
extern void func_8042201C_de();
#endif
extern void func_80422020_de();

s32 func_8042B394_de(void) {
    func_802547E4_de(D_800E4F60);
    func_802A2360_de();
#if defined(VERSION_DE)
    func_80422020_de();
#else
    
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_80422020_de
#else
func_8042201C_de
#endif
();
#endif
    D_800E4F60 = 0;
    return 0;
}
