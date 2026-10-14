#include "common/unused.h"
#include "shared/world.h"

extern void func_80217388_de(void *, void *);

s32 func_80214178_de(void *arg0, void *arg1, s32 arg2) {
    struct ActorStateTable *node;
    StateEntry *entry;
    StateEntry *scan;
    s32 flags;

    if (D_8011FE88.mode == 2) {
        return 1;
    }
    if (D_8011FE88.mode == 4) {
        ((Source110 *)arg0)->flags |= 0x100;
    }

    ((Dest *)arg1)->requestedState = ((Dest *)arg1)->state;
    ((Source110 *)arg0)->animationChanged = 1;
    ((Source110 *)arg0)->stateChanged = 1;
    if ((((Dest *)arg1)->entry != 0) && (((Dest *)arg1)->state == arg2)) {
        return 1;
    }

    node = ((Dest *)arg1)->table;
    entry = 0;
    ((Dest *)arg1)->state = arg2;
    ((Dest *)arg1)->stateTimer = 0;
    while (node != 0) {
        scan = node->entries;
        if (scan->id != -1) {
            while (scan->id != -1) {
                if (scan->id == arg2) {
                    entry = scan;
                    node = 0;
                    break;
                }
                scan = scan + 1;
            }
        }
        if (node != 0) {
            node = node->next;
        }
    }

    if (entry == 0) {
        return 0;
    }

    ((Dest *)arg1)->entry = entry;
    ((Source110 *)arg0)->renderFlags &= 0x1F80007F;
    if ((((Source110 *)arg0)->flags & 0x08000000) == 0) {
        ((Dest *)arg1)->count = 0;
        ((Dest *)arg1)->flags &= ~1U;
    }
    if (((Dest *)arg1)->sound != 0) {
        func_80217388_de(arg0, arg1);
    }
    if (entry->enter != 0) {
        entry->enter(arg0, arg1);
    }
    flags = entry->flags;
    ((Dest *)arg1)->entry_flags = flags;
    if (flags & 4) {
        ((Source110 *)arg0)->velocity.x = 0;
        ((Source110 *)arg0)->velocity.y = 0;
        ((Source110 *)arg0)->velocity.z = 0;
    }
    return ((Dest *)arg1)->state == arg2;
}

