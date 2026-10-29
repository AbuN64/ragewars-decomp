#include "DATA/ACTION_CALLBACKS/ACTION_ACTIVATE_ROM_ENTRY.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_actor_state_entry_CE1F0_us_rev1.c */
unsigned int g_overlayThreeActorStateEntryFragment1[2] = {
    0x00000000, (unsigned int)addrLow_Action_ActivateActorAndClearMotion,
};
#endif
