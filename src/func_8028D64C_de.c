#include "shared/world.h"
#include "span_1000/code_80277444.h"
#include "span_1000/code_8028CCB8.h"



/** Clear the scene counters and linked state fields. */
void func_8028D64C_de(void *object) {
    ((Shared_World *)object)->counter944 = 0;
    ((Shared_World *)object)->counterB48 = 0;
    ((Shared_World *)object)->counterC4C = 0;
    ((Shared_World *)object)->counterE50 = 0;
    ((Shared_World *)object)->counterF54 = 0;
    ((Shared_World *)object)->counterFDC = 0;
    ((Shared_World *)object)->counter1020 = 0;
    ((Shared_World *)object)->counter10A4 = 0;
    ((Shared_World *)object)->counter10B8 = 0;
    ((Shared_World *)object)->counter10BC = 0;
    ((Shared_World *)object)->counter1504 = 0;
}
