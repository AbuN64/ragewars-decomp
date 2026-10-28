#include "include_asm.h"

#include "TYPES.H"
#include "FX/80271B18.H"
#include "sdk/PFS/8044E8B0.H"
#include "OVLGAME/8044E8B0.H"


extern const f32 D_800C53B0_de;
extern const f32 D_800C53B8_de;




void Ovlgame_InitializeRenderDirection(RenderSettings *state) {
    state->direction.x = D_800C53B0_de;
    state->direction.y = D_800C53B4_de;
    state->direction.z = D_800C53B8_de;
    Graphu64_NormalizeVec3(&state->direction.x);
    state->ready = 1;
}

#if defined(VERSION_US)
char rodata_unresolved_8044DE24[12] =
    "LESHequR\000\000\005\000";
#endif

#if defined(VERSION_EU_X)
unsigned int func_8044DC60_de_padding_13F0B4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_8044F0B8[2] = {
    0x00010041, 0x00000014,
};
#endif
