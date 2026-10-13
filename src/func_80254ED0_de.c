#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80254CE4.h"
#include "types.h"
#include "stddef.h"
/* Obtains a free node, marks it active and moves it to the active list, retrying while processing permits. */
extern func_8022BC04_S3 *D_801010F8;
extern char D_8010110C;

extern void func_80255CB8_de(void *,func_8022BC04_S3 *);
extern void func_80255ED8_de(func_8022BC04_S3 **,func_8022BC04_S3 *);
static inline func_8022BC04_S3 *take(s32 active) {
 func_8022BC04_S3 *node=D_801010F8;
 if(node) {func_80255ED8_de(&D_801010F8,node); node->unk10=active;func_80255CB8_de(&D_8010110C,node);}
 return node;
}
void *func_80254ED0_de(s32 unused,s32 flags) {
 func_8022BC04_S3 *node=take(1);
 if (!node) {
  s32 active=1;
  flags &= 0x10;
  while(func_80251328_de(0,2,flags==0)) {node=take(active);if(node)break;}
 }
 return node;
}
