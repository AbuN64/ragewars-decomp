#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Releases the buffers of the pool at D_80153C40: every entry holding a buffer that is not locked
   (flag 1) unless force is set has its reference count forced to one and dropped, and when it
   reaches zero the buffer is freed through func_802547E4_de, along with the entry's secondary buffer
   when secondary buffers are in use (D_800E2AC4), and the entry is cleared. Pool fields read as one struct at D_80153C40, as in func_80410E1C_de. */





extern BufferPool D_80153C40;
extern s32 D_800E2AC4;

extern void func_802547E4_de(void *buffer);

void func_804118E4_de(s32 force) {
    s32 i;

    for (i = 0; i < D_80153C40.count; i++) {
        if (D_80153C40.primary[i].unk8 != 0 && (!(D_80153C40.flags[i] & 1) || force != 0)) {
            D_80153C40.refs[i] = 1;
            D_80153C40.refs[i]--;
            if (D_80153C40.primary[i].unk8 != 0 && D_80153C40.refs[i] == 0) {
                func_802547E4_de(D_80153C40.primary[i].unk8);
                if (D_800E2AC4 != 0 && D_80153C40.secondary != 0 &&
                    D_80153C40.secondary[i].unk8 != 0) {
                    func_802547E4_de(D_80153C40.secondary[i].unk8);
                }
                D_80153C40.primary[i].unk8 = 0;
            }
        }
    }
}
