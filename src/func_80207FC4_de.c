#include "common/types_8fd754e1e915.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80207ABC.h"
#include "types.h"
#include "audio_callbacks.h"

/** Set the fixed flags on the supplied object and word. */
void func_80207FC4_de(char *object, unsigned int *flags) {
    Player *actor = (void *)object;
    *flags |= 0x20000;
    actor->weaponFlags |= 0x2100;
}

              /* size 0x0 */

s32 func_80207FE4_de(void *arg0) {
    Player *actor = arg0;
    s32 temp_v0;

    temp_v0 = actor->weaponFlags & ~0x2000;
    actor->weaponFlags = temp_v0;
    return temp_v0;
}
