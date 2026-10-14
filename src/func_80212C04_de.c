#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802106E0.h"
#include "types.h"

extern void *func_8022A83C_de(char *);
extern s32 func_80209874_de(void *, s32);
extern void func_80211020_de(void *);
extern void func_80209948_de(s32 *, s32);
extern void func_80208410_de(void *);
extern void func_80208EB0_de(s32 *);
extern char D_80145040;






void func_80212C04_de(void *arg0) {
    s32 *rec;
    void *v0;

    ObjRecAt1D8V1 *object = arg0;
    ObjRecAt1454V1 *actor = object->unk1D8;

    rec = actor->unk1454;
    v0 = func_8022A83C_de(&D_80145040);
    if (v0 == (void *) *rec) {
        func_80209874_de(rec, 10);
        return;
    }
    if (v0 != 0) {
        func_80209874_de(rec, 2);
        return;
    }
    func_80211020_de(rec);
    func_80209948_de(rec, rec[3]);
    func_80208410_de(rec);
    func_80208EB0_de(rec);
}
