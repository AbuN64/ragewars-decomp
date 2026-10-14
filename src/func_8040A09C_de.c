#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"
/* Picks the pak menu prompt text: in pak mode, when a prompt is due, the text for the channel (D_800E28C8 when D_8015375C is set, else the widget's channel) from four channel texts; otherwise one of two texts in the other mode, or a third text when D_8015375C alone is set, and 0 when none applies. */





extern char D_0044E4F8[];
extern char D_0044FB50[];
extern char D_0044FFA4[];
extern char D_00450BF0_de[];
extern char D_00450C14_de[];
extern char D_00450C38_de[];
extern char D_00450C5C_de[];
extern s32 D_8014D4C0_de;
extern s32 D_8015375C;
extern s32 D_80153760;
extern s32 D_8014D4EC_de;
extern s32 D_800E28C8;

char *func_8040A09C_de(struct Record_func_80409BDC_de *menu) {
    s32 channel[2]; /* FAKEMATCH: unused second slot keeps channel in the frame */
    char *text;
    char *prompt; /* FAKEMATCH: copy-only local routes the switch result through its own register before text */

    text = 0;
    if (D_8014D4C0_de != 0) {
        if (D_8014D4EC_de == 0) {
            return text;
        }
        if (D_8015375C != 0) {
            channel[0] = D_800E28C8;
        } else {
            channel[0] = menu->inner->unk4;
        }
        switch (channel[0]) {
        case 0:
        default:
            prompt = D_00450BF0_de;
            break;
        case 1:
            prompt = D_00450C14_de;
            break;
        case 2:
            prompt = D_00450C38_de;
            break;
        case 3:
            prompt = D_00450C5C_de;
            break;
        }
        text = prompt;
    } else if (D_80153760 != 0) {
        text = D_0044FFA4;
        if (D_8014D4EC_de != 0) {
            text = D_0044FB50;
        }
    } else if (D_8015375C != 0) {
        text = D_0044E4F8;
    }
    return text;
}
