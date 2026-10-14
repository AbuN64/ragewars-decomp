#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80203F04.h"
typedef struct Owner Owner;
/** Run the object's optional update hook, then copy one of two byte pairs into the record header. */







void func_802043E0_de(char *arg0, char *arg1) {
    Owner *owner = (void *)arg0;
    ObjRecAt30 *event = (void *)arg1;
    char *base = owner->track + 0x14;
    Hook *hook = event->unk30;

    if (hook != 0 && hook->fn != 0) {
        hook->fn(arg0, arg1);
    }
    if (arg1[0x34] == 0) {
        arg0[1] = base[0xE];
        arg0[3] = base[0xF];
    } else {
        arg0[1] = base[0x1A];
        arg0[3] = base[0x1B];
    }
}
