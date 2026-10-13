#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"
#include "types.h"
#include "span_1000/code_802B7B80.h"
/* Reinitializes a present controller pak entry under the pak queue lock, resets its counters and label, retries initialization, and releases the lock; an unsigned pointer local and a queue address relative to the adjacent status byte separate address lifetimes and preserve register scheduling. */



extern u8 D_800CBC10;
extern s32 D_800CBC1C;
extern s8 D_8010BBB8;
extern char D_8010FBC0;
extern char D_8010FC00;
extern s32 func_802BB2A0_de(void *, void *, s32);
extern s32 func_802BB420_de(void *, void *, s32);
extern s32 func_802BAD80_de(void *);
extern void func_80263740_de(void);
extern s32 func_80285AC4_de(void *, void *, s32);
extern s32 func_802B7FD8_de(void *, void *, s32);
#if defined(VERSION_EU)

#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)

#elif defined(VERSION_US)

#else

#endif






void func_80264248_de(Shape *arg0) {
    u32 address=(u32)arg0;
    char *o=(char *)address;

    if (D_800CBC10 != 0 && ((Obj80264124 *)address)->flags != 0) {
        if (func_802BB2A0_de(&D_8010FBC0, 0, 1) == 0) {
            D_800CBC1C = func_802BAD80_de(0);
        }
        func_80263740_de();
        D_8010BBB8 = 2;
        ((Obj80264124 *)o)->state = 0;
        ((Obj80264124 *)o)->amount = 0;
        ((Obj80264124 *)o)->timer = 0;
        func_80285AC4_de(o + 0x140, o + 0x16C, 3);
        func_802B7FD8_de(&D_8010FC00, o + 0xD8, arg0->enabled);
        
#if defined(VERSION_EU)
func_802B7EF0_eu
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#if defined(VERSION_EU) || defined(VERSION_US)
func_802B7F30_eu_x
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
((u32 (*)(void *))func_802B7F30_eu_x)
#endif
#elif defined(VERSION_US)
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
func_802B7B80_us
#elif defined(VERSION_US)
((u32 (*)(void *))func_802B7B80_us)
#endif
#else
#if defined(VERSION_DE)
((u32 (*)(void *))func_802B7C50_de)
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_802B7C50_de
#endif
#endif
((char *)o + 0xD8);
        
#if defined(VERSION_EU)
func_802B7EF0_eu
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#if defined(VERSION_EU) || defined(VERSION_US)
func_802B7F30_eu_x
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
((u32 (*)(void *))func_802B7F30_eu_x)
#endif
#elif defined(VERSION_US)
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
func_802B7B80_us
#elif defined(VERSION_US)
((u32 (*)(void *))func_802B7B80_us)
#endif
#else
#if defined(VERSION_DE)
((u32 (*)(void *))func_802B7C50_de)
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_802B7C50_de
#endif
#endif
((char *)o + 0xD8);
        if (func_802B7FD8_de(&D_8010FC00, o + 0xD8, arg0->enabled) == 0) {
            ((Obj80264124 *)o)->active = 1;
        }
        D_8010BBB8 = 2;
        D_800CBC1C = -1;
        func_802BB420_de(&((PakQueueState *)&D_8010BBB8)->queue, 0, 1);
    }
}
