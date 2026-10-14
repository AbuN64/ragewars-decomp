#include "span_16E000/code_804264F0.h"
/* Finds a menu item identifier in three selection tables, falling back to the first item of the second table. */
extern int D_800E1AFC_de[],D_800E5B44[],D_800E1B7C[],D_800E5BC4[],D_800E1ACC_de[],D_800E5B14[];
int func_8042863C_de(int id) {
 int i;
 for(i=0;i<8;i++) if(D_800E1AFC_de[i*4]==id) return D_800E5B44[i*4];
 for(i=0;i<4;i++) if(D_800E1B7C[i*4]==id) return D_800E5BC4[i*4];
 for(i=0;i<3;i++) if(D_800E1ACC_de[i*4]==id) return D_800E5B14[i*4];
 return D_800E5BC4[0];
}
