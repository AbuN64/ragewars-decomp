#include "include_asm.h"
#include "COMMON/EXTERNS_21.H"
#include "TYPES.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/MEASURED_STORAGE.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern s32 Menu_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 Items_AdjustLanguage(void *first, void *second) {
    Shared_Game *game = &g_gameSettings;
    game->language = Menu_AdjustValue(second, game->language, 1, 0, 3, 1);
    return 0;
}
#endif

#if defined(VERSION_EU)
              /* size 0x0 */


unsigned char g_LanguageTrailingBytes[4] = { 0x00, 0x00, 0x28, 0x21 };

 /* opaque address transport */

s32 CItemValue_BindItemValueField(struct ItemValueBindingView *field) {
    field->value = &g_languageMenuAlternateTextTable; /* types.abi.opaque_pointer: field carries an address only */
    return 0;
}
#endif

#if defined(VERSION_EU_X)
            /* size 0x0 */

 /* opaque address transport */

s32 Items_SetLanguageTextTable(struct ItemValueBindingView *field) {
    field->value = &g_languageMenuTextTable; /* types.abi.opaque_pointer: field carries an address only */
    return 0;
}
#endif
