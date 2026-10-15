#include "span_1000/code_8028469C.h"
#include "types.h"

extern void func_80295E84_de(s32 *arg0, s32 arg1);






void func_80285570_de(void *arg0, void *arg1) {
    s16 value;
    s32 reference;

    ((MeshMaterial *)arg0)->flags = ((PackedMeshMaterial *)arg1)->flags;
    ((MeshMaterial *)arg0)->primaryColor[0] = ((PackedMeshMaterial *)arg1)->primaryColor[0];
    ((MeshMaterial *)arg0)->primaryColor[1] = ((PackedMeshMaterial *)arg1)->primaryColor[1];
    ((MeshMaterial *)arg0)->primaryColor[2] = ((PackedMeshMaterial *)arg1)->primaryColor[2];
    ((MeshMaterial *)arg0)->primaryColor[3] = ((PackedMeshMaterial *)arg1)->primaryColor[3];
    ((MeshMaterial *)arg0)->secondaryColor[0] = ((PackedMeshMaterial *)arg1)->secondaryColor[0];
    ((MeshMaterial *)arg0)->secondaryColor[1] = ((PackedMeshMaterial *)arg1)->secondaryColor[1];
    ((MeshMaterial *)arg0)->secondaryColor[2] = ((PackedMeshMaterial *)arg1)->secondaryColor[2];
    ((MeshMaterial *)arg0)->secondaryColor[3] = ((PackedMeshMaterial *)arg1)->secondaryColor[3];
    ((MeshMaterial *)arg0)->width = ((PackedMeshMaterial *)arg1)->width;
    ((MeshMaterial *)arg0)->height = ((PackedMeshMaterial *)arg1)->height;
    ((MeshMaterial *)arg0)->mode = ((PackedMeshMaterial *)arg1)->mode;
    if (((PackedMeshMaterial *)arg1)->flags & 0x40) {
        value = (((PackedMeshMaterial *)arg1)->renderMode * 2) | 1;
    } else {
        value = ((PackedMeshMaterial *)arg1)->renderMode * 2;
    }
    ((MeshMaterial *)arg0)->renderMode = value;
    reference = ((PackedMeshMaterial *)arg1)->textureId;
    if (reference == -1) {
        ((MeshMaterial *)arg0)->texture = 0;
        return;
    }
    func_80295E84_de(&((MeshMaterial *)arg0)->texture, reference);
}
