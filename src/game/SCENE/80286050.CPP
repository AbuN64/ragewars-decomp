#include "COMMON/FLOOR_RESOURCE.H"
#include "include_asm.h"
#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "TYPES.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "TYPES.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "ACHIEVE/80437C30_2.H"
#include "RENDER_4/8028FD2C_11.H"
#include "SCENE/80286050.H"
#include "ENGINE/SCENE_2.H"
#include "ENGINE/SCENE_3.H"
#include "WEAPONS/80225D10_5.H"
#include "RENDER_4/8028FD2C_6.H"

void func_80286080_de(void *arg0) {
    Shared_World *state;
    Shared_Game *input;
    s32 old_flags;

    state = arg0;
    input = &D_801462C8;
    old_flags = D_800CD3F0;
    D_800CD3F0 = input->buttons;
    if (input->flags & 0x4000) {
        D_800CD3F0 |= 0x100;
    }
    if (input->flags & 0x8000) {
        D_800CD3F0 |= 0x200;
    }
    if (old_flags != D_800CD3F0) {
        D_800CD3F4 = 1;
        func_8025476C_de(8);
    } else {
        D_800CD3F4 = 0;
    }

    Scene_UpdateSelectionTransition(state);
    func_8028D64C_de(state);
    state->counter120 = 0;
    state->counter124 = 0;
    func_80279990_de(state->system128);
    func_80253BBC_de(0, state->resource);
    {
        void *manager;

        manager = &D_801379C0;
        func_802A56FC_de(manager);
        func_8022A170_de(&D_80145040);
        func_80287F18_de(state);
        func_80288470_de(state);
        func_8028D61C_de(state);

        if ((state->frozen == 0) && (D_80146894 == 0)) {
            func_802A5680_de(manager);
            func_80286284_de(state);
            func_80290238_de(&state->system11778);
            state->elapsed += D_800D2988 * D_800C50E4_de;
            func_8028C60C_de(state);
        }
    }

    Particle_UpdateSystem(state->system1B08);
    if (state->frozen == 0) {
        func_802285E8_de(&D_80145040);
    }

    func_80236F1C_de(&D_80145088, state);
    if ((state->frozen == 0) && (D_80145088.status[7] == 0)) {
        func_8028D67C_de(state);
    }
    func_8028D888_de(state);
    func_8028D108_de(state);
}



extern void func_8024BE3C_de(void *arg0);
extern void func_80246E44_de(char *);
extern s32 func_802934F8_de(void);
extern void func_80226A34_de(void *arg0);
extern s32 func_8022A68C_de(void *arg0);



extern void *func_8025CC6C_de(void);
extern void func_8025CB88_de(void *arg0);









void func_80286284_de(void *arg0) {
    s32 count;
    s32 total;
    u32 skip_mask;
    s32 *objects;
    s32 *objectp;
    void *object;
    f32 saved_delta;
    u32 flags;
    s32 object_type;
    u32 remove_mask;
    u32 remove_value;

    count = 0;
    total = ((SceneRecAt10C0 *)arg0)->count;
    objects = &((SceneRecAt10C0 *)(arg0))->objects[0];
    if (total > 0) {
        object_type = 2;
        skip_mask = 0x40000000;
        remove_mask = 0x40002000;
        remove_value = 0x2000;
        objectp = objects;
        do {
            void *next_object;

            next_object = (void *)*objectp;
            if (*((ObjectRecAt1A4 *)(next_object))->kind != object_type) {
                goto first_pass_done;
            }
            object = next_object;
            objectp++;
            flags = ((Shared_Actor *)object)->weaponFlags;
            saved_delta = D_800D2988;
            count++;
            if (!(flags & skip_mask)) {
                func_8024BE3C_de(object);
            }
            if ((((Shared_Actor *)object)->weaponFlags & remove_mask) == remove_value) {
                func_80246E44_de(object);
            }
            D_800D2988 = saved_delta;
        } while (count < total);
    }

first_pass_done:
    if (func_802934F8_de()) {
        func_80226A34_de(&D_80145040);
    }
    if (func_8022A68C_de(&D_80145040)) {
        func_8025E2D4_de(0x34);
        {
        s32 sw_mode_value = ((GlobalMode *)&D_80145040)->mode;
        if ((unsigned int)sw_mode_value > 4) {
            goto sw_mode_default;
        }
        switch (sw_mode_value) {
        case 0: goto sw_mode_0;
        case 1: goto sw_mode_1;
        case 2: goto sw_mode_0;
        case 3: goto sw_mode_1;
        case 4: goto sw_mode_1;
        }
    }
    do {
        sw_mode_0:
        sw_mode_2:
            func_8042CFB0_de();
            break;
        sw_mode_1:
        sw_mode_3:
        sw_mode_4:
            func_804389C4_de();
            break;
        
    sw_mode_default:;
    } while (0);
    }

    if (count < total) {
        objectp = (s32 *)((count * 4) + (s32)objects);
        do {
            object = (void *)*objectp;
            objectp++;
            saved_delta = D_800D2988;
            func_8024BE3C_de(object);
            count++;
            if (((Shared_Actor *)object)->weaponFlags & 0x2000) {
                func_80246E44_de(object);
            }
            D_800D2988 = saved_delta;
        } while (count < total);
    }
    func_8025CB88_de(func_8025CC6C_de());
}

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
#ifndef PUSH_GFX
#define PUSH_GFX(w0, w1) do { u32 *cmd_ = (u32 *)D_80110634; cmd_[0] = (w0); cmd_[1] = (u32)(w1); D_80110634 = (void *)(cmd_ + 2); } while (0)
#endif
extern f32 D_800C50FC_de;
extern u32 *D_80110634;
extern char D_0028DFE4[], D_0028E044[];
typedef struct SortEntry { void *object; f32 distance; } SortEntry;
extern void func_802390D0_de(void *, void *);
extern void func_802852C0_de(void *, s32, s32, void *, void *);
extern void func_80250A9C_de(void *, void *);
extern void func_8024EB90_de(void *);
extern void func_80249E28_de(void *, void *);
/* Draws a world's scene objects back to front: emits the world's static display list if there is one, then
 * measures each object's squared distance to the camera (offset by a jittered vector from func_802390D0_de),
 * sorts the list with func_802852C0_de and draws each object by its kind (0 actor, 1 prop, 3 effect). */
void func_80286454_de(void *world, void *camera) {
    SortEntry entries[0x800];
    f32 jitter[3];
    s32 count;
    s32 i;
    f32 ox;
    f32 oy;
    f32 oz;
    if (FIELD(void *, world, 0x124) != 0) {
        PUSH_GFX(0xDE000000, FIELD(void *, world, 0x124));
    }
    count = FIELD(s32, world, 0x10BC);
    if (count == 0) {
        return;
    }
    PUSH_GFX(0xDB040004, 1);
    PUSH_GFX(0xDB04000C, 1);
    PUSH_GFX(0xDB040014, 0xFFFF);
    PUSH_GFX(0xDB04001C, 0xFFFF);
    func_802390D0_de(jitter, camera);
    ox = jitter[0] * D_800C50FC_de;
    func_802390D0_de(jitter, camera);
    oy = jitter[1] * D_800C50FC_de;
    func_802390D0_de(jitter, camera);
    oz = jitter[2] * D_800C50FC_de;
    for (i = 0; i < count; i++) {
        void *object = FIELD(void *, world, 0x10C0 + i * 4);
        f32 x;
        f32 y;
        f32 z;
        u8 kind = FIELD(u8, object, 0);
        if (kind != 1 && kind < 2 && kind == 0) {
            x = FIELD(f32, object, 0xB8) + FIELD(f32, object, 0xC4) + ox;
            y = FIELD(f32, object, 0xBC) + FIELD(f32, object, 0xC8) + oy;
            z = FIELD(f32, object, 0xC0) + FIELD(f32, object, 0xCC) + oz;
        } else {
            x = FIELD(f32, object, 0x8) + FIELD(f32, object, 0x8) + ox;
            y = FIELD(f32, object, 0xC) + FIELD(f32, object, 0xC) + oy;
            z = FIELD(f32, object, 0x10) + FIELD(f32, object, 0x10) + oz;
        }
        entries[i].object = object;
        entries[i].distance = x * x + y * y + z * z;
    }
    func_802852C0_de(entries, count, 8, D_0028E044, D_0028DFE4);
    func_8026D980_de();
    for (i = 0; i < count; i++) {
        void *object = entries[i].object;
        switch (FIELD(u8, object, 0)) {
        case 0:
            func_80250A9C_de(object, camera);
            break;
        case 1:
            func_80249E28_de(object, camera);
            break;
        case 3:
            func_8024EB90_de(object);
            break;
        }
    }
    func_8026D9D0_de();
}
#else
INCLUDE_ASM("span_1000", func_80286454_de);
#endif

#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/WORLD.H"
#include "stddef.h"
f32 func_80275DD4_de(Node75 *node, f32 x, f32 z);
f32 func_8027525C_de(Node75 *node, f32 x, f32 z);
extern s32 D_800CD764_de;

/* The floor polygon under pos: a volume polygon (flag 0x40) that holds pos, else the one nearest in height. */
/* Finds the containing solid volume, or the nearest floor polygon, as a legacy 32-bit handle. */
s32 Scene_FindFloorPolygon(Shared_World *world, CVector3 *pos) {
    Node75 *polys;
    FloorPolygonTable *polygonTable;
    FloorGrid *grid;
    FloorCell *cell;
    FloorCell *cells;
    Node75 *poly;
    Node75 *best;
    f32 bestDist;
    f32 floor;
    f32 ceiling;
    f32 x;
    f32 z;
    f32 dist;
    s32 cellCount;
    s32 index;
    s32 i;
    u32 j;
    if (D_800CD764_de == 0) {
        return 0;
    }
    polygonTable = func_8028FDB4_de(world->modelSections, 2);
    polys = polygonTable->polygons;
    index = 0;
    i = 0;
    bestDist = 0.0f;
    best = NULL;
    grid = func_8028FDB4_de(world->modelSections, 3);
    cellCount = grid->cellCount;
    cells = grid->cells;
    if (cellCount > 0) {
        do {
            cell = &cells[i];
            x = pos->x;
            if (!(cell->bounds.minX <= x && x <= cell->bounds.maxX)) goto skip_cell;
            z = pos->z;
            if (!(cell->bounds.minZ <= z && z <= cell->bounds.maxZ)) goto skip_cell;
            j = 0;
            if (cell->count != 0) {
                /* Preserve the index-first address add emitted by the original compiler. */
                poly = polys - -index;
                do {
                    if (func_80275B10_de(poly, pos->x, pos->z) != 0) {
                        floor = func_80275DD4_de(poly, pos->x, pos->z);
                        if (poly->flags & 0x40) {
                            ceiling = func_8027525C_de(poly, pos->x, pos->z);
                            if (floor <= pos->y && pos->y <= ceiling) {
                                return (s32)poly;
                            }
                        } else {
                            dist = pos->y - floor;
                            if (dist < 0.0f) {
                                dist = -dist;
                            }
                            if (best == NULL || dist < bestDist) {
                                best = poly;
                                bestDist = dist;
                            }
                        }
                    }
                    poly++;
                    index++;
                } while (cell->count > ++j);
            }
            goto advance_cell;
        skip_cell:
            index += cell->count;
        advance_cell:
            i++;
        } while (i < cellCount);
    }
    return (s32)best;
}
