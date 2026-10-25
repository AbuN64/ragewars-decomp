#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "FRONTEND/8041DF04_3.H"

/* Calls MarkMenuEventHandled with the arguments it was given and returns zero. */
extern void MarkMenuEventHandled();

s32 func_8041DE94_de(void) {
    MarkMenuEventHandled();
    return 0;
}

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3724, an actor kind at D_800E3728 and a handler at D_800E372C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E3724;
extern s32 D_800E3728;
extern Handler802A2B50 D_800E372C;

s32 func_8041DEB4_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E372C != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E372C;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3724)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3728)) + offset))->field_0;
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
unsigned int func_8041DFB4_us_padding_181FB4[3] = {
    0x65717568, 0x10000094, 0x10000B00,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_8041E394_eu_x_padding_10E394[3] = {
    0xAFB00010, 0x0C0A6623, 0x241000FF,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8041E394_eu_padding_194394[3] = {
    0xAFA20014, 0x8FA2005C, 0x4600A306,
};
#endif
