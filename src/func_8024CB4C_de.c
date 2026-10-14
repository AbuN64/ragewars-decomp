#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);
extern void func_80270AAC_de(void *arg0, s32 arg1, void *arg2, void *arg3);

void func_8024CB4C_de(ObjectLinks24_2 *arg0, s32 arg1, Vector4f *arg2) {
    ObjectLinks24_2 *o = arg0;
    ObjRecAt2V1 *indices;
    s16 idx;
    ObjectState14 *rec;
    void *base;
    f32 scale;

    indices = (void *)o->unk_0;
    idx = indices[arg1].unk2;
    if (idx == -1) {
        rec = (void *)(o->unk_4 + arg1 * 0x14);
        scale = D_800C3B7C;
        arg2->x = (f32)rec->unk_C * scale;
        arg2->y = (f32)rec->unk_E * scale;
        arg2->z = (f32)rec->unk_10 * scale;
        arg2->w = (f32)rec->unk_12 * scale;
        return;
    }
    base = func_8028FDB4_de(o->unk_C, (s32)idx);
    func_80270AAC_de(arg2, o->unk_20,
                    (char *)base + o->unk_10 * 4,
                    (char *)base + o->unk_14 * 4);
}
