#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: rodata/__osDevMgrMain/800CCB80 */
#endif

#if defined(VERSION_DE)
RestLinkerAlignmentFill4 k_SystemEncodedWords = {
    { 119, 114, 101, 97 },
};
#endif
