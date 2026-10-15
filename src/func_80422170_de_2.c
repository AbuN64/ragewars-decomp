#include "span_16E000/code_804221A0.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "types.h"

/* Releases the object D_800E44A0 holds through func_802547E4_de, clears D_800E44A0 and returns zero. */


extern void func_802547E4_de(void *);

/* Event callback for screen D_800E44A0: on event 1 while func_8043C308_de reports the screen in state
   1 it advances the screen through func_8043C080_de and func_8043C2A4_de, and when that leaves it in
   state 2 it tears the match display down through func_80422020_de and func_8042DEA0_de and calls
   func_80264854_de(1). Returns zero. */


extern void func_8043C080_de(void *);

extern void func_8043C2A4_de(void *);

#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_80422020_de(void);
#else
extern void func_8042201C_de(void);
#endif

extern void func_80422020_de(void);

extern void func_8042DEA0_de(void);

/* Unless func_8043C308_de reports one for the object D_800E44A0 holds, calls func_802A2360_de and, when
   the object's word at 0x20 is one, calls func_802A2394_de, then func_80245B28_de and func_8042B2E4_de unless
   the option byte D_801462D5 is set, and finally resets the object through func_8043C278_de. Returns
   zero. */




extern u8 D_801462D5;

extern void func_802A2360_de();

extern void func_802A2394_de();

extern void func_80245B28_de();

extern void func_8042B2E4_de();

extern void func_8043C278_de(struct func_8022A404_S1 *);

/* On event 3 with value 0xB, calls func_8029973C_de and sets the word at offset 0x20 of the object
   D_800E44A0 points to. Returns zero. */




extern void func_8029973C_de();

/* Sets the word at offset 0x20 of the object D_800E44A0 points to and returns zero. */




/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E44A4, an actor kind at D_800E44A8 and a handler at D_800E44AC: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E44A4;

extern s32 D_800E44A8;

extern Handler802A2B50 D_800E44AC;

s32 func_80422278_de(void) {
    extern void *D_800E44A0;
    func_802547E4_de(D_800E44A0);
    D_800E44A0 = 0;
    return 0;
}

s32 func_804222A8_de(s32 arg0, s32 arg1, s32 event) {
    extern s32 func_8043C308_de(void *);
    extern void *D_800E44A0;
    if (event == 1) {
        if (func_8043C308_de(D_800E44A0) != 1) {
            return 0;
        }
        func_8043C080_de(D_800E44A0);
        func_8043C2A4_de(D_800E44A0);
        if (func_8043C308_de(D_800E44A0) != 2) {
            return 0;
        }
#if defined(VERSION_DE)
        func_80422020_de();
#else
        
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_80422020_de
#else
func_8042201C_de
#endif
();
#endif
        func_8042DEA0_de();
        func_80264854_de(1);
    }
    return 0;
}

s32 func_80422340_de(void) {
    extern s32 func_8043C308_de(struct func_8022A404_S1 *);
    extern struct func_8022A404_S1 *D_800E44A0;
    s32 one = 1;

    if (func_8043C308_de(D_800E44A0) == one) {
        return 0;
    }
    func_802A2360_de();
    if (D_800E44A0->unk20 != one) {
        return 0;
    }
    func_802A2394_de();
    if (D_801462D5 == 0) {
        func_80245B28_de();
        func_8042B2E4_de();
    }
    func_8043C278_de(D_800E44A0);
    return 0;
}

s32 func_804223CC_de(void *first, void *second, u32 event, s32 value) {
    extern struct func_8022A404_S1 *D_800E44A0;
    if ((event >> 16) == 3 && value == 0xB) {
        func_8029973C_de();
        D_800E44A0->unk20 = 1;
    }
    return 0;
}

s32 func_80422414_de(void) {
    extern struct func_8022A404_S1 *D_800E44A0;
    D_800E44A0->unk20 = 1;
    return 0;
}

s32 func_8042242C_de(void) {
    func_8029973C_de();
    return 0;
}

s32 func_8042244C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E44AC != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E44AC;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E44A4)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E44A8)) + offset))->field_0;
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
