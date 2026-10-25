#include "COMMON/VECTOR4F.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V6.H"
#include "TYPES.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/S1.H"
#include "COMMON/EXTERNS_10.H"
#include "SYSTEM_3/802A6AC0.H"
#include "FX_2/80271B18.H"
#include "SYSTEM/80255C40_7.H"
#include "LISTS/80279520.H"


void func_802A5AD0_de(ObjRecAt3CV1 *arg0) {
    if (arg0->unk24 != 0.0f) {
        D_800D15E4[0] += arg0->unk34;
        D_800D15E4[1] += arg0->unk38;
        D_800D15E4[2] += arg0->unk3C;
        D_800D15E4[3] += arg0->unk24;
    }
    D_800D15E4[4] += arg0->unk14;
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

void PitchMatrixLocal(void *, f32);
void TranslateMatrix(char *, f32, f32, f32);
void ScaleMatrixLocal(void *, f32, f32, f32);
void Rsp_ConvertMatrixToFixed(f32 *, PackedMatrixWords *);

Particle *System_SpawnImpactMark(SceneRecAt95A8 *scene, CVector3 position, CVector3 normal, s32 surface, s32 owner) {
    f32 matrix[16];
    CQuatern rotation;
    Particle *node;
    IntrusiveList *list;

    rotation = func_80271818_de(&normal.x);
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
        MatrixFromQuaternion(&rotation.x, matrix);
        PitchMatrixLocal(matrix, 1.5707965f);
        Particle_NormalizeVec3(&normal);
        Particle_ScaleVector(&normal, &normal, 2.048f);
        Particle_AddVec3(&position, &position, &normal);
        TranslateMatrix((char *)matrix, position.x, position.y, position.z);
        ScaleMatrixLocal(matrix, D_800C5EA8_de, 1.0f, D_800C5EA8_de);
        Rsp_ConvertMatrixToFixed(matrix, &node->transform.matrix);
    }
done:
    return node;
}
