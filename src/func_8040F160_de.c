#include "span_16E000/code_8040F1E0.h"
#include "types.h"

/* Measures the pixel width of a string of the given length in the given font by summing each character's signed width byte from the font record func_8041200C_de returns, then adding the spacing func_80411C60_de reports once between each pair of characters.
   Adapted from func_8025C8D8_de with the two clears and per-record call replaced by the font lookup, the width sum and the spacing term changed. */





extern Font_func_8040F160_de *func_8041200C_de(s32 index);
extern short func_80411C60_de(s32 index);

s32 func_8040F160_de(s32 font, u8 *text, s32 length) {
    Font_func_8040F160_de *record;
    s32 i;
    s32 total;

    record = func_8041200C_de(font);
    total = 0;
    for (i = 0; i < length; i++) {
        total += record->glyphs[*text++ - 0x20].width;
    }
    total += func_80411C60_de(font) * (length - 1);
    return total;
}
