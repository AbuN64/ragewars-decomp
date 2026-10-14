#include "common/unused.h"
#include "span_1000/code_802B0388.h"
#include "types.h"






void *func_802B151C_de(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    ALVoiceState *node;
    ALSeqPlayer88 *player = arg0;
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
        node->channel = arg3;
        node->key = arg1;
        node->velocity = arg2;
        node->voice.clientPrivate = node;
    }
    return node;
}
