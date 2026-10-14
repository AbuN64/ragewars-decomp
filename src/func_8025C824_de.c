#include "span_1000/code_8025A3EC.h"

void func_802B25D0_de(void *sound, short sample);

static inline short slot_id(Slots *slots, int index) {
    return slots->ids[index];
}

int func_8025C824_de(RecordRecAt4V4 *pool, short index) {
    SlotRecAtB4V2 *entry;
    Context_func_8025AE1C_de *context;
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
