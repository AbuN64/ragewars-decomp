#include "span_1000/code_80256220.h"
#include "types.h"



extern u32 D_800CB700_de;
extern u32 D_800CB704_de;
extern char D_80107DD8[];
extern Node_func_80256FC0_de *D_80107DF4[];

extern void func_802BB2A0_de(s32, s32, s32);
extern void func_802B2450_de(Node_func_80256FC0_de *arg0);
extern void func_802B2480_de(void *arg0, void **arg1);

void func_80256FC0_de(void) {
    u32 i;
    s32 value;
    Node_func_80256FC0_de *node;
    Node_func_80256FC0_de *next;

    value = 0;
    for (i = 0; i < D_800CB704_de; i++) {
        func_802BB2A0_de(D_80107DD8, &value, 1);
    }

    node = D_80107DF4[0];
    if (node != 0) {
        do {
            next = node->prev;
            if (node->age + 1 < D_800CB700_de) {
                if (D_80107DF4[0] == node) {
                    D_80107DF4[0] = next;
                }
                func_802B2450_de(node);
                if (D_80107DF4[1] != 0) {
                    func_802B2480_de(node, (void **)D_80107DF4[1]);
                } else {
                    D_80107DF4[1] = node;
                    node->prev = 0;
                    node->next = 0;
                }
            }
            node = next;
        } while (node != 0);
    }

    D_800CB704_de = 0;
    D_800CB700_de++;
}
