#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"
/* Reports note index of the Controller Pak on channel ch from the cached directory: refuses with -2
   unless the pak is ready, clears the exists flag for an empty slot, and otherwise returns its size
   in 256-byte blocks, its company and game codes as terminated byte strings, and its game name and
   extension decoded from pak font codes with trailing blanks trimmed. */






extern PakDirectoryRecAt4 *D_800E2854;
extern u8 D_800DE80C[];

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

static inline void func_8040458C_decode(u8 *dst, u8 *src, s32 n) {
    s32 i;
    u8 *p;
    s32 started;

    for (i = n - 1, p = dst + i; i >= 0; i--) {
        *p-- = 0;
    }
    started = 0;
    for (i = 0; i < n; i++) {
        if (src[i] < 0x42) {
            if (src[i] == 0 && !started) {
                dst[i] = ' ';
            } else {
                dst[i] = D_800DE80C[src[i]];
                started = 1;
            }
        } else {
            dst[i] = '~';
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (dst[i] != ' ' && dst[i] != 0) {
            break;
        }
        dst[i] = 0;
    }
    dst[n - 1] = 0;
}

s32 func_8040458C_de(s32 ch, s32 index, s32 *exists, u8 *name, u8 *ext, s32 *size, u8 *company,
                  u8 *code) {
    if (D_801534F0[ch] != 3) {
        return -2;
    }
    if (D_800E2854[ch].notes[index].file_size == 0) {
        *exists = 0;
    } else {
        *exists = 1;
    *size = D_800E2854[ch].notes[index].file_size >> 8;
    func_802BD3A0_de(company, &D_800E2854[ch].notes[index].company_code, 2);
    func_802BD3A0_de(code, &D_800E2854[ch].notes[index].game_code, 4);
    func_8040458C_decode(name, D_800E2854[ch].notes[index].game_name, 17);
    func_8040458C_decode(ext, D_800E2854[ch].notes[index].ext_name, 4);
    code[4] = 0;
    company[2] = 0;
    }
    return 0;
}
