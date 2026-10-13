#include "common/unused.h"
#include "shared/gameplay_round_rules.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80258820.h"
#include "span_1000/code_8025C544.h"
#include "types.h"

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
extern void func_8025BE08_de(void *arg0, s32 arg1);
extern void func_80259988_de(void *arg0, s32 arg1);






void func_80258800_de(void *arg0, s32 arg1) {
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_a0;

        temp_s0 = &((Context_func_80257360_de *)(arg0))->lock;
        temp_a0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 1) {
            func_802BCF50_de(temp_a0);
            func_802BB2A0_de((s32)temp_s0, 0, 1);
        } else {
            func_802BCF50_de(temp_a0);
        }
    }
    func_8025BE08_de(&((Context_func_80257360_de *)(arg0))->menu[0], arg1);
    func_80259988_de(&((Context_func_80257360_de *)(arg0))->view[0], arg1);
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &((Context_func_80257360_de *)(arg0))->lock;
        temp_v0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 0) {
            func_802BCF50_de(temp_v0);
            func_802BB420_de(temp_s0, 0, 1);
        } else {
            func_802BCF50_de(temp_v0);
        }
    }
}

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_8025BF08_de(void *, s32);
extern void func_802599EC_de(void *, s32);
extern void func_802BB420_de(void *, s32, s32);






void func_802588D4_de(void *arg0, s32 arg1) {
    void *temp_s0;
    void *var_a0;
    s32 temp_v1;
    u32 temp_a0;
    u32 temp_v0;

    temp_s0 = &((Context_func_80257360_de *)(arg0))->lock;
    temp_a0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de((s32)temp_s0, 0, 1);
        var_a0 = &((Context_func_80257360_de *)(arg0))->menu[0];
    } else {
        func_802BCF50_de(temp_a0);
        var_a0 = &((Context_func_80257360_de *)(arg0))->menu[0];
    }
    func_8025BF08_de(var_a0, arg1);
    func_802599EC_de(&((Context_func_80257360_de *)(arg0))->view[0], arg1);
    temp_s0 = &((Context_func_80257360_de *)(arg0))->lock;
    temp_v0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(temp_s0, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
extern void func_8025C008_de(void *arg0, s32 arg1);
extern void func_80259A50_de(void *arg0, s32 arg1);






void func_802589A8_de(void *arg0, s32 arg1) {
    void *temp_s0;
    void *var_a0;
    s32 temp_v1;
    u32 temp_a0;
    u32 temp_v0;

    temp_s0 = &((Context_func_80257360_de *)(arg0))->lock;
    temp_a0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 1) {
        func_802BCF50_de(temp_a0);
        func_802BB2A0_de((s32)temp_s0, 0, 1);
        var_a0 = &((Context_func_80257360_de *)(arg0))->menu[0];
    } else {
        func_802BCF50_de(temp_a0);
        var_a0 = &((Context_func_80257360_de *)(arg0))->menu[0];
    }
    func_8025C008_de(var_a0, arg1);
    func_80259A50_de(&((Context_func_80257360_de *)(arg0))->view[0], arg1);
    temp_s0 = &((Context_func_80257360_de *)(arg0))->lock;
    temp_v0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 0) {
        func_802BCF50_de(temp_v0);
        func_802BB420_de(temp_s0, 0, 1);
        return;
    }
    func_802BCF50_de(temp_v0);
}

extern f32 D_800C3EE0_de[];
extern s32 func_80257DD4_de(void *, s32, Vec3, s32, s32);




void func_80258A7C_de(void *arg0, s32 arg1, Vec3 arg2, s32 arg3, s32 arg4, f32 arg5) {
    ((Context_func_80257360_de *)(arg0))->alpha = arg5;
    func_80257DD4_de(arg0, arg1, arg2, arg3, arg4);
    ((Context_func_80257360_de *)(arg0))->alpha = D_800C3EE0_de[1];
}

extern char D_80145088;

extern s32 func_802934F8_de(void);
extern void *func_802395A4_de(s32 *arg0, Vec3 *arg1);
extern s32 func_80257DD4_de(void *, s32, Vec3, s32, s32);






void func_80258AE0_de(void *arg0) {
    Vec3 zero;
    void *result;
    Vec3 *vec;

    if (D_800CB720 != 0 &&
        ((Context_func_80257360_de *)(arg0))->field2BB4 != 0 &&
        func_802934F8_de() != 0 &&
        ((Context_func_80257360_de *)(arg0))->track > 0) {
        {
            register f32 value = 0.0f;

            zero.z = value;
            zero.y = value;
            zero.x = value;
        }
        result = func_802395A4_de(&D_80145088, &zero);
        vec = &((struct Shared_func_80227014_S4 *)(result))->position;
        if ((((Context_func_80257360_de *)(arg0))->frame & 3) == 0) {
            func_80257DD4_de(arg0, ((Context_func_80257360_de *)(arg0))->track, *vec, 0, -1);
        }
    }
}

void func_80258B8C_de(void *arg0, float arg1) {
    ((Context_func_80257360_de *)(arg0))->red = arg1;
}

void func_80258B94_de(void *arg0, int arg1) {
    double d = (double)arg1;
    if (arg1 < 0) {
        d = d + D_800C3EE8_de;
    }
    ((Context_func_80257360_de *)(arg0))->green = (float)d;
}

/** Store the second argument at byte offset 0x2BA8 in the first argument. */
void func_80258BBC_de(void *object, float value) {
    ((Context_func_80257360_de *)(object))->blue = value;
}

/** Return the indexed twelve-byte record from the table at offset 0x2B70. */
char *func_80258BC4_de(char *object, int index) {
    return ((Context_func_80257360_de *)(object))->table2B70 + index * 12;
}

void *func_80258BDC_de(void *arg0, int arg1) {
    return (char *)((Context_func_80257360_de *)(arg0))->table2B74 + arg1 * 12;
}

/** Return the indexed 12-byte entry under object offset 0x2B78. */
void *func_80258BF4_de(void *arg0, int arg1) {
    return (char *)((Context_func_80257360_de *)(arg0))->table2B78 + arg1 * 12;
}

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
extern void func_8025B5F0_de(void *arg0, s32 arg1);
extern void func_80259918_de(void *arg0, s32 arg1);







void func_80258C0C_de(void *arg0, s32 arg1) {
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_a0;

        temp_s0 = &((Context_func_80257360_de *)(arg0))->lock;
        temp_a0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 1) {
            func_802BCF50_de(temp_a0);
            func_802BB2A0_de((s32)temp_s0, 0, 1);
        } else {
            func_802BCF50_de(temp_a0);
        }
    }
    func_8025B5F0_de(&((Context_func_80257360_de *)(arg0))->menu[0], arg1);
    func_80259918_de(&((Context_func_80257360_de *)(arg0))->view[0], arg1);
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &((Context_func_80257360_de *)(arg0))->lock;
        ((Context_func_80257360_de *)(arg0))->field2B9C = 0;
        temp_v0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 0) {
            func_802BCF50_de(temp_v0);
            func_802BB420_de(temp_s0, 0, 1);
        } else {
            func_802BCF50_de(temp_v0);
        }
    }
    func_8025D1BC_de((char *)arg0 + 0x2BC0);
}

extern void func_8025DACC_de(int a);

/** Thin wrapper forwarding an offset argument to func_8025DACC_de. */
void func_80258CEC_de(int arg0) {
    func_8025DACC_de(arg0 + 0x1D64);
}

/** Store the second argument at offset 0x2BAC. */
void func_80258D08_de(void *arg0, int arg1) {
    ((Context_func_80257360_de *)(arg0))->field2BAC = arg1;
}

int func_80258D10_de(void *arg0) {
    return ((Context_func_80257360_de *)(arg0))->field2BAC;
}

/** Store a value in the field at offset 0x2BB4. */
void func_80258D1C_de(char *object, int value) {
    ((Context_func_80257360_de *)(object))->field2BB4 = value;
}

/** Store a value in the field at offset 0x2B98. */
void func_80258D24_de(void *object, int value) {
    ((Context_func_80257360_de *)(object))->field2B98 = value;
}

/** Read the object word at offset 0x2BB0. */
int func_80258D2C_de(void *object) {
    return ((Context_func_80257360_de *)(object))->field2BB0;
}

/** Store the supplied word at object offset 0x2BB0. */
void func_80258D38_de(void *arg0, int arg1) {
    ((Context_func_80257360_de *)(arg0))->field2BB0 = arg1;
}

void *func_80258D40_de(void *arg0) {
    return &((Context_func_80257360_de *)(arg0))->list[0];
}

/** Store a word in the object field at offset 0x2BB8. */
void func_80258D48_de(void *object, int value) {
    ((Context_func_80257360_de *)(object))->field2BB8 = value;
}

/* Counts how many of an object's seventeen 0xCC-byte slots at 0x1DC0 hold a given owner, holding the object's lock at 0x110 (raised and released under interrupts disabled through func_802BCF30_de and func_802BCF50_de) around the scan. */

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern void func_802BB2A0_de(s32, s32, s32);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);






s32 func_80258D50_de(char *obj, s32 owner)
{
    s32 count;
    s32 i;

    count = 0;
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_a0;

        temp_s0 = &((Context_func_80257360_de *)(obj))->lock;
        temp_a0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 1) {
            func_802BCF50_de(temp_a0);
            func_802BB2A0_de((s32)temp_s0, 0, 1);
        } else {
            func_802BCF50_de(temp_a0);
        }
    }
    for (i = 0; i < 17; i++) {
        if (((Context_func_80257360_de *)obj)->voices[i].sound == owner) {
            count++;
        }
    }
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &((Context_func_80257360_de *)(obj))->lock;
        temp_v0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 0) {
            func_802BCF50_de(temp_v0);
            func_802BB420_de(temp_s0, 0, 1);
        } else {
            func_802BCF50_de(temp_v0);
        }
    }
    return count;
}

extern void func_8025DB58_de(int a);

/** Thin wrapper forwarding an offset argument to func_8025DB58_de. */
void func_80258E40_de(int arg0) {
    func_8025DB58_de(arg0 + 0x1D64);
}

/* Clamps a level to between zero and D_800C8FE0, scales it by D_800C8FE4 and stores it as an integer
   at 0x2B9C of the object. */





void func_80258E5C_de(Obj_func_80258E5C_de *obj, float value) {
    float v;
    float max = D_800C8FE0;
    if (value > max || !(value < 0.0f)) {
        v = value;
        if (v > max) {
            v = max;
        }
    } else {
        v = 0.0f;
    }
    obj->level = v * D_800C8FE4;
}

extern void func_8025DB34_de(int a);

/** Thin wrapper forwarding an offset argument to func_8025DB34_de. */
void func_80258EBC_de(int arg0) {
    func_8025DB34_de(arg0 + 0x1D64);
}

extern void func_8025DB44_de(int a);

/** Thin wrapper forwarding an offset argument to func_8025DB44_de. */
void func_80258ED8_de(int arg0) {
    func_8025DB44_de(arg0 + 0x1D64);
}

extern void func_8025BB3C_de(int a);

/** Thin wrapper forwarding an offset argument to func_8025BB3C_de. */
void func_80258EF4_de(int arg0) {
    func_8025BB3C_de(arg0 + 0x1DB8);
}

extern int func_8025CED0_de(void *arg0, int arg1, float arg2, int arg3);




int func_80258F10_de(void *arg0, int arg1) {
    float var_f0 = (1.0f);
    float temp_f1 = ((Context_func_80257360_de *)(arg0))->blue;
    if (!(var_f0 < temp_f1)) {
        var_f0 = temp_f1;
    }
    return func_8025CED0_de(&((Context_func_80257360_de *)(arg0))->dialog[0], arg1, var_f0, 0x40);
}

/** Thin wrapper forwarding an offset argument to func_8025D1BC_de. */
void func_80258F50_de(int arg0) {
    func_8025D1BC_de(arg0 + 0x2BC0);
}

/** Sort the table's word entries into ascending unsigned order. */
void func_80258F6C_de(SortTable *table) {
    int i;
    int j;
    u32 right;
    u32 left;

    for (i = 0; i < table->count; i++) {
        for (j = i + 1; j < table->count; j++) {
            right = table->entries[j];
            left = table->entries[i];
            if (right < left) {
                table->entries[i] = right;
                table->entries[j] = left;
            }
        }
    }
}

/* Returns the index of the first of seventeen 0xCC-byte slots at offset 0x1DBC whose id at 0xC
   equals the given id, or -1 when the id is -1 or absent. */




int func_80258FF4_de(char *arg0, int id) {
    Voice *slot;
    int i;
    slot = ((Context_func_80257360_de *)arg0)->voices;
    if (id == -1) {
        return -1;
    }
    for (i = 0; i < 17; i++, slot++) {
        if (slot->unkC == id) {
            return i;
        }
    }
    return -1;
}

/* Picks a weighted random entry from the range func_80265550_de finds for an id in a scene's table: -1 when
 * the scene has no table or no range, the single entry when the range has one; otherwise each entry weighs
 * ten times its table value, a random draw selects one, and when avoidance is requested and it equals the
 * scene's last pick at 0x130 it steps to the next entry (or back from the last). Adapted from
 * func_8025D238_de with the table weights and the stored last pick. */



extern s32 func_80265550_de(s32, s32, s32, s32 *, s32 *);
extern s32 func_802744D4_de(void);

s32 func_80259038_de(Scene_func_80259038_de *scene, s16 id, s16 avoid) {
    s32 first;
    s32 last;
    s32 total;
    s32 entry;
    s32 draw;
    s32 i;

    total = 0;
    if (scene->count != 0) {
        if (func_80265550_de(scene->ids, scene->count, id, &first, &last) == 0) {
            return -1;
        }
        entry = first;
        if (entry != last) {
            for (i = first; i <= last; i++) {
                total += scene->weights[i] * 10;
            }
            draw = func_802744D4_de() % total;
            total = 0;
            for (entry = first; entry < last; entry++) {
                total += scene->weights[entry] * 10;
                if (total >= draw) {
                        break;
                }
            }
            if (avoid != 0 && entry == scene->lastPick) {
                if (entry == last) {
                        entry--;
                } else {
                        entry++;
                }
            }
        }
        return entry;
    }
    return -1;
}
