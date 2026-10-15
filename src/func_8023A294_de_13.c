#include "span_1000/code_8023A284.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"
#include "common/unused.h"
#include "shared/func_80245BC0_de_closed.h"


extern Region D_80103F88;

extern func_80205628_S3 *D_800FFE20;


extern void func_802AD370_de(int a0, int a1, int a2, int a3, int a4, int a5);



void osCreateMesgQueue(void *arg0, s32 arg1, s32 arg2);

void **func_8025343C_de(s32 arg0, s32 arg1, s32 arg2, void *arg3);

void func_802BB420_de(void *arg0, void *arg1, s32 arg2);

extern void osCreateMesgQueue(void *arg0, s32 arg1, s32 arg2);

extern void func_802BB420_de(void *arg0, void *arg1, s32 arg2);


extern struct Shape_typemap_110 D_800FF230;

void func_8023C6BC_de(void) {
    u32 var_a2;
    u32 var_a3;
    s32 var_a1;
    u32 *var_a0;
    u32 temp_v1;
    Region *var_v1;
    s32 var_a0_2;
    u16 temp_v0;
    s32 *out;
    s32 *ordered;

    var_a2 = 0;
    var_a3 = 0x80000000;
    var_a1 = 0;
    var_a0 = &D_800FFB5C;
    do {
        temp_v1 = *var_a0;
        if (var_a2 < temp_v1) {
            var_a2 = temp_v1;
        }
        if (temp_v1 < var_a3) {
            var_a3 = temp_v1;
        }
        *var_a0 = temp_v1 + 1;
        var_a1 += 1;
        var_a0 += 4;
    } while (var_a1 < 0x18);

    var_v1 = &D_80103F88;
    var_a0_2 = 0;
    if (&D_80103F88 != 0) {
        do {
            temp_v0 = var_v1->pages;
            var_v1 = var_v1->next;
            var_a0_2 += temp_v0 << 0xC;
        } while (var_v1 != 0);
    }

    out = D_800FF24C;
    ordered = out;
    *ordered = var_a0_2;
    ordered[-3] = var_a2;
    ordered[-2] = var_a3;
    __builtin_memcpy(&out[-1], &D_800FFE20->unkC, sizeof(s32));
}

void func_8023C750_de(void) {
    func_802AD370_de(0x1F, 0x1FE000, 0x200000, 0, 0x100000, 7);
}

s32 func_8023C78C_de(s32 arg0, s32 arg1_unused, s32 arg2)
{
  char sp10[0x18];
  int new_var2;
  Block10 blk;
  s32 sp38;
  u32 temp_s1;
  s32 sp3C;
  u32 rounded;
  void **temp_v0;
  Draw *temp_v1;
  int new_var;
  temp_s1 = ((u32) (arg0 + 0xFFF)) >> 0xC;
  new_var = (temp_s1 + 1) & (~1);
  if (1)
  {
    osCreateMesgQueue(sp10, (s32) (&sp38), 1);
    blk.f28 = 3;
    blk.f2C = arg0;
    blk.f34 = (void **) sp10;
    new_var2 = temp_s1 * 4;
    rounded = new_var + 0x18;
    temp_v0 = func_8025343C_de(0, new_var2 + rounded, 3, &D_800C3600_de);
    temp_v1 = *temp_v0;
    blk.f30 = temp_v1;
    temp_v1->model = temp_v0;
  }
  ((Draw *)blk.f30)->allocationMode = arg2;
  func_802BB420_de(&D_800FF254, &blk.f28, 1);
  func_802BB2A0_de(sp10, &sp3C, 1);
  return sp3C;
}

void func_8023C85C_de(s32 arg0) {
    char sp10[0x18];
    Block_func_8023C85C_de block;
    s32 sp38;
    void *sp3C;

    osCreateMesgQueue(sp10, (s32)&sp38, 1);
    block.type = 2;
    block.value = arg0;
    block.data = sp10;
    func_802BB420_de(&D_800FF254, &block, 1);
    func_802BB2A0_de(sp10, &sp3C, 1);
    func_80253838_de(0, ((Draw *)(sp3C))->model);
}

void func_8023C8D4_de(struct Shape_typemap_110 *arg0) {
    *arg0 = D_800FF230;
}
