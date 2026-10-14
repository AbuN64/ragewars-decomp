#include "span_1000/code_8022C894.h"
#include "types.h"




/** Reset two object fields and replace the control word's mode bit. */
void func_8022D25C_de(void *arg0) {
    Actor_func_8022D290_de *actor = arg0;
    actor->flags &= 0xFF7FFFFF;
    actor->unk_0x11D8 = 0;
    actor->unk_0x11FC = 0;
    actor->flags |= 0x01000000;
}
