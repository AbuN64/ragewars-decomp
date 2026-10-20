#include "COMMON/FIELD_VEC_B0.H"
#include "WEAPONS/80213ED4_21.H"

/** Store one word into both elements of a two-word value. */
void func_802171BC_de(int *value, int word) {
    value[0] = word;
    value[1] = word;
}
