#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/ALDELAY28.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/seqplayer.h"

void *__mapVoice(void *sequencePlayer, s8 noteKey, s8 noteVelocity, s8 midiChannel) {
    ALVoiceState *node;
    ALSeqPlayer88 *player = sequencePlayer;
    ALVoiceState *next;
    ALVoiceState *tail;

    node = player->vFreeList;
    if (node != 0) {
        next = node->next;
        player->vFreeList = next;
        node->next = 0;
        if (player->vAllocHead == 0) {
            player->vAllocHead = node;
        } else {
            tail = player->vAllocTail;
            tail->next = node;
        }
        player->vAllocTail = node;
        node->channel = midiChannel;
        node->key = noteKey;
        node->velocity = noteVelocity;
        node->voice.clientPrivate = node;
    }
    return node;
}

void Audio_ReleaseSequenceVoice(List802B663C *voicePool, void *voice) {
    Node_func_80239AF4_de *node;
    Node_func_80239AF4_de *prev;

    prev = 0;
    node = voicePool->head;
    while (node != 0) {
        if ((void *)(node + 1) == voice) {
            if (prev != 0) {
                prev->next = node->next;
            } else {
                voicePool->head = node->next;
            }
            if (node == voicePool->tail) {
                voicePool->tail = prev;
            }
            node->next = voicePool->free;
            voicePool->free = node;
            return;
        }
        prev = node;
        node = node->next;
    }
}
