#include "COMMON/MODEL_RENDER.H"
#include "RENDER/8026AC38.H"
#include "COMMON/PROPGEOMETRY.H"
#include "WORLD/8024E914.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "SCENE/802508E0.H"
#include "SCENE/802508E0_9.H"
#include "particle/80271B18_3.H"
#include "include_asm.h"

/* STATINST.CPP */
extern s32 D_800D2978;

extern void GraphU64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern f32 D_800C3E50_de[];

/* Draws an owner model with timed descriptor selection and fade setup/reset; a named descriptor-slot reference preserves reload scheduling. */

extern void *Statinst_AcquireGeometry(ResourceOwner *owner,s32 index);

extern void Link_AnimateVertexColors(void *object, void *colors);

extern void Geometry_QueueModelInstance(void **, void *, s32, void *, void *, s32);

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

extern char g_statObjectIndexText;

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

extern s32 SetN64_LocatePackSection(s32 *, s32, s32, s32 *);

extern void Events_DeliverContactEffect(void *, void *, s32, s32, Triple, ResourceManagerState);

s32 Statinst_UpdateDistanceFade(void *prop, s32 arg1) {
    OwnerStaticInstanceDrawDistanceFadedModel *owner = prop;
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

    GraphU64_SubtractVectors(&sp10, &camera->position,
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

void Statinst_DrawDistanceFadedModel(OwnerStaticInstanceDrawDistanceFadedModel *owner) {
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
    instance = Statinst_AcquireGeometry(owner, key);
    if (instance != 0) {
        resource = Cache_RequestPairedResource(0, owner->flagsD0 | D_800CD3F0, instance, (CachedResource *)owner->field20, 8, owner, &D_00250C2C,
                                 D_800C3E40_de, 0);
        if (resource != 0) {
            Cache_MarkResourceInUse(0, resource);
            header = (s32 *)resource->data;
            if (header[0] == 1) {
                char *object = (char *)header + header[1];
                char *colors = (char *)header + header[2];

                if (owner->colorFrame != (u8)D_800D2978) {
                    Link_AnimateVertexColors(object, colors);
                }
                data = object;
            } else {
                data = (char *)(header + 2);
            }
            if (D_800D15E0 != 0) {
                Geometry_DrawModelResource(instance, owner->transform, 0, 0, data, remaining);
            } else {
                Geometry_QueueModelInstance(instance, owner->transform, 0, 0, data, remaining);
            }
            Cache_UnlockResource(0, resource);
        }
        Cache_UnlockResource(0, instance);
        owner->colorFrame = (u8)D_800D2978;
    }
    D_800D15E0 = 0;
    D_800D15E4[3] = D_800C3E58_de;
}

void Statinst_DrawModel(ModelOwner *owner) {
    s32 remaining;
    void *instance;
    CachedResource *resource;
    s32 *header;
    char *data;

    if (owner->flagsD8 & 0x40) {
        return;
    }
    remaining = owner->descriptor->argument;
    instance = Statinst_AcquireGeometry(owner, owner->descriptor->key);
    if (instance == 0) {
        return;
    }
    resource = Cache_RequestPairedResource(0, owner->flagsD0 | D_800CD3F0, instance, (CachedResource *)owner->field20, 8, owner, &D_00250C2C,
                             D_800C3E40_de, 0);
    if (resource != 0) {
        Cache_MarkResourceInUse(0, resource);
        header = (s32 *)resource->data;
        if (header[0] == 1) {
            char *object = (char *)header + header[1];
            char *colors = (char *)header + header[2];

            if (owner->colorFrame != (u8)D_800D2978) {
                Link_AnimateVertexColors(object, colors);
            }
            data = object;
        } else {
            data = (char *)&header[2];
        }
        if (D_800D15E0 != 0) {
            Geometry_DrawModelResource(instance, owner->transform, 0, 0, data, remaining);
        } else {
            Geometry_QueueModelInstance(instance, owner->transform, 0, 0, data, remaining);
        }
        Cache_UnlockResource(0, resource);
    }
    Cache_UnlockResource(0, instance);
    owner->colorFrame = (u8)D_800D2978;
}

void Statinst_DispatchAttachmentEvents(void *object, s32 all) {
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

    model = Cache_RequestResource(0, ((PlacedProp *)object)->owner, ((PlacedProp *)object)->owner, 0x18, 4, 0, 0,
                          &g_statObjectIndexText, 0);
    if (model == 0) {
        return;
    }
    name = SetN64_LocatePackSection(*model, ((PlacedProp *)object)->owner, 3, &size);
#if defined(VERSION_DE)
    table = Cache_RequestResource(0, name, name, size, 0, 0, 0, D_800C3E70, 0);
#elif defined(VERSION_EU)
    table = Cache_RequestResource(0, name, name, size, 0, 0, 0, D_800C4120, 0);
#elif defined(VERSION_EU_X)
    table = Cache_RequestResource(0, name, name, size, 0, 0, 0, D_800C4160, 0);
#elif defined(VERSION_US)
    table = Cache_RequestResource(0, name, name, size, 0, 0, 0, D_800C3DA0, 0);
#else
    table = Cache_RequestResource(0, name, name, size, 0, 0, 0, D_800C8F60, 0);
#endif
    if (table != 0) {
        header = *table;
        count = header[1];
        entries = (Attachment *)(header + 2);
        for (i = 0; i < count; i++) {
            attachment = &entries[i];
            if (all != 0 || attachment->type == 8) {
                GraphU64_TransformPoint(((PlacedProp *)object)->matrix, &attachment->offset, &position);
                Events_DeliverContactEffect(object, object, attachment->type, -1, position, attachment->params);
            }
        }
        Cache_UnlockResource(0, table);
    }
    Cache_UnlockResource(0, model);
}

/* 800C8F30.CPP */
const unsigned char D_d0_0ba355c47669e01e[13] = {
    0x6C, 0x69, 0x74, 0x20, 0x76, 0x65, 0x72, 0x74, 0x69, 0x63, 0x65, 0x73, 0x00,
};
