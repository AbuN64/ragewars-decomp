#include "span_1000/code_80256220.h"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "shared/func_802B80B4_eu_closed.h"
#include "span_1000/code_8025D948.h"
#include "span_1000/code_8025E280.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_802B7058.h"
#include "span_1000/code_802BB15C.h"
#include "span_1000/code_802BD1A8.h"
#include "types.h"
#include "libasm_802BD1A8.h"

extern u32 D_800CB700_de;

extern u32 D_800CB710;

extern s32 D_002571F0;

extern s32 D_80107928;

extern s32 D_80107DF0;

extern void *D_80107E20[];

extern char D_80107E80;

extern u16 D_80107E9A;

extern char D_80142928;

extern void func_80256FC0_de(Work56EC8 *arg0);

extern s32 func_802BBBC0_de(s32);

extern void *func_802B3A44_de(void *arg0, s32 *arg1, s32 arg2, s16 arg3);

extern void func_8028FD4C_de(void *arg0, void *arg1);

extern void func_802B7400_de(void *arg0, s32 arg1);

void func_80256C90_de(void) {
    u32 stop, argument, frame;
    u64 previous;
    u32 messages[2];
    union { void *message; u32 words[2]; } event;
    CacheCountdownEntry *entry;
    void *entryObject;
    stop = 0;
    argument = stop;
    frame = stop;
    previous = 0;
    osScAddClient(&D_80142928, messages, (s32)D_80107E00);
    do {
        D_800CB710 = ((func_802BADC0_de() - previous) << 6) / 3000ULL;
        func_802BB2A0_de((void *)D_80107E00, &event.message, 1);
        previous = func_802BADC0_de();
        switch (event.words[0]) {
        case 1:
            frame++;
            if (frame < 21) break;
            frame = 0;
        case 7:
            D_800CB70C_de++;
            while (!(func_802B72C0_de() & 0x80000000)) {
                func_80256EA8_de(D_80107E28[D_800CB700_de % 3], argument);
            }
            entryObject = D_80107DFC;
            for (entry = entryObject; entry; entry = entry->next) {
                if (entry->state) entry->state--;
            }
            break;
        case 4:
            break;
        }
    } while (stop == 0);
    func_802B24D0_de(D_80107E34);
}

s32 *func_80256E6C_de(s32 **arg0) {
    if ((((struct ObjectLinksC *) ((s8 *) (&D_80107DF0)))->unk_0) == 0) {
        (((struct ObjectLinksC *) ((s8 *) (&D_80107DF0)))->unk_8) = &D_80107928;
        (((struct ObjectLinksC *) ((s8 *) (&D_80107DF0)))->unk_4) = 0;
        (((struct ObjectLinksC *) ((s8 *) (&D_80107DF0)))->unk_0) = 1U;
    }
    *arg0 = &D_80107DF0;
    return &D_002571F0;
}

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
    osWritebackDCacheAll();
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
