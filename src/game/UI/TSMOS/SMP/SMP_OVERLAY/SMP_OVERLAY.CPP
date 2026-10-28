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
#include "COMMON/SCREEN.H"
#include "SCENE/802508E0_13.H"
#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/LABEL.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/STATEPAIR.H"
#include "COMMON/MENURECAT24.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "COMMON/RECORDRECATCV1.H"
#include "FRONTEND/8041BEA8_5.H"
#include "FRONTEND/8042E080_42.H"
#include "COMMON/GAME_SESSION.H"
#include "FRONTEND/SCREEN.H"

/* SMP_OVERLAY.CPP */
/* 804196C0_24.CPP */
/* Allocates and zeroes a 0x70-byte overlay node, copies the 0x2C-byte header of the owner's tree root into it, tags it 0x7A51 with kind 0x7D5 and flags 8, links it to its owner and the given value, inserts it under the root through Node_InsertWidgetBefore and records it as the owner's overlay. */

extern void Node_InsertWidgetBefore(NodeMenuCreateOverlayNode *parent, NodeMenuCreateOverlayNode *node);

/* Unless slot index is locked, hides the node shown in that slot, finds node id under the context root through Node_FindWidgetByResourceId, shows it, and stores it in that slot or, in shared mode, in all four slots; then clears the slot's lock. */

/* Unless slot index is locked, hides the node in that slot and shows the given node through func_8040E928_de, storing it in that slot or, in shared mode, in all four slots. */

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E34A0, an actor kind at D_800E34A4 and a handler at D_800E34A8: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

#if defined(VERSION_DE)
#elif defined(VERSION_EU)
#elif defined(VERSION_EU_X)
#elif defined(VERSION_US)
#elif defined(VERSION_US_REV1)
#endif

/* Draws the child at 0x8 of window arg0 with the arguments passed by value once Widget_ComputeWidgetBounds resolves the window's rectangle, and when flag 0x200 of the halfword at 0x12 is set it saves the four values N64Eng_GetClipBounds reports, narrows them by the resolved basis through func_8040F488_de and installs them through N64Eng_SetClipBounds around the draw, restoring the saved values after it. Adapted from N64Eng_DrawNumericWidgetChildren. */

extern s32 Widget_ComputeWidgetBounds(QuadN64EngDrawNumericWidgetChildren *, QuadN64EngDrawNumericWidgetChildren *, void *, Args *);

extern void N64Eng_GetClipBounds(u32 *, u32 *, u32 *, u32 *);

extern s32 Node_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);

extern void Widget_DrawVisibleSiblings(void *, Args);

void SmpOverlay_RegisterOverlayClass(void) {
    SmSmngr_RegisterElementHandlers(0x7D5, D_0041B970, D_0041BA00, 3);
}

NodeMenuCreateOverlayNode *SmpOverlay_CreateOverlayNode(OwnerRecAt44 *owner, s32 value) {
    NodeMenuCreateOverlayNode *node;

    node = (NodeMenuCreateOverlayNode *)Cache_AllocateMemory(0x70);
    XPlus_FillBytes(node, 0, 0x70);
    *(Header44 *)node = *(Header44 *)owner->root;
    node->kind = 0x7D5;
    node->flags = 8;
    node->value = value;
    node->owner = owner;
    node->tag = 0x7A51;
    node->field_6C = 0;
    Node_InsertWidgetBefore(owner->root, node);
    return owner->overlay = node;
}

void SmpOverlay_ShowSlotById(OwnerRecAt8V1 *owner, s32 index, s32 id) {
    sm_dlmultiuser *context;
    NodeMenuShowSlotById *node;
    s32 i;

    context = owner->context;
    if (context->locked[index] == 0) {
        if (context->shown[index] != 0) {
            Menu_RouteElementEvent(context->shown[index]->id, 0x10, 0, 0, 0);
        }
        node = (NodeMenuShowSlotById *)Node_FindWidgetByResourceId(context->root, id & 0xFFFF);
        Menu_RouteElementEvent(node->id, 0xF, 0, 0, 0);
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

void SmpOverlay_SetSlotValue(struct SlotsRecAt5CV1 *object, s32 index, s32 value) {
    object->values[index] = value;
}

/* Counts the non-zero words among the first n of the array at offset 0x5C of an object, n being
   its count at 0x48. */

s32 SmpOverlay_CountUsedSlots(struct SlotsRecAt5CV2 *object) {
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

struct WidgetNode *SmpOverlay_GetSlotValue(struct SlotsCode804196C0 *object, s32 index) {
    return object->values[index];
}

/* Returns the halfword at offset 0xC of the object held in entry i of the pointer array at
   offset 0x4C of an object. */

s16 SmpOverlay_GetSlotNodeId(struct SlotsRecAt4C *object, s32 index) {
    return object->entries[index]->unkC;
}

void SmpOverlay_ShowSlotNodeById(sm_dlmultiuser *context, s32 index, s32 id) {
    NodeMenuShowSlotById *node;
    s32 i;

    if (context->locked[index] == 0) {
        if (context->shown[index] != 0) {
            Menu_RouteElementEvent(context->shown[index]->id, 0x10, 0, 0, 0);
        }
        node = (NodeMenuShowSlotById *)Node_FindWidgetByResourceId(context->root, id & 0xFFFF);
        Menu_RouteElementEvent(node->id, 0xF, 0, 0, 0);
        if (context->shared == 0) {
            context->shown[index] = node;
        } else {
            for (i = 3; i >= 0; i--) {
                context->shown[i] = node;
            }
        }
    }
}

void SmpOverlay_ShowSlotNode(sm_dlmultiuser *context, s32 index, NodeMenuShowSlotById *node) {
    s32 i;

    if (context->locked[index] == 0) {
        if (context->shown[index] != 0) {
            Widget_SetWidgetFlag40(context->shown[index], 0);
        }
        Widget_SetWidgetFlag40(node, 1);
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

void SmpOverlay_SetObjectValue(struct Object6C *object, s32 value) {
    object->value = value;
}

s32 SmpOverlay_DispatchSlotEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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

void SmpOverlay_DrawOverlayWidget(Shared_Item *widget, Args args) {
    QuadN64EngDrawNumericWidgetChildren first;
    QuadN64EngDrawNumericWidgetChildren basis;
    QuadN64EngDrawNumericWidgetChildren value;
    QuadN64EngDrawNumericWidgetChildren transformed;
    s32 changed;

    changed = 0;
    if (Widget_ComputeWidgetBounds(&first, &basis, widget, &args) != 0) {
        if ((widget->flags & 0x200) != 0) {
            N64Eng_GetClipBounds(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            Node_ClampRectToClip(&transformed, &basis);
            N64Eng_SetClipBounds(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        Widget_DrawVisibleSiblings(widget->label, args);
        if (changed != 0) {
            N64Eng_SetClipBounds(value.x, value.z, value.y, value.w);
        }
    }
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 SmpOverlay_ReturnUnhandledEvent(void) {
    return 0;
}

/* 804196C0_25.CPP */
/* Calls MarkMenuEventHandled and, for an event of kind one on a slot with no word at 0x5C whose child at 0x4C has flag 0x10 of its halfword at 0x12 set and a target at 0x34, passes the owner, the slot and the target to func_8041B8DC_de, returning zero. */

/* After MarkMenuEventHandled, forwards an event for a channel to Menu_RouteElementEvent with the channel's handler id
   (short at 0xC of the handler at 0x4C) when the channel is not muted (word at 0x5C) and has a handler;
   returns 0. */

/* Calls Cache_FreeMemory with the arguments it was given and returns zero. */

s32 SmpOverlay_FollowSlotTarget34(struct sm_dlmultiuser_t *owner, s32 unused1, s32 slot, s32 kind) {
    struct Child *child;

    MarkMenuEventHandled();
    if (kind != 1) {
        return 0;
    }
    if (owner->locked[(u16)slot] != 0) {
        return 0;
    }
    child = owner->shown[(u16)slot];
    if (child == 0) {
        return 0;
    }
    if (!(child->flags & 0x10)) {
        return 0;
    }
    if (child->target == 0) {
        return 0;
    }
    SmpOverlay_ShowSlotNode(owner, (u16)slot, child->target);
    return 0;
}

s32 SmpOverlay_FollowSlotTarget2c(struct sm_dlmultiuser_t *owner, s32 unused1, s32 slot, s32 kind) {
    struct ChildRecAt2C *child;

    MarkMenuEventHandled();
    if (kind != 1) {
        return 0;
    }
    if (owner->locked[(u16)slot] != 0) {
        return 0;
    }
    child = owner->shown[(u16)slot];
    if (child == 0) {
        return 0;
    }
    if (!(child->flags & 0x10)) {
        return 0;
    }
    if (child->target == 0) {
        return 0;
    }
    SmpOverlay_ShowSlotNode(owner, (u16)slot, child->target);
    return 0;
}

s32 SmpOverlay_FollowSlotTarget38(struct sm_dlmultiuser_t *owner, s32 unused1, s32 slot, s32 kind) {
    struct ChildRecAt38 *child;

    MarkMenuEventHandled();
    if (kind != 1) {
        return 0;
    }
    if (owner->locked[(u16)slot] != 0) {
        return 0;
    }
    child = owner->shown[(u16)slot];
    if (child == 0) {
        return 0;
    }
    if (!(child->flags & 0x10)) {
        return 0;
    }
    if (child->target == 0) {
        return 0;
    }
    SmpOverlay_ShowSlotNode(owner, (u16)slot, child->target);
    return 0;
}

s32 SmpOverlay_FollowSlotTarget30(struct sm_dlmultiuser_t *owner, s32 unused1, s32 slot, s32 kind) {
    struct ChildRecAt30 *child;

    MarkMenuEventHandled();
    if (kind != 1) {
        return 0;
    }
    if (owner->locked[(u16)slot] != 0) {
        return 0;
    }
    child = owner->shown[(u16)slot];
    if (child == 0) {
        return 0;
    }
    if (!(child->flags & 0x10)) {
        return 0;
    }
    if (child->target == 0) {
        return 0;
    }
    SmpOverlay_ShowSlotNode(owner, (u16)slot, child->target);
    return 0;
}

int SmpOverlay_ForwardSlotEvent(Mixer *mixer, int unused, int channel, int value, int extra) {
    ObjRecAtCV1 *h;

    MarkMenuEventHandled();
    if (mixer->muted[(unsigned short)channel] != 0) {
        return 0;
    }
    h = mixer->handlers[(unsigned short)channel];
    if (h == 0) {
        return 0;
    }
    Menu_RouteElementEvent(h->unkC, 1, channel, value, extra);
    return 0;
}

s32 SmpOverlay_FreeEventObject(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}

/* 8041BEA8_5.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#else
#endif
extern SlotDialog *D_800E3518;

/* Calls func_8040E928_de with flag 1 on each of the list's items (count at 0x48, items from 0x4C) and
   returns 0. */

/* Updates the slot-selection dialog after availability and capacity probes, choosing unavailable, empty and confirmation states or entering the requested transition. The negative probe statuses -4, -3 and -1 trigger the error transition. */

#if defined(VERSION_DE)
enum { SLOT_RESOURCE_962 = 956, SLOT_RESOURCE_966 = 961, SLOT_RESOURCE_968 = 960, SLOT_RESOURCE_971 = 964 };
#elif defined(VERSION_EU)
enum { SLOT_RESOURCE_962 = 962, SLOT_RESOURCE_966 = 966, SLOT_RESOURCE_968 = 968, SLOT_RESOURCE_971 = 971 };

#elif defined(VERSION_EU_X)
enum { SLOT_RESOURCE_962 = 967, SLOT_RESOURCE_966 = 969, SLOT_RESOURCE_968 = 971, SLOT_RESOURCE_971 = 975 };

#else
enum { SLOT_RESOURCE_962 = 962, SLOT_RESOURCE_966 = 966, SLOT_RESOURCE_968 = 968, SLOT_RESOURCE_971 = 971 };

#endif

extern s32 Control_IsControllerConnected(s32);

extern void SmXlate_SwitchScreen(s32);

extern void Menu_SetFocusedElement(s32);

extern void Tsmos_ActivateControllerState(void);

extern s32 XStdio_FormatBuffer(void *, const char *, ...);

extern s32 Note_FindNoteByName(s32, s32, s32 *);

extern s32 PAKInterface_CheckRecordsNoteCapacity(s32,u32 *);

extern void SmpOverlay_AdvancePakDialogPort(void);

#if defined(VERSION_DE)
extern char g_noteCountIntFormat[];

extern s32 D_800DF4C4;
#elif defined(VERSION_EU)
extern char D_800EDAD0[];
extern s32 D_800EFB34;
#elif defined(VERSION_EU_X)
extern char D_800EDAD0[];
extern s32 D_800EACF4;

#elif defined(VERSION_US)
extern char g_noteCountIntFormat[];

extern s32 D_800DE174;
#else
extern char g_noteCountIntFormat[];
extern s32 D_800E3514;

#endif

/* Calls Tsmos_DeactivateControllerState and MarkMenuEventHandled, then SmXlate_SwitchScreen with 2, sets D_8014ADA0 and returns
   one. */

/* Refreshes each of the four ports through Note_ProbeStatus and sets field 0x1C of D_800E3518 as soon as one reports status 0, -1, -3 or -4 through Note_GetStatus, clearing it otherwise. */

/* Advances the slot-dialog retry counter. Before the fourth attempt it updates
 * the dialog; later attempts start the transition and mark it active. */

extern void SmpOverlay_RefreshPakDialog(void);

/* Builds screen state D_800E3518 under a parent window: allocates its 0x2C bytes, keeps the parent,
   opens windows 0x3C3 (shown), 0x3C9, 0x3C4 and 0x3C5 (hidden) at 0x4 to 0x10, clears the words at
   0x14 and 0x18, resets through func_8040C428_de(0) and Tsmos_DeactivateControllerState, sets D_800E28C8 to -1 and
   D_80146D70 to 0, releases the resources of D_8011FAC0 and of its block at 0x3C8, clears the
   word at 0x1C and returns zero. */

extern void SetN64_ResetSessionPlayerPools(void *, s32, s32);

extern void Scene_LoadLevelResources(void *, s32, s32);

/* Releases the object D_800E3518 holds through Cache_FreeMemory, clears D_800E3518 and returns zero. */

/* In one- or no-player mode, counts a tick on the state D_800E3518 and, while it is not paused, once
   more than five ticks have passed runs Tsmos_ActivateControllerState and SmpOverlay_AdvancePakDialogPort; always returns 0. */

/* The slot-error scalar is real external storage in every ROM version: the de cart writes
   800DF4C4, eu writes 800EFB34, eu-x writes 800EACF4, us writes 800DE174, us-rev1 800E3514. */
#if defined(VERSION_EU) || defined(VERSION_DE) || defined(VERSION_US)
#elif defined(VERSION_EU_X)
#else
#endif

#if defined(VERSION_EU)
#elif defined(VERSION_DE)
#elif defined(VERSION_US)
#else
#endif

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E351C, an actor kind at D_800E3520 and a handler at D_800E3524: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

int SmpOverlay_SetListWidgetFlag40(ListRecAt4C *list) {
    int i;

    for (i = 0; i < list->count; i++) {
        Widget_SetWidgetFlag40(list->items[i], 1);
    }
    return 0;
}

void SmpOverlay_RefreshPakDialog(void) {
    s32 foundNote;
    u32 hasRoom;
    s32 var_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_s2;
    Label *temp_s0;

    Menu_SetFocusedElement(SLOT_RESOURCE_962);
    Widget_SetWidgetFlag08(D_800E3518->absent, 0);
    var_s2 = 0;
    Widget_SetWidgetFlag08(D_800E3518->unavailable, 0);
    var_s1 = 1;
    Widget_SetWidgetFlag08(D_800E3518->prompt, 0);
    temp_v0 = Control_IsControllerConnected(0);
    if (temp_v0 == 1) {
        SmpOverlay_ProbePakDialogPorts();
        if (D_800E3518->ready == 1) {
            Note_ProbeStatus(D_800DF4C0);
            temp_v0_2 = Note_GetStatus(D_800DF4C0);
            switch (temp_v0_2) { /* irregular */
            case 0:
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                if ((Note_FindNoteByName(((D_800E25A4)[g_languageIndex]), D_800DF4C0, &foundNote) == 0) && (PAKInterface_CheckRecordsNoteCapacity(D_800DF4C0, &hasRoom) == 0)) {
#else
                if ((Note_FindNoteByName((D_800D36D4), D_800DF4C0, &foundNote) == 0) && (PAKInterface_CheckRecordsNoteCapacity(D_800DF4C0, &hasRoom) == 0)) {
#endif
                    var_s1 = hasRoom > 0U;
                }
                break;
            case -4:
            case -3:
            case -1:
                var_s2 = 1;
                break;
            }
        }
    }
    if (temp_v0 == 0) {
        D_800E3518->state = 1;
        D_800E3518->elapsed = 0;
        Widget_SetWidgetFlag08(D_800E3518->main, 0);
        Widget_SetWidgetFlag08(D_800E3518->unavailable, 1);
        goto block_25;
    }
    if (D_800E3518->ready == 0) {
        D_800E3518->state = 2;
        D_800E3518->elapsed = 0;
        Widget_SetWidgetFlag08(D_800E3518->main, 0);
        Widget_SetWidgetFlag08(D_800E3518->absent, 1);
        var_a0 = SLOT_RESOURCE_971;
        goto block_24;
    }
    if ((var_s2 == 1) || (D_8010B0E0.buttons & 0x1000)) {
        MarkMenuEventHandled();
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
        if (var_s2 == 0) {
#if defined(VERSION_DE)
            D_800DF4C4 = 0;
#elif defined(VERSION_EU)
            D_800EFB34 = 0;
#elif defined(VERSION_EU_X)
            D_800EACF4 = 0;
#elif defined(VERSION_US)
            D_800DE174 = 0;
#else
            D_800E3514 = 0;
#endif
        } else {
#if defined(VERSION_DE)
            D_800DF4C4 = 2;
#elif defined(VERSION_EU)
            D_800EFB34 = 2;
#elif defined(VERSION_EU_X)
            D_800EACF4 = 2;
#elif defined(VERSION_US)
            D_800DE174 = 2;
#else
            D_800E3514 = 2;
#endif
        }
        PAKInterface_SetScreenPhase(6);
        SmXlate_SwitchScreen(0x13);
        return;
    }
    if (var_s1 == 1) {
        SmpOverlay_AdvancePakDialogPort();
        return;
    }
    temp_s0 = Node_FindWidgetByResourceId(D_800E3518->root, SLOT_RESOURCE_968);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    XStdio_FormatBuffer(D_800E3518->text, D_800EDAD0, D_800DF4C0 + 1);
#else
    XStdio_FormatBuffer(D_800E3518->text, g_noteCountIntFormat, D_800DF4C0 + 1);
#endif
    temp_s0->text = D_800E3518->text;
    D_800E3518->state = 3;
    D_800E3518->elapsed = 0;
    Widget_SetWidgetFlag08(D_800E3518->main, 0);
    Widget_SetWidgetFlag08(D_800E3518->prompt, 1);
    var_a0 = SLOT_RESOURCE_966;
block_24:
    Menu_SetFocusedElement(var_a0);
block_25:
    Tsmos_ActivateControllerState();
}

s32 SmpOverlay_FinishPakDialog(void) {
    Tsmos_DeactivateControllerState();
    MarkMenuEventHandled();
    SmXlate_SwitchScreen(2);
    D_8014ADA0 = 1;
    return 1;
}

void SmpOverlay_ProbePakDialogPorts(void) {
    s32 port;

    D_800E3518->ready = 0;
    for (port = 0; port < 4; port++) {
        Note_ProbeStatus(port);
        switch (Note_GetStatus(port)) {
        case 0:
            D_800E3518->ready = 1;
            return;
        case -1:
        case -3:
        case -4:
            D_800E3518->ready = 1;
            return;
        }
    }
}

void SmpOverlay_AdvancePakDialogPort(void) {
    D_800DF4C0++;
    if (D_800DF4C0 >= 4) {
        Tsmos_DeactivateControllerState();
        MarkMenuEventHandled();
        SmXlate_SwitchScreen(2);
        D_8014ADA0 = 1;
    } else {
        SmpOverlay_RefreshPakDialog();
    }
}

s32 SmpOverlay_CreatePakDialog(void *parent) {
    void *window;
    char *resources;
    D_800E3518 = Cache_AllocateMemory(0x2C);
    D_800E3518->root = parent;
#if defined(VERSION_DE)
    window = Node_FindWidgetByResourceId(parent, 0x3BE);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = Node_FindWidgetByResourceId(parent, 0x3C3);
#elif defined(VERSION_EU_X)
    window = Node_FindWidgetByResourceId(parent, 0x3CC);
#endif
    D_800E3518->main = window;
    Widget_SetWidgetFlag08(window, 1);
#if defined(VERSION_DE)
    window = Node_FindWidgetByResourceId(parent, 0x3C3);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = Node_FindWidgetByResourceId(parent, 0x3C9);
#elif defined(VERSION_EU_X)
    window = Node_FindWidgetByResourceId(parent, 0x3CD);
#endif
    D_800E3518->absent = window;
    Widget_SetWidgetFlag08(window, 0);
#if defined(VERSION_DE)
    window = Node_FindWidgetByResourceId(parent, 0x3BD);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = Node_FindWidgetByResourceId(parent, 0x3C4);
#elif defined(VERSION_EU_X)
    window = Node_FindWidgetByResourceId(parent, 0x3C6);
#endif
    D_800E3518->unavailable = window;
    Widget_SetWidgetFlag08(window, 0);
#if defined(VERSION_DE)
    window = Node_FindWidgetByResourceId(parent, 0x3BF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = Node_FindWidgetByResourceId(parent, 0x3C5);
#elif defined(VERSION_EU_X)
    window = Node_FindWidgetByResourceId(parent, 0x3C8);
#endif
    D_800E3518->prompt = window;
    Widget_SetWidgetFlag08(window, 0);
    D_800E3518->elapsed = 0;
    D_800E3518->state = 0;
    Frontend_RequestScreenMode(0);
    Tsmos_DeactivateControllerState();
    D_800E28C8 = -1;
    D_80146D70 = 0;
    resources = (char *)&D_8011FAC0;
    SetN64_ResetSessionPlayerPools(resources, 0, 0);
    Scene_LoadLevelResources(resources + 0x3C8, 0, 0);
    D_800E3518->ready = 0;
    return 0;
}

s32 SmpOverlay_DestroyPakDialog(void) {
    Cache_FreeMemory(D_800E3518);
    D_800E3518 = 0;
    return 0;
}

int SmpOverlay_TickPakDialog(void) {
    if (D_800E28E0 < 2) {
        D_800E3518->elapsed++;
        if (D_800E3518->state == 0) {
            if (D_800E3518->elapsed < 6) {
                return 0;
            }
            Tsmos_ActivateControllerState();
            SmpOverlay_AdvancePakDialogPort();
        }
    }
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8041C46C_de(void) {
    return 0;
}

s32 SmpOverlay_ConsumePakDialogEvent(void) {
    MarkMenuEventHandled();
    return 0;
}

/* The dialog-event codes Menu_GetFocusedElementId reports differ per cartridge family: the European
   eu-x cart numbers them 0x3C9..0x3CF, the de cart 0x3C1..0x3C5, and eu/us/us-rev1 0x3C6..0x3CB.
   Each case below carries the same work in every family, only its label changes. */
s32 SmpOverlay_HandlePakDialogChoice(void) {
    MarkMenuEventHandled();
    switch (Menu_GetFocusedElementId()) {
#if defined(VERSION_EU_X)
    case 0x3CF:
#elif defined(VERSION_DE)
    case 0x3C4:
#else
    case 0x3CB:
#endif
        Widget_SetWidgetFlag08(D_800E3518->absent, 0);
        SmpOverlay_RefreshPakDialog();
        break;
#if defined(VERSION_EU_X)
    case 0x3CE:
#elif defined(VERSION_DE)
    case 0x3C5:
#else
    case 0x3CA:
#endif
        SmpOverlay_FinishPakDialog();
        break;
#if defined(VERSION_EU_X)
    case 0x3CA:
#elif defined(VERSION_DE)
    case 0x3C2:
#else
    case 0x3C7:
#endif
        SmpOverlay_AdvancePakDialogPort();
        break;
#if defined(VERSION_EU_X)
    case 0x3C9:
#elif defined(VERSION_DE)
    case 0x3C1:
#else
    case 0x3C6:
#endif
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
#if defined(VERSION_EU)
        D_800EFB34 = 1;
#elif defined(VERSION_EU_X)
        D_800EACF4 = 1;
#elif defined(VERSION_DE)
        D_800DF4C4 = 1;
#elif defined(VERSION_US)
        D_800DE174 = 1;
#else
        D_800E3514 = 1;
#endif
        PAKInterface_SetScreenPhase(6);
        SmXlate_SwitchScreen(0x13);
        break;
    }
    return 0;
}

s32 SmpOverlay_DispatchPakDialogEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E3524 != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E3524;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E351C)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E3520)) + offset))->field_0;
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

#if defined(VERSION_US)
unsigned int rodata_unresolved_8041C67C[1] = {
    0x00941000,
};
#endif

/* 800E1470_2.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
const unsigned char rodata_func_8041BE90_de_800EDAD0[3] = {
    0x25, 0x64, 0x00,
};
#endif
#if defined(VERSION_EU_X)
const unsigned int rodata_func_8041BE90_de_800EDAD0[1] = {
    0x25640086,
};
#endif
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800EDAD3[13] = {
    0x2F, 0x01, 0x29, 0x01, 0x2C, 0x01, 0x2A, 0x01, 0x2B, 0x08, 0x00, 0xFF, 0xE5,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif
