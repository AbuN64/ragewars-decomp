#include "span_1000/code_802BB67C.h"
#include "shared/func_802BB8B0_de_closed.h"
#include "types.h"

void func_802BB8B0_de(void)
{
    OSTimer_s *t;
    u32 count;
    u32 elapsed_cycles;
    u32 *counter;

    if (((OSTimer_s *)D_800D5280)->next == D_800D5280) {
        return;
    }
    counter = &D_8014FE30;
    for (;;) {
        t = ((OSTimer_s *)D_800D5280)->next;

        if (t == D_800D5280) {
            func_802BD150_de(0);
            D_8014FE30 = 0;
            break;
        }

        count = func_802BCF00_de();
        elapsed_cycles = count - *counter;
        *counter = count;

        if (elapsed_cycles < t->value) {
            t->value -= elapsed_cycles;
            func_802BBA4C_de(t->value);
            break;
        }

        t->prev->next = t->next;
        t->next->prev = t->prev;
        t->next = 0;
        t->prev = 0;

        if (t->mq != 0) {
            func_802BB420_de(t->mq, t->msg, 0);
        }

        if (t->interval != 0) {
            t->value = t->interval;
            __osInsertTimer(t);
        }
    }
}




void func_802BB9F8_de(void) {
    NodeRecAt1C *node = (NodeRecAt1C *)D_800D5280;

    D_80149B98 = 0;
    D_80149B90 = 0;
    D_80149B94 = 0;
    node->field10 = 0;
    node->field8 = 0;
    node->prev = node;
    node->next = node;
    node->field18 = 0;
    node->field1C = 0;
}

/* Arms the CP0 timer interrupt: with interrupts disabled through func_802BCF30_de, reads the Count
   register through func_802BCF00_de into D_8014FE30, sets the Compare register through
   func_802BD150_de to that count plus the requested interval, then restores interrupts. */

void func_802BBA4C_de(u64 interval) {
    u64 compare;
    u32 saved = func_802BCF30_de();

    D_8014FE30 = func_802BCF00_de();
    compare = D_8014FE30 + interval;
    func_802BD150_de(compare);
    __osRestoreInt(saved);
}
