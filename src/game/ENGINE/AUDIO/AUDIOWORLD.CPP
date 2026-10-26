#include "COMMON/LISTNODE.H"
#include "AUDIO/80259280.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "TEXTURE/80256220_16.H"
#include "COMMON/SHAREDPLAYER.H"
#include "ENGINE/AUDIO/AUDIOWORLD.H"

extern void Audio_InitializeVoiceRecord(void *arg0, int arg1, int arg2);

/* Starts a sound instance from a description: when the scene's free node list is not empty it takes the
 * first node under the audio lock (func_80258740_de/func_802587A4_de), unlinks it, gives it the next handle, the
 * volume, sample, priority, pan and pitch fields decoded from the description, full gain, the scene frame
 * and the position, prepares its channel through Audio_SetVoiceTrackId and Audio_InitializeVoiceParameters and inserts it into the
 * active list ahead of the first lower-priority node; returns the handle or -1 when no node is free. */











extern void Audio_InitializeVoiceParameters(void *, void *, s32);


extern s8 func_8025E518_de(void *);


extern u8 func_8025E548_de(void *);

extern s16 func_8025E578_de(void *);


/* Services the pending glyph requests of a text cache: each request still counting down its delay is ticked and, when it reaches zero, stamped with the current frame and the next sequence number; a request older than sixteen frames is moved to the done list, otherwise it reserves a cell for its glyph and a texture for its bitmap, stopping when none is free, copies itself into the cell, uploads the cell through Audio_UpdateSoundSlot and moves to the done list. The slot address is written as the doubled slot plus the table address because the cartridge adds the scaled index first; array indexing puts the table first (1 word). */


















extern s16 func_802B2510_de(char *, s32);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern void Audio_UpdateSoundSlot(ContextCode802591C0 *, s32, s32, char *);

static inline void append(ListHead *head, Entry_func_80259440_de *entry) {
    entry->prev = head->prev;
    entry->next = (Entry_func_80259440_de *)head;
    head->prev->next = entry;
    head->prev = entry;
}

s32 func_80259260_de(ManagerRecAtD8V1 *manager, void *desc, Vec3Words *position, s32 volume, s32 extra) {
    NodeRecAtC8 *node;
    NodeRecAtC8 *first;
    NodeRecAtC8 *at;
    s32 *scene;
    s32 priority;

    if (manager->free.next != (NodeRecAtC8 *)&manager->free) {
        func_80258740_de(manager->scene);
        first = manager->free.next;
        first->prev->next = first->next;
        first->next->prev = first->prev;
        scene = manager->scene;
        node = first;
        node->handle = scene[0x108 / 4];
        scene[0x108 / 4] = node->handle + 1;
        node->volume = volume;
        node->voice = -1;
        node->volume16 = volume;
        node->group = func_8025E500_de(desc);
        node->priority = func_8025E518_de(desc);
        node->sample = func_8025E50C_de(desc);
        node->pan = func_8025E548_de(desc);
        node->flags = func_8025E578_de(desc);
        node->pitch = func_8025E554_de(desc);
        node->gainB = 0x7D00;
        node->gainA = 0x7D00;
        node->time = 0;
        node->frame = manager->scene[0x104 / 4];
        node->position = *position;
        node->pad58 = 0;
        node->padB4 = 0;
        Audio_SetVoiceTrackId(node->channel, ((struct ContextRecAt2BC0 *)manager->scene)->selectedSound);
        node->mix = manager->scene[0x2BAC / 4];
        Audio_InitializeVoiceParameters(node->channel, desc, extra);
        at = manager->active.next;
        priority = node->priority;
        while (at != (NodeRecAtC8 *)&manager->active) {
            if (at->priority < priority) {
                break;
            }
            at = at->next;
        }
        node->prev = at->prev;
        node->next = at;
        at->prev->next = node;
        at->prev = node;
        func_802587A4_de(manager->scene);
        return node->handle;
    }
    return -1;
}

void func_80259440_de(Cache *cache) {
    s16 *slots;
    char *textures;
    Glyphs *glyphs;
    Entry_func_80259440_de *entry;
    Entry_func_80259440_de *next;
    s32 slot;
    s16 *cursor;
    s32 free;
    CellCode802591C0 *cell;

    func_80258740_de(cache->context);
    slots = cache->context->slots;
    textures = cache->context->textures;
    glyphs = cache->context->font->glyphs;
    for (entry = cache->pending.next; entry != (Entry_func_80259440_de *)&cache->pending; entry = next) {
        next = entry->next;
        if (entry->delay != 0) {
            if (--entry->delay == 0) {
                entry->frame = cache->context->frame;
                entry->sequence = cache->context->sequence++;
                entry->fieldA8 = 0;
            }
            continue;
        }
        if (cache->context->frame - entry->frame >= 16) {
            entry->prev->next = next;
            entry->next->prev = entry->prev;
            append(&cache->done, entry);
            continue;
        }
        slot = Channel_SelectVoiceSlot((struct RecordD90 *)cache->context->cells, entry->style, entry->font, entry->glyph, 0);
        if (slot == -1 || slot == 16) {
            break;
        }
        cursor = (s16 *)((slot << 1) + (u32)slots);
        free = *cursor;
        if (free != -1) {
            break;
        }
        *cursor = func_802B2510_de(textures, glyphs->bitmaps[entry->font]);
        if (*cursor == free) {
            break;
        }
        cell = (CellCode802591C0 *)(cache->context->cells + 4 + slot * 0xCC);
        func_802BD3A0_de(cell, entry->body, 0xCC);
        cell->sequence = entry->sequence;
        cell->texture = *cursor;
        cell->frame = cache->context->frame;
        cell->index = slot;
        Audio_UpdateSoundSlot(cache->context, cell->sequence, 0, cell->data);
        entry->sequence = free;
        entry->glyph = free;
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
        append(&cache->done, entry);
    }
    func_802587A4_de(cache->context);
}

void func_8025966C_de(void *sentinel, s32 owner) {
    (((struct ObjectLinks8 *) ((s8 *) sentinel))->unk_4) = sentinel;
    (((struct ObjectLinks8 *) ((s8 *) sentinel))->unk_0) = sentinel;
    Audio_InitializeVoiceRecord(sentinel + 8, owner, -1);
}

void *AudioWorld_UnlinkChannelNode(LinkPair *channelNode) {
    channelNode->first[1] = (void *) channelNode->second;
    channelNode->second[0] = (void *) channelNode->first;
    return channelNode;
}

extern void Audio_InitializeVoiceRecord(void *header, int owner, int arg2);

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
    Audio_InitializeVoiceRecord(&voice->header, owner, -1);
}

/* Starts a copy of a sound table entry when that entry is idle: takes the first node of the free list at
 * 0xD8, copies the 0xCC-byte entry into it, sets its owner value and position, clears its timer and
 * inserts it into the active list at 0x4 ahead of the first node with lower priority; the scene's
 * current selection fields are then reset. */














/* Initialises a channel set: records the owner, sets up its free and active lists with headers, and appends 32 initialised voices to the active list. */
void func_802596B4_de(ChannelSet *set, s32 owner) {
    s32 i;

    set->owner = owner;
    func_802596D4_linkInit(&set->free);
    Audio_InitializeVoiceRecord(&set->freeHeader, owner, -1);
    func_802596D4_linkInit(&set->active);
    Audio_InitializeVoiceRecord(&set->activeHeader, owner, -1);
    for (i = 0; i < 32; i++) {
        func_802596D4_voiceInit(&set->voices[i], owner);
        func_802596D4_insertAfter(set->active.prev, &set->voices[i].link);
    }
}

void AudioWorld_StartSpatialVoice(ManagerRecAtD8V2 *manager, s32 index, s32 owner, CVector3 *position) {
    Entry_func_80259784_de *entry;
    NodeRecAt4C *node;
    NodeRecAt4C *at;
    NodeRecAt4C *first;
    s32 priority;

    entry = &manager->scene->entries[index];
    if (entry->busy != 0) {
        return;
    }
    first = manager->free.next;
    if (first != (NodeRecAt4C *)&manager->free) {
        first->prev->next = first->next;
        first->next->prev = first->prev;
        node = first;
        func_802BD3A0_de(node->pad8, entry, 0xCC);
        node->owner = owner;
        node->position.x = position->x;
        node->position.y = position->y;
        node->position.z = position->z;
        node->timer = 0;
        at = manager->active.next;
        priority = node->priority;
        while (at != (NodeRecAt4C *)&manager->active) {
            if (at->priority < priority) {
                break;
            }
            at = at->next;
        }
        node->prev = at->prev;
        node->next = at;
        at->prev->next = node;
        at->prev = node;
    }
    manager->scene->activeSelection = 0;
    manager->scene->pendingSelection = -1;
    manager->scene->previousSelection = -1;
    manager->scene->selection = -1;
}

void func_802598B4_de(ChannelSet *channelSet, s32 soundId) {
    Node_func_802598B4_de *node;
    Node_func_802598B4_de *next;
    Node_func_802598B4_de *end;
    Node_func_802598B4_de *initial_end;
    Node_func_802598B4_de *tail_end;

    node = (Node_func_802598B4_de *)channelSet->free.prev;
    tail_end = (Node_func_802598B4_de *)&channelSet->active;
    initial_end = (Node_func_802598B4_de *)&channelSet->free;
    if (node != initial_end) {
        end = initial_end;
        do {
            next = node->next;
            if (node->value == soundId) {
                node->prev->next = next;
                node->next->prev = node->prev;
                node->prev = (Node_func_802598B4_de *)channelSet->active.next;
                node->next = tail_end;
                ((Node_func_802598B4_de *)channelSet->active.next)->next = node;
                channelSet->active.next = (ListLink *)node;
            }
            node = next;
        } while (node != end);
    }
}

/* Moves nodes whose key differs from arg1 (or every node when arg1 is -1) from the active list to the tail of the list rooted at offset 0xD8. Adapted from func_80259988_de, with the match test inverted, a -1 wildcard added, and the tail insertion written as a do-while(0) list macro. */


void func_80259918_de(OwnerRecAtD8 *channelOwner, s32 retainedKey) {
    Node_func_80259918_de *node;
    Node_func_80259918_de *next;
    node = channelOwner->activeNext;
    while (node != (Node_func_80259918_de *) &channelOwner->activePrev) {
        next = node->next;
        if (retainedKey == -1 || node->key != retainedKey) {
            node->prev->next = next;
            node->next->prev = node->prev;
            do { Node_func_80259918_de *tail_ = (channelOwner)->otherPrev; (node)->next = (Node_func_80259918_de *) &(channelOwner)->otherPrev; (node)->prev = tail_; (channelOwner)->otherPrev->next = (node); (channelOwner)->otherPrev = (node); } while (0);
        }
        node = next;
    }
}

/* Move nodes with the requested key from the active list to the other list. */
void func_80259988_de(void *channelOwner, s32 matchingKey)
{
    OwnerRecAtD8 *owner = channelOwner;
    Node_func_80259918_de *node = owner->activeNext;
    Node_func_80259918_de *head = (Node_func_80259918_de *)&owner->activePrev;
    Node_func_80259918_de *other = (Node_func_80259918_de *)&owner->otherPrev;

    if (node != head) {
        Node_func_80259918_de *sentinel = head;
        do {
            Node_func_80259918_de *next = node->next;
            if (node->key == matchingKey) {
                Node_func_80259918_de *tail;
                node->prev->next = next;
                node->next->prev = node->prev;
                tail = owner->otherPrev;
                node->next = other;
                node->prev = tail;
                owner->otherPrev->next = node;
                owner->otherPrev = node;
            }
            node = next;
        } while (node != sentinel);
    }
}

void func_802599EC_de(OwnerRecAtD8 *listNode, s32 matchingValue) {
    ListNode *node;
    ListNode *next;
    ListNode *sentinel;
    ListNode *loop_sentinel;
    ListNode *append_sentinel;
    ListNode *tail;

    node = (ListNode *)listNode->activeNext;
    sentinel = (ListNode *)&listNode->activePrev;
    append_sentinel = (ListNode *)&listNode->otherPrev;
    if (node != sentinel) {
        loop_sentinel = sentinel;
        do {
            next = node->next;
            if (node->valueBC == matchingValue) {
                node->prev->next = next;
                node->next->prev = node->prev;
                tail = (ListNode *)listNode->otherPrev;
                node->next = append_sentinel;
                node->prev = tail;
                ((ListNode *)listNode->otherPrev)->next = node;
                listNode->otherPrev = (Node_func_80259918_de *)node;
            }
            node = next;
        } while (node != loop_sentinel);
    }
}

void func_80259A50_de(Lists *lists, s32 matchingFlags) {
    NodeRecAtAC *channelCursor;
    NodeRecAtAC *next;
    NodeRecAtAC *sourceSentinel;
    NodeRecAtAC *iterationSentinel;
    NodeRecAtAC *destinationSentinel;

    channelCursor = lists->first.next;
    sourceSentinel = &lists->first;
    if (channelCursor != sourceSentinel) {
        destinationSentinel = &lists->second;
        iterationSentinel = sourceSentinel;
        do {
            next = channelCursor->next;
            if ((channelCursor->flags & matchingFlags) != 0) {
                NodeRecAtAC *prev;

                channelCursor->prev->next = next;
                channelCursor->next->prev = channelCursor->prev;
                prev = lists->second.prev;
                channelCursor->next = destinationSentinel;
                channelCursor->prev = prev;
                lists->second.prev->next = channelCursor;
                lists->second.prev = channelCursor;
            }
            channelCursor = next;
        } while (channelCursor != iterationSentinel);
    }
}

int func_80259AB8_de(void *channelOwner, int wantedKey) {
    struct OwnerRecAtD8 *owner = channelOwner;
    struct Node_func_80259918_de *node = owner->activeNext;
    void *sentinel = &owner->activePrev;
    if (node != sentinel) {
        do {
            int value = node->key;
            node = node->next;
            if (value == wantedKey) {
                return 1;
            }
        } while (node != sentinel);
    }
    return 0;
}
