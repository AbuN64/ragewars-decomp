#include "COMMON/FLOOR_RESOURCE.H"
#include "COMMON/LONE/D_800CD764_de.H"
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
    Scene_MarkResourceInUse(0, state->resource);
    {
        void *manager;

        manager = &D_801379C0;
        func_802A56FC_de(manager);
        func_8022A170_de(&D_80145040);
        Engine_UpdateActorVisibility(state);
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

extern Gfx *D_80110634;
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
#include "COMMON/WORLD.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "gbi.h"
/* The static-instance bounds view also used by the adjacent scene pass. */
typedef struct SceneStaticBounds {
    u8 pad0[0xB8];
    Box bounds;
} SceneStaticBounds;
void Scene_DrawTransparentObjects(Shared_World *world, void *camera) {
    LevelActor *object;
    SortEntry entries[0x800];
    CVector3 jitter;
    s32 count;
    s32 i;
    f32 ox;
    f32 oy;
    f32 oz;
    if ((void *)world->counter124 != 0) {
        gSPDisplayList(D_80110634++, (void *)world->counter124);
    }
    count = world->drawableCount;
    if (count == 0) {
        return;
    }
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RNX, FRUSTRATIO_1);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RNY, FRUSTRATIO_1);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RPX, (u16)-FRUSTRATIO_1);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RPY, (u16)-FRUSTRATIO_1);
    func_802390D0_de(&jitter, camera);
    ox = jitter.x * -2.0f;
    func_802390D0_de(&jitter, camera);
    oy = jitter.y * -2.0f;
    func_802390D0_de(&jitter, camera);
    oz = jitter.z * -2.0f;
    for (i = 0; i < count; i++) {
        f32 x;
        f32 y;
        f32 z;
        object = world->drawables[i];
        switch (object->kind) {
        case 0:
            x = ((SceneStaticBounds *)object)->bounds.min.x + ((SceneStaticBounds *)object)->bounds.max.x + ox;
            y = ((SceneStaticBounds *)object)->bounds.min.y + ((SceneStaticBounds *)object)->bounds.max.y + oy;
            z = ((SceneStaticBounds *)object)->bounds.min.z + ((SceneStaticBounds *)object)->bounds.max.z + oz;
            break;
        case 1:
        case 3:
        default:
            x = object->position0.x + object->position0.x + ox;
            y = object->position0.y + object->position0.y + oy;
            z = object->position0.z + object->position0.z + oz;
            break;
        }
        entries[i].object = object;
        entries[i].distance = x * x + y * y + z * z;
    }
    func_802852C0_de(entries, count, 8, D_0028E044, D_0028DFE4);
    Render_BeginModelBatch();
    for (i = 0; i < count; i++) {
        object = entries[i].object;
        switch (object->kind) {
        case 0:
            func_80250A9C_de(object, camera);
            break;
        case 3:
            func_8024EB90_de(object);
            break;
        case 1:
            func_80249E28_de(object, camera);
            break;
        }
    }
    Render_FlushModelBatch();
}


#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/WORLD.H"
#include "stddef.h"
f32 func_80275DD4_de(Node75 *node, f32 x, f32 z);
f32 func_8027525C_de(Node75 *node, f32 x, f32 z);

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
    polygonTable = Render_GetPackSection(world->modelSections, 2);
    polys = polygonTable->polygons;
    index = 0;
    i = 0;
    bestDist = 0.0f;
    best = NULL;
    grid = Render_GetPackSection(world->modelSections, 3);
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
