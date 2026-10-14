#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802636D0.h"
#include "types.h"
#include "span_1000/code_802B7B80.h"






extern s32 D_8010EC90;

extern s32 D_80146894;

extern void func_80285D30_de(s32 *);

extern f32 func_802856E0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3);
#if defined(VERSION_EU)
extern unsigned int func_802B80B4_eu(void *arg0);
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
extern unsigned int func_802B80F4_eu_x(void *arg0);
#elif defined(VERSION_US)
extern unsigned int func_802B7D44_us(void *arg0);
#else
extern unsigned int func_802B7E14_de(void *arg0);
#endif
#if defined(VERSION_EU)

#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)

#elif defined(VERSION_US)

#else

#endif

void func_80264104_de(Obj80264124 *arg0) {
    Triple zero;
    void *object;
    s32 *global;
    f32 first;

    if (arg0->active != 0) {
        zero.x = 0;
        zero.y = 0;
        zero.z = 0;
        if (arg0->state == 0) {
            goto reset;
        }
        global = &D_80146894;
        if ((*global != 0) || (D_801371DC != 0) || (global[-6] != 13)) {
reset:
            arg0->amount = 0.0f;
            func_80285D30_de(arg0->object);
        } else {
            object = arg0->object;
            func_80285C78_de(object);
            first = func_802856E0_de(&D_8010EC90, arg0->x, arg0->y, arg0->z);
            arg0->amount = first + func_802856E0_de(object, zero.x, zero.y, zero.z);
        }
        if (arg0->active != 0) {
            if (arg0->amount != 0.0f) {
                arg0->timer += arg0->amount;
                if (arg0->timer >= D_800C4308_de) {
                    arg0->timer -= D_800C4308_de;
                    
#if defined(VERSION_EU)
func_802B80B4_eu
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
func_802B80F4_eu_x
#elif defined(VERSION_US)
func_802B7D44_us
#else
func_802B7E14_de
#endif
((void *)arg0->status);
                    return;
                }
            }
            
#if defined(VERSION_EU)
func_802B7EF0_eu
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#if defined(VERSION_EU) || defined(VERSION_US)
func_802B7F30_eu_x
#elif defined(VERSION_EU_X) || defined(VERSION_US_REV1)
((unsigned int (*)(void *))func_802B7F30_eu_x)
#endif
#elif defined(VERSION_US)
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
func_802B7B80_us
#elif defined(VERSION_US)
((unsigned int (*)(void *))func_802B7B80_us)
#endif
#else
#if defined(VERSION_DE)
((unsigned int (*)(void *))func_802B7C50_de)
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_802B7C50_de
#endif
#endif
((void *)arg0->status);
        }
    }
}
