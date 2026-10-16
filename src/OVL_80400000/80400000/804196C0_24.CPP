#include "span_16E000/code_804196C0.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8041B020.h"
#include "TYPES.H"

/* Calls func_8029973C_de and, for an event of kind one on a slot with no word at 0x5C whose child at 0x4C has flag 0x10 of its halfword at 0x12 set and a target at 0x34, passes the owner, the slot and the target to func_8041B8DC_de, returning zero. */




extern void func_8029973C_de();

extern void func_8041B8DC_de(struct ContextCode804196C0 *, s32, void *);

/* After func_8029973C_de, forwards an event for a channel to func_802995D4_de with the channel's handler id
   (short at 0xC of the handler at 0x4C) when the channel is not muted (word at 0x5C) and has a handler;
   returns 0. */




extern void func_8029973C_de(void);

extern void func_802995D4_de(int, int, int, int, int);

/* Calls func_802547E4_de with the arguments it was given and returns zero. */
extern void func_802547E4_de();

s32 func_8041BB3C_de(struct ContextCode804196C0 *owner, s32 arg1, s32 slot, s32 kind) {
    struct Child *child;

    func_8029973C_de();
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
    func_8041B8DC_de(owner, (u16)slot, child->target);
    return 0;
}

s32 func_8041BBD0_de(struct ContextCode804196C0 *owner, s32 arg1, s32 slot, s32 kind) {
    struct ChildRecAt2C *child;

    func_8029973C_de();
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
    func_8041B8DC_de(owner, (u16)slot, child->target);
    return 0;
}

s32 func_8041BC64_de(struct ContextCode804196C0 *owner, s32 arg1, s32 slot, s32 kind) {
    struct ChildRecAt38 *child;

    func_8029973C_de();
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
    func_8041B8DC_de(owner, (u16)slot, child->target);
    return 0;
}

s32 func_8041BCF8_de(struct ContextCode804196C0 *owner, s32 arg1, s32 slot, s32 kind) {
    struct ChildRecAt30 *child;

    func_8029973C_de();
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
    func_8041B8DC_de(owner, (u16)slot, child->target);
    return 0;
}

int func_8041BD8C_de(Mixer *mixer, int unused, int channel, int value, int extra) {
    ObjRecAtCV1 *h;

    func_8029973C_de();
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

s32 func_8041BE08_de(void) {
    func_802547E4_de();
    return 0;
}
