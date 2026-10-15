#include "span_1000/code_802B53FC.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_1000/code_802B0388.h"
#include "types.h"

void *__mapVoice(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
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

void func_802B156C_de(List802B663C *arg0, void *arg1) {
    Node_func_80239AF4_de *node;
    Node_func_80239AF4_de *prev;

    prev = 0;
    node = arg0->head;
    while (node != 0) {
        if ((void *)(node + 1) == arg1) {
            if (prev != 0) {
                prev->next = node->next;
            } else {
                arg0->head = node->next;
            }
            if (node == arg0->tail) {
                arg0->tail = prev;
            }
            node->next = arg0->free;
            arg0->free = node;
            return;
        }
        prev = node;
        node = node->next;
    }
}
