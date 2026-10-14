#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80412270.h"
#include "types.h"
typedef struct List List;
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
