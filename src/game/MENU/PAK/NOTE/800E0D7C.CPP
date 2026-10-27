#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_fifoText[5] = "fifo";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804058B0_E197C_us_rev1.c */
const char D_blob_dd23482635aa126a2066[5] = "fifo";
#endif
