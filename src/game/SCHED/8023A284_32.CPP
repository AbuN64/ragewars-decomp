#include "include_asm.h"
#include "COMMON/OUTPUT.H"
#include "SCHED/8023A284.H"
#include "COMMON/CCOLLISIONSETUP_T.H"
#include "TYPES.H"

/* Fills every collision info named by a collision setup table from its row, resetting the
 * active collision state D_80103FCC before each one; the table ends at a row without info. */
extern Reusable *D_80103FCC;
void func_8023EE60_de(CCollisionSetup_t *setupTable)
{
    CCollisionSetup_t *setup = setupTable;
    s32 counter = -1;

    if (setup->m_pCollInfo != 0) {
        do {
            CCollisionInfo2_t *info = setup->m_pCollInfo;

            D_80103FCC->unk0 = 0;
            D_80103FCC->unk14 = counter;
            D_80103FCC->unk88 = 0;
            D_80103FCC->unk9C = 0;
            D_80103FCC->unkB0 = 0;
            D_80103FCC->unkB4 = 0;
            D_80103FCC->unkC4 = 0;

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
