#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8025E568.h"
#include "types.h"





extern void *func_8028FDB4_de(void *arg0, s32 arg1);
extern void func_80271FC8_de(void *arg0, s32 arg1, void *arg2, void *arg3);




void func_802604AC_de(void *arg0, s32 arg1, void *arg2) {
    ObjectLinks24_2 *o = arg0;
    ObjRecAt2V1 *indices = (void *)o->unk_0;
    s16 idx;
    Rec_func_8024C92C_de *recs;
    void *base;
    Triple *out = arg2;

    idx = indices[arg1].translation;
    if (idx == -1) {
        recs = (void *)o->unk_4;
        __builtin_memcpy(out, &recs[arg1], sizeof(*out));
        return;
    }
    base = func_8028FDB4_de(o->unk_8, (s32) idx);
    func_80271FC8_de(arg2, o->unk_20,
                  (char *)base + (o->unk_18) * 4,
                  (char *)base + (o->unk_1C) * 4);
}
