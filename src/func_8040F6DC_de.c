#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Relocates a loaded widget list and its children from the stored base to base: for widgets
   flagged 0x10 rebases the four resource words, then by widget type clears an out-of-range image
   index (type 3), rebases the extra pointer and marks the widget 0x800 (type 2), clears the fourth
   word (type 4) or turns the three packed resource references (index and offset) into pointers,
   acquiring resources through func_804116CC_de and marking them in D_80153C4C as needed (type 8);
   it then rebases the name (clearing it for an empty type 2 widget), the child list, which it
   relocates recursively, and the next pointer. */



extern s16 D_80153C0C;
extern u16 *D_80153C4C;

extern s32 func_80411DCC_de(u32 index);
extern void func_804116CC_de(u32 index);

static inline void func_8040F75C_resolve(Widget_func_8040F6DC_de *widget) {
    Widget_func_8040F6DC_de *w;
    u32 index;
    s32 offset;
    s32 data;

    w = widget;
    index = (u32)(w->words[0] & 0xFFFF0000) >> 16;
    offset = w->words[0] & 0xFFFF;
    if (index != 0 || offset != 0) {
        data = func_80411DCC_de(index);
        if (data == 0) {
            func_804116CC_de(index);
            data = func_80411DCC_de(index);
            D_80153C4C[index] |= 1;
        }
        w->words[0] = data + offset;
    }
    index = (u32)(w->words[1] & 0xFFFF0000) >> 16;
    offset = w->words[1] & 0xFFFF;
    if (index != 0 || offset != 0) {
        data = func_80411DCC_de(index);
        if (data == 0) {
            func_804116CC_de(index);
            data = func_80411DCC_de(index);
            D_80153C4C[index] |= 1;
        }
        w->words[1] = data + offset;
    }
    index = (u32)(w->words[2] & 0xFFFF0000) >> 16;
    offset = w->words[2] & 0xFFFF;
    if (index != 0 || offset != 0) {
        data = func_80411DCC_de(index);
        if (data == 0) {
            func_804116CC_de(index);
            data = func_80411DCC_de(index);
            D_80153C4C[index] |= 1;
        }
        w->words[2] = data + offset;
    }
}

void func_8040F6DC_de(Widget_func_8040F6DC_de *widget, s32 base, s32 old) {
    for (; widget != 0; widget = widget->next) {
        if (widget->flags & 0x10) {
            if (widget->words[0] != 0) {
                widget->words[0] = widget->words[0] + base - old;
            }
            if (widget->words[1] != 0) {
                widget->words[1] = widget->words[1] + base - old;
            }
            if (widget->words[2] != 0) {
                widget->words[2] = widget->words[2] + base - old;
            }
            if (widget->words[3] != 0) {
                widget->words[3] = widget->words[3] + base - old;
            }
        }
        switch (widget->type) {
            case 3:
                if (widget->words[0] < 0 || D_80153C0C - 1 < widget->words[0]) {
                    widget->words[0] = 0;
                }
                break;
            case 2:
                if (widget->extra != 0) {
                    widget->extra = widget->extra + base - old;
                }
                widget->flags |= 0x800;
                break;
            case 4:
                widget->words[3] = 0;
                break;
            case 8:
                func_8040F75C_resolve(widget);
                break;
        }
        if ((widget->name != 0 && (widget->next != 0 || widget->children != 0)) || widget->type != 2) {
            widget->name = widget->name + base - old;
        } else {
            widget->name = 0;
        }
        if (widget->children != 0) {
            widget->children = (Widget_func_8040F6DC_de *)((s32)widget->children + base - old);
            func_8040F6DC_de(widget->children, base, old);
        }
        if (widget->next != 0) {
            widget->next = (Widget_func_8040F6DC_de *)((s32)widget->next + base - old);
        }
    }
}
