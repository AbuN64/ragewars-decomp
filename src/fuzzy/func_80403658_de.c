#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80400000.h"
#include "TYPES.H"
extern State_func_8040385C_de *D_800E2830;
extern f32 D_800DCC78;
extern void *func_8028FDB4_de(void *,s32);
extern void func_80400E50_de(Vec3 *,void *,s32,s32);
extern void func_80271F68_de(Vec3 *,Vec3 *,Vec3 *);
extern f32 func_802725FC_de(Vec3 *),func_80271AA8_de(Vec3 *);
Vec3 func_80403658_de(void) {
    Vec3 first,second,delta,result,temp,fallback;
    StridedTable *table;
    if (D_800E2830->unk38 == 0) {
        result.x = 0;
        result.y = 0;
    } else {
        table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->unk4,0),0),0);
        func_80400E50_de(&temp,table->data,table->count,0);
        first = temp;
        if (D_800E2830->unk38 == 0) {
            fallback.x = D_800DCC78;
            fallback.y = 0;
            fallback.z = 0;
            second = fallback;
        } else {
            table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->unk4,0),0),1);
            func_80400E50_de(&temp,table->data,table->count,0);
            second = temp;
        }
        func_80271F68_de(&delta,&second,&first);
        result.x = -func_802725FC_de(&delta);
        result.y = func_80271AA8_de(&delta);
    }
    result.z = 0;
    return result;
}
