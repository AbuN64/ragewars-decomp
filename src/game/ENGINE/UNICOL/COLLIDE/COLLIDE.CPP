#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/LONE/D_80103FCC.H"
#include "COMMON/OUTPUT.H"
#include "SCHED/8023A284.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/CCOLLISIONSETUP_T.H"
#include "SCHED/8023A284_29.H"
#include "include_asm.h"

/* 8023A284_29.CPP */
/* Points the active collision state at D_801041F0 and fills the collision infos from the setup table
 * D_0044A850 (the KUSEG alias of D_8044A850). */

extern u8 D_801041F0[];

extern CCollisionSetup_t D_0044A850[];

void func_8023EE00_de(void) {
    D_80103FCC = D_801041F0;
    CCollision_ApplySetupTable(D_0044A850);
}

/** Reset the selected fields of the current global record. */
void CCollision_ResetResult(void) {
    Reusable *record = D_80103FCC;
    record->unk0 = 0;
    record->unk14 = -1;
    record->unk88 = 0;
    record->unk9C = 0;
    record->unkB0 = 0;
    record->unkB4 = 0;
    record->unkC4 = 0;
}

/* 8023A284_32.CPP */
/* Fills every collision info named by a collision setup table from its row, resetting the
 * active collision state D_80103FCC before each one; the table ends at a row without info. */
void CCollision_ApplySetupTable(CCollisionSetup_t *setupTable)
{
    CCollisionSetup_t *setup = setupTable;
    s32 counter = -1;

    if (setup->m_pCollInfo != 0) {
        do {
            CCollisionInfo2_t *info = setup->m_pCollInfo;

            ((Reusable *)D_80103FCC)->unk0 = 0;
            ((Reusable *)D_80103FCC)->unk14 = counter;
            ((Reusable *)D_80103FCC)->unk88 = 0;
            ((Reusable *)D_80103FCC)->unk9C = 0;
            ((Reusable *)D_80103FCC)->unkB0 = 0;
            ((Reusable *)D_80103FCC)->unkB4 = 0;
            ((Reusable *)D_80103FCC)->unkC4 = 0;

            info->dwFlags = setup->m_dwFlags;
            info->InstanceBehavior = setup->m_InstanceBehavior;
            info->WallBehavior = setup->m_WallBehavior;
            info->GroundBehavior = setup->m_GroundBehavior;
            info->GravityAcceleration = setup->m_GravityAcceleration;
            info->BounceReturnEnergy = setup->m_BounceReturnEnergy;
            info->GroundFriction = setup->m_GroundFriction;
            info->AirFriction = setup->m_AirFriction;
            info->WaterFriction = setup->m_WaterFriction;
            setup += 1;
        } while (setup->m_pCollInfo != 0);
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8023EEDC[1] = {
    0x0000000B,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_8023EE60_de_padding_3FB3C[1] = {
    0x00000000,
};
#endif

/* 8023A284_34.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_8023EF0C_eu_padding_3FB0C[4] = { 0x10, 0x40, 0x00, 0x05 };
#endif
