#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"








/** Lerp a 3-component vector: out = a + t * (b - a). */
void func_8024C874_de(void *arg0, f32 t, void *a, void *b) {
    Vec3 *out = arg0;
    Vec3 *start = a;
    Vec3 *end = b;
    out->x = start->x + (t * (end->x - start->x));
    out->y = start->y + (t * (end->y - start->y));
    out->z = start->z + (t * (end->z - start->z));
}
