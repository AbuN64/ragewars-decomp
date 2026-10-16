#include "span_16E000/code_8043A0A4.h"
#include "shared/func_80421E70_eu_closed.h"
/* Cancels a player's selection or schedules the menu transition according to the current selection state. */


extern FourPlayerResultsScreen *D_800E59E0;
extern void func_8041B7B4_de(void *, int, int);
extern void func_8041CE10_de(void *, int);
int func_8043BF28_de(int a,int b,unsigned int player) {
 func_8029973C_de();player &= 0xFFFF;
 switch(D_800E59E0->panels[player].state) {
 case 1:D_800E59E0->state=5;D_800E59E0->timer=4;D_800E59E0->next=7;break;
 case 2:D_800E59E0->panels[player].state=0;func_8041B7B4_de(D_800E59E0->menu,player,0);func_8041CE10_de(D_800E59E0->panels[player].pad0,1);func_8043B0CC_de(player);break;
 }
 return 0;
}
