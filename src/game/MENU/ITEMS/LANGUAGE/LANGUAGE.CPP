#include "include_asm.h"
#include "COMMON/EXTERNS_21.H"
#include "TYPES.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/MEASURED_STORAGE.H"
#include "COMMON/UNUSED.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern s32 Menu_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 Items_AdjustLanguage(void *first, void *second) {
    Shared_Game *game = &D_801462C8;
    game->language = Menu_AdjustValue(second, game->language, 1, 0, 3, 1);
    return 0;
}
#endif

#if defined(VERSION_EU)
              /* size 0x0 */


unsigned char D_auto_func_8044502C_eu_padding_1BB02C[4] = { 0x00, 0x00, 0x28, 0x21 };

 /* opaque address transport */

s32 CItemValue_BindItemValueField(struct Measured_func_80445FB4_eu_5a0991979bf8 *field) {
    field->value = &D_800E2304; /* types.abi.opaque_pointer: field carries an address only */
    return 0;
}
#endif

#if defined(VERSION_EU_X)
            /* size 0x0 */

 /* opaque address transport */

s32 func_804460E4_eu_x(struct Measured_func_80445FB4_eu_5a0991979bf8 *field) {
    field->value = &D_800DDCB8; /* types.abi.opaque_pointer: field carries an address only */
    return 0;
}
#endif
