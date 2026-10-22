#include "include_asm.h"

/* handwritten in the original SDK: exception-handler tail that parks $ra in $s2 and returns with jr $s2, runs frameless on $t0-$t5 with an inline div/mfhi ring index; no C compiler emits that */
INCLUDE_ASM("span_1000", func_802BC268_de);
