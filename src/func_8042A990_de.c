#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80429C10.h"
#include "types.h"
/* Refreshes the selection on the screen D_800E4F60: for category 0 to 3 at 0x434 it takes the item
   the selection at 0x438 names in the 4-byte table D_800E5240, D_800E5214, D_800E51F8 or
   D_800E51E4 from the window into 0x43C, copies the selection's name into the text at 0x3F4 (the
   default label for selection 0, otherwise the resource name func_8028D380_de reads from
   D_8011FE88 for the entry func_8042B1B8_de finds in the category's list func_8042B294_de), points the
   label at 0x3EC to that text and calls func_80245B28_de. */
extern struct Screen_func_8042A990_de *D_800E4F60;
extern struct StateFlags D_800E51E4[];
extern struct StateFlags D_800E51F8[];
extern struct StateFlags D_800E5214[];
extern struct StateFlags D_800E5240[];
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern char *D_800D34D4_de[];
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern char *D_800E1DA4[];
#endif

extern void *func_8040EC30_de(void *, s32);
extern void *func_8042B294_de(s32);
extern s32 func_8042B1B8_de(void *, s32);
extern void func_8028D380_de(char *, s32, char *, s32);
extern char *func_802A0494_de(char *);
extern void func_802A025C_de(char *, char *);
extern void func_80245B28_de();
void func_8042A990_de(void) {
    struct StateFlags *table;
    char buffer[0x40];
    switch (D_800E4F60->category) {
    case 3:
        table = D_800E51E4;
        break;
    case 2:
        table = D_800E51F8;
        break;
    case 1:
        table = D_800E5214;
        break;
    case 0:
        table = D_800E5240;
        break;
    default:
        return;
    }
    D_800E4F60->item = func_8040EC30_de(D_800E4F60->window, table[D_800E4F60->selection].flags);
    if (D_800E4F60->selection == 0) {
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        func_802A025C_de(D_800E4F60->text, D_800D34D4_de[0]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        func_802A025C_de(D_800E4F60->text, D_800E1DA4[D_80152789]);
#endif
    } else {
        func_8028D380_de(&D_8011FE88,
                      func_8042B1B8_de(func_8042B294_de(D_800E4F60->category), D_800E4F60->selection),
                      buffer, 0x3F);
        func_802A025C_de(D_800E4F60->text, func_802A0494_de(buffer));
    }
    D_800E4F60->label->text = D_800E4F60->text;
    func_80245B28_de();
}
