#include "COMMON/ANIMATION.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/SLOTRECATCV1.H"
#include "MENU_2/SCROLL.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU_2/804196C0_21.H"
#include "MATH/802A2870.H"
#include "FRONTEND/8040B45C_35.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"
#include "RESMGR/resmgr_string_memory.H"

/* Stores a mode at offset 0x58 of an object and plays sound 0xE77 for mode 1 or 0xE76 for mode 2
   through func_8025DF34_de. */



/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3360, an actor kind at D_800E3364 and a handler at D_800E3368: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E3360;

extern s32 D_800E3364;

extern Handler802A2B50 D_800E3368;

/* Calls func_802547E4_de with the arguments it was given and returns zero. */

/* Allocates and zeroes a 0x58-byte record, copies the header and five-word block of the record func_8040EC30_de finds for the low half of the first argument, links the record func_8040EC30_de finds for the second into it with its halfword at 0x18, stores the third argument, and registers it through func_8040EEA4_de and func_8040EF84_de.
   Adapted from func_802A1990_de with the record size, tag 0xB63, the tail fields and the dropped func_802A1B24_de call changed. */









extern s32 func_80299958_de(void);

extern void *func_80411DCC_de(s32 index);

extern MenuSliderWidget *func_8040EC30_de(s32 arg0, s32 arg1);

extern MenuSliderWidget *func_8025305C_de(s32);



extern void func_8040EF84_de(s32 arg0, MenuSliderWidget *arg1, MenuSliderWidget *arg2);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3390, an actor kind at D_800E3394 and a handler at D_800E3398: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E3390;

extern s32 D_800E3394;

extern Handler802A2B50 D_800E3398;

/* Draws the child at 0x8 of window arg0 with the arguments passed by value once func_8040E0D4_de resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values func_802A1898_de reports, narrows them by the resolved basis through func_8040F488_de and installs them through func_802A1870_de around the draw, restoring the saved values after it. Adapted from func_802A1BE0_de. */





extern s32 func_8040E0D4_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);

extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);

extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void func_8040E7FC_de(void *, Args);

/* Scrolls up: moves a scroll bar to the previous item through func_8041A6EC_de unless it is already
   at the first. */


extern void func_8041A6EC_de(struct Scroll *, s32);

void func_8041A430_de(struct func_8022FD9C_S4 *object, s32 mode) {
    object->unk58 = mode;
    switch (mode) {
    case 1:
        func_8025DF34_de(0xE77);
        break;
    case 2:
        func_8025DF34_de(0xE76);
        break;
    }
}

/* Returns the word at offset 0x58 of a record. */
s32 func_8041A470_de(s32 *record) {
    return record[0x58 / 4];
}

/* Sets the flag word at offset 0x5C that func_8041A488_de clears. */


void func_8041A47C_de(struct Access_s32_5C *object) {
    object->field = 1;
}

/* Clears the flag word at offset 0x5C that func_8041A47C_de sets to one. func_80423A40_de calls it on
   the object func_8041A280_de has just returned. */


void func_8041A488_de(struct Access_s32_5C *object) {
    object->field = 0;
}

s32 func_8041A490_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3368 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3368;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3360)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3364)) + offset))->field_0;
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

/* A disabled debug print: takes a target, a format and variable arguments and does nothing beyond
   spilling the variable arguments to their home slots. Matched like the variadic stub func_80268264_de:
   the leftover float test of its compiled-out body makes the compiler fill the return delay slot
   with the last argument spill. */
void func_8041A520_de(void *target, const char *format, ...)
{
    float enabled;

    enabled = 1.0f;
    if (enabled) {
    }
}

s32 func_8041A530_de(void *arg0) {
    func_802547E4_de(arg0);
    return 0;
}

void func_8041A550_de(void) {
    func_802982C4_de(0xB63, D_0041A724, D_0041A7B4, 3);
}

MenuSliderWidget *func_8041A580_de(s32 arg0, s32 arg1, s32 arg2) {
    MenuSliderWidget *source;
    s32 context;
    MenuSliderWidget *result;
    MenuSliderWidget *child;

    source = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 0xFFFF);
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x58);
    func_802A0748_de(result, 0, 0x58);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB63;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    child = func_8040EC30_de(context, arg1 & 0xFFFF);
    result->field_44 = child;
    result->field_48 = child->field_18;
    result->field_4C = arg2;
    result->field_50 = 0;
    result->field_54 = 2;
    func_8040EEA4_de(source, result);
    source->field_0C = -1;
    func_8040EF84_de(context, source, result);
    return result;
}

/* Returns the word at offset 0x50 of a record. */
s32 func_8041A6E0_de(s32 *record) {
    return record[0x50 / 4];
}

/* Positions a scroll bar: records the current item at offset 0x50 and stores in the halfword at
   0x18 of the bar object at 0x44 the item scaled from the item count at 0x4C to the track
   length at 0x48. */




void func_8041A6EC_de(struct Scroll *scroll, s32 item) {
    scroll->item = item;
    scroll->bar->field18 = (f32) item / (f32) scroll->count * (f32) scroll->length;
}

s32 func_8041A724_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3398 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3398;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3390)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3394)) + offset))->field_0;
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

void func_8041A7B4_de(void *arg0, Args args) {
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    s32 changed;
    UiWidget *window = arg0;

    changed = 0;
    if (func_8040E0D4_de(&first, &basis, arg0, &args) != 0) {
        if ((window->flags & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            func_8040F488_de(&transformed, &basis);
            func_802A1870_de(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        func_8040E7FC_de(window->children, args);
        if (changed != 0) {
            func_802A1870_de(value.x, value.z, value.y, value.w);
        }
    }
}

void func_8041A8E8_de(struct Scroll *scroll) {
    if (scroll->item > 0) {
        func_8041A6EC_de(scroll, scroll->item - 1);
    }
}

void func_8041A910_de(struct Scroll *scroll) {
    if (scroll->item < scroll->count) {
        func_8041A6EC_de(scroll, scroll->item + 1);
    }
}

/* sets the menu's state word at 0x54 to 2 and Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 100. Returns zero. */




s32 func_8041A940_de(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    menu->state = 2;
    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 100;
        }
    }
    return 0;
}

/* sets the menu's state word at 0x54 to 2 and Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 200. Returns zero. */




s32 func_8041A978_de(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    menu->state = 2;
    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 200;
        }
    }
    return 0;
}
