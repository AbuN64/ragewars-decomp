#include "span_1000/code_8023B9A0.h"
#include "types.h"





extern Link_func_8023CC08_de *D_800FFE20;
extern Link_func_8023CC08_de *D_800FFE24;
extern void func_8023C084_de(void *arg0);
extern Node_func_8023CC08_de *func_8023CBC0_de(u32 arg0);

Link_func_8023CC08_de *func_8023CC08_de(void) {
    Link_func_8023CC08_de *entry;
    Node_func_8023CC08_de *node;

    entry = D_800FFE20;
    if (entry->prev != 0) {
        entry->prev->next = *(Link_func_8023CC08_de * volatile *)&entry->next;
    } else {
        D_800FFE20 = entry->next;
        (*(Link_func_8023CC08_de * volatile *)&entry->next)->prev = 0;
    }
    if (entry->next != 0) {
        entry->next->prev = *(Link_func_8023CC08_de * volatile *)&entry->prev;
    } else {
        D_800FFE24 = entry->prev;
        (*(Link_func_8023CC08_de * volatile *)&entry->prev)->next = 0;
    }

    func_8023C084_de(entry);
    if (entry->id != 0xFFFF) {
        node = func_8023CBC0_de(entry->id);
        node->data[entry->id - node->start] = 0xFF;
        entry->id = 0xFFFF;
    }
    entry->fieldC = 0;
    return entry;
}
