#include "include_asm.h"
#include "COMMON/LABEL.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/STATEPAIR.H"
#include "COMMON/MENURECAT24.H"
#include "COMMON/NAME.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8041BEA8_5.H"
#include "FRONTEND/8042E080_42.H"
#include "FRONTEND/8040B45C_32.H"
#include "SCENE/802508E0_13.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#else
#endif
extern SlotDialog *D_800E3518;

/* Calls func_8040E928_de with flag 1 on each of the list's items (count at 0x48, items from 0x4C) and
   returns 0. */


/* Updates the slot-selection dialog after availability and capacity probes, choosing unavailable, empty and confirmation states or entering the requested transition. The negative probe statuses -4, -3 and -1 trigger the error transition. */

#if defined(VERSION_DE)
enum { SLOT_RESOURCE_962 = 956, SLOT_RESOURCE_966 = 961, SLOT_RESOURCE_968 = 960, SLOT_RESOURCE_971 = 964 };
#elif defined(VERSION_EU)
enum { SLOT_RESOURCE_962 = 962, SLOT_RESOURCE_966 = 966, SLOT_RESOURCE_968 = 968, SLOT_RESOURCE_971 = 971 };

extern s32 D_800E25A4[];

#elif defined(VERSION_EU_X)
enum { SLOT_RESOURCE_962 = 967, SLOT_RESOURCE_966 = 969, SLOT_RESOURCE_968 = 971, SLOT_RESOURCE_971 = 975 };

extern s32 D_800E25A4[];

#else
enum { SLOT_RESOURCE_962 = 962, SLOT_RESOURCE_966 = 966, SLOT_RESOURCE_968 = 968, SLOT_RESOURCE_971 = 971 };

#endif

extern s32 func_80264614_de(s32);

extern void func_80298368_de(s32);

extern void func_802991D4_de(s32);

extern void func_8029973C_de(void);

extern void func_802A2360_de(void);

extern s32 func_802A0C08_de(void *, const char *, ...);

extern s32 func_80404BE8_de(s32, s32, s32 *);

extern s32 Pak_GetStatus(s32);

extern s32 func_80435384_de(s32,u32 *);

extern void func_80404E28_de(s32);

extern void func_8041C244_de(void);

extern void func_80434FB4_de(s32);

extern char *D_800D36D4;

extern s32 D_800E28CC, D_800DF4C0,D_8010F190,D_80146D60,D_8014AD94;

#if defined(VERSION_DE)
extern char D_800DD450[];

extern s32 D_800DF4C4;
#elif defined(VERSION_EU)
extern char D_800EDAD0[];
extern s32 D_800EFB34;
#elif defined(VERSION_EU_X)
extern char D_800EDAD0[];
extern s32 D_800EACF4;

#elif defined(VERSION_US)
extern char D_800DD450[];

extern s32 D_800DE174;
#else
extern char D_800DD450[];
extern s32 D_800E3514;

#endif

/* Calls func_802A2394_de and func_8029973C_de, then func_80298368_de with 2, sets D_8014ADA0 and returns
   one. */
extern s32 D_8014ADA0;

extern void func_802A2394_de();

extern void func_8029973C_de();

/* Refreshes each of the four ports through func_80404E28_de and sets field 0x1C of D_800E3518 as soon as one reports status 0, -1, -3 or -4 through Pak_GetStatus, clearing it otherwise. */





extern void func_80404E28_de(s32 port);

extern s32 Pak_GetStatus(s32 port);

/* Advances the slot-dialog retry counter. Before the fourth attempt it updates
 * the dialog; later attempts start the transition and mark it active. */
extern s32 D_800DF4C0;

extern void func_8041BE90_de(void);

/* Builds screen state D_800E3518 under a parent window: allocates its 0x2C bytes, keeps the parent,
   opens windows 0x3C3 (shown), 0x3C9, 0x3C4 and 0x3C5 (hidden) at 0x4 to 0x10, clears the words at
   0x14 and 0x18, resets through func_8040C428_de(0) and func_802A2394_de, sets D_800E28C8 to -1 and
   D_80146D70 to 0, releases the resources of D_8011FAC0 and of its block at 0x3C8, clears the
   word at 0x1C and returns zero. */


extern s32 D_800E28C8;

extern s32 D_80146D70;

#include "COMMON/GAME_SESSION.H"

extern void func_8040C428_de(s32);

extern void func_802A2394_de(void);

extern void func_80293334_de(void *, s32, s32);

extern void func_80286AA8_de(void *, s32, s32);

/* Releases the object D_800E3518 holds through func_802547E4_de, clears D_800E3518 and returns zero. */



/* In one- or no-player mode, counts a tick on the state D_800E3518 and, while it is not paused, once
   more than five ticks have passed runs func_802A2360_de and func_8041C244_de; always returns 0. */


extern int D_800E28E0;

/* The slot-error scalar is real external storage in every ROM version: the de cart writes
   800DF4C4, eu writes 800EFB34, eu-x writes 800EACF4, us writes 800DE174, us-rev1 800E3514. */
#if defined(VERSION_EU) || defined(VERSION_DE) || defined(VERSION_US)
#elif defined(VERSION_EU_X)
extern s32 D_800EACF4;
#else
extern s32 D_800E3514;
#endif

#if defined(VERSION_EU)
extern s32 D_800EFB34;
#elif defined(VERSION_DE)
extern s32 D_800DF4C4;
#elif defined(VERSION_US)
extern s32 D_800DE174;
#else
#endif

extern s32 func_80299A08_de(void);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E351C, an actor kind at D_800E3520 and a handler at D_800E3524: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E351C;

extern s32 D_800E3520;

extern Handler802A2B50 D_800E3524;

int func_8041BE28_de(ListRecAt4C *list) {
    int i;

    for (i = 0; i < list->count; i++) {
        func_8040E928_de(list->items[i], 1);
    }
    return 0;
}

void func_8041BE90_de(void) {
    s32 sp10;
    u32 sp14;
    s32 var_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_s2;
    Label *temp_s0;

    func_802991D4_de(SLOT_RESOURCE_962);
    func_8040E8D8_de(D_800E3518->absent, 0);
    var_s2 = 0;
    func_8040E8D8_de(D_800E3518->unavailable, 0);
    var_s1 = 1;
    func_8040E8D8_de(D_800E3518->prompt, 0);
    temp_v0 = func_80264614_de(0);
    if (temp_v0 == 1) {
        func_8041C19C_de();
        if (D_800E3518->ready == 1) {
            func_80404E28_de(D_800DF4C0);
            temp_v0_2 = Pak_GetStatus(D_800DF4C0);
            switch (temp_v0_2) { /* irregular */
            case 0:
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                if ((func_80404BE8_de(((D_800E25A4)[D_80152789]), D_800DF4C0, &sp10) == 0) && (func_80435384_de(D_800DF4C0, &sp14) == 0)) {
#else
                if ((func_80404BE8_de((D_800D36D4), D_800DF4C0, &sp10) == 0) && (func_80435384_de(D_800DF4C0, &sp14) == 0)) {
#endif
                    var_s1 = sp14 > 0U;
                }
                break;
            case -4:
            case -3:
            case -1:
                var_s2 = 1;
                break;
            }
        }
    }
    if (temp_v0 == 0) {
        D_800E3518->state = 1;
        D_800E3518->elapsed = 0;
        func_8040E8D8_de(D_800E3518->main, 0);
        func_8040E8D8_de(D_800E3518->unavailable, 1);
        goto block_25;
    }
    if (D_800E3518->ready == 0) {
        D_800E3518->state = 2;
        D_800E3518->elapsed = 0;
        func_8040E8D8_de(D_800E3518->main, 0);
        func_8040E8D8_de(D_800E3518->absent, 1);
        var_a0 = SLOT_RESOURCE_971;
        goto block_24;
    }
    if ((var_s2 == 1) || (D_8010F190 & 0x1000)) {
        func_8029973C_de();
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
        if (var_s2 == 0) {
#if defined(VERSION_DE)
            D_800DF4C4 = 0;
#elif defined(VERSION_EU)
            D_800EFB34 = 0;
#elif defined(VERSION_EU_X)
            D_800EACF4 = 0;
#elif defined(VERSION_US)
            D_800DE174 = 0;
#else
            D_800E3514 = 0;
#endif
        } else {
#if defined(VERSION_DE)
            D_800DF4C4 = 2;
#elif defined(VERSION_EU)
            D_800EFB34 = 2;
#elif defined(VERSION_EU_X)
            D_800EACF4 = 2;
#elif defined(VERSION_US)
            D_800DE174 = 2;
#else
            D_800E3514 = 2;
#endif
        }
        func_80434FB4_de(6);
        func_80298368_de(0x13);
        return;
    }
    if (var_s1 == 1) {
        func_8041C244_de();
        return;
    }
    temp_s0 = func_8040EC30_de(D_800E3518->root, SLOT_RESOURCE_968);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    func_802A0C08_de(D_800E3518->text, D_800EDAD0, D_800DF4C0 + 1);
#else
    func_802A0C08_de(D_800E3518->text, D_800DD450, D_800DF4C0 + 1);
#endif
    temp_s0->text = D_800E3518->text;
    D_800E3518->state = 3;
    D_800E3518->elapsed = 0;
    func_8040E8D8_de(D_800E3518->main, 0);
    func_8040E8D8_de(D_800E3518->prompt, 1);
    var_a0 = SLOT_RESOURCE_966;
block_24:
    func_802991D4_de(var_a0);
block_25:
    func_802A2360_de();
}

s32 func_8041C164_de(void) {
    func_802A2394_de();
    func_8029973C_de();
    func_80298368_de(2);
    D_8014ADA0 = 1;
    return 1;
}

void func_8041C19C_de(void) {
    s32 port;

    D_800E3518->ready = 0;
    for (port = 0; port < 4; port++) {
        func_80404E28_de(port);
        switch (Pak_GetStatus(port)) {
        case 0:
            D_800E3518->ready = 1;
            return;
        case -1:
        case -3:
        case -4:
            D_800E3518->ready = 1;
            return;
        }
    }
}

void func_8041C244_de(void) {
    D_800DF4C0++;
    if (D_800DF4C0 >= 4) {
        func_802A2394_de();
        func_8029973C_de();
        func_80298368_de(2);
        D_8014ADA0 = 1;
    } else {
        func_8041BE90_de();
    }
}

s32 func_8041C2AC_de(void *parent) {
    void *window;
    char *resources;
    D_800E3518 = func_8025305C_de(0x2C);
    D_800E3518->root = parent;
#if defined(VERSION_DE)
    window = func_8040EC30_de(parent, 0x3BE);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = func_8040EC30_de(parent, 0x3C3);
#elif defined(VERSION_EU_X)
    window = func_8040EC30_de(parent, 0x3CC);
#endif
    D_800E3518->main = window;
    func_8040E8D8_de(window, 1);
#if defined(VERSION_DE)
    window = func_8040EC30_de(parent, 0x3C3);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = func_8040EC30_de(parent, 0x3C9);
#elif defined(VERSION_EU_X)
    window = func_8040EC30_de(parent, 0x3CD);
#endif
    D_800E3518->absent = window;
    func_8040E8D8_de(window, 0);
#if defined(VERSION_DE)
    window = func_8040EC30_de(parent, 0x3BD);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = func_8040EC30_de(parent, 0x3C4);
#elif defined(VERSION_EU_X)
    window = func_8040EC30_de(parent, 0x3C6);
#endif
    D_800E3518->unavailable = window;
    func_8040E8D8_de(window, 0);
#if defined(VERSION_DE)
    window = func_8040EC30_de(parent, 0x3BF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = func_8040EC30_de(parent, 0x3C5);
#elif defined(VERSION_EU_X)
    window = func_8040EC30_de(parent, 0x3C8);
#endif
    D_800E3518->prompt = window;
    func_8040E8D8_de(window, 0);
    D_800E3518->elapsed = 0;
    D_800E3518->state = 0;
    func_8040C428_de(0);
    func_802A2394_de();
    D_800E28C8 = -1;
    D_80146D70 = 0;
    resources = (char *)&D_8011FAC0;
    func_80293334_de(resources, 0, 0);
    func_80286AA8_de(resources + 0x3C8, 0, 0);
    D_800E3518->ready = 0;
    return 0;
}

s32 func_8041C3DC_de(void) {
    func_802547E4_de(D_800E3518);
    D_800E3518 = 0;
    return 0;
}

int func_8041C40C_de(void) {
    if (D_800E28E0 < 2) {
        D_800E3518->elapsed++;
        if (D_800E3518->state == 0) {
            if (D_800E3518->elapsed < 6) {
                return 0;
            }
            func_802A2360_de();
            func_8041C244_de();
        }
    }
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8041C46C_de(void) {
    return 0;
}

s32 func_8041C474_de(void) {
    func_8029973C_de();
    return 0;
}

/* The dialog-event codes func_80299A08_de reports differ per cartridge family: the European
   eu-x cart numbers them 0x3C9..0x3CF, the de cart 0x3C1..0x3C5, and eu/us/us-rev1 0x3C6..0x3CB.
   Each case below carries the same work in every family, only its label changes. */
s32 func_8041C494_de(void) {
    func_8029973C_de();
    switch (func_80299A08_de()) {
#if defined(VERSION_EU_X)
    case 0x3CF:
#elif defined(VERSION_DE)
    case 0x3C4:
#else
    case 0x3CB:
#endif
        func_8040E8D8_de(D_800E3518->absent, 0);
        func_8041BE90_de();
        break;
#if defined(VERSION_EU_X)
    case 0x3CE:
#elif defined(VERSION_DE)
    case 0x3C5:
#else
    case 0x3CA:
#endif
        func_8041C164_de();
        break;
#if defined(VERSION_EU_X)
    case 0x3CA:
#elif defined(VERSION_DE)
    case 0x3C2:
#else
    case 0x3C7:
#endif
        func_8041C244_de();
        break;
#if defined(VERSION_EU_X)
    case 0x3C9:
#elif defined(VERSION_DE)
    case 0x3C1:
#else
    case 0x3C6:
#endif
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
#if defined(VERSION_EU)
        D_800EFB34 = 1;
#elif defined(VERSION_EU_X)
        D_800EACF4 = 1;
#elif defined(VERSION_DE)
        D_800DF4C4 = 1;
#elif defined(VERSION_US)
        D_800DE174 = 1;
#else
        D_800E3514 = 1;
#endif
        func_80434FB4_de(6);
        func_80298368_de(0x13);
        break;
    }
    return 0;
}

s32 func_8041C574_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3524 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3524;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E351C)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3520)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8041C67C[1] = {
    0x00941000,
};
#endif
