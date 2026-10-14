#include "span_16E000/code_804251F4.h"
#include "types.h"

/* Applies event *D_800E4680 to player record D_80102B00[index] once per D_8015402C: when that bit
   of the record's current slot flags is already set it returns -1; otherwise it sets the bit and,
   for an event code below 58, dispatches through jtbl_800E1790 to the effect for that code and
   returns the code plus 5000 (5001 when the second effect's test clears bit 0), or -1 for a code
   the table marks unknown. The dispatch and return sit in a one-pass loop; that weighting gives
   the result its saved register ahead of the key pointer, as the cartridge has it. */


extern struct Player_func_80425014_de D_80102B00[];
extern s32 D_8015402C;
extern u8 *D_800E4680;
extern s32 func_80265650_de(u8 *, s32);
extern void func_80265688_de(u8 *, s32, s32);
extern void func_8022F3F8_de(struct Player_func_80425014_de *, s32);
extern s32 func_8022F454_de(struct Player_func_80425014_de *, s32);
extern void func_8022F4BC_de(struct Player_func_80425014_de *, s32);
extern void func_8022F514_de(struct Player_func_80425014_de *, s32);
extern void func_8022F31C_de(struct Player_func_80425014_de *);
extern void func_8022F340_de(struct Player_func_80425014_de *);
extern void func_8022F364_de(struct Player_func_80425014_de *);
extern void func_8022F388_de(struct Player_func_80425014_de *);

s32 func_80425014_de(s32 index) {
    s32 result = -1;
    struct Player_func_80425014_de *player = &D_80102B00[index];
    s32 *key = &D_8015402C;
    u32 code;

    if (func_80265650_de(player->flags[player->slot], *key) != 0) {
        goto done;
    }
    func_80265688_de(player->flags[player->slot], *key, 1);
    code = *D_800E4680;
    result = code + 5000;
    do {
        if (code >= 58) {
            goto unknown;
        }
        switch (code) {
        case 0: goto unknown;
        case 1: goto effect_0;
        case 2: goto effect_1;
        case 3: goto effect_2;
        case 4: goto effect_3;
        case 5: goto effect_4;
        case 6: goto effect_5;
        case 7: goto effect_6;
        case 8: goto effect_7;
        case 9: goto effect_8;
        case 10: goto effect_9;
        case 11: goto effect_10;
        case 12: goto effect_11;
        case 13: goto effect_12;
        case 14: goto effect_13;
        case 15: goto effect_14;
        case 16: goto effect_15;
        case 17: goto effect_16;
        case 18: goto effect_17;
        case 19: goto effect_18;
        case 20: goto effect_19;
        case 21: goto effect_20;
        case 22: goto effect_21;
        case 23: goto effect_22;
        case 24: goto effect_23;
        case 25: goto effect_24;
        case 26: goto effect_25;
        case 27: goto effect_26;
        case 28: goto effect_27;
        case 29: goto effect_28;
        case 30: goto effect_29;
        case 31: goto effect_30;
        case 32: goto unknown;
        case 33: goto effect_31;
        case 34: goto effect_32;
        case 35: goto unknown;
        case 36: goto unknown;
        case 37: goto effect_33;
        case 38: goto unknown;
        case 39: goto unknown;
        case 40: goto unknown;
        case 41: goto unknown;
        case 42: goto unknown;
        case 43: goto unknown;
        case 44: goto unknown;
        case 45: goto unknown;
        case 46: goto unknown;
        case 47: goto unknown;
        case 48: goto unknown;
        case 49: goto unknown;
        case 50: goto unknown;
        case 51: goto unknown;
        case 52: goto done;
        case 53: goto effect_34;
        case 54: goto unknown;
        case 55: goto unknown;
        case 56: goto unknown;
        case 57: goto effect_35;
        }
    effect_0:
        func_8022F3F8_de(player, player->slot);
        func_8022F3F8_de(player, player->slot);
        goto done;
    effect_1:
        func_8022F3F8_de(player, player->slot);
        if ((func_8022F454_de(player, player->slot) & 1) == 0) {
            result = 5001;
        }
        goto done;
    effect_2:
        func_8022F4BC_de(player, 4);
        goto done;
    effect_3:
        func_8022F514_de(player, 2);
        goto done;
    effect_4:
        func_8022F4BC_de(player, 14);
        goto done;
    effect_5:
        func_8022F514_de(player, 6);
        goto done;
    effect_6:
        func_8022F4BC_de(player, 7);
        goto done;
    effect_7:
        func_8022F514_de(player, 16);
        goto done;
    effect_8:
        func_8022F514_de(player, 5);
        goto done;
    effect_9:
        func_8022F514_de(player, 17);
        goto done;
    effect_10:
        func_8022F4BC_de(player, 6);
        goto done;
    effect_11:
        func_8022F514_de(player, 14);
        goto done;
    effect_12:
        func_8022F514_de(player, 4);
        goto done;
    effect_13:
        func_8022F4BC_de(player, 12);
        goto done;
    effect_14:
        func_8022F4BC_de(player, 10);
        goto done;
    effect_15:
        func_8022F31C_de(player);
        goto done;
    effect_16:
        func_8022F514_de(player, 8);
        goto done;
    effect_17:
        func_8022F4BC_de(player, 8);
        goto done;
    effect_18:
        func_8022F4BC_de(player, 15);
        goto done;
    effect_19:
        func_8022F514_de(player, 11);
        goto done;
    effect_20:
        func_8022F514_de(player, 10);
        goto done;
    effect_21:
        func_8022F514_de(player, 3);
        goto done;
    effect_22:
        func_8022F364_de(player);
        goto done;
    effect_23:
        func_8022F340_de(player);
        goto done;
    effect_24:
        func_8022F4BC_de(player, 13);
        goto done;
    effect_25:
        func_8022F4BC_de(player, 9);
        goto done;
    effect_26:
        func_8022F514_de(player, 1);
        goto done;
    effect_27:
        func_8022F514_de(player, 9);
        goto done;
    effect_28:
        func_8022F514_de(player, 7);
        goto done;
    effect_29:
        func_8022F514_de(player, 13);
        goto done;
    effect_30:
        func_8022F4BC_de(player, 5);
        goto done;
    effect_31:
        func_8022F4BC_de(player, 1);
        goto done;
    effect_32:
        func_8022F514_de(player, 0);
        goto done;
    effect_33:
        func_8022F4BC_de(player, 11);
        goto done;
    effect_34:
        player->count++;
        goto done;
    effect_35:
        func_8022F388_de(player);
        goto done;
    unknown:
        result = -1;
    done:
        return result;
    } while (0);
}
