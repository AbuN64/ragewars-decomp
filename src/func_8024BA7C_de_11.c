#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"








/** Lerp a 4-component vector: out = a + t * (b - a). */
void func_8024C8C4_de(void *arg0, f32 t, void *a, void *b) {
    Vector4f *out = arg0;
    Vector4f *left = a;
    Vector4f *right = b;

    out->x = left->x + (t * (right->x - left->x));
    out->y = left->y + (t * (right->y - left->y));
    out->z = left->z + (t * (right->z - left->z));
    out->w = left->w + (t * (right->w - left->w));
}
