#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80212C90.h"
#include "TYPES.H"
/* Sets up a sound voice from its definition: clears the voice's handle at 0xC and state at 0x100 and
   0x102, takes the definition's three bytes at 0x12, 0xE and 0x10 for the output parameters, and the
   pitch from its word at 0x18 read unsigned for kinds 1 and 4 (with the two level bytes at 0x41 and 0x40
   for kind 1, D_800C2100_de otherwise) or signed short for kind 7; for kinds 1 and 4 the audio mode
   D_801462D0 8 scales the pitch by D_800C2118_de with a floor of (&D_800C2118_de)[1] and no second level,
   and mode 0x20 scales it by D_800C2120_de with second level D_800C2124_de; the pitch is stored shifted up 8
   bits at 0x4 and 0x8 and the levels at 0x10 and 0xCC. */








extern s32 D_801462D0;







void func_802138F0_de(Dest *voice, void *def, ResourceManagerState unused, s32 arg4, u8 *out) {
    s32 send;
    s32 first;
    s32 second;
    f32 pitch;
    f32 level;
    f32 level2;
    f64 wide;
    f32 scaled;
    s32 raw;

    send = 0;
    level = D_800C2100_de;
    level2 = (&D_800C2100_de)[1];
    first = 0;
    second = 0;
    voice->handle = -1;
    voice->pending = 0;
    voice->channel = -1;
    pitch = level;
    if (def != 0) {
        send = ((ActorDefinitionHeader *)def)->send;
        first = ((ActorDefinitionHeader *)def)->first;
        second = ((ActorDefinitionHeader *)def)->second;
        switch (((ActorDefinitionHeader *)def)->kind) {
        case 1:
            raw = ((ActorHealthDefinition *)def)->health;
            wide = raw;
            if (raw < 0) {
                wide += D_800C2108_de;
            }
            level = ((MovementDescriptor *)def)->level;
            level2 = ((MovementDescriptor *)def)->secondaryLevel;
            pitch = wide;
            break;
        case 4:
            raw = ((ActorHealthDefinition *)def)->health;
            wide = raw;
            if (raw < 0) {
                wide += D_800C2110_de;
            }
            pitch = wide;
            break;
        case 7:
            pitch = ((PickupHealthDefinition *)def)->health;
            break;
        }
        if (((ActorDefinitionHeader *)def)->kind == 1 || ((ActorDefinitionHeader *)def)->kind == 4) {
            switch (D_801462D0) {
            case 8:
                scaled = pitch * D_800C2118_de;
                level2 = 0.0f;
                if (scaled < (&D_800C2118_de)[1]) {
                    scaled = (&D_800C2118_de)[1];
                }
                pitch = scaled;
                break;
            case 0x20:
                level2 = D_800C2124_de;
                pitch *= D_800C2120_de;
                break;
            }
        }
    }
    out[3] = send;
    out[1] = first;
    out[2] = second;
    voice->health = pitch;
    voice->level = (s32) level;
    voice->secondaryLevel = (s32) level2;
    voice->health <<= 8;
    voice->maxHealth = voice->health;
}
