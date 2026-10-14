#include "span_16E000/code_8042F988.h"
#include "types.h"

/* Copies the records player p owns into p's block record: for each of the four 400-byte records of
   D_80102B00 whose byte 0xE is clear and whose owner byte 0xD is p, when the matching 150-byte
   status record at 0xD0 of D_801462C8 has byte 0x78 equal to one and byte 0x91 clear, copies the whole record
   through func_802A0724_de into slot [byte 0xC] of the 400-byte slots at 0x18 of p's 2920-byte
   record at 0x58 of the block D_800E54A4 points to. */





extern struct Block_func_80434B08_de *D_800E54A4;
extern u8 D_80102B00[];
extern s8 D_800FEB0C[];
extern s8 D_80102B0D[];
extern s8 D_800FEB0E[];




extern struct MatchSetupGlobals D_801462C8;
extern void func_802A0724_de(void *, void *, s32);

void func_80434B08_de(s32 player) {
    struct MatchSetupGlobals *globals;
    s32 i;
    s32 size;

    size = 400;
    globals = &D_801462C8;
    for (i = 0; i < 4; i++) {
        if (D_800FEB0E[i * 400] == 0 && D_80102B0D[i * 400] == player &&
            globals->status[i].active == 1 && globals->status[i].out == 0) {
            func_802A0724_de(D_800E54A4->players[player].slots[D_800FEB0C[i * 400]],
                          &D_80102B00[i * 400], size);
        }
    }
}
