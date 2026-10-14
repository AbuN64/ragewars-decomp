#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80297CD0.h"
#include "types.h"
#include "stddef.h"
/* Dispatches a pending menu event and clears its pending state. */
int func_80297310_de(int, int, s32, int, s32); /* extern */
int func_802995D4_de(s16, int, int, int, s32); /* extern */
int func_80299CC4_de(); /* extern */
extern State_func_80297EA4_de *D_8014D080;
int func_80297EA4_de(int arg0) {
 int index,event,result; ObjRecAtCV1 *item; int (*callback)(int,int,int,int);
 index=D_8014D080->unk4;
 if(index>=0 && D_8014D080->unk530) {
 item=D_8014D080->unkC[index].unk8;
 if(item) func_802995D4_de(item->unkC,0x10,0,0,0);
 event=arg0;
 func_80299CC4_de();
 if(D_8014D080->unk4 != -1) {
 callback=D_8014D080->unk0;
 if(callback) {
 arg0=D_8014D080->unk520;
 D_8014D080->unk520=0;
 callback(0xE03,event,0,0);
 result=D_8014D080->unk520;
 if(result==1) { D_8014D080->unk520=arg0; goto done; }
 D_8014D080->unk520=arg0;
 }
 func_80297310_de(1,0xE03,event,0,0);
 }
 done:
 D_8014D080->unk530=0;
 }
 return 1;
}
