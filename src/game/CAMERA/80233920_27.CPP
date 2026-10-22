#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CHANNEL.H"

extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
extern void func_802B72B0_de(float arg0);




void func_8023946C_de(void *arg0, CVector3 *arg1) {
    CVector3 sp10;
    GameplayCamera *camera = arg0;
    func_80271F68_de(&sp10, &camera->position, arg1);
    func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
}
