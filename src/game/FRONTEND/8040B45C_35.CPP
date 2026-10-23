#include "MENU/GFX/80414430_24.H"
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
#include "RESMGR/resmgr_stream_io.H"
#include "MATH/802A2870.H"
#include "SCENE/802508E0_13.H"
extern s32 func_8040E0D4_de(struct Shape_typemap_165 *, struct Shape_typemap_165 *, WidgetLayout *, DrawArgs *);
#include "RESMGR/resmgr_string_memory.H"

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
   through Frontend_DrawWidget with the same flags and style. */













extern void Frontend_DrawWidget(struct Pair14 *image, Triple at, Style style);

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
   loaded slot (flag 1) has its data released through Gfx_ReleaseImage, its flags and owner cleared and
   the entry's reference count decremented, and an entry left without references is unloaded
   through func_80411518_de and marked inactive. Pool layout and indexed slot access follow func_80411518_de. */









extern Pool_func_8040F580_de D_80153C20;


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
            Frontend_DrawWidget(image, at, style);
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
                        Gfx_ReleaseImage((struct OwnedImage *)slot[i].data);
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

#include "FRONTEND/ARCHIVEDATA.H"
#include "FRONTEND/LAYOUT.H"
void *func_8025305C_de(s32 size);
u8 *func_802A025C_de(u8 *dst, u8 *src);
void func_802A0EB0_de(s32 handle);
void func_8040F9E0_de(s32 index);
extern char D_800DD0B0;
extern s32 D_800E2AC4;

/* Records of the menu resource file (original names from the debug type catalog). */
/* One texture of the resource's texture table (28 bytes). */
typedef struct _sm_texture_element {
    struct OwnedImage *VramAddr;
    u32 SMFlags;
    s16 BitsPerPixel;
    s16 Width;
    s16 Height;
    s16 NClutColors;
    u16 Flags;
    s16 TPage;
    s32 ImageOffset;
    s32 ClutOffset;
} _sm_texture_element;

/* One glyph of a font (8 bytes). */
typedef struct sm_char_info {
    u32 DataOffset;
    s8 Width;
    s8 Height;
    s8 PhysicalWidth;
    s8 BaselineOffset;
} sm_char_info;

/* One cached glyph image (44 bytes). */
typedef struct t_char {
    s32 __Unused;
    s32 CharTimer;
    u16 SMFlags;
    struct OwnedImage Vram;
} t_char;

/* One open font (0x49C bytes): its 96 glyphs, their cached images per clut and its font table entry. */
typedef struct _sm_font {
    s32 Active;
    sm_char_info CharInfo[96];
    u8 *CharBits[96];
    t_char **Char;
    u8 **Clut;
    ArchiveFontRecord *TableEntry;
    u8 NumInUse;
    struct ResourceRecAt6 FontTimer;
} _sm_font;

/* The resource file header (0x54 bytes): where each table sits in the file and how long it is. */
typedef struct t_res_header {
    s32 TextureTable;
    s32 TextureTableLen;
    s32 FontTable;
    s32 FontTableLen;
    s32 FontClutTable;
    s32 FontClutTableLen;
    s32 FontData;
    s32 FontDataLen;
    s32 LanguageTable;
    s32 LanguageTableLen;
    s32 StringTable;
    s32 StringTableLen;
    s32 ScreenTable;
    s32 ScreenTableLen;
    s32 ScreenData;
    s32 ScreenDataLen;
    s32 TextureData;
    s32 TextureDataLen;
    s32 CharData;
    s32 CharDataLen;
    s32 FirstScreen;
} t_res_header;

/* The open menu resource (D_801539B0, 0x2A8 bytes). */
typedef struct t_resource {
    s32 In;
    char Name[512];
    s32 Init;
    t_res_header Header;
    s16 NTextures;
    _sm_texture_element *Texture;
    u32 *ChromaKey;
    struct ResourceRecAt6 *TexTimer;
    struct OwnedImage *VramPool;
    s16 NFonts;
    ArchiveFontRecord *FontTable;
    _sm_font *Font;
    s16 NLanguages;
    ArchiveTextIndexEntry *LangTable;
    s32 CurrentLanguage;
    char *StringBuffer;
    char **StringTable;
    s16 NScreens;
    ArchiveMapEntry *Screen;
    ArchiveMapEntry *ScreenOriginal;
    s16 *ScreenFlags;
    s16 *RefCount;
    s32 NeverFreeResources;
} t_resource;

extern t_resource D_801539B0;

#ifndef NON_MATCHING
INCLUDE_ASM("ovl_80400000", func_8040F9E0_de);
#else
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
    Resmgr_ReadStream(archive->strings, size, 1, archive->handle);
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
#endif

/* Opens the menu archive NAME: reads its table of contents, then its image table (with a fresh image
   and load state per entry), its text index (loading section 0), its resource map (with copies when
   D_800E2AC4 is set) and its fonts with their bitmap pages and glyph rows; records the name and closes
   the file. */
void func_8040FB94_de(u8 *name) {
    t_resource *res;
    s32 handle;
    _sm_texture_element *texture;
    ArchiveFontRecord *entry;
    _sm_font *font;
    s32 *clutOffsets;
    s32 stride;
    s32 clut;
    s32 i;
    s32 n;
    s32 j;

    res = &D_801539B0;
    handle = Resmgr_OpenStream(name, &D_800DD0B0);
    res->In = handle;
    Resmgr_ReadStream(&D_801539B0.Header, sizeof(t_res_header), 1, handle);
    D_801539B0.NTextures = D_801539B0.Header.TextureTableLen / sizeof(_sm_texture_element);
    if (D_801539B0.NTextures > 0) {
        D_801539B0.VramPool = func_8025305C_de(D_801539B0.NTextures * sizeof(struct OwnedImage));
        D_801539B0.TexTimer = func_8025305C_de(D_801539B0.NTextures * sizeof(struct ResourceRecAt6));
        D_801539B0.ChromaKey = func_8025305C_de(D_801539B0.NTextures * sizeof(void *));
        texture = D_801539B0.Texture = func_8025305C_de(D_801539B0.Header.TextureTableLen);
        Resmgr_SeekStream(res->In, D_801539B0.Header.TextureTable, 0);
        Resmgr_ReadStream(texture, sizeof(_sm_texture_element), D_801539B0.NTextures, res->In);
        for (i = 0; i < D_801539B0.NTextures; i++, texture++) {
            texture->SMFlags = 0;
            texture->TPage = 0;
            D_801539B0.TexTimer[i].retained = 0;
            D_801539B0.TexTimer[i].id = 0;
            D_801539B0.Texture[i].VramAddr = &D_801539B0.VramPool[i];
            Gfx_ResetImage(&D_801539B0.VramPool[i]);
        }
    }
    D_801539B0.NLanguages = D_801539B0.Header.LanguageTableLen / sizeof(ArchiveTextIndexEntry);
    if (D_801539B0.NLanguages > 0) {
        D_801539B0.LangTable = func_8025305C_de(D_801539B0.Header.LanguageTableLen);
        Resmgr_SeekStream(res->In, D_801539B0.Header.LanguageTable, 0);
        Resmgr_ReadStream(D_801539B0.LangTable, D_801539B0.Header.LanguageTableLen, 1, res->In);
        func_8040F9E0_de(0);
    }
    D_801539B0.NScreens = D_801539B0.Header.ScreenTableLen / sizeof(ArchiveMapEntry);
    if (D_801539B0.NScreens > 0) {
        D_801539B0.Screen = func_8025305C_de(D_801539B0.Header.ScreenTableLen);
        if (D_800E2AC4 != 0) {
            D_801539B0.ScreenOriginal = func_8025305C_de(D_801539B0.Header.ScreenTableLen);
            func_802A0748_de(D_801539B0.ScreenOriginal, 0, D_801539B0.Header.ScreenTableLen);
        }
        Resmgr_SeekStream(res->In, D_801539B0.Header.ScreenTable, 0);
        Resmgr_ReadStream(D_801539B0.Screen, D_801539B0.Header.ScreenTableLen, 1, res->In);
        for (i = 0; i < D_801539B0.NScreens; i++) {
            D_801539B0.Screen[i].data = 0;
        }
        D_801539B0.RefCount = func_8025305C_de(D_801539B0.NScreens * sizeof(s16));
        func_802A0748_de(D_801539B0.RefCount, 0, D_801539B0.NScreens * sizeof(s16));
        D_801539B0.ScreenFlags = func_8025305C_de(D_801539B0.NScreens * sizeof(s16));
        func_802A0748_de(D_801539B0.ScreenFlags, 0, D_801539B0.NScreens * sizeof(s16));
    }
    if (D_801539B0.Header.FontTableLen > 0) {
        clutOffsets = func_8025305C_de(D_801539B0.Header.FontClutTableLen);
        Resmgr_SeekStream(res->In, D_801539B0.Header.FontClutTable, 0);
        Resmgr_ReadStream(clutOffsets, D_801539B0.Header.FontClutTableLen, 1, res->In);
        D_801539B0.FontTable = func_8025305C_de(D_801539B0.Header.FontTableLen);
        Resmgr_SeekStream(res->In, D_801539B0.Header.FontTable, 0);
        Resmgr_ReadStream(D_801539B0.FontTable, D_801539B0.Header.FontTableLen, 1, res->In);
        D_801539B0.NFonts = D_801539B0.Header.FontTableLen / sizeof(ArchiveFontRecord);
        D_801539B0.Font = func_8025305C_de(D_801539B0.NFonts * sizeof(_sm_font));
        func_802A0748_de(D_801539B0.Font, 0, D_801539B0.NFonts * sizeof(_sm_font));
        for (i = 0; i < D_801539B0.NFonts; i++) {
            D_801539B0.Font[i].TableEntry = &D_801539B0.FontTable[i];
        }
        clut = 0;
        for (n = 0; n < D_801539B0.NFonts; n++) {
            entry = D_801539B0.Font[n].TableEntry;
            font = &D_801539B0.Font[n];
            Resmgr_SeekStream(res->In, D_801539B0.Header.FontData + entry->glyphTableOffset, 0);
            Resmgr_ReadStream(font->CharInfo, 8, 0x60, res->In);
            font->Char = func_8025305C_de(entry->bitmapCount * sizeof(t_char *));
            font->Char[0] = func_8025305C_de(entry->bitmapCount * 96 * sizeof(t_char));
            func_802A0748_de(font->Char[0], 0, entry->bitmapCount * 96 * sizeof(t_char));
            for (j = 0; j < entry->bitmapCount; j++) {
                font->Char[j] = font->Char[0] + j * 96;
            }
            if (entry->bitmapCount > 0) {
                stride = (entry->glyphWidth * 2 + 7) & ~7;
                font->Clut = func_8025305C_de(entry->bitmapCount * sizeof(t_char *));
                font->Clut[0] = func_8025305C_de(entry->bitmapCount * stride);
                Resmgr_SeekStream(res->In, D_801539B0.Header.CharData + clutOffsets[clut], 0);
                Resmgr_ReadStream(font->Clut[0], entry->bitmapCount * stride, 1, res->In);
                for (j = 0; j < entry->bitmapCount; j++) {
                    font->Clut[j] = font->Clut[0] + j * stride;
                }
                clut += entry->bitmapCount + n - n; /* FAKEMATCH: the extra n terms give the font counter the allocation priority the ROM shows. */
            }
        }
        func_802547E4_de(clutOffsets);
    } else {
        D_801539B0.NFonts = 0;
    }
    D_801539B0.Init = 1;
    func_802A025C_de(D_801539B0.Name, name);
    D_801539B0.NeverFreeResources = 0;
    func_802A0EB0_de(D_801539B0.In);
    D_801539B0.In = 0;
}
