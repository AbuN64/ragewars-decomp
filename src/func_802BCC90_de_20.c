#include "span_1000/code_802BBC68.h"
#include "types.h"
#include "version_calls.h"
extern Func802C1F10Node *D_800D526C;
extern void *D_800D5270;
extern u32 func_802BCF30_de(void);
extern void func_802BB870_de(void *arg0, Func802C1F10Node *arg1);

extern void func_802BCF50_de(u32);
void func_802BCE20_de(Func802C1F10Node *arg0) {
    Func802C1F10Node *node;
    Func802C1F10Node *cur;
    Func802C1F10Node **head;
    s32 token;
    node = arg0;
    token = func_802BCF30_de();
    if (node == 0) {
        node = D_800D5270;
    } else if (node->field10 != 1) {
        func_802BB870_de(node->field8, node);
    }
    head = &D_800D526C;
    if (*head == node) {
        *head = node->next;
    } else {
        cur = *head;
        while (cur->field4 != -1) {
            if (cur->next == node) {
                cur->next = node->next;
                break;
            }
            cur = cur->next;
        }
    }
    if (node == D_800D5270) {
        func_802BC850_eu_x();
    }
    func_802BCF50_de(token);
}
