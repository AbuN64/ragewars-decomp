#include "COMMON/EXTERNS.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/SELF.H"
#include "AUDIO_2/INTEGERSTATE1DC4.H"
#include "COMMON/LISTNODE.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/EXTERNS_18.H"
#include "AUDIO/8025A3EC_4.H"
#include "AUDIO_2/802591C0.H"
#include "AUDIO_2/8025CCB0_2.H"
#include "sdk/OS/8025DA30.H"
#include "sdk/os.h"
#include "SYSTEM_3/80265370.H"
#include "RENDER_4/8028FD2C_6.H"

extern u32 func_802BCF30_de(void);



extern void func_8025BE08_de(void *arg0, s32 arg1);

extern void func_8025BF08_de(void *, s32);


extern void func_8025C008_de(void *arg0, s32 arg1);

extern void func_80259A50_de(void *arg0, s32 arg1);

extern f32 D_800C3EE0_de[];

extern s32 func_802934F8_de(void);

extern void *func_802395A4_de(MenuMatchGlobals *arg0, CVector3 *arg1);

extern void func_8025B5F0_de(void *arg0, s32 arg1);

extern void func_80259918_de(void *arg0, s32 arg1);

extern void func_8025DACC_de(int a);

extern void func_8025DB34_de(Track *a);

extern void func_8025DB44_de(Track *a);

extern void func_8025BB3C_de(int a);

/* Picks a weighted random entry from the range func_80265550_de finds for an id in a scene's table: -1 when
 * the scene has no table or no range, the single entry when the range has one; otherwise each entry weighs
 * ten times its table value, a random draw selects one, and when avoidance is requested and it equals the
 * scene's last pick at 0x130 it steps to the next entry (or back from the last). Adapted from
 * func_8025D238_de with the table weights and the stored last pick. */




void func_80258800_de(ContextRecAt2BC0 *arg0, s32 arg1) {
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 mask;

        temp_s0 = &arg0->lock;
        mask = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 1) {
            __osRestoreInt(mask);
            osRecvMesg(temp_s0, 0, 1);
        } else {
            __osRestoreInt(mask);
        }
    }
    func_8025BE08_de(&arg0->menu[0], arg1);
    func_80259988_de(&arg0->view[0], arg1);
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &arg0->lock;
        temp_v0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(temp_v0);
            osSendMesg(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_v0);
        }
    }
}

struct OwnerRecAtD8;

void func_802588D4_de(ContextRecAt2BC0 *arg0, s32 arg1) {
    void *temp_s0;
    void *record;
    s32 temp_v1;
    u32 mask;
    u32 temp_v0;

    temp_s0 = &arg0->lock;
    mask = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        osRecvMesg(temp_s0, 0, 1);
        record = &arg0->menu[0];
    } else {
        __osRestoreInt(mask);
        record = &arg0->menu[0];
    }
    func_8025BF08_de(record, arg1);
    func_802599EC_de(&arg0->view[0], arg1);
    temp_s0 = &arg0->lock;
    temp_v0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 0) {
        __osRestoreInt(temp_v0);
        osSendMesg(temp_s0, 0, 1);
        return;
    }
    __osRestoreInt(temp_v0);
}

void func_802589A8_de(ContextRecAt2BC0 *arg0, s32 arg1) {
    void *temp_s0;
    void *record;
    s32 temp_v1;
    u32 mask;
    u32 temp_v0;

    temp_s0 = &arg0->lock;
    mask = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(mask);
        osRecvMesg(temp_s0, 0, 1);
        record = &arg0->menu[0];
    } else {
        __osRestoreInt(mask);
        record = &arg0->menu[0];
    }
    func_8025C008_de(record, arg1);
    func_80259A50_de(&arg0->view[0], arg1);
    temp_s0 = &arg0->lock;
    temp_v0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 0) {
        __osRestoreInt(temp_v0);
        osSendMesg(temp_s0, 0, 1);
        return;
    }
    __osRestoreInt(temp_v0);
}

void func_80258A7C_de(ContextRecAt2BC0 *arg0, s32 track, CVector3 arg2, s32 arg3, s32 arg4, f32 arg5) {
    arg0->alpha = arg5;
    Texture_PlaySoundAtPosition(arg0, track, arg2, arg3, arg4);
    arg0->alpha = D_800C3EE0_de[1];
}

void func_80258AE0_de(ContextRecAt2BC0 *arg0) {
    CVector3 zero;
    void *result;
    CVector3 *vec;

    if (D_800CB720 != 0 &&
        arg0->field2BB4 != 0 &&
        func_802934F8_de() != 0 &&
        arg0->track > 0) {
        {
            register f32 value = 0.0f;

            zero.z = value;
            zero.y = value;
            zero.x = value;
        }
        result = func_802395A4_de(&D_80145088, &zero);
        vec = &((struct SharedRecAt564V1 *)(result))->position;
        if ((arg0->frame & 3) == 0) {
            Texture_PlaySoundAtPosition(arg0, arg0->track, *vec, 0, -1);
        }
    }
}

void func_80258B8C_de(ContextRecAt2BC0 *arg0, float arg1) {
    arg0->red = arg1;
}

void func_80258B94_de(ContextRecAt2BC0 *arg0, int arg1) {
    double d = (double)arg1;
    if (arg1 < 0) {
        d = d + D_800C3EE8_de;
    }
    arg0->green = (float)d;
}

/** Store the second argument at byte offset 0x2BA8 in the first argument. */
void func_80258BBC_de(ContextRecAt2BC0 *object, float value) {
    object->blue = value;
}

/** Return the indexed twelve-byte record from the table at offset 0x2B70. */
char *func_80258BC4_de(char *object, int index) {
    return ((ContextRecAt2BC0 *)(object))->table2B70 + index * 12;
}

void *func_80258BDC_de(ContextRecAt2BC0 *arg0, int arg1) {
    return (char *)arg0->table2B74 + arg1 * 12;
}

/** Return the indexed 12-byte entry under object offset 0x2B78. */
void *func_80258BF4_de(ContextRecAt2BC0 *arg0, int arg1) {
    return (char *)arg0->table2B78 + arg1 * 12;
}

void func_80258C0C_de(void *arg0, s32 arg1) {
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 mask;

        temp_s0 = &((ContextRecAt2BC0 *)(arg0))->lock;
        mask = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 1) {
            __osRestoreInt(mask);
            osRecvMesg(temp_s0, 0, 1);
        } else {
            __osRestoreInt(mask);
        }
    }
    func_8025B5F0_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], arg1);
    func_80259918_de(&((ContextRecAt2BC0 *)(arg0))->view[0], arg1);
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &((ContextRecAt2BC0 *)(arg0))->lock;
        ((ContextRecAt2BC0 *)(arg0))->field2B9C = 0;
        temp_v0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(temp_v0);
            osSendMesg(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_v0);
        }
    }
    func_8025D1BC_de((char *)arg0 + 0x2BC0);
}

/** Thin wrapper forwarding an offset argument to func_8025DACC_de. */
void func_80258CEC_de(int arg0) {
    func_8025DACC_de(arg0 + 0x1D64);
}

/** Store the second argument at offset 0x2BAC. */
void func_80258D08_de(ContextRecAt2BC0 *arg0, int arg1) {
    arg0->field2BAC = arg1;
}

int func_80258D10_de(ContextRecAt2BC0 *arg0) {
    return arg0->field2BAC;
}

/** Store a value in the field at offset 0x2BB4. */
void func_80258D1C_de(char *object, int value) {
    ((ContextRecAt2BC0 *)(object))->field2BB4 = value;
}

/** Store a value in the field at offset 0x2B98. */
void func_80258D24_de(ContextRecAt2BC0 *object, int value) {
    object->field2B98 = value;
}

/** Read the object word at offset 0x2BB0. */
int func_80258D2C_de(void *object) {
    return ((ContextRecAt2BC0 *)(object))->field2BB0;
}

/** Store the supplied word at object offset 0x2BB0. */
void func_80258D38_de(ContextRecAt2BC0 *arg0, int arg1) {
    arg0->field2BB0 = arg1;
}

void *func_80258D40_de(void *arg0) {
    return &((ContextRecAt2BC0 *)(arg0))->list[0];
}

/** Store a word in the object field at offset 0x2BB8. */
void func_80258D48_de(ContextRecAt2BC0 *object, int value) {
    object->field2BB8 = value;
}

s32 func_80258D50_de(char *obj, s32 owner)
{
    s32 count;
    s32 i;

    count = 0;
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_a0;

        temp_s0 = &((ContextRecAt2BC0 *)(obj))->lock;
        temp_a0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 1) {
            __osRestoreInt(temp_a0);
            osRecvMesg(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_a0);
        }
    }
    for (i = 0; i < 17; i++) {
        if (((ContextRecAt2BC0 *)obj)->voices[i].sound == owner) {
            count++;
        }
    }
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &((ContextRecAt2BC0 *)(obj))->lock;
        temp_v0 = func_802BCF30_de();
        temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(temp_v0);
            osSendMesg(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_v0);
        }
    }
    return count;
}

/** Thin wrapper forwarding an offset argument to func_8025DB58_de. */
void func_80258E40_de(int arg0) {
    func_8025DB58_de(arg0 + 0x1D64);
}

/* Clamps a level to between zero and D_800C8FE0, scales it by D_800C8FE4 and stores it as an integer
   at 0x2B9C of the object. */





void func_80258E5C_de(ObjRecAt2B9C *obj, float value) {
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

/** Thin wrapper forwarding an offset argument to func_8025DB34_de. */
void func_80258EBC_de(int arg0) {
    func_8025DB34_de(arg0 + 0x1D64);
}

/** Thin wrapper forwarding an offset argument to func_8025DB44_de. */
void func_80258ED8_de(int arg0) {
    func_8025DB44_de(arg0 + 0x1D64);
}

/** Thin wrapper forwarding an offset argument to func_8025BB3C_de. */
void func_80258EF4_de(int arg0) {
    func_8025BB3C_de(arg0 + 0x1DB8);
}

int func_80258F10_de(ContextRecAt2BC0 *arg0, int group) {
    float scale = (1.0f);
    float blue = arg0->blue;
    if (!(scale < blue)) {
        scale = blue;
    }
    return func_8025CED0_de(&arg0->dialog[0], group, scale, 0x40);
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




int func_80258FF4_de(char *context, int id) {
    Voice *slot;
    int i;
    slot = ((ContextRecAt2BC0 *)context)->voices;
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

s32 func_80259038_de(SceneRecAt2B5C *scene, s16 id, s16 avoid) {
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

void func_802591A0_de(void *arg0, s16 index) {
    Render_GetPackSection(Render_GetPackSection((((struct ObjectLinks2B50 *) ((s8 *) arg0))->unk_2B4C), (s32) index), 0);
}

void func_802591D0_de(void *arg0, s16 index) {
    Render_GetPackSection(Render_GetPackSection((((struct ObjectLinks2B50 *) ((s8 *) arg0))->unk_2B4C), (s32) index), 1);
}

/* Returns 1 when the object's owner at 0x102 is set, or when the id is below 256 and at least six of
   its seventeen 0xCC-byte slots at 0x1E64 already carry that id; otherwise 0. */




int func_80259200_de(ObjRecAt1E64 *obj, int id) {
    int count;
    int i;

    if (obj->owner != -1) {
        return 1;
    }
    if (id < 256) {
        count = 0;
        for (i = 0; i < 17; i++) {
            if (obj->slots[i].id == id) {
                count++;
            }
        }
        if (count >= 6) {
            return 1;
        }
    }
    return 0;
}
