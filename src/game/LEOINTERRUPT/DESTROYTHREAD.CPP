#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_5.H"
#include "COMMON/CTX.H"
#include "TYPES.H"
#include "COMMON/VERSION_CALLS.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "sdk/os.h"

extern Func802C1F10Node *D_800D526C;
extern void *D_800D5270;
extern void Audio_DequeueThread(void *listHead, Func802C1F10Node *node);

void Audio_DestroyThread(Func802C1F10Node *thread) {
    Func802C1F10Node *node;
    Func802C1F10Node *cur;
    Func802C1F10Node **head;
    s32 token;
    node = thread;
    token = __osDisableInt();
    if (node == 0) {
        node = D_800D5270;
    } else if (node->field10 != 1) {
        Audio_DequeueThread(node->field8, node);
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
    __osRestoreInt(token);
}
