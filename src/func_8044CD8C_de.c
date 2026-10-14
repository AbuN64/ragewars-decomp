#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"

/* Loads every still-empty cell of the level's tile grid: for each row and column whose cell
   record has no resource, fetches the cell's block through func_8028FE3C_de and func_8025193C_de,
   binds and spawns each object of its two object lists (0xE8- and 0x1C8-byte records) and
   releases the spawned handles and the block. */











extern char D_0028798C[];
extern char D_800C5210_de[];

extern void func_8024F294_de(ObjB *obj, s32 arg1);
extern void *func_8024F6EC_de(ObjB *obj, s32 type);
extern void func_802509A8_de(ObjA *obj, s32 arg1);
extern void *func_802507AC_de(ObjA *obj, s32 type);
extern void **func_8025193C_de(s32, s32, s32, s32, s32, Level_func_8044CD8C_de *, void *, void *, s32);
extern void func_80253754_de(s32, void *);
extern void func_8026E158_de(void *handle);
extern void *func_8028FDB4_de(void *node, s32 index);
extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);




void func_8044CD8C_de(Level_func_8044CD8C_de *level) {
    s32 size;
    s32 width;
    s32 row;
    s32 lastCol;
    s32 lastRow;
    s32 rows;
    DraftStreamCell *cells;
    DraftStreamCell *cell;
    s32 col;
    s32 first;
    s32 key;
    void **block;
    void *node;
    ResourceManagerState *list;
    s32 i;
    s32 n;
    s32 m;
    ObjA *a;
    ObjA *objsA;
    ObjB *objsB;
    ObjB *b;
    void *handle;

    width = ((ResourceManagerState *) func_8028FDB4_de(level->grid, 0))->count;
    row = 0;
    rows = ((ResourceManagerState *) func_8028FDB4_de(level->grid, 2))->count;
    cells = (DraftStreamCell *) ((ResourceManagerState *) func_8028FDB4_de(level->grid, 4) + 1);
    lastRow = rows - 1;
    lastCol = width - 1;
    /* FAKEMATCH: constant-holding local first keeps the column loop's entry test as slt */
    first = 0;
    for (; row <= lastRow; row++) {
        for (col = first; col <= lastCol; col++) {
            cell = &cells[col + row * width];
            if (cell->occupied != 0) {
                continue;
            }
            key = func_8028FE3C_de(level->file, level->key, col + row * width, &size);
            block = func_8025193C_de(0, key, key, size, 4, level, D_0028798C, D_800C5210_de, 1);
            if (block == 0) {
                continue;
            }
            node = *block;
            if (*(s32 *) node != 0) {
                list = func_8028FDB4_de(node, 0);
                n = list->count;
                objsA = (ObjA *) (list + 1);
                for (i = 0; i < n; i++) {
                    a = &objsA[i];
                    a->block = block;
                    func_802509A8_de(a, 0);
                    handle = func_802507AC_de(a, a->type);
                    if (handle != 0) {
                        func_8026E158_de(handle);
                        func_80253754_de(0, handle);
                    }
                }
                list = func_8028FDB4_de(node, 1);
                m = list->count;
                objsB = (ObjB *) (list + 1);
                for (i = 0; i < m; i++) {
                    b = &objsB[i];
                    b->block = block;
                    func_8024F294_de(b, 0);
                    handle = func_8024F6EC_de(b, b->type);
                    if (handle != 0) {
                        func_8026E158_de(handle);
                        func_80253754_de(0, handle);
                    }
                }
            }
            func_80253754_de(0, block);
        }
    }
}

/* Runs func_8044D054_de and func_8044D0F0_de on a large state block, then clears its word at offset
   0x1B444, sets the word at 0x1B448 to 0x15 and copies D_801462CC into the word at 0x1B44C. */

extern struct Shape_func_8021A2D4_de_2 D_801462CC;
extern void func_8044D054_de(char *);
extern void func_8044D0F0_de(char *);




void func_8044CFF8_de(char *state) {
    func_8044D054_de(state);
    func_8044D0F0_de(state);
    ((Shared_World *)state)->previewState = 0;
    ((Shared_World *)state)->previewTimer = 0x15;
    ((Shared_World *)state)->previewStart = D_801462CC.field_0;
}
