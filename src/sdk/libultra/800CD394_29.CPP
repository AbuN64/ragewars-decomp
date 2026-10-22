#include "sdk/libgultra.h"

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_actor_state_entry_CE060_us_rev1.c */
extern char D_00203B60[];
extern char D_00203C08[];
unsigned int D_blob_c84dc03fb86ab9c374fb[3] = {
    0x00000040, (unsigned int)D_00203B60, (unsigned int)D_00203C08,
};
#endif
