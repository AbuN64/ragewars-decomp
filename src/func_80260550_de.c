#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025E568.h"
#include "types.h"
#include "span_C76B0/data.h"

extern char *func_8028FDB4_de(s32 *, s32);
extern void func_80270AAC_de(void *arg0, s32 arg1, void *arg2, void *arg3);











void func_80260550_de(void *arg0, s32 arg1, void *arg2) {
    ObjectLinks24_2 *o = arg0;
    Vector4f *out = arg2;
    func_8025E52C_S1 *indices = (void *)o->unk_0;
    s16 idx;
    ObjectState14 *rec;
    void *base;
    f32 scale;

    idx = indices[arg1].unk2;
    if (idx == -1) {
        rec = (void *)(o->unk_4 + arg1 * 0x14);
        scale = D_800C416C_de;
        out->x = (f32)(rec->unk_C) * scale;
        out->y = (f32)(rec->unk_E) * scale;
        out->z = (f32)(rec->unk_10) * scale;
        out->w = (f32)(rec->unk_12) * scale;
        return;
    }
    base = func_8028FDB4_de(o->unk_C, (s32) idx);
    func_80270AAC_de(arg2, o->unk_20,
                  (char *)base + (o->unk_10) * 4,
                  (char *)base + (o->unk_14) * 4);
}
