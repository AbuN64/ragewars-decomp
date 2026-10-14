#include "shared/gameplay_transition.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022AE90.h"
#include "types.h"





extern void func_80273198_de(Matrix *, Vec3 *);
extern void func_80271F9C_de(Vec3 *out, Vec3 *in, f32 scale);
extern void func_80271F34_de(Vec3 *result, Vec3 *left, Vec3 *right);
extern void func_80273448_de(Matrix *object, f32 x, f32 y, f32 z);
extern void func_80273D6C_de(Matrix *object);
extern void func_8027027C_de(Matrix *src, void *dst);




void func_8022B3D0_de(char *arg0, s32 arg1, Vec3 *arg2) {
    Shared_ActorView *actor = (Shared_ActorView *)arg0;
    Matrix matrix;
    Vec3 offset;

    func_80273198_de(&matrix, arg2);
    func_80271F9C_de(&offset, arg2, 5.12f);
    func_80271F34_de(&offset, &offset, &actor->targetPosition);
    func_80273448_de(&matrix, offset.x, offset.y, offset.z);
    func_80273D6C_de(&matrix);
    func_8027027C_de(&matrix, actor->transform1600);
}
