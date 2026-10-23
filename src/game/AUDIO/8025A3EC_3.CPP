#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "AUDIO/8025A3EC.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"
#include "AUDIO/EXTERNS.H"
#include "COMMON/UNUSED.H"

/* Updates a playing view each frame: records the result of func_802395A4_de for its position in the context, selects its channel and checks whether it still plays; a view past its end, finished once, or whose track changed is marked done, and a done view that still plays is stopped once per frame and loses its handle; a stopped view first waits out its hold count, then is released with its slot and state cleared unless it is fading, while a playing view copies its tracked position and runs its three per-frame updates. The first channel selection matches as an inline helper returning the channel. */









#include "COMMON/MENU_MATCH_GLOBALS.H"
struct ALSndPlayer;
extern void func_802B2ED0_de(struct ALSndPlayer *player, short index, unsigned char value);
extern void func_80258740_de(s32 *arg0);
extern void func_802587A4_de(s32 *arg0);
extern short func_8025E500_de(void *arg0);


extern s32 func_802395A4_de(MenuMatchGlobals *, Triple *);
extern void func_802B2D80_de(char *);
extern void func_802B25D0_de(char *, s32);
extern void Audio_UpdateVoiceVolume(View_func_8025AE1C_de *);
extern void func_8025A844_de(View_func_8025AE1C_de *);
extern void func_8025AB94_de(View_func_8025AE1C_de *);




static inline char *selectChannel(ContextCode8025A3EC *context, s32 slot) {
    func_802B2F00_de(((OwnerCode8025A3EC *)context)->sound, context->slots.ids[slot]);
    return ((OwnerCode8025A3EC *)context)->sound;
}

void func_8025AE1C_de(View_func_8025AE1C_de *view) {
    char *channel;
    ContextCode8025A3EC *context;
    Slots *slots;
    s32 playing;

    view->context->result = func_802395A4_de(&D_80145088, &view->position);
    playing = func_802B2620_de(selectChannel(view->context, view->slot));
    if (view->time <= D_800C3F68_de || ((view->flags & 4) && view->finished == 0)) {
        view->done = 1;
    }
    if (view->followTrack != 0 && view->context->track != view->trackId) {
        view->done = 1;
    }
    if (playing != 0) {
        if (view->done != 0) {
            view->done = 1;
            view->tracked = 0;
            context = view->context;
            if (view->frame != context->frame) {
                channel = ((OwnerCode8025A3EC *)context)->sound;
                func_802B2F00_de(channel, context->slots.ids[view->slot]);
                if (func_802B2620_de(channel) != 0) {
                    alSndpStop(channel);
                }
                view->handle = -1;
            }
            return;
        }
    } else if (view->hold > 0) {
        view->hold--;
        view->flags |= 0x10;
        return;
    }
    if ((view->flags & 0x18) == 0x10) {
        func_802B2D80_de(((OwnerCode8025A3EC *)view->context)->sound);
        return;
    }
    if (playing == 0) {
        context = view->context;
        slots = &context->slots;
        func_802B25D0_de(((OwnerCode8025A3EC *)context)->sound, slots->ids[view->slot]);
        slots->ids[view->slot] = -1;
        view->field38 = 0;
        view->fieldC = -1;
        view->field8 = -1;
        view->trackId = -1;
        view->field3A = -1;
        view->fieldB4 = -1;
        return;
    }
    if (view->tracked != 0) {
        view->position = *view->tracked;
    }
    Audio_UpdateVoiceVolume(view);
    func_8025A844_de(view);
    func_8025AB94_de(view);
}

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "AUDIO/EXTERNS.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"
typedef struct ListNode_8025B034 {
    char pad0[4];
    struct ListNode_8025B034 *next;
    char pad8[0x38];
    s16 priority;
} ListNode_8025B034;
s16 func_8025B034_de(char *player, s32 variant, s32 count, s32 priority, s32 arg4) {
    ContextCode8025A3EC *context;
    View_func_8025AE1C_de *view;
    View_func_8025AE1C_de *iter;
    s32 cur;
    Slots *slots;
    ListNode_8025B034 *head;
    ListNode_8025B034 *node;
    char *channel;
    s32 best;
    s32 found;
    s32 limit;
    s32 i;
    s32 ret;
    context = *(ContextCode8025A3EC **)player;
    iter = (View_func_8025AE1C_de *)(player + 4);
    slots = &context->slots;
    best = (s16)priority;
    found = -1;
    limit = best;
    for (i = 0; i < 16; i++) {
        if (slots->ids[i] == -1) {
            return i;
        }
        cur = ((View_func_8025AE1C_de *)((char *)iter + i * 0xCC))->field38;
        if (cur < limit && best >= cur && cur != 100) {
            best = cur;
            found = i;
        }
    }
    if (found == -1) {
        return -1;
    }
    if (slots->ids[found] == -1) {
        node = *(ListNode_8025B034 **)((char *)context + 0x140);
        if (node != (ListNode_8025B034 *)((char *)context + 0x13C) && (s16)priority < node->priority) {
            return -1;
        }
        return found;
    }
    view = (View_func_8025AE1C_de *)((char *)iter + (s16)found * 0xCC);
    view->done = 1;
    view->tracked = 0;
    context = view->context;
    channel = ((OwnerCode8025A3EC *)context)->sound;
    if (view->frame != context->frame) {
        func_802B2F00_de(channel, context->slots.ids[view->slot]);
        if (func_802B2620_de(channel) != 0) {
            alSndpStop(channel);
        }
        view->handle = -1;
    }
    if (*(s32 *)(player + 0xCD0) != -1) {
        return -1;
    }
    return 0x10;
}
#else
INCLUDE_ASM("span_1000", func_8025B034_de);
#endif

#ifdef NON_MATCHING
typedef struct SoundEngine {
    char pad0[0x7C];
    ALBank_s *bank;
    char pad80[4];
    char pool[0xDC - 0x84];
    s16 slots[16];
    u16 allocated;
    char padFE[4];
    s16 current;
    s32 effect;
    s32 serial;
    char pad10C[0x2B8C - 0x10C];
    s16 priorityTable;
    char pad2B8E[2];
    s32 f2B90;
    char pad2B94[0x2BAC - 0x2B94];
    s32 f2BAC;
    char pad2BB0[0x2BBC - 0x2BB0];
    f32 f2BBC;
} SoundEngine;
typedef struct SoundVoice {
    char pad0[4];
    s32 userData;
    s32 slot;
    s32 serial;
    s32 effect;
    char pad14[4];
    s32 reach;
    s32 reachCopy;
    s16 pitchOffset;
    char pad22[2];
    s32 zero24;
    s16 pan;
    char pad2A[0xA];
    f32 gain;
    s16 priority;
    s16 note;
    s16 variant;
    char pad3E[0x12];
    s32 zero50;
    u8 mode;
    char pad55[0x47];
    s32 noteLength;
    s32 noteWord;
    s32 f_A4;
    s32 f_A8;
    s32 zeroAC;
    char padB0[4];
    s32 f_B4;
    f32 f_B8;
    s32 flagBC;
    s32 f_C0;
    s32 flagC4;
    char padC8[4];
} SoundVoice;
typedef struct SoundPlayer {
    SoundEngine *engine;
    SoundVoice voices[1];
} SoundPlayer;
extern float D_800C3F6C_de, D_800C3F70_de, D_800C3F74_de;
extern s32 D_800CBAD4[];
extern s32 D_800CBAE4[];
extern s32 func_8025E518_de(void *);
extern s32 func_8025E524_de(void *);
extern s32 func_8025E548_de(void *);
extern s32 func_8025E578_de(void *);
extern s16 func_802B2510_de(void *, s32);
/* Starts a note on a free voice: picks the voice with func_8025B034_de, asks the sound set for its sample, and
 * fills in the voice record (volume, pan, pitch, which categories its effect belongs to). Returns the voice, or
 * 0 when the note's set is too small, the chance roll fails, or no voice or sample is available. */
SoundVoice *func_8025B1C8_de(SoundPlayer *player, ControllerCode802591C0 *note, s16 variant, s32 userData) {
    SoundEngine *engine;
    SoundVoice *voice;
    s16 *slots;
    s16 index;
    s16 slot;
    s16 priority;
    s16 count;
    s32 roll;
    s32 i;
    f32 pitch;
    u32 pitchByte;

    count = func_8025E500_de(note);
    priority = (s8)func_8025E518_de(note);
    engine = player->engine;
    slots = engine->slots;
    if (engine->bank->instArray[0]->soundCount < count) {
        return 0;
    }
    func_80258740_de((s32 *)engine);
    if ((s8)func_8025E524_de(note) != 100) {
        roll = func_8027451C_de() % 100;
        if (!(roll < (s8)func_8025E524_de(note))) {
            goto fail;
        }
    }
    index = func_8025B034_de((s8 *)player, variant, count, priority, (s16)func_8025E578_de(note));
    if (index == -1) {
        goto fail;
    }
    voice = &player->voices[index];
    if (index == 0x10) {
        voice->userData = userData;
        voice->serial = engine->serial++;
        voice->slot = 99;
    } else {
        engine->current = index;
        slot = func_802B2510_de(engine->pool, (s32)engine->bank->instArray[0]->soundArray[count]);
        slots[index] = slot;
        if (slot == -1) {
            voice->serial = -1;
            voice->slot = -1;
            voice->priority = 0;
            engine->current = -1;
            goto fail;
        }
        pitch = (f32)priority * D_800C3F6C_de;
        engine->allocated++;
        voice->userData = userData;
        voice->serial = engine->serial++;
        voice->slot = slots[index];
        voice->noteLength = note->sample;
        if (D_800C3F70_de <= pitch) {
            pitchByte = (u32)(pitch - D_800C3F70_de) | 0x80000000;
        } else {
            pitchByte = (u32)pitch;
        }
        func_802B2ED0_de(engine->pool, slots[index], pitchByte & 0xFF);
    }
    voice->f_A8 = engine->priorityTable;
    voice->f_C0 = engine->f2BAC;
    voice->flagBC = 0;
    for (i = 0; i < 4; i++) {
        if (voice->f_A8 == D_800CBAD4[i]) {
            voice->flagBC = 1;
            break;
        }
    }
    voice->flagC4 = 1;
    for (i = 0; i < 6; i++) {
        if (voice->f_A8 == D_800CBAE4[i]) {
            voice->flagC4 = 0;
            break;
        }
    }
    voice->f_B4 = engine->f2B90;
    voice->zeroAC = 0;
    voice->f_B8 = engine->f2BBC;
    voice->pitchOffset = note->pitch;
    voice->priority = priority;
    voice->reachCopy = 0x7D00;
    voice->reach = 0x7D00;
    voice->zero24 = 0;
    voice->pan = 0x40;
    voice->note = count;
    voice->variant = variant;
    voice->effect = engine->effect;
    voice->gain = D_800C3F74_de;
    voice->mode = func_8025E548_de(note);
    voice->noteWord = (s16)func_8025E578_de(note);
    voice->zero50 = 0;
    func_802587A4_de((s32 *)engine);
    return voice;
fail:
    func_802587A4_de((s32 *)engine);
    return 0;
}
#else
INCLUDE_ASM("span_1000", func_8025B1C8_de);
#endif
