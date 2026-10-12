#include "types.h"

typedef struct AimProfile { char pad00[0x8F]; u8 scaled; } AimProfile;
typedef struct AimModel { char pad00[0x12C]; f32 height; } AimModel;
typedef struct AimPlayer {
    char pad00[8]; f32 position[3]; char pad14[0x5C4];
    AimProfile *profile; AimModel *model;
    char pad5E0[0xE70]; s32 transformed;
} AimPlayer;
typedef struct AimTarget { char pad00[0x1D8]; AimPlayer *player; } AimTarget;
typedef struct AimBrain {
    AimPlayer *player; char pad04[0x60]; AimTarget *target;
    char pad68[0x1E0]; f32 angle, previousAngle; char pad250[8];
    f32 targetPosition[3]; f32 distance;
} AimBrain;
extern f32 D_800C1C74_de, D_800C1C78_de, D_800C1C7C_de, D_800C1C80_de, D_800C1C84_de;
extern s32 D_801468F4;
extern void func_8022B144_de(void *, f32 *);
extern f32 func_802B72B0_de(f32);

void func_802095F8_de(AimBrain *brain) {
    f32 origin[3], delta[3];
    f32 ownHeight, targetHeight, correction, vertical, horizontal;
    AimPlayer *target;
    if (brain->target) {
        origin[0] = brain->player->position[0];
        origin[1] = brain->player->position[1];
        origin[2] = brain->player->position[2];
        func_8022B144_de(brain->player, delta);
        target = brain->target->player;
        ownHeight = delta[1] - brain->player->position[1];
        if (target->transformed) {
            func_8022B144_de(target, delta);
            targetHeight = delta[1] - target->position[1];
        } else targetHeight = target->model->height - target->position[1];
        targetHeight *= D_800C1C74_de;
        if (D_801468F4 && target->profile->scaled) targetHeight *= D_800C1C78_de;
        delta[0] = brain->targetPosition[0];
        delta[1] = brain->targetPosition[1];
        delta[2] = brain->targetPosition[2];
        delta[0] -= origin[0];
        delta[1] -= origin[1];
        delta[2] -= origin[2];
        correction = targetHeight - ownHeight;
        brain->distance = func_802B72B0_de(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);
        vertical = delta[1] + correction;
        delta[1] = 0.0f;
        horizontal = func_802B72B0_de(delta[0]*delta[0] + delta[2]*delta[2]);
        if (horizontal == 0.0f) {
            if (vertical < 0.0f) brain->angle = D_800C1C7C_de;
            else brain->angle = D_800C1C80_de;
        } else brain->angle = func_8029C044_de(vertical, horizontal) * D_800C1C84_de;
    } else brain->angle = 0.0f;
    brain->previousAngle = brain->angle;
}
