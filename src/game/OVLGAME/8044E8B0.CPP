#include "include_asm.h"

#include "TYPES.H"
#include "FX_2/80271B18.H"
#include "SDK/PFS/8044E8B0.H"


extern const f32 D_800C53B0_de;
extern const f32 D_800C53B4_de;
extern const f32 D_800C53B8_de;




void func_8044DC60_de(RenderSettings *state) {
    state->direction.x = D_800C53B0_de;
    state->direction.y = D_800C53B4_de;
    state->direction.z = D_800C53B8_de;
    func_8027207C_de(&state->direction.x);
    state->ready = 1;
}

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_8044DE24);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("ovl_80400000", func_8044DC60_de_padding_13F0B4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_8044F0B8);
#endif
