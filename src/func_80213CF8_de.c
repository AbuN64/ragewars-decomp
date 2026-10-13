#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80212C90.h"
#include "types.h"







typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_80100338;

extern u8 *func_8024E6A0_de(Source *arg0);
extern void func_8024E6D8_de(u8 *arg0, Vec3 *arg1);
extern void func_80271F34_de(Vec3 *result, Vec3 *left, Vec3 *right);
extern void func_80271F68_de(Vec3 *result, Vec3 *left, Vec3 *right);
extern f32 func_8024E73C_de(u8 *arg0);
extern void func_80272944_de(Matrix_func_80213CF8_de *arg0, Vec3 *arg1, Vec3 *arg2, s32 count);
extern void func_80243A90_de(Source *arg0, Vec3 arg1, CollisionInfo *arg2);
extern void func_80207730_de(u8 *arg0, Source *arg1);




void func_80213CF8_de(Source *arg0, void *arg1) {
    Vec3 saved_velocity;
    Vec3 position;
    Vec3 transformed;
    Matrix_func_80213CF8_de matrix;
    u8 *object;
    f32 amount;

    object = func_8024E6A0_de(arg0);
    if ((object != 0) && (*((Source *)object)->kind == 2)) {
        position = arg0->position;
        func_8024E6D8_de(object, &saved_velocity);
        if (!(arg0->flags38 & 0x1000) || (saved_velocity.y > 0.0f)) {
            func_80271F34_de(&position, &position, &saved_velocity);
        }
        saved_velocity = arg0->velocity;
        arg0->velocity.x = 0.0f;
        arg0->velocity.y = 0.0f;
        arg0->velocity.z = 0.0f;
        func_80271F68_de(&transformed, &position, &((Source *)object)->position);
        amount = func_8024E73C_de(object);
        func_802736D4_de(&matrix, amount);
        func_80272944_de(&matrix, &transformed, &transformed, 1);
        func_80271F34_de(&transformed, &transformed, &((Source *)object)->position);
        func_80271F68_de(&transformed, &transformed, &position);
        arg0->height += amount;
        func_80271F34_de(&position, &position, &transformed);
        func_80243A90_de(arg0, position, &D_80100338);
        arg0->velocity = saved_velocity;
        if ((object[0] == 1) && (*((Source *)object)->kind == 2)) {
            func_80207730_de(object, arg0);
        }
    }
}
