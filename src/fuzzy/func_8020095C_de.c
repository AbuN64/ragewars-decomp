#include "types.h"
#include "n64sdk.h"
extern s32 D_800C8140_de;
extern u8 D_800F2CE0[],D_800F2CC0[];
extern u8 func_80200840_de(u32);

extern s32 func_802B8CF0_de(void *,s32,s32,u32,void *,u32,void *);
extern void func_802BB2A0_de(void *,void *,s32);
void func_8020095C_de(u32 address,u8 *out,u32 count) {
 s32 status = -(D_800C8140_de == 0); u32 word;
 while(count!=0 && (address&3)!=0) { *out++=func_80200840_de(address++); count--; }
 while(count>3) {
  if(count>=16 && ((((u32)out&15)==0) & (status!=-1))) {
   status=func_802B8CF0_de(D_800F2CE0,1,0,address,out,count,D_800F2CC0);
   if(status!=-1) { func_802BB2A0_de(D_800F2CC0,0,1); count=0; }
  } else {
   word=func_802005A0_de(address);
   *out++=word>>24; *out++=word>>16; *out++=word>>8; *out++=word;
   address+=4; count-=4;
  }
 }
 while(count!=0) { *out++=func_80200840_de(address++); count--; }
}
