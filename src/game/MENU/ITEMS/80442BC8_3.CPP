#include "COMMON/PARTICLE_LIGHTING.H"
#include "MENU/OBJECT1C8.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"

/* Writes a numeric menu value through its bound storage callback using the selected scalar type. */

void func_80442FB0_de(ItemRecAt14 *item,float value) {
 float *storage;
 struct Binding *binding;
 unsigned int *word;
 binding=item->binding;
 storage=binding->storage();

 switch(binding->type) {
 case 0:*(float *)storage=value;return;
 case 3:*(signed char *)storage=(int)value;return;
 case 4:*(short *)storage=(int)value;return;
 case 1:case 2:case 5:*(int *)storage=(int)value;return;
 case 6:*(unsigned char *)storage=(unsigned int)value;return;
 case 7:*(unsigned short *)storage=(unsigned int)value;return;
 case 8:word=(unsigned int *)storage;*word=(unsigned int)value;return;
 }
}

/* Calls func_8024B990_de with its three arguments and the table D_800D0EF8 as the fourth. */
extern void func_8024B990_de(void *, void *, void *, void *);

void func_80443104_de(void *first, void *second, void *third) {
    func_8024B990_de(first, second, third, &D_800D0EF8);
}
