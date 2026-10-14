#include "span_1000/code_802AE028.h"
#include "types.h"





extern u32 func_802AEA2C_de(RuntimeStateRecAtB8 *state, u32 index);



void func_802AE5B8_de(RuntimeStateRecAtB8 *state, u32 base) {
    f64 converted;
    s32 count;
    u32 entry;
    u32 i;

    i = 0;
    state->resources = (ResourceTable *)base;
    state->active = 0;
    state->unk10 = 0;
    state->unkC = 0;
    state->one14 = 1;
    do {
        state->flagsA8[i] = 0;
        state->unk58[i] = 0;
        state->flags98[i] = 0;
        entry = state->resources->entries[i];
        if (entry != 0) {
            state->active |= 1U << i;
            state->objects[i] = (void *)(base + entry);
            state->results[i] = func_802AEA2C_de(state, i);
        } else {
            state->objects[i] = 0;
        }
        i++;
    } while (i < 16U);
    count = state->resources->entries[16];
    converted = (f64)count;
    if (count < 0) {
        converted += D_800C7300_de;
    }
    state->scale = D_800C7308_de / (f32)converted;
}
