#include "span_16E000/code_804264F0.h"
#include "types.h"

/* Grants unowned unlocks for the completed game using its mode and player kind; an unsigned local carries the globals address before the category value to preserve register scheduling, and the default kind calls the table selector directly. */









extern struct Globals_func_80427D70_de D_801462C8;
extern struct Screen_func_80427D70_de *D_800E4690;
extern s8 D_80142358[];
extern struct Table_func_80427D70_de *func_80425C70_de(void *, s32, s32);
extern s32 func_80265650_de(u8 *, s32);
extern void func_80265688_de(u8 *, s32, s32);

void func_80427D70_de(void *arg0) {
    struct Globals_func_80427D70_de *globals;
    struct Table_func_80427D70_de *table;
    unsigned int category;
    s32 kind;
    s32 value;
    s32 i;

    category=(unsigned int)&D_801462C8;
    globals=(struct Globals_func_80427D70_de *)category;
    switch (globals->mode) {
    case 1:
        kind = globals->status[D_800E4690->player].kind;
        category = 0;
        break;
    case 2:
        category = 1;
        kind = 0;
        break;
    case 3:
        category = 3;
        kind = 0;
        break;
    case 4:
        category = 2;
        kind = 0;
        break;
    default:
        kind = D_80142358[D_800E4690->player * 150];
        table = func_80425C70_de(arg0,0,kind);
        goto selected;
        break;
    }
    table = func_80425C70_de(arg0, category, kind);
selected:
    if ((value = table->first) > 0) {
        
        if (func_80265650_de(D_800E4690->owned, value-1) == 0) {
            func_80265688_de(D_800E4690->unlocked, value-1, 1);
        }
    }
    for (i = 0; i < 3; i++) {
        if ((value = table->items[i]) > 0) {
            
            if (func_80265650_de(D_800E4690->owned, value-1) == 0) {
                func_80265688_de(D_800E4690->unlocked, value-1, 1);
            }
        }
    }
}
