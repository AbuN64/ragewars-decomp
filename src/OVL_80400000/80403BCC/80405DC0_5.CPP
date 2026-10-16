#include "shared/pak_menu.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80405454.h"
#include "span_16E000/code_80405DC0.h"
#include "TYPES.H"
#include "common/unused.h"

/* Enters pak menu mode 1: sets the mode flags, clears the owner's 0x01000000 flag and, when a
   message is pending (D_800E28C0), shows the player's message at 0x554 through func_80442574_de;
   otherwise probes the Controller Pak on the selected channel, falls back to func_80405F48_de when
   func_80404F04_de reports none, and shows the D_44F67C, D_44F994 or D_44F610 prompt according to
   func_80404F3C_de and func_80405598_de. */















extern s32 D_8015375C;
extern s32 D_800E28C0;
extern char D_8014561C[];
extern char D_0044ED44[];
extern char D_0044E468[];

extern void func_80404E28_de(s32 ch);
extern s32 func_80404F04_de(s32 ch);
extern s32 func_80404F3C_de(s32 ch);
extern s32 func_80405598_de(s32 ch);
extern void func_80442574_de(char *, char *, ObjRecAt5DC *, PakMenuSlot *, char *);

void func_804066BC_de(Shared_PakMenu *menu) {
    s32 ch;

    D_8014D4C0_de = 0;
    D_8014D4DC = 0;
    D_80153760 = 1;
    D_8014D4EC_de = 1;
    D_800DE874 = 1;
    D_80153784 = 0;
    D_8015375C = 0;
    menu->items[20].flags &= ~0x01000000;
    ch = menu->slot->unk4;
    if (D_800E28C0 != 0) {
        D_80153784 = 1;
        func_80442574_de(menu->player->unk5DC + 0x554, D_0044FB50, menu->player, menu->slot, 0);
        return;
    }
    func_80404E28_de(ch);
    if (func_80404F04_de(ch) == 0) {
        func_80405F48_de(menu);
        return;
    }
    D_80153784 = 1;
    if (func_80404F3C_de(ch) != 0) {
        func_80442574_de(D_8014561C, D_0044EA2C, menu->player, menu->slot, D_0044FB50);
    } else if (func_80405598_de(ch) != 0) {
        func_80442574_de(D_8014561C, D_0044ED44, menu->player, menu->slot, D_0044E468);
    } else {
        func_80442574_de(D_8014561C, D_0044E9C0, menu->player, menu->slot, D_0044FB50);
    }
}

/* Rates the Controller Pak on channel ch as a save target: when one of its 16 notes is named
   D_800D36D4 or D_800D36D8 it selects the pak with score 123 and returns 1; otherwise it reads the
   pak's free space and note count and, when the pak is readable but has no notes or lacks the
   space the save image needs, records the pak as the best candidate if that need beats the
   current score and returns 0; a readable pak with room returns 1 and a read error returns 0. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)


extern char *D_800E25A4[];
extern char *D_800E25B4[];
extern u8 D_80152789;


#else




#endif


extern s32 D_8011FECC;

extern s32 func_80405338_de(s32 ch, s32 index, u8 **state);
extern void func_80405648_de(u8 *state, u8 *name, s32 size);
extern s32 func_802A037C_de(const void *a, const void *b);
extern s32 func_80405160_de(s32 ch, s32 *freeSpace);
extern s32 func_804050CC_de(s32 ch, s32 *noteCount);
extern u32 func_804057EC_de(u32 size);

s32 func_80406858_de(void *unused, s32 ch, s32 *bestCh, s32 *bestScore) {
    u8 name[16];
    u8 *state0;
    u8 *state1;
    s32 freeSpace;
    s32 noteCount;
    s32 found0;
    s32 found1;
    s32 i;
    s32 result;
    s32 need;
    char *wanted;

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    wanted = D_800E25A4[D_80152789];
#else
    wanted = D_800D36D4;
#endif
    for (i = 0; i < 16; i++) {
        func_80405338_de(ch, i, &state0);
        func_80405648_de(state0, name, 16);
        if (func_802A037C_de(name, wanted) == 0) {
            found0 = 1;
            goto search1;
        }
    }
    found0 = 0;
search1:
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    wanted = D_800E25B4[D_80152789];
#else
    wanted = D_800D36D8;
#endif
    for (i = 0; i < 16; i++) {
        func_80405338_de(ch, i, &state1);
        func_80405648_de(state1, name, 16);
        if (func_802A037C_de(name, wanted) == 0) {
            found1 = 1;
            goto check;
        }
    }
    found1 = 0;
check:
    if (found0 || found1) {
        *bestCh = ch;
        *bestScore = 123;
        return 1;
    }
    result = func_80405160_de(D_800E28C8, &freeSpace);
    if (result == 0) {
        result = func_804050CC_de(D_800E28C8, &noteCount);
        if (result == 0) {
            need = func_804057EC_de(D_8011FECC + 0x610);
            if (noteCount == 0 || freeSpace < need) {
                if (*bestScore < need) {
                    *bestScore = need;
                    *bestCh = ch;
                }
                return 0;
            }
        }
    }
    return result == 0;
}
