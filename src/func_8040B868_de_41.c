#include "span_16E000/code_8040B45C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_80411B68.h"
#include "span_16E000/code_80412270.h"
#include "types.h"

/* Releases the buffers of the pool at D_80153C40: every entry holding a buffer that is not locked
   (flag 1) unless force is set has its reference count forced to one and dropped, and when it
   reaches zero the buffer is freed through func_802547E4_de, along with the entry's secondary buffer
   when secondary buffers are in use (D_800E2AC4), and the entry is cleared. Pool fields read as one struct at D_80153C40, as in func_80410E1C_de. */







extern s32 D_800E2AC4;

extern void func_802547E4_de(void *buffer);

/* Returns the halfword held in D_80153C40. */


/* Returns the halfword held in D_80153C0C. */
extern s16 D_80153C0C;

/* Returns the halfword held in D_80153C20. */


/* Returns the halfword at offset 0xA of entry i in the 28-byte record table D_80153C10 points
   to; func_80411A84_de and func_80411AA8_de read offsets 0xA and 0xC. */




/* Returns the halfword at offset 0xC of entry i in the 28-byte record table D_80153C10 points
   to; func_80411A84_de and func_80411AA8_de read offsets 0xA and 0xC. */




/* Returns entry i of the word array D_80153C14 points to. */
extern s32 *D_80153C14;

/* Releases UI resource slot i once its retain count reaches zero, closing its open entry and clearing the slot id. */






extern struct ResourceRecAt6 *D_8014D988;

extern void func_80419624_de(s32);

/* Returns the signed byte at offset 0x9 of entry j in the 8-byte entries that begin record i of
   the 1180-byte record table D_80153C28 points to. */


/* Returns the signed byte at offset 0xA of entry j in the 8-byte entries that begin record i of
   the 1180-byte record table D_80153C28 points to. */


/* Returns the halfword at offset 0xE of the object held at offset 0x48C of record i in the
   1180-byte record table D_80153C28 points to; func_80411C60_de reads offset 0x10 of the same
   object. */


/* Runs func_80411518_de for each of the manager D_80153C20's entries unless its mode word at 0x34 is 1. */




/* The debugger showed this global holding 0x80698160, a heap address rather than a static one,
   so it is a pointer variable and not an array base. The returned words were 0x8069A52F and
   0x8069A673, which are guest addresses that are not word aligned, so the element type is a
   pointer to bytes. */
extern char **D_8014D9AC;

/* Calls func_8040F9E0_de when the halfword D_80153C2C is non-zero. */

extern void func_8040F9E0_de();

/* Twelve bytes of stride and a load at offset 8. The debugger showed the global holding
   0x80697F80 and the results being 0, 0x8067E570, 0x8067F870 and 0x80697E00, so the third word is
   a pointer that may be absent. The largest index seen was 0x1D, which is inside the bound of 36
   that func_80411DF0_de checks against D_80153C40, so this is an accessor over the same table. */
extern struct EntryRecAt8V2 {
    s32 unk_0;
    s32 unk_4;
    void *unk_8;
} *D_8014D9B4;

/* Returns whether an index lies inside the table bound D_80153C40, from zero up to but not
   including it. */


/* Drops one reference to buffer pool entry i and, when none remain, frees its primary and secondary buffers and clears the entry. */







/* Clears the 0x2A8-byte block D_801539B0 through func_802A0748_de, sets D_800E2AC0 and clears
   D_800E2AC4. */
extern char D_801539B0[];

extern s32 D_800E2AC0;

extern void func_802A0748_de(void *, s32, s32);

/* Sets the buffer pool flag, then runs func_804116CC_de on every buffer pool entry, func_80410674_de in mode 2 on every resource slot and func_80410F54_de on every chunk. */





extern void func_804116CC_de(s32 index);

extern void func_80410F54_de(s32 arg0, s32 index, s32 arg2);

/* A stride of 1180 bytes. The debugger showed the global holding 0x80696F50 and the two observed
   indices, 0 and 1, returning 0x80696F50 and 0x806973EC, which differ by exactly 1180. */




extern void func_80411AF0_de(s32 i);

/* Loads or unloads the images of a widget subtree: visits the later siblings when asked and the
   children, then for an image widget (type 3) loads its image through func_80410674_de or unloads it
   through func_80411AF0_de, and for a button (type 8) visits its normal, pressed and highlighted
   variants without their siblings; type 4 widgets and other types have nothing to do. */





typedef struct List List;

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E2AD0, an actor kind at D_800E2AD4 and a handler at D_800E2AD8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E2AD0;

extern s32 D_800E2AD4;

extern Handler802A2B50 D_800E2AD8;

void func_804118E4_de(s32 force) {
    extern BufferPool D_80153C40;
    s32 i;

    for (i = 0; i < D_80153C40.count; i++) {
        if (D_80153C40.primary[i].unk8 != 0 && (!(D_80153C40.flags[i] & 1) || force != 0)) {
            D_80153C40.refs[i] = 1;
            D_80153C40.refs[i]--;
            if (D_80153C40.primary[i].unk8 != 0 && D_80153C40.refs[i] == 0) {
                func_802547E4_de(D_80153C40.primary[i].unk8);
                if (D_800E2AC4 != 0 && D_80153C40.secondary != 0 &&
                    D_80153C40.secondary[i].unk8 != 0) {
                    func_802547E4_de(D_80153C40.secondary[i].unk8);
                }
                D_80153C40.primary[i].unk8 = 0;
            }
        }
    }
}

/** Perform no work. */
void func_80411A3C_de(void) {
}

s16 func_80411A44_de(void) {
    extern s16 D_80153C40;
    return D_80153C40;
}

s16 func_80411A54_de(void) {
    return D_80153C0C;
}

s16 func_80411A64_de(void) {
    extern s16 D_80153C20;
    return D_80153C20;
}

/* Returns the word held in D_80153C08. */


s32 func_80411A74_de(void) {
    return D_80153C08;
}

s16 func_80411A84_de(s32 index) {
    extern struct RecordRecAtCV4 *D_80153C10;
    return D_80153C10[index].a;
}

s16 func_80411AA8_de(s32 index) {
    extern struct RecordRecAtCV4 *D_80153C10;
    return D_80153C10[index].c;
}

s32 func_80411ACC_de(s32 index) {
    return D_80153C14[index];
}

/** Report success. */
int func_80411AE8_de(void) {
    return 1;
}

void func_80411AF0_de(s32 i) {
    extern struct EntryRecAt8V1 *D_80153C10;
    struct ResourceRecAt6 *resource;

    resource = (struct ResourceRecAt6 *)(i * 8 + (s32)D_8014D988);
    if (resource->id != -1) {
        if (resource->retained > 0) {
            resource->retained--;
        } else {
            if (D_80153C10[i].flags & 1) {
                func_80419624_de(D_80153C10[i].unused);
                D_80153C10[i].flags &= ~1;
            }
            D_8014D988[i].id = 0;
        }
    }
}

signed char func_80411BA8_de(int entry, int index) {
    extern char *D_80153C28;
    char *record = D_80153C28 + index * 1180;
    int size;

    return ((struct ObjectStateA *) ((D_80153C28 + (index * 1180)) + (((unsigned char) entry) * (size = 8))))->unk_9;
}

signed char func_80411BE8_de(int entry, int index) {
    extern char *D_80153C28;
    char *record = D_80153C28 + index * 1180;
    int size;

    return ((struct ObjectStateB *) ((D_80153C28 + (index * 1180)) + (((unsigned char) entry) * (size = 8))))->unk_A;
}

short func_80411C28_de(int index) {
    extern char *D_80153C28;
    return ((struct ObjRecAtE *) ((struct ObjectLinks490 *) (D_80153C28 + (index * 1180)))->unk_48C)->unkE;
}

short func_80411C60_de(int index) {
    extern char *D_80153C28;
    return ((struct OSThread_s *) ((struct ObjectLinks490 *) (D_80153C28 + (index * 1180)))->unk_48C)->state;
}

short func_80411C98_de(int index) {
    extern char *D_80153C28;
    return ((struct ObjRecAtA *) ((struct ObjectLinks490 *) (D_80153C28 + (index * 1180)))->unk_48C)->unkA;
}

short func_80411CD0_de(int index) {
    extern char *D_80153C28;
    return ((struct ObjRecAtCV1 *) ((struct ObjectLinks490 *) (D_80153C28 + (index * 1180)))->unk_48C)->unkC;
}

/** Report success. */
int func_80411D08_de(void) {
    return 1;
}

/** Report success. */
int func_80411D10_de(void) {
    return 1;
}

void func_80411D18_de(void) {
    extern Manager_func_80411D18_de D_80153C20;
    int i;

    if (D_80153C20.mode != 1) {
        for (i = 0; i < D_80153C20.count; i++) {
            func_80411518_de(i);
        }
    }
}

char *func_80411D78_de(s32 index) {
    return D_8014D9AC[index];
}

/* Returns the halfword held in D_80153C2C. */


s16 func_80411D94_de(void) {
    return D_80153C2C;
}

void func_80411DA4_de(void) {
    if (D_80153C2C != 0) {
        func_8040F9E0_de();
    }
}

void *func_80411DCC_de(s32 index) {
    return D_8014D9B4[index].unk_8;
}

s32 func_80411DF0_de(s32 index) {
    extern s16 D_80153C40;
    if (index >= 0 && index < D_80153C40) {
        return 1;
    }
    return 0;
}

void func_80411E18_de(s32 i) {
    extern BufferPool D_80153C40;
    D_80153C40.refs[i]--;
    if (D_80153C40.primary[i].unk8 != 0 && D_80153C40.refs[i] == 0) {
        func_802547E4_de(D_80153C40.primary[i].unk8);
        if (D_800E2AC4 != 0 && D_80153C40.secondary != 0 &&
            D_80153C40.secondary[i].unk8 != 0) {
            func_802547E4_de(D_80153C40.secondary[i].unk8);
        }
        D_80153C40.primary[i].unk8 = 0;
    }
}

void func_80411EEC_de(void) {
    func_802A0748_de(D_801539B0, 0, 0x2A8);
    D_800E2AC0 = 1;
    D_800E2AC4 = 0;
}

void func_80411F28_de(void) {
    D_800E2AC0 = 0;
}

void func_80411F38_de(s32 value) {
    D_800E2AC4 = value;
}

void func_80411F48_de(void) {
    extern void func_80410674_de(s32 index, s32 mode);
    extern BufferPool D_80153C40;
    extern s16 D_80153C20;
    s32 i;

    D_80153C40.dirty = 1;
    for (i = 0; i < D_80153C40.count; i++) {
        func_804116CC_de(i);
    }
    for (i = 0; i < D_80153C0C; i++) {
        func_80410674_de(i, 2);
    }
    for (i = 0; i < D_80153C20; i++) {
        func_80410F54_de(0, i, 0);
    }
}

GlyphBuffer *func_8041200C_de(s32 index) {
    extern GlyphBuffer *D_80153C28;
    return &D_80153C28[index];
}

void func_80412038_de(void) {
    extern struct EntryRecAt8V1 *D_80153C10;
    s32 i;
    s32 invalid;
    s32 offset;
    struct ResourceRecAt6 *resource;

    i = 0;
    if (D_80153C0C > 0) {
        invalid = -1;
        offset = 0;
        do {
            if (((struct EntryRecAt8V1 *)(offset + (s32)D_80153C10))->flags & 1) {
                resource = D_8014D988 + i;
                if (resource->id != invalid && resource->retained == 0) {
                    func_80411AF0_de(i);
                }
            }
            offset += 0x1C;
        } while (++i < D_80153C0C);
    }
}

void func_804120DC_de(WidgetRecAt34 *widget, s32 load, s32 siblings) {
    extern void func_80410674_de(WidgetRecAt34 *image, s32 mode);
    if (widget == 0) {
        return;
    }
    if (widget->next != 0 && siblings != 0) {
        func_804120DC_de(widget->next, load, siblings);
    }
    if (widget->child != 0) {
        func_804120DC_de(widget->child, load, siblings);
    }
    switch (widget->type) {
        case 4:
            break;
        case 3:
            if (load != 0) {
                func_80410674_de(widget->normal, 3);
            } else {
                func_80411AF0_de(widget->normal);
            }
            break;
        case 8:
            if (widget->normal != 0) {
                func_804120DC_de(widget->normal, load, 0);
            }
            if (widget->pressed != 0) {
                func_804120DC_de(widget->pressed, load, 0);
            }
            if (widget->highlighted != 0) {
                func_804120DC_de(widget->highlighted, load, 0);
            }
            break;
    }
}

/* Clamps a list's two cursor coordinates into their [min, max] ranges and scrolls each view offset so the cursor stays inside the visible window. */



void func_804121F0_de(List *list) {
    if (list->maxY < list->cursorY) {
        list->cursorY = list->maxY;
    }
    if (list->maxX < list->cursorX) {
        list->cursorX = list->maxX;
    }
    if (list->cursorY < list->minY) {
        list->cursorY = list->minY;
    }
    if (list->cursorX < list->minX) {
        list->cursorX = list->minX;
    }
    if (list->cursorY - list->scrollY >= list->visibleY - list->minY) {
        list->scrollY = list->cursorY - (list->visibleY - list->minY) + 1;
    }
    if (list->cursorX - list->scrollX >= list->visibleX - list->minX) {
        list->scrollX = list->cursorX - (list->visibleX - list->minX) + 1;
    }
    if (list->cursorY < list->scrollY) {
        list->scrollY = list->cursorY;
    }
    if (list->cursorX < list->scrollX) {
        list->scrollX = list->cursorX;
    }
}

/* Lays out cell (row, col) of a scrolling table: copies the table's cell template, picks the header
   colours for header rows and columns and the body colours otherwise (mapping body positions past
   the headers onto the scrolled contents), offsets the cell by the widths and heights of the
   columns and rows before it (repeating the last header size beyond the headers), sets its size
   from its own column and row, points it at the content entry and gives the selected entry its
   highlight colours. */







void func_804122CC_de(ScrollTable *table, CellCode8040B45C *cell, u32 row, u32 col) {
    s32 lastCol;
    s32 lastRow;
    u32 entryCol;
    u32 entryRow;
    s32 x;
    s32 y;
    s32 n;
    s32 i;

    cell->layout = table->layout;
    cell->fg = table->fg;
    cell->bg = table->bg;
    if (col < table->headerCols) {
        entryCol = col;
        cell->fg = table->headerFg;
        cell->bg = table->headerBg;
        lastCol = -1;
        if (col != 0) {
            lastCol = col - 1;
        }
    } else {
        lastCol = -1;
        entryCol = col - table->headerCols + table->colScroll;
        if (table->headerCols != 0) {
            lastCol = col;
        }
    }
    if (row < table->headerRows) {
        entryRow = row;
        cell->fg = table->headerFg;
        cell->bg = table->headerBg;
        lastRow = -1;
        if (row != 0) {
            lastRow = row - 1;
        }
    } else {
        lastRow = -1;
        entryRow = row - table->headerRows + table->rowScroll;
        if (table->headerRows != 0) {
            lastRow = row;
        }
    }
    x = 0;
    y = 0;
    n = lastCol;
    if (table->headerCols < lastCol) {
        n = table->headerCols;
    }
    if (lastCol != -1) {
        for (i = 0; i < n; i++) {
            x += table->widths[i];
        }
    }
    n = lastRow;
    if (table->headerRows < lastRow) {
        n = table->headerRows;
    }
    if (lastRow != -1) {
        for (i = 0; i < n; i++) {
            y += table->heights[i];
        }
    }
    if (table->headerCols < lastCol) {
        x += (lastCol - table->headerCols) * table->widths[table->headerCols - 1];
    }
    if (table->headerRows < lastRow) {
        y += (lastRow - table->headerRows) * table->heights[table->headerRows - 1];
    }
    if (col < table->headerCols) {
        cell->layout.width = table->widths[col];
    } else {
        cell->layout.width = table->widths[table->headerCols - 1];
    }
    if (row < table->headerRows) {
        cell->layout.height = table->heights[row];
    } else {
        cell->layout.height = table->heights[table->headerRows - 1];
    }
    cell->content = table->contents[(entryRow * table->columns + entryCol) * 2];
    if (entryRow == table->selectedRow && entryCol == table->selectedCol) {
        cell->selectedFg = table->selectedFg;
        cell->selectedBg = table->selectedBg;
    } else {
        cell->selectedFg = cell->fg;
        cell->selectedBg = cell->bg;
    }
    cell->layout.x += x;
    cell->layout.y += y;
}

s32 func_804125A4_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E2AD8 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E2AD8;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E2AD0)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E2AD4)) + offset))->field_0;
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
