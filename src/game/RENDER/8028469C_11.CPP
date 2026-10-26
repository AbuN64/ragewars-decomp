#include "COMMON/PACKEDMESHMATERIAL.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "include_asm.h"
#include "RENDER/8028469C_11.H"

extern void TextLoad_LocateTextureResource(s32 *arg0, s32 arg1);






void Rumble_ExpandMeshMaterial(MeshMaterial *dstData, PackedMeshMaterial *arg1) {
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
    TextLoad_LocateTextureResource(&dstData->texture, reference);
}

f32 Rumble_SamplePackedFloatRange(s32 arg0) {
    s32 sp0;
    s32 sp4;
    u32 seed;
    s32 idx;
    f64 var_f2;

    sp0 = (s32) (*(u16 *) &arg0) << 16;
    if (((struct ObjRecAt2V2 *) ((u16 *) (&arg0)))->unk2 == 0) {
        return *(f32 *) &sp0;
    }
    sp4 = (s32) (((struct ObjRecAt2V2 *) ((u16 *) (&arg0)))->unk2) << 16;
    seed = (D_80111D24 * (s32) 0xA84A5B53) + (s32) 0x58348C2D;
    idx = (s32) ((seed >> 16) & 0x7FFF);
    var_f2 = (f64) idx;
    D_80111D24 = seed;
    if (idx < 0) {
        var_f2 += D_800C4EB0_de;
    }
    return *(f32 *) &sp0 + (((f32) var_f2 * *(f32 *) &sp4) * D_800C4EB8_de);
}

#if defined(VERSION_US)
unsigned char D_auto_func_8028562C_us_padding_8622C[4] = { 0x08, 0x00, 0x08, 0x00 };
#endif

#if defined(VERSION_US)
unsigned int data_unresolved_80285630[1] = {
    0x27BDFFA8,
};
#endif
