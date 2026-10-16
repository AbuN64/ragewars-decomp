#include "span_1000/code_8025C544.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80255BEC.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025D948.h"
#include "TYPES.H"

void func_802B25D0_de(void *sound, short sample);

static inline short slot_id(Slots *slots, int index) {
    return slots->ids[index];
}

extern s32 func_8025DE54_de(s16 arg0, Vec3 position, s32 arg4, s32 arg5);

extern s32 func_8025E0F4_de(s32 arg0);

int func_8025C824_de(RecordRecAt4V4 *pool, short index) {
    SlotRecAtB4V2 *entry;
    ContextCode8025A3EC *context;
    Slots *slots;
    void *owner;

    entry = &pool->slots[index + 1];
    entry--;
    owner = entry->owner;
    context = owner;
    slots = &context->slots;
    func_802B25D0_de(entry->owner->sound, slot_id(slots, entry->index));
    slots->ids[entry->index] = -1;
    entry->priority = 0;
    entry->fieldC = -1;
    entry->used = -1;
    entry->value = -1;
    entry->channel = -1;
    entry->fieldB4 = -1;
    return 0;
}

/** Initialize the two object words at offsets 8 and 12 to negative one. */
void func_8025C8C0_de(void *arg0) {
    SoundSourceNode *voice = arg0;
    voice->state = -1;
    voice->value = -1;
}

void func_8025C8D0_de(void) {
}

void func_8025C8D8_de(void *arg0, SoundSourceNode *arg1, s32 arg2) {
    s32 i;

    func_80255CA0_de(arg0, 0, 4);
    func_80255CA0_de(&((SoundVoicePool *)arg0)->playing, 0, 4);
    i = 0;
    if (arg2 > 0) {
        do {
            func_80255D14_de(arg0, arg1);
            i += 1;
            arg1 = arg1 + 1;
        } while (i < arg2);
    }
    ((SoundVoicePool *)arg0)->state = 0;
}

void *func_8025C95C_de(void *arg0, s32 arg1, Vec3 *arg2, void *arg3, s32 arg4) {
    extern void func_80255ED8_de(void *arg0, void *arg1);
    SoundSourceNode *node;
    s32 result;

    node = ((SoundVoicePool *)arg0)->available.head;
    if (node != 0) {
        func_80255ED8_de(arg0, node);
        func_80255D14_de(&((SoundVoicePool *)arg0)->playing, node);
        node->state = -1;
        node->value = -1;
        result = func_8025DE54_de((s16)arg1, *arg2,
                                (s32)arg3, arg4);
        node->value = result;
        D_800CBB10 = result;
        node->state = arg1;
        node->position = *arg2;
        node->owner = arg3;
    }
    return node;
}

s32 func_8025CA24_de(void *arg0, void *arg1) {
    extern void func_80255ED8_de(void *, s32);
    void *var_s0;

    if (arg1 == 0) {
        return 0;
    }

    var_s0 = ((SoundVoicePool *)arg0)->playing.head;
    if (var_s0 != 0) {
        do {
            if (var_s0 == arg1) {
                func_8025E174_de(((SoundSourceNode *)var_s0)->value);
                D_800CBB14 = ((SoundSourceNode *)var_s0)->value;
                func_80255ED8_de(&((SoundVoicePool *)arg0)->playing, (s32)var_s0);
                func_80255D14_de(arg0, var_s0);
                return 1;
            }
            var_s0 = ((SoundSourceNode *)var_s0)->next;
        } while (var_s0 != 0);
    }
    return 0;
}

void func_8025CAB0_de(void *arg0) {
    s32 temp_v0;
    SoundVoicePool *pool = arg0;
    SoundSourceNode *var_s0;

    var_s0 = pool->playing.head;
    if (var_s0 != 0) {
        do {
            func_8025E174_de(var_s0->value);
            temp_v0 = var_s0->value;
            var_s0 = var_s0->next;
            D_800CBB18 = temp_v0;
        } while (var_s0 != 0);
    }
    pool->state = 1;
}

void func_8025CB0C_de(SoundVoicePool *arg0) {
    s32 temp_v0;
    SoundSourceNode *var_s0;

    var_s0 = arg0->playing.head;
    if (var_s0 != 0) {
        do {
            temp_v0 = func_8025DE54_de((s16)var_s0->state,
                                     var_s0->position,
                                     (s32)var_s0->owner,
                                     -1);
            var_s0->value = temp_v0;
            var_s0 = var_s0->next;
            D_800CBB1C = temp_v0;
        } while (var_s0 != 0);
    }
    arg0->state = 0;
}

void func_8025CB88_de(void *arg0) {
    SoundVoicePool *pool = arg0;
    SoundSourceNode *var_s0;

    if (pool->state == 0) {
        var_s0 = pool->playing.head;
        if (var_s0 != 0) {
            do {
                if (func_8025E0F4_de(var_s0->value) == 0) {
                    var_s0->state = -1;
                    var_s0->value = -1;
                }
                var_s0 = var_s0->next;
            } while (var_s0 != 0);
        }
    }
}

void func_8025CBEC_de(void *arg0) {
    extern void func_80255ED8_de(void *, s32);
    SoundSourceNode *cur;
    SoundSourceNode *next;
    s32 value;
    SoundVoicePool *pool = arg0;

    cur = pool->playing.head;
    if (cur != 0) {
        do {
            value = cur->value;
            next = cur->next;
            func_8025E174_de(value);
            cur->state = -1;
            cur->value = -1;
            func_80255ED8_de(&pool->playing, cur);
            func_80255D14_de(&pool->available, cur);
            cur = next;
        } while (cur != 0);
    }
}
