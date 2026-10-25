#include "COMMON/WORLD.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "WORLD_2/8024E914.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PROPGEOMETRY.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "ACTORS/80277444_2.H"
#include "GAME/CODE_8027302C.H"
#include "WORLD_2/8024E914_8.H"
#include "SCENE/802508E0_4.H"

/** Clear the word at object offset 0x1C4. */
void func_8024F470_de(void *staticObject) {
    ((StaticObject *)(staticObject))->cached = 0;
}

CQuatern func_8024D870_de(void *);
CQuatern func_8024F478_de(void *actor) {
    return func_8024D870_de(actor);
}


extern func_8020CA10_G1 D_800C3DF8_de;

extern func_8020CA10_G1 D_800C3DFC_de;

extern f32 D_800D2988;

extern struct Shape_func_8021A2D4_de_2 D_800CD8D0;
extern GlobalStateRecAt1C D_80146894;

void func_8024F4A0_de(void *arg0) {
    char *o = (char *) arg0;
    f32 temp_f1;
    f32 threshold;
    f32 final_value;

    ((StaticObject *)(o))->model = func_8024F858_de(arg0);
    ((StaticObject *)(o))->material = ((PropGeometry *)(((StaticObject *)(o))->type))->material;

    if (D_80146894.field0 == 0) {
        char *state = ((StaticObject *)(o))->type;
        if (*(s32 *)state == 0xC) {
            ((StaticObject *)(o))->frameDelta = D_800D2988 * ((PropGeometry *)(state))->speed;
        } else if (((StaticObject *)(o))->flags & 0x10) {
            temp_f1 = ((StaticObject *)(o))->scaleTime + D_800D2988 * D_800C3DF0_de;
            threshold = (&D_800C3DF0_de)[1];
            ((StaticObject *)(o))->scaleTime = temp_f1;
            if (temp_f1 < threshold) {
                ((StaticObject *)(o))->scale = temp_f1 * D_800C3DF8_de.unk0;
            } else {
                final_value = D_800C3DFC_de.unk0;
                ((StaticObject *)(o))->flags &= 0xFFEF;
                ((StaticObject *)(o))->scale = final_value;
            }
        }

        if (((StaticObject *)(o))->room != 0) {
            ((StaticObject *)(o))->scene = ((MenuRules *)(((StaticObject *)(o))->room))->locked;
        } else {
            ((StaticObject *)(o))->scene = D_800CD8D0.field_0;
        }
    }
}

extern f32 D_800D2988;

void func_8024F5A0_de(StaticObject *staticObject) {
    f32 temp_f1;
    f32 threshold;
    f32 final_value;

    if (staticObject->flags & 0x10) {
        temp_f1 = staticObject->scaleTime +
                  D_800D2988 * D_800C3E00_de;
        threshold = (&D_800C3E00_de)[1];
        staticObject->scaleTime = temp_f1;
        if (temp_f1 < threshold) {
            staticObject->scale = temp_f1 * D_800C3E08_de;
            return;
        }
        final_value = D_800C3E0C_de;
        staticObject->flags &= 0xFFEF;
        staticObject->scale = final_value;
    }
}

/** Stores D_800D2988 times the float at 0x20 of the object at 0x18 in the float at 0x1A4. */
extern float D_800D2988;

void func_8024F618_de(StaticObject *staticObject) {
    void *p = staticObject->type;
    staticObject->frameDelta = (D_800D2988) * (((PropGeometry *)(p))->speed);
}

extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
extern s32 func_8027254C_de(f32 *arg0, f32 arg1);
extern void func_80273448_de(char *object, float x, float y, float z);
extern void func_80273D6C_de(void *object);
extern void func_8027027C_de(void *arg0, void *arg1);


void func_8024F634_de(void *arg0) {
    char *o = (char *) arg0;
    f32 matrix[16];

    if (*(s32 *)((StaticObject *)o)->type == 8) {
        func_802736D4_de(matrix, D_8011FE88.elapsed);
    } else {
        func_802736D4_de(matrix, ((StaticObject *)o)->angle);
    }

    func_8027347C_de(matrix, ((StaticObject *)(o))->scale, ((StaticObject *)(o))->scale, ((StaticObject *)(o))->scale);

    func_8027254C_de(&((StaticObject *)(o))->position.x, 20000.0f);

    func_80273448_de((char *) matrix, ((StaticObject *)(o))->position.x, ((StaticObject *)(o))->position.y + ((StaticObject *)(o))->height, ((StaticObject *)(o))->position.z);

    func_80273D6C_de(matrix);

    func_8027027C_de(matrix, (D_800D297C << 6) + 0x68 + o);
}

extern void func_80253838_de(void *arg0, void *arg1);
extern s32 func_802540F4_de(s32, void **, s32, void *, s32);
extern s32 func_8028FE28_de(s32 *, s32, s32);
extern s32 Render_LocatePackSection(s32, s32, s32, s32 *);

extern char D_0026D7F4;
extern char D_800C3DA8_de;
extern char D_800C3DC0_de[];
extern char D_800C3DD4_de[];

void **func_8024F6EC_de(void *arg0, s32 arg1) {
    void *sp28;
    void **resource;
    s32 key;
    s32 found;

    if (arg1 != ((func_8022FD9C_Record *)(arg0))->unk54) {
        resource = Scene_RequestResource(0, ((Access_s32_50 *)(arg0))->field,
                                ((Access_s32_50 *)(arg0))->field, 0x18,
                                0, 0, 0, &D_800C3DA8_de + 4, 1);
        if (resource != 0) {
            key = func_8028FE28_de(*resource, ((Access_s32_50 *)(arg0))->field, 1);
            func_80253838_de(0, resource);
            found = func_802540F4_de(0, &sp28, key, D_800C3DC0_de, 1);
            if (found != 0) {
                ((StaticObject *)(arg0))->resource = Render_LocatePackSection((s32)sp28, key,
                                                    arg1 % *(s32 *)sp28,
                                                    &((Access_s32_5C *)(arg0))->field);
                ((func_8022FD9C_Record *)(arg0))->unk54 = arg1;
                func_80253838_de(0, (void *)found);
            }
        }
    }
    if (((StaticObject *)(arg0))->resource != 0) {
        return Scene_RequestResource(0, ((StaticObject *)(arg0))->resource,
                             ((StaticObject *)(arg0))->resource, ((Access_s32_5C *)(arg0))->field,
                             0, 0, &D_0026D7F4, D_800C3DD4_de, 0);
    }
    return 0;
}


extern s32 D_801462C8;
extern s32 func_8028B25C_de(void *arg0, s32 arg1);

s32 func_8024F858_de(StaticObject *staticObject) {
    void *obj;
    s32 value;
    s32 index;

    obj = staticObject->type;
    if (*(s32 *)obj == 0xC) {
        return 0;
    }

    value = ((PropGeometry *)(obj))->variant;
    index = func_8028B25C_de(&D_8011FE88, staticObject->id);
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

extern void func_80253E64_de(s32 a, s32 **b, s32 c);

void func_8024F8DC_de(void *arg0, s32 **arg1) {
    s32 new_var;
    new_var = **arg1;
    func_80253E64_de(0, arg1, Actors_BuildLitModel(new_var, *((StaticObject *)(arg0))->renderResource, &((StaticObject *)(arg0))->effect[0], (s32)((char *)arg0 + ((D_800D297C << 6) + 0x68)), 0, arg0));
}
