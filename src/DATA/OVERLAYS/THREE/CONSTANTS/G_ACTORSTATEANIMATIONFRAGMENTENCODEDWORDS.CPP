#include "DATA/ACTION_CALLBACKS/BREAKABLE_PROXIMITY_AND_HEALTH_CALLBACK_ADDRESSES.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800CD4C4_unclaimed_CE0F0_unclaimed_CE104_unclaimed_CE10C */
unsigned int g_ActorStateAnimationFragmentEncodedWords[3] = {
    (unsigned int)addrLow_Action_UpdateBreakableProximity, 0x801043D8, (unsigned int)addrLow_Actionai_UpdateHealthFlag,
};

/* ROM-grounded data: src/rw_actor_state_animation_CE118_us_rev1.c */
unsigned int g_overlayThreeActorStateAnimationFragment10[3] = {
    0x3F800000, 0x00000000, 0x00000000,
};
#endif
