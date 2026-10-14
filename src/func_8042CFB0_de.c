#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Calls func_802A2164_us and func_802A2394_de, then func_80298368_de with 0x11. */
#if defined(VERSION_EU)
extern void func_802A2344_eu();
#elif defined(VERSION_EU_X)
extern void func_802A2374_eu_x();
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_802A2164_us();
#else
extern void func_802A2224_de();
#endif
extern void func_802A2394_de();
extern void func_80298368_de(s32);

void func_8042CFB0_de(void) {
    
#if defined(VERSION_EU)
func_802A2344_eu
#elif defined(VERSION_EU_X)
func_802A2374_eu_x
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
func_802A2164_us
#else
func_802A2224_de
#endif
();
    func_802A2394_de();
    func_80298368_de(0x11);
}
