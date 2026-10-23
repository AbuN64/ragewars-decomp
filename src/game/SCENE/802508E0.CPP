#include "COMMON/MODEL_RENDER.H"
#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/LEVEL_SPAWN.H"
#include "COMMON/PROPGEOMETRY.H"
#include "TYPES.H"
#include "ACTORS/80277444_2.H"
#include "SCENE/802508E0.H"
#include "RENDER_4/8028FD2C_6.H"
extern s32 D_800D2978;

/* Returns the matching resource entry index, or minus one when absent. */

extern void *func_802507AC_de(ResourceOwner *owner,s32 index);

extern void func_8026E158_de(void **arg0);

extern void func_80253754_de(s32 arg0, s32 arg1);

extern s32 D_800CD3F0;

extern char D_00250C2C;

extern char D_800C3E40_de;

void func_80250274_de(void *);

void func_802504B0_de(void *);

extern u8 D_801462E5;

extern void func_80253F8C_de(s32 arg0, s32 arg1);

extern s32 *func_8026E27C_de(void **arg0, s32 arg1, s32 *arg2);

extern s32 D_800D15E0;

extern void func_80253BBC_de(s32, s32);

extern void func_8027892C_de(void *object, void *colors);

extern void Render_QueueModelInstance(void **, void *, s32, void *, void *, s32);

extern void func_80253754_de(s32, s32);

int func_80250938_de(void *wanted,int key) {
 int result=-1; int i,count,offset; char *entries;
 LevelNode *h=func_8028FDB4_de(key,0);
 count=h->count; entries=(char *)h->records;
i=0; if(count>0) {offset=i; do {if(entries+offset!=wanted) {i++;offset+=232;} else {result=i;break;}}while(i<count);}return result;}

void func_802509A8_de(void *arg0) {
    struct ResourceBinding *o = (struct ResourceBinding *) arg0;
    void *temp_v0;
    CachedResource *ret2;

    if (!(o->status & 0x40)) {
        temp_v0 = func_802507AC_de(arg0, o->variant);
        if (temp_v0 != 0) {
            func_8026E158_de((void **) temp_v0);
            ret2 = func_80251F6C_de(0, o->registrationFlags | D_800CD3F0, temp_v0, (CachedResource *)o->resource, 8, arg0, &D_00250C2C, &D_800C3E40_de, 0);
            if (ret2 != 0) {
                func_80253754_de(0, (s32)ret2);
            }
            func_80253754_de(0, (s32) temp_v0);
        }
    }
}

/** Return the nested signed byte unless flag 0x40 suppresses it. */
int func_80250A64_de(char *object) {
    if (((ObjectLinksDC *)(object))->unk_D8 & 0x40) {
        return 0;
    }
    return ((struct ObjectState13 *) ((ObjectLinksDC *) object)->unk_18)->unk_12;
}

/** Read the signed byte at offset 0xE from the object's linked record. */
signed char func_80250A8C_de(struct PlacedProp *object) {
    void *linked = object->model;
    return ((signed char *)linked)[0xE];
}

void func_80250A9C_de(void *owner) {
    if (D_801462E5 != 0) {
        func_802504B0_de(owner);
        return;
    }
    func_80250274_de(owner);
}

void func_80250AD4_de(void *arg0) {
    struct ResourceBinding *binding = arg0;
    if (!(binding->status & 0x40) && (binding->colorFrame != (u8)D_800D2978)) {
        func_80253F8C_de(0, binding->registrationFlags | D_800CD3F0);
    }
}

s32 *func_80250B24_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    struct ResourceBinding *o = (struct ResourceBinding *) arg0;
    void *temp_v0;
    s32 *var_s1;
    CachedResource *ret2;

    var_s1 = arg3;
    temp_v0 = func_802507AC_de(arg0, arg2);
    if (temp_v0 != 0) {
        o->loadedResource = temp_v0;
        *var_s1 = (s32) temp_v0;
        var_s1 = func_8026E27C_de(temp_v0, arg1, var_s1 + 1);
        ret2 = func_80251F6C_de(0, o->registrationFlags | D_800CD3F0, temp_v0, (CachedResource *)o->resource, 8, arg0, &D_00250C2C, &D_800C3E40_de, 1);
        if (ret2 != 0) {
            *var_s1 = (s32)ret2;
            var_s1 += 1;
        }
    }
    return var_s1;
}

/** Advance the wrapping counter D_800D0910, resetting to 0x380000 at 0x3FFFFF. */
int func_80250BF0_de(void) {
    int temp_v0;

    temp_v0 = D_800D0910 + 1;
    D_800D0910 = temp_v0;
    if (temp_v0 == 0x3FFFFF) {
        D_800D0910 = 0x380000;
    }
    return D_800D0910;
}

void func_80250C2C_de(void *arg0, s32 **arg1)
{
  struct ResourceBinding *binding = arg0;
  s32 new_var;
  new_var = *(*arg1);
  func_80253E64_de(0, arg1, Actors_BuildLitModel(new_var, *binding->resource, binding->runtimeState, (s32)binding->transform, 0, arg0));
}

void func_80250C84_de(Owner_func_80250C84_de *owner, s32 unused, s32 arg2, s32 key) {
    void *instance;
    CachedResource *resource;
    s32 *header;
    char *data;

    instance = func_802507AC_de(owner, key);
    if (instance == 0) {
        return;
    }
    resource = func_80251F6C_de(0, owner->flagsD0 | D_800CD3F0, instance, (CachedResource *)owner->field20, 8, owner, &D_00250C2C,
                             &D_800C3E40_de, 0);
    if (resource != 0) {
        func_80253BBC_de(0, (s32)resource);
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
            func_8026DA4C_de(instance, owner->transform, 0, 0, data, arg2);
        } else {
            Render_QueueModelInstance(instance, owner->transform, 0, 0, data, arg2);
        }
        func_80253754_de(0, (s32)resource);
    }
    func_80253754_de(0, (s32)instance);
    owner->colorFrame = (u8)D_800D2978;
}

/** Select one of two signed bytes according to a doubled nested count. */
int func_80250DE0_de(void *object) {
    LevelActor *actor = object;
    struct ResourceFadeDefinition *nested = (struct ResourceFadeDefinition *)actor->definition;
    if ((u32)actor->resourceState <
        nested->threshold * 2) {
        return nested->nearValue;
    }
    return nested->farValue;
}

s8 func_80250E14_de(LevelActor *arg0) {
    void *temp_a1;

    if (D_801462E5 != 0) {
        return ((struct ResourceFadeDefinition *)arg0->definition)->nearValue;
    }
    temp_a1 = arg0->definition;
    if ((u32)arg0->resourceState < ((struct ResourceFadeDefinition *)temp_a1)->threshold * 2) {
        return ((struct ResourceFadeDefinition *)temp_a1)->nearValue;
    }
    return ((struct ResourceFadeDefinition *)temp_a1)->farValue;
}
