#ifndef RW_PAK_MENU_H
#define RW_PAK_MENU_H
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
/* Controller Pak menu items are 0x28-byte records. */
struct PakNotesMenuItem {
    char pad0[8];
    u32 flags;
    char padC[0x1C];
};
/* Shared menu passed to note enumeration and note selection callbacks. */
typedef struct Shared_PakMenu {
    s16 state;
    char pad02[0xA];
    struct PakNotesMenuItem *items;
    char pad10[4];
    char *dialogData;
    char pad18[4];
    ObjRecAt5DC *player;
    union {
        func_80242278_S1 *owner;
        func_80242278_S1 *slot;
    };
} Shared_PakMenu;
void func_80405F48_de(Shared_PakMenu *menu);
#endif
