#include "span_1000/code_8020AF9C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80208000.h"
#include "types.h"

void func_80209804_de(AiController *arg0)
{
    s32 i;
    s32 empty;
    empty = -1;
    i = 3;
    do {
        arg0->queue[i] = empty;
        i -= 1;
    } while (i >= 0);
}

/* Pops the front of a four-entry queue at offset 0x14 of a record: shifts the entries down one,
   marks the last empty with -1 and returns whether an entry remains at the front. */

s32 func_80209828_de(AiController *queue) {
    s32 i;

    for (i = 1; i < 4; i++) {
        queue->queue[i - 1] = queue->queue[i];
    }
    queue->queue[3] = -1;
    return queue->queue[0] != -1;
}

/** Store the second argument at byte offset 0x214 in the first argument. */
void func_8020986C_de(AiController *object, AiBehaviourTable *value) {
    object->table = value;
}

s32 func_80209874_de(AiController *arg0, s32 arg1) {
    AiBehaviourTable *node;
    AiBehaviourEntry *entry;
    AiBehaviourEntry *found;
    void (*callback)(Player *, s32);

    node = arg0->table;
    found = 0;
    arg0->state = arg1;
    while (node != 0) {
        entry = node->entries;
        if (entry->id != -1) {
            while (entry->id != -1) {
                if (entry->id == arg1) {
                    found = entry;
                    node = 0;
                    break;
                }
                entry++;
            }
        }
        if (node != 0) node = node->next;
    }
    if (found == 0) return 0;
    arg0->behaviour = found;
    callback = found->enter;
    if (callback != 0) callback(arg0->player, 0);
    return 1;
}

void func_80209910_de(AiController *arg0, float arg1) {
    float result = arg1 * D_800C1C88_de;
    if (arg0 != 0) {
        arg0->player->pitch = -result;
    }
}

Vec3 *func_8020993C_de(AiController *arg0) {
    return &arg0->player->pos;
}

f32 func_802726F8_de(f32 *, f32 *);
extern void *func_8020C994_de(void *, s32);
extern NavigationGraph D_8013B364;
void func_80209948_de(AiController *arg0, s32 arg1) {
    func_802726F8_de(&arg0->player->pos.x, func_8020C994_de(&D_8013B364, arg1));
}

/** Reset three state words and set the final state to one. */
void func_80209988_de(void *object) {
    AiController *arg0 = object;
    arg0->unk2F4 = 0;
    arg0->unk2F8 = 0;
    arg0->unk2FC = 1;
}

/** Clear five consecutive object words beginning at offset 0x300. */
void func_8020999C_de(AiController *arg0) {
    arg0->unk300 = 0;
    arg0->unk304 = 0;
    arg0->unk308 = 0;
    arg0->unk30C = 0;
    arg0->unk310 = 0;
}

extern char D_80103FD0;
extern void **D_80103FCC;

extern s32 func_802444A4_de(void *arg0, Vec3 arg1, Vec3 arg2, void *arg3);

s32 func_802099B4_de(Player **arg0, Player *arg1) {
    Vec3 first;
    Vec3 second;

    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }

    first = (*arg0)->pos;
    second = arg1->pos;
    first.y += D_800C1C8C_de;
    second.y += D_800C1C8C_de;
    if (func_802444A4_de(*arg0, first, second, &D_80103FD0) != 0) {
        return *D_80103FCC == arg1;
    }
    return 1;
}

s32 func_80209A94_de(AiController *arg0) {
    s32 val;

    val = arg0->state;
    if (val >= 8) {
        goto ge_8;
    }
    if (val >= 3) {
        goto ret1;
    }
    if (val == 1) {
        goto ret1;
    }
    goto ret0;
ge_8:
    if (val != 0xD) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

/** Report whether the state word at offset 0x21C equals eight. */
int func_80209AD8_de(AiController *object) {
    return object->state == 8;
}
