#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802591C0.h"
#include "types.h"









extern void func_8025B6F8_de(Header *header, s32 owner, s32 arg2);

static inline void func_802596D4_linkInit(ListLink *link) {
    link->prev = link;
    link->next = link;
}

static inline void func_802596D4_insertAfter(ListLink *at, ListLink *link) {
    link->next = at->next;
    link->prev = at;
    at->next->prev = link;
    at->next = link;
}

static inline void func_802596D4_voiceInit(VoiceRecAt8 *voice, s32 owner) {
    func_802596D4_linkInit(&voice->link);
    func_8025B6F8_de(&voice->header, owner, -1);
}

/* Initialises a channel set: records the owner, sets up its free and active lists with headers, and appends 32 initialised voices to the active list. */
void func_802596B4_de(ChannelSet *set, s32 owner) {
    s32 i;

    set->owner = owner;
    func_802596D4_linkInit(&set->free);
    func_8025B6F8_de(&set->freeHeader, owner, -1);
    func_802596D4_linkInit(&set->active);
    func_8025B6F8_de(&set->activeHeader, owner, -1);
    for (i = 0; i < 32; i++) {
        func_802596D4_voiceInit(&set->voices[i], owner);
        func_802596D4_insertAfter(set->active.prev, &set->voices[i].link);
    }
}
