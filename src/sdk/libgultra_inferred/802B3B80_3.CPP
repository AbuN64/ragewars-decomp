#include "span_1000/code_802B4730.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802AE028.h"
#include "span_1000/code_802B0388.h"
#include "TYPES.H"

extern void func_802B2450_de(Node_func_802AFD6C_de *arg0);

extern void __CSPRepostEvent(void *arg0, Node_func_802AFD6C_de *arg1);

extern s32 func_802AE9B0_de(s32 arg0, s32 *arg1);

extern void func_802B00D4_de(ALEventQueue *, ALEvent *, s32);

extern s32 func_802BD170_de(s32);

void func_802AFB6C_de(void *arg0, ObjectState10_2 *arg1) {
    extern void func_802B2480_de(Node_func_802AFD6C_de *arg0, Node_func_802AFD6C_de *arg1);
    s32 padding[4];
    s32 total = 0;
    Node_func_802AFD6C_de *head = 0;
    s32 scale;
    Node_func_802AFD6C_de *node;
    Node_func_802AFD6C_de *next;
    if (arg1->unk_8 == 0xFF) {
        if (arg1->unk_9 != 0x51) {
            return;
        }
        scale = ((ObjectState4C *)(arg0))->unk_24;
        func_802AFDFC_de(arg0,
                      (f32)((arg1->unk_B << 16) | (arg1->unk_C << 8) | arg1->unk_D));
        node = ((struct ObjectLinks54_2 *) ((char *) arg0))->link;
        while (node != 0) {
            next = ((struct ObjectLinks4_5 *) ((char *) node))->link;
            total += node->value;
            if (node->type == 0x15) {
                s32 node_total;
                func_802B2450_de(node);
                if (head != 0) {
                    func_802B2480_de(node, head);
                } else {
                    head = node;
                    node->prev = 0;
                    node->next = 0;
                }
                node_total = total;
                if (next != 0) {
                    total -= node->value;
                    next->value += node->value;
                }
                node->value = node_total;
            }
            node = next;
        }
        node = head;
        while (node != 0) {
            next = node->prev;
            node->value = (node->value / scale) * ((ObjectState4C *)(arg0))->unk_24;
            __CSPRepostEvent(&((ObjectState4C *)(arg0))->unk_48, node);
            node = next;
        }
    }
}

void func_802AFD00_de(void *arg0) {
    struct ALSeqPlayer *player = arg0;
    ALEvent sp10;
    s32 sp20;
    s32 field18;

    if (player->state == 1) {
        field18 = (s32)player->target;
        if (field18 != 0 && (func_802AE9B0_de(field18, &sp20) & 0xFF)) {
            sp10.type = 0;
            func_802B00D4_de(&player->evtq, &sp10, sp20 * player->uspt);
        }
    }
}

void __CSPRepostEvent(void *arg0, Node_func_802AFD6C_de *arg1) {
    extern void func_802B2480_de(void *, void * *);
    ObjRecAt8V3 *object = arg0;
    s32 saved;
    Node_func_802AFD6C_de **link;
    Node_func_802AFD6C_de *node;
    s32 value;
    s32 node_value;

    saved = func_802BD170_de(1);
    link = &object->unk8;
    if (link != 0) {
loop:
        node = *link;
        if (node == 0) {
            goto insert;
        }
        value = arg1->value;
        node_value = node->value;
        if (value < node_value) {
            node->value = node_value - value;
insert:
            func_802B2480_de(arg1, link);
            goto done;
        }
        arg1->value = value - node_value;
        link = (Node_func_802AFD6C_de **)*link;
        if (link != 0) {
            goto loop;
        }
    }
done:
    func_802BD170_de(saved);
}

void func_802AFDFC_de(void *arg0, f32 arg1) {
    ALSeqPlayer *player = arg0;
    ALCSeq_s *temp_v0;

    temp_v0 = player->target;
    if (temp_v0 != 0) {
        player->uspt = (s32)(arg1 * temp_v0->qnpt);
        return;
    }
    player->uspt = 0x1E8;
}
