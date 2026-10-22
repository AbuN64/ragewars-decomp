#include "MENU_2/EXTERNS_2.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "TYPES.H"
#include "MENU_2/MEASURED.H"
#include "COMMON/UNUSED.H"

#if defined(VERSION_EU_X)
            /* size 0x0 */

 /* opaque address transport */

s32 func_804460E4_eu_x(struct MeasuredCode8042FBEC *arg0) {
    arg0->value = &D_800DDCB8; /* types.abi.opaque_pointer: field carries an address only */
    return 0;
}
#endif
