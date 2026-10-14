#include "span_1000/code_80225D10.h"
#include "types.h"
/* Checks accumulated opponent scores and updates the completion flag. */




extern State D_801468A0;
extern int func_8022A5A0_de(Root *,ObjRecAt16E0V1 *);
s32 func_802281F0_de(Root *root) {
 State *initial=&D_801468A0; State *state;
 ObjRecAt16E0V1 *node; int i,sum,skip; unsigned char *settings;
 if(initial->unk58==0) return 0;
 node=root->unk20; state=initial;
 if(node) { settings=(unsigned char *)state-0x5D8; }
 for(;node;node=node->unk16E0) {
  skip=func_8022A5A0_de(root,node);
  sum=0;
  for(i=0;i<8;i++) {
   if(i!=skip) {
    sum+=node->unk5D8->score[i];
    if(sum>=state->unk58) {
     { unsigned char trialKind=settings[0xD]; if(trialKind) {
      if(node->unk5D4<4) {state->humanWon=1;return 1;}
      state->humanWon=0;
      if(trialKind==1) continue;
     }
     } return 1;
    }
   }
  }
 }
 return 0;
}
