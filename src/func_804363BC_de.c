#include "span_16E000/code_80435CE4.h"
#include "types.h"

/* Handles the menu message func_80299A08_de reports after func_8029973C_de: 0x3D8 clears D_80146894, calls func_802A2394_de, then calls func_8043C278_de on D_800E5558 when func_8042ACD8_de reports non-zero or else func_8040C428_de with zero and func_80298368_de with 0x14; 0x3D9 calls func_80298368_de with one. Returns zero.
   Adapted from func_80435CD8_de with the message numbers and the arms changed. */
extern s32 D_80146894;
extern s32 D_800E5558;
extern void func_8029973C_de(void);
extern s32 func_80299A08_de(void);
extern void func_802A2394_de(void);
extern s32 func_8042ACD8_de(void);
extern void func_8040C428_de(s32);
extern void func_8043C278_de(s32);
extern void func_80298368_de(s32);

#if defined(VERSION_DE)
enum { MENU_8043659C_984 = 978, MENU_8043659C_985 = 979 };
#elif defined(VERSION_EU_X)
enum { MENU_8043659C_984 = 988, MENU_8043659C_985 = 989 };
#else
enum { MENU_8043659C_984 = 984, MENU_8043659C_985 = 985 };
#endif

s32 func_804363BC_de(void) {
    func_8029973C_de();
    switch (func_80299A08_de()) {
    case MENU_8043659C_985:
        func_80298368_de(1);
        return 0;
    case MENU_8043659C_984:
        D_80146894 = 0;
        func_802A2394_de();
        if (func_8042ACD8_de() == 0) {
            func_8040C428_de(0);
            func_80298368_de(0x14);
        } else {
            func_8043C278_de(D_800E5558);
        }
        return 0;
    }
    return 0;
}
