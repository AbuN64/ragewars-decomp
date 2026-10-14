#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E914.h"
#include "types.h"
/* Draws an owner's own model instance unless it is hidden (flag 0x40 at 0xD8): looks up the instance keyed
 * by the descriptor's byte 0xE through func_802507AC_de, loads the owner's model resource, decodes its colour
 * block when the owner's colour frame differs from D_800D297B, draws it through func_8026DA4C_de or
 * func_8026DC24_de with the descriptor's byte 0x12, releases the resource and the instance, and records the
 * colour frame. Adapted from func_80250C84_de with the hidden flag and the descriptor-supplied key and
 * draw argument. */





extern s32 D_800CD3F0;
extern s32 D_800D15E0;

extern char D_00250C2C;
extern char D_800C3E40_de;

extern void *func_802507AC_de(ResourceOwner *owner,s32 index);
extern s32 func_80251F6C_de(s32, s32, s32, s32, s32, void *, void *, void *, s32);
extern void func_80253BBC_de(s32, s32);
extern void func_8027892C_de(void *object, void *colors);
extern void func_8026DA4C_de(s32, void *, s32, s32, void *, s32);
extern void func_8026DC24_de(s32, void *, s32, s32, void *, s32);
extern void func_80253754_de(s32, s32);

void func_802504B0_de(ModelOwner *owner) {
    s32 arg2;
    s32 instance;
    s32 resource;
    s32 *header;
    char *data;

    if (owner->flagsD8 & 0x40) {
        return;
    }
    arg2 = owner->descriptor->argument;
    instance = func_802507AC_de(owner, owner->descriptor->key);
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
