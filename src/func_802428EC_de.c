#include "shared/level_actor.h"
#include "span_1000/code_802412C0.h"

extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);

void func_802428EC_de(void *arg0, void *arg1) {
    Actor_func_80241BAC_de *actor = arg0;
    Actor_func_8024A7A0_de *target = arg1;
    Vec3 *position = &target->position1;
    actor->flags |= 8;
    func_80271F34_de(position, position, &actor->movement);
}
