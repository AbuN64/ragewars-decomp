#include "span_1000/code_802508E0.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "shared/level_actor.h"
#include "shared/level_spawn.h"
#include "span_1000/code_8024E914.h"
#include "types.h"

/* Returns the matching resource entry index, or minus one when absent. */
extern void *func_8028FDB4_de(int,int);

extern void *func_802507AC_de(ResourceOwner *owner,s32 index);

extern void func_8026E158_de(void **arg0);

extern void func_80253754_de(s32 arg0, s32 arg1);

extern s32 D_800CD3F0;

extern char D_00250C2C;

extern char D_800C3E40_de;

s32 func_80250274_de();

s32 func_802504B0_de();

extern u8 D_801462E5;

extern void func_80253F8C_de(s32 arg0, s32 arg1);

extern s32 *func_8026E27C_de(void **arg0, s32 arg1, s32 *arg2);

extern s32 D_800D15E0;

extern void func_80253BBC_de(s32, s32);

extern void func_8027892C_de(void *object, void *colors);

extern void func_8026DA4C_de(s32, void *, s32, s32, void *, s32);

extern void func_8026DC24_de(s32, void *, s32, s32, void *, s32);

extern void func_80253754_de(s32, s32);

int func_80250938_de(void *wanted,int key) {
 int result=-1; int i,count,offset; char *entries;
 LevelNode *h=func_8028FDB4_de(key,0);
 count=h->count; entries=(char *)h->records;
i=0; if(count>0) {offset=i; do {if(entries+offset!=wanted) {i++;offset+=232;} else {result=i;break;}}while(i<count);}return result;}

void func_802509A8_de(void *arg0) {
    extern s32 func_80251F6C_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, void *arg7, s32 arg8);
    struct ResourceBinding *o = (struct ResourceBinding *) arg0;
    void *temp_v0;
    s32 ret2;

    if (!(o->status & 0x40)) {
        temp_v0 = func_802507AC_de(arg0, o->variant);
        if (temp_v0 != 0) {
            func_8026E158_de((void **) temp_v0);
            ret2 = func_80251F6C_de(0, o->registrationFlags | D_800CD3F0, temp_v0, (s32)o->resource, 8, arg0, &D_00250C2C, &D_800C3E40_de, 0);
            if (ret2 != 0) {
                func_80253754_de(0, ret2);
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

void func_80250A9C_de(void) {
    if (D_801462E5 != 0) {
        func_802504B0_de();
        return;
    }
    func_80250274_de();
}

void func_80250AD4_de(void *arg0) {
    struct ResourceBinding *binding = arg0;
    if (!(binding->status & 0x40) && (binding->colorFrame != D_800D297B)) {
        func_80253F8C_de(0, binding->registrationFlags | D_800CD3F0);
    }
}

s32 *func_80250B24_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    extern s32 func_80251F6C_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, void *arg7, s32 arg8);
    struct ResourceBinding *o = (struct ResourceBinding *) arg0;
    void *temp_v0;
    s32 *var_s1;
    s32 ret2;

    var_s1 = arg3;
    temp_v0 = func_802507AC_de(arg0, arg2);
    if (temp_v0 != 0) {
        o->loadedResource = temp_v0;
        *var_s1 = (s32) temp_v0;
        var_s1 = func_8026E27C_de(temp_v0, arg1, var_s1 + 1);
        ret2 = func_80251F6C_de(0, o->registrationFlags | D_800CD3F0, temp_v0, (s32)o->resource, 8, arg0, &D_00250C2C, &D_800C3E40_de, 1);
        if (ret2 != 0) {
            *var_s1 = ret2;
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
  func_80253E64_de(0, arg1, func_802784C0_de(new_var, *binding->resource, binding->runtimeState, (s32)binding->transform, 0, arg0));
}

void func_80250C84_de(Owner_func_80250C84_de *owner, s32 unused, s32 arg2, s32 key) {
    extern s32 func_80251F6C_de(s32, s32, s32, s32, s32, void *, void *, void *, s32);
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
