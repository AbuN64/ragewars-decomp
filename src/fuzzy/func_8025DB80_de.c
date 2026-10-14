#include "types.h"
#include "stddef.h"
typedef struct SequenceResource {
    char pad[0x2B50];
    void *sections;
    char pad2B54[0xC];
    void *lookup;
    s32 count;
} SequenceResource;
typedef struct SequenceState {
    SequenceResource *resource;
    char pad4[0x20];
    s32 command;
    char pad28[8];
    f32 duration;
} SequenceState;
typedef struct SequenceCommand { s32 command; u16 duration; } SequenceCommand;
extern s32 func_802654E8_de(void *, s32, s32);
extern void *func_8028FDB4_de(void *, s32);
extern f32 func_802B2350(s32);
extern f32 D_800C401C_de;
void *func_8025DB80_de(SequenceState *state, s32 index) {
    s32 selection;
    s32 section;
    void *result;
    SequenceCommand *command;
    f32 duration;
    selection = func_802654E8_de(state->resource->lookup, state->resource->count, index);
    if (selection != -1) {
        section = selection * 2;
        result = func_8028FDB4_de(state->resource->sections, section | 1);
        command = func_8028FDB4_de(state->resource->sections, section);
        state->command = command->command;
        duration = func_802B2350(command->duration);
        state->duration = duration;
        if (duration <= 0.0f) state->duration = D_800C401C_de;
        return result;
    }
    return NULL;
}
