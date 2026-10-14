#ifndef UNBAKE_SPAN_16E000_CODE_8041C67C_H
#define UNBAKE_SPAN_16E000_CODE_8041C67C_H
#include "types.h"
#include "span_16E000/code_80403BCC.h"


struct __OSContRequesFormatShort;
typedef struct __OSContRequesFormatShort __OSContRequesFormatShort;

struct __OSContRequesFormatShort;
struct __OSContRequesFormatShort {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
};

#endif
