#include "span_1000/code_8025C544.h"
#include "span_1000/code_8025D948.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"




extern void func_80255ED8_de(void *, s32);





void func_8025CBEC_de(void *arg0) {
    SoundSourceNode *cur;
    SoundSourceNode *next;
    s32 value;
    SoundVoicePool *pool = arg0;

    cur = pool->playing.head;
    if (cur != 0) {
        do {
            value = cur->value;
            next = cur->next;
            func_8025E174_de(value);
            cur->state = -1;
            cur->value = -1;
            func_80255ED8_de(&pool->playing, cur);
            func_80255D14_de(&pool->available, cur);
            cur = next;
        } while (cur != 0);
    }
}
