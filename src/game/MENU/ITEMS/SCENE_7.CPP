#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/OBJB.H"
#include "MENU/8044ACCC.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_14.H"
#include "MENU/ITEMS/SCENE_7.H"
#include "SCENE/802508E0_4.H"
#include "SYSTEM_3/80265370.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "RENDER_4/8028FD2C_6.H"

/* Loads the preview resource into the sound buffer when idle, while the adjacent helper resets a changed selection. */

extern char D_00285160[],D_800C50CC_de[],D_800F41F0[];
extern int func_80264B6C_de(void);
extern void func_802BD3A0_de(void *,int,int),func_8044D528_de(State_func_8044D0F0_de *,int,int);
void func_8044D0F0_de(State_func_8044D0F0_de *state) {
 int *resource;
 int id;
 if(func_80264B6C_de()==0) {
  resource=Scene_RequestResource(0,state->resource,state->resource,state->bank,0,0,D_00285160,D_800C50CC_de,1);
  func_802BD3A0_de(D_800F41F0,*resource,0x5000);
  Scene_ReleaseResource(0,resource);
 }
}

/* Loads the preview resource into the sound buffer when idle, while the adjacent helper resets a changed selection. */

extern char D_00285160[],D_800C50CC_de[],D_800F41F0[];
extern int func_80264B6C_de(void);
extern void func_802BD3A0_de(void *,int,int);
extern void func_8044D528_de(State_func_8044D0F0_de *,int,int);


void func_8044D178_de(State_func_8044D0F0_de *state,int selection) {
 if(selection!=state->selection) {
  state->changed=0;
  func_8044D528_de(state,~selection,0);
 }
}

/* Resets part of a large state block: sets its word at offset 0x1B410 to 2 and clears the words
   at 0x1B414 to 0x1B41C and 0x1B434 to 0x1B440. */
void func_8044D1B4_de(char *state) {
    ((Shared_World *)state)->selectionState = 2;
    ((Shared_World *)state)->frozen = 0;
    ((Shared_World *)state)->selectionTimer = 0;
    ((Shared_World *)state)->selectionFlags = 0;
    ((Shared_World *)state)->selectionValues[0] = 0;
    ((Shared_World *)state)->selectionValues[1] = 0;
    ((Shared_World *)state)->selectionValues[2] = 0;
    ((Shared_World *)state)->selectionValues[3] = 0;
}

/* Copies up to max of a track's placed objects whose key matches into out: finds the key's index range in the track's sorted key table through func_80265550_de, queues each object in that range of the given kind (any kind for -1) on a local list through func_80255CA0_de and func_80255CB8_de, then takes them back off through func_80256190_de and func_80255ED8_de, copying each 20-byte object, and returns how many were copied. */








extern Node_Items_FindPlacedObjectsByKey *func_80256190_de(ListRec *);

s32 Items_FindPlacedObjectsByKey(void *world, s32 kind, s32 key, Shared_Placed *out, s32 max) {
    Shared_World *track = world;
    ListRec list;
    Node_Items_FindPlacedObjectsByKey nodes[64];
    s32 first;
    s32 last;
    s32 found;
    s32 *keys;
    s32 *objectTable;
    Shared_Placed *objects;
    Node_Items_FindPlacedObjectsByKey *node;
    s32 i;
    s32 match;
    s32 count;

    found = 0;
    count = (keys = Render_GetPackSection(track->placedObjectTable, 0))[1];
    keys += 2;
    objectTable = Render_GetPackSection(track->placedObjectTable, 1);
    objects = (Shared_Placed *)(objectTable + 2);
    if (func_80265550_de(keys, count, key, &first, &last) != 0) {
        func_80255CA0_de(&list, 4, 8);
        node = nodes;
        for (i = first; i <= last; i++) {
            match = 1;
            if (kind != -1) {
                match = objects[i].kind == kind;
            }
            if (match) {
                node->index = i;
                func_80255CB8_de(&list, node);
                node++;
            }
        }
        for (max--; max != -1; max--) {
            if (list.count == 0) {
                return found;
            }
            node = func_80256190_de(&list);
            out[found++] = objects[node->index];
            func_80255ED8_de(&list, node);
        }
    }
    return found;
}

/* Render_GetPackSection sections of Shared_World.placedObjectTable: 0 holds one key per placed object,
   1 the placed objects in the same order. */
typedef struct PlacedObjectKeys {
    s32 tag;
    s32 count;
    s32 keys[1];
} PlacedObjectKeys;
typedef struct PlacedObjectList {
    s32 tag;
    s32 count;
    Shared_Placed objects[1];
} PlacedObjectList;
extern f32 Particle_GetPointDistance(f32 *a, f32 *b);
/* Finds the placed object of the given kind nearest to position, copies it to out and returns its key; returns 0
   when none is found or the nearest is object 0 (index 0 doubles as "none"). */
s32 Items_FindNearestPlacedObject(Shared_World *world, f32 *position, s32 kind, Shared_Placed *out) {
    s32 i;
    s32 nearest;
    PlacedObjectKeys *keys;
    PlacedObjectList *list;
    s32 *key;
    Shared_Placed *objects;
    s32 count;
    f32 distance;
    f32 nearestDistance;
    keys = Render_GetPackSection(world->placedObjectTable, 0);
    count = keys->count;
    key = keys->keys;
    list = Render_GetPackSection(world->placedObjectTable, 1);
    nearestDistance = 3.4028235e+38f;
    objects = list->objects;
    nearest = 0;
    for (i = 0; i < count; i++) {
        if (objects[i].kind == kind) {
            distance = Particle_GetPointDistance(&objects[i].pos.x, position);
            if (distance < nearestDistance) {
                nearestDistance = distance;
                nearest = i;
            }
        }
    }
    if (nearest != 0) {
        *out = objects[nearest];
    }
    if (nearest != 0) {
        return key[nearest];
    }
    return 0;
}
