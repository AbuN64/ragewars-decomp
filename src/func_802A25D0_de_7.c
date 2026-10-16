#include "shared/gameplay_camera.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A25C4.h"
#include "types.h"
#include "common/unused.h"



extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);
extern void func_80272B38_de(void *, void *, void *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_802727D8_de(void *);













void func_802A31E8_de(Node438C *arg0, Node438C *arg1, GameplayCamera *arg2, void *arg3) {
    f32 setup[4];
    Vec3 first;
    Vec3 basis;
    Vec3 cross;
    Vec3 result;
    f32 neg_y;
    f32 neg_z;

    func_80271F68_de(&first, &arg0->position,
                  &arg1->position);
    func_8027207C_de(&first);
    setup[0] = 0;
    setup[1] = 0;
    setup[2] = D_800C5DE8_de[1];
    func_80272B38_de(&arg2->unk1A0, setup, &basis);
    neg_y = -basis.y;
    neg_z = -basis.z;
    basis.y = neg_y;
    basis.z = neg_z;
    func_80271F9C_de(&cross, &basis,
                  basis.x * first.x + neg_y * first.y + neg_z * first.z);
    func_80271F68_de(&cross, &first, &cross);
    func_8027207C_de(&cross);
    func_80272018_de(&result, &basis, &cross);
    func_8027207C_de(&result);
    func_80271F9C_de(&result, &result, arg0->a);
    func_80271F9C_de(&cross, &cross, arg0->b);
    func_80271F9C_de(&basis, &basis, arg0->c);
    func_802727D8_de(arg3);
    ((Matrix *)arg3)->m[0] = result.x;
    ((Matrix *)arg3)->m[1] = result.y;
    ((Matrix *)arg3)->m[2] = result.z;
    ((Matrix *)arg3)->m[4] = cross.x;
    ((Matrix *)arg3)->m[5] = cross.y;
    ((Matrix *)arg3)->m[6] = cross.z;
    ((Matrix *)arg3)->m[8] = basis.x;
    ((Matrix *)arg3)->m[9] = basis.y;
    ((Matrix *)arg3)->m[10] = basis.z;
    ((Matrix *)arg3)->m[12] = arg0->position.x;
    ((Matrix *)arg3)->m[13] = arg0->position.y;
    ((Matrix *)arg3)->m[14] = arg0->position.z;
}
