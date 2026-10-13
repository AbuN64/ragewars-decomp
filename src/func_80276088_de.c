#include "shared/world.h"
#include "span_1000/code_80275E44.h"
#include "types.h"
#include "common/types_8fd754e1e915.h"

extern void *func_8028B2F8_de(char *arg0, s32 arg1);





u8 func_80276088_de(s32 arg0) {
    Model_func_80223E34_de *temp = func_8028B2F8_de(&D_8011FE88, arg0);
    if (temp == 0) {
        return 0;
    }
    return temp->byte59;
}
