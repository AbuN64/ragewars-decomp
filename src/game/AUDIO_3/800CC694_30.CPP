#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B6664_CD6C0);
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_func_802B6664_de_800C7874);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int D_blob_70cd42de207f8964de31[2] = {
    0xBF800000, 0x3F800000,
};
#endif
