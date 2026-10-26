#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/PACKED.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "TYPES.H"
#include "SYSTEM_3/80265370.H"
extern s32 SetN64_LocatePackSection(void *arg0, s32 arg1, s32 arg2, s32 *arg3);

extern void func_8028FFD0_de(s32, s32, s32, Triple, Triple, s32, f32);

extern s32 Region_IsPointInTriangleXZ(Node75 *arg0, f32 arg1, f32 arg2);

extern f32 Region_GetPolygonHeight(void *, f32, f32);

extern f32 GraphU64_GetTrianglePlaneHeight(void *arg0, f32 arg1, f32 arg2);

extern s32 SetN64_GetDirectoryEntry(s32 *arg0, s32 arg1, s32 arg2);

extern void func_80278E7C_de(void *arg0);

void func_8028BFD8_de(s32 arg0, s32 arg1, Triple position, s32 arg5, f32 arg6) {
    Triple zero;

    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    func_8028FFD0_de(arg0 + 0x11778, 0, arg5, zero, position, arg1, arg6);
}

void *func_8028C050_de(void *triangle, CVector3 *arg1) {
    f32 lower;
    f32 upper;
    f32 value;

    if (triangle != 0 &&
        Region_IsPointInTriangleXZ(triangle, arg1->x,
                          arg1->z) != 0) {
        if (!(((Triangle *)triangle)->flags & 0x40)) {
            return triangle;
        }
        lower = Region_GetPolygonHeight(triangle,
            arg1->x, arg1->z);
        upper = GraphU64_GetTrianglePlaneHeight(triangle,
            arg1->x, arg1->z);
        value = arg1->y;
        if (lower <= value && value <= upper) {
            return triangle;
        }
    }
    return Scene_FindFloorPolygon(&g_world, arg1);
}

/* Searches the counted pointer list at offset 0x1B620 of a world record for the first entry whose definition id at 0x18->0xC equals the given id, returning it or null. */







EntryRecAt18V4 *func_8028C108_de(World *world, s32 id) {
    s32 i;
    EntryRecAt18V4 *found = 0;

    for (i = 0; i < world->count; i++) {
        if (world->list[i]->def->unkC == id) {
            found = world->list[i];
            break;
        }
    }
    return found;
}

void func_8028C15C_de(void *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    *arg2 = SetN64_LocatePackSection((((struct IntegerState54 *) ((s8 *) arg0))->unk_50), (((struct IntegerState54 *) ((s8 *) arg0))->unk_20), arg1, arg3);
}

s32 func_8028C198_de(Shared_World *world, s32 type) {
    s32 *directory = world->indexedDirectory;

    if (type < *directory) {
        return SetN64_GetDirectoryEntry(directory, world->indexedBank, type);
    }
    return 0;
}

s32 func_8028C1D4_de(char *world, u16 *arg1, s32 *arg2, s32 *arg3) {
    s32 sp18;
    s32 sp1C;
    s32 temp_v0_2;
    s32 field_cc;
    s32 field_c4;

    temp_v0_2 = func_80265550_de(field_cc, field_c4, *arg1,
        (field_cc = (s32)((Shared_World *)world)->alternateRecordIndex,
         field_c4 = ((Shared_World *)world)->alternateRecordCount, &sp18), &sp1C);
    if (temp_v0_2 != 0) {
        *arg2 = (s32)((Shared_World *)world)->alternateRecordArray + (sp18 * 0x14);
        temp_v0_2 = (sp1C - sp18) + 1;
        *arg3 = temp_v0_2;
    } else {
        *arg2 = 0;
        *arg3 = 0;
    }
    return temp_v0_2;
}

void func_8028C26C_de(char *world, void *levelActor, s32 *arg2, s32 *arg3) {
    s32 sp18;
    s32 sp1C;
    s32 index;
    u32 first;
    s32 lastOffset;
    s32 temp_v0;
    s32 field_c8;
    s32 field_c0;

    if (!(((LevelActor *)levelActor)->flags & 0x80000)) {
        first = (u32)((Shared_World *)world)->actors;
        index = -1;
        if ((u32)levelActor >= first) {
            lastOffset = ((Shared_World *)world)->actorCount * 0x2E8;
            lastOffset -= 0x2E8;
            if (first + lastOffset >= (u32)levelActor) {
                index = ((u32)levelActor - first) / 0x2E8;
            }
        }
    } else {
        index = -1;
    }
    if (index == -1) {
        *arg3 = 0;
        return;
    }
    temp_v0 = func_80265550_de(field_c8, field_c0, index,
        (field_c8 = (s32)((Shared_World *)world)->recordIndex,
         field_c0 = ((Shared_World *)world)->recordCount, &sp18), &sp1C);
    if (temp_v0 != 0) {
        *arg2 = (s32)((Shared_World *)world)->recordArray + (sp18 * 0x14);
        *arg3 = (sp1C - sp18) + 1;
    } else {
        *arg2 = 0;
        *arg3 = 0;
    }
}

void func_8028C370_de(Shared_World *world, s32 arg1) {
    s32 var_s0;
    s32 var_s0_2;
    Record14 *trigger;
    Record14 *var_s1_2;

    var_s0 = world->recordCount;
    trigger = world->recordArray;
    var_s0 -= 1;
    if (var_s0 != -1) {
        do {
            if (trigger->kind == arg1) {
                func_80278E7C_de(trigger);
            }
            var_s0 -= 1;
            trigger = trigger + 1;
        } while (var_s0 != -1);
    }
    var_s1_2 = world->alternateRecordArray;
    var_s0_2 = world->alternateRecordCount;
    var_s0_2 -= 1;
    if (var_s0_2 != -1) {
        do {
            if (var_s1_2->kind == arg1) {
                func_80278E7C_de(var_s1_2);
            }
            var_s0_2 -= 1;
            var_s1_2 = var_s1_2 + 1;
        } while (var_s0_2 != -1);
    }
}

s32 func_8028C424_de(char *object, s32 type) {
    s32 index;
    Record14 *record;
    u8 *flags;

    index = ((Shared_World *)object)->recordCount;
    record = ((Shared_World *)object)->recordArray;
    index--;
    if (index != -1) {
        flags = &record->flags;
        do {
            if (flags[1] == type &&
                (*flags & 0x40) == 0) {
                return 0;
            }
            index--;
            flags += sizeof(Record14);
        } while (index != -1);
    }

    index = ((Shared_World *)object)->alternateRecordCount;
    record = ((Shared_World *)object)->alternateRecordArray;
    index--;
    if (index != -1) {
        do {
            if (record->kind == type &&
                (record->flags & 0x40) == 0) {
                return 0;
            }
            index--;
            record++;
        } while (index != -1);
    }

    return 1;
}
