#include "include_asm.h"

/* TURRETAI_6.CPP */

/* TURRETAI_7.CPP */
/* 800C1D38_2.CPP */
#if !(defined(VERSION_DE) || defined(VERSION_US))
/* ROM-grounded data: rodata/shared/800D7034_unclaimed_D7C58_unclaimed_D7E0C_unclaimed_D8A44_unclaimed_D8B84 */
#ifdef VERSION_EU
const float k_BuildFourWords[1] = {
    4.0f,
};
#endif
#ifdef VERSION_EU_X
const float k_BuildFourWords[1] = {
    4.0f,
};
#endif
#ifdef VERSION_US_REV1
#include "COMMON/GAMEPLAY_SOUND_TABLE.H"
extern void *g_screenMessageTextSlot;
/* event message table read by Events_PostGameplayMessage / Link_DispatchMatchingTriggers / Action_ShowTriggerMessage:
   entry 0 points at the slot holding the screen message text pointer, entry 1 is unused */
GameplaySoundEntry g_gameplaySoundTable[2] = {
    { (s32 *)&g_screenMessageTextSlot, 0 },
    { 0, 0 },
};
/* 12 bytes of stale fill behind the table (0x000E0204, 2, 0x500), read by nothing */
unsigned int g_gameplaySoundTablePad[3] = {
    0x000E0204, 0x00000002, 0x00000500,
};
#endif
#endif

/* TURRETAI_7.CPP */
#if defined(VERSION_DE)
unsigned int func_8020402C_de_padding_4C2C[1] = {
    0xDDC190FC,
};
#endif
