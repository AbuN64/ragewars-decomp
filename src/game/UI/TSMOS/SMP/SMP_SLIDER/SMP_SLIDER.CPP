#include "COMMON/FRUSTUM.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/SLOTRECATCV1.H"
#include "MENU/SCROLL.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU/804196C0_21.H"
#include "MATH/802A2870.H"
#include "FRONTEND/8040B45C_35.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "SCENE/CACHE_FREEMEMORY.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"

/* Stores a mode at offset 0x58 of an object and plays sound 0xE77 for mode 1 or 0xE76 for mode 2
   through SoundElement_PlayFlatSound. */



/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3360, an actor kind at D_800E3364 and a handler at D_800E3368: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */






/* Calls Cache_FreeMemory with the arguments it was given and returns zero. */

/* Allocates and zeroes a 0x58-byte record, copies the header and five-word block of the record Node_FindWidgetByResourceId finds for the low half of the first argument, links the record Node_FindWidgetByResourceId finds for the second into it with its halfword at 0x18, stores the third argument, and registers it through func_8040EEA4_de and func_8040EF84_de.
   Adapted from N64Eng_CreateNumericWidget with the record size, tag 0xB63, the tail fields and the dropped N64Eng_SetNumericWidgetValue call changed. */












extern MenuSliderWidget *Cache_AllocateMemory(s32);



extern void Node_ReplaceNodeRefs(s32 arg0, MenuSliderWidget *arg1, MenuSliderWidget *arg2);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E3390, an actor kind at D_800E3394 and a handler at D_800E3398: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */






/* Draws the child at 0x8 of window arg0 with the arguments passed by value once Widget_ComputeWidgetBounds resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values N64Eng_GetClipBounds reports, narrows them by the resolved basis through func_8040F488_de and installs them through N64Eng_SetClipBounds around the draw, restoring the saved values after it. Adapted from N64Eng_DrawNumericWidgetChildren. */





extern s32 Widget_ComputeWidgetBounds(QuadN64EngDrawNumericWidgetChildren *, QuadN64EngDrawNumericWidgetChildren *, void *, Args *);

extern void N64Eng_GetClipBounds(u32 *, u32 *, u32 *, u32 *);

extern s32 Node_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void Widget_DrawVisibleSiblings(void *, Args);

/* Scrolls up: moves a scroll bar to the previous item through SmpSlider_SetSliderItem unless it is already
   at the first. */


extern void SmpSlider_SetSliderItem(struct Scroll *, s32);

void SmpSlider_SetTransitionMode(struct func_8022FD9C_S4 *object, s32 mode) {
    object->modeState = mode;
    switch (mode) {
    case 1:
        SoundElement_PlayFlatSound(0xE77);
        break;
    case 2:
        SoundElement_PlayFlatSound(0xE76);
        break;
    }
}

/* Returns the word at offset 0x58 of a record. */
s32 SmpSlider_GetTransitionMode(s32 *record) {
    return record[0x58 / 4];
}

/* Sets the flag word at offset 0x5C that SmpSlider_DisableTransition clears. */


void SmpSlider_EnableTransition(struct Access_s32_5C *object) {
    object->field = 1;
}

/* Clears the flag word at offset 0x5C that SmpSlider_EnableTransition sets to one. Frontend_InitPlayModeMenu calls it on
   the object SmpFade_CreateFadeWidget has just returned. */


void SmpSlider_DisableTransition(struct Access_s32_5C *object) {
    object->field = 0;
}

s32 SmpSlider_DispatchTransitionEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3368 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3368;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3360)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3364)) + offset))->field_0;
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

/* A disabled debug print: takes a target, a format and variable arguments and does nothing beyond
   spilling the variable arguments to their home slots. Matched like the variadic stub Events_IgnoreEvent:
   the leftover float test of its compiled-out body makes the compiler fill the return delay slot
   with the last argument spill. */
void SmpSlider_IgnoreFormattedMessage(void *target, const char *format, ...)
{
    float enabled;

    enabled = 1.0f;
    if (enabled) {
    }
}

s32 SmpSlider_DestroyController(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}

void SmpSlider_RegisterSliderClass(void) {
    SmSmngr_RegisterElementHandlers(0xB63, D_0041A724, D_0041A7B4, 3);
}

MenuSliderWidget *SmpSlider_CreateSliderWidget(s32 arg0, s32 arg1, s32 arg2) {
    MenuSliderWidget *source;
    s32 context;
    MenuSliderWidget *result;
    MenuSliderWidget *child;

    source = Node_FindWidgetByResourceId(Node_GetScreenData(GetMenuScreenOwner()), arg0 & 0xFFFF);
    context = Node_GetScreenData(GetMenuScreenOwner());
    result = Cache_AllocateMemory(0x58);
    XPlus_FillBytes(result, 0, 0x58);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB63;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    child = Node_FindWidgetByResourceId((void*)context, arg1 & 0xFFFF);
    result->field_44 = child;
    result->field_48 = child->field_18;
    result->field_4C = arg2;
    result->field_50 = 0;
    result->field_54 = 2;
    Node_WrapNodeInParent(source, result);
    source->field_0C = -1;
    Node_ReplaceNodeRefs(context, source, result);
    return result;
}

/* Returns the word at offset 0x50 of a record. */
s32 SmpSlider_GetSliderItem(s32 *record) {
    return record[0x50 / 4];
}

/* Positions a scroll bar: records the current item at offset 0x50 and stores in the halfword at
   0x18 of the bar object at 0x44 the item scaled from the item count at 0x4C to the track
   length at 0x48. */




void SmpSlider_SetSliderItem(struct Scroll *scroll, s32 item) {
    scroll->item = item;
    scroll->bar->field18 = (f32) item / (f32) scroll->count * (f32) scroll->length;
}

s32 SmpSlider_DispatchSliderEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3398 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3398;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E3390)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3394)) + offset))->field_0;
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

void SmpSlider_DrawSliderWidget(void *widget, Args args) {
    QuadN64EngDrawNumericWidgetChildren first;
    QuadN64EngDrawNumericWidgetChildren basis;
    QuadN64EngDrawNumericWidgetChildren value;
    QuadN64EngDrawNumericWidgetChildren transformed;
    s32 changed;
    UiWidget *window = widget;

    changed = 0;
    if (Widget_ComputeWidgetBounds(&first, &basis, widget, &args) != 0) {
        if ((window->flags & 0x200) != 0) {
            N64Eng_GetClipBounds(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            Node_ClampRectToClip(&transformed, &basis);
            N64Eng_SetClipBounds(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        Widget_DrawVisibleSiblings(window->children, args);
        if (changed != 0) {
            N64Eng_SetClipBounds(value.x, value.z, value.y, value.w);
        }
    }
}

void SmpSlider_DecrementSliderItem(struct Scroll *scroll) {
    if (scroll->item > 0) {
        SmpSlider_SetSliderItem(scroll, scroll->item - 1);
    }
}

void SmpSlider_IncrementSliderItem(struct Scroll *scroll) {
    if (scroll->item < scroll->count) {
        SmpSlider_SetSliderItem(scroll, scroll->item + 1);
    }
}

/* sets the menu's state word at 0x54 to 2 and Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 100. Returns zero. */




s32 SmpSlider_DimSliderItems(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    menu->state = 2;
    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 100;
        }
    }
    return 0;
}

/* sets the menu's state word at 0x54 to 2 and Walks the item list at offset 8 of a menu and sets the byte at offset 0x10 of every item
   whose kind at 0xE is not 8 to 200. Returns zero. */




s32 SmpSlider_HighlightSliderItems(struct MenuRecAt54 *menu) {
    struct ItemRecAt10 *item;

    menu->state = 2;
    for (item = menu->items; item != 0; item = item->next) {
        if (item->kind != 8) {
            item->alpha = 200;
        }
    }
    return 0;
}
