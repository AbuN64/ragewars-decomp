#include "include_asm.h"

const char g_graphicsetType[16] = "graphicset type";

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const char rodata_unresolved_800C4F68[17] =
    "graphicset index\000";
#endif
