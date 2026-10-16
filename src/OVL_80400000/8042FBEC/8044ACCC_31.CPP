#include "shared/world.h"
#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "TYPES.H"

/* Loads the preview resource into the sound buffer when idle, while the adjacent helper resets a changed selection. */

extern char D_00285160[],D_800C50CC_de[],D_800F41F0[];
extern int func_80264B6C_de(void);
extern int *func_8025193C_de(int,int,int,int,int,int,void *,void *,int);
extern void func_802BD3A0_de(void *,int,int),func_8044D528_de(State_func_8044D0F0_de *,int,int);
extern void func_80253838_de(void *arg0, void *arg1);
void func_8044D0F0_de(State_func_8044D0F0_de *state) {
 int *resource;
 int id;
 if(func_80264B6C_de()==0) {
  resource=func_8025193C_de(0,state->resource,state->resource,state->bank,0,0,D_00285160,D_800C50CC_de,1);
  func_802BD3A0_de(D_800F41F0,*resource,0x5000);
  func_80253838_de(0,resource);
 }
}

/* Loads the preview resource into the sound buffer when idle, while the adjacent helper resets a changed selection. */

extern char D_00285160[],D_800C50CC_de[],D_800F41F0[];
extern int func_80264B6C_de(void);
extern int *func_8025193C_de(int,int,int,int,int,int,void *,void *,int);
extern void func_802BD3A0_de(void *,int,int);
extern void func_80253838_de(void *arg0, void *arg1);
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








extern s32 *func_8028FDB4_de(s32, s32);
extern s32 func_80265550_de(s32 *, s32, s32, s32 *, s32 *);
extern void func_80255CB8_de(ListRec *, Node_func_8044D220_de *);
extern Node_func_8044D220_de *func_80256190_de(ListRec *);
extern void func_80255ED8_de(ListRec *, Node_func_8044D220_de *);

s32 func_8044D220_de(World *track, s32 kind, s32 key, Object_func_8044D220_de *out, s32 max) {
    ListRec list;
    Node_func_8044D220_de nodes[64];
    s32 first;
    s32 last;
    s32 found;
    s32 *keys;
    Object_func_8044D220_de *objects;
    Node_func_8044D220_de *node;
    s32 i;
    s32 match;
    s32 count;

    found = 0;
    count = (keys = func_8028FDB4_de(track->resource, 0))[1];
    keys += 2;
    objects = (Object_func_8044D220_de *)(func_8028FDB4_de(track->resource, 1) + 2);
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
