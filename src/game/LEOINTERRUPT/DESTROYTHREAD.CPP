#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_5.H"
#include "COMMON/CTX.H"
#include "TYPES.H"
#include "COMMON/VERSION_CALLS.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "sdk/os.h"

extern Func802C1F10Node *__osActiveQueue;
extern void *g_osRunningThread;
extern void Audio_DequeueThread(void *listHead, Func802C1F10Node *node);

void Audio_DestroyThread(Func802C1F10Node *thread) {
    Func802C1F10Node *node;
    Func802C1F10Node *cur;
    Func802C1F10Node **head;
    s32 token;
    node = thread;
    token = __osDisableInt();
    if (node == 0) {
        node = g_osRunningThread;
    } else if (node->state != 1) {
        Audio_DequeueThread(node->queue, node);
    }
    head = &__osActiveQueue;
    if (*head == node) {
        *head = node->next;
    } else {
        cur = *head;
        while (cur->priority != -1) {
            if (cur->next == node) {
                cur->next = node->next;
                break;
            }
            cur = cur->next;
        }
    }
    if (node == g_osRunningThread) {
        __osDispatchThread();
    }
    __osRestoreInt(token);
}
