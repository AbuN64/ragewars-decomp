#include "span_16E000/code_8042BD40.h"
#include "types.h"
/* Activates the requested player slots and creates any missing players when entering the screen. */





extern Screen_func_8042DC04_de *D_800E5430;
extern SlotRecAt7F D_80146398[];
extern s8 D_80102B0D[];
extern void func_8029973C_de(void);
extern void func_8041A430_de(int, int);


int func_8042DC04_de(void) {
    int i;
    SlotRecAt7F *slot;

    func_8029973C_de();
    D_800E5430->state = 7;
    func_8041A430_de(D_800E5430->window, 2);
    for (i = 0; i < D_800E5430->count; i++) {
        slot = &D_80146398[i];
        slot->active = 1;
        slot->index = i;
        if (D_80102B0D[i * 400] < 0) {
            func_8022F204_de(i);
        }
    }
    return 0;
}
