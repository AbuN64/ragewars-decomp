#include "span_1000/code_80296014.h"
#include "types.h"
#include "math_helpers.h"
/* Tests a centered grid cell and interprets its sentinel value. */
extern int func_80263154_de(Board *,int);
static inline int offset(int v){return v+9;}
int func_80296390_de(Board*g,int x,int y,int z){int v; unsigned int adjusted;if(!(RW_ABS(x-g->originX)<9 && RW_ABS(y-g->originY)<9))return 0;v=g->cells[(x-g->originX)+8+((y-g->originY)+8)*17];if(v==-2)return 1;if(v==-3)return 0;adjusted=z+9;g->unk4=v+adjusted;return func_80263154_de(g,1)!=0;}
