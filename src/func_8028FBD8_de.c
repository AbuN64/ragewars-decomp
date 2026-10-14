#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_802B9ED8.h"
#include "types.h"





void func_8028FBD8_de(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjectLinks2F8 *) ((s8 *) arg0))->unk_2F4);
    if ((((struct IntegerState14 *) ((s8 *) temp_a0))->unk_10) == 1) {
        (((struct IntegerState14 *) ((s8 *) temp_a0))->unk_4) = (s32) ((((struct IntegerState14 *) ((s8 *) temp_a0))->unk_4) | 0x10);
        func_802BA120_de();
    }
}
