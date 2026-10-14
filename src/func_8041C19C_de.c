#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"
/* Refreshes each of the four ports through func_80404E28_de and sets field 0x1C of D_800E3518 as soon as one reports status 0, -1, -3 or -4 through func_80404F04_de, clearing it otherwise. */



extern MenuRules *D_800E3518;
extern void func_80404E28_de(s32 port);
extern s32 func_80404F04_de(s32 port);

void func_8041C19C_de(void) {
    s32 port;

    D_800E3518->locked = 0;
    for (port = 0; port < 4; port++) {
        func_80404E28_de(port);
        switch (func_80404F04_de(port)) {
        case 0:
            D_800E3518->locked = 1;
            return;
        case -1:
        case -3:
        case -4:
            D_800E3518->locked = 1;
            return;
        }
    }
}
