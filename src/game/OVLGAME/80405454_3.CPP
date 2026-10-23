#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECORDRECAT1C.H"
#include "OVLGAME/80405454.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "OVLGAME/80405454_3.H"
#include "RESMGR/802A0888.H"

/* Chooses a free extension letter for a new note on the Controller Pak on channel ch: refuses with
   -2 unless the pak is ready, queries each of the 16 notes through func_8040458C_de (failing with -1
   on error) and marks the letter of every existing note, then writes the first unused letter from
   'A' as the extension, returning 0, or -1 when all 16 letters are taken. */



extern s32 func_8040458C_de(s32 ch, s32 index, s32 *exists, char *gameName, u8 *ext, s32 *size,
                         char *companyCode, char *gameCode);

s32 func_80405454_de(s32 ch, u8 *ext) {
    char companyCode[8];
    char gameCode[8];
    char gameName[16];
    s32 exists;
    s32 size;
    s32 used;
    s32 i;

    used = 0;
    if (D_801534F0[ch] != 3) {
        return -2;
    }
    for (i = 0; i < 16; i++) {
        if (func_8040458C_de(ch, i, &exists, gameName, ext, &size, companyCode, gameCode) != 0) {
            return -1;
        }
        if (exists != 0) {
            used |= 1 << (ext[0] - 'A');
        }
    }
    ext[0] = 'A';
    ext[1] = 0;
    ext[2] = 0;
    ext[3] = 0;
    for (i = 0; i < 16 && (used & (1 << i) & 0xFFFF); i++) {
        ext[0]++;
    }
    if (i >= 16) {
        return -1;
    }
    return 0;
}

/* Returns whether entry i of D_80153500 is -4 when entry i of the state table D_801534F0 is 3,
   otherwise zero. */



s32 func_80405598_de(s32 index) {
    if (D_801534F0[index] != 3) {
        return 0;
    }
    return D_80153500[index] == -4;
}

/* Marks the given controller port's 0x70-byte pak record in D_80153330 present when the port's D_8010FBE3 status byte is clear and func_802B7FD8_de initialises the pak block at offset 8 of the record through D_8010FC00 without error, clearing the mark otherwise, and returns the mark.
   Adapted from func_8028B2F8_de with the record reached by port index, the status byte guard and the initialisation result stored as a byte flag changed. */



extern char D_8010FC00[];
extern PakRecord D_80153330[];
extern s32 func_802B7FD8_de(void *queue, void *pak, s32 channel);

s32 func_804055D4_de(s32 channel) {
    PakRecord *record = &D_80153330[channel];
    s32 result;

    if (D_8010FBE3[channel * 4] == 0) {
        record->present = func_802B7FD8_de(D_8010FC00, record->pak, channel) == 0;
        result = record->present;
    } else {
        record->present = 0;
        result = 0;
    }
    return result;
}

extern u8 D_800DE80C[];

/* Converts a controller-pak filename through its character table, blanking leading nulls, then trims trailing spaces. */
void func_80405648_de(u8 *arg0, u8 *noteText, s32 arg2) {
    s32 i;
    s32 started;

    for (i = 0; i < arg2; i++) {
        noteText[i] = 0;
    }

    started = 0;
    for (i = started; i < arg2; i++, arg0++) {
        if (*arg0 < 0x42) {
            if (*arg0 == 0 && !started) {
                noteText[i] = ' ';
            } else {
                noteText[i] = D_800DE80C[*arg0];
                started = 1;
            }
        } else {
            noteText[i] = '~';
        }
    }

    for (i = arg2 - 1; i >= 0; i--) {
        if (noteText[i] != ' ' && noteText[i] != 0) {
            break;
        }
        noteText[i] = 0;
    }
    noteText[arg2 - 1] = 0;
}

extern u8 func_802A05A0_de(u8);
extern u8 D_800DE80C[0x42];

/* Maps input bytes through a lookup table and stores results. */
void func_8040570C_de(u8 *arg0, s8 *arg1, s32 arg2) {
    s32 i;
    s8 *var_s1;
    s32 j;
    u8 *var_s0;
    int new_var;

    i = 0;
    if (arg2 > 0) {
        new_var = 0x42;
        var_s1 = arg1;
        var_s0 = arg0;
        do {
            *var_s0 = func_802A05A0_de(*var_s0);
            for (j = 0; j < 0x42; j += 1) {
                if (*var_s0 == D_800DE80C[j]) {
                    *var_s1 = (s8)j;
                    break;
                }
            }
            if (j == new_var) {
                *var_s1 = 0;
            }
            var_s1 += 1;
            i += 1;
            var_s0 += 1;
        } while (i < arg2);
    }
}

/* Returns one when a tilde appears among the first n + 1 bytes of a string, otherwise zero. */
s32 func_804057BC_de(u8 *text, s32 count) {
    do {
        if (*text++ == '~') {
            return 1;
        }
    } while (--count != -1);
    return 0;
}

/* Rounds a byte count up to whole 256-byte units; func_80435384_de passes it the 0x648-byte size
   that func_80435424_de returns. */
u32 func_804057EC_de(u32 bytes) {
    return (bytes + 0xFF) >> 8;
}

/* Computes the CRC-32 with polynomial 0xEDB88320 of arg1 bytes at arg0, continuing from the running value arg2, from a 256-entry table built on the stack. Adapted from func_802A08B8_de. */

u32 func_804057F8_de(u8 *arg0, u32 arg1, u32 arg2) {
    u32 table[256];
    u32 i;
    u32 j;
    u32 value;
    u32 shifted;
    u8 *end;

    for (i = 0; i < 256; i++) {
        value = i;
        for (j = 0; j < 8; j++) {
            shifted = value >> 1;
            if (value & 1) {
                shifted ^= 0xEDB88320U;
            }
            value = shifted;
        }
        table[i] = value;
    }

    end = arg0 + arg1;
    arg2 = ~arg2;
    while (arg0 < end) {
        arg2 = table[(arg2 ^ *arg0++) & 0xFF] ^ ((arg2 >> 8) & 0xFFFFFF);
    }
    return ~arg2;
}

/* Returns the word held in D_800E2850. */

s32 func_804058A0_de(void) {
    return D_800E2850;
}

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_12.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/TRIPLE.H"

void func_80253838_de(s32, void *);
u32 func_80265350_de(void);
void *func_80253530_de(s32, s32, u32, void *);

extern u8 D_800DCD1C[];
extern u8 D_800DCD0C[];
extern u8 D_800DCD3C[];
extern u8 D_800DCD54[];
extern s32 D_800DCD4C;
extern u8 D_800DCD00_de[];
#include "COMMON/DISPLAY.H"

/* 51/254 aligned edits; remaining: tail global-store scheduling (D_800E28A4 held in s1), empty count loop, register allocation. */
int Ovlgame_AllocateRenderBuffers(struct RecordRecAt1C *record) {
    void **puVar2;
    void **clearSlot;
    s32 clearIndex;
    u32 uVar3;
    s32 *piVar4;
    s32 *compactHandle;
    u32 compactCount;
    s32 *piVar5;
    u32 uVar6;
    u32 uVar7;
    s32 iVar8;
    u32 blockSize;
    u32 memoryAddress;
    u32 megabyte = 0x100000;
    u32 count;
    u32 i;

    if (((void **)record)[1] != 0) {
        func_80253838_de(0, ((void **)record)[1]);
    }
    if (((void **)record)[2] != 0) {
        func_80253838_de(0, ((void **)record)[2]);
    }
    if (((void **)record)[6] != 0) {
        func_80253838_de(0, ((void **)record)[6]);
    }
    if (((void **)record)[7] != 0) {
        func_80253838_de(0, ((void **)record)[7]);
    }
    iVar8 = 0;
    puVar2 = ((void **)record);
    do {
        if (puVar2[3] != 0) {
            func_80253838_de(0, puVar2[3]);
        }
        iVar8 = iVar8 + 1;
        puVar2 = puVar2 + 1;
    } while (iVar8 < 3);

    clearIndex = 2;
    clearSlot = ((void **)record) + 2;
    *((void **)record) = 0;
    ((void **)record)[1] = 0;
    ((void **)record)[2] = 0;
    ((void **)record)[6] = 0;
    ((void **)record)[7] = 0;
    do {
        clearSlot[3] = 0;
        clearIndex = clearIndex - 1;
        clearSlot = clearSlot - 1;
    } while (-1 < clearIndex);

    uVar3 = func_80265350_de();
    if (uVar3 >= 6 * megabyte) {
        blockSize = 0x54600;
        uVar3 = func_80265350_de();
        memoryAddress = uVar3 | 0x80000000;
        D_800DE850 = 3;
        piVar4 = (s32 *)func_80253530_de(0, (s32)(memoryAddress - megabyte), 0x54600,
                                         D_800DCD00_de);
        piVar5 = (s32 *)func_80253530_de(0, (s32)(memoryAddress - 2 * megabyte),
                                         D_800DE850 * blockSize, D_800DCD0C);
        func_802A001C_de((void *)*piVar5, 0, 0xfd200);
        func_802A001C_de((void *)*piVar4, 0, 0x54600);
        ((void **)record)[6] = piVar4;
        ((void **)record)[3] = piVar5;
        D_801536E8 = *(void **)((void **)record)[6];
        count = D_800DE850;
        for (i = 0; i < count; i++) {
            D_8014D468_de[i] = (void *)(*piVar5 + i * blockSize);
        }
        } else {
        blockSize = 0x1ecc0;
        memoryAddress = 0x80400000U;
        compactHandle = (s32 *)func_80253530_de(0, (s32)(memoryAddress - (D_800DE850 + 1) * blockSize),
                                         (D_800DE850 + 1) * blockSize, D_800DCD1C);
        compactCount = D_800DE850;
        ((void **)record)[3] = compactHandle;
        for (i = 0; i < compactCount; i++) {
            D_8014D468_de[i] = (void *)(*compactHandle + blockSize * i);
        }
        D_801536E8 = (void *)(*compactHandle + blockSize * i);
        }

    for (i = 0; i < D_800DE850; i++) {
        func_802A001C_de(D_8014D468_de[i], 0, blockSize);
    }
    func_802A001C_de(D_801536E8, 0, blockSize);

    ((void **)record)[1] = func_8025343C_de(0, (D_800E28A4 + D_800DE858) * 0x10, 0x23, D_800DCD3C);
    ((void **)record)[2] = func_8025343C_de(0, 0x8000, 0x23, &D_800DCD4C);
    ((void **)record)[7] = func_8025343C_de(0, 0x22000, 0x23, D_800DCD54);
    iVar8 = D_800E28A4;
    D_8014D424 = 0x8000;
    D_8014D45C = 0x22000;
    D_8014D460 = *(Gfx **)((void **)record)[1];
    D_8014D420_de = *(s32 *)((void **)record)[7];
    D_8014D42C = D_8014D460 + iVar8;
    D_8014D464 = D_8014D42C + D_800DE858;
    D_8014D428 = *(u64 **)((void **)record)[2];
    D_8014D430_de = D_8014D464 + iVar8;
    if (D_800DE850 != 0) {
        uVar6 = 1;
        do {
            uVar7 = uVar6 < D_800DE850;
            uVar6 = uVar6 + 1;
        } while (uVar7);
    }
    *((void **)record) = (void *)1;
    return 1;
}
#else
INCLUDE_ASM("ovl_80400000", Ovlgame_AllocateRenderBuffers);
#endif
