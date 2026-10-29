#include "DATA/OVLDAT7/WEAPON_SPIN_AND_SIDE_YAW_CALLBACK_ADDRESSES.H"

#if defined(VERSION_US_REV1)
unsigned int g_weaponSlot8BehaviorUsRev1[7] = {
    0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x800CF51C, (unsigned int)g_Weapon_ApplyScaledSideYawAddress, (unsigned int)g_Weaponai_DecaySpinAndActivateEffectAddress,
};
#endif
