#include "types.h"
#include "n64sdk.h"
typedef struct { s32 kind,start,length,offset; void *table; } DraftBlock;
typedef struct { char pad[0x18]; u16 header[16]; char gap[0x80]; u16 output[256]; } DraftStream;
extern DraftBlock D_800D5564[];
extern s16 D_800D54BE;
extern u16 D_8014AE10[16];
extern u16 func_802BEDB0_de(u16 *,u16,s32,s32,void *);
extern s32 func_802BEF84_de(DraftBlock *,u16 *,s16,s16 *,void *);
s32 func_802BF388_de(DraftStream *stream) {
 DraftBlock *block = D_800D5564;
 s16 done[4]; s32 i;
 if (D_800D54BE == 0) {
  D_800D54BE = 1;
  if ((s16)func_802BEDB0_de(stream->header,6,16,0,stream) <= 0) return -1;
  block->offset += 0x60;
  for (i=0;(s16)i<16;i++) D_8014AE10[(s16)i] = stream->header[(s16)i];
  while (block->kind != 0) block++;
 } else {
  if ((s16)func_802BEF84_de(D_800D5564,stream->header,16,done,stream) != 16) return -1;
  block = &D_800D5564[done[0]];
  for (i=0;(s16)i<16;i++) {
   u16 value = stream->header[(s16)i] + D_8014AE10[(s16)i];
   stream->header[(s16)i] = value;
   D_8014AE10[(s16)i] = value;
  }
 }
 if ((s16)func_802BEF84_de(block,stream->output,256,done,stream) != 256) return -1;
 return 1;
}
