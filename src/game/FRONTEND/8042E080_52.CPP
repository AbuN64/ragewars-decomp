#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_53.H"

/* Reads two values and reports whether the first reaches the rounded object size when the second is nonzero. */

extern s32 Pak_GetFreePages(void *a0, s32 *a1);
extern s32 Pak_CountFreeNotes(void *a0, s32 *a1);

extern s32 Ovlgame_BytesToPakPages(s32 a0);

s32 func_80435384_de(void *arg0, s32 *out)
{
    s32 a, b;
    s32 ret;
    s32 val;

    *out = 0;

    ret = Pak_GetFreePages(arg0, &a);
    if (ret == 0) {
        ret = Pak_CountFreeNotes(arg0, &b);
        if (ret == 0) {
            val = Ovlgame_BytesToPakPages(func_80435424_de());
            if (b == 0) {
                *out = 0;
            } else if (a < val) {
                *out = 0;
            } else {
                *out = 1;
            }
        }
    }

    return ret;
}
