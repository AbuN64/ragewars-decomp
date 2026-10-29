#include "DATA/OVL1_D/WEAPON_CHARGE_FIVE_CALLBACK_ADDRESS.H"

#if defined(VERSION_US_REV1)
unsigned int g_weaponControllerAndMovementTuningUsRev1[14] = {
    0x00000000, 0x00000008, (unsigned int)addrLow_Weapon_InitializeChargeForWeaponFive, 0x00010000, 0x00050000, 0x00040000, 0x000C0000, 0x00080000,
    0x000A0000, 0x00020000, 0x00030000, 0x41F00000, 0x42400000, 0x43020000,
};
#endif
