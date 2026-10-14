#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8029EB74.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"






/** Scale a 3-vector (arg1) by a scalar (arg2), store into arg0. */
void func_8029E36C_de(void *arg0, void *arg1, f32 arg2) {
    Vec3 *arg1_record = arg1;
    Vec3 *arg0_record = arg0;
    arg0_record->x = arg1_record->x * arg2;
    arg0_record->y = arg1_record->y * arg2;
    arg0_record->z = arg1_record->z * arg2;
}
