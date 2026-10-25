#include "include_asm.h"
#include "COMMON/FIELD_VEC_B0.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "WEAPONS/80213ED4.H"

extern f32 D_800D2988;

extern s32 func_80265878_de(StateCallback);
extern s32 func_80265784_de(u32);
extern void *func_8024B738_de(void *, void *, s32);
extern s32 func_80246A08_de(void *, s32, s32);


void func_80213ED4_de(Source110 *src, Dest *dst) {
    StateEntry *entry;
    StateCallback callback;
    f32 factor;

    entry = dst->entry;
    if (entry != 0) {
        if (dst->old_state != dst->state) {
            if (entry->scale >= 0.0f) {
                dst->entry_scale = entry->scale;
            }
            dst->old_entry_flags = dst->entry_flags;
            dst->entry_flags = entry->flags;
            src->state_changed = 0;
            callback = entry->callback;
            if (callback != 0) {
                if (func_80265878_de(callback) != 0) {
                    callback = callback(src, dst);
                } else if (func_80265784_de((u32)callback) != 0) {
                    callback = (StateCallback)func_8024B738_de(src, callback, dst->state_result);
                }
                if (callback != 0) {
                    if (callback != (StateCallback)-1) {
                        dst->state_result = func_80246A08_de(src, (s32)callback, dst->state_result);
                        dst->result = (s16)callback;
                        if (src->current_state == dst->state_result) {
                            src->limit = 0.0f;
                        }
                    }
                    dst->count = 0;
                    dst->flags &= ~1U;
                }
            }
            dst->old_state = (u8)dst->state;
        } else if ((dst->state_result == -1) || (dst->result == -1)) {
            dst->count++;
            dst->flags |= 1;
        } else if (src->current_state == dst->state_result) {
            if (!(dst->flags & 1)) {
                s32 difference = src->counter - entry->threshold;
                double converted = difference;
                if (difference < 0) {
                    converted += D_800C2130_de;
                }
                if ((f32)converted <= src->limit) {
                    dst->count++;
                    dst->flags |= 1;
                }
            }
            if (src->state_changed != 0) {
                src->state_changed = 0;
                if (!(dst->flags & 1)) {
                    dst->count++;
                }
                dst->flags &= ~1U;
            }
        }

        if (dst->entry_flags & 0x10) {
            factor = dst->entry_scale;
        } else {
            factor = dst->scale * dst->entry_scale;
        }
        D_800D2988 *= factor;
        func_8024B6F4_de(src, dst->state_result, (dst->entry_flags >> 5) & 1);
        if ((dst->state_result != -1) && (src->previous_state != dst->state_result)) {
            dst->count = 0;
            dst->flags &= ~1U;
            src->state_changed = 0;
        }
        if (src->flags & 0x08000000) {
            dst->count++;
        }
    }
}

#include "COMMON/WORLD.H"
#include "COMMON/WORLD.H"
extern void func_80217388_de(void *, void *);

s32 Weapons_RequestActorState(void *arg0, void *arg1, s32 action) {
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
    if ((((Dest *)arg1)->entry != 0) && (((Dest *)arg1)->state == action)) {
        return 1;
    }

    node = ((Dest *)arg1)->table;
    entry = 0;
    ((Dest *)arg1)->state = action;
    ((Dest *)arg1)->stateTimer = 0;
    while (node != 0) {
        scan = node->entries;
        if (scan->id != -1) {
            while (scan->id != -1) {
                if (scan->id == action) {
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
    return ((Dest *)arg1)->state == action;
}
