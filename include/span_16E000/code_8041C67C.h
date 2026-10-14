#ifndef UNBAKE_SPAN_16E000_CODE_8041C67C_H
#define UNBAKE_SPAN_16E000_CODE_8041C67C_H
#include "types.h"
struct OSPfsState;
struct OSPfsState {
    u32 file_size;
    u32 game_code;
    u16 company_code;
    char ext_name[4];
    char game_name[16];
};

struct OSPfsState;
typedef struct OSPfsState OSPfsState;

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
