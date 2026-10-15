#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);












void func_8024CA10_de(void *arg0, s32 arg1, void *arg2) {
    char *o = (char *)arg0;
    s16 idx;
    char *rec;
    void *base;
    char *a;

    idx = ((struct ObjRecAt2V1 *) (((ObjectLinks24 *) o)->unk_0 + (arg1 * 4)))->unk2;
    if (idx == -1) {
        f32 scale;
        rec = ((ObjectLinks24 *)(o))->unk_4 + arg1 * 0x14;
        scale = (3.0518509447574615e-05f);
        ((Vector4f *)(arg2))->x = (f32)(((ObjectState14 *)(rec))->unk_C) * scale;
        ((Vector4f *)(arg2))->y = (f32)(((ObjectState14 *)(rec))->unk_E) * scale;
        ((Vector4f *)(arg2))->z = (f32)(((ObjectState14 *)(rec))->unk_10) * scale;
        ((Vector4f *)(arg2))->w = (f32)(((ObjectState14 *)(rec))->unk_12) * scale;
        return;
    }
    base = func_8028FDB4_de(((ObjectLinks24 *)(o))->unk_C, (s32)idx);
    a = (char *)base + (((ObjectLinks24 *)(o))->unk_10) * 4;
    base = (char *)base + (((ObjectLinks24 *)(o))->unk_14) * 4;
    {
        f32 scale;
        scale = ((ObjectLinks24 *)(o))->unk_20;
        ((Vector4f *)(arg2))->x = ((Vector4f *)(a))->x + scale * (((Vector4f *)(base))->x - ((Vector4f *)(a))->x);
        ((Vector4f *)(arg2))->y = ((Vector4f *)(a))->y + scale * (((Vector4f *)(base))->y - ((Vector4f *)(a))->y);
        ((Vector4f *)(arg2))->z = ((Vector4f *)(a))->z + scale * (((Vector4f *)(base))->z - ((Vector4f *)(a))->z);
        ((Vector4f *)(arg2))->w = ((Vector4f *)(a))->w + scale * (((Vector4f *)(base))->w - ((Vector4f *)(a))->w);
    }
}
