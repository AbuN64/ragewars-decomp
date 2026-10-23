#include "COMMON/RECRECAT4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLD.H"
#include "COMMON/CONTROL.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/80423280_50.H"
#include "FRONTEND/80423280_52.H"
#include "FRONTEND/80423280_53.H"
#include "FRONTEND/8040B45C_33.H"
extern struct Screen_func_8042AFE0_de *D_800E4F60;

/* Stores its argument in D_80154014. */

extern struct MenuSettings D_801462C8;

/* Refreshes the name label of screen D_800E4F60: with no entry at 0x438 it uses the default text
   D_800D34D4_de; otherwise it formats the entry's name from func_8042B1B8_de on the list Frontend_CategoryToList
   returns for 0x434 into a 0x40-byte buffer through D_8011FE88 and takes the text func_802A0494_de
   makes of it. Either text is copied into the screen's label at 0x3F4 through func_802A025C_de, and the
   widget at 0x3EC is pointed at that label. */








extern char *func_8042B1B8_de(s32, s32);

extern void func_8028D380_de(Shared_World *, char *, char *, s32);

extern char *func_802A0494_de(char *);

extern void func_802A025C_de(char *, char *);

/* Calls Frontend_HideArenaCatalogueWidgets and then func_8042A7B4_de with 0. */


/* Hides each primary and optional secondary selection widget. */
extern void func_8040E8D8_de(void *, s32);
extern struct Icon D_800E4F64[];

 /* extern */

 /* extern */





/* Returns one; Frontend_OpenResultsScreen calls it. */
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
        func_8028D380_de(&D_8011FE88, func_8042B1B8_de(Frontend_CategoryToList(D_800E4F60->list), D_800E4F60->entry),
                      buffer, 0x3F);
        func_802A025C_de(D_800E4F60->label, func_802A0494_de(buffer));
    }
    D_800E4F60->widget->text = D_800E4F60->label;
}

void func_8042B080_de(void) {
    Frontend_HideArenaCatalogueWidgets();
    func_8042A7B4_de(0);
}

#ifdef NON_MATCHING
/* The catalogue stores word-valued widget identifiers. Cast the value to
 * its 16-bit widget key; an address at word+2 is only its low half on MIPS. */
void Frontend_HideArenaCatalogueWidgets(void) {
    s32 index;
    struct Icon *entry;

    for (index = 0; index < 40; index++) {
        entry = &D_800E4F64[index];
        func_8040E8D8_de(func_8040EC30_de((void *)D_800E4F60->field0,
                                         (u16)entry->key), 0);
        if (entry->other != -1) {
            func_8040E8D8_de(func_8040EC30_de((void *)D_800E4F60->field0,
                                             (u16)entry->other), 0);
        }
    }
}
#else
void Frontend_HideArenaCatalogueWidgets(void) {
    s32 offset;
    s32 index;
    index = 0;
    do {
        offset = index * 0x10;
        func_8040E8D8_de((void *)func_8040EC30_de((void*)D_800E4F60->field0, *(u16 *)(&D_800E0F16 + offset)), 0);
        if (*(s32 *)(&D_800E0F18 + offset) != -1) {
            func_8040E8D8_de((void *)func_8040EC30_de((void*)D_800E4F60->field0, *(u16 *)(&D_800E0F1A + offset)), 0);
        }
            index += 1;
    } while (index < 0x28);
}
#endif

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
