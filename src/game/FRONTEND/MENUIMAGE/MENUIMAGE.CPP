#include "include_asm.h"

#include "FRONTEND/ENTRYRECAT4D4.H"
#include "TYPES.H"
#include "FRONTEND/8043A0B0_12.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"

/* Clears the words at offsets 0x10 to 0x18 of a record, then stores the first value through
   Frontend_SetMenuImageResource and the next three through Frontend_SetMenuImageColor. */

void Frontend_InitMenuImage(s32 *record, s32 first, s32 second, s32 third, s32 fourth) {
    record[4] = 0;
    record[5] = 0;
    record[6] = 0;
    Frontend_SetMenuImageResource(record, first);
    Frontend_SetMenuImageColor(record, second, third, fourth);
}

/* Sets the words at offsets 0x10, 0x14 and 0x18 of a record to one, zero and one, then calls
   SoundElement_PlayFlatSound with 0xE83. */

void Frontend_StartMenuImageTransition(s32 *record) {
    record[4] = 1;
    record[5] = 0;
    record[6] = 1;
    SoundElement_PlayFlatSound(0xE83);
}

/* Advances the counter at offset 0x14 of a record by the step at 0x10; once it reaches 0xD both
   are cleared and the state word at 0x18 becomes 2. */
void Frontend_AdvanceMenuImageTransition(s32 *record) {
    record[5] += record[4];
    if (record[5] >= 0xD) {
        record[5] = 0;
        record[4] = 0;
        record[6] = 2;
    }
}

/* Returns the word at offset 0x14 of a record. */
s32 Frontend_GetMenuImageFrame(s32 *record) {
    return record[0x14 / 4];
}

/* Returns whether the word at offset 0x18 of a record equals 2; Frontend_GetMenuImageState returns that word. */
s32 Frontend_IsMenuImageTransitionComplete(s32 *record) {
    return record[0x18 / 4] == 2;
}

/* Stores a value into the first word of a record; Frontend_SetMenuImageColor, which follows it, fills the
   words after it. */
void Frontend_SetMenuImageResource(s32 *record, s32 value) {
    record[0] = value;
}

/* Stores three values into words 1 to 3 of a record; Frontend_SetMenuImageResource stores word 0. */
void Frontend_SetMenuImageColor(s32 *record, s32 first, s32 second, s32 third) {
    record[1] = first;
    record[2] = second;
    record[3] = third;
}

/* Returns the word at offset 0x18 of a record. */
s32 Frontend_GetMenuImageState(s32 *record) {
    return record[0x18 / 4];
}
#if VERSION_EU
INCLUDE_DATA("ovl_80400000", D_auto_func_8043D1F4_eu_padding_1B31F4);
#endif
#if VERSION_EU_X
INCLUDE_DATA("ovl_80400000", D_auto_Menu_GetLocalizedEncodedResource_padding_12D324);
#endif
#if VERSION_US
INCLUDE_DATA("ovl_80400000", D_auto_func_8043C4F4_us_padding_1A04F4);
#endif
