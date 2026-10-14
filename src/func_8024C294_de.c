#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"
extern char D_800C3830_de;

extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern void *func_8028FDB4_de(void *arg0, s32 arg1);
extern void func_80253754_de(s32 arg0, s32 arg1);






s32 func_8024C294_de(void *arg0, s32 arg1) {
    void *temp_v0;
    Table *temp_v1;
    s32 temp_s0;

    if (((LevelActor *)arg0)->flags & 0x40000) {
        temp_v0 = func_8025193C_de(0, ((LevelActor *)arg0)->resource, ((LevelActor *)arg0)->resource, ((LevelActor *)arg0)->resourceFlags, 4, 0, 0, &D_800C3830_de, 1);
        if (temp_v0 != 0) {
            temp_v1 = func_8028FDB4_de(*(void **) temp_v0, 1);
            temp_s0 = temp_v1->deltas[arg1];
            func_80253754_de(0, (s32) temp_v0);
            return temp_s0;
        }
    }
    return -1;
}
