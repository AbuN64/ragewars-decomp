#include "span_1000/code_802A25C4.h"
#include "common/unused.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A6AC0.h"
#include "types.h"

extern s32 D_800D297C;



extern void func_80270910_de(f32 *, s32);
extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
extern void func_80272828_de(f32 *arg0);
extern void func_802732D0_de(char *object, float *output);
extern void func_802732EC_de(void *arg0, f32 *arg1);
extern void func_8027027C_de(void *arg0, s32 arg1);














void func_802A6174_de(void *arg0, void *arg1) {
    f32 local[16];
    f32 scale;
    void *entry;
    Matrix *dst;
    Matrix *src;

    entry = ((ChildB4 *)arg1)->unk_B0;
    if (entry != 0) {
        if (entry == (void *)-1) {
            ((ChildB4 *)arg1)->mat[D_800D297C] = ((ChildB4 *)arg1)->mat[D_800D297C ^ 1];
            ((ChildB4 *)arg1)->unk_B0 = 0;
        } else {
            func_80270910_de(local, entry + ((D_800D297C << 6) + 0x60));
            scale = D_800C5EB8_de;
            if (((Effect_func_802800C0_de *)entry)->entry->unk14 != 0) {
                scale = D_800C5EBC_de;
            }
            func_8027347C_de(local, scale, scale, scale);
            func_80272828_de(local);
            func_802732D0_de((char *)local, &((ChildB4 *)arg1)->pos[0]);
            if (((Node44 *)arg0)->unk_3C & 4) {
                func_802732EC_de(local, &((ChildB4 *)arg1)->rot[0]);
            } else {
                func_8027027C_de(local, arg1 + ((D_800D297C << 6) + 0x28));
            }
        }
        ((ChildB4 *)arg1)->unk_8 = ((Node44 *)arg0)->unk_8->unk_8;
    }
}
