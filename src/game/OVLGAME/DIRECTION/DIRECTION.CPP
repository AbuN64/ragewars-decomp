#include "include_asm.h"

#include "TYPES.H"
#include "FX/GRAPHU64_NORMALIZEVEC3.H"
#include "sdk/PFS/OVLGAME_INITIALIZERENDERDIRECTION.H"
#include "OVLGAME/DIRECTION.H"


extern const f32 g_defaultEffectDirectionX;
extern const f32 g_defaultEffectDirectionZ;




void Ovlgame_InitializeRenderDirection(RenderSettings *state) {
    state->direction.x = g_defaultEffectDirectionX;
    state->direction.y = g_defaultEffectDirectionY;
    state->direction.z = g_defaultEffectDirectionZ;
    Graphu64_NormalizeVec3(&state->direction.x);
    state->ready = 1;
}

#if defined(VERSION_US)
char s_DirectionLESHequRText[12] =
    "LESHequR\000\000\005\000";
#endif

#if defined(VERSION_EU_X)
unsigned int func_8044DC60_de_padding_13F0B4[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_DirectionEncodedWords[2] = {
    0x00010041, 0x00000014,
};
#endif
