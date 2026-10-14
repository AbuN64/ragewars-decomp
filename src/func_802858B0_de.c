#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028567C.h"
#include "types.h"




extern void *func_8028CE78_de(void *object, int index);
extern void func_80264DE0_de(unsigned int *record, unsigned int value);






void func_802858B0_de(void *arg0, void *arg1, Vec3 arg2,
                   f32 arg5, f32 arg6, void **arg7) {
    ((Node_func_80285B64_de *)arg0)->key = arg1;
    ((Node_func_80285B64_de *)arg0)->position = arg2;
    ((Node_func_80285B64_de *)arg0)->value0 = arg5;
    ((Node_func_80285B64_de *)arg0)->value1 = arg6;
    ((Node_func_80285B64_de *)arg0)->owner = arg7;
    if (arg7 != 0) {
        *arg7 = arg0;
    }
    func_80264DE0_de(&((Node_func_80285B64_de *)arg0)->amplitudeHandle,
                  (unsigned int)func_8028CE78_de(&D_8011FE88, ((Clip *)arg1)->mode));
    func_80264DE0_de(&((Node_func_80285B64_de *)arg0)->lifetimeHandle,
                  (unsigned int)func_8028CE78_de(&D_8011FE88, ((Clip *)arg1)->frames));
}
