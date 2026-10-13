#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80207ABC.h"
extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

void func_80207EEC_de(void *event) {
    ActorMotionEvent *arg0 = event;
    func_8028B670_de(&D_8011FE88, arg0->id, arg0->key, 1);
}
