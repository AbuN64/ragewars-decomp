#include "shared/gameplay_transition.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022C894.h"
#include "types.h"



extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(f32 *);
extern void func_80271F9C_de(void *, void *, f32);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);




void func_8022D1A8_de(void *arg0) {
    Vec3 sp10;
    Vec3 *temp_s1;

    temp_s1 = &((Shared_ActorView *)arg0)->weapon.aimPosition;
    func_80271F68_de(&sp10, &((Shared_ActorView *)arg0)->resetPosition, temp_s1);
    func_8027207C_de(&sp10);
    func_80271F9C_de(&sp10, &sp10, 30.0f);
    func_80271F34_de(&((Player *)arg0)->previousPosition, temp_s1, &sp10);
}
