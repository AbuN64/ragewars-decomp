#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80411B68.h"
#include "types.h"
/* Drops one reference to buffer pool entry i and, when none remain, frees its primary and secondary buffers and clears the entry. */





extern BufferPool D_80153C40;
extern s32 D_800E2AC4;

extern void func_802547E4_de(void *buffer);

void func_80411E18_de(s32 i) {
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
