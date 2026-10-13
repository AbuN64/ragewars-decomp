#include "shared/level_actor.h"
#include "span_1000/code_80206258.h"
#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802022E0.h"
#include "types.h"


extern f32 D_800C6B30[];

extern s32 func_80285F58_de(void *, void *);
extern s32 func_80214178_de(void *, void *, s32);











void func_80203908_de(void *arg0, void *arg1) {
    s32 flags;
    ActorMotionDefinition *record;

    record = &((ActorMotionResource *)((Actor_func_8024A7A0_de *)arg0)->definition)->motion;
    if (((Actor_func_8024A7A0_de *)arg0)->type == 0x40C) {
        ((struct Record_func_8020388C_de *)arg1)->speed = D_800C6B30[1];
    } else {
        ((struct Record_func_8020388C_de *)arg1)->speed = 0.0f;
    }
    ((struct Record_func_8020388C_de *)arg1)->pad128 = 0;
    ((struct Record_func_8020388C_de *)arg1)->threshold = record->eventThreshold;

    if (func_80285F58_de(&D_8011FE88, arg0) == 0) {
        if (record->flags & 0x1000) {
            flags = ((Actor_func_8024A7A0_de *)arg0)->flags & ~0x2000;
            flags = flags & ~0x100;
            ((Actor_func_8024A7A0_de *)arg0)->flags = flags;
        }
        if (record->flags & 0x800) {
            ((Actor_func_8024A7A0_de *)arg0)->flags =
                ((Actor_func_8024A7A0_de *)arg0)->flags & ~0x100;
            func_80214178_de(arg0, arg1, 0);
        } else {
            func_80214178_de(arg0, arg1, 1);
        }
    } else {
        func_80214178_de(arg0, arg1, 0x40);
    }
    ((struct Record_func_8020388C_de *)arg1)->state = 0;
}
