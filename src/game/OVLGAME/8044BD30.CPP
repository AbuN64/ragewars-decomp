#include "include_asm.h"
#include "COMMON/OBJB.H"
#include "COMMON/S1.H"
#include "TYPES.H"

/* Initializes a list and its eight records with default state. */



void func_8044B0E0_de(struct CGameDynamicLight_t *arg0) {
    f32 temp_f20;
    s32 var_s1;
    s32 var_s2;
    PoolRecord *temp_s0;
    void *base;

    func_80255CA0_de(&arg0->empty, 0, 4);
    func_80255CA0_de(&arg0->records, 0, 4);
    var_s2 = 0;
    var_s1 = 0x28;
    temp_f20 = 1.0f;
    do {
        base = arg0;
        temp_s0 = base + var_s1;
        func_80255D14_de(&arg0->records, temp_s0);
        var_s1 += 0x18;
        var_s2 += 1;
        temp_s0->unk8 = 0;
        temp_s0->unkC = temp_f20;
        temp_s0->unk16 = 0;
    } while (var_s2 < 8);
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
