#include "include_asm.h"

const char g_graphicsetType[16] = "graphicset type";

#if defined(VERSION_US)
const char rodata_unresolved_800C4F68[17] =
    "graphicset index\000";
#endif

#if defined(VERSION_EU_X)
const char rodata_unresolved_800C5328[17] =
    "graphicset index\000";
#endif

#if defined(VERSION_EU)
const char rodata_unresolved_800C52E8[17] =
    "graphicset index\000";
#endif

#if defined(VERSION_DE)
const char rodata_unresolved_800C5038[17] =
    "graphicset index\000";
#endif
