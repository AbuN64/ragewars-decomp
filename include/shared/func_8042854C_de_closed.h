#ifndef FUNC_8042854C_DE_CLOSED_H
#define FUNC_8042854C_DE_CLOSED_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_804264F0.h"

/* Picks a menu element id from arg0 and whether arg2 is set, hides the 0x14B child of that element and stores 0x64 and the value func_8042863C_de reports for arg1 into its 0x14A child; on eu-x every element id in this menu is renumbered 4 higher. */

extern ResultsOptionsScreen *D_800E4690;

#if defined(VERSION_DE)
enum { ID_SHIFT = -4, OPTION_SHIFT = -2 };
#elif defined(VERSION_EU_X)
enum { ID_SHIFT = 4, OPTION_SHIFT = 4 };
#else
enum { ID_SHIFT = 0, OPTION_SHIFT = 0 };
#endif


#endif
