#include "COMMON/MODEL_RENDER.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/PROPGEOMETRY.H"
#include "WORLD_2/8024E914.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "SCENE/802508E0.H"
#include "SCENE/802508E0_9.H"
#include "particle/80271B18_3.H"
extern s32 D_800D2978;

extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
extern f32 D_800C3E50_de[];

/* Draws an owner model with timed descriptor selection and fade setup/reset; a named descriptor-slot reference preserves reload scheduling. */











extern void *func_802507AC_de(ResourceOwner *owner,s32 index);



extern void func_8027892C_de(void *object, void *colors);

extern void Render_QueueModelInstance(void **, void *, s32, void *, void *, s32);

static inline int select_key(DescriptorRecAt24 *descriptor, u32 timer) {
 int key;
    if (timer >= (u32)(descriptor->period * 2)) {
        key = descriptor->key2;
    } else {
        key = descriptor->key;
    }
 return key;
}

/* Starts the effects attached to an object's model: loads the model resource named by the object's id,
 * finds its attachment table (group 3) and loads it, then for each 0x1C-byte attachment (all of them, or
 * only type 8 when all is clear) transforms its offset by the object's matrix at 0x68 and starts the
 * attachment's effect at that point through func_80265E10_de, releasing both resources afterwards. */

extern char D_800C3E5C_de;

#if defined(VERSION_DE)
#elif defined(VERSION_EU)
extern char D_800C4120[];
#elif defined(VERSION_EU_X)
extern char D_800C4160[];
#elif defined(VERSION_US)
extern char D_800C3DA0[];
#else
extern char D_800C8F60[];
#endif


extern s32 func_8028FE3C_de(s32 *, s32, s32, s32 *);


extern void func_80265E10_de(void *, void *, s32, s32, Triple, ResourceManagerState);

s32 func_802500FC_de(void *prop, s32 arg1) {
    Owner_func_80250274_de *owner = prop;
    GameplayCamera *camera = (void *)arg1;
    CVector3 sp10;
    f32 temp_f0;
    f32 threshold;
    s32 var_v1;
    s8 temp_v0;
    s32 var_v1_2;
    u16 temp_v1;
    u16 var_v0;
    u8 next_timer;
    DescriptorRecAt24 *descriptor;

    func_80271F68_de(&sp10, &camera->position,
                  &owner->position);
    temp_f0 = sp10.x * sp10.x + sp10.y * sp10.y + sp10.z * sp10.z;
    threshold = D_800C3E50_de[0];
    if (!(threshold <= temp_f0)) {
        var_v1 = (s32)temp_f0;
    } else {
        var_v1 = (s32)(temp_f0 - threshold) | 0x80000000;
    }
    descriptor = owner->descriptor;
    owner->timer = var_v1;
    if ((u32)var_v1 >= (u32)(descriptor->period * 2)) {
        var_v1_2 = descriptor->key2;
    } else {
        var_v1_2 = descriptor->key;
    }

    if (var_v1_2 == -1) {
        if (owner->fade <= 0) {
            owner->fade = 0;
            owner->flagsD8 =
                owner->flagsD8 | 4;
            return 0;
        }
        temp_v1 = owner->flagsD8;
        if (temp_v1 & 0x200) {
            owner->flagsD8 = temp_v1 | 4;
            owner->fade = 0;
            return 0;
        }
        temp_v0 = (u8)owner->fade - 1;
        owner->fade = temp_v0;
        if (temp_v0 < 0) {
            owner->fade = 0;
        }
        var_v0 = owner->flagsD8 | 4;
        goto block_20;
    } else if (owner->fade < 8) {
        next_timer = (u8)owner->fade + 1;
        if (owner->flagsD8 & 0x200) {
            owner->fade = 8;
            owner->flagsD8 =
                owner->flagsD8 & 0xFFFB;
        } else {
            owner->fade =
                next_timer;
            var_v0 = owner->flagsD8 | 4;
block_20:
            owner->flagsD8 = var_v0;
        }
    } else {
        owner->fade = 8;
    }
    return 1;
}

void func_80250274_de(Owner_func_80250274_de *owner) {
    DescriptorRecAt24 *descriptor;
    s32 remaining;
    s32 key;
    void *instance;
    CachedResource *resource;
    s32 *header;
    char *data;
    f32 alpha;

    if (owner->flagsD8 & 0x40) {
        return;
    }
    descriptor = owner->descriptor;
    remaining = descriptor->argument;
    key = select_key(descriptor, owner->timer);
    if (key == -1) {
        if (owner->fade <= 0) {
            return;
        }
        D_800D15E0 = 1;
        D_800D15E4[3] = owner->fade << 5;
        { DescriptorRecAt24 **slot = &owner->descriptor; key = (*slot)->key; }
    } else {
        if (owner->fade < 8) {
            D_800D15E0 = 1;
            alpha = owner->fade << 5;
        } else {
            alpha = D_800C3E50_de[1];
            D_800D15E0 = 0;
        }
        D_800D15E4[3] = alpha;
    }
    instance = func_802507AC_de(owner, key);
    if (instance != 0) {
        resource = func_80251F6C_de(0, owner->flagsD0 | D_800CD3F0, instance, (CachedResource *)owner->field20, 8, owner, &D_00250C2C,
                                 &D_800C3E40_de, 0);
        if (resource != 0) {
            func_80253BBC_de(0, resource);
            header = (s32 *)resource->data;
            if (header[0] == 1) {
                char *object = (char *)header + header[1];
                char *colors = (char *)header + header[2];

                if (owner->colorFrame != (u8)D_800D2978) {
                    func_8027892C_de(object, colors);
                }
                data = object;
            } else {
                data = (char *)(header + 2);
            }
            if (D_800D15E0 != 0) {
                func_8026DA4C_de(instance, owner->transform, 0, 0, data, remaining);
            } else {
                Render_QueueModelInstance(instance, owner->transform, 0, 0, data, remaining);
            }
            func_80253754_de(0, resource);
        }
        func_80253754_de(0, instance);
        owner->colorFrame = (u8)D_800D2978;
    }
    D_800D15E0 = 0;
    D_800D15E4[3] = D_800C3E58_de;
}

void func_802504B0_de(ModelOwner *owner) {
    s32 remaining;
    void *instance;
    CachedResource *resource;
    s32 *header;
    char *data;

    if (owner->flagsD8 & 0x40) {
        return;
    }
    remaining = owner->descriptor->argument;
    instance = func_802507AC_de(owner, owner->descriptor->key);
    if (instance == 0) {
        return;
    }
    resource = func_80251F6C_de(0, owner->flagsD0 | D_800CD3F0, instance, (CachedResource *)owner->field20, 8, owner, &D_00250C2C,
                             &D_800C3E40_de, 0);
    if (resource != 0) {
        func_80253BBC_de(0, resource);
        header = (s32 *)resource->data;
        if (header[0] == 1) {
            char *object = (char *)header + header[1];
            char *colors = (char *)header + header[2];

            if (owner->colorFrame != (u8)D_800D2978) {
                func_8027892C_de(object, colors);
            }
            data = object;
        } else {
            data = (char *)&header[2];
        }
        if (D_800D15E0 != 0) {
            func_8026DA4C_de(instance, owner->transform, 0, 0, data, remaining);
        } else {
            Render_QueueModelInstance(instance, owner->transform, 0, 0, data, remaining);
        }
        func_80253754_de(0, resource);
    }
    func_80253754_de(0, instance);
    owner->colorFrame = (u8)D_800D2978;
}

void func_80250624_de(void *object, s32 all) {
    s32 **model;
    s32 **table;
    s32 *header;
    Attachment *attachment;
    Attachment *entries;
    Triple position;
    s32 name;
    s32 size;
    s32 count;
    s32 i;

    model = func_8025193C_de(0, ((PlacedProp *)object)->owner, ((PlacedProp *)object)->owner, 0x18, 4, 0, 0,
                          &D_800C3E5C_de, 0);
    if (model == 0) {
        return;
    }
    name = func_8028FE3C_de(*model, ((PlacedProp *)object)->owner, 3, &size);
#if defined(VERSION_DE)
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C3E70, 0);
#elif defined(VERSION_EU)
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C4120, 0);
#elif defined(VERSION_EU_X)
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C4160, 0);
#elif defined(VERSION_US)
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C3DA0, 0);
#else
    table = func_8025193C_de(0, name, name, size, 0, 0, 0, D_800C8F60, 0);
#endif
    if (table != 0) {
        header = *table;
        count = header[1];
        entries = (Attachment *)(header + 2);
        for (i = 0; i < count; i++) {
            attachment = &entries[i];
            if (all != 0 || attachment->type == 8) {
                func_80272898_de(((PlacedProp *)object)->matrix, &attachment->offset, &position);
                func_80265E10_de(object, object, attachment->type, -1, position, attachment->params);
            }
        }
        func_80253754_de(0, table);
    }
    func_80253754_de(0, model);
}
