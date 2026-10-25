#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_53.H"

/* Returns 0x648, the byte size func_80435384_de passes on to Ovlgame_BytesToPakPages for the object it
   creates when it has none. */
s32 func_80435424_de(void) {
    return 0x648;
}
