#include "span_1000/code_80233920.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802393F4.h"
#include "types.h"

/* Spawns an emitter record: takes the head of the free list at 0x11D8 into the active list at 0x11EC (or reuses the record at 0x11F0 when none is free) and fills its position, scale, shared value and three rates converted by D_800C8630. */



extern f32 D_800C8630[];
extern void func_80255ED8_de(void *list, void *node);
extern void func_80255CB8_de(void *list, void *node);






static inline void set_emitter(Effect33920 *node, f32 a, f32 b, f32 c, f32 scale, s32 value, Vec3 pos)
{
    node->origin = pos;
    node->radius = scale;
    node->x.mode = value;
    node->x.value = a;
    node->y.mode = value;
    node->y.value = b;
    node->z.mode = value;
    node->z.value = c;
}

void func_802394BC_de(char *obj, f32 a, f32 b, f32 c, f32 scale, s32 value, Vec3 pos)
{
    RaceViewportState *state = (void *)obj;
    Effect33920 *node = state->freeEffects.head;
    f32 k;

    if (node != 0) {
        func_80255ED8_de(&state->freeEffects, node);
        func_80255CB8_de(&state->activeEffects, node);
    } else {
        node = state->activeEffects.tail;
    }
    k = D_800C8630[1];
    set_emitter(node, a * k, b * k, c * k, scale, value, pos);
}
