#include "COMMON/VIEWFLAGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

/* Posts a text as on-screen messages for a target: the target's messages still in the pool's list at 0xE40
 * are unlinked and returned to the owner's list at 0xF24, then the text (or D_800D7028 when given D_800D7034)
 * is split at newlines and for each non-empty line the oldest message node of the owner's list is recycled
 * and set up as a kind 2 message for the target, centred horizontally 80 pixels above the bottom of the
 * screen and scaled by the given size. Returns the last message node. */




extern func_80237E70_G1 D_800D7028;

extern func_80237E70_G1 D_800D7034;

extern s32 D_800E28D0;
extern s32 D_800E28D4;

extern void func_80239CE0_de(void *arg0);

static inline Message *recycle(void *owner, void *pool) {
    Message *oldest;

    oldest = ((struct ScreenMessageOwner *)owner)->activeMessages.head;
    if (oldest != 0) {
        func_80239CE0_de(oldest);
        func_80255ED8_de(&((struct ScreenMessageOwner *)owner)->activeMessages, oldest);
        func_80255D14_de(&((struct ScreenMessagePool *)pool)->freeMessages, oldest);
    }
    return oldest;
}

static inline Message *post_lines(void *owner, void *pool, u8 *text, s32 kind, f32 size, s32 target) {
    Message *message;
    s32 height;
    u8 *line;
    u8 *p;

    message = 0;
    if (pool == 0) {
        return message;
    }
    if (text == D_800D7034.unk0) {
        text = D_800D7028.unk0;
    }
    p = text;
    line = p;
    while (*p != 0) {
        p++;
        if (*p == '\n' || *p == 0) {
            if (line != p) {
                message = recycle(owner, pool);
                if (message != 0) {
                    message->kind = kind;
                    message->text = line;
                    message->timer = 0;
                    message->alpha = 1.0f;
                    message->target = target;
                    message->pad20 = 0;
                    message->progress = 0;
                    message->pad2C = 0;
                    message->scaleX = 1.0f;
                    message->scaleY = 1.0f;
                    height = D_800E28D4;
                    message->x = D_800E28D0 / 2;
                    message->y = height - 80;
                    message->size = size * 15.0f;
                }
                line = p + 1;
            }
        }
    }
    return message;
}

extern void *D_80140FE8_de;

extern void func_8044A7D0_de(int a);

extern u32 func_802337D0_de(s32);

Message *Camera_PostTargetedScreenMessage(void *owner, void *pool, u8 *text, s32 target, f32 size) {
    Message *pending;
    Message *next;

    if (pool == 0) {
        return 0;
    }
    for (pending = ((struct ScreenMessagePool *)pool)->freeMessages.head; pending != 0; pending = next) {
        next = pending->next;
        if (pending->target == target) {
            func_80255ED8_de(&((struct ScreenMessagePool *)pool)->freeMessages, pending);
            func_80255CB8_de(&((struct ScreenMessageOwner *)owner)->activeMessages, pending);
        }
    }
    pending = post_lines(owner, pool, text, 2, size, target);
    return pending;
}

void func_80239AF4_de(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool) {
    Node_func_80239AF4_de *message;
    Node_func_80239AF4_de *nextMessage;
    void *freeList;

    if (pool != 0) {
        message = pool->freeMessages.tail;
        freeList = &pool->freeMessages;
        if (message != 0) {
            do {
                nextMessage = message->next;
                func_80255ED8_de(freeList, message);
                func_80255CB8_de(&owner->activeMessages, message);
                message = nextMessage;
                freeList = &pool->freeMessages;
            } while (message != 0);
        }
    }
}

void func_80239B64_de(s32 arg0) {
    Node_func_80239AF4_de *next;
    Node_func_80239AF4_de *temp_s0_2;
    Node_func_80239AF4_de *var_s1;
    Node_func_80239AF4_de *var_s1_2;
    void *temp_s2;
    void *var_s2;

    temp_s2 = (void *)(arg0 + 0x40);
    if (temp_s2 != 0) {
        var_s1 = ((struct ScreenMessagePool *)temp_s2)->freeMessages.tail;
        if (var_s1 != 0) {
            do {
                next = var_s1->next;
                func_80255ED8_de(&((struct ScreenMessagePool *)temp_s2)->freeMessages, var_s1);
                func_80255CB8_de(&((struct ScreenMessageOwner *)arg0)->activeMessages, var_s1);
                var_s1 = next;
            } while (var_s1 != 0);
        }
    }

    var_s2 = D_80140FE8_de;
    if (var_s2 != 0) {
        do {
            var_s1_2 = ((struct ScreenMessagePool *)var_s2)->freeMessages.tail;
            if (var_s1_2 != 0) {
                do {
                    temp_s0_2 = var_s1_2->next;
                    func_80255ED8_de(&((struct ScreenMessagePool *)var_s2)->freeMessages, var_s1_2);
                    func_80255CB8_de(&((struct ScreenMessageOwner *)arg0)->activeMessages, var_s1_2);
                    var_s1_2 = temp_s0_2;
                } while (var_s1_2 != 0);
            }
            var_s2 = ((struct ScreenMessagePool *)var_s2)->next;
        } while (var_s2 != 0);
    }
}

/** Thin wrapper forwarding an offset argument to func_8044A7D0_de. */
void func_80239C20_de(int arg0) {
    func_8044A7D0_de(arg0 + 0x570);
}

void *func_80239C3C_de(void *arg0, struct ScreenMessagePool *arg1) {
    struct ScreenMessageOwner *owner = arg0;
    struct ScreenMessagePool *pool = arg1;
    void *message;

    message = owner->activeMessages.head;
    if (message != 0) {
        func_80239CE0_de(message);
        func_80255ED8_de(&owner->activeMessages, message);
        func_80255D14_de(&pool->freeMessages, message);
    }
    return message;
}

void func_80239C9C_de(s32 arg0, s32 arg1, s32 arg2) {
    func_80255ED8_de(arg1 + 0xE40, arg2);
    func_80255CB8_de(arg0 + 0xF24, arg2);
}

void func_80239CE0_de(void *arg0) {
    struct Message *message = arg0;
    message->kind = 0;
    message->target = 0;
}

/** Clear four consecutive object words beginning at offset 4. */
void func_80239CEC_de(void *arg0) {
    struct Channel *channel = arg0;
    channel->level = 0.0f;
    channel->state[0] = 0;
    channel->state[1] = 0;
    channel->state[2] = 0;
}

/** Stores the float argument scaled by D_800C8658 at 0x4 of the object and the int argument at 0x0. */




void func_80239D00_de(struct Channel *channel, float arg1, int arg2) {
    channel->level = arg1 * (D_800C8658);
    channel->mode = arg2;
}

/* Evaluates a wave: kind 1 returns func_802B7130_de of the phase at 0x10 scaled by D_800C865C, times
   the amplitude at 0xC; kind 0 returns func_80274A90_de over minus to plus the amplitude; any other
   kind returns zero. */






f32 func_80239D1C_de(struct Wave *wave) {
    switch (wave->kind) {
    case 1:
        return func_802B7130_de(wave->phase * D_800C865C) * wave->amplitude;
    case 0:
        return func_80274A90_de(-wave->amplitude, wave->amplitude);
    }
    return 0.0f;
}

/** Zero the object's vector fields and reset the scale field to the default. */
void func_80239D90_de(void *arg0) {
    struct RecordRecAt18 *o = arg0;
    struct Channel *channel0;
    struct Channel *channel1;
    struct Channel *channel2;
    f32 diag;

    diag = D_800C3570_de;
    channel0 = &o->channels[0];
    o->triple.x = 0;
    o->triple.y = 0;
    o->triple.z = 0;
    o->value = diag;
    channel0->level = 0;
    channel0->state[0] = 0;
    channel0->state[1] = 0;
    channel0->state[2] = 0;
    channel1 = &o->channels[1];
    channel2 = &o->channels[2];
    channel1->level = 0;
    channel1->state[0] = 0;
    channel1->state[1] = 0;
    channel1->state[2] = 0;
    channel2->level = 0;
    channel2->state[0] = 0;
    channel2->state[1] = 0;
    channel2->state[2] = 0;
}

/* Configures a three-channel record: copies a by-value three-word block to offset 8 and a value to
   0x14, and gives each of the channels at 0x18, 0x2C and 0x40 the same mode word and a level scaled
   by the pooled constant D_800C8664. */








void func_80239DE8_de(struct RecordRecAt18 *record, f32 first, f32 second, f32 third, f32 value, s32 mode,
                   Triple triple) {
    record->triple = triple;
    record->value = value;
    record->channels[0].mode = mode;
    record->channels[1].mode = mode;
    record->channels[2].mode = mode;
    record->channels[0].level = first * D_800C8664;
    record->channels[1].level = second * D_800C8664;
    record->channels[2].level = third * D_800C8664;
}

s32 func_80239E48_de(s32 arg0) {
    s32 result;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_v0;

    temp_s1 = func_802337D0_de(arg0 + 0x18);
    temp_s0 = func_802337D0_de(arg0 + 0x2C);
    temp_v0 = func_802337D0_de(arg0 + 0x40);
    result = 0;
    if ((temp_s1 != 0) && (temp_s0 != 0)) {
        result = temp_v0 > 0U;
    }
    return result;
}
