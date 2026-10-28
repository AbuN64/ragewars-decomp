#include "COMMON/MODEL_RENDER.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "RENDER/8026AC38.H"
#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/LEVEL_SPAWN.H"
#include "COMMON/PROPGEOMETRY.H"
#include "TYPES.H"
#include "ACTORS/LIGHTING_BUILDLITMODEL.H"
#include "SCENE/802508E0.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
extern s32 D_800D2978;

/* Returns the matching resource entry index, or minus one when absent. */

extern void *Statinst_AcquireGeometry(ResourceOwner *owner,s32 index);

extern void Geometry_UnlockMaterialResources(void **arg0);

extern void Cache_UnlockResource(s32 arg0, s32 arg1);

extern s32 D_800CD3F0;

extern char D_00250C2C;

extern char D_800C3E40_de[];

void Statinst_DrawDistanceFadedModel(void *);

void Statinst_DrawModel(void *);


extern void Cache_TouchResourceByKey(s32 arg0, s32 arg1);

extern s32 *Geometry_CollectMaterialResources(void **arg0, s32 arg1, s32 *arg2);


extern void Cache_MarkResourceInUse(s32, s32);

extern void Link_AnimateVertexColors(void *object, void *colors);

extern void Geometry_QueueModelInstance(void **, void *, s32, void *, void *, s32);

extern void Cache_UnlockResource(s32, s32);

int Statinst_FindPlacedPropIndex(void *wanted,int key) {
 int result=-1; int i,count,offset; char *entries;
 LevelNode *h=SetN64_GetPackSection(key,0);
 count=h->count; entries=(char *)h->records;
i=0; if(count>0) {offset=i; do {if(entries+offset!=wanted) {i++;offset+=232;} else {result=i;break;}}while(i<count);}return result;}

void Statinst_RegisterGeometryResources(void *owner) {
    struct ResourceBinding *o = (struct ResourceBinding *) owner;
    void *temp_v0;
    CachedResource *ret2;

    if (!(o->status & 0x40)) {
        temp_v0 = Statinst_AcquireGeometry(owner, o->variant);
        if (temp_v0 != 0) {
            Geometry_UnlockMaterialResources((void **) temp_v0);
            ret2 = Cache_RequestPairedResource(0, o->registrationFlags | D_800CD3F0, temp_v0, (CachedResource *)o->resource, 8, owner, &D_00250C2C, D_800C3E40_de, 0);
            if (ret2 != 0) {
                Cache_UnlockResource(0, (s32)ret2);
            }
            Cache_UnlockResource(0, (s32) temp_v0);
        }
    }
}

/** Return the nested signed byte unless flag 0x40 suppresses it. */
int Statinst_GetPropModelIndex(char *object) {
    if (((ObjectLinksDC *)(object))->unk_D8 & 0x40) {
        return 0;
    }
    return ((struct ObjectState13 *) ((ObjectLinksDC *) object)->unk_18)->unk_12;
}

/** Read the signed byte at offset 0xE from the object's linked record. */
signed char Statinst_GetPropGeometryIndex(struct PlacedProp *object) {
    void *linked = object->model;
    return ((signed char *)linked)[0xE];
}

void Statinst_DrawForGameMode(void *owner) {
    if (D_801462C8.local != 0) {
        Statinst_DrawModel(owner);
        return;
    }
    Statinst_DrawDistanceFadedModel(owner);
}

void Statinst_RefreshResourceUsage(void *resourceBinding) {
    struct ResourceBinding *binding = resourceBinding;
    if (!(binding->status & 0x40) && (binding->colorFrame != (u8)D_800D2978)) {
        Cache_TouchResourceByKey(0, binding->registrationFlags | D_800CD3F0);
    }
}

s32 *Statinst_CollectPropResources(void *prop, s32 model, s32 geometryVariant, s32 *nextResource) {
    struct ResourceBinding *o = (struct ResourceBinding *) prop;
    void *geometryResource;
    s32 *resourceCursor;
    CachedResource *ret2;

    resourceCursor = nextResource;
    geometryResource = Statinst_AcquireGeometry(prop, geometryVariant);
    if (geometryResource != 0) {
        o->loadedResource = geometryResource;
        *resourceCursor = (s32) geometryResource;
        resourceCursor = Geometry_CollectMaterialResources(geometryResource, model, resourceCursor + 1);
        ret2 = Cache_RequestPairedResource(0, o->registrationFlags | D_800CD3F0, geometryResource, (CachedResource *)o->resource, 8, prop, &D_00250C2C, D_800C3E40_de, 1);
        if (ret2 != 0) {
            *resourceCursor = (s32)ret2;
            resourceCursor += 1;
        }
    }
    return resourceCursor;
}

/** Advance the wrapping counter D_800D0910, resetting to 0x380000 at 0x3FFFFF. */
int Statinst_AdvanceResourceKey(void) {
    int temp_v0;

    temp_v0 = D_800D0910 + 1;
    D_800D0910 = temp_v0;
    if (temp_v0 == 0x3FFFFF) {
        D_800D0910 = 0x380000;
    }
    return D_800D0910;
}

void Statinst_BuildLitGeometryResource(void *arg0, s32 **arg1)
{
  struct ResourceBinding *binding = arg0;
  s32 new_var;
  new_var = *(*arg1);
  Cache_ReplaceResourcePairFirst(0, arg1, Lighting_BuildLitModel(new_var, *binding->resource, binding->runtimeState, (s32)binding->transform, 0, arg0));
}

void Statinst_DrawGeometryVariant(OwnerStaticInstanceDrawGeometryVariant *owner, s32 unused, s32 remaining, s32 key) {
    void *instance;
    CachedResource *resource;
    s32 *header;
    char *data;

    instance = Statinst_AcquireGeometry(owner, key);
    if (instance == 0) {
        return;
    }
    resource = Cache_RequestPairedResource(0, owner->flagsD0 | D_800CD3F0, instance, (CachedResource *)owner->field20, 8, owner, &D_00250C2C,
                             D_800C3E40_de, 0);
    if (resource != 0) {
        Cache_MarkResourceInUse(0, (s32)resource);
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
        Cache_UnlockResource(0, (s32)resource);
    }
    Cache_UnlockResource(0, (s32)instance);
    owner->colorFrame = (u8)D_800D2978;
}

/** Select one of two signed bytes according to a doubled nested count. */
int Statinst_SelectDistanceVariant(void *object) {
    LevelActor *actor = object;
    struct ResourceFadeDefinition *nested = (struct ResourceFadeDefinition *)actor->definition;
    if ((u32)actor->resourceState <
        nested->threshold * 2) {
        return nested->nearValue;
    }
    return nested->farValue;
}

s8 Statinst_SelectGameModeVariant(LevelActor *actor) {
    void *definition;

    if (D_801462C8.local != 0) {
        return ((struct ResourceFadeDefinition *)actor->definition)->nearValue;
    }
    definition = actor->definition;
    if ((u32)actor->resourceState < ((struct ResourceFadeDefinition *)definition)->threshold * 2) {
        return ((struct ResourceFadeDefinition *)definition)->nearValue;
    }
    return ((struct ResourceFadeDefinition *)definition)->farValue;
}
