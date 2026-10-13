#include "span_1000/code_8024BA6C.h"
#include "shared/gameplay_transition.h"
#include "shared/gameplay_round_rules.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"



extern char D_800C2BC0_de;

extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern void *func_8028FDB4_de(void *arg0, s32 arg1);
extern void func_8024B4F4_de(void *arg0, s32 arg1);
extern void func_8024ADD0_de(void *arg0, Vec3 *arg1, s32 arg2);
extern void func_80253754_de(s32 arg0, s32 arg1);










void func_8022BC94_de(void *arg0, s32 arg1) {
    Vec3 sp28;
    void *temp_s1;
    Shared_ActorView *temp_s2;
    Shared_func_80227014_S4 *temp_v0;
    ObjectLinks1DC_3 *object = arg0;

    if (object->unk_100 & 0x40000) {
        temp_s1 = func_8025193C_de(0, object->resource, object->resource, object->resourceFlags, 4, 0, 0, &D_800C2BC0_de, 1);
        if (temp_s1 != 0) {
            temp_s2 = object->unk_1D8;
            func_8024B4F4_de(arg0, (s32)func_8028FDB4_de(*(void **)temp_s1, 0));
            if (arg1 != 0) {
                temp_v0 = temp_s2->message;
                if (temp_v0 != 0) {
                    sp28.x = temp_v0->position.x - object->unk_8.x;
                    sp28.y = 0.0f;
                    sp28.z = ((Shared_func_80227014_S4 *)temp_s2->message)->position.z - object->unk_8.z;
                    func_8024ADD0_de(arg0, &sp28, arg1);
                }
            }
            func_80253754_de(0, (s32)temp_s1);
        }
    }
}
