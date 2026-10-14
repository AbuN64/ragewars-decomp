#include "span_16E000/code_80403BCC.h"
/* Looks up the current menu resource through func_8028FE3C_de from the fields at 0x74 and 0x34 of
   D_8011FE88 and, when found, opens it through func_8025193C_de as widget 0x33 with the handler table
   D_800E0B2C; returns the result, or 0 when there is no resource. Matched through a local pointer to the menu. */


extern Menu_func_80403BE0_de D_8011FE88;
extern int D_800E0B2C;
extern void *func_8028FE3C_de(int, int, int, int *);
extern int func_8025193C_de(int, void *, void *, int, int, int, int, int *, int);

int func_80403BE0_de(void) {
    int size;
    void *res;
    Menu_func_80403BE0_de *menu = &D_8011FE88;

    res = func_8028FE3C_de(menu->id, menu->group, 0, &size);
    if (res == 0) {
        return 0;
    }
    return func_8025193C_de(0, res, res, size, 0x33, 0, 0, &D_800E0B2C, 1);
}
