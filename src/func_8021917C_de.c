#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80217388.h"
#include "types.h"
s32 func_8021917C_de(void *arg0, void *arg1) {
    if (((((struct ObjRecAtB0 *) ((s8 *) ((struct ObjectLinks69C *) ((s8 *) arg1))->unk_698))->unkB0) & 0x8000) && ((((struct Record *) ((s8 *) ((struct ObjectLinks69C *) ((s8 *) arg1))->unk_5D8))->team) != 0xFF)) {
        (((struct Object6C *) ((s8 *) arg0))->value) = -1;
        return 1;
    }
    return 0;
}
extern s32 D_801468C4;
extern void func_80219124_de(void *arg0, s32 arg1, void *arg2);
extern s32 func_80218988_de(void *arg0);
void func_802191B8_de(char *arg0, void *arg1) {
    s32 flags;
    s32 state;
    s32 result;
    s32 value;
    char *entry;
    flags = ((struct ObjRecAtB0 *) ((ObjectLinks11BC *) arg1)->unk_698)->unkB0 & 0x8000;
    state = *(s32 *)arg0;
    if ((state == 0) || (state == 3)) {
        if ((D_801468C4 != 0) &&
            (((struct Record *) ((ObjectLinks11BC *) arg1)->unk_5D8)->team == 0xFF)) {
            func_80219124_de((void *)arg0, flags, arg1);
            *(s32 *)arg0 = 1;
        } else {
            return;
        }
    }
    ((ObjectLinks11BC *)(arg1))->unk_670 = D_800C22C8_de;
    ((ObjectLinks11BC *)(arg1))->unk_11B4 = 1;
    ((ObjectLinks11BC *)(arg1))->unk_11B8 = 1;
    result = func_80218988_de(arg1);
    if (result != ((IntegerState74 *)(arg0))->unk_70) {
        if (result != -1) {
            entry = (char *)arg0 + result * 0x14;
            value = ((Entry *)(entry))->team;
            if (((Entry *)(entry))->enabled != 0) {
                if ((s16)value < 0) {
                    ((IntegerState74 *)(arg0))->unk_70 = -1;
                    return;
                }
                if (result != ((IntegerState74 *)(arg0))->unk_6C) {
                    ((IntegerState74 *)(arg0))->unk_6C = result;
                }
                ((struct Record *) ((ObjectLinks11BC *) arg1)->unk_5D8)->team = value;
            } else {
                return;
            }
        }
        ((IntegerState74 *)(arg0))->unk_70 = result;
    }
}
