#include "COMMON/PACKEDMESHMATERIAL.H"
#include "TYPES.H"

extern void func_80295E84_de(s32 *arg0, s32 arg1);






void func_80285570_de(MeshMaterial *dstData, PackedMeshMaterial *arg1) {
    s16 value;
    s32 reference;

    dstData->flags = arg1->flags;
    dstData->primaryColor[0] = arg1->primaryColor[0];
    dstData->primaryColor[1] = arg1->primaryColor[1];
    dstData->primaryColor[2] = arg1->primaryColor[2];
    dstData->primaryColor[3] = arg1->primaryColor[3];
    dstData->secondaryColor[0] = arg1->secondaryColor[0];
    dstData->secondaryColor[1] = arg1->secondaryColor[1];
    dstData->secondaryColor[2] = arg1->secondaryColor[2];
    dstData->secondaryColor[3] = arg1->secondaryColor[3];
    dstData->width = arg1->width;
    dstData->height = arg1->height;
    dstData->mode = arg1->mode;
    if (arg1->flags & 0x40) {
        value = (arg1->renderMode * 2) | 1;
    } else {
        value = arg1->renderMode * 2;
    }
    dstData->renderMode = value;
    reference = arg1->textureId;
    if (reference == -1) {
        dstData->texture = 0;
        return;
    }
    func_80295E84_de(&dstData->texture, reference);
}
