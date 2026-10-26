#include "COMMON/ANIMATION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MATH/802A2870.H"
#include "FRONTEND/8040B45C_32.H"
#include "RESMGR/resmgr_string_memory.H"
#include "MATH/80299ECC.H"

/* Allocates and zeroes a 0x70-byte overlay node, copies the 0x2C-byte header of the owner's tree root into it, tags it 0x7A51 with kind 0x7D5 and flags 8, links it to its owner and the given value, inserts it under the root through func_8040EDE4_de and records it as the owner's overlay. */









extern NodeMenuCreateOverlayNode *Scene_AllocateMemory(s32 size);


extern void func_8040EDE4_de(NodeMenuCreateOverlayNode *parent, NodeMenuCreateOverlayNode *node);

/* Unless slot index is locked, hides the node shown in that slot, finds node id under the context root through func_8040EC30_de, shows it, and stores it in that slot or, in shared mode, in all four slots; then clears the slot's lock. */








extern NodeMenuShowSlotById *func_8040EC30_de(void *root, s32 id);

/* Unless slot index is locked, hides the node in that slot and shows the given node through func_8040E928_de, storing it in that slot or, in shared mode, in all four slots. */






/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E34A0, an actor kind at D_800E34A4 and a handler at D_800E34A8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */





#if defined(VERSION_DE)
#elif defined(VERSION_EU)
#elif defined(VERSION_EU_X)
#elif defined(VERSION_US)
#elif defined(VERSION_US_REV1)
#endif

/* Draws the child at 0x8 of window arg0 with the arguments passed by value once Frontend_ComputeWidgetBounds resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values func_802A1898_de reports, narrows them by the resolved basis through func_8040F488_de and installs them through func_802A1870_de around the draw, restoring the saved values after it. Adapted from func_802A1BE0_de. */





extern s32 Frontend_ComputeWidgetBounds(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);

extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);

extern s32 Frontend_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void Frontend_DrawVisibleSiblings(void *, Args);

void Menu_RegisterOverlayClass(void) {
    func_802982C4_de(0x7D5, D_0041B970, D_0041BA00, 3);
}

NodeMenuCreateOverlayNode *Menu_CreateOverlayNode(OwnerRecAt44 *owner, s32 value) {
    NodeMenuCreateOverlayNode *node;

    node = Scene_AllocateMemory(0x70);
    Resmgr_FillBytes(node, 0, 0x70);
    *(Header44 *)node = *(Header44 *)owner->root;
    node->kind = 0x7D5;
    node->flags = 8;
    node->value = value;
    node->owner = owner;
    node->tag = 0x7A51;
    node->field_6C = 0;
    func_8040EDE4_de(owner->root, node);
    return owner->overlay = node;
}

void Menu_ShowSlotById(OwnerRecAt8V1 *owner, s32 index, s32 id) {
    sm_dlmultiuser *context;
    NodeMenuShowSlotById *node;
    s32 i;

    context = owner->context;
    if (context->locked[index] == 0) {
        if (context->shown[index] != 0) {
            func_802995D4_de(context->shown[index]->id, 0x10, 0, 0, 0);
        }
        node = func_8040EC30_de(context->root, id & 0xFFFF);
        func_802995D4_de(node->id, 0xF, 0, 0, 0);
        if (context->shared == 0) {
            context->shown[index] = node;
        } else {
            for (i = 3; i >= 0; i--) {
                context->shown[i] = node;
            }
        }
    }
    context->locked[index] = 0;
}

/* Stores a value into entry i of the word array at offset 0x5C of an object; func_8041B7FC_de reads
   the parallel array at offset 0x4C. */


void Menu_SetSlotValue(struct SlotsRecAt5CV1 *object, s32 index, s32 value) {
    object->values[index] = value;
}

/* Counts the non-zero words among the first n of the array at offset 0x5C of an object, n being
   its count at 0x48. */


s32 func_8041B7C4_de(struct SlotsRecAt5CV2 *object) {
    s32 used = 0;
    s32 i;

    for (i = 0; i < object->count; i++) {
        if (object->values[i] != 0) {
            used++;
        }
    }
    return used;
}

/* Returns entry i of the word array at offset 0x4C of an object; func_8041B7B4_de writes the
   parallel array at offset 0x5C. */


struct WidgetNode *Menu_GetSlotValue(struct SlotsCode804196C0 *object, s32 index) {
    return object->values[index];
}

/* Returns the halfword at offset 0xC of the object held in entry i of the pointer array at
   offset 0x4C of an object. */




s16 func_8041B810_de(struct SlotsRecAt4C *object, s32 index) {
    return object->entries[index]->unkC;
}

void func_8041B828_de(sm_dlmultiuser *context, s32 index, s32 id) {
    NodeMenuShowSlotById *node;
    s32 i;

    if (context->locked[index] == 0) {
        if (context->shown[index] != 0) {
            func_802995D4_de(context->shown[index]->id, 0x10, 0, 0, 0);
        }
        node = func_8040EC30_de(context->root, id & 0xFFFF);
        func_802995D4_de(node->id, 0xF, 0, 0, 0);
        if (context->shared == 0) {
            context->shown[index] = node;
        } else {
            for (i = 3; i >= 0; i--) {
                context->shown[i] = node;
            }
        }
    }
}

void Menu_ShowSlotNode(sm_dlmultiuser *context, s32 index, NodeMenuShowSlotById *node) {
    s32 i;

    if (context->locked[index] == 0) {
        if (context->shown[index] != 0) {
            Frontend_SetWidgetFlag40(context->shown[index], 0);
        }
        Frontend_SetWidgetFlag40(node, 1);
        if (context->shared == 0) {
            context->shown[index] = node;
        } else {
            for (i = 3; i >= 0; i--) {
                context->shown[i] = node;
            }
        }
    }
}

/* Stores a value into the word at offset 0x6C of an object; func_8041CE18_de uses it to set that word
   to one on the object held at offset 4 of the structure D_800E3590 points to. */


void func_8041B968_de(struct Object6C *object, s32 value) {
    object->value = value;
}

s32 func_8041B970_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (
#if defined(VERSION_DE)
D_800DF458
#elif defined(VERSION_EU)
D_800EFAC8
#elif defined(VERSION_EU_X)
D_800EAC88
#elif defined(VERSION_US)
D_800DE108
#elif defined(VERSION_US_REV1)
D_800E34A8
#endif
 != 0) {
        wildcard = 0x7530;
        entry = (char *)&
#if defined(VERSION_DE)
D_800DF458
#elif defined(VERSION_EU)
D_800EFAC8
#elif defined(VERSION_EU_X)
D_800EAC88
#elif defined(VERSION_US)
D_800DE108
#elif defined(VERSION_US_REV1)
D_800E34A8
#endif
;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E34A0)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E34A4)) + offset))->field_0;
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

void Menu_DrawOverlayWidget(Shared_Item *widget, Args args) {
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    s32 changed;

    changed = 0;
    if (Frontend_ComputeWidgetBounds(&first, &basis, widget, &args) != 0) {
        if ((widget->flags & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            Frontend_ClampRectToClip(&transformed, &basis);
            func_802A1870_de(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        Frontend_DrawVisibleSiblings(widget->label, args);
        if (changed != 0) {
            func_802A1870_de(value.x, value.z, value.y, value.w);
        }
    }
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8041BB34_de(void) {
    return 0;
}
