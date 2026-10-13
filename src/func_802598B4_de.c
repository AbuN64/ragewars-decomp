#include "span_1000/code_802591C0.h"
#include "types.h"







void func_802598B4_de(void *arg0, s32 arg1) {
    Node_func_802598B4_de *node;
    Node_func_802598B4_de *next;
    Node_func_802598B4_de *end;
    Node_func_802598B4_de *initial_end;
    Node_func_802598B4_de *tail_end;

    node = (Node_func_802598B4_de *)((ChannelSet *)arg0)->free.prev;
    tail_end = (Node_func_802598B4_de *)&((ChannelSet *)arg0)->active;
    initial_end = (Node_func_802598B4_de *)&((ChannelSet *)arg0)->free;
    if (node != initial_end) {
        end = initial_end;
        do {
            next = node->next;
            if (node->value == arg1) {
                node->prev->next = next;
                node->next->prev = node->prev;
                node->prev = (Node_func_802598B4_de *)((ChannelSet *)arg0)->active.next;
                node->next = tail_end;
                ((Node_func_802598B4_de *)((ChannelSet *)arg0)->active.next)->next = node;
                ((ChannelSet *)arg0)->active.next = (Link_func_802596B4_de *)node;
            }
            node = next;
        } while (node != end);
    }
}
