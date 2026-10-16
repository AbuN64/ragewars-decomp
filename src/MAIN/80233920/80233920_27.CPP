#include "shared/gameplay_camera.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802393F4.h"


extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_802B72B0_de(float arg0);




void func_8023946C_de(void *arg0, Vec3 *arg1) {
    Vec3 sp10;
    GameplayCamera *camera = arg0;
    func_80271F68_de(&sp10, &camera->position, arg1);
    func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
}
