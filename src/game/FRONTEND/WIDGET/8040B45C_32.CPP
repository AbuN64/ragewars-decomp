#include "COMMON/NODERECAT2A8.H"
#include "COMMON/UNUSED.H"
#include "COMMON/LONE/D_800DEA60.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_31.H"
#include "FRONTEND/8040B45C_32.H"
#include "MATH/802A2870.H"

/* Draws a visible widget (flag 8): when Widget_ComputeWidgetBounds places it, and its draw flags ask for
   clipping (0x200), it narrows the current scissor from N64Eng_GetClipBounds to the widget's box through
   func_8040F488_de (skipping the draw when nothing is left) and applies it with N64Eng_SetClipBounds; it then
   draws the widget through Widget_DrawWidget and restores the saved scissor if it was narrowed. */







extern s32 Widget_ComputeWidgetBounds(struct Shape_typemap_165 *a, struct Shape_typemap_165 *box, Widget *widget, DrawArgsFrontendDrawVisibleWidgetClipped *args);

extern void N64Eng_GetClipBounds(s32 *left, s32 *right, s32 *top, s32 *bottom);

extern s32 Node_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


/* Resets the state and copies the two configured values after initialization. */



extern struct Shape_typemap_165 D_8014D580;
extern void Widget_DrawWidget(Widget *widget, DrawArgsFrontendDrawVisibleWidgetClipped args);

void Widget_DrawVisibleWidgetClipped(Widget *widget, DrawArgsFrontendDrawVisibleWidgetClipped args) {
    struct Shape_typemap_165 box;
    struct Shape_typemap_165 area;
    struct Shape_typemap_165 saved;
    struct Shape_typemap_165 clip;
    DrawArgsFrontendDrawVisibleWidgetClipped local;
    s32 clipped;

    clipped = 0;
    if (widget->flags & 8) {
        local = args;
        if (Widget_ComputeWidgetBounds(&area, &box, widget, &local) != 0) {
            if (local.flags & 0x200) {
                N64Eng_GetClipBounds(&saved.field_0, &saved.field_8, &saved.field_4, &saved.field_C);
                clip = saved;
                if (Node_ClampRectToClip(&clip, &box) == 0) {
                    return;
                }
                clipped = 1;
                N64Eng_SetClipBounds(clip.field_0, clip.field_8, clip.field_4, clip.field_C);
            }
            Widget_DrawWidget(widget, args);
            if (clipped) {
                N64Eng_SetClipBounds(saved.field_0, saved.field_8, saved.field_4, saved.field_C);
            }
        }
    }
}

/* Walks a sibling node list and dispatches the by-value event to every node whose flag bit 3 is set. */
void Widget_DrawVisibleSiblings(Widget *node, DrawArgsFrontendDrawVisibleWidgetClipped event) {
    for (; node != 0; node = node->next) {
        if (node->flags & 8) {
            Widget_DrawWidget(node, event);
        }
    }
}

void Widget_ResetTextClipBounds(void) {

    struct Shape_typemap_165 *state;

    Widget_FlushTextBatches();
    state = &D_8014D580;
    state->field_8 = 0;
    state->field_0 = 0;
    state->field_4 = D_800DEA60;
    state->field_C = D_800E2AB4_de;
}

void Frontend_SetWidgetFlag08(void *object, int enabled) {
    u16 *flags = &((Widget *)(object))->flags;
    if (enabled) {
        *flags |= 8;
    } else {
        *flags &= 0xFFF7;
    }
}

/* Sets or clears bit 1 of the flag halfword at offset 0x12 of a record according to the second
   argument. */


void Widget_SetWidgetFlag01(struct Widget *record, int enable) {
    if (enable) {
        record->flags |= 1;
    } else {
        record->flags &= ~1;
    }
}

void Widget_SetWidgetFlag40(void *object, int enabled) {
    u16 *flags = &((Widget *)(object))->flags;
    if (enabled) {
        *flags |= 0x40;
    } else {
        *flags &= 0xFFBF;
    }
}

/* Sets or clears bit 0x100 of the flag halfword at offset 0x12 of a record according to the second
   argument. */


void Widget_SetWidgetFlag100(struct Widget *record, int enable) {
    if (enable) {
        record->flags |= 0x100;
    } else {
        record->flags &= ~0x100;
    }
}

/* Stores two halfwords at offsets 0x14 and 0x16 of a record, a pair set together. */


void Widget_SetPairValues(struct Pair14 *record, s16 first, s16 second) {
    record->first = first;
    record->second = second;
}

/* Hit-tests a widget tree at point (px, py): unless a hit is already recorded it searches the
   node's later siblings first, then offsets the origin by the node's position and searches its
   children, and finally records the node itself when it has an id, its rectangle contains the
   point and FindKindHandler accepts its selector. */








void Widget_FindWidgetAtPoint(WidgetRecAt1A **hit, WidgetRecAt1A *node, DrawArgsFrontendDrawVisibleWidgetClipped args, s32 px, s32 py) {
    if (*hit != 0) {
        return;
    }
    if (node->next != 0) {
        Widget_FindWidgetAtPoint(hit, node->next, args, px, py);
    }
    if (*hit != 0) {
        return;
    }
    args.x += node->x;
    args.y += node->y;
    if (node->child != 0) {
        Widget_FindWidgetAtPoint(hit, node->child, args, px, py);
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
    if (FindKindHandler(node->selector) != 0) {
        *hit = node;
    }
}

/* Returns the union of the flag halfwords at offset 0x12 of every node in a linked list. */


s32 Widget_CollectSiblingFlags(struct WidgetNode *node) {
    s32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return flags;
}

/* Returns whether any node in a linked list has bit 3 set in its flag halfword at offset 0x12. */


s32 Widget_AnyVisibleSibling(struct WidgetNode *node) {
    u32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return (flags >> 3) & 1;
}

/* Returns whether any node in a linked list has bit 0 set in its flag halfword at offset 0x12. */


s32 Widget_AnySiblingFlag01(struct WidgetNode *node) {
    s32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return flags & 1;
}

/* Returns whether any node in a linked list has bit 6 set in its flag halfword at offset 0x12. */


s32 Widget_AnySiblingFlag40(struct WidgetNode *node) {
    u32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return (flags >> 6) & 1;
}

/* Returns whether any node in a linked list has bit 8 set in its flag halfword at offset 0x12. */


s32 Widget_ListHasFlag100(struct WidgetNode *node) {
    u32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return (flags >> 8) & 1;
}

/* Sums the halfword positions at offsets 0x14 and 0x16 along a linked list starting at a node and
   reports the totals through the two pointers. */


void Widget_SumNodeOffsets(struct NodeRecAt16 *node, s32 *x, s32 *y) {
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
