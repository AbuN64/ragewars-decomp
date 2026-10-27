#include "COMMON/OUTPUT.H"
#include "COMMON/CHANNEL.H"

/** Reset the word at 0x100 and enable the word at 0xFC. */
void func_8023940C_de(char *object) {
    struct CCollisionResults *output = (void *)object;
    output->field100 = 0;
    output->typeFC = 1;
}
