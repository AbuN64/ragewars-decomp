#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "GAME/CODE_8027302C.H"

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_80100338;

extern u8 *func_8024E6A0_de(Source *arg0);
extern void func_8024E6D8_de(u8 *arg0, CVector3 *arg1);
extern void func_80271F34_de(CVector3 *result, CVector3 *left, CVector3 *right);
extern void func_80271F68_de(CVector3 *result, CVector3 *left, CVector3 *right);
extern void func_80272944_de(MatrixF *arg0, CVector3 *arg1, CVector3 *arg2, s32 count);
extern void func_80243A90_de(Source *arg0, CVector3 arg1, CollisionInfo *arg2);
extern void func_80207730_de(u8 *arg0, Source *arg1);




void func_80213CF8_de(Source *player, void *arg1) {
    CVector3 saved_velocity;
    CVector3 position;
    CVector3 transformed;
    MatrixF matrix;
    u8 *object;
    f32 amount;

    object = func_8024E6A0_de(player);
    if ((object != 0) && (*((Source *)object)->kind == 2)) {
        position = player->position;
        func_8024E6D8_de(object, &saved_velocity);
        if (!(player->flags38 & 0x1000) || (saved_velocity.y > 0.0f)) {
            func_80271F34_de(&position, &position, &saved_velocity);
        }
        saved_velocity = player->velocity;
        player->velocity.x = 0.0f;
        player->velocity.y = 0.0f;
        player->velocity.z = 0.0f;
        func_80271F68_de(&transformed, &position, &((Source *)object)->position);
        amount = func_8024E73C_de(object);
        func_802736D4_de(&matrix, amount);
        func_80272944_de(&matrix, &transformed, &transformed, 1);
        func_80271F34_de(&transformed, &transformed, &((Source *)object)->position);
        func_80271F68_de(&transformed, &transformed, &position);
        player->height += amount;
        func_80271F34_de(&position, &position, &transformed);
        func_80243A90_de(player, position, &D_80100338);
        player->velocity = saved_velocity;
        if ((object[0] == 1) && (*((Source *)object)->kind == 2)) {
            func_80207730_de(object, player);
        }
    }
}
