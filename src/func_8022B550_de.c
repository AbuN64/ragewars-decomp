#include "span_1000/code_8022AE90.h"
/* Starts a timer in the first of the object's five 24-byte slots at 0x1248 whose remaining time is not
   positive: records the kind, target, a zero elapsed value and the tag, sets the duration to rate
   times D_800C7E00 and the step to target over duration. */





void func_8022B550_de(Obj_func_8022B550_de *obj, float target, float rate, int kind, int tag) {
    int i;

    for (i = 0; i < 5; i++) {
        Timer *t = &obj->timers[i];
        if (t->duration <= 0.0f) {
            t->kind = kind;
            t->target = target;
            t->elapsed = 0.0f;
            t->tag = tag;
            t->duration = rate * D_800C7E00;
            do {
                t->step = target / t->duration;
                return;
            } while (0);
        }
    }
}
