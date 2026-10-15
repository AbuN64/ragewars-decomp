#include "span_16E000/code_8042F988.h"
#include "types.h"

/* Handles a cancel event for the player the low half of the third argument names: calls
   func_8029973C_de and, when the block D_800E54A4 points to is in phase 7 at 0x54, returns to screen 3
   through func_8043577C_de; otherwise by the player's state at the start of its 2920-byte record at
   0x58: in state 0 it leaves for screen 0x1B unless func_804355B4_de reports something pending, in
   state 0xC it blanks the character at the cursor of the name at 0xB34 of the record, and in
   states 0x16 and 0x1B it closes the keyboard through func_80433BCC_de or func_80433D38_de with -1,
   returns the player to state 0xD and redraws through func_804322AC_de. Returns zero. Written from
   the assembly with the player index as an unsigned short parameter. */







extern struct Block_func_80432158_de *D_800E54A4;
extern void func_8029973C_de();
extern void func_8043577C_de(s32);
extern s32 func_804355B4_de();
extern void func_80433BCC_de(s32);
extern void func_80433D38_de(s32);
extern void func_804322AC_de(s32);

s32 func_80432158_de(void *arg0, void *arg1, u16 player) {
    func_8029973C_de();
    if (D_800E54A4->phase == 7) {
        func_8043577C_de(3);
        return 0;
    }
    switch (D_800E54A4->players[player].state) {
    case 0:
        if (func_804355B4_de() > 0) {
            return 0;
        }
        func_8029973C_de();
        func_8043577C_de(0x1B);
        return 0;
    case 0xC:
        func_8029973C_de();
        D_800E54A4->players[player].name[D_800E54A4->players[player].cursor].c = ' ';
        break;
    case 0x16:
        func_8029973C_de();
        func_80433BCC_de(-1);
        D_800E54A4->players[player].state = 0xD;
        func_804322AC_de(player);
        break;
    case 0x1B:
        func_8029973C_de();
        func_80433D38_de(-1);
        D_800E54A4->players[player].state = 0xD;
        func_804322AC_de(player);
        break;
    default:
        return 0;
    }
    return 0;
}
