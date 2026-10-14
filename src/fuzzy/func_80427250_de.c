#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804264F0.h"
#include "decomp/argb_color.h"
#include "types.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"

extern struct EntryRecAt0V1 D_800E4694[];
extern s32 func_80265650_de(u8 *, s32);
extern void func_80265688_de(u8 *, s32, s32);
extern s32 func_80428158_de(s32, s32);

s32 func_80427250_de(u8 *available, s32 *sequence) {
    s32 found;
    s32 i;
    s32 count;
    s32 compatible;
    s32 *last;

    found = 0;
    i = 0;
    do {
        if (func_80265650_de(available, i) == 1) {
            found = 1;
        }
        i++;
    } while (i < 36 && found == 0);
    if (found != 0) {
        count = 0;
        while (sequence[count] != -1) {
            count++;
        }
        count--;
        last = &sequence[count];
        for (i = 0; i < 36; i++) {
            if (func_80265650_de(available, i) != 0) {
                compatible = func_80428158_de(D_800E4694[*last].value,
                                              D_800E4694[i].value);
                if (compatible == 1) {
                    last++;
                    last[0] = i;
                    last[1] = -1;
                    func_80265688_de(available, i, 0);
                    if (func_80427250_de(available, sequence) == compatible) {
                        return 1;
                    }
                    func_80265688_de(available, i, 1);
                    last[0] = -1;
                    last--;
                }
            }
        }
    }
    return 1;
}
