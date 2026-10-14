#include "span_16E000/code_80429C10.h"
/* Resets the selection screen: maps the menu mode at 0x434 to a category (0 to 2, 1 to 3, 2 to 1,
   otherwise 0), builds the category list through func_8042B1B8_de, hides the forty controls of the
   table D_800E4F64 (and each entry's optional second control), refreshes the list, hides five fixed
   widgets and restores the selection, starting from the first entry when nothing was selected. */




extern Menu_func_8042AAD0_de *D_800E4F60;
extern Control D_800E4F64[];
extern void *func_8040EC30_de(void *, int);
extern void func_8040E8D8_de(void *, int);
extern int func_8042B1B8_de(int, int);
extern void func_8042E9A0_de(int, int);
extern void func_8042E988_de(int);

extern void func_8042AFC0_de(int);
extern void func_8042AFD0_de(int);
extern void func_8042ACD8_de(void);

static inline int map_category(int mode) {
    int category;

    switch (mode) {
        case 3:
            category = 0;
            break;
        case 2:
            category = 1;
            break;
        case 1:
            category = 3;
            break;
        case 0:
            category = 2;
            break;
        default:
            return 0;
    }
    return category;
}
void func_8042AAD0_de(void) {
    int category;
    int list;
    int i;

    category = map_category(D_800E4F60->mode);
    list = func_8042B1B8_de(category, D_800E4F60->selection);
    for (i = 0; i < 40; i++) {
        func_8040E8D8_de(func_8040EC30_de(D_800E4F60->screen, D_800E4F64[i].first), 0);
        if (D_800E4F64[i].second != -1) {
            func_8040E8D8_de(func_8040EC30_de(D_800E4F60->screen, (unsigned short)D_800E4F64[i].second), 0);
        }
    }
    func_8042E9A0_de(category, list);
    func_8042E988_de(0x15);
    func_8040E8D8_de(D_800E4F60->widgetC, 0);
    func_8040E8D8_de(D_800E4F60->widgetE, 0);
    func_8040E8D8_de(D_800E4F60->widgetD, 0);
    func_8040E8D8_de(D_800E4F60->widgetA, 0);
    func_8040E8D8_de(D_800E4F60->widgetB, 0);
    func_8042B350_de();
    if (D_800E4F60->selection == 0) {
        func_8042AFC0_de(category);
        func_8042AFD0_de(0);
        func_8042ACD8_de();
    } else {
        func_8042AFC0_de(-1);
        func_8042AFD0_de(D_800E4F60->selection);
    }
}
