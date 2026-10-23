#include "include_asm.h"
#include "COMMON/RECRECAT4.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "FRONTEND/80423280_25.H"
#include "FRONTEND/80423280_3.H"
#include "SCENE/802508E0_13.H"

/* Releases the object D_800E4514 holds through func_802547E4_de, calls func_802A2360_de, clears
   D_800E4514 and returns zero. */



extern void func_802A2360_de();

/* Sets the word at offset 0xC of the object D_800E4514 points to and calls func_802A2360_de, once:
   nothing happens when the word is already set. Returns zero. */




/* Handles the menu message func_80299A08_de reports after func_8029973C_de: 0x1C3, 0x1BD, 0x1C2 and
   0x1C4 send codes -1, 13, 12 and 14 to func_8042E988_de; a handled message then runs func_8042302C_de
   and func_802998A8_de. Returns zero. */
extern void func_8029973C_de(void);

extern s32 func_80299A08_de(void);

extern void func_8042E988_de(s32);

extern void func_802998A8_de(void);

/* Calls func_8029973C_de, func_8042E988_de with -1, func_8042302C_de and func_802998A8_de, and returns zero. */
extern void func_8029973C_de();

extern void func_802998A8_de();

typedef s32 (*Handler80423930)(void *, s32, s32, s32, s32);

extern FieldRow D_800E4564[];

extern FieldRow D_800E4568[];

extern Handler80423930 D_800E456C;

/* Releases the object D_800E4518 holds through func_802547E4_de, calls func_802A2360_de, clears D_800E4518, calls
   func_80245B28_de and returns zero. */


extern void func_80245B28_de();

/* Handles the menu message func_80299A08_de reports after func_8029973C_de, for its MESSAGE_COUNT messages from
   FIRST_MESSAGE (0x377 to 0x380 on us) through jtbl_800E1668: one reopens screen D_800E4518 (marking it shown with timer -1 and
   refreshing its two windows at 0x44 and 0x4C) and calls func_80245B28_de; one tries func_8042ACD8_de
   and on failure sets the screen's modes 5 and 4 with timer 20, else reopens it with timer 0; the
   others pass codes 0x17, 13, 12 and 14 to func_8042E988_de. Any handled message then runs
   func_80423080_de. Returns zero. */
/* The first message this handles and how many it takes: eu-x numbers the messages 4 higher, de 4
   lower and takes only 8, as each cartridge's own bytes show; us, us-rev1 and eu share 0x377 and 10. */


extern void func_802A2394_de(void);

/* The message screen D_800E4514; its word at 0xC marks the message handled. */
extern struct func_80205628_S3 *D_800E4514;
extern struct MessageScreen *D_800E4518;
extern void func_8043C278_de(struct MessageScreen *);

extern void func_8040E8D8_de(void *object, int enabled);

extern void func_80245B28_de(void);

extern s32 func_8042ACD8_de(void);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E45AC, an actor kind at D_800E45B0 and a handler at D_800E45B4: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80423B88)(void *, s32, s32, s32, s32);

extern FieldRow D_800E45AC[];

extern FieldRow D_800E45B0[];

extern Handler80423B88 D_800E45B4;

s32 func_804235E8_de(void) {
    func_802547E4_de(D_800E4514);
    func_802A2360_de();
    D_800E4514 = 0;
    return 0;
}

s32 func_80423620_de(void) {
    struct func_80205628_S3 *state = D_800E4514;

    if (state->unkC == 0) {
        state->unkC = 1;
        func_802A2360_de();
    }
    return 0;
}

s32 func_80423654_de(void) {
    s32 handled;
    func_8029973C_de();
    handled = 1;
    switch (func_80299A08_de()) {
#if defined(VERSION_DE)
    case 0x1BF:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x1C3:
#elif defined(VERSION_EU_X)
    case 0x1C7:
#endif
        func_8042E988_de(-1);
        break;
#if defined(VERSION_DE)
    case 0x1B9:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x1BD:
#elif defined(VERSION_EU_X)
    case 0x1C1:
#endif
        func_8042E988_de(13);
        break;
#if defined(VERSION_DE)
    case 0x1BE:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x1C2:
#elif defined(VERSION_EU_X)
    case 0x1C6:
#endif
        func_8042E988_de(12);
        break;
#if defined(VERSION_DE)
    case 0x1C0:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x1C4:
#elif defined(VERSION_EU_X)
    case 0x1C8:
#endif
        func_8042E988_de(14);
        break;
    default:
        handled = 0;
        break;
    }
    if (handled == 1) {
        func_8042302C_de();
        func_802998A8_de();
    }
    return 0;
}

s32 func_80423720_de(void) {
    func_8029973C_de();
    func_8042E988_de(-1);
    func_8042302C_de();
    func_802998A8_de();
    return 0;
}

s32 func_80423758_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80423930 *entry;
    ObjRecAtCV1 *actor;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E456C != 0) {
        wildcard = 0x7530;
        entry = &D_800E456C;
        index = 0;
        do {
            if (D_800E4564[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4568[index].value;
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

s32 func_804237E8_de(void) {
    func_802547E4_de(D_800E4518);
    func_802A2360_de();
    D_800E4518 = 0;
    func_80245B28_de();
    return 0;
}

s32 func_80423828_de(void) {
    s32 handled;
    u32 message;
    func_8029973C_de();
    handled = 1;
    message = func_80299A08_de() -
#if defined(VERSION_DE)
        0x373;
#elif defined(VERSION_EU_X)
        0x37B;
#else
        0x377;
#endif
    if (message >=
#if defined(VERSION_DE)
        8
#else
        10
#endif
    ) {
        goto other;
    }
    switch (message) {
#if defined(VERSION_DE)
        case 0: goto reopen;
        case 1: goto retry;
        case 2: goto code_14;
        case 3: goto code_17;
        case 4: goto other;
        case 5: goto other;
        case 6: goto code_13;
        case 7: goto code_12;
#else
        case 0: goto code_13;
        case 1: goto other;
        case 2: goto other;
        case 3: goto other;
        case 4: goto other;
        case 5: goto code_12;
        case 6: goto reopen;
        case 7: goto retry;
        case 8: goto code_14;
        case 9: goto code_17;
#endif
        }
reopen:
    func_802A2394_de();
    func_8043C278_de(D_800E4518);
    D_800E4518->shown = 1;
    D_800E4518->timer = -1;
    func_8040E8D8_de(D_800E4518->window, 1);
    func_8040E8D8_de(D_800E4518->second_window, 1);
    func_80245B28_de();
    goto done;
code_17:
    func_8042E988_de(0x17);
    goto done;
retry:
    func_802A2394_de();
    if (func_8042ACD8_de() == 0) {
        D_800E4518->mode = 5;
        D_800E4518->next_mode = 4;
        D_800E4518->timer = 20;
    } else {
        func_8043C278_de(D_800E4518);
        D_800E4518->shown = 1;
        D_800E4518->timer = 0;
    }
    goto done;
code_13:
    func_8042E988_de(13);
    goto done;
code_12:
    func_8042E988_de(12);
    goto done;
code_14:
    func_8042E988_de(14);
    goto done;
other:
    handled = 0;
done:
    if (handled == 1) {
        func_80423080_de();
    }
    return 0;
}

s32 func_80423990_de(void) {
    func_8029973C_de();
    return 0;
}

s32 func_804239B0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80423B88 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E45B4 != 0) {
        wildcard = 0x7530;
        entry = &D_800E45B4;
        index = 0;
        do {
            if (D_800E45AC[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E45B0[index].value;
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

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD658[2] = {
    0x00424034, 0x0042405C,
};
#endif
