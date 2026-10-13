#include "span_16E000/code_8043E9A8.h"
extern struct Options_func_8043EBE4_de D_801462C8;
/* Toggle the selected match option; unknown actions leave all options alone. */
s32 func_8043E830_de(s32 *action)
{
    switch (*action) {
    case 2: D_801462C8.toggles[0] ^= 1; break;
    case 3: D_801462C8.toggles[1] ^= 1; break;
    case 4: D_801462C8.toggles[2] ^= 1; break;
    case 5: D_801462C8.toggles[3] ^= 1; break;
    case 6: D_801462C8.toggles[4] ^= 1; break;
    case 7: D_801462C8.toggles[5] ^= 1; break;
    case 8: D_801462C8.toggles[6] ^= 1; break;
    case 9: D_801462C8.extraToggle ^= 1; break;
    }
    return 0;
}
