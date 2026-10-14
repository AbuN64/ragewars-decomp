#include "span_1000/code_8021CD70.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"



extern s32 D_80146938;
extern u8 D_801462D5;
extern Entry190 D_800FEB10[];






s32 func_8022AC00_de(void *arg0) {
    char *o = (char *)arg0;
    s32 value;
    s8 type;

    if (D_80146938 != 0 && ((struct RecordRecAt94 *) ((ObjectLinks1454_3 *) o)->unk_5D8)->display != 0) {
        type = ((struct RecordRecAt94 *) ((ObjectLinks1454_3 *) o)->unk_5D8)->kind;
        if (type == 0xB) {
            value = 0x19000;
        } else if (type == 0xC) {
            value = 0x19000;
        } else if (type == 0xE) {
            value = 0x12C00;
        } else if (type == 0xD) {
            value = 0x12C00;
        } else {
            value = ((ActorHealthDefinition *)((ObjectLinks1454_3 *)o)->unk_18)->health << 8;
        }
    } else {
        value = ((ActorHealthDefinition *)((ObjectLinks1454_3 *)o)->unk_18)->health << 8;
    }
    if (D_801462D5 == 1 && ((ObjectLinks1454_3 *)(o))->unk_1450 == 0) {
        value += D_800FEB10[((ObjectLinks1454_3 *)(o))->unk_5D4].value;
    }
    return value;
}
