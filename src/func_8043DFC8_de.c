#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
/* Clears eight player active flags, then marks the first settings slot whose controller profile is active. */
extern StatusStep D_80142622[];
extern PlayerSettings D_80146398[];
extern ControllerProfile D_8010F328[];
extern s32 func_8026437C_de(ControllerProfile *);
void func_8043DFC8_de(void) {
    StatusStep *status;
    PlayerSettings *settings;
    s32 i;
    s32 active;
    i = 7;
    status = D_80142622;
    for (; i >= 0; i--) {
        ((StatusView *)status)->active = 0;
        status--;
    }
    i = 0;
    active = 1;
    settings = D_80146398;
    for (; i < 4; i++) {
        if (func_8026437C_de(&D_8010F328[i]) != 0) {
            settings[i].active = active;
            settings[i].selected = i;
            break;
        }
    }
}
