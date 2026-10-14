#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802022E0.h"
#include "types.h"

/* Rotates a point about a pivot by an object's orientation: builds the rotation matrix from the
   three angles at offset 0x130 of the object through func_80202CA0_de and func_80274244_de (the body of
   func_80203CFC_de, inlined here as the frame layout shows), takes the point's offset from the pivot,
   rotates it through func_80272BCC_de into the point and adds the pivot back. */


extern void func_80202CA0_de(s32 *, f32 *);
extern void func_80274244_de(s32 *, f32 *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80272BCC_de(f32 *, Vec3 *, Vec3 *);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);




static inline void build_rotation(struct RotationObject *object, f32 *matrix) {
    s32 rotation[4];
    f32 angles[3];

    angles[0] = object->angleX;
    angles[1] = object->angleY;
    angles[2] = object->angleZ;
    func_80202CA0_de(rotation, angles);
    func_80274244_de(rotation, matrix);
}

void func_80203D4C_de(void *unused, struct RotationObject *object, Vec3 *pivot, Vec3 *point) {
    f32 matrix[16];
    Vec3 offset;

    build_rotation(object, matrix);
    func_80271F68_de(&offset, point, pivot);
    func_80272BCC_de(matrix, &offset, point);
    func_80271F34_de(point, point, pivot);
}
