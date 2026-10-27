#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "MENU_2/STATE.H"
#include "TYPES.H"
#include "MATH/802A2870.H"

#if defined(VERSION_EU)
int Menu_ReturnZeroEuropean(void) {
    return 0;
}
#endif

#if defined(VERSION_DE)
int Menu_ReturnZeroGerman(void) {
    return 0;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_EU)
/* Processes a widget with clipping and drawing operations. */





extern s32 Frontend_ComputeWidgetBounds(struct Shape_typemap_165 *, struct Shape_typemap_165 *, void *, Args *);
extern void N64Eng_GetClipBounds(s32 *, s32 *, s32 *, s32 *);
extern s32 Frontend_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);
extern void Frontend_DrawVisibleSiblings(void *, Args);




void Menu_DrawClippedWidgetSiblings(void *widget, Args args) {
    func_802A2BE0_S1 *record = widget;
    struct Shape_typemap_165 first;
    struct Shape_typemap_165 basis;
    struct Shape_typemap_165 value;
    struct Shape_typemap_165 transformed;
    s32 changed;

    changed = 0;
    if (Frontend_ComputeWidgetBounds(&first, &basis, widget, &args) != 0) {
        if ((record->unk12 & 0x200) != 0) {
            N64Eng_GetClipBounds(&value.field_0, &value.field_8, &value.field_4, &value.field_C);
            transformed = value;
            Frontend_ClampRectToClip(&transformed, &basis);
            N64Eng_SetClipBounds(transformed.field_0, transformed.field_8, transformed.field_4, transformed.field_C);
            changed = 1;
        }
        Frontend_DrawVisibleSiblings(record->unk8, args);
        if (changed != 0) {
            N64Eng_SetClipBounds(value.field_0, value.field_8, value.field_4, value.field_C);
        }
    }
}
#endif
