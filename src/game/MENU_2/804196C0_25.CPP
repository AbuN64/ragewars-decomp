#include "COMMON/ANIMATION.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "TYPES.H"
#include "SCENE/802508E0_13.H"
#include "MATH/80299ECC.H"

/* Calls MarkMenuEventHandled and, for an event of kind one on a slot with no word at 0x5C whose child at 0x4C has flag 0x10 of its halfword at 0x12 set and a target at 0x34, passes the owner, the slot and the target to func_8041B8DC_de, returning zero. */




extern void MarkMenuEventHandled();

extern void SmpOverlay_ShowSlotNode(struct sm_dlmultiuser_t *, s32, void *);

/* After MarkMenuEventHandled, forwards an event for a channel to func_802995D4_de with the channel's handler id
   (short at 0xC of the handler at 0x4C) when the channel is not muted (word at 0x5C) and has a handler;
   returns 0. */




extern void MarkMenuEventHandled(void);


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
    func_802995D4_de(h->unkC, 1, channel, value, extra);
    return 0;
}

s32 SmpOverlay_FreeEventObject(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}
