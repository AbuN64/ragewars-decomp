#include "include_asm.h"
#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/INTEGERSTATE530.H"
#include "MENU_2/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MATH/802A2870.H"
#include "FRONTEND/8040B45C_35.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"
#include "RESMGR/resmgr_string_memory.H"

/* Allocates and zeroes a 0x118-byte record, copies the header and five-word block of the record Frontend_FindWidgetByResourceId finds for the low half of the first argument, links the record Frontend_FindWidgetByResourceId finds for the second into it, clears the words at 0x110 and 0x114, and registers it through func_8040EEA4_de and func_8040EF84_de. Adapted from SmpSlider_CreateSliderWidget with the record size 0x118, the tag 0xB64 and the tail fields changed. */










extern void *Frontend_GetScreenData(s32 index);
extern void Frontend_ReplaceNodeRefs(NodeRecAt44 *node, void *from, void *to);
extern MenuWidget *Frontend_FindWidgetByResourceId(void *root, s32 id);
extern void *Cache_AllocateMemory(s32 size);

/* Appends to a menu: passes the next free 20-byte entry at offset 0x48, selected by the count at
   0x114, to func_802A025C_de and increments the count. func_8041AD10_de selects an entry. */




extern u8 *XPlus_CopyString(u8 *, u8 *);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3400, an actor kind at D_800E3404 and a handler at D_800E3408: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */






/* Draws the child at 0x8 of window arg0 with the arguments passed by value once Frontend_ComputeWidgetBounds resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values N64Eng_GetClipBounds reports, narrows them by the resolved basis through func_8040F488_de and installs them through N64Eng_SetClipBounds around the draw, restoring the saved values after it. Adapted from N64Eng_DrawNumericWidgetChildren. */





extern s32 Frontend_ComputeWidgetBounds(QuadN64EngDrawNumericWidgetChildren *, QuadN64EngDrawNumericWidgetChildren *, void *, Args *);

extern void N64Eng_GetClipBounds(u32 *, u32 *, u32 *, u32 *);

extern s32 Frontend_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void Frontend_DrawVisibleSiblings(void *, Args);

/* When the fourth argument is one, advances a menu's selection at offset 0x110 to the next of its
   0x114 entries, wrapping to the first, points word 0x38 of its owner at 0x44 to the selected
   20-byte entry at 0x48 and plays sound 0xE81. Returns zero. */








/* When the fourth argument is one, moves a menu's selection at offset 0x110 to the previous of its
   0x114 entries, wrapping to the last, points word 0x38 of its owner at 0x44 to the selected 20-byte
   entry at 0x48 and plays sound 0xE81. Returns zero. */








/* Calls Cache_FreeMemory with the arguments it was given and returns zero. */


/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3460, an actor kind at D_800E3464 and a handler at D_800E3468: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */






/* Calls SoundElement_PlayFlatSound with 0xE74 and sets the byte at 0x10 of every child in the list at 0x8 of arg0 whose halfword at 0xE is not 8 to 100, returning zero. Adapted from N64Eng_SetLinkedCommand100WithSound with both stores to 0x5C and 0x48 removed. */



/* Releases the supplied object through Cache_FreeMemory and returns zero. */


MenuListWidget *SmpButton_CreateListWidget(s32 arg0, s32 arg1) {
    MenuListWidget *source;
    void *context;
    MenuListWidget *result;
    void *child;

    source = Frontend_FindWidgetByResourceId(Frontend_GetScreenData(GetMenuScreenOwner()), arg0 & 0xFFFF);
    context = Frontend_GetScreenData(GetMenuScreenOwner());
    result = Cache_AllocateMemory(0x118);
    XPlus_FillBytes(result, 0, 0x118);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB64;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    child = Frontend_FindWidgetByResourceId(context, arg1 & 0xFFFF);
    result->owner = child;
    result->index = 0;
    result->count = 0;
    Frontend_WrapNodeInParent(source, result);
    source->field_0C = -1;
    Frontend_ReplaceNodeRefs(context, source, result);
    return result;
}

/* Returns the word at offset 0x110 of a record. */
s32 SmpButton_GetListSelection(s32 *record) {
    return record[0x110 / 4];
}

/* Selects entry i of the 20-byte records at offset 0x48 of an object: records the index at 0x110
   and points word 0x38 of the object at 0x44 to that record. SmpButton_GetListSelection returns the index. */






void SmpButton_SelectListEntry(struct MenuListWidget *menu, s32 index) {
    menu->index = index;
    menu->owner->selected = &menu->entries[index];
}

void SmpButton_AppendListText(struct MenuListWidget *menu, u8 *text) {
    XPlus_CopyString(menu->entries[menu->count].text, text);
    menu->count++;
}

s32 SmpButton_DispatchListEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3408 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3408;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3400)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3404)) + offset))->field_0;
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

void SmpButton_DrawListWidget(Shared_Item *widget, Args args) {
    QuadN64EngDrawNumericWidgetChildren first;
    QuadN64EngDrawNumericWidgetChildren basis;
    QuadN64EngDrawNumericWidgetChildren value;
    QuadN64EngDrawNumericWidgetChildren transformed;
    s32 changed;

    changed = 0;
    if (Frontend_ComputeWidgetBounds(&first, &basis, widget, &args) != 0) {
        if ((widget->flags & 0x200) != 0) {
            N64Eng_GetClipBounds(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            Frontend_ClampRectToClip(&transformed, &basis);
            N64Eng_SetClipBounds(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        Frontend_DrawVisibleSiblings(widget->label, args);
        if (changed != 0) {
            N64Eng_SetClipBounds(value.x, value.z, value.y, value.w);
        }
    }
}

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 100. Returns zero. */




s32 SmpButton_DimListItems(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 100;
        }
    }
    return 0;
}

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 200. Returns zero. */




s32 SmpButton_HighlightListItems(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 200;
        }
    }
    return 0;
}

s32 SmpButton_DimListItemsWithSound(struct MenuRecAt54 *arg0) {
    struct ItemRecAt10 *p;

    SoundElement_PlayFlatSound(0xE74);
    p = arg0->items;
    if (p != 0) {
        do {
            if (p->kind != 8) {
                p->alpha = 0x64;
            }
            p = p->next;
        } while (p != 0);
    }
    return 0;
}

s32 SmpButton_SelectNextListEntry(struct MenuRecAt114 *menu, void *second, void *third, s32 active) {
    struct OwnerRecAt38 *owner;

    if (active == 1) {
        owner = menu->owner;
        if (++menu->index >= menu->count) {
            menu->index = 0;
        }
        owner->selected = &menu->entries[menu->index];
        SoundElement_PlayFlatSound(0xE81);
        return 0;
    }
    return 0;
}

s32 SmpButton_SelectPreviousListEntry(struct MenuRecAt114 *menu, void *second, void *third, s32 active) {
    struct OwnerRecAt38 *owner;

    if (active == 1) {
        owner = menu->owner;
        if (--menu->index < 0) {
            menu->index = menu->count - 1;
        }
        owner->selected = &menu->entries[menu->index];
        SoundElement_PlayFlatSound(0xE81);
        return 0;
    }
    return 0;
}

s32 SmpButton_DestroyListController(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}

void SmpButton_RegisterButtonClass(void) {
    SmSmngr_RegisterElementHandlers(0xB61, D_0041B340, D_0041B3D0, 3);
}

void SmpButton_WrapButtonWidget(s32 arg0) {
    RecordSmpButtonWrapButtonWidget *source;
    void *context;
    RecordSmpButtonWrapButtonWidget *result;

    source = Frontend_FindWidgetByResourceId(Frontend_GetScreenData(GetMenuScreenOwner()), arg0 & 0xFFFF);
    context = Frontend_GetScreenData(GetMenuScreenOwner());
    result = Cache_AllocateMemory(0x44);
    XPlus_FillBytes(result, 0, 0x44);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB61;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    Frontend_WrapNodeInParent(source, result);
    source->field_0C = -1;
    Frontend_ReplaceNodeRefs(context, source, result);
}

void SmpButton_EnsureButtonWrapper(RecordSmpButtonEnsureButtonWrapper *source) {
    void *context;
    RecordSmpButtonEnsureButtonWrapper *result;

    if (source->field_0E == 0xB61) {
        return;
    }
    context = Frontend_GetScreenData(GetMenuScreenOwner());
    result = Cache_AllocateMemory(0x44);
    XPlus_FillBytes(result, 0, 0x44);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB61;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    Frontend_WrapNodeInParent(source, result);
    source->field_0C = -1;
    Frontend_ReplaceNodeRefs(context, source, result);
}

s32 SmpButton_DispatchButtonEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3468 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3468;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3460)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3464)) + offset))->field_0;
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

void SmpButton_DrawButtonWidget(Shared_Item *widget, Args args) {
    QuadN64EngDrawNumericWidgetChildren first;
    QuadN64EngDrawNumericWidgetChildren basis;
    QuadN64EngDrawNumericWidgetChildren value;
    QuadN64EngDrawNumericWidgetChildren transformed;
    s32 changed;

    changed = 0;
    if (Frontend_ComputeWidgetBounds(&first, &basis, widget, &args) != 0) {
        if ((widget->flags & 0x200) != 0) {
            N64Eng_GetClipBounds(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            Frontend_ClampRectToClip(&transformed, &basis);
            N64Eng_SetClipBounds(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        Frontend_DrawVisibleSiblings(widget->label, args);
        if (changed != 0) {
            N64Eng_SetClipBounds(value.x, value.z, value.y, value.w);
        }
    }
}

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 100. Returns zero. */




s32 SmpButton_DimButtonItems(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 100;
        }
    }
    return 0;
}

/* Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 200. Returns zero. */




s32 SmpButton_HighlightButtonItems(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 200;
        }
    }
    return 0;
}

s32 SmpButton_DimButtonItemsWithSound(OwnerRecAt44 *arg0) {
    void *p;

    SoundElement_PlayFlatSound(0xE74);
    p = arg0->root;
    if (p != 0) {
        do {
            if ((u16)((NodeMenuCreateOverlayNode *)p)->kind != 8) {
                ((NodeMenuCreateOverlayNode *)p)->alpha = 0x64;
            }
            p = (NodeMenuCreateOverlayNode *)((NodeMenuCreateOverlayNode *)p)->words_00[1];
        } while (p != 0);
    }
    return 0;
}

int SmpButton_DestroyButtonController(void *object)
{
    Cache_FreeMemory(object);
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8041B65C[1] = {
    0x4D4F5645,
};
#endif

#if defined(VERSION_DE)
unsigned int func_8041B5BC_de_padding_1815DC[1] = {
    0x00000000,
};
#endif
