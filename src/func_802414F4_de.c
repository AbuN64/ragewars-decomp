#include "span_1000/code_8023D370.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"
#include "stddef.h"
/* Tests a point against every edge plane of a polygon. */
void func_80271F68_de(f32 *, void *, void *); /* extern */
void func_80272018_de(f32 *, void *, f32 *);
/* extern */
s32 func_802414F4_de(func_80204468_S3 *arg0, void *arg1) {
    f32 sp10[3];
    f32 sp20[3];
    f32 sp30[3];
    s32 temp_v1;
    void *var_s1;
    s32 var_s0;
    void *var_s2;
    temp_v1 = ((Polygon_func_8023E8D4_de *)arg0)->vertexCount;
    if (temp_v1 == 1) {
        return 1;
    }
    var_s2 = (char *)arg0 + ((temp_v1 * 0xC) + 0xC);
    var_s1 = ((Polygon_func_8023E8D4_de *)arg0)->vertices;
    var_s0 = temp_v1;
    var_s0 = var_s0 - 1;
    for (; var_s0 != -1; var_s1 += 0xC, var_s0--) {
        func_80271F68_de(sp20, var_s1, var_s2);
        func_80272018_de(sp10, &((Polygon_func_8023E8D4_de *)arg0)->normal, sp20);
        func_80271F68_de(sp30, arg1, var_s2);
        var_s2 = var_s1;
        if (sp10[0]*sp30[0]+sp10[1]*sp30[1]+sp10[2]*sp30[2] > 0.0f) return 0;
    }
    return 1;
}
