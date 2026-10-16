#include "common/types_8fd754e1e915.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8020FDB0.h"
#include "span_1000/code_80225D10.h"
#include "span_1000/code_8022D944.h"
#include "TYPES.H"

extern float D_800C2B70_de;
extern f32 D_80115DEC;
extern void func_80274098_de(void *arg0, void *arg1, void *arg2);

void func_80226C60_de(void *object, Vector4f *output)
{
    Vector4f pitchRotation;
    Vector4f yawRotation;
    Vector4f rollRotation;
    Vector4f orientation;
    Vector4f pitchYaw;
    Vector4f oriented;
    Player *player = object;
    float pitch;
    float roll;
    float heading;
    float yaw;
    float scale;

    pitch = player->pitchOffset + player->state730;
    roll = player->lean + player->state738;
    scale = D_800C2B70_de;
    roll *= scale;
    yaw = player->state728 + player->state734;
    heading = player->heading;
    orientation = player->orientation;
    pitch -= player->state708;

    D_80115DEC = func_802B7130_de(roll);
    pitch *= scale;
    rollRotation.x = 0.0f;
    rollRotation.y = 0.0f;
    rollRotation.z = D_80115DEC;
    rollRotation.w = func_802B6560_de(roll);

    D_80115DEC = func_802B7130_de(pitch);
    pitchRotation.x = D_80115DEC;
    pitchRotation.y = 0.0f;
    pitchRotation.z = 0.0f;
    pitchRotation.w = func_802B6560_de(pitch);

    heading = (heading + yaw) * scale;
    D_80115DEC = func_802B7130_de(heading);
    yawRotation.x = 0.0f;
    yawRotation.y = D_80115DEC;
    yawRotation.z = 0.0f;
    yawRotation.w = func_802B6560_de(heading);

    func_80274098_de(&pitchYaw, &pitchRotation, &yawRotation);
    func_80274098_de(&oriented, &pitchYaw, &orientation);
    func_80274098_de(output, &rollRotation, &oriented);
}
