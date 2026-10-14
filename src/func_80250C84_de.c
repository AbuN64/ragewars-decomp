#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "types.h"
/* Draws a model instance for an owner: looks up the instance through func_802507AC_de, loads the owner's
 * model resource, decodes its colour block when the owner's colour frame at 0xDA differs from the current
 * D_800D297B, draws it through func_8026DA4C_de or func_8026DC24_de (by D_800D15E0) with the owner's transform
 * at 0x28, releases the resource and the instance, and records the current colour frame. Adapted from
 * func_8024A7A0_de with the instance lookup, the colour frame test and the alternative draw call; the colour
 * block address is taken before the frame test. D_250BD4 is the callback address as splat names it. */



extern s32 D_800CD3F0;
extern s32 D_800D15E0;

extern char D_00250C2C;
extern char D_800C3E40_de;

extern s32 func_802507AC_de(Owner_func_80250C84_de *, s32);
extern s32 func_80251F6C_de(s32, s32, s32, s32, s32, void *, void *, void *, s32);
extern void func_80253BBC_de(s32, s32);
extern void func_8027892C_de(void *object, void *colors);
extern void func_8026DA4C_de(s32, void *, s32, s32, void *, s32);
extern void func_8026DC24_de(s32, void *, s32, s32, void *, s32);
extern void func_80253754_de(s32, s32);

void func_80250C84_de(Owner_func_80250C84_de *owner, s32 unused, s32 arg2, s32 key) {
    s32 instance;
    s32 resource;
    s32 *header;
    char *data;

    instance = func_802507AC_de(owner, key);
    if (instance == 0) {
        return;
    }
    resource = func_80251F6C_de(0, owner->flagsD0 | D_800CD3F0, instance, owner->field20, 8, owner, &D_00250C2C,
                             &D_800C3E40_de, 0);
    if (resource != 0) {
        func_80253BBC_de(0, resource);
        header = *(s32 **)resource;
        if (header[0] == 1) {
            char *object = (char *)header + header[1];
            char *colors = (char *)header + header[2];

            if (owner->colorFrame != D_800D297B) {
                func_8027892C_de(object, colors);
            }
            data = object;
        } else {
            data = (char *)&header[2];
        }
        if (D_800D15E0 != 0) {
            func_8026DA4C_de(instance, owner->transform, 0, 0, data, arg2);
        } else {
            func_8026DC24_de(instance, owner->transform, 0, 0, data, arg2);
        }
        func_80253754_de(0, resource);
    }
    func_80253754_de(0, instance);
    owner->colorFrame = D_800D297B;
}
