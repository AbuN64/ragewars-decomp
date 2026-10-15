#include "span_16E000/code_804366C4.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "decomp/argb_color.h"
#include "gfx.h"
#include "menu_text.h"
#include "shared/func_80421E70_eu_closed.h"
#include "shared/func_804235A8_eu_closed.h"
#include "shared/func_804235A8_eu_layout.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028CCB8.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_8028FC98.h"
#include "span_1000/code_802944E8.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B8DD0.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BBC68.h"
#include "span_1000/code_802BE0D0.h"
#include "span_166000/code_80426310.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "span_16E000/code_8041BEA8.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_80420E90.h"
#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_804251F4.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_8043962C.h"
#include "span_16E000/code_8043E9A8.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"

/* Releases the object D_800E5694 holds through func_802547E4_de, clears D_800E5694 and returns zero. */


extern void func_802547E4_de(void *);

/* Calls func_8029973C_de; when func_80299A08_de reports 0x1C8, passes the word at offset 0x14 of the
   object D_800E5694 points to to func_804369E8_de, then passes -1 to func_8042E988_de if func_802999A0_de
   reports 0x16 for zero and 0xB otherwise, and calls func_802998A8_de. Returns zero. */





/* Calls func_8029973C_de, then passes -1 to func_8042E988_de when func_802999A0_de reports 0x16 for zero
   and 0xB otherwise, then calls func_802998A8_de. Returns zero. */
extern void func_8029973C_de();


void func_8029973C_de();

                                  /* extern */
s32 func_802A0C08_de(void *, s32, ...);

                  /* extern */

                               /* extern */

                               /* extern */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E1D54[];
extern u8 D_80152789;
#else
#endif

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5710, an actor kind at D_800E5714 and a handler at D_800E5718: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80437454)(void *, s32, s32, s32, s32);



extern Handler80437454 D_800E5718;

s32 func_8043701C_de(void) {
    extern void *D_800E5694;
    func_802547E4_de(D_800E5694);
    D_800E5694 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8043704C_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80437054_de(void) {
    return 0;
}

s32 func_8043705C_de(void) {
    extern struct func_80204468_S3 *D_800E5694;
    func_8029973C_de();
#if defined(VERSION_DE)
    if (func_80299A08_de() == 0x1C4) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (func_80299A08_de() == 0x1C8) {
#elif defined(VERSION_EU_X)
    if (func_80299A08_de() == 0x1CC) {
#endif
        func_804369E8_de(D_800E5694->unk14);
        func_8042E988_de(func_802999A0_de(0) == 0x16 ? -1 : 0xB);
        func_802998A8_de();
    }
    return 0;
}

s32 func_804370CC_de(void) {
    func_8029973C_de();
    func_8042E988_de(func_802999A0_de(0) == 0x16 ? -1 : 0xB);
    func_802998A8_de();
    return 0;
}

s32 func_80437114_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern StyleNextState *D_800E5694;
    s32 temp_v0;

    func_8029973C_de();
    if (arg3 == 1) {
        func_804369E8_de(D_800E5694->unk_14);
        temp_v0 = D_800E5694->unk_14 + 1;
        D_800E5694->unk_14 = temp_v0;
        if (temp_v0 >= 4) {
            D_800E5694->unk_14 = 0;
        }
        func_804368F8_de(D_800E5694->unk_14);
        func_802A0C08_de(D_800E5694->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, D_80152789), D_800E5694->unk_14 + 1);
        D_800E5694->unk_18->text = (void *) (D_800E5694->text);
        return 0;
    }
    return 0;
}

s32 func_804371C4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern StyleNextState *D_800E5694;
    s32 temp_v0;

    func_8029973C_de();
    if (arg3 == 1) {
        func_804369E8_de(D_800E5694->unk_14);
        temp_v0 = D_800E5694->unk_14 - 1;
        D_800E5694->unk_14 = temp_v0;
        if (temp_v0 < 0) {
            D_800E5694->unk_14 = 3;
        }
        func_804368F8_de(D_800E5694->unk_14);
        func_802A0C08_de(D_800E5694->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, D_80152789), D_800E5694->unk_14 + 1);
        D_800E5694->unk_18->text = (void *) (D_800E5694->text);
        return 0;
    }
    return 0;
}

s32 func_80437274_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80437454 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E5718 != 0) {
        wildcard = 0x7530;
        entry = &D_800E5718;
        index = 0;
        do {
            if (D_800E5710[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5714[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}
