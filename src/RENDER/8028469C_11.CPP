#include "COMMON/PACKEDMESHMATERIAL.H"
#include "TYPES.H"

extern void func_80295E84_de(s32 *arg0, s32 arg1);






void func_80285570_de(MeshMaterial *arg0, PackedMeshMaterial *arg1) {
    s16 value;
    s32 reference;

    arg0->flags = arg1->flags;
    arg0->primaryColor[0] = arg1->primaryColor[0];
    arg0->primaryColor[1] = arg1->primaryColor[1];
    arg0->primaryColor[2] = arg1->primaryColor[2];
    arg0->primaryColor[3] = arg1->primaryColor[3];
    arg0->secondaryColor[0] = arg1->secondaryColor[0];
    arg0->secondaryColor[1] = arg1->secondaryColor[1];
    arg0->secondaryColor[2] = arg1->secondaryColor[2];
    arg0->secondaryColor[3] = arg1->secondaryColor[3];
    arg0->width = arg1->width;
    arg0->height = arg1->height;
    arg0->mode = arg1->mode;
    if (arg1->flags & 0x40) {
        value = (arg1->renderMode * 2) | 1;
    } else {
        value = arg1->renderMode * 2;
    }
    arg0->renderMode = value;
    reference = arg1->textureId;
    if (reference == -1) {
        arg0->texture = 0;
        return;
    }
    func_80295E84_de(&arg0->texture, reference);
}
