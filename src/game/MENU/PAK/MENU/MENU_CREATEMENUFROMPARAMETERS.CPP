#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/LONE/D_80152789.H"
#include "MENU/8043F69C.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_3.H"
#include "MENU/PAK/8043F69C_11.H"

/* Allocates a block sized for the entries of the list the parameters point at through Cache_AllocateResource, builds it with Menu_InitializeMenu from the list's own value and three parameters, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from Pak_AllocateMenu with the list read from the parameters at 0x18, a null list returning zero, and the first value read from the list at 0x20 instead of the parameters at 0x14 changed. */








extern char g_menuText[];

extern void **Cache_AllocateResource(s32, s32, s32, char *);



#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

/* Returns the length of the first line of a text item's string, taken from func_8043F290 for type 5 items and from the string pointer at 0x14 otherwise, counting until a newline, the end of the string or a null pointer. */





/* Forwards its four arguments to Menu_DrawStyledMenuText, adding the word the object's pointer at offset
   0x14 addresses and a zero as the fifth and sixth. Menu_DrawMenuItemLabel and Menu_DrawLocalizedMenuItemText are the
   same function. */




/* Forwards its four arguments to Menu_DrawStyledMenuText with, as the fifth, a one-character string made
   of the byte at offset 0x17 of the object, and a zero as the sixth. */




/* Forwards its four arguments to Menu_DrawStyledMenuText with what func_8043F290 returns for the object as the fifth and a one as the sixth. Adapted from Menu_DrawLocalizedMenuItemText with the fifth argument taken from func_8043F290 and a one as the sixth changed. */



/* Loads a preview model into the widget state, resets its motion and remembers its original size. */




extern PreviewWidget *Scene_FindActorDefinition(Shared_World *,int,int);

void *Menu_CreateMenuFromParameters(struct func_8025E5B0_S1 *owner, struct ParamsRecAt24V1 *params) {
    struct Dialog *list = params->list;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 size;
    s32 i;
    void **block;
    void *first;

    if (list != 0) {
        a = list->value;
        b = params->b;
        c = params->c;
        d = params->d;
        size = list->count * 40 + 0x1D8;
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
        if (first != 0) {
            Menu_InitializeMenu(first, block, list, a, b, c, d, owner);
            func_80255CB8_de(owner, first);
            if (++owner->unk14 >= 4) {
                owner->unk14 = 0;
            }
            return first;
        }
    }
    return 0;
}

extern u8 *func_8043F290(LayeredText *item);
extern void Menu_DrawStyledMenuText(void *item, s32 second, s32 third, s32 fourth, void *text, s32 mode);
int Pak_CountLineChars(LayeredText *item) {
    u8 *p;
    int len;

    len = 0;
    if (item->mode == 5) {
        p = func_8043F290(item);
    } else {
        
#if defined(VERSION_EU) || defined(VERSION_EU_X)
p = item->text[g_languageIndex];
#else
p = *item->text;
#endif

    }
    while (p != 0 && *p != 0 && *p != '\n') {
        p++;
        len++;
    }
    return len;
}

void Menu_DrawMenuItemLabel(struct Field *object, s32 second, s32 third, s32 fourth) {
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
Menu_DrawStyledMenuText(object, second, third, fourth, object->text[g_languageIndex], 0);
#else
Menu_DrawStyledMenuText(object, second, third, fourth, *object->text, 0);
#endif

}

void Menu_DrawLocalizedMenuItemText(struct Field *object, s32 second, s32 third, s32 fourth) {
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
Menu_DrawStyledMenuText(object, second, third, fourth, object->text[g_languageIndex], 0);
#else
Menu_DrawStyledMenuText(object, second, third, fourth, *object->text, 0);
#endif

}

void Menu_DrawMenuCharacter(struct ObjectPakDrawMenuCharacter *object, s32 second, s32 third, s32 fourth) {
    u8 text[2];

    text[0] = object->character;
    text[1] = 0;
    Menu_DrawStyledMenuText(object, second, third, fourth, text, 0);
}

void Menu_DrawDynamicMenuText(LayeredText *object, s32 second, s32 third, s32 fourth) {
#if defined(VERSION_DE)
    Menu_DrawStyledMenuText(object, second, third, fourth, func_8043F290(object), 1);
#else
    Menu_DrawStyledMenuText(object, second, third, fourth,
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_8043F290
#else
func_8043F114_de
#endif
(object), 1);
#endif
}

PreviewWidget *Pak_SelectPreviewModel(WidgetRecAt20 *widget,int selection,int kind) {
 StateRecAt47C *state=widget->state;
 PreviewWidget *model=Scene_FindActorDefinition(&g_world,selection,kind);
 if(!model){state->active=0;return 0;}
 state->selection=selection;
 state->active=1;
 state->model=*model;
 state->model.x=0;state->model.y=0;
 state->model.dx=0;state->model.dy=0;state->model.dz=0;
 state->model.depth=(10240.0f);
 state->size=state->model.size;
 return &state->model;
}
