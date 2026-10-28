#include "include_asm.h"
#include "COMMON/OBJB.H"
#include "OVLGAME/OVLGAME_INITIALIZEDYNAMICLIGHTPOOL.H"
#include "COMMON/S1.H"
#include "TYPES.H"

/* Initializes a list and its eight records with default state. */



void Ovlgame_InitializeDynamicLightPool(struct CGameDynamicLight_t *arg0) {
    f32 temp_f20;
    s32 var_s1;
    s32 i;
    CDLight *temp_s0;
    void *base;

    func_80255CA0_de(&arg0->m_ActiveList, 0, 4);
    func_80255CA0_de(&arg0->m_FreeList, 0, 4);
    i = 0;
    var_s1 = 0x28;
    temp_f20 = 1.0f;
    do {
        base = arg0;
        temp_s0 = base + var_s1;
        func_80255D14_de(&arg0->m_FreeList, temp_s0);
        var_s1 += 0x18;
        i += 1;
        temp_s0->m_pROMLight = 0;
        temp_s0->m_ColorFade = temp_f20;
        temp_s0->m_bEnabled = 0;
    } while (i < 8);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C43CC[1] = {
    0x4E657874,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C478C[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C474C[1] = {
    0x00031C00,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C449C[1] = {
    0x00268D74,
};
#endif
