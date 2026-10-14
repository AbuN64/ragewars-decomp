#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80411B68.h"
/* Returns the halfword at offset 0xE of the object held at offset 0x48C of record i in the
   1180-byte record table D_80153C28 points to; func_80411C60_de reads offset 0x10 of the same
   object. */
extern char *D_80153C28;

short func_80411C28_de(int index) {
    return ((struct ObjRecAtE *) ((struct ObjectLinks490 *) (D_80153C28 + (index * 1180)))->unk_48C)->unkE;
}
