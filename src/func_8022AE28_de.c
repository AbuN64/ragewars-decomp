#include "shared/gameplay_transition.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022A274.h"




extern char D_8011FE88[];




int func_8022AE28_de(void *arg0, void *arg1) {
    int flag;
    Vec3 *src;
    src = arg1;
    flag = ((int (*)(void *))func_80286728_de)(D_8011FE88);
    ((Actor_func_8024A7A0_de *)arg0)->position0 = *src;
    ((Actor_func_8024A7A0_de *)arg0)->model = flag;
    ((Shared_ActorView *)arg0)->weapon.position0 = *src;
    ((Shared_ActorView *)arg0)->weapon.model = flag;
    return flag != 0;
}
