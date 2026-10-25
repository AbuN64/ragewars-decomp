#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800CA8C4_de.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "ENGINE/INSTANCE/GOBJINST_10.H"
#include "SCENE/802508E0_9.H"
#include "particle/80271B18_3.H"
#include "RENDER_4/8028FD2C_6.H"

/* Finds the hit box of an object nearest a point: with the object's bone matrices (0xB4, else 0xB8) and its
 * hit-box resource from func_8024BFD4_de, each box whose mask matches the object's mask 0x17C has the average
 * of its eight corners carried through its bone matrix, and the box whose center lies nearest the point is
 * copied out, taking weight 1 for a controlled actor unless the global option D_801462E5 is set. The
 * resource is released afterwards; returns whether a box was found. */








extern s32 *func_8024BFD4_de(char *, s8);



extern void Particle_AddVec3(CVector3 *, CVector3 *, CVector3 *);

extern void Particle_ScaleVector(CVector3 *, CVector3 *, f32);

extern void Rsp_ConvertMatrixToFloat(f32 *, char *);


extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);


extern TypeEntry *D_800CB440_de[];

extern char *D_80140F84;

extern f32 D_800C3B48_de[];

extern void *Engine_GetActorDefinition(void *, s32);

extern s32 Render_TestActorStateBit(void *, void *);

extern void func_802466A0_de(void *, u16, u16, s32, void *, s32, s32, f32,
                          CVector3, u8, CVector3, CVector3, s32);

s32 func_8024B06C_de(char *obj, CVector3 point, Box70 *out) {
    CVector3 center;
    CVector3 diff;
    f32 matrix[16];
    s32 *resource;
    s32 count;
    struct Shape_typemap_13 *table;
    Box70 *box;
    Box70 *best;
    char *bones;
    s32 i;
    s32 j;
    f32 dist;
    f32 bestDist;

    bones = ((struct ObjectLinks180_2 *) obj)->unk_B4;
    if (bones == 0) {
        bones = ((struct ObjectLinks180_2 *) obj)->unk_B8;
        if (bones == 0) {
            return 0;
        }
    }
    resource = func_8024BFD4_de(obj, ((struct ObjectLinks180_2 *) obj)->unk_1);
    if (resource == 0) {
        return 0;
    }
    table = Render_GetPackSection(*resource, 5);
    count = table->field_4;
    bestDist = 3.4028235e38f;
    best = 0;
    for (i = 0; i < count; i++) {
        box = (Box70 *)((char *)table + (i * table->field_0 + 8));
        if (box->mask & ((struct ObjectLinks180_2 *) obj)->unk_17C) {
            center = box->corners[0];
            for (j = 1; j < 8; j++) {
                Particle_AddVec3(&center, &center, &box->corners[j]);
            }
            Particle_ScaleVector(&center, &center, 0.125f);
            Rsp_ConvertMatrixToFloat(matrix, bones + i * 0x40);
            Particle_TransformPoint(matrix, &center, &diff);
            Particle_SubtractVectors(&diff, &diff, &point);
            dist = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
            if (dist < bestDist) {
                best = box;
                bestDist = dist;
            }
        }
    }
    if (best != 0) {
        *out = *best;
        if ((((struct ObjectLinks180_2 *) obj)->unk_100 & 0x300000) && D_801462C8.local == 0) {
            ((struct Shield *) ((char *) out))->factor = 1.0f;
        }
    }
    Scene_UnlockResource(0, resource);
    return best != 0;
}

void func_8024B2D0_de(char *arg0)
{
    s32 type;
    s32 i;
    s32 count;
    s32 limit;
    char *object;
    TypeEntry *entry;

    type = ((struct LevelActor *)(arg0))->definition->kind;
    if ((u32)type < 15) {
        goto valid_type;
    }
zero_entry:
    entry = 0;
    goto selected;
special_entry:
    entry = (TypeEntry *)D_800CA8C4_de;
    goto selected;
valid_type:
    if (type == 11) {
        count = D_80145048;
        i = 0;
        if (count > 0) {
            limit = count;
            object = D_80140F84;
            do {
                if (object == arg0) {
                    goto zero_entry;
                }
                if (object + 0x2E8 == arg0) {
                    goto special_entry;
                }
                i++;
                object += 0x16E8;
            } while (i < limit);
        }
    }
    entry = D_800CB440_de[type];

selected:
    if (entry != 0 && entry->callback != 0) {
        entry->callback(arg0, (char *)arg0 + 0x170);
    }
    if ((((struct LevelActor *)(arg0))->flags & 0x08000000) != 0) {
        (((struct LevelActor *)(arg0))->updateCount)++;
    }
}

void func_8024B3A8_de(void *arg0, InputRecAt27 *arg1, s32 mode, s32 index) {
    void *resource0;
    s32 resource1;
    s32 lookup;
    s32 amountRaw;
    f32 fzero;
    f32 amount;
    CVector3 zero;

    resource0 = Engine_GetActorDefinition(&D_8011FE88, arg1->resource22);
    if (arg1->resource20 == 0xFFFF) {
        resource1 = 0;
    } else {
        resource1 = func_8028B394_de(&D_8011FE88, arg1->resource20);
    }
    amountRaw = arg1->amount24;
    fzero = 0.0f;
    amount = amountRaw * D_800C3B48_de[1];
    zero.x = zero.y = zero.z = fzero;
    lookup = Render_TestActorStateBit(&D_8011FE88, arg0);
    func_802466A0_de(arg0, arg1->unk1C, arg1->unk1E, arg1->unk0,
                  resource0, arg1->unk27 == 0xFF ? -1 : arg1->unk27,
                  resource1, amount, *(CVector3 *)arg1->vec4, arg1->unk26,
                  *(CVector3 *)arg1->vec10, zero, lookup);
}

void func_8024B4F4_de(void *arg0, int arg1) {
    Actor36 *actor = arg0;
    func_8024B4E4_de_FuncPtr fn = actor->update;
    fn(arg0, actor->state);
    func_8026EE20_de(actor->matrix, arg1, &actor->box);
}
