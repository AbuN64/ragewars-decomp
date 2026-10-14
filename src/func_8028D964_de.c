#include "span_1000/code_8028CCB8.h"
#include "types.h"
#include "common/draft_fields_func_8028D964_de.h"

extern void func_8028DA74_de(void *arg0);
extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);
extern void func_80253838_de(void *, void *);

extern s32 D_00285160;
extern char D_800C5290_de;
extern char D_800C52BC;


void func_8028D964_de(void *arg0, s32 arg1) {
    s32 sp28;
    void **resource;
    s32 key;
    s32 size;
    s32 one;

    if (((struct MeasuredRecAt14V2 *)(arg0))->value == 0 || ((struct Measured_func_8028D964_de_7705078627e3 *)(arg0))->value != arg1) {
        func_8028DA74_de(arg0);
        if (((struct MeasuredRecAtCV3 *)(arg0))->value != 0) {
            size = 0x10;
            one = 1;
            resource = func_8025193C_de(0, ((struct MeasuredRecAtCV3 *)(arg0))->value,
                                     ((struct MeasuredRecAtCV3 *)(arg0))->value,
                                     ((struct MeasuredRecAt10V2 *)(arg0))->value, size, 0, 0,
                                     &D_800C5290_de, one);
            if (resource != 0) {
                key = func_8028FE3C_de((s32)*resource, ((struct MeasuredRecAtCV3 *)(arg0))->value,
                                    arg1, &sp28);
                func_80253838_de(0, resource);
                if ((((struct MeasuredRecAt14V6 *)(arg0))->value =
                     func_8025193C_de(0, key, key, sp28, size, 0,
                                   &D_00285160, &D_800C52BC, one)) != 0) {
                    ((struct Measured_func_8028D964_de_7705078627e3 *)(arg0))->value = arg1;
                }
            }
        }
    }
}
