#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804453C4.h"
#include "types.h"
#include "stddef.h"
/* Append one selected character to an eight-character entry buffer. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern char D_80145040;
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
extern struct LocalizedInputState D_80145040;
#endif
extern EntryRecAtCV2 D_800E63C0[];
extern s32 func_8022A5A0_de(void *,s32);
s32 func_80445AB4_de(ObjRecAt14V2 *arg0, MenuRules *arg1) {
 s32 value; s32 count; s32 index=func_8022A5A0_de(&D_80145040,arg1->locked);
 D_800E63C0[index].timer=0;
 if(D_800E63C0[index].count == 8) return 0;
 {
 D_800E63C0[index].text[D_800E63C0[index].value]=
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
     **arg0->unk14;
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
     *arg0->unk14[D_80145040.language];
#endif
 value=D_800E63C0[index].value+1;
 count=D_800E63C0[index].count+1;
 D_800E63C0[index].value=value;
 D_800E63C0[index].count=count;
 D_800E63C0[index].text[count]=0;
 }
 return 0;
}
