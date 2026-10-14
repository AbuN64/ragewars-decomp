#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043E9A8.h"
#include "types.h"

extern void func_80264788_de(s32 arg0);

extern s32 D_8011FAC0;
extern s32 D_80154048;





/** Clears the D_8011FAC0 record and D_80154048, then re-registers the target through func_80264788_de. */
s32 func_8043EA4C_de(void *arg0, Outer8043E56C *arg1) {
    func_80293824_de(&D_8011FAC0, 8);
    D_80154048 = 0;
    func_80264788_de(arg1->unk20->unk4);
    return 1;
}
