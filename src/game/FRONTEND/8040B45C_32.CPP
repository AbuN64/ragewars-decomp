#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_31.H"
#include "FRONTEND/8040B45C_32.H"
#include "MATH/802A2870.H"

/* Draws a visible widget (flag 8): when Frontend_ComputeWidgetBounds places it, and its draw flags ask for
   clipping (0x200), it narrows the current scissor from func_802A1898_de to the widget's box through
   func_8040F488_de (skipping the draw when nothing is left) and applies it with func_802A1870_de; it then
   draws the widget through Frontend_DrawWidget and restores the saved scissor if it was narrowed. */







extern s32 Frontend_ComputeWidgetBounds(struct Shape_typemap_165 *a, struct Shape_typemap_165 *box, Widget *widget, DrawArgs_func_8040E67C_de *args);

extern void func_802A1898_de(s32 *left, s32 *right, s32 *top, s32 *bottom);

extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


/* Resets the state and copies the two configured values after initialization. */

extern int D_800DEA60;

extern int D_800E2AB4_de;

extern struct Shape_typemap_165 D_8014D580;
extern void Frontend_DrawWidget(Widget *widget, DrawArgs_func_8040E67C_de args);

void func_8040E67C_de(Widget *widget, DrawArgs_func_8040E67C_de args) {
    struct Shape_typemap_165 box;
    struct Shape_typemap_165 area;
    struct Shape_typemap_165 saved;
    struct Shape_typemap_165 clip;
    DrawArgs_func_8040E67C_de local;
    s32 clipped;

    clipped = 0;
    if (widget->flags & 8) {
        local = args;
        if (Frontend_ComputeWidgetBounds(&area, &box, widget, &local) != 0) {
            if (local.flags & 0x200) {
                func_802A1898_de(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (func_8040F488_de(&clip, &box) == 0) {
                    return;
                }
                clipped = 1;
                func_802A1870_de(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            Frontend_DrawWidget(widget, args);
            if (clipped) {
                func_802A1870_de(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
            }
        }
    }
}

/* Walks a sibling node list and dispatches the by-value event to every node whose flag bit 3 is set. */
void func_8040E7FC_de(Widget *node, DrawArgs_func_8040E67C_de event) {
    for (; node != 0; node = node->next) {
        if (node->flags & 8) {
            Frontend_DrawWidget(node, event);
        }
    }
}

void func_8040E894_de(void) {

    struct Shape_typemap_165 *state;

    func_8040CAB0_de();
    state = &D_8014D580;
    state->field_8 = 0;
    state->field_0 = 0;
    state->field_4 = D_800DEA60;
    state->field_C = D_800E2AB4_de;
}

void func_8040E8D8_de(void *object, int enabled) {
    u16 *flags = &((Widget *)(object))->flags;
    if (enabled) {
        *flags |= 8;
    } else {
        *flags &= 0xFFF7;
    }
}

/* Sets or clears bit 1 of the flag halfword at offset 0x12 of a record according to the second
   argument. */


void func_8040E900_de(struct Widget *record, int enable) {
    if (enable) {
        record->flags |= 1;
    } else {
        record->flags &= ~1;
    }
}

void func_8040E928_de(void *object, int enabled) {
    u16 *flags = &((Widget *)(object))->flags;
    if (enabled) {
        *flags |= 0x40;
    } else {
        *flags &= 0xFFBF;
    }
}

/* Sets or clears bit 0x100 of the flag halfword at offset 0x12 of a record according to the second
   argument. */


void func_8040E950_de(struct Widget *record, int enable) {
    if (enable) {
        record->flags |= 0x100;
    } else {
        record->flags &= ~0x100;
    }
}

/* Stores two halfwords at offsets 0x14 and 0x16 of a record, a pair set together. */


void func_8040E978_de(struct Pair14 *record, s16 first, s16 second) {
    record->first = first;
    record->second = second;
}

/* Hit-tests a widget tree at point (px, py): unless a hit is already recorded it searches the
   node's later siblings first, then offsets the origin by the node's position and searches its
   children, and finally records the node itself when it has an id, its rectangle contains the
   point and func_802997E4_de accepts its selector. */








void func_8040E984_de(WidgetRecAt1A **hit, WidgetRecAt1A *node, DrawArgs_func_8040E67C_de args, s32 px, s32 py) {
    if (*hit != 0) {
        return;
    }
    if (node->next != 0) {
        func_8040E984_de(hit, node->next, args, px, py);
    }
    if (*hit != 0) {
        return;
    }
    args.x += node->x;
    args.y += node->y;
    if (node->child != 0) {
        func_8040E984_de(hit, node->child, args, px, py);
    }
    if (*hit != 0) {
        return;
    }
    if (node->id == -1) {
        return;
    }
    if (px < args.x || args.x + node->width < px || py < args.y ||
        args.y + node->height < py) {
        return;
    }
    if (func_802997E4_de(node->selector) != 0) {
        *hit = node;
    }
}

/* Returns the union of the flag halfwords at offset 0x12 of every node in a linked list. */


s32 func_8040EB48_de(struct WidgetNode *node) {
    s32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return flags;
}

/* Returns whether any node in a linked list has bit 3 set in its flag halfword at offset 0x12. */


s32 func_8040EB68_de(struct WidgetNode *node) {
    u32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return (flags >> 3) & 1;
}

/* Returns whether any node in a linked list has bit 0 set in its flag halfword at offset 0x12. */


s32 func_8040EB8C_de(struct WidgetNode *node) {
    s32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return flags & 1;
}

/* Returns whether any node in a linked list has bit 6 set in its flag halfword at offset 0x12. */


s32 func_8040EBAC_de(struct WidgetNode *node) {
    u32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return (flags >> 6) & 1;
}

/* Returns whether any node in a linked list has bit 8 set in its flag halfword at offset 0x12. */


s32 func_8040EBD0_de(struct WidgetNode *node) {
    u32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return (flags >> 8) & 1;
}

/* Sums the halfword positions at offsets 0x14 and 0x16 along a linked list starting at a node and
   reports the totals through the two pointers. */


void func_8040EBF4_de(struct NodeRecAt16 *node, s32 *x, s32 *y) {
    s32 sumX = node->x;
    s32 sumY = node->y;

    while (node->next != 0) {
        node = node->next;
        sumX += node->x;
        sumY += node->y;
    }
    *x = sumX;
    *y = sumY;
}
