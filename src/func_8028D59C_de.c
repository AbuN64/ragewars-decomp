#include "span_1000/code_80286050.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"

extern void *func_8028FDB4_de(void *arg0, s32 arg1);
extern void func_80253754_de(s32 arg0, s32 arg1);
extern void func_80253838_de(void *arg0, void *arg1);




void func_8028D59C_de(void *arg0) {
    Scene_func_80288EA8_de *object = arg0;
    s32 *list;
    s32 val;

    if (object->loaded != 0) {
        list = (s32 *) func_8028FDB4_de(object->model, 0);
        if (*list != 0) {
            do {
                val = *list;
                list += 1;
                func_80253754_de(0, val);
            } while (*list != 0);
        }
        func_80253838_de(0, object->loaded);
        object->loaded = 0;
        object->model = 0;
    }
}
