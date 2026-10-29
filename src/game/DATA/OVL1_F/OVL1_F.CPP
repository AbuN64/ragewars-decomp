#include "DATA/OVL1_F/WEAPON_CHARGE_CALLBACK_ADDRESS.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordConstantWords_Ovl1F.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordLinkWordsBlock3_Ovl1F.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordLinkWordsBlock4_Ovl1F.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordLinkWordsBlock5_Ovl1F.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordLinkWordsBlock7_Ovl1F.H"
#include "DATA/OVL1_F/WEAPON_UPDATE_HELD_FIRE_CALLBACK_ADDRESS.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordConstantWordsBlock10_Ovl1F.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordLinkWordsBlock11_Ovl1F.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordConstantWordsBlock13_Ovl1F.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordLinkWordsBlock13_Ovl1F.H"
#include "DATA/OVL1_F/g_overlayOneFLinkRecordConstantWordsBlock19_Ovl1F.H"

/* g_overlayOneFLinkRecordAddressWords_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_overlayOneFLinkRecordAddressWords[8] = {
    0x800CF298, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* WEAPON_CHARGE_CALLBACK_ADDRESS.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D01E0_us_rev1.c */
unsigned int g_overlayOneFLinkRecordLinkWords[2] = {
    0x00000002, (unsigned int)addrLow_Weapon_ReleaseLinkedActorHandlesEntryVariant2,
};
#endif

/* g_overlayOneFLinkRecordConstantWords_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock1[2] = {
    (unsigned int)addrLow_Weaponai_ToggleFiringModeWithAmmoCheck, 0x00000000,
};

unsigned int g_overlayOneFLinkRecordConstantWords[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock1_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D0200_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock1[2] = {
    0x00000003, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordLinkWordsBlock2_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock2[2] = {
    (unsigned int)addrLow_Weaponai_ToggleFiringModeWithAmmoCheck, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock2_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_resource_animation_D0210_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock2[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordLinkWordsBlock3_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D0220_us_rev1.c */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock3[2] = {
    0x00000004, (unsigned int)addrLow_Weapon_EnterChargeStateWithCues,
};
#endif

/* g_overlayOneFLinkRecordLinkWordsBlock4_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock4[2] = {
    (unsigned int)addrLow_Weaponai_UpdateSpinAndRepeatCue, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock3_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_resource_animation_D0230_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock3[4] = {
    0x00004EE8, 0x3F800000, 0x00000003, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordSentinelWords_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_D0240_us_rev1.c */
unsigned int g_overlayOneFLinkRecordSentinelWords[1] = {
    0xFFFFFFFF,
};
#endif

/* g_overlayOneFLinkRecordAddressWordsBlock1_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_overlayOneFLinkRecordAddressWordsBlock1[15] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800CF298,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock4_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D0280_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock4[2] = {
    0x00000002, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordLinkWordsBlock5_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock5[2] = {
    (unsigned int)addrLow_Weaponai_UpdateAnimatedFiringMode, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock5_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_resource_animation_D0290_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock5[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock6_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D02A0_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock6[2] = {
    0x00000003, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordLinkWordsBlock6_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock6[2] = {
    (unsigned int)addrLow_Weaponai_UpdateAnimatedFiringMode, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock7_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_resource_animation_D02B0_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock7[4] = {
    0x00004E8E, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordSentinelWordsBlock1_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_D02C0_us_rev1.c */
unsigned int g_overlayOneFLinkRecordSentinelWordsBlock1[1] = {
    0xFFFFFFFF,
};
#endif

/* g_overlayOneFLinkRecordAddressWordsBlock2_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_overlayOneFLinkRecordAddressWordsBlock2[15] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800CF298,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordLinkWordsBlock7_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D0300_us_rev1.c */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock7[2] = {
    0x00000008, (unsigned int)addrLow_Weapon_SetDelayAndRequestStateEight,
};
#endif

/* WEAPON_UPDATE_HELD_FIRE_CALLBACK_ADDRESS.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock8[3] = {
    (unsigned int)addrLow_Weaponai_UpdateHeldFire, 0x00000000, 0x800CF258,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock8_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_animation_D0314_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock8[3] = {
    0x3F800000, 0x00000003, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordSentinelWordsBlock2_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_D0320_us_rev1.c */
unsigned int g_overlayOneFLinkRecordSentinelWordsBlock2[1] = {
    0xFFFFFFFF,
};
#endif

/* g_overlayOneFLinkRecordAddressWordsBlock3_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324 */
unsigned int g_overlayOneFLinkRecordAddressWordsBlock3[15] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800CF298,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

/* ROM-grounded data: src/rw_weapon_state_entry_D0360_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock9[2] = {
    0x00000002, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock10_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock9[2] = {
    (unsigned int)addrLow_Weaponai_TryEnterAmmoCostState, 0x00000000,
};

unsigned int g_overlayOneFLinkRecordConstantWordsBlock10[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock11_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D0380_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock11[2] = {
    0x00000003, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock12_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368_unclaimed_D0380_unclaimed_D0388 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock10[2] = {
    (unsigned int)addrLow_Weaponai_TryEnterAmmoCostState, 0x00000000,
};

unsigned int g_overlayOneFLinkRecordConstantWordsBlock12[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordLinkWordsBlock11_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D03A0_us_rev1.c */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock11[2] = {
    0x0000000B, (unsigned int)addrLow_Weapon_EmptyAlternateFireHook,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock13_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368_unclaimed_D0380_unclaimed_D0388_unclaimed_D03A0_unclaimed_D03A8 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock12[2] = {
    (unsigned int)addrLow_Weapon_UpdateHeldAlternateFire_Ovl1F, 0x00000000,
};

unsigned int g_overlayOneFLinkRecordConstantWordsBlock13[4] = {
    0x00004EE8, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordSentinelWordsBlock3_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_D03C0_us_rev1.c */
unsigned int g_overlayOneFLinkRecordSentinelWordsBlock3[1] = {
    0xFFFFFFFF,
};
#endif

/* g_overlayOneFLinkRecordAddressWordsBlock4_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368_unclaimed_D0380_unclaimed_D0388_unclaimed_D03A0_unclaimed_D03A8_unclaimed_D03C0_unclaimed_D03C4 */
unsigned int g_overlayOneFLinkRecordAddressWordsBlock4[15] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800CF298,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

/* ROM-grounded data: src/rw_weapon_state_entry_D0400_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock14[2] = {
    0x00000002, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordLinkWordsBlock13_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368_unclaimed_D0380_unclaimed_D0388_unclaimed_D03A0_unclaimed_D03A8_unclaimed_D03C0_unclaimed_D03C4_unclaimed_D0408 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock13[2] = {
    (unsigned int)addrLow_Weaponai_TryEnterAlternateStateEight, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock15_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_resource_animation_D0410_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock15[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock16_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D0420_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock16[2] = {
    0x00000003, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock17_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368_unclaimed_D0380_unclaimed_D0388_unclaimed_D03A0_unclaimed_D03A8_unclaimed_D03C0_unclaimed_D03C4_unclaimed_D0408_unclaimed_D0420_unclaimed_D0428 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock14[2] = {
    (unsigned int)addrLow_Weaponai_TryEnterAlternateStateEight, 0x00000000,
};

unsigned int g_overlayOneFLinkRecordConstantWordsBlock17[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordSentinelWordsBlock4_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_D0440_us_rev1.c */
unsigned int g_overlayOneFLinkRecordSentinelWordsBlock4[1] = {
    0xFFFFFFFF,
};
#endif

/* g_overlayOneFLinkRecordAddressWordsBlock5_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368_unclaimed_D0380_unclaimed_D0388_unclaimed_D03A0_unclaimed_D03A8_unclaimed_D03C0_unclaimed_D03C4_unclaimed_D0408_unclaimed_D0420_unclaimed_D0428_unclaimed_D0440_unclaimed_D0444 */
unsigned int g_overlayOneFLinkRecordAddressWordsBlock5[15] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800CF298,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

/* ROM-grounded data: src/rw_weapon_state_entry_D0480_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock18[2] = {
    0x00000002, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock19_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368_unclaimed_D0380_unclaimed_D0388_unclaimed_D03A0_unclaimed_D03A8_unclaimed_D03C0_unclaimed_D03C4_unclaimed_D0408_unclaimed_D0420_unclaimed_D0428_unclaimed_D0440_unclaimed_D0444_unclaimed_D0488 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock15[2] = {
    (unsigned int)addrLow_Weapon_UpdateSpecialFireAndAmmo, 0x00000000,
};

unsigned int g_overlayOneFLinkRecordConstantWordsBlock19[4] = {
    0x00004E84, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock20_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_entry_D04A0_us_rev1.c */
unsigned int g_overlayOneFLinkRecordConstantWordsBlock20[2] = {
    0x00000003, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordConstantWordsBlock21_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CF5C0_unclaimed_D01E8_unclaimed_D0200_unclaimed_D0208_unclaimed_D0220_unclaimed_D0228_unclaimed_D0240_unclaimed_D0244_unclaimed_D0288_unclaimed_D02A0_unclaimed_D02A8_unclaimed_D02C0_unclaimed_D02C4_unclaimed_D0308_unclaimed_D0320_unclaimed_D0324_unclaimed_D0368_unclaimed_D0380_unclaimed_D0388_unclaimed_D03A0_unclaimed_D03A8_unclaimed_D03C0_unclaimed_D03C4_unclaimed_D0408_unclaimed_D0420_unclaimed_D0428_unclaimed_D0440_unclaimed_D0444_unclaimed_D0488_unclaimed_D04A0_unclaimed_D04A8 */
unsigned int g_overlayOneFLinkRecordLinkWordsBlock16[2] = {
    (unsigned int)addrLow_Weapon_UpdateSpecialFireAndAmmo, 0x00000000,
};

unsigned int g_overlayOneFLinkRecordConstantWordsBlock21[4] = {
    0x00004E8E, 0x3F800000, 0x00000000, 0x00000000,
};
#endif

/* g_overlayOneFLinkRecordSentinelWordsBlock5_Ovl1F.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_weapon_state_end_D04C0_us_rev1.c */
unsigned int g_overlayOneFLinkRecordSentinelWordsBlock5[1] = {
    0xFFFFFFFF,
};
#endif
