#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80271B18.h"
#include "types.h"

extern f32 D_800C99B0;




/** Reset the matrix to identity-diagonal * D_800C99B0, zeroing the rest. */
void func_802727D8_de(void *arg0) {
    Matrix *matrix = arg0;
    f32 zero = 0.0f;

    matrix->m[15] = D_800C99B0;
    matrix->m[10] = D_800C99B0;
    matrix->m[5] = D_800C99B0;
    matrix->m[0] = D_800C99B0;
    matrix->m[14] = zero;
    matrix->m[13] = zero;
    matrix->m[12] = zero;
    matrix->m[11] = zero;
    matrix->m[9] = zero;
    matrix->m[8] = zero;
    matrix->m[7] = zero;
    matrix->m[6] = zero;
    matrix->m[4] = zero;
    matrix->m[3] = zero;
    matrix->m[2] = zero;
    matrix->m[1] = zero;
}
