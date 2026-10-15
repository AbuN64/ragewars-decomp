#include "span_16E000/code_8043F69C.h"
#include "common/types_1dc8418c21db.h"
#include "shared/world.h"
#include "types.h"

/* Allocates a block sized for the entries of the list the parameters point at through func_8025343C_de, builds it with func_80440DA0_de from the list's own value and three parameters, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from func_804427C4_de with the list read from the parameters at 0x18, a null list returning zero, and the first value read from the list at 0x20 instead of the parameters at 0x14 changed. */








extern char D_800DE4E8[];

extern void **func_8025343C_de(s32, s32, s32, char *);

extern void func_80440DA0_de(void *, void **, struct List_func_80442574_de *, s32, s32, s32, s32, struct func_8025E5B0_S1 *);

extern void func_80255CB8_de(struct func_8025E5B0_S1 *, void *);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif

/* Returns the length of the first line of a text item's string, taken from func_8043F290 for type 5 items and from the string pointer at 0x14 otherwise, counting until a newline, the end of the string or a null pointer. */





/* Forwards its four arguments to func_8043FE3C_de, adding the word the object's pointer at offset
   0x14 addresses and a zero as the fifth and sixth. func_80442064_de and func_8044208C_de are the
   same function. */




/* Forwards its four arguments to func_8043FE3C_de with, as the fifth, a one-character string made
   of the byte at offset 0x17 of the object, and a zero as the sixth. */




/* Forwards its four arguments to func_8043FE3C_de with what func_8043F290 returns for the object as the fifth and a one as the sixth. Adapted from func_8044208C_de with the fifth argument taken from func_8043F290 and a one as the sixth changed. */



/* Loads a preview model into the widget state, resets its motion and remembers its original size. */




extern PreviewWidget *func_8028CFA0_de(void *,int,int);

void *func_80441EB0_de(struct func_8025E5B0_S1 *owner, struct ParamsRecAt24V1 *params) {
    struct List_func_80442574_de *list = params->list;
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
        block = func_8025343C_de(0, size, 0x3B, D_800DE4E8 + 4);
        if (block == 0) {
            return 0;
        }
        first = *block;
        if (first != 0) {
            func_80440DA0_de(first, block, list, a, b, c, d, owner);
            func_80255CB8_de(owner, first);
            if (++owner->unk14 >= 4) {
                owner->unk14 = 0;
            }
            return first;
        }
    }
    return 0;
}

int func_80441FE8_de(LayeredText *item) {
    extern u8 *func_8043F290(LayeredText *item);
    u8 *p;
    int len;

    len = 0;
    if (item->mode == 5) {
        p = func_8043F290(item);
    } else {
        
#if defined(VERSION_EU) || defined(VERSION_EU_X)
p = item->text[D_80152789];
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

void func_80442064_de(struct Field *object, s32 second, s32 third, s32 fourth) {
    extern void func_8043FE3C_de(struct Field *, s32, s32, s32, s32, s32);
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_8043FE3C_de(object, second, third, fourth, object->text[D_80152789], 0);
#else
func_8043FE3C_de(object, second, third, fourth, *object->text, 0);
#endif

}

void func_8044208C_de(struct Field *object, s32 second, s32 third, s32 fourth) {
    extern void func_8043FE3C_de(struct Field *, s32, s32, s32, s32, s32);
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_8043FE3C_de(object, second, third, fourth, object->text[D_80152789], 0);
#else
func_8043FE3C_de(object, second, third, fourth, *object->text, 0);
#endif

}

void func_804420B4_de(struct Object_func_804420B4_de *object, s32 second, s32 third, s32 fourth) {
    extern void func_8043FE3C_de(struct Object_func_804420B4_de *, s32, s32, s32, u8 *, s32);
    u8 text[2];

    text[0] = object->character;
    text[1] = 0;
    func_8043FE3C_de(object, second, third, fourth, text, 0);
}

void func_804420E4_de(LayeredText *object, s32 second, s32 third, s32 fourth) {
    extern void func_8043FE3C_de(LayeredText *, s32, s32, s32, s32, s32);
    extern char *func_8043F290(LayeredText *);
#if defined(VERSION_DE)
    func_8043FE3C_de(object, second, third, fourth, (s32)func_8043F290(object), 1);
#else
    func_8043FE3C_de(object, second, third, fourth, (s32)
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_8043F290
#else
func_8043F114_de
#endif
(object), 1);
#endif
}

PreviewWidget *func_8044214C_de(WidgetRecAt20 *widget,int selection,int kind) {
 StateRecAt47C *state=widget->state;
 PreviewWidget *model=func_8028CFA0_de(&D_8011FE88,selection,kind);
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
