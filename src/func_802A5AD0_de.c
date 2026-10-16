#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A6AC0.h"
#include "types.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_802A25C4.h"
#include "span_1000/code_80255BEC.h"
#include "shared/func_8028C568_de_closed.h"

extern func_802A6AC0_S2 D_800D15E0;
extern func_802077F4_S2 D_800D15F0;

void func_802A5AD0_de(ObjRecAt3CV1 *arg0) {
    if (arg0->unk24 != 0.0f) {
        D_800D15E0.unk4 += arg0->unk34;
        D_800D15E0.unk8 += arg0->unk38;
        D_800D15E0.unkC += arg0->unk3C;
        D_800D15E0.unk10 += arg0->unk24;
    }
    D_800D15F0.unk4 += arg0->unk14;
}

extern f32 D_800C5EA0_de[2];

void func_802A5B4C_de(f32 *arg0) {
    f32 new_var;
    f32 new_var2;

    new_var2 = (new_var2 = *arg0);
    if (*arg0 < 0.0f) {
        *arg0 = 0.0f;
    } else {
        new_var = D_800C5EA0_de[1];
        if (new_var < new_var2) {
            *arg0 = new_var;
        }
    }
}

extern void *func_8027963C_de(s32 arg0);




void func_802A5B84_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    void *node;

    node = func_8027963C_de(arg0 + 0x7588);
    if (node != 0) {
        ((ObjRecAt18V6 *)(node))->unk18 = arg1;
        ((ObjRecAt18V6 *)(node))->unk14 = arg2;
        ((ObjRecAt18V6 *)(node))->unk8 = 0;
        ((ObjRecAt18V6 *)(node))->unkC = arg4;
        ((ObjRecAt18V6 *)(node))->unk10 = arg3;
    }
}

void func_802737F0_de(void *, f32);
void func_80273448_de(char *, f32, f32, f32);
void func_8027347C_de(void *, f32, f32, f32);
void func_8027027C_de(f32 *, PackedMatrixWords *);

Particle *func_802A5BE4_de(SceneRecAt95A8 *scene, Vec3 position, Vec3 normal, s32 surface, s32 owner) {
    f32 matrix[16];
    Vector4f rotation;
    Particle *node;
    IntrusiveList *list;

    func_80271818_de(&rotation, &normal.x);
    if (D_800CDBE8 != 0) return 0;
    D_800CDBE8 = 1;
    list = &scene->lists[surface];
    node = scene->free.head;
    if (node != 0) {
        func_80255ED8_de(&scene->free, node);
    } else {
        node = list->head;
        if (node == 0) goto done;
        func_80255ED8_de(list, node);
    }
    func_80255D14_de(list, node);
    if (node != 0) {
        node->owner = owner;
        func_80274244_de(&rotation.x, matrix);
        func_802737F0_de(matrix, 1.5707965f);
        func_8027207C_de(&normal);
        func_80271F9C_de(&normal, &normal, 2.048f);
        func_80271F34_de(&position, &position, &normal);
        func_80273448_de((char *)matrix, position.x, position.y, position.z);
        func_8027347C_de(matrix, D_800C5EA8_de, 1.0f, D_800C5EA8_de);
        func_8027027C_de(matrix, &node->transform.matrix);
    }
done:
    return node;
}
