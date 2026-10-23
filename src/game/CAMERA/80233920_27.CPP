#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CHANNEL.H"

extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
extern void func_802B72B0_de(float arg0);




void func_8023946C_de(void *arg0, CVector3 *arg1) {
    CVector3 delta;
    GameplayCamera *camera = arg0;
    func_80271F68_de(&delta, &camera->position, arg1);
    func_802B72B0_de((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
}
