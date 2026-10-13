#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B369C.h"
#include "types.h"

extern void func_802B2450_de(void *arg0);
extern void func_802B2480_de(void *arg0, void *arg1);




void func_802B3C7C_de(void *arg0) {
    void *node;

    node = ((ALSynth4C *)arg0)->pLameList.next;
    if (node != 0) {
        do {
            func_802B2450_de(node);
            func_802B2480_de(node, (char *)arg0 + 4);
            node = ((ALSynth4C *)arg0)->pLameList.next;
        } while (node != 0);
    }
}
