#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024E914.h"
#include "types.h"

/** Clear the word at object offset 0x1C4. */
void func_8024F470_de(void *arg0) {
    ((Object_func_8024EB90_de *)(arg0))->cached = 0;
}

s32 func_8024D870_de();
s32 func_8024F478_de(s32 arg0) {
    func_8024D870_de();
    return arg0;
}

extern s32 func_8024F858_de(void *arg0);

extern func_8020CA10_G1 D_800C3DF8_de;

extern func_8020CA10_G1 D_800C3DFC_de;

extern f32 D_800D2988;

extern struct Shape_func_8021A2D4_de_2 D_800CD8D0;
extern GlobalState_func_8024F4A0_de D_80146894;

void func_8024F4A0_de(void *arg0) {
    char *o = (char *) arg0;
    f32 temp_f1;
    f32 threshold;
    f32 final_value;

    ((Object_func_8024EB90_de *)(o))->model = func_8024F858_de(arg0);
    ((Object_func_8024EB90_de *)(o))->material = ((PropGeometry *)(((Object_func_8024EB90_de *)(o))->type))->material;

    if (D_80146894.field0 == 0) {
        char *state = ((Object_func_8024EB90_de *)(o))->type;
        if (*(s32 *)state == 0xC) {
            ((Object_func_8024EB90_de *)(o))->frameDelta = D_800D2988 * ((PropGeometry *)(state))->speed;
        } else if (((Object_func_8024EB90_de *)(o))->flags & 0x10) {
            temp_f1 = ((Object_func_8024EB90_de *)(o))->scaleTime + D_800D2988 * D_800C3DF0_de;
            threshold = (&D_800C3DF0_de)[1];
            ((Object_func_8024EB90_de *)(o))->scaleTime = temp_f1;
            if (temp_f1 < threshold) {
                ((Object_func_8024EB90_de *)(o))->scale = temp_f1 * D_800C3DF8_de.unk0;
            } else {
                final_value = D_800C3DFC_de.unk0;
                ((Object_func_8024EB90_de *)(o))->flags &= 0xFFEF;
                ((Object_func_8024EB90_de *)(o))->scale = final_value;
            }
        }

        if (((Object_func_8024EB90_de *)(o))->room != 0) {
            ((Object_func_8024EB90_de *)(o))->scene = ((MenuRules *)(((Object_func_8024EB90_de *)(o))->room))->locked;
        } else {
            ((Object_func_8024EB90_de *)(o))->scene = D_800CD8D0.field_0;
        }
    }
}

extern f32 D_800D2988;

void func_8024F5A0_de(void *arg0) {
    f32 temp_f1;
    f32 threshold;
    f32 final_value;

    if (((Object_func_8024EB90_de *)(arg0))->flags & 0x10) {
        temp_f1 = ((Object_func_8024EB90_de *)(arg0))->scaleTime +
                  D_800D2988 * D_800C3E00_de;
        threshold = (&D_800C3E00_de)[1];
        ((Object_func_8024EB90_de *)(arg0))->scaleTime = temp_f1;
        if (temp_f1 < threshold) {
            ((Object_func_8024EB90_de *)(arg0))->scale = temp_f1 * D_800C3E08_de;
            return;
        }
        final_value = D_800C3E0C_de;
        ((Object_func_8024EB90_de *)(arg0))->flags &= 0xFFEF;
        ((Object_func_8024EB90_de *)(arg0))->scale = final_value;
    }
}

/** Stores D_800D2988 times the float at 0x20 of the object at 0x18 in the float at 0x1A4. */
extern float D_800D2988;

void func_8024F618_de(void *arg0) {
    void *p = ((Object_func_8024EB90_de *)(arg0))->type;
    ((Object_func_8024EB90_de *)(arg0))->frameDelta = (D_800D2988) * (((PropGeometry *)(p))->speed);
}

extern void func_802736D4_de(void *, s32);
extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
extern s32 func_8027254C_de(f32 *arg0, f32 arg1);
extern void func_80273448_de(char *object, float x, float y, float z);
extern void func_80273D6C_de(void *object);
extern void func_8027027C_de(void *arg0, void *arg1);

extern s32 D_800D297C;

void func_8024F634_de(void *arg0) {
    char *o = (char *) arg0;
    f32 sp10[16];
    s32 var_a1;

    if (*(s32 *) (((Object_func_8024EB90_de *)(o))->type) == 8) {
        var_a1 = D_8013B190;
    } else {
        var_a1 = ((Object_func_8024EB90_de *)(o))->angle;
    }
    func_802736D4_de(sp10, var_a1);

    func_8027347C_de(sp10, ((Object_func_8024EB90_de *)(o))->scale, ((Object_func_8024EB90_de *)(o))->scale, ((Object_func_8024EB90_de *)(o))->scale);

    func_8027254C_de(&((Object_func_8024EB90_de *)(o))->position.x, 20000.0f);

    func_80273448_de((char *) sp10, ((Object_func_8024EB90_de *)(o))->position.x, ((Object_func_8024EB90_de *)(o))->position.y + ((Object_func_8024EB90_de *)(o))->height, ((Object_func_8024EB90_de *)(o))->position.z);

    func_80273D6C_de(sp10);

    func_8027027C_de(sp10, (D_800D297C << 6) + 0x68 + o);
}

extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern void func_80253838_de(void *, void *);
extern s32 func_802540F4_de(s32, void **, s32, void *, s32);
extern s32 func_8028FE28_de(s32 *, s32, s32);
extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);

extern char D_0026D7F4;
extern char D_800C3DA8_de;
extern char D_800C3DC0_de;
extern char D_800C3DD4_de;

void **func_8024F6EC_de(void *arg0, s32 arg1) {
    void *sp28;
    void **resource;
    s32 key;
    s32 found;

    if (arg1 != ((func_8022FD9C_Record *)(arg0))->unk54) {
        resource = func_8025193C_de(0, ((Access_s32_50 *)(arg0))->field,
                                ((Access_s32_50 *)(arg0))->field, 0x18,
                                0, 0, 0, &D_800C3DA8_de + 4, 1);
        if (resource != 0) {
            key = func_8028FE28_de(*resource, ((Access_s32_50 *)(arg0))->field, 1);
            func_80253838_de(0, resource);
            found = func_802540F4_de(0, &sp28, key, &D_800C3DC0_de, 1);
            if (found != 0) {
                ((Object_func_8024EB90_de *)(arg0))->resource = func_8028FE3C_de((s32)sp28, key,
                                                    arg1 % *(s32 *)sp28,
                                                    &((Access_s32_5C *)(arg0))->field);
                ((func_8022FD9C_Record *)(arg0))->unk54 = arg1;
                func_80253838_de(0, (void *)found);
            }
        }
    }
    if (((Object_func_8024EB90_de *)(arg0))->resource != 0) {
        return func_8025193C_de(0, ((Object_func_8024EB90_de *)(arg0))->resource,
                             ((Object_func_8024EB90_de *)(arg0))->resource, ((Access_s32_5C *)(arg0))->field,
                             0, 0, &D_0026D7F4, &D_800C3DD4_de, 0);
    }
    return 0;
}


extern s32 D_801462C8;
extern s32 func_8028B25C_de(void *arg0, s32 arg1);

s32 func_8024F858_de(void *arg0) {
    void *obj;
    s32 value;
    s32 index;

    obj = ((Object_func_8024EB90_de *)(arg0))->type;
    if (*(s32 *)obj == 0xC) {
        return 0;
    }

    value = ((PropGeometry *)(obj))->variant;
    index = func_8028B25C_de(&D_8011FE88, ((Object_func_8024EB90_de *)(arg0))->id);
    if (index < 0x6AB) {
        if (index < 0x6A9) {
            return value;
        }
        if (D_801462C8 & 0x800) {
            value = 1;
        }
        if (D_801462C8 & 0x1000) {
            value = 2;
        }
    }
    return value;
}

extern s32 func_802784C0_de(s32 a, s32 b, void *c, s32 d, s32 e, void *f);
extern void func_80253E64_de(s32 a, s32 **b, s32 c);
extern s32 D_800D297C;

void func_8024F8DC_de(void *arg0, s32 **arg1) {
    s32 new_var;
    new_var = **arg1;
    func_80253E64_de(0, arg1, func_802784C0_de(new_var, *((Object_func_8024EB90_de *)(arg0))->renderResource, &((Object_func_8024EB90_de *)(arg0))->effect[0], (s32)((char *)arg0 + ((D_800D297C << 6) + 0x68)), 0, arg0));
}
