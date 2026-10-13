#include "types.h"
extern f32 D_800C5B04_de;
extern f32 D_800C5B08_de;

/* Invert a 4x4 matrix with partial pivoting. Return one for a singular
 * matrix, leaving the destination untouched until elimination succeeds. */
s32 func_8029D510_de(f32 output[4][4], f32 input[4][4])
{
    f32 rows[4][8];
    s32 order[4];
    s32 i, j, k, pivot, row, other;
    f32 largest, magnitude, value, factor;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            rows[i][j] = input[i][j];
            rows[i][j + 4] = 0.0f;
        }
        rows[i][i + 4] = D_800C5B04_de;
        order[i] = i;
    }
    for (i = 0; i < 4; i++) {
        largest = rows[order[i]][i];
        if (largest < 0.0f) largest = -largest;
        pivot = i;
        for (j = i + 1; j < 4; j++) {
            magnitude = rows[order[j]][i];
            if (magnitude < 0.0f) magnitude = -magnitude;
            if (largest < magnitude) {
                pivot = j;
                largest = magnitude;
            }
        }
        row = order[pivot];
        order[pivot] = order[i];
        order[i] = row;
        value = rows[row][i];
        if (value == 0.0f) return 1;
        rows[row][i] = D_800C5B08_de;
        for (j = i + 1; j < 8; j++) rows[row][j] /= value;
        for (j = i + 1; j < 4; j++) {
            other = order[j];
            factor = -rows[other][i];
            if (factor != 0.0f) {
                rows[other][i] = 0.0f;
                for (k = i + 1; k < 8; k++) rows[other][k] += factor * rows[row][k];
            }
        }
    }
    for (i = 3; i > 0; i--) {
        row = order[i];
        for (j = i - 1; j >= 0; j--) {
            other = order[j];
            factor = rows[other][i];
            for (k = i; k < 8; k++) rows[other][k] -= factor * rows[row][k];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) output[i][j] = rows[order[i]][j + 4];
    }
    return 0;
}
