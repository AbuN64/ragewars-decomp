#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/OBJECT1C8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_8.H"
#include "MENU/ITEMS/80442BC8_11.H"
#include "MENU/PAK/8043F69C_11.H"
#include "SYSTEM/80255C40_3.H"
#include "MENU/ITEMS/80442BC8_12.H"

/* 80442BC8_11.CPP */
/* Runs the optional callback at offset 0xC of an object's handler table at 0x14, then clears the
   words at offsets 0xB0, 0xB4 and 0xBC of the object at 0x20. */

void Items_InvokeHandlerAndClearItemState(struct ObjectRecAt20 *object) {
    struct StateRecAtBCV2 *state;

    if (object->handlers->callback != 0) {
        ((void (*)(struct ObjectRecAt20 *))object->handlers->callback)(object);
    }
    state = object->state;
    state->a = 0;
    state->b = 0;
    state->c = 0;
}

/* Allocates a block sized for the entries of a list through Cache_AllocateResource, builds it with Pak_InitializeMenu from four arguments, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from Pak_AllocateMenu with the list and all four values passed as arguments instead of read from a parameter block changed. */

extern void **Cache_AllocateResource(s32, s32, s32, char *);
extern char g_menuText[];

void *Items_CreateMenu(struct func_8025E5B0_S1 *owner, struct Dialog *list, s32 a, s32 b, s32 c, s32 d) {
    s32 size = list->count * 40 + 0x1D8;
    s32 i;
    void **block;
    void *first;

    for (i = 0; i < list->count; i++) {
        s32 extra = 0;
        if (list->entries[i].type == 3) {
            extra = 0x480;
        }
        size += extra;
    }
    block = Cache_AllocateResource(0, size, 0x3B, g_menuText);
    if (block == 0) {
        return 0;
    }
    first = *block;
    if (first == 0) {
        return 0;
    }
    Pak_InitializeMenu(first, block, list, a, b, c, d, owner);
    func_80255CB8_de(owner, first);
    if (++owner->unk14 >= 4) {
        owner->unk14 = 0;
    }
    return first;
}

/* Removes an item from a list: runs the item's optional callback at offset 0xC of its handler table
   with the item and the list, clears three words of its state at 0x20, unlinks it through
   func_80255ED8_de and releases its resource at offset 8 through Cache_ReleaseResource. */

void Items_DestroyMenu(void *list, struct ItemRecAt20V2 *item) {
    struct StateRecAtBCV2 *state;

    if (item->handlers->callback != 0) {
        item->handlers->callback(item, list);
    }
    state = item->state;
    state->a = 0;
    state->b = 0;
    state->c = 0;
    func_80255ED8_de(list, item);
    Cache_ReleaseResource(0, item->resource);
}

#if defined(VERSION_EU)
unsigned int func_8044334C_de_padding_1BA304[1] = {
    0x00000000,
};
#endif

/* 80442BC8_12.CPP */
#if defined(VERSION_US_REV1)
/* Does nothing. Nothing in the cartridge image calls it or stores its address as a word. */
void func_80443528_us_rev1(void) {
}
#endif
