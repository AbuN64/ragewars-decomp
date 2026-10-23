#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/ENTRYRECATE.H"
#include "WEAPONS/80213ED4.H"

/* Adds ammunition to a player's weapon slot: computes the slot's cap as func_80222D64_de does (zero for
   no slot, the character's cap unless option D_801462D5 is 1, otherwise D_800CE3E8's cap plus the
   profile bonus from D_80102B00 unless the flag at 0x1450 is set), and when the slot has room it
   selects weapon 1, 5 or 4 at 0xCC0 for slots 0, 1 and 2 if the slot was empty and ammunition is
   added, then adds the amount clamped to the cap. Returns whether the slot had room. Adapted from
   func_80222D64_de with the count read once into an int and the weapon selection as a switch. */





extern void *func_802AC950_de(s32);
extern u8 D_801462D5;
extern s32 D_800CE3E8[];
extern Profile D_80102B00[];




s32 func_80222BE8_de(void *player, s32 slot, s32 amount) {
    s16 *count;
    s32 cap;
    s32 room;
    s32 total;
    s32 have;

    count = (&((Actor_func_8022D290_de *)(player))->unk_0x05F4 + slot);
    if (slot == -1) {
        cap = 0;
    } else if (D_801462D5 != 1) {
        cap = ((Desc *)((Actor_func_8022D290_de *)(player))->field_0x18)->caps[slot];
    } else {
        cap = D_800CE3E8[slot];
        if (((Actor_func_8022D290_de *)(player))->unk_0x1450 == 0) {
            if (slot == 0) {
                cap += D_80102B00[((Actor_func_8022D290_de *)(player))->unk_0x05D4].bonus0;
            } else if (slot == 1) {
                cap += D_80102B00[((Actor_func_8022D290_de *)(player))->unk_0x05D4].bonus1;
            } else if (slot == 2) {
                cap += D_80102B00[((Actor_func_8022D290_de *)(player))->unk_0x05D4].bonus2;
            }
        }
    }
    have = *count;
    room = have < cap;
    if (room) {
        if (have == 0 && amount > 0) {
            switch (slot) {
            case 0:
                ((Actor_func_8022D290_de *)(player))->unk_0x0CC0 = 1;
                break;
            case 1:
                ((Actor_func_8022D290_de *)(player))->unk_0x0CC0 = 5;
                break;
            case 2:
                ((Actor_func_8022D290_de *)(player))->unk_0x0CC0 = 4;
                break;
            }
        }
        total = (s16) (*count += amount);
        if (total > cap) {
            total = cap;
        }
        *count = total;
    }
    return room;
}

/* Returns whether a player can take more ammunition for a pickup: looks up the pickup's weapon slot
   through func_802AC950_de, takes the cap as zero for no slot, the character's cap at 0x108 when option
   D_801462D5 is not 1, or otherwise D_800CE3E8's cap raised, unless the flag at 0x1450 is set, by the
   player profile's bonus byte for slots 0, 1 and 2 in D_80102B00, and compares the slot's count at
   0x5F4 against it. */





extern void *func_802AC950_de(s32);
extern u8 D_801462D5;
extern s32 D_800CE3E8[];
extern Profile D_80102B00[];






s32 func_80222D64_de(void *context, s32 arg1) {
    void *pickup;
    s32 slot;
    s16 *count;
    s32 cap;
    s32 base;

    pickup = func_802AC950_de(arg1);
    if (pickup == 0) {
        return 0;
    }
    slot = ((AmmoPickupDefinition *)(pickup))->slot;
    count = (&((Actor_func_8022D290_de *)(context))->unk_0x05F4 + slot);
    if (slot == -1) {
        cap = 0;
    } else {
        if (D_801462D5 != 1) {
            base = ((Desc *)((Actor_func_8022D290_de *)(context))->field_0x18)->caps[slot];
        } else {
            base = D_800CE3E8[slot];
            if (((Actor_func_8022D290_de *)(context))->unk_0x1450 == 0) {
                if (slot == 0) {
                    base += D_80102B00[((Actor_func_8022D290_de *)(context))->unk_0x05D4].bonus0;
                } else if (slot == 1) {
                    base += D_80102B00[((Actor_func_8022D290_de *)(context))->unk_0x05D4].bonus1;
                } else if (slot == 2) {
                    base += D_80102B00[((Actor_func_8022D290_de *)(context))->unk_0x05D4].bonus2;
                }
            }
        }
        cap = base;
    }
    return *count < cap;
}

/* Starts a player's ducking states from input: with button 0x1000 held and the player not already
   down (states 9 to 0xC or 0x26) it enters state 0xC, or while being hit (states 0x13 to 0x15) keeps
   the button latched at 0x38 instead; otherwise, when not being hit, holding direction bits 0x2000
   without 0x3, on the ground or descending no faster than D_800C7948[1] and not already down, it
   enters state 0xA. Returns whether a state was entered. */

extern f32 D_800C7948[];
extern s32 func_802227F4_de(void *, void *, s32);






s32 func_80222EA4_de(void *player, void *arg1) {
    s16 state;
    s32 hit;

    if (((Actor_func_802238E0_de *)(arg1))->inputFlags & 0x1000) {
        state = ((Actor_func_8022D290_de *)(player))->unk_0x0650;
        if (state != 0xB) {
            if (state != 0xC) {
                if (state != 9) {
                    if (state != 0xA) {
                        if (state != 0x26) {
                            if (state == 0x15 || state == 0x13 || state == 0x14) {
                                hit = 1;
                            } else {
                                hit = 0;
                            }
                            if (hit) {
                                ((Actor_func_8022D290_de *)(player))->unk_0x0038 |= 0x1000;
                                return 0;
                            }
                            func_802227F4_de(player, arg1, 0xC);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    state = ((Actor_func_8022D290_de *)(player))->unk_0x0650;
    if (state == 0x15 || state == 0x13 || state == 0x14) {
        hit = 1;
    } else {
        hit = 0;
    }
    if (hit) {
        return 0;
    }
    if ((((Actor_func_802238E0_de *)(arg1))->inputFlags & 0x2003) != 0x2000) {
        return 0;
    }
    if (!(((Actor_func_802238E0_de *)(arg1))->unk20 <= 0.0f)) {
        return 0;
    }
    if (!(D_800C7948[1] < ((Actor_func_802238E0_de *)(arg1))->unk20)) {
        return 0;
    }
    state = ((Actor_func_8022D290_de *)(player))->unk_0x0650;
    if (state == 0xB) {
        return 0;
    }
    if (state == 0xC) {
        return 0;
    }
    if (state == 9) {
        return 0;
    }
    if (state == 0xA) {
        return 0;
    }
    if (state == 0x26) {
        return 0;
    }
    func_802227F4_de(player, arg1, 0xA);
    return 1;
}

extern u8 *D_801041F0;

s32 func_80222FE0_de(void *playerObject, void *positionObject, s32 *unused) {
    ThrowPlayer *player = playerObject;
    ThrowPosition *position = positionObject;
    ThrowActor *actor, *selected;
    s32 kind;
    f32 offset, scale, xSpeed, angle;
    { void *object = D_801041F0; actor = object; }
    if (!(player->flags & 0x8000)) goto invalid;
    if (!actor) return 0;
    selected = player->selected;
    if (actor == selected) goto invalid;
    if (actor->category != 1) return 0;
    kind = actor->definition->kind;
    if (kind != 1 || !selected) return 0;
    if (actor->state.active) {
        angle = position->angle;
        offset = D_800C2860_de;
        xSpeed = player->speed * func_802B7130_de(angle + offset);
        scale = D_800C2864_de;
        actor->vx = xSpeed * scale;
        actor->vy = player->speed * D_800C2868_de;
        actor->vz = player->speed * func_802B6560_de(position->angle + offset) * scale;
        if (player->effect)
            func_80239324_de(player->effect, D_800C2870_de, 100.0f, D_800C2870_de, D_800C286C_de, kind, position->pos);
        if (selected->state.kind == 0x2E) actor->state.flags |= 0x200;
        actor->state.timer = -1;
        func_80214178_de(actor, &actor->state, 0x34);
    } else if (player->effect)
        func_80239324_de(player->effect, D_800C2878_de, 60.0f, D_800C2878_de, D_800C2874_de, kind, position->pos);
    return 1;
invalid:
    return 0;
}

#ifdef NON_MATCHING
#include "TYPES.H"

typedef struct { u8 pad0[0x79]; u8 yaw, pitch; s8 pitchMode; u8 pad7C; u8 freePitch; } ControlSettings;
typedef struct { u8 pad0[0x5D8]; ControlSettings *settings; u8 pad5DC[0xC0]; f32 yawInput, pitchInput; u8 pad6A4[0x80]; f32 pitch; u8 pad728[0xC4]; f32 damping; u8 pad7F0[0x9C4]; s32 locked; u8 pad11B8[0x20]; f32 cooldown; } ControlPlayer;
typedef struct { u8 pad0[0x6C]; f32 yaw; } ControlBody;
typedef struct { u8 pad0[0x50]; u32 flags; } Surface;
typedef struct { f32 enableYaw, yawRate, pitchRate, pitchScale, downScale, upScale; } ControlTuning;
extern void *func_8024E7DC_de(void *);
extern void func_80274870_de(f32 *, f32, f32);
extern f32 D_800C287C_de;
extern f32 D_800C2880_de;
extern f32 D_800C2884_de;
extern f32 D_800C2888_de;
extern f32 D_800C288C_de;
extern f32 D_800C2890_de;
extern f32 D_800C2894_de;
extern f32 D_800C2898_de;
extern f32 D_800C289C_de;
extern f32 D_800C28A0_de;
extern f32 D_800C28A4_de;
extern f32 D_800C28A8_de;
extern f32 D_800C28AC_de;
extern f32 D_800C28B0_de;

void func_802231D4_de(ControlPlayer *player, ControlBody *body, ControlTuning *tuning) {
    f32 damp, yawRate, pitchRate, input, value;
    ControlSettings *settings;
    Surface *surface;
    if (player->locked != 0 || 0.0f < player->cooldown) return;
    damp = player->damping * D_800C287C_de;
    settings = player->settings;
    input = ((f32)settings->yaw * D_800C2880_de - D_800C2884_de) * D_800C2888_de;
    damp = D_800C2884_de - damp;
    value = damp * tuning->yawRate;
    yawRate = (input + D_800C288C_de) * value;
    input = ((f32)settings->pitch * D_800C2880_de - D_800C2884_de) * D_800C2890_de;
    value = damp * tuning->pitchRate;
    value = value * tuning->pitchScale;
    pitchRate = (input + D_800C2894_de) * value;
    if (settings->pitchMode == 0) {
        if (settings->freePitch == 0) pitchRate = D_800C2898_de;
    } else if (settings->pitchMode == 1) pitchRate = D_800C2888_de;
    surface = func_8024E7DC_de(body);
    if (surface == 0 || (surface->flags & 0x6000) != 0x2000) {
        if (tuning->enableYaw != 0.0f) {
            value = player->yawInput * D_800C289C_de;
            value = value * tuning->enableYaw;
            value = value * D_800C28A0_de;
            func_80274870_de(&body->yaw, body->yaw + value, yawRate);
        }
    }
    input = -player->pitchInput * D_800C28A4_de;
    if (input < 0.0f) value = input * D_800C28A8_de * tuning->downScale;
    else value = input * D_800C28AC_de * tuning->upScale;
    value = value * D_800C28B0_de;
    func_80274870_de(&player->pitch, value, pitchRate);
}
#else
INCLUDE_ASM("span_1000", func_802231D4_de);
#endif
