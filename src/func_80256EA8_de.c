#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025D948.h"
#include "span_1000/code_8025E280.h"
#include "span_1000/code_802BD1A8.h"
#include "types.h"



extern void *D_80107E20[];
extern char D_80107E80;
extern u16 D_80107E9A;
extern char D_80142928;
extern void func_80256FC0_de(Work56EC8 *arg0);
extern s32 func_802BBBC0_de(s32);

extern void *func_802B3A44_de(void *arg0, s32 *arg1, s32 arg2, s16 arg3);


extern void func_8028FD4C_de(void *arg0, void *arg1);

extern void func_802BB2A0_de(s32, s32, s32);
extern void func_802B7400_de(void *arg0, s32 arg1);
s32 func_80256EA8_de(Work56EC8 *arg0, u32 unused)
{
  s32 completed;
  s32 event;
  s32 value;
  void *item;
  func_80256FC0_de(arg0);
  value = func_802BBBC0_de(arg0->owner);
  arg0->id = D_80107E9A;
  func_8025E48C_de();
  item = func_802B3A44_de(D_80107E20[D_800CB708], &completed, value, arg0->id);
  func_8025E4B0_de();
  if (completed != 0)
  {
    arg0->base = D_80107E20[D_800CB708];
    arg0->offset = ((((s32) item) - ((s32) D_80107E20[D_800CB708])) >> 3) << 3;
    func_802BD2F0_de();
    func_8028FD4C_de(&D_80142928, arg0->payload);
    D_800CB708 ^= 1;
    func_8025E23C_de();
    func_802BB2A0_de(&D_80107E80, &event, 1);
    func_802B7400_de(arg0->owner, arg0->id << 2);
    return 1;
  }
  if (completed || arg0->id)
  {
    return 0;
  }
  else
  {
    return 0;
  }
}
