#include "span_1000/code_80256220.h"
#include "types.h"
/* Clears and sizes the 0x8016E000 heap region against the detected RAM size, then initialises the
   five dependent subsystems over it. */

extern u8 D_80166000[];
extern u8 D_801051A0[];
extern u8 D_80106248[];
extern u8 D_801011B8[];

extern s32 func_80265350_de(void);
extern void func_802A001C_de(void *, s32, s32);
extern void func_802558B4_de(void *, void *, s32);
extern void func_802550F0_de(void *, s32);
extern void func_80256280_de(void *, s32);
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_8023B9C0_eu(s32, s32);
#elif defined(VERSION_EU_X)
extern void func_8023B9F0_eu_x(s32, s32);
#else
extern void func_8023B9B0_de(s32, s32);
#endif
extern void func_80250E70_de(s32, s32);

void func_802567D0_de(void) {
    u8 *heapStart;
    s32 heapEnd;
    s32 size;

    heapEnd = 0x80400000;
    heapStart = D_80166000;
    if (func_80265350_de() != 0x400000) {
        heapEnd = func_80265350_de() | 0x80000000;
    }

    size = heapEnd - (s32)heapStart;
    func_802A001C_de(heapStart, 0, size);
    func_802558B4_de(D_801051A0, heapStart, size);
    func_802550F0_de(D_80106248, 3);
    func_80256280_de(D_801011B8, 4);
    
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_8023B9C0_eu
#elif defined(VERSION_EU_X)
func_8023B9F0_eu_x
#else
func_8023B9B0_de
#endif
(0, 0);
    func_80250E70_de(0, 5);
}
