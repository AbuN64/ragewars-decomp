#include "span_16E000/code_8042F988.h"
#include "types.h"

/* Runs the block D_800E54A4 points to on event 1: in phase 3 at 0x4C it counts each player's timer
   at 0x14 of its 2920-byte record at 0x58 down and, when one expires, marks it -1 and resets that
   player through func_80404E28_de and func_80433610_de between func_802A2394_de and func_802A2360_de; then it
   advances the menu at 0x8 with func_8043C080_de and func_8043C2A4_de while func_8043C308_de reports 1, and
   once it reports 2 in phase 5 at 0x54 calls func_8029973C_de and moves on through func_8042CFDC_de,
   func_8042D034_de or func_804389F0_de as the cartridge's jump table jtbl_800E1BB0 chooses for option
   byte D_801462D5 up to 4. Returns zero. */





extern struct Block_func_8042F7A8_de *D_800E54A4;
extern u8 D_801462D5;
extern void func_802A2394_de();
extern void func_802A2360_de();
extern void func_80404E28_de(s32);
extern void func_80433610_de(s32);
extern s32 func_8043C308_de(void *);
extern void func_8043C080_de(void *);
extern void func_8043C2A4_de(void *);
extern void func_8029973C_de();
extern void func_8042CFDC_de();
extern void func_8042D034_de();
extern void func_804389F0_de();

s32 func_8042F7A8_de(void *arg0, void *arg1, s32 event) {
    s32 i;
    u32 option;

    if (event != 1) {
        return 0;
    }
    if (D_800E54A4->phase4C == 3) {
        for (i = 0; i < 4; i++) {
            if (D_800E54A4->players[i].timer > 0 && --D_800E54A4->players[i].timer == 0) {
                D_800E54A4->players[i].timer = -1;
                func_802A2394_de();
                func_80404E28_de(i);
                func_80433610_de(i);
                func_802A2360_de();
            }
        }
    }
    if (func_8043C308_de(D_800E54A4->menu) != 1) {
        return 0;
    }
    func_8043C080_de(D_800E54A4->menu);
    func_8043C2A4_de(D_800E54A4->menu);
    if (func_8043C308_de(D_800E54A4->menu) != 2) {
        return 0;
    }
    if (D_800E54A4->phase54 != 5) {
        return 0;
    }
    func_8029973C_de();
    option = D_801462D5;
    if (option >= 5) {
        goto done;
    }
    switch (option) {
        case 0: goto option_a;
        case 1: goto option_c;
        case 2: goto option_b;
        case 3: goto option_c;
        case 4: goto option_c;
        }
option_a:
    func_8042CFDC_de();
    return 0;
option_b:
    func_8042D034_de();
    return 0;
option_c:
    func_804389F0_de();
done:
    return 0;
}
