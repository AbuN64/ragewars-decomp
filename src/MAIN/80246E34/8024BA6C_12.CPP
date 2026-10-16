#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
#include "TYPES.H"





extern char *func_8028FDB4_de(s32 *, s32);










void func_8024C92C_de(void *arg0, s32 arg1, void *arg2) {
    ObjectLinks24 *o = arg0;
    Vec3 *out = arg2;
    ObjRecAt2V1 *indices = (void *)o->unk_0;
    s16 idx;
    ObjectState14 *recs;
    f32 *base;
    f32 *a;
    f32 scale;

    idx = indices[arg1].translation;
    if (idx == -1) {
        recs = (void *)o->unk_4;
        *out = recs[arg1].position;
        return;
    }
    base = func_8028FDB4_de(o->translationFrames, (s32) idx);
    a = base + o->translationFirst;
    base = base + o->translationNext;

    scale = o->unk_20;

    out->x = a[0] + scale * (base[0] - a[0]);
    out->y = a[1] + scale * (base[1] - a[1]);
    out->z = a[2] + scale * (base[2] - a[2]);
}
