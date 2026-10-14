#include "span_1000/code_8023D370.h"
#include "types.h"






s32 func_8023E864_de(void *arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 0;
    if ((((struct Input *)arg0)->contactNormal.x == ((Polygon_func_8023E8D4_de *)arg1)->normal.x) &&
        (((struct Input *)arg0)->contactNormal.y == ((Polygon_func_8023E8D4_de *)arg1)->normal.y) &&
        (((struct Input *)arg0)->contactNormal.z == ((Polygon_func_8023E8D4_de *)arg1)->normal.z)) {
        var_v0 = 1;
    }
    return var_v0;
}
