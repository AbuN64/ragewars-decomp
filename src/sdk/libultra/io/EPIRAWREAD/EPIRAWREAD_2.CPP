#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"
#if defined(VERSION_EU)
INCLUDE_RODATA("game_data", k_systemRunPiManagerJumpTableTrailingWord);
#endif

const unsigned char s_epirawreadExText[3] = {
    0x45, 0x58, 0x00,
};
const char s_epirawreadText[16] = "io/epirawread.c";
