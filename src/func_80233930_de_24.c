#include "span_1000/code_8023D370.h"
#include "span_1000/code_802393F4.h"



/** Reset the word at 0x100 and enable the word at 0xFC. */
void func_8023940C_de(char *object) {
    struct Output *output = (void *)object;
    output->field100 = 0;
    output->typeFC = 1;
}
