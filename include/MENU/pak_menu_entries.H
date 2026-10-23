#ifndef MENU_PAK_MENU_ENTRIES_H
#define MENU_PAK_MENU_ENTRIES_H
#include "TYPES.H"
struct MenuRecAt10 {
    s16 cursor;
    char pad2[0xA];
    struct EntryRecAt18V2 *entries;
    s32 count;
};
#endif
