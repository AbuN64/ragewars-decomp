#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804366C4.h"
#include "types.h"
/* Builds a three-item menu: allocates 0x14 bytes into D_800E5784 through func_8025305C_de, creates the
   title 0x3CC/0x3CD through func_8041A280_de and the button 0x3CF through func_80419E54_de with 0x6E,
   finds entry 0x3CE of the list through func_8040EC30_de and sets its byte at 0x10 to 0xF, and stores
   the three with 3 and -1 in the block. Returns zero. */
extern struct Menu_func_80437718_de *D_800E5784;
extern struct Menu_func_80437718_de *func_8025305C_de(s32);
extern void *func_8041A280_de(s32, s32);
extern void *func_80419E54_de(s32, s32);
extern struct Resource_func_80419E54_de *func_8040EC30_de(void *, s32);
s32 func_80437718_de(void *list) {
    struct Resource_func_80419E54_de *item;
    D_800E5784 = func_8025305C_de(0x14);
#if defined(VERSION_DE)
    D_800E5784->title = func_8041A280_de(0x3C6, 0x3C6 + 1);
    D_800E5784->button = func_80419E54_de(0x3C6 + 3, 0x6E);
    item = func_8040EC30_de(list, 0x3C6 + 2);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    D_800E5784->title = func_8041A280_de(0x3CC, 0x3CC + 1);
    D_800E5784->button = func_80419E54_de(0x3CC + 3, 0x6E);
    item = func_8040EC30_de(list, 0x3CC + 2);
#elif defined(VERSION_EU_X)
    D_800E5784->title = func_8041A280_de(0x3D0, 0x3D0 + 1);
    D_800E5784->button = func_80419E54_de(0x3D0 + 3, 0x6E);
    item = func_8040EC30_de(list, 0x3D0 + 2);
#endif
    D_800E5784->item = item;
    item->value = 0xF;
    D_800E5784->count = 3;
    D_800E5784->selection = -1;
    return 0;
}
