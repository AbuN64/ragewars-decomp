#include "types.h"
#include "n64sdk.h"
typedef struct { void *destination; s32 command,unused; u32 address; s32 channel; u32 count; s32 zero; void *reply; } DraftRequest;
extern s32 D_800C8144_de;
extern u8 D_800F2F40[], D_800F3110[];
extern void func_802BB420_de(void *, void *, s32);
extern void func_802BB2A0_de(void *, s32 *, s32);
extern s32 func_80200500_de(void);
extern void func_80200538_de(s32);
extern s32 func_802017E8_de(s32,s32,u32,s32);
extern void func_80200880_de(u32,void *,s32);
s32 func_80201E94_de(s32 channel, u8 *destination, u32 remaining) {
 DraftRequest request;
 s32 received[2]; s32 total=0, saved; u32 chunk;
 if (D_800C8144_de == 2) {
  while (remaining != 0) {
   chunk=remaining; if (chunk>0x8000) chunk=0x8000;
   request.destination=destination; request.command=1; request.unused=0;
   request.address=0x80000505; request.channel=channel; request.count=chunk;
   request.zero=0; request.reply=D_800F3110;
   func_802BB420_de(D_800F2F40,&request,1);
   func_802BB2A0_de(D_800F3110,received,1);
   if (received[0]==0) return total;
   destination+=received[0]; total+=received[0]; remaining-=received[0];
  }
 } else {
  saved=func_80200500_de();
  while (remaining != 0) {
   chunk=remaining; if (chunk>0x8000) chunk=0x8000;
   received[0]=func_802017E8_de(0x505,channel,chunk,0);
   if (received[0]==0) break;
   func_80200880_de(0xb1ff0000,destination,received[0]);
   destination+=received[0]; total+=received[0]; remaining-=received[0];
  }
  func_80200538_de(saved);
 }
 return total;
}
