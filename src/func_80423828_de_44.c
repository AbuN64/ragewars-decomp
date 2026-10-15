#include "span_16E000/code_80423280.h"
#include "common/types_1dc8418c21db.h"
#include "shared/world.h"
#include "span_16E000/code_80429C10.h"
#include "stddef.h"
#include "types.h"
#include "common/unused.h"

/* Stores its argument in D_80154014. */

extern struct MenuSettings D_801462C8;

/* Refreshes the name label of screen D_800E4F60: with no entry at 0x438 it uses the default text
   D_800D34D4_de; otherwise it formats the entry's name from func_8042B1B8_de on the list func_8042B294_de
   returns for 0x434 into a 0x40-byte buffer through D_8011FE88 and takes the text func_802A0494_de
   makes of it. Either text is copied into the screen's label at 0x3F4 through func_802A025C_de, and the
   widget at 0x3EC is pointed at that label. */








extern char *func_8042B1B8_de(s32, s32);

extern void func_8028D380_de(void *, char *, char *, s32);

extern char *func_802A0494_de(char *);

extern void func_802A025C_de(char *, char *);

/* Calls func_8042B0A4_de and then func_8042A7B4_de with 0. */


/* Hides each primary and optional secondary selection widget. */
void func_8040E8D8_de(s32, s32);

 /* extern */
s32 func_8040EC30_de(s32, u16);

 /* extern */





/* Returns one; func_8042BB60_de calls it. */
s32 func_8042AFB8_de(void) {
    return 1;
}

/* Stores its argument in D_80154010. */

void func_8042AFC0_de(s32 value) {
    D_80154010.index = value;
}

void func_8042AFD0_de(s32 value) {
    D_80154014 = value;
}

void func_8042AFE0_de(void) {
    extern struct Screen_func_8042AFE0_de *D_800E4F60;
    char buffer[0x40];

    if (D_800E4F60->entry == 0) {
        func_802A025C_de(D_800E4F60->label,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800D34D4_de[D_801462C8.language]
#else
D_800D34D4_de[0]
#endif
);
    } else {
        func_8028D380_de(&D_8011FE88, func_8042B1B8_de(func_8042B294_de(D_800E4F60->list), D_800E4F60->entry),
                      buffer, 0x3F);
        func_802A025C_de(D_800E4F60->label, func_802A0494_de(buffer));
    }
    D_800E4F60->widget->text = D_800E4F60->label;
}

void func_8042B080_de(void) {
    func_8042B0A4_de();
    func_8042A7B4_de(0);
}

void func_8042B0A4_de(void) {
    extern s32 *D_800E4F60;
    s32 var_s0;
    s32 var_s1;
    var_s1 = 0;
    do {
        var_s0 = var_s1 * 0x10;
        func_8040E8D8_de(func_8040EC30_de(*D_800E4F60, *(u16 *)(&D_800E0F16 + var_s0)), 0);
        if (*(s32 *)(&D_800E0F18 + var_s0) != -1) {
            func_8040E8D8_de(func_8040EC30_de(*D_800E4F60, *(u16 *)(&D_800E0F1A + var_s0)), 0);
        }
            var_s1 += 1;
    } while (var_s1 < 0x28);
}

/* Maps a selection index to its code: 0 gives 5, 1 gives 7, 2 gives 17, 3 gives 11 and anything else
   0. */
int func_8042B154_de(int index) {
    int r;

    switch (index) {
    case 0:
        return 5;
    case 1:
        return 7;
    case 3:
        return 11;
    case 2:
        return 17;
    default:
        r = 0;
        break;
    }
    return r;
}
