#include "span_1000/code_8024D018.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"
#include "common/unused.h"









void func_802170A0_de(Player *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 *entry;

    if ((arg1[0] & arg2) != 0) {
        return;
    }

    arg1[0] |= arg2;
    entry = D_800C8FF0_de;
    if (entry[0] != 0) {
        do {
            if ((arg3 & entry[0]) != 0) {
                func_8024DBC0_de(arg0,
                              arg0->pos,
                              entry[1],
                              func_80274A90_de(D_800C21D8_de, D_800C21DC_de));
            }
            entry += 2;
        } while (entry[0] != 0);
    }

    entry = D_800C90F8_de;
    if (entry[0] != 0) {
        do {
            if ((arg4 & entry[0]) != 0) {
                func_8024DBC0_de(arg0,
                              arg0->pos,
                              entry[1],
                              func_80274A90_de(D_800C21E0_de, D_800C21E4_de));
            }
            entry += 2;
        } while (entry[0] != 0);
    }
}
