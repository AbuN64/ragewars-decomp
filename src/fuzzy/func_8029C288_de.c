#include "TYPES.H"

extern f32 func_802B72B0_de(f32);
extern f32 D_800C5A58_de, D_800C5A5C, D_800C5A60_de, D_800C5A64;
extern f32 D_800C5A68_de, D_800C5A6C, D_800C5A70_de, D_800C5A74;
extern f32 D_800C5A78_de, D_800C5A7C, D_800C5A80_de;

f32 func_8029C288_de(f32 *a, f32 *b) {
    f32 lengthA, lengthB, product, value, polynomial, root, result;
    s32 negative;
    lengthA = a[0]*a[0] + a[1]*a[1] + a[2]*a[2];
    if (lengthA <= 0.0f) lengthA = 0.0f;
    else lengthA = func_802B72B0_de(lengthA);
    lengthB = b[0]*b[0] + b[1]*b[1] + b[2]*b[2];
    if (lengthB <= 0.0f) lengthB = 0.0f;
    else lengthB = func_802B72B0_de(lengthB);
    product = lengthA * lengthB;
    result = 0.0f;
    if (product != 0.0f) {
        value = (a[0]*b[0] + a[1]*b[1] + a[2]*b[2]) / product;
        if (D_800C5A58_de < value) value = D_800C5A58_de;
        else if (value < D_800C5A5C) value = D_800C5A5C;
        if (D_800C5A60_de < value) value = D_800C5A60_de;
        if (value < D_800C5A64) value = D_800C5A64;
        negative = 0;
        if (value < 0.0f) { negative = 1; value = -value; }
        polynomial = ((((value * D_800C5A68_de + D_800C5A6C) * value - D_800C5A70_de) * value + D_800C5A74) * value - D_800C5A78_de) * value + D_800C5A7C;
        root = D_800C5A60_de - value;
        if (root <= 0.0f) root = 0.0f;
        else root = func_802B72B0_de(root);
        result = D_800C5A80_de - root * polynomial;
        if (negative) result = -result;
        result = D_800C5A80_de - result;
    }
    return result;
}
