#include "include_asm.h"
#include "COMMON/ENTRYRECAT0V3.H"
#include "MENU/80403BCC.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"

/* Writes a note to the Controller Pak on channel ch: refuses with -2 unless the pak is ready,
   takes the controller lock and, when the pak has no pending error, converts the extension and
   game name to pak font codes, allocates the note rounded up to whole 256-byte blocks through
   osPfsAllocateFile (func_80445F80_de), writes the data through osPfsReadWriteFile (func_80447AF0_de),
   deletes the note again if the write fails, refreshes the pak state through Pak_UpdateStatus and
   returns 0 or -1. */





extern OSPfs D_8014D280[];

extern PakDirectory *D_800E2854;

extern u8 D_8010BBB8;

extern u8 D_800DE80C[];

extern void Render_ReadControllerStates(void);

extern void func_8026454C_de(void);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern s32 func_80445F80_de(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name,
                         s32 size, s32 *file_no);

extern s32 func_80447AF0_de(OSPfs *pfs, s32 file_no, s32 flag, s32 offset, s32 size, void *data);

/* Reports note index of the Controller Pak on channel ch from the cached directory: refuses with -2
   unless the pak is ready, clears the exists flag for an empty slot, and otherwise returns its size
   in 256-byte blocks, its company and game codes as terminated byte strings, and its game name and
   extension decoded from pak font codes with trailing blanks trimmed. */








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

/* Saves data as a Controller Pak note on channel ch and verifies it: refuses with -2 unless the pak
   is ready, then up to four times writes the note through func_804042F0_de with the D_800D36DC
   company code, reads it back into a temporary buffer through an inlined note read, and stops when
   the bytes compare equal or deletes the note through Pak_DeleteNote and retries, returning the
   write result. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern u8 *D_800E25C4[], *D_800E25C4[];
#endif

extern char D_800DCCD0[];

extern char D_800DCCE8_de[];

extern void **func_8025343C_de(s32, s32, s32, char *);

extern void func_80253908_de(s32);

extern void func_80253838_de(void *arg0, void *arg1);

extern s32 func_8025477C_de(void);

extern void func_8025476C_de(s32);

extern s32 func_80265444_de(void *a, void *b, s32 size);

extern s32 func_804042F0_de(s32 ch, s32 size, void *data, u8 *game_name, s32 *file_no, u8 *ext_name,
                         u8 *company, u8 *code);

extern s32 Pak_DeleteNote(s32 ch, s32 index);

static inline s32 func_80404958_read(s32 ch, s32 file_no, void *dst, s32 size) {
    s32 result;
    s32 blocks;
    void **handle;
    void *buf;

    blocks = (size + 0xFF) & ~0xFF;
    if (D_801534F0[ch] != 3) {
        return -2;
    }
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
    handle = func_8025343C_de(0, blocks, 0x23, D_800DCCD0);
    buf = *handle;
    ((void (*)(s32))func_802644FC_de)(1);
    Render_ReadControllerStates();
    result = D_80153500[ch];
    D_8010BBB8 = 2;
    if (result == 0) {
        if ((result = func_80447AF0_de(&D_8014D280[ch], file_no, 0, 0, blocks, buf)) != 0) {
            result = -1;
        }
        if (result == 0) {
            func_802BD3A0_de(dst, buf, size);
        }
    }
    func_8026454C_de();
    func_80253908_de(0);
    if (handle != 0) {
        func_80253838_de(0, handle);
    }
    return result;
}

extern s32 func_804042F0_de(s32 ch, s32 size, void *data, u8 *game_name, s32 *file_no, u8 *ext_name, u8 *company, u8 *code);

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

s32 Pak_DeleteNote(s32 ch, s32 index) {
    extern s32 func_80446580_de(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name);
    extern void Pak_UpdateStatus(s32 ch);
    s32 result;

    if (D_801534F0[ch] != 3) {
        return -2;
    }
    ((void (*)(s32))func_802644FC_de)(1);
    Render_ReadControllerStates();
    result = D_80153500[ch];
    D_8010BBB8 = 2;
    if (result == 0) {
        result = func_80446580_de(&D_8014D280[ch], D_800E2854[ch].notes[index].company_code,
                               D_800E2854[ch].notes[index].game_code,
                               D_800E2854[ch].notes[index].game_name,
                               D_800E2854[ch].notes[index].ext_name);
        if (result != 0) {
            result = -1;
        }
        Pak_UpdateStatus(ch);
    }
    func_8026454C_de();
    return result;
}

s32 Pak_SaveNote(s32 ch, s32 size, void *data, u8 *name, u8 *ext, u8 *code) {
    s32 result;
    s32 file_no;
    void **handle;
    void *buf;
    s32 blocks;
    s32 tries;

    blocks = (size + 0xFF) & ~0xFF;
    if (D_801534F0[ch] != 3) {
        return -2;
    }
    handle = func_8025343C_de(0, blocks, 0x23, D_800DCCE8_de);
    buf = *handle;
    for (tries = 0; tries < 4; tries++) {
        result = func_804042F0_de(ch, size, data, name, &file_no, ext, RW_LOCALIZED_TEXT(D_800D36DC, D_800E25C4, D_800E25C4, D_80152789), code);
        if (result != 0) {
            break;
        }
        if (func_80404958_read(ch, file_no, buf, blocks) == 0 && func_80265444_de(buf, data, size) == 0) {
            break;
        }
        if (Pak_DeleteNote(ch, file_no) != 0) {
            break;
        }
    }
    func_80253908_de(0);
    if (handle != 0) {
        func_80253838_de(0, handle);
    }
    return result;
}

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "stddef.h"
#include "TYPES.H"
s32 func_802A037C_de(const void *arg0, const void *arg1);
extern u8 D_800DE80C[];

s32 func_80404BE8_de(void *arg0, s32 arg1, s32 *arg2) {
    u8 sp10[16];
    u8 *sp20;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a3;
    s32 var_s0;
    s32 var_s1;
    s8 *var_v0;
    u8 *temp_v1_2;
    u8 *var_a1;
    u8 *var_a2;
    u8 temp_v0;
    u8 temp_v1;

    var_s0 = 0;
    var_s1 = 4;
loop_1:
    if (D_801534F0[arg1] == 3) {
        sp20 = (u8 *)D_800E2854 + (arg1 * 0x204) + var_s1 + 0xE;
    }
    var_a0 = 0xF;
    var_v0 = (s8 *)&sp10[15];
    do {
        *var_v0 = 0;
        var_a0 -= 1;
        var_v0 -= 1;
    } while (var_a0 >= 0);
    var_a3 = 0;
    var_a0_2 = 0;
    var_a1 = sp10;
    var_a2 = sp20;
    do {
        temp_v1 = *var_a2;
        if (temp_v1 >= 0x42U) {
            *var_a1 = 0x7E;
        } else if ((temp_v1 == 0) && (var_a3 == 0)) {
            *var_a1 = 0x20;
        } else {
            var_a3 = 1;
            *var_a1 = D_800DE80C[*var_a2];
        }
        var_a1 += 1;
        var_a0_2 += 1;
        var_a2 += 1;
    } while (var_a0_2 < 0x10);
    var_a0_3 = 0xF;
loop_15:
    temp_v1_2 = &(sp10)[var_a0_3];
    temp_v0 = *temp_v1_2;
    var_a0_3 -= 1;
    if ((temp_v0 == 0x20) || (temp_v0 == 0)) {
        *temp_v1_2 = 0;
        if (var_a0_3 >= 0) {
            goto loop_15;
        }
    }
    sp10[15] = 0;
    if (func_802A037C_de(sp10, arg0) != 0) {
        var_s0 += 1;
        var_s1 += 0x20;
        if (var_s0 >= 0x10) {
            return 0;
        }
        goto loop_1;
    }
    if (arg2 != NULL) {
        *arg2 = var_s0;
    }
    return 1;
}
#else
INCLUDE_ASM("ovl_80400000", func_80404BE8_de);
#endif
