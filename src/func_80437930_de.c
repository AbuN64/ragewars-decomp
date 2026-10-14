#include "span_16E000/code_804379C8.h"
#include "types.h"




/* Calls func_8029973C_de; when func_80299A08_de reports 0x3D0 it sets the word at 0x10 of the menu block
   D_800E5784 points to to 7 and clears five bytes at D_80102B7E through func_802A001C_de, for 0x3D1 it
   sets that word to -1; then it calls func_8041A430_de on the block's first word with 2. Returns
   zero. */
extern MenuSelectionMessage *D_800E5784;
extern char D_80102B7E[];
extern void func_8029973C_de();
extern s32 func_80299A08_de();
extern void func_802A001C_de(void *, s32, s32);
extern void func_8041A430_de(void *, s32);

#if defined(VERSION_DE)
enum { MENU_80437B10_976 = 970, MENU_80437B10_977 = 971 };
#elif defined(VERSION_EU_X)
enum { MENU_80437B10_976 = 980, MENU_80437B10_977 = 981 };
#else
enum { MENU_80437B10_976 = 976, MENU_80437B10_977 = 977 };
#endif

s32 func_80437930_de(void) {
    s32 choice;

    func_8029973C_de();
    choice = func_80299A08_de();
    switch (choice) {
    case MENU_80437B10_977:
        D_800E5784->value = -1;
        break;
    case MENU_80437B10_976:
        D_800E5784->value = 7;
        func_802A001C_de(D_80102B7E, 0, 5);
        break;
    }
    func_8041A430_de(D_800E5784->first, 2);
    return 0;
}

