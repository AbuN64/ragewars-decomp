#include "include_asm.h"
#include "COMMON/STATEPAIR.H"
#include "MATH/802A2870.H"
#include "TYPES.H"
#include "RESMGR/802A2230_4.H"
#include "SCENE/802508E0_13.H"

extern void N64Eng_IncrementNumericWidget(void *);

/* Counts ticks while the controller state is 0 or 1; after ten, steps the list selection backward (state 0) or forward (state 1). Returns 0. */
s32 TickSelectionRepeat(void *widget) {
    struct CommandListController *cmd = widget;

    switch (cmd->state) {
    case 0:
        if (++cmd->progress > 10) {
            N64Eng_DecrementNumericWidget(cmd);
        }
        break;
    case 1:
        if (++cmd->progress > 10) {
            N64Eng_IncrementNumericWidget(cmd);
        }
        break;
    case 2:
        break;
    }
    return 0;
}

s32 N64Eng_FreeNumericWidget(void *arg0) {
    Cache_FreeMemory(arg0);
    return 0;
}

#if defined(VERSION_US)
unsigned int func_802A206C_de_padding_A2BCC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802A206C_de_padding_A2DDC[1] = {
    0x00000000,
};
#endif
