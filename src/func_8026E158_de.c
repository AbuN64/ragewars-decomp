#include "span_1000/code_8026E1F8.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8026AC38.h"
#include "types.h"

extern void *func_8028FDB4_de(void *arg0, s32 arg1);
extern void **func_80295EAC_de(void *arg0, s32 arg1);
extern void func_80253754_de(s32 arg0, s32 arg1);





void func_8026E158_de(void **arg0) {
    void *temp_v0;
    s32 count;
    s32 i;
    void *rec;
    s32 result;

    temp_v0 = func_8028FDB4_de(*arg0, 2);
    count = *(s32 *)temp_v0;
    for (i = 0; i < count; i++) {
        rec = func_8028FDB4_de(func_8028FDB4_de(temp_v0, i), 0);
        if (((ResourceSectionReference *)rec)->resource == 0) {
            continue;
        }
        result = func_80295EAC_de(&((ResourceSectionReference *)rec)->resource, -1);
        if (result == 0) {
            continue;
        }
        func_80253754_de(0, result);
    }
}
