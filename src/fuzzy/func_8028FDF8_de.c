#include "TYPES.H"

/* Difference between successive offsets in a resource table. */
s32 func_8028FDF8_de(const s32 *table, s32 index) {
    return table[index + 2] - table[index + 1];
}
