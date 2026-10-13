#include "span_1000/code_8028308C.h"
#include "types.h"
#include "common/unused.h"


extern char D_801379C0;
extern char D_8013B1A8;

extern void func_80279A00_de(void *arg0);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *arg0, void *arg1);

extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);




void func_80283278_de(struct EffectSystem *arg0, s32 arg1) {
    s32 *temp_v1_3;
    s32 temp_a1;
    s32 temp_v1_2;
    u16 temp_v1;
    Effect_func_802800C0_de *temp_s1;
    Effect_func_802800C0_de *var_s0;

    var_s0 = arg0->lists[2].head;
    if (var_s0 != 0) {
        do {
            temp_v1 = var_s0->kind;
            temp_s1 = var_s0->next;
            if (((temp_v1 == 0x414) || (temp_v1 == 0x42D)) &&
                (var_s0->owner == (void *)arg1)) {
                temp_v1_2 = var_s0->flags;
                if (temp_v1_2 & 0x100) {
                  if (!(temp_v1_2 & 0x800)) {
                    func_80279A00_de(var_s0);
                    if (var_s0->unk1D9 != 0) {
                        func_80284178_de(var_s0);
                        func_802A42F4_de(&D_801379C0, var_s0);
                    }
                    temp_a1 = var_s0->unk138;
                    if (temp_a1 != 0) {
                        func_80268C7C_de(&D_8013B1A8, temp_a1);
                        var_s0->unk138 = 0;
                    }
                    temp_v1_3 = var_s0->refCount;
                    if (temp_v1_3 != 0) {
                        *temp_v1_3 -= 1;
                    }
                    var_s0->flags =
                        var_s0->flags & 0xFDFFFEFF;
                    func_80255ED8_de(var_s0->list, (s32)var_s0);
                    var_s0->list = 0;
                    func_80255CB8_de(&arg0->free, (s32)var_s0);
                    if (var_s0->flags & 0x01000000) {
                        func_80255ED8_de(&arg0->groups, (s32)var_s0);
                    }
                  }
                }
            }
            var_s0 = temp_s1;
        } while (var_s0 != 0);
    }
}
