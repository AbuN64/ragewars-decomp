#include "COMMON/PROBE.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "particle/8024D018_4.H"
#include "WEAPONS/80213ED4_23.H"

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
