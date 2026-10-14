#include "shared/level_actor.h"
#include "shared/world.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024E130.h"
extern int func_8028B2F8_de(char *arg0, int arg1);





int func_8024E7DC_de(void *arg0) {
    int temp_a1 = ((LevelActor *)arg0)->model;
    int var_v0 = 0;
    if (temp_a1 != 0) {
        var_v0 = func_8028B2F8_de(&D_8011FE88, temp_a1);
    }
    return var_v0;
}
