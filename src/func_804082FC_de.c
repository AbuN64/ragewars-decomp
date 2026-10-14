#include "shared/pak_menu.h"
#include "common/unused.h"
#include "span_16E000/code_80405DC0.h"
#include "types.h"
#include "types.h"
/* Searches controller pak slots for the pak menu: takes the channel (the cycling one D_800E28C8 or the
   menu slot's) and returns 1 (setting D_80153784) when func_80406178_de takes over; with a note search pending (D_8014D4EC_de)
   it shows the notes through func_80407290_de; otherwise it looks for the game's note (D_800D36D8) among
   the channel's 16 notes and shows the found prompt or the create screen func_80407578_de; when cycling,
   it advances D_800E28C8 to the next channel whose pak is present (-1 and a failure flag when none)
   and retries it, returning 0 after func_80405F48_de when nothing answers. */

extern s32 D_8015375C;

extern char D_8014561C[];
extern char D_0044EEF4[];

extern s32 func_80406178_de(Shared_PakMenu *menu, s32 ch, s32 mode);
extern void func_80407290_de(s32 arg0, Shared_PakMenu *menu, s32 arg2);
extern void func_80407578_de(s32 arg0, Shared_PakMenu *menu, s32 arg2);
extern void func_80405338_de(s32 ch, s32 note, s32 *state);
extern void func_80405648_de(s32 state, char *name, s32 size);
extern s32 func_802A037C_de(char *name, s32 game);
extern void func_80442574_de(char *, char *, ObjRecAt5DC *, PakMenuSlot *, char *);
extern void func_80404E28_de(s32 ch);
extern s32 func_80404F04_de(s32 ch);

static inline void pickChannel(Shared_PakMenu *menu, s32 *ch)
{
    if (D_8015375C != 0) {
        *ch = D_800E28C8;
    } else {
        *ch = menu->owner->unk4;
    }
}

static inline s32 findNote(s32 ch, s32 *found)
{
    char name[16];
    s32 state;
    s32 game = D_800D36D8;
    s32 i;

    D_8014D4FC = -1;
    for (i = 0; i < 16; i++) {
        func_80405338_de(ch, i, &state);
        func_80405648_de(state, name, 16);
        if (func_802A037C_de(name, game) == 0) {
            if (found != 0) {
                *found = i;
            }
            return 1;
        }
    }
    return 0;
}

s32 func_804082FC_de(s32 arg0, Shared_PakMenu *menu, s32 arg2)
{
    s32 ch = 0;
    s32 use;
    s32 next;
    s32 tries;
    s32 hasNote;
    s32 c;

    if (D_8014D4C0_de != 0) {
        pickChannel(menu, &ch);
    }
    if (D_8015375C != 0) {
        use = D_800E28C8;
    } else {
        use = ch;
    }
    if (func_80406178_de(menu, use, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_8014D4EC_de != 0) {
        if (D_8014D4C0_de != 0) {
            func_80407290_de(arg0, menu, arg2);
            return 1;
        }
    } else if (D_8014D4C0_de != 0) {
        hasNote = findNote(use, &D_8014D4FC);
        if (hasNote != 0 && D_8014D4FC >= 0 && D_8014D4FC < 16) {
            func_80442574_de(D_8014561C, D_0044EEF4, menu->player, menu->owner, D_0044E4D4);
            return 1;
        }
        func_80407578_de(arg0, menu, arg2);
        return 1;
    }
    if (D_8015375C != 0) {
        next = 0;
        if (D_800E28C8 != -1) {
            next = D_800E28C8 + 1;
            if (next >= 4) {
                next = 0;
            }
        }
        for (tries = 0; tries < 4; tries++) {
            func_80404E28_de(next);
            if (func_80404F04_de(next) != -2) {
                break;
            }
            next++;
            if (next >= 4) {
                next = 0;
            }
        }
        if (tries == 4) {
            next = -1;
        }
        D_800E28C8 = next;
        if (next == -1) {
            D_8014ADA0 = D_80153784 = 1;
            return 1;
        }
        if (D_8015375C != 0) {
            c = D_800E28C8;
        } else {
            c = menu->owner->unk4;
        }
        ch = c;
        if (func_80406178_de(menu, c, 0) != 0) {
            D_80153784 = 1;
            return 1;
        }
        func_80405F48_de(menu);
    }
    return 0;
}
