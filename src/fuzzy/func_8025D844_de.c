#include "types.h"

struct AudioHeapD844 {
    u8 *start;
    u8 *cursor;
    u32 size;
};
struct AudioRootD844 {
    char pad0[0x1DA8];
    struct AudioHeapD844 heap;
};
struct AudioParamsD844 {
    s32 count38, count1C;
    u8 kind;
    u8 pad9[3];
    struct AudioHeapD844 *context;
    s32 value10, value14, value18;
};
struct AudioStateD844 {
    struct AudioRootD844 *root;
    char pad4[0xC];
    void *allocation;
    void *player;
    s32 mode, flags, unused20, timer, index, unused2C;
    f32 first, second;
    s32 counter;
    f32 third, fourth;
};
extern f32 D_800C3FF8_de, D_800C3FFC_de;
extern void *func_802B0340_de(s32, s32, struct AudioHeapD844 *, s32, s32);
extern void func_802AEAB0_de(void *, struct AudioParamsD844 *);

void func_8025D844_de(struct AudioStateD844 *state, struct AudioRootD844 *root) {
    struct AudioParamsD844 params;
    void *player;
    state->root = root;
    state->mode = 16;
    state->index = -1;
    state->flags = 0;
    params.count38 = 20;
    params.count1C = 192;
    params.kind = 20;
    params.context = &state->root->heap;
    params.value10 = 0;
    params.value14 = 0;
    params.value18 = 0;
    player = func_802B0340_de(0, 0, &state->root->heap, 1, 0x7C);
    state->player = player;
    func_802AEAB0_de(player, &params);
    state->allocation = func_802B0340_de(0, 0, &state->root->heap, 1, 0xF8);
    state->timer = 50;
    state->counter = 0;
    state->first = D_800C3FF8_de;
    state->second = D_800C3FFC_de;
    state->third = D_800C3FF8_de;
    state->fourth = D_800C3FF8_de;
}
