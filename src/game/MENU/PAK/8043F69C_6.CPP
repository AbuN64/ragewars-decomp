#include "COMMON/TEXTLAYERMETRICS.H"
#include "MENU/8043F69C.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "MENU/PAK/8043F69C_6.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "MENU/PAK/8043F69C_11.H"
extern void Scene_ReleaseResource(void *arg0, void *arg1);

/* Returns the address 0x190 bytes into the block at offset 0x20 of an object, or null when the
   object has no block. */

char *func_80442214_de(struct ObjRecAt20V2 *object) {
    char *result = 0;

    if (object->unk20 != 0) {
        result = object->unk20 + 0x190;
    }
    return result;
}

/* Computes a glyph advance using character widths and special spacing before T. */
f32 Pak_GetGlyphAdvance(s32 ch, u8 next_ch, f32 scale, f32 special_advance) {
    f32 factor;
    s32 cur;
    s32 next_a;
    s32 next_b;

    cur = ch & 0xFF;
    factor = 1.0f;
    switch (cur) {
    case 0x24:
    case 0x26:
    case 0x7E:
        return special_advance;
    case 0x49:
    case 0x69:
        factor = 0.5f;
    default:
        break;
    case 0x4C:
    case 0x6C:
        next_a = next_ch & 0xFF;
        if ((next_a == 0x74) || (next_a == 0x54)) {
            factor = 0.7f;
        }
        break;
    case 0x41:
    case 0x61:
        next_b = next_ch & 0xFF;
        if ((next_b == 0x74) || (next_b == 0x54)) {
            factor = 0.8f;
        }
        break;
    case 0x4D:
    case 0x6D:
        factor = 1.2f;
        break;
    case 0x21:
    case 0x2E:
        factor = 0.4f;
        break;
    }
    return factor * scale;
}

/* Sums the glyph advances that Pak_GetGlyphAdvance returns for each character pair of a string at the given scales, stopping at a newline, the end of the string or a null pointer. */

f32 Pak_MeasureLine(u8 *p, f32 sx, f32 sy) {
    f32 total;
    u8 c;

    total = 0.0f;
    while (p != 0 && (c = *p) != 0 && c != '\n') {
        p++;
        total += Pak_GetGlyphAdvance(c, *p, sx, sy);
    }
    return total;
}

/* Returns whether func_80441EB0_de gives a non-zero answer for the third argument. */
extern s32 func_80441EB0_de(void *);

s32 func_80442384_de(void *first, void *second, void *third) {
    return func_80441EB0_de(third) != 0;
}

/* Returns zero. */
s32 func_804423A4_de(void) {
    return 0;
}

/* Returns the word at offset 0x1C of the object that offset 0x14 of a record points to. */

s32 func_804423AC_de(struct Outer *outer) {
    return outer->inner->locked;
}

/* Adjusts a value from controller input and clamps or wraps it between its limits. */

s32 Render_IsAButtonPressed(s32); /* extern */
 /* extern */
 /* extern */

s32 Pak_AdjustValue(func_8022A404_S1 *menu,s32 value,s32 step,s32 minimum,s32 maximum,s32 wrap) {
 if(((s32 (*)(s32))Control_IsLeftPressed)(menu->unk20))value-=step;
 if(((s32 (*)(s32))Control_IsRightPressed)(menu->unk20)||Render_IsAButtonPressed(menu->unk20))value+=step;
 if(value<minimum) {
  value=minimum;if(wrap)value=maximum;
 } else if(value>maximum) {
  value=maximum;if(wrap)value=minimum;
 }
 return value;
}

/* Steps a menu value left or right with optional range wrapping. */

 /* extern */
 /* extern */

s32 Pak_StepValue(func_8022A404_S1 *menu, s32 value, s32 step, s32 minimum, s32 maximum, s32 wrap) {
    s32 stepped;
    s32 current;
    s32 result;

    current = value;
    if (((s32 (*)(s32))Control_IsLeftPressed)(menu->unk20) != 0) {
        current -= step;
        if (current < minimum) {
            current = minimum;
            if (wrap != 0) {
                current = maximum;
            }
        }
    }
    result = current;
    if (((s32 (*)(s32))Control_IsRightPressed)(menu->unk20) != 0) {
        stepped = current + step;
        result = stepped;
        if (maximum < stepped) {
            current = maximum;
            if (wrap != 0) {
                current = minimum;
            }
            result = current;
        }
    }
    return result;
}


void func_80442544_de(void *object) {
    func_80255CA0_de(object, 0x1D0, 0x1D4);
    ((MessageList *)object)->rotation = 0;
}

/* Allocates a block sized for the entries of a list through Scene_AllocateResource, builds it with Pak_InitializeMenu from a zero and three arguments, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from Pak_AllocateMenu with the list and three values passed as arguments and a zero as the first value changed. */

extern char g_menuText[];
extern void **Scene_AllocateResource(s32, s32, s32, char *);

void *Pak_OpenDialog(void *parent, struct Dialog *list, s32 player, s32 controller, s32 d) {
    struct func_8025E5B0_S1 *owner;
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
    block = Scene_AllocateResource(0, size, 0x3B, g_menuText);
    if (block == 0) {
        return 0;
    }
    first = *block;
    if (first == 0) {
        return 0;
    }
    Pak_InitializeMenu(first, block, list, 0, player, controller, d, parent);
    func_80255CB8_de(parent, first);
    owner = parent;
    if (++owner->unk14 >= 4) {
        owner->unk14 = 0;
    }
    return first;
}

/* Allocates a block sized for the entries of a list (forty bytes each plus 0x480 for every entry of type three, over a 0x1D8 header) through Scene_AllocateResource, builds it with Pak_InitializeMenu from four parameters, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. */
extern char g_menuText[];
extern void **Scene_AllocateResource(s32, s32, s32, char *);

void *func_80442690_de(struct func_8025E5B0_S1 *owner, struct ParamsRecAt24V2 *params, struct Dialog *list) {
    s32 a = params->a;
    s32 b = params->b;
    s32 c = params->c;
    s32 d = params->d;
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
    block = Scene_AllocateResource(0, size, 0x3B, g_menuText);
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

/* Allocates a block sized for the entries of a list through Scene_AllocateResource, builds it with Pak_InitializeMenu from four parameters, registers it with func_80255CB8_de and advances the owner's rotating counter below four, returning the block or zero. Adapted from func_80442690_de with the first parameter read from offset 0x14 instead of 0x18. */
extern char g_menuText[];
extern void **Scene_AllocateResource(s32, s32, s32, char *);

void *Pak_AllocateMenu(struct func_8025E5B0_S1 *owner, struct ParamsPakAllocateMenu *params, struct Dialog *list) {
    s32 a = params->a;
    s32 b = params->b;
    s32 c = params->c;
    s32 d = params->d;
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
    block = Scene_AllocateResource(0, size, 0x3B, g_menuText);
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

/* Tears down every node of one list: walks it from the head, saving the successor at 0x1D4 first,
   skips nodes of kind 2 while the list is not the global one at D_8014561C and that list's flag at
   0x10 is set, and for each remaining node asks Pak_UpdateMenuEntries whether it may go; when it may, calls
   the node's optional handler at 0xC of its table at 0x14, clears the three words at 0xB0, 0xB4 and
   0xBC of the state it owns at 0x20, unlinks it with func_80255ED8_de and releases its handle at 0x8
   through Scene_ReleaseResource. */
extern MessageList D_8014561C;
extern s32 Pak_UpdateMenuEntries(CMenu *, MessageList *);

void Pak_UpdateDialogList(MessageList *list) {
    CMenu *node;
    CMenu *next;
    StateRecAtBCV1 *state;

    node = list->head;
    while (node != 0) {
        next = node->next;
        if (!((node->kind == 2) && (list != &D_8014561C) && (D_8014561C.flag != 0))) {
            if (Pak_UpdateMenuEntries(node, list) != 0) {
                if (node->table->handler != 0) {
                    node->table->handler(node, list);
                }
                state = node->state;
                state->field_B0 = 0;
                state->field_B4 = 0;
                state->field_BC = 0;
                func_80255ED8_de(list, node);
                Scene_ReleaseResource(0, node->handle);
            }
        }
        node = next;
    }
}

void func_804429D4_de(struct OwnerRecAt4 *owner) {
    struct NodeRecAt1D0 *node = owner->head;

    while (node != 0) {
        ((void (*)(struct NodeRecAt1D0 *, struct OwnerRecAt4 *))node->vtable[4])(node, owner);
        node = node->next;
    }
}

int Pak_CountLiveNodes(Node_Pak_CountLiveNodes **head) {
    Node_Pak_CountLiveNodes *node = *head;
    int count = 0;
    while (node != 0) {
        if (node->kind != 4) {
            count++;
        }
        node = node->next;
    }
    return count;
}
