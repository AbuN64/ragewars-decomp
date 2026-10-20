#include "RESMGR/resmgr_stream_callbacks.H"
#include "include_asm.h"
#include "COMMON/NODERECAT2A8.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/SLOTRECATCV1.H"
#include "FRONTEND/8040B45C_35.H"
#include "FRONTEND/CODE_80411598.H"
#include "RESMGR/802A0888_8.H"
#include "MATH/802A2870.H"
#include "SCENE/802508E0_13.H"
extern s32 func_8040E0D4_de(struct Shape_typemap_165 *, struct Shape_typemap_165 *, WidgetLayout *, DrawArgs *);
#include "RESMGR/802A0888_4.H"

/* Puts a new node in a tree node's place, taking over its parent and next links and becoming the parent's first child or the successor of the predecessor func_8040ECA8_de's search finds, then makes the old node the new node's only child with its next link and the halfwords at 0x14 and 0x16 cleared.
   Adapted from func_8040EDE4_de with the new node taking the old node's next link and child position and the old node's links reset afterwards changed. */



extern struct Tree *func_8040ECA8_de(struct Tree *node, s32 id);

static inline struct Tree *findPredecessor(struct Tree *node, s32 id) {
    s32 childId;
    struct Tree *found = 0;

    childId = id;
    while (node != 0 && found == 0) {
        if (node->next != 0 && node->next->id == (u16)id) {
            found = node;
        }
        if (found == 0 && node->child != 0) {
            found = func_8040ECA8_de(node->child, (u16)childId);
        }
        node = node->next;
    }
    return found;
}

/* Measures the pixel width of a string of the given length in the given font by summing each character's signed width byte from the font record func_8041200C_de returns, then adding the spacing func_80411C60_de reports once between each pair of characters.
   Adapted from func_8025C8D8_de with the two clears and per-record call replaced by the font lookup, the width sum and the spacing term changed. */





extern GlyphBuffer *func_8041200C_de(s32 index);

extern short func_80411C60_de(s32 index);

/* Draws a widget's variant image: when func_8040E0D4_de accepts the widget at the position, picks the
   pressed (flag 0x100), highlighted (flag 0x40) or normal image of the widget, and when present
   moves the position back by the image's offset scaled by the style's scale factors and draws it
   through func_8040DB04_de with the same flags and style. */













extern void func_8040DB04_de(struct Pair14 *image, Triple at, Style style);

/* Draws the child at 0x8 of a window with the arguments passed by value after clearing D_800E2AB8 once func_8040E0D4_de resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values func_802A1898_de reports, narrows them by the resolved basis through func_8040F488_de, giving up when it fails, and installs them through func_802A1870_de around the draw, restoring the saved values after it. Adapted from func_8041BA00_de with D_800E2AB8 cleared before the rectangle is resolved, the resolved basis declared first, and a failed func_8040F488_de ending the function. */







extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);

extern s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void func_8040E7FC_de(void *, Args);

extern s32 D_800E2AB8;

/* Records the last column and row of a width by height area: stores width - 1 and height - 1 in
   D_800DEA60 and D_800E2AB4_de, and fills the rectangle D_8014D580 with zero to width - 1 and zero
   to height - 1. */


extern s32 D_800DEA60;

extern s32 D_800E2AB4_de;

extern struct Shape_typemap_165 D_8014D580;

/* Releases every loaded slot of the active, referenced entries of the pool at D_80153C20: each
   loaded slot (flag 1) has its data released through func_80419624_de, its flags and owner cleared and
   the entry's reference count decremented, and an entry left without references is unloaded
   through func_80411518_de and marked inactive. Pool layout and indexed slot access follow func_80411518_de. */









extern Pool_func_8040F580_de D_80153C20;

extern void func_80419624_de(char *data);

/* Relocates a loaded widget list and its children from the stored base to base: for widgets
   flagged 0x10 rebases the four resource words, then by widget type clears an out-of-range image
   index (type 3), rebases the extra pointer and marks the widget 0x800 (type 2), clears the fourth
   word (type 4) or turns the three packed resource references (index and offset) into pointers,
   acquiring resources through Frontend_AcquireArchiveEntry and marking them in D_80153C4C as needed (type 8);
   it then rebases the name (clearing it for an empty type 2 widget), the child list, which it
   relocates recursively, and the next pointer. */



extern s16 D_80153C0C;

extern u16 *D_80153C4C;

extern void *func_80411DCC_de(s32 index);

extern void Frontend_AcquireArchiveEntry(u32 index);

static inline void func_8040F75C_resolve(UiWidget *widget) {
    UiWidget *w;
    u32 index;
    s32 offset;
    s32 data;

    w = widget;
    index = (u32)(w->words[0] & 0xFFFF0000) >> 16;
    offset = w->words[0] & 0xFFFF;
    if (index != 0 || offset != 0) {
        data = func_80411DCC_de(index);
        if (data == 0) {
            Frontend_AcquireArchiveEntry(index);
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
            Frontend_AcquireArchiveEntry(index);
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
            Frontend_AcquireArchiveEntry(index);
            data = func_80411DCC_de(index);
            D_80153C4C[index] |= 1;
        }
        w->words[2] = data + offset;
    }
}

void func_8040EEA4_de(struct Tree *node, struct Tree *added) {
    struct Tree *parent;

    added->child = node;
    added->parent = node->parent;
    added->next = node->next;
    parent = node->parent;
    if (parent->child == node) {
        parent->child = added;
    } else {
        findPredecessor(parent, (u16)node->id)->next = added;
    }
    node->next = 0;
    node->parent = added;
    node->field_14 = 0;
    node->field_16 = 0;
}

/* Walks a node tree recursively, replacing every reference to one pointer with another in each node's link fields. */



void func_8040EF84_de(NodeRecAt44 *node, void *from, void *to) {
    if (node != 0) {
        if (node->left != 0) {
            func_8040EF84_de(node->left, from, to);
        }
        if (node->right != 0) {
            func_8040EF84_de(node->right, from, to);
        }
        if (node->flags & 0x10) {
            if (node->ref30 == from) {
                node->ref30 = to;
            }
            if (node->ref34 == from) {
                node->ref34 = to;
            }
            if (node->ref38 == from) {
                node->ref38 = to;
            }
            if (node->ref2C == from) {
                node->ref2C = to;
            }
        }
        if (node->kind == 2) {
            if (node->ref44 == from) {
                node->ref44 = to;
            }
        }
    }
}

/* Swaps two widgets within the widget tree: after walking up from the first widget to the root
   (type 2), it finds each widget's predecessor in its parent's child list, links the other widget
   in its place (as the predecessor's next or the parent's first child), and swaps the two widgets'
   parent and next links. */



void func_8040F044_de(WidgetRecAtE *a, WidgetRecAtE *b) {
    WidgetRecAtE *w;
    WidgetRecAtE *cursorA;
    WidgetRecAtE *cursorB;
    WidgetRecAtE saved;

    cursorA = a;
root:
    if (cursorA->type != 2) {
        cursorA = cursorA->parent;
        goto root;
    }
    cursorA = a->parent;
    w = cursorA->child;
    cursorA = 0;
    goto testA;
nextA:
    w = cursorA->next;
testA:
    if (w != a) {
        cursorA = w;
        if (cursorA != 0) {
            goto nextA;
        }
    }
    cursorB = b->parent;
    w = cursorB->child;
    cursorB = 0;
    goto testB;
nextB:
    w = cursorB->next;
testB:
    if (w != b) {
        cursorB = w;
        if (cursorB != 0) {
            goto nextB;
        }
    }
    if (cursorA != 0) {
        cursorA->next = b;
    } else {
        a->parent->child = b;
    }
    if (cursorB != 0) {
        cursorB->next = a;
    } else {
        b->parent->child = a;
    }
    saved = *a;
    a->next = b->next;
    a->parent = b->parent;
    b->next = saved.next;
    b->parent = saved.parent;
}

s32 func_8040F160_de(s32 font, u8 *text, s32 length) {
    GlyphBuffer *record;
    s32 i;
    s32 total;

    record = func_8041200C_de(font);
    total = 0;
    for (i = 0; i < length; i++) {
        total += record->glyphs[*text++ - 0x20].width;
    }
    total += func_80411C60_de(font) * (length - 1);
    return total;
}

/* Stores two bytes at offsets 0x2C and 0x2D of a record, a pair set together. */


void func_8040F1FC_de(struct Pair2C *record, u8 first, u8 second) {
    record->first = first;
    record->second = second;
}

/** Store a word at offset 0x2c. */
void func_8040F208_de(void *object, int value) {
    ObjRecAt2CV2 *record = object;
    record->unk2C = value;
}

/** Store a word at offset 0x2c. */
void func_8040F210_de(void *object, int value) {
    ObjRecAt2CV2 *record = object;
    record->unk2C = value;
}

/* Stores four values into the consecutive words at offsets 0x2C to 0x38 of a record. */


void func_8040F218_de(struct QuadRecAt2C *record, s32 first, s32 second, s32 third, s32 fourth) {
    record->values[0] = first;
    record->values[1] = second;
    record->values[2] = third;
    record->values[3] = fourth;
}

void func_8040F230_de(ButtonWidget *widget, Triple at, Style style) {
    Shared_Quad box0;
    Shared_Quad box1;
    struct Pair14 *image;

    if (func_8040E0D4_de((struct Shape_typemap_165 *)&box0, (struct Shape_typemap_165 *)&box1, (WidgetLayout *)widget, (DrawArgs *)&at) != 0) {
        if (at.z & 0x100) {
            image = widget->pressed;
        } else if (at.z & 0x40) {
            image = widget->highlighted;
        } else {
            image = widget->normal;
        }
        if (image != 0) {
            at.x -= (s32)(image->first * style.scaleX);
            at.y -= (s32)(image->second * style.scaleY);
            func_8040DB04_de(image, at, style);
        }
    }
}

void func_8040F350_de(WidgetLayout *arg0, Args args) {
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    Quad_func_802A1BE0_de first;
    s32 changed;
    UiWidget *window = arg0;

    changed = 0;
    D_800E2AB8 = 0;
    if (func_8040E0D4_de((struct Shape_typemap_165 *)&first, (struct Shape_typemap_165 *)&basis, arg0, (DrawArgs *)&args) != 0) {
        if ((window->flags & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            if (func_8040F488_de(&transformed, &basis) == 0) {
                return;
            }
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

/* Intersects a rectangle with another in place, widening it to at least one unit and returning whether it was non-empty. */



s32 func_8040F488_de(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip) {
    s32 ok;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 v;

    x0 = rect->field_0;
    ok = 1;
    if (x0 < clip->field_0) {
        x0 = clip->field_0;
    }
    x1 = rect->field_4;
    rect->field_0 = x0;
    if (clip->field_4 < x1) {
        x1 = clip->field_4;
    }
    y0 = rect->field_8;
    rect->field_4 = x1;
    if (y0 < clip->field_8) {
        y0 = clip->field_8;
    }
    y1 = rect->field_C;
    rect->field_8 = y0;
    if (clip->field_C < y1) {
        y1 = clip->field_C;
    }
    rect->field_C = y1;
    v = rect->field_0 + 1;
    if (rect->field_4 < v) {
        rect->field_4 = v;
        ok = 0;
    }
    v = rect->field_8 + 1;
    if (rect->field_C < v) {
        rect->field_C = v;
        ok = 0;
    }
    return ok;
}

void func_8040F534_de(s32 width, s32 height) {
    struct Shape_typemap_165 *rect = &D_8014D580;

    width--;
    height--;
    D_800DEA60 = width;
    D_800E2AB4_de = height;
    rect->field_8 = 0;
    rect->field_0 = 0;
    rect->field_4 = width;
    rect->field_C = height;
}

/** Perform no work. */
void func_8040F568_de(void) {
}

/* Orders two records by the unsigned halfword at offset 0x14, returning the difference in the
   shape a sort comparator uses. */


int func_8040F570_de(struct Field_u16_14 *a, struct Field_u16_14 *b) {
    return a->value - b->value;
}

void func_8040F580_de(void) {
    s32 e;
    s32 n;
    s32 i;
    SlotRecAtCV2 *slot;

    for (e = 0; e < D_80153C20.count; e++) {
        if (D_80153C20.entries[e].refCount != 0 && D_80153C20.entries[e].active != 0) {
            for (n = 0; n < D_80153C20.entries[e].def->unkE; n++) {
                slot = D_80153C20.entries[e].pages[n];
                for (i = 0; i < 0x60; i++) {
                    if (slot[i].flags & 1) {
                        func_80419624_de(slot[i].data);
                        slot[i].flags = 0;
                        slot[i].owner = 0;
                        D_80153C20.entries[e].refCount--;
                    }
                }
            }
            if (D_80153C20.entries[e].refCount == 0) {
                func_80411518_de(e);
                D_80153C20.entries[e].active = 0;
            }
        }
    }
}

void func_8040F6DC_de(UiWidget *widget, s32 base, s32 old) {
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
            widget->children = (UiWidget *)((s32)widget->children + base - old);
            func_8040F6DC_de(widget->children, base, old);
        }
        if (widget->next != 0) {
            widget->next = (UiWidget *)((s32)widget->next + base - old);
        }
    }
}

#ifndef NON_MATCHING
INCLUDE_ASM("ovl_80400000", func_8040F9E0_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
/* Opens image archives and allocates image, palette, and cached-resource tables. */
void * func_8025305C_de(s32);
u8 * func_802A025C_de(u8 *, u8 *);
s32 func_802A0E8C_de(void *, void *);
extern char D_8014D724[];
extern char D_800DD0B0[];
void func_802A0EB0_de(s32);
void func_80419608_de(void *);
void func_8040F9E0_de(s32 index);






extern s32 D_80153C2C;
extern s32 D_80153C40;

extern s32 D_800E2AC4[3];

typedef union { s16 count; s32 clear; } ArchiveCountWord; /* FAKEMATCH: shared views keep count reloads ordered with record clears. */
#include "FRONTEND/ARCHIVEDATA.H"
typedef struct Images Images;
typedef struct func_8040FC14_S2 func_8040FC14_S2;
typedef struct func_8040FC14_S3 func_8040FC14_S3;
typedef struct func_8040FC14_S4 func_8040FC14_S4;
typedef struct func_8040FC14_S5 func_8040FC14_S5;
typedef struct func_8040FC14_S6 func_8040FC14_S6;
typedef struct Palettes Palettes;
typedef struct func_8040FC14_S9 func_8040FC14_S9;
typedef struct func_8040FC14_S10 func_8040FC14_S10;
typedef struct func_8040FC14_S11 func_8040FC14_S11;
typedef struct func_8040FC14_S12 func_8040FC14_S12;
typedef struct Objects Objects;
typedef struct func_8040FC14_S14 func_8040FC14_S14;
typedef struct func_8040FC14_S15 func_8040FC14_S15;
typedef struct func_8040FC14_S17 func_8040FC14_S17;
typedef struct func_8040FC14_S18 func_8040FC14_S18;
typedef struct func_8040FC14_S19 func_8040FC14_S19;
struct Images {
    s32 unk0;
    char unk4[0x204];
    s32 unk208;
    u32 unk20C;
    char pad20C[0x4C];
    s16 unk25C;
    char pad25C[0x2];
    void* unk260;
    void* unk264;
    void* unk268;
    void* unk26C; /* FAKEMATCH: reload the resource base after linking a descriptor. */
};

typedef struct { char pad0[0xC]; u32 unkC; char padC[0xC]; s32 unk1C; } ImageHeader;
extern ImageHeader D_8014D940;
struct func_8040FC14_S2 {
    char pad0[0x12];
    u8 unk12;
};
struct func_8040FC14_S3 {
    void *unk0;
    s32 unk4;
    char pad8[0xA];
    s16 unk12;
    char pad14[8];
};
struct func_8040FC14_S4 {
    s32 unk0;
    s16 unk4;
}; /* FAKEMATCH: order table clears between the two table-base reloads. */
struct func_8040FC14_S5 {
    void* unk0;
};
struct func_8040FC14_S6 {
    char unk0[1];
};
struct Palettes {
    s16 unk0;
    char pad0[0x2];
    void* unk4;
    char pad4[0xC];
    ArchiveCountWord unk14;
    void* unk18;
    void* unk1C;
};
struct func_8040FC14_S9 {
    s16 unk0;
    char pad0[0xA];
    void* unkC;
    void* unk10;
};
struct Objects {
    s16 unk0;
    char pad2[2];
    void *raw;
    func_8040FC14_S15 *unk8;
};
struct func_8040FC14_S10 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    u32 unk28;
    char pad28[0x30];
    Objects objects;
    Palettes palettes;
};
extern func_8040FC14_S10 D_8014D934;
struct func_8040FC14_S11 {
    char pad0[0x48C];
    void* unk48C;
};
struct func_8040FC14_S12 {
    char unk0[1];
};
struct func_8040FC14_S14 {
    char pad0[0x48C];
    void* unk48C;
};
struct func_8040FC14_S15 {
    char pad0[0x4];
    s8 unk4;
    char pad4[0x47F];
    void** unk484;
    void** unk488;
    ArchiveFontRecord *metadata;
    char pad490[0xC];
};
struct func_8040FC14_S17 {
    char unk0[1];
};
struct func_8040FC14_S18 {
    char unk0[1];
};
struct func_8040FC14_S19 {
    s32 unk0;
    char pad4[8];
    s32 unkC;
    func_8040FC14_S10 header;
    char pad98[0x8];
    s32 unkA0;
};
extern func_8040FC14_S19 D_8014D924;
typedef union {
    Images images;
    struct { char prefix[0x204]; func_8040FC14_S19 status; } archive;
} ArchiveContext;
extern ArchiveContext D_801539B0;



extern func_8040FC14_S3 *D_80153C10;
/* FAKEMATCH: preserve the ordered table-base reloads around the two clears. */
extern func_8040FC14_S4 *D_8014D988;
extern func_8040FC14_S15 *D_80153C28;
/* FAKEMATCH: reload the map table base on each record clear. */
extern ArchiveMapEntry *D_8014D9B4;
/* Opens image archives and allocates image, palette, and cached-resource tables. */
void func_8040FB94_de(u8 *arg0) {
    void *state; /* FAKEMATCH: recycle the file base for the final status view, ending its old live range. */
    void * regpart_state;
    func_8040FC14_S10 *header;
    Palettes *palettes;
    s32 recordData; /* FAKEMATCH: share the field-derived member address and later object counter in one N64 integer local; their lifetimes are disjoint. */
    Objects *objects;
    func_8040FC14_S15 **objectTable;
    ArchiveCountWord *mapCount;
    s16 temp_a0_3;
    s16 temp_hi;
    s16 temp_v0_3;
    s32 temp_a0; /* FAKEMATCH: reuse the record-link offset as the object index to raise its allocator priority. */
    void **temp_a0_2;
    void **temp_a0_4;
    s32 temp_a1;
    s32 temp_a3;
    s32 var_s2; /* FAKEMATCH: reuse the descriptor index as the later palette stride to preserve allocation lifetime. */
    s32 temp_v1;
    s32 var_a1; /* FAKEMATCH: share the two independent pointer-array indices. */
    s32 var_a2; /* FAKEMATCH: share the independent linking and block-offset counters. */
    s32 var_s0; /* FAKEMATCH: reuse the image, map, and record-link indices to preserve their shared saved register. */
    extern s32 D_8014D970;
    s32 var_s4;
    s32 var_v1;
    u32 temp_v0_2;
    u32 temp_v1_2;
    void **temp_v1_3;
    void **temp_v1_4;
    ArchiveFontRecord *temp_s0;
    func_8040FC14_S15 *temp_s1;
    void *temp_s7;
    func_8040FC14_S2 *temp_v0;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    func_8040FC14_S3 *var_s1;

    temp_a3 = func_802A0E8C_de(arg0, D_800DD0B0);
    state = &D_801539B0.images;
    ((Images *)state)->unk0 = temp_a3;
    func_802A0ED4_de((s32) &((Images *)state)->unk208, 0x54, 1, temp_a3);
    temp_hi = ((Images *)state)->unk20C / 28;
    ((Images *)state)->unk25C = temp_hi;
    if (temp_hi > 0) {
        ((Images *)state)->unk26C = func_8025305C_de(temp_hi << 5);
        ((Images *)state)->unk268 = func_8025305C_de(((Images *)state)->unk25C * 8);
        ((Images *)state)->unk264 = func_8025305C_de(((Images *)state)->unk25C * 4);
        temp_v0 = func_8025305C_de((s32) ((Images *)state)->unk20C);
        ((Images *)state)->unk260 = temp_v0;
        Resmgr_SeekStream(((Images *)state)->unk0, ((Images *)state)->unk208, 0);
        func_802A0ED4_de((s32) temp_v0, 0x1C, (s32) ((Images *)state)->unk25C, ((Images *)state)->unk0);
        var_s0 = 0;
        if (((Images *)state)->unk25C > 0) {
            recordData = (s32) &((Images *)state)->unk26C;
            var_s1 = (void *)temp_v0;
            var_s2 = 0;
            do {
                temp_v1 = var_s0;
                var_s1->unk4 = 0;
                var_s1->unk12 = 0;
                temp_a1 = var_s0 << 5;
                D_8014D988[var_s0].unk4 = 0;
                D_8014D988[var_s0].unk0 = 0;
                var_s0 += 1;
                D_80153C10[var_s2].unk0 = ((void *)&((func_8040FC14_S6 *)((*((void **)recordData))))->unk0[temp_a1]);
                var_s1++;
                func_80419608_de((u8 *)*((void **)recordData) + temp_a1);
                var_s2 += 1;
            } while (var_s0 < ((Images *)state)->unk25C);
        }
    }
    palettes = &D_8014D924.header.palettes;
    temp_v0_2 = (u32) D_8014D924.header.unk18 >> 3;
    palettes->unk0 = (s16) temp_v0_2;
    if ((s32)(temp_v0_2 << 0x10) > 0) {
        palettes->unk4 = func_8025305C_de((s32) D_8014D924.header.unk18);
        Resmgr_SeekStream(((Images *)state)->unk0, D_8014D924.header.unk14, 0);
        func_802A0ED4_de((s32) palettes->unk4, (s32) D_8014D924.header.unk18, 1, ((Images *)state)->unk0);
        func_8040F9E0_de(0);
    }
    temp_v0_3 = D_8014D924.header.unk28 / 12;
    palettes->unk14.count = temp_v0_3;
    if ((s32)((u32)temp_v0_3 << 0x10) > 0) {
        palettes->unk18 = func_8025305C_de(D_8014D924.header.unk28);
        if (*D_800E2AC4 != 0) {
            temp_v0_4 = func_8025305C_de(D_8014D924.header.unk28);
            palettes->unk1C = temp_v0_4;
            func_802A0748_de(temp_v0_4, 0, (u32) D_8014D924.header.unk28);
        }
        Resmgr_SeekStream(((Images *)state)->unk0, D_8014D924.header.unk24, 0);
        func_802A0ED4_de((s32) palettes->unk18, D_8014D924.header.unk28, 1, ((Images *)state)->unk0);
        var_s0 = 0;
        mapCount = &palettes->unk14;
        if (palettes->unk14.count > 0) {
            var_v1 = 0;
            do {
                var_s0 += 1;
                D_8014D9B4[var_v1].data = 0;
                var_v1 += 1;
            } while (var_s0 < mapCount->count);
        }
        temp_v0_5 = func_8025305C_de((((func_8040FC14_S9 *)(&D_80153C40))->unk0) * 2);
        (((func_8040FC14_S9 *)(&D_80153C40))->unk10) = temp_v0_5;
        func_802A0748_de(temp_v0_5, 0, (((func_8040FC14_S9 *)(&D_80153C40))->unk0) * 2);
        temp_v0_6 = func_8025305C_de((((func_8040FC14_S9 *)(&D_80153C40))->unk0) * 2);
        (((func_8040FC14_S9 *)(&D_80153C40))->unkC) = temp_v0_6;
        func_802A0748_de(temp_v0_6, 0, (((func_8040FC14_S9 *)(&D_80153C40))->unk0) * 2);
    }
    header = &D_8014D924.header;
    if (header->unk0 > 0) {
        var_s0 = 0;
        temp_s7 = func_8025305C_de(header->unk8);
        Resmgr_SeekStream(((Images *)state)->unk0, header->unk4, 0);
        func_802A0ED4_de((s32) temp_s7, header->unk8, 1, ((Images *)state)->unk0);
        header->objects.raw = func_8025305C_de(header->unk0);
        Resmgr_SeekStream(((Images *)state)->unk0, ((func_8040FC14_S19 *)&D_8014D924)->unkC, 0);
        func_802A0ED4_de((s32) header->objects.raw, header->unk0, 1, ((Images *)state)->unk0);
        temp_v1_2 = (u32) header->unk0 >> 5;
        header->objects.unk0 = (s16) temp_v1_2;
        temp_v0_7 = func_8025305C_de((s16) temp_v1_2 * 0x49C);
        header->objects.unk8 = temp_v0_7;
        func_802A0748_de(temp_v0_7, 0, header->objects.unk0 * 0x49C);
        recordData = (s32) &header->objects.raw;
        if (header->objects.unk0 > 0) {
            var_a2 = 0;
            do {
                temp_a0 = var_s0 << 5;
                var_s0 += 1;
                D_80153C28[var_a2].metadata = ((void *)&((func_8040FC14_S12 *)(*((void **)recordData)))->unk0[temp_a0]);
                var_a2 += 1;
            } while (var_s0 < header->objects.unk0);
        }
        objects = &D_8014D924.header.objects;
        temp_a0 = 0;
        recordData = 0;
        if (objects->unk0 > 0) {
            objectTable = &objects->unk8;
            var_s4 = 0;
            do {
                temp_s0 = D_80153C28[var_s4].metadata;
                temp_s1 = (*objectTable) + var_s4;
                Resmgr_SeekStream(((Images *)state)->unk0, D_8014D924.header.unkC + temp_s0->glyphTableOffset, 0);
                func_802A0ED4_de(&temp_s1->unk4, 8, 0x60, ((Images *)state)->unk0);
                temp_s1->unk484 = func_8025305C_de(temp_s0->bitmapCount * 4);
                *temp_s1->unk484 = func_8025305C_de(temp_s0->bitmapCount * 0x1080);
                func_802A0748_de(*temp_s1->unk484, 0, temp_s0->bitmapCount * 0x1080);
                var_a1 = 0;
                if (temp_s0->bitmapCount > 0) {
                    var_a2 = 0;
                    do {
                        temp_a0_2 = &temp_s1->unk484[var_a1];
                        temp_v1_3 = temp_s1->unk484;
                        var_a1 += 1;
                        *temp_a0_2 = ((void *)&((func_8040FC14_S17 *)((*temp_v1_3)))->unk0[var_a2]);
                        var_a2 += 0x1080;
                    } while (var_a1 < temp_s0->bitmapCount);
                }
                temp_a0_3 = temp_s0->bitmapCount;
                if (temp_a0_3 > 0) {
                    var_s2 = ((temp_s0->glyphWidth * 2) + 7) & ~7;
                    temp_s1->unk488 = func_8025305C_de(temp_a0_3 * 4);
                    *temp_s1->unk488 = func_8025305C_de(temp_s0->bitmapCount * var_s2);
                    Resmgr_SeekStream(((Images *)state)->unk0, D_8014D970 + ((s32 *)temp_s7)[temp_a0], 0);
                    func_802A0ED4_de((s32) *temp_s1->unk488, temp_s0->bitmapCount * var_s2, 1, ((Images *)state)->unk0);
                    var_a1 = 0;
                    if (temp_s0->bitmapCount > 0) {
                        var_a2 = 0;
                        do {
                            temp_a0_4 = &temp_s1->unk488[var_a1];
                            temp_v1_4 = temp_s1->unk488;
                            var_a1 += 1;
                            *temp_a0_4 = ((void *)&((func_8040FC14_S18 *)((*temp_v1_4)))->unk0[var_a2]);
                            var_a2 += var_s2;
                        } while (var_a1 < temp_s0->bitmapCount);
                    }
                    temp_a0 += temp_s0->bitmapCount;
                }

                recordData += 1;
                var_s4 += 1;
            } while (recordData < D_80153C20.count);
        }
        func_802547E4_de(temp_s7);
    } else {
        header->objects.unk0 = 0;
    }
    regpart_state = &D_801539B0.archive.status;
    ((func_8040FC14_S19 *)regpart_state)->unk0 = 1;
    func_802A025C_de(D_801539B0.images.unk4, arg0);
    ((func_8040FC14_S19 *)regpart_state)->unkA0 = 0;
    func_802A0EB0_de(D_801539B0.images.unk0);
    D_801539B0.images.unk0 = 0;
}
/* Loads the string table of resource archive section index: frees the previous string buffer and
 * pointer table, reads the section's bytes from the archive file into a fresh buffer (its size is the
 * distance to the next section's start, or to the archive end for the last one), then builds the table of
 * string starts: entry 0 is the buffer, and every byte after a terminating zero starts the next string. */
typedef struct ArchiveView8040F9E0 {
    s32 handle;
    u8 pad04[0x22C];
    s32 base;
    s32 end;
    u8 pad238[0x44];
    s16 count;
    u8 pad27E[2];
    ArchiveTextIndexEntry *sections;
    u8 pad284[4];
    u8 *strings;
    u8 **stringTable;
} ArchiveView8040F9E0;
void func_802547E4_de(void *arg0);
void func_8040F9E0_de(s32 index) {
    ArchiveView8040F9E0 *archive;
    s32 count;
    s32 next;
    s32 size;
    s32 slot;
    s32 closeArchive;
    u8 *p;

    archive = (ArchiveView8040F9E0 *)&D_801539B0;
    count = archive->sections[index].count;
    closeArchive = 0;
    if (archive->strings != 0) {
        func_802547E4_de(archive->strings);
    }
    archive->strings = 0;
    if (archive->stringTable != 0) {
        func_802547E4_de(archive->stringTable);
    }
    archive->stringTable = 0;
    if (index < archive->count - 1) {
        next = archive->sections[index + 1].start;
    } else {
        next = archive->end;
    }
    size = next - archive->sections[index].start;
    archive->strings = (u8 *)func_8025305C_de(size);
    Resmgr_SeekStream(archive->handle, archive->sections[index].start + archive->base, 0);
    func_802A0ED4_de((s32)archive->strings, size, 1, archive->handle);
    if (closeArchive) {
        func_802A0EB0_de(archive->handle);
        archive->handle = 0;
    }
    archive->stringTable = (u8 **)func_8025305C_de(count << 2);
    archive->stringTable[0] = archive->strings;
    slot = 1;
    for (p = archive->strings + 1; p < archive->strings + size && slot < count; p++) {
        if (*p == 0) {
            archive->stringTable[slot] = p + 1;
            slot++;
        }
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8040FB94_de);
#endif
