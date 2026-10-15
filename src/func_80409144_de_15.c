#include "common/unused.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Reports whether the two-character code arg0 and the four-character name arg1 are the pair D_800D36DC and D_800D36E0, measuring them with func_802A0238_de and comparing them with func_802A037C_de; returns one on a match and zero otherwise. */

extern char *D_800D36E0;

extern s32 func_802A0238_de(u8 *);
extern s32 func_802A037C_de(const void *, const void *);

s32 func_804097F8_de(char *code, char *name) {
    if (func_802A0238_de((u8 *)name) == 4 && func_802A0238_de((u8 *)code) == 2 &&
        func_802A037C_de(name, D_800D36E0) == 0 && func_802A037C_de(code, D_800D36DC) == 0) {
        return 1;
    }
    return 0;
}
