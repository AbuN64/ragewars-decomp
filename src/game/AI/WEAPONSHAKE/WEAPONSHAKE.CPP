#include "COMMON/STATERECAT10.H"
#include "TYPES.H"
#include "COMMON/WEAPON_SCREEN_MESSAGE_OPERATIONS.H"
#include "include_asm.h"

/* 80231F5C_15.CPP */
u32 Weapon_UpdateShakeAxis(CShakeAxis *state) {
    f32 scale;
    f32 step;

    if (state->value > state->m_LastShake) {
        state->m_LastShake = state->value;
    }
    if (state->m_Amp == 0.0f) {
        state->m_Angle = g_weaponShakeInitialAngle;
    }
    if (state->m_Amp < state->m_LastShake + state->m_LastShake) {
        state->m_Amp = state->m_LastShake + state->m_LastShake;
    }

    step = g_frameElapsedTime;
    scale = g_weaponShakeAngleRate;
    state->value = Graphu64_DecayToZero(state->value, step * scale);
    state->m_LastShake = Graphu64_DecayToZero(state->m_LastShake, g_frameElapsedTime * scale);

    switch (state->mode) {
    case 1:
        if (state->m_Amp > 0.0f) {
            state->m_Angle += (state->m_Amp + state->m_Amp) * (g_frameElapsedTime * scale);
            state->m_Amp = Graphu64_DecayToZero(state->m_Amp, g_weaponShakeActiveDecay);
        }
        break;
    case 0:
        if (state->m_Amp > 0.0f) {
            state->m_Amp = Graphu64_DecayToZero(state->m_Amp, g_weaponShakeIdleDecay);
        }
        break;
    }

    return state->m_Amp == 0.0f;
}

const unsigned int k_WeaponshakeEncodedWords[4] = {
    0x42B40000, 0x40400000, 0x40C00000, 0x40C00000,
};

/* 800C8180.CPP */
const unsigned int k_WeaponshakeEncodedWordsBlock1[4] = {
    0x3F800000, 0x3C8EFA36, 0x3C8EFA36, 0x3C8EFA36,
};
