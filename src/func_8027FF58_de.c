#include "common/unused.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027A0F4.h"
#include "types.h"


extern char D_801379C0;
extern char D_8013B1A8;

extern void func_80279A00_de(void *arg0);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *arg0, void *arg1);

extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);









void func_8027FF58_de(void *arg0) {
    s32 *temp_v1_2;
    s32 temp_a1;
    s32 temp_v1;
    s32 var_s3;
    s32 clear_mask;
    s32 remove_offset;
    s32 active_mask;
    s32 flagged_offset;
    s32 head_offset;
    ParticleEffect *temp_s0;
    ParticleEffect *var_s1;
    u8 *head_cursor;

    var_s3 = 0;
    clear_mask = 0xFDFFFEFF;
    remove_offset = 0xFC00;
    active_mask = 0x01000000;
    flagged_offset = 0xFC14;
    do {
        __builtin_memcpy(&var_s1, &((EffectSystem *)arg0)->lists[var_s3].head, sizeof(var_s1));
        if (var_s1 != 0) {
            do {
                temp_s0 = var_s1;
                var_s1 = var_s1->next;
                temp_v1 = temp_s0->flags;
                if (temp_v1 & 0x100) {
                  if (!(temp_v1 & 0x800)) {
                    func_80279A00_de(temp_s0);
                    if (temp_s0->unk1D9 != 0) {
                        func_80284178_de(temp_s0);
                        func_802A42F4_de(&D_801379C0, temp_s0);
                    }
                    temp_a1 = temp_s0->unk138;
                    if (temp_a1 != 0) {
                        func_80268C7C_de(&D_8013B1A8, temp_a1);
                        temp_s0->unk138 = 0;
                    }
                    temp_v1_2 = temp_s0->refCount;
                    if (temp_v1_2 != 0) {
                        *temp_v1_2 -= 1;
                    }
                    temp_s0->flags = temp_s0->flags & clear_mask;
                    func_80255ED8_de(temp_s0->list, (s32)temp_s0);
                    temp_s0->list = 0;
                    func_80255CB8_de((char *)arg0 + remove_offset, (s32)temp_s0);
                    if (temp_s0->flags & active_mask) {
                        func_80255ED8_de((char *)arg0 + flagged_offset, (s32)temp_s0);
                    }
                  }
                }
            } while (var_s1 != 0);
        }
        var_s3 += 1;
    } while (var_s3 < 3);
}
