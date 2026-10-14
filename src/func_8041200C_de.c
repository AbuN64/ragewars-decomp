#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80411B68.h"
#include "types.h"

/* A stride of 1180 bytes. The debugger showed the global holding 0x80696F50 and the two observed
   indices, 0 and 1, returning 0x80696F50 and 0x806973EC, which differ by exactly 1180. */


extern GlyphBuffer *D_80153C28;

GlyphBuffer *func_8041200C_de(s32 index) {
    return &D_80153C28[index];
}
