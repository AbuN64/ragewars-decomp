#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_audioAbortdisktransferDataConstantWords[1] = {
    0x003FFF01,
};

#if defined(VERSION_US)
unsigned int data_unresolved_800D3F0C[1] = {
    0x52445F4C,
};
#endif

#if defined(VERSION_EU)
#if defined(VERSION_EU)
extern char g_audioDiskTransferLinkTable[];
unsigned int data_unresolved_800E58DC[1] = {
    (unsigned int)g_audioDiskTransferLinkTable + 0x18,
};
#endif
#endif

#if defined(VERSION_DE)
#if defined(VERSION_DE)
extern char g_osaisetfrequencyDataConstantWords[];
unsigned int data_unresolved_800D525C[1] = {
    (unsigned int)g_osaisetfrequencyDataConstantWords,
};
#endif
#endif
