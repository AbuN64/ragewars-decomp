#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/OBJECT1C8.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/CACHE_RELEASERESOURCE.H"
#include "MENU/ITEMS/ITEMS_INVOKEHANDLERANDCLEARITEMSTATE.H"
#include "MENU/PAK/MENU_INITIALIZEMENU.H"
#include "SYSTEM/LIST.H"
#include "MENU/ITEMS/ITEMS_CREATEMENU.H"

/* 80442BC8_11.CPP */
/* Runs the optional callback at offset 0xC of an object's handler table at 0x14, then clears the
   words at offsets 0xB0, 0xB4 and 0xBC of the object at 0x20. */

void Items_InvokeHandlerAndClearItemState(struct MenuItemCallbackAndStateView *object) {
    struct MenuItemInputStateView *state;

    if (object->handlers->callback != 0) {
        ((void (*)(struct MenuItemCallbackAndStateView *))object->handlers->callback)(object);
    }
    state = object->state;
    state->a = 0;
    state->b = 0;
    state->c = 0;
}

/* Allocates a block sized for the entries of a list through Cache_AllocateResource, builds it with Menu_InitializeMenu from four arguments, registers it with List_PrependIntrusive and advances the owner's rotating counter below four, returning the block or zero. Adapted from Menu_AllocateMenu with the list and all four values passed as arguments instead of read from a parameter block changed. */

extern void **Cache_AllocateResource(s32, s32, s32, char *);
extern char g_menuText[];

void *Items_CreateMenu(struct MenuCreationOwnerView *owner, struct Dialog *list, s32 a, s32 b, s32 c, s32 d) {
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
    Menu_InitializeMenu(first, block, list, a, b, c, d, owner);
    List_PrependIntrusive(owner, first);
    if (++owner->menuFlags >= 4) {
        owner->menuFlags = 0;
    }
    return first;
}

/* Removes an item from a list: runs the item's optional callback at offset 0xC of its handler table
   with the item and the list, clears three words of its state at 0x20, unlinks it through
   List_RemoveIntrusive and releases its resource at offset 8 through Cache_ReleaseResource. */

void Items_DestroyMenu(void *list, struct MenuResourceItemView *item) {
    struct MenuItemInputStateView *state;

    if (item->handlers->callback != 0) {
        item->handlers->callback(item, list);
    }
    state = item->state;
    state->a = 0;
    state->b = 0;
    state->c = 0;
    List_RemoveIntrusive(list, item);
    Cache_ReleaseResource(0, item->resource);
}

#if defined(VERSION_EU)
unsigned int g_itemsMenuTextPadding[3] = {
    0x00000000, 0x24040001, 0x03E00008,
};
#endif

/* 80442BC8_12.CPP */
#if defined(VERSION_US_REV1)
/* Does nothing. Nothing in the cartridge image calls it or stores its address as a word. */
void Items_MenuCreationNoOpUsRevisionOne(void) {
}
#endif
