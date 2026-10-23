#include "include_asm.h"
#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/INTEGERSTATE530.H"
#include "MENU_2/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MATH/802A2870.H"
#include "FRONTEND/8040B45C_35.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"
#include "RESMGR/resmgr_string_memory.H"

/* Allocates and zeroes a 0x118-byte record, copies the header and five-word block of the record func_8040EC30_de finds for the low half of the first argument, links the record func_8040EC30_de finds for the second into it, clears the words at 0x110 and 0x114, and registers it through func_8040EEA4_de and func_8040EF84_de. Adapted from func_8041A580_de with the record size 0x118, the tag 0xB64 and the tail fields changed. */









extern s32 func_80299958_de(void);

extern void *func_80411DCC_de(s32 index);
extern void func_8040EF84_de(NodeRecAt44 *node, void *from, void *to);
extern MenuWidget *func_8040EC30_de(void *root, s32 id);
extern void *func_8025305C_de(s32 size);

/* Appends to a menu: passes the next free 20-byte entry at offset 0x48, selected by the count at
   0x114, to func_802A025C_de and increments the count. func_8041AD10_de selects an entry. */




extern u8 *func_802A025C_de(u8 *, u8 *);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3400, an actor kind at D_800E3404 and a handler at D_800E3408: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E3400;

extern s32 D_800E3404;

extern Handler802A2B50 D_800E3408;

/* Draws the child at 0x8 of window arg0 with the arguments passed by value once func_8040E0D4_de resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values func_802A1898_de reports, narrows them by the resolved basis through func_8040F488_de and installs them through func_802A1870_de around the draw, restoring the saved values after it. Adapted from func_802A1BE0_de. */





extern s32 func_8040E0D4_de(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);

extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);

extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void func_8040E7FC_de(void *, Args);

/* When the fourth argument is one, advances a menu's selection at offset 0x110 to the next of its
   0x114 entries, wrapping to the first, points word 0x38 of its owner at 0x44 to the selected
   20-byte entry at 0x48 and plays sound 0xE81. Returns zero. */








/* When the fourth argument is one, moves a menu's selection at offset 0x110 to the previous of its
   0x114 entries, wrapping to the last, points word 0x38 of its owner at 0x44 to the selected 20-byte
   entry at 0x48 and plays sound 0xE81. Returns zero. */








/* Calls func_802547E4_de with the arguments it was given and returns zero. */


/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3460, an actor kind at D_800E3464 and a handler at D_800E3468: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E3460;

extern s32 D_800E3464;

extern Handler802A2B50 D_800E3468;

/* Calls func_8025DF34_de with 0xE74 and sets the byte at 0x10 of every child in the list at 0x8 of arg0 whose halfword at 0xE is not 8 to 100, returning zero. Adapted from func_802A1E5C_de with both stores to 0x5C and 0x48 removed. */



/* Releases the supplied object through func_802547E4_de and returns zero. */


MenuListWidget *func_8041ABC0_de(s32 arg0, s32 arg1) {
    MenuListWidget *source;
    void *context;
    MenuListWidget *result;
    void *child;

    source = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 0xFFFF);
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x118);
    func_802A0748_de(result, 0, 0x118);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB64;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    child = func_8040EC30_de(context, arg1 & 0xFFFF);
    result->owner = child;
    result->index = 0;
    result->count = 0;
    func_8040EEA4_de(source, result);
    source->field_0C = -1;
    func_8040EF84_de(context, source, result);
    return result;
}

/* Returns the word at offset 0x110 of a record. */
s32 func_8041AD04_de(s32 *record) {
    return record[0x110 / 4];
}

/* Selects entry i of the 20-byte records at offset 0x48 of an object: records the index at 0x110
   and points word 0x38 of the object at 0x44 to that record. func_8041AD04_de returns the index. */






void func_8041AD10_de(struct MenuListWidget *menu, s32 index) {
    menu->index = index;
    menu->owner->selected = &menu->entries[index];
}

void func_8041AD34_de(struct MenuListWidget *menu, u8 *text) {
    func_802A025C_de(menu->entries[menu->count].text, text);
    menu->count++;
}

s32 func_8041AD7C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3408 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3408;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3400)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3404)) + offset))->field_0;
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

void func_8041AE0C_de(Shared_Item *arg0, Args args) {
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    s32 changed;

    changed = 0;
    if (func_8040E0D4_de(&first, &basis, arg0, &args) != 0) {
        if ((arg0->flags & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            func_8040F488_de(&transformed, &basis);
            func_802A1870_de(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        func_8040E7FC_de(arg0->label, args);
        if (changed != 0) {
            func_802A1870_de(value.x, value.z, value.y, value.w);
        }
    }
}

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 100. Returns zero. */




s32 func_8041AF40_de(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 100;
        }
    }
    return 0;
}

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 200. Returns zero. */




s32 func_8041AF70_de(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 200;
        }
    }
    return 0;
}

s32 func_8041AFA0_de(struct MenuRecAt54 *arg0) {
    struct ItemRecAt10 *p;

    func_8025DF34_de(0xE74);
    p = arg0->items;
    if (p != 0) {
        do {
            if (p->kind != 8) {
                p->alpha = 0x64;
            }
            p = p->next;
        } while (p != 0);
    }
    return 0;
}

s32 func_8041AFF8_de(struct MenuRecAt114 *menu, void *second, void *third, s32 active) {
    struct OwnerRecAt38 *owner;

    if (active == 1) {
        owner = menu->owner;
        if (++menu->index >= menu->count) {
            menu->index = 0;
        }
        owner->selected = &menu->entries[menu->index];
        func_8025DF34_de(0xE81);
        return 0;
    }
    return 0;
}

s32 func_8041B05C_de(struct MenuRecAt114 *menu, void *second, void *third, s32 active) {
    struct OwnerRecAt38 *owner;

    if (active == 1) {
        owner = menu->owner;
        if (--menu->index < 0) {
            menu->index = menu->count - 1;
        }
        owner->selected = &menu->entries[menu->index];
        func_8025DF34_de(0xE81);
        return 0;
    }
    return 0;
}

s32 func_8041B0C0_de(void *arg0) {
    func_802547E4_de(arg0);
    return 0;
}

void func_8041B0E0_de(void) {
    func_802982C4_de(0xB61, D_0041B340, D_0041B3D0, 3);
}

void func_8041B110_de(s32 arg0) {
    Record_func_8041B110_de *source;
    void *context;
    Record_func_8041B110_de *result;

    source = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 0xFFFF);
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x44);
    func_802A0748_de(result, 0, 0x44);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB61;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    func_8040EEA4_de(source, result);
    source->field_0C = -1;
    func_8040EF84_de(context, source, result);
}

void func_8041B22C_de(Record_func_8041B22C_de *source) {
    void *context;
    Record_func_8041B22C_de *result;

    if (source->field_0E == 0xB61) {
        return;
    }
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x44);
    func_802A0748_de(result, 0, 0x44);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB61;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    func_8040EEA4_de(source, result);
    source->field_0C = -1;
    func_8040EF84_de(context, source, result);
}

s32 func_8041B340_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3468 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3468;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3460)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3464)) + offset))->field_0;
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

void func_8041B3D0_de(Shared_Item *arg0, Args args) {
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    s32 changed;

    changed = 0;
    if (func_8040E0D4_de(&first, &basis, arg0, &args) != 0) {
        if ((arg0->flags & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            func_8040F488_de(&transformed, &basis);
            func_802A1870_de(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        func_8040E7FC_de(arg0->label, args);
        if (changed != 0) {
            func_802A1870_de(value.x, value.z, value.y, value.w);
        }
    }
}

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 100. Returns zero. */




s32 func_8041B504_de(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 100;
        }
    }
    return 0;
}

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 200. Returns zero. */




s32 func_8041B534_de(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 200;
        }
    }
    return 0;
}

s32 func_8041B564_de(OwnerRecAt44 *arg0) {
    void *p;

    func_8025DF34_de(0xE74);
    p = arg0->root;
    if (p != 0) {
        do {
            if ((u16)((Node_func_8041B610_de *)p)->kind != 8) {
                ((Node_func_8041B610_de *)p)->alpha = 0x64;
            }
            p = (Node_func_8041B610_de *)((Node_func_8041B610_de *)p)->words_00[1];
        } while (p != 0);
    }
    return 0;
}

int func_8041B5BC_de(void *object)
{
    func_802547E4_de(object);
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8041B65C[1] = {
    0x4D4F5645,
};
#endif

#if defined(VERSION_DE)
unsigned int func_8041B5BC_de_padding_1815DC[1] = {
    0x00000000,
};
#endif
