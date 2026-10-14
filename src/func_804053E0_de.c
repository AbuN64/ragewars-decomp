#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Reports through the third argument the size in 256-byte units, per func_804057EC_de, of entry j of
   record i in the table D_800E2854 points to, returning zero, or returns -2 when record i's state in
   D_801534F0 is not 3. */





extern struct RecordRecAt4V2 *D_800E2854;
extern s32 func_804057EC_de(s32);

s32 func_804053E0_de(s32 index, s32 entry, s32 *out) {
    if (D_801534F0[index] != 3) {
        return -2;
    }
    *out = func_804057EC_de(D_800E2854[index].entries[entry].size);
    return 0;
}
