#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"
/* Restarts a round for the player passed in arg1: clears the world timer flag D_800E28C0 via
   func_804097E8_de, cancels the active countdown sound through func_8025E214_de, then reallocates a
   fresh scoreboard entry via func_80442574_de using arg1's fields at 0x1C and 0x20, and always
   reports success. */

extern s32 D_8014561C;
extern s32 D_0044E468;

void func_804097E8_de(void);

void *func_80442574_de(void *owner, void *list, s32 b, s32 c, s32 d);



s32 func_8043E568_de(void *arg0, Arg1Struct *arg1) {
    s32 val1C;

    val1C = arg1->unk1C;
    func_804097E8_de();
    ((s32 (*)(s32))func_8025E214_de)(-1);
    func_80442574_de(&D_8014561C, &D_0044E468, val1C, arg1->unk20, 0);
    return 1;
}
