#include "TYPES.H"

typedef struct MenuTiming {
    u8 pad[0x14];
    f32 rate;
    s32 identifier;
    s32 elapsed;
    s32 unknown20;
    s32 argument5;
    s32 count;
    s32 slots[5];
    s32 pending[5];
    s32 argument4;
    s32 argument2;
    u8 pad5C[0x10];
    s32 limit;
    u8 pad70[8];
    s32 argument6;
    s32 argument3;
    s32 ready;
} MenuTiming;

extern MenuTiming D_801468A0;
extern u8 D_801462D5;
extern f32 D_800DDB54;
extern f32 D_800DDB58;
extern f32 D_800DDB5C_de;

void func_8042ED70_de(f32 rate, s32 identifier, s32 argument2, s32 argument3,
                     s32 argument4, s32 argument5, s32 argument6) {
    MenuTiming *state = &D_801468A0;
    f32 scale;
    s32 i;

    state->argument2 = argument2;
    state->ready = 0;
    state->argument3 = argument3;
    state->argument4 = argument4;
    state->argument5 = argument5;
    scale = D_800DDB54;
    state->argument6 = argument6;
    if ((u32)(D_801462D5 - 2) < 2) {
        scale = D_800DDB58;
    }
    state->rate = rate * scale;
    i = 0;
    state->limit = 0xA00;
    state->identifier = identifier;
    state->elapsed = 0;
    do {
        state->slots[i] = 0;
        state->pending[i] = 0;
        i++;
    } while (i < 5);
    state->count = 0;
    if (state->rate == 0.0f) {
        state->rate = D_800DDB5C_de;
    }
}
