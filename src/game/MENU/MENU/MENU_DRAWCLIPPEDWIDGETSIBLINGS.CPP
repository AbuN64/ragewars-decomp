#include "include_asm.h"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "SCENE/CACHE_FREEMEMORY.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "MENU/STATE.H"
#include "TYPES.H"
#include "MATH/N64_ENG.H"

/* 80408AC4_14.CPP */
#if defined(VERSION_DE)
unsigned char g_MenuDrawclippedwidgetsiblingsTrailingBytes[4] = { 0xD0, 0x14, 0x9C, 0x2C };
#endif

/* 80406A88_8.CPP */
#if defined(VERSION_EU_X)
extern void Node_LoadLanguageStringsIfAny(int);
extern void *g_optionsPage;

int Menu_DestroyEuxOptionsAndReloadLanguage(void *allocation) {
    Cache_FreeMemory(allocation);
    g_optionsPage = 0;
    Node_LoadLanguageStringsIfAny(g_languageIndex);
    return 0;
}
#endif

/* 80408CB0_13.CPP */
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

extern s32 Widget_ComputeWidgetBounds(struct CacheResourceBlockView *, struct CacheResourceBlockView *, void *, Args *);
extern void N64Eng_GetClipBounds(s32 *, s32 *, s32 *, s32 *);
extern s32 Node_ClampRectToClip(struct CacheResourceBlockView *rect, struct CacheResourceBlockView *clip);
extern void Widget_DrawVisibleSiblings(void *, Args);

void Menu_DrawClippedWidgetSiblings(void *widget, Args args) {
    NumericWidgetChildView *record = widget;
    struct CacheResourceBlockView first;
    struct CacheResourceBlockView basis;
    struct CacheResourceBlockView value;
    struct CacheResourceBlockView transformed;
    s32 changed;

    changed = 0;
    if (Widget_ComputeWidgetBounds(&first, &basis, widget, &args) != 0) {
        if ((record->flags & 0x200) != 0) {
            N64Eng_GetClipBounds(&value.first, &value.third, &value.second, &value.fourth);
            transformed = value;
            Node_ClampRectToClip(&transformed, &basis);
            N64Eng_SetClipBounds(transformed.first, transformed.third, transformed.second, transformed.fourth);
            changed = 1;
        }
        Widget_DrawVisibleSiblings(record->firstChild, args);
        if (changed != 0) {
            N64Eng_SetClipBounds(value.first, value.third, value.second, value.fourth);
        }
    }
}
#endif
