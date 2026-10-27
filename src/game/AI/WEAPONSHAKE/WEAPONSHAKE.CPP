#include "COMMON/STATERECAT10.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "include_asm.h"

/* 80231F5C_15.CPP */
u32 Weapon_UpdateShakeAxis(CShakeAxis *state) {
    f32 scale;
    f32 step;

    if (state->value > state->m_LastShake) {
        state->m_LastShake = state->value;
    }
    if (state->m_Amp == 0.0f) {
        state->m_Angle = D_800C3080_de;
    }
    if (state->m_Amp < state->m_LastShake + state->m_LastShake) {
        state->m_Amp = state->m_LastShake + state->m_LastShake;
    }

    step = D_800D2988;
    scale = D_800C3084_de;
    state->value = GraphU64_DecayToZero(state->value, step * scale);
    state->m_LastShake = GraphU64_DecayToZero(state->m_LastShake, D_800D2988 * scale);

    switch (state->mode) {
    case 1:
        if (state->m_Amp > 0.0f) {
            state->m_Angle += (state->m_Amp + state->m_Amp) * (D_800D2988 * scale);
            state->m_Amp = GraphU64_DecayToZero(state->m_Amp, D_800C3088_de);
        }
        break;
    case 0:
        if (state->m_Amp > 0.0f) {
            state->m_Amp = GraphU64_DecayToZero(state->m_Amp, D_800C308C_de);
        }
        break;
    }

    return state->m_Amp == 0.0f;
}

#if !(defined(VERSION_US_REV1))
const unsigned int D_802337D0_C8D70[4] = {
    0x42B40000, 0x40400000, 0x40C00000, 0x40C00000,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_802337D0_C8D70_us_rev1[4] = {
    0x42B40000, 0x40400000, 0x40C00000, 0x40C00000,
};
#endif

/* 800C8180.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80233930_C8D80[4] = {
    0x3F800000, 0x3C8EFA36, 0x3C8EFA36, 0x3C8EFA36,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_80233930_C8D80_us_rev1[4] = {
    0x3F800000, 0x3C8EFA36, 0x3C8EFA36, 0x3C8EFA36,
};
#endif
