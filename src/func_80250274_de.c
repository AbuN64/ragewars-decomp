#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E914.h"
#include "types.h"
/* Draws an owner model with timed descriptor selection and fade setup/reset; a named descriptor-slot reference preserves reload scheduling. */





extern s32 D_800CD3F0;
extern s32 D_800D15E0;
extern f32 D_800D15F0;
extern f32 D_800C3E50_de[];
extern f32 D_800C3E58_de;

extern char D_00250C2C;
extern char D_800C3E40_de;

extern s32 func_802507AC_de(Owner_func_80250274_de *, s32);
extern s32 func_80251F6C_de(s32, s32, s32, s32, s32, void *, void *, void *, s32);
extern void func_80253BBC_de(s32, s32);
extern void func_8027892C_de(void *object, void *colors);
extern void func_8026DA4C_de(s32, void *, s32, s32, void *, s32);
extern void func_8026DC24_de(s32, void *, s32, s32, void *, s32);
extern void func_80253754_de(s32, s32);

static inline int select_key(DescriptorRecAt24 *descriptor, u32 timer) {
 int key;
    if (timer >= (u32)(descriptor->period * 2)) {
        key = descriptor->key2;
    } else {
        key = descriptor->key;
    }
 return key;
}
void func_80250274_de(Owner_func_80250274_de *owner) {
    DescriptorRecAt24 *descriptor;
    s32 arg2;
    s32 key;
    s32 instance;
    s32 resource;
    s32 *header;
    char *data;
    f32 alpha;

    if (owner->flagsD8 & 0x40) {
        return;
    }
    descriptor = owner->descriptor;
    arg2 = descriptor->argument;
    key = select_key(descriptor, owner->timer);
    if (key == -1) {
        if (owner->fade <= 0) {
            return;
        }
        D_800D15E0 = 1;
        D_800D15F0 = owner->fade << 5;
        { DescriptorRecAt24 **slot = &owner->descriptor; key = (*slot)->key; }
    } else {
        if (owner->fade < 8) {
            D_800D15E0 = 1;
            alpha = owner->fade << 5;
        } else {
            alpha = D_800C3E50_de[1];
            D_800D15E0 = 0;
        }
        D_800D15F0 = alpha;
    }
    instance = func_802507AC_de(owner, key);
    if (instance != 0) {
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
                data = (char *)(header + 2);
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
    D_800D15E0 = 0;
    D_800D15F0 = D_800C3E58_de;
}
