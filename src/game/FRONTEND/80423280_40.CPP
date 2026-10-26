#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "TYPES.H"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "FRONTEND/80423280_40.H"
#include "ACHIEVE/80424E30_3.H"

/* Grants unowned unlocks for the completed game using its mode and player kind; an unsigned local carries the globals address before the category value to preserve register scheduling, and the default kind calls the table selector directly. */









extern struct Data801462C8 D_801462C8;
extern s8 D_80142358[]; /* MIXED: this unit views D_801462C8 as Data801462C8 */
extern struct Screen_func_80427D70_de *D_800E4690;
extern s32 Defs_TestBit(u8 *, s32);
extern void Defs_SetBitValue(u8 *, s32, s32);

void func_80427D70_de(void *arg0) {
    struct Data801462C8 *globals;
    struct Table_func_80427D70_de *table;
    unsigned int category;
    s32 kind;
    s32 value;
    s32 i;

    category=(unsigned int)&D_801462C8;
    globals=(struct Data801462C8 *)category;
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
        
        if (Defs_TestBit(D_800E4690->owned, value-1) == 0) {
            Defs_SetBitValue(D_800E4690->unlocked, value-1, 1);
        }
    }
    for (i = 0; i < 3; i++) {
        if ((value = table->items[i]) > 0) {
            
            if (Defs_TestBit(D_800E4690->owned, value-1) == 0) {
                Defs_SetBitValue(D_800E4690->unlocked, value-1, 1);
            }
        }
    }
}
