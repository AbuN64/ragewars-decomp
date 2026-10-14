#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80411B68.h"
#include "types.h"
/* Releases every UI resource slot whose entry is open, whose id is valid and whose retain count is zero, through func_80411AF0_de. */




extern s16 D_80153C0C;
extern struct EntryRecAt8V1 *D_80153C10;
extern struct ResourceRecAt6 *D_8014D988;
extern void func_80411AF0_de(s32);

void func_80412038_de(void) {
    s32 i;
    s32 invalid;
    s32 offset;
    struct ResourceRecAt6 *resource;

    i = 0;
    if (D_80153C0C > 0) {
        invalid = -1;
        offset = 0;
        do {
            if (((struct EntryRecAt8V1 *)(offset + (s32)D_80153C10))->flags & 1) {
                resource = D_8014D988 + i;
                if (resource->id != invalid && resource->retained == 0) {
                    func_80411AF0_de(i);
                }
            }
            offset += 0x1C;
        } while (++i < D_80153C0C);
    }
}
