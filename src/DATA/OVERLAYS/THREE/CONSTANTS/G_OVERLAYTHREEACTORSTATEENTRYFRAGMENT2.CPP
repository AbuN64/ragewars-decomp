#include "DATA/ACTION_CALLBACKS/BREAKABLE_HIT_CALLBACK_ADDRESSES.H"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_actor_state_entry_CE210_us_rev1.c */
unsigned int g_overlayThreeActorStateEntryFragment2[3] = {
    0x00000001, (unsigned int)addrLow_Action_DeactivateBreakable, (unsigned int)addrLow_Action_ResolveBreakableHit,
};
#endif
