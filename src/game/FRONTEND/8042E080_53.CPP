#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_53.H"

/* Returns 0x648, the byte size PAKInterface_CheckRecordsNoteCapacity passes on to Pak_BytesToPakPages for the object it
   creates when it has none. */
s32 PAKInterface_GetRecordsNoteSize(void) {
    return 0x648;
}
