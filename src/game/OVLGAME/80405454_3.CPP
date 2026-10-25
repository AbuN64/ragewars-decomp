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

#include "stddef.h"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/EXTERNS_12.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/DISPLAY.H"
#include "COMMON/SHAREDPLAYER.H"
typedef struct Shape_typemap_165 Handle;
extern void func_80253838_de(void *heap, Handle *handle);
extern u32 func_80265350_de(void);
extern Handle *func_80253530_de(void *heap, u32 address, u32 size, char *name);
extern char D_800DCD00_de[9];  /* "Z-Buffer" */
extern char D_800DCD0C[15];    /* "Display Buffer" */
extern char D_800DCD1C[31];    /* "color frame buffers + z buffer" */
extern char D_800DCD3C[14];    /* "display lists" */
extern char D_800DCD4C[5];     /* "fifo" */
extern char D_800DCD54[11];    /* "audio heap" */
/* Rebuilds the render buffers held by the record: releases every handle it holds and clears it, then
   claims the frame buffers at the top of RDRAM (three 0x54600-byte buffers below the 1 MB z-buffer when
   the expansion pak gives 6 MB or more; otherwise the count in D_800DE850 plus one 0x1ECC0-byte buffer,
   the extra one holding the z-buffer, below 4 MB), clears them, allocates the display lists, the RSP fifo
   and the audio heap, publishes their addresses in the render globals and marks the record ready. */
int Ovlgame_AllocateRenderBuffers(struct RecordRecAt1C *record) {
    u32 megabyte = 0x100000;
    u32 bufferBytes;
    u32 memoryEnd;
    Handle *zBuffer;
    Handle *frameBuffers;
    Handle *buffers;
    u32 i;
    s32 j;
    s32 k;

    if (record->displayLists != NULL) {
        func_80253838_de(NULL, record->displayLists);
    }
    if (record->fifo != NULL) {
        func_80253838_de(NULL, record->fifo);
    }
    if (record->zBuffer != NULL) {
        func_80253838_de(NULL, record->zBuffer);
    }
    if (record->audioHeap != NULL) {
        func_80253838_de(NULL, record->audioHeap);
    }
    for (j = 0; j < 3; j++) {
        if (record->frameBuffers[j] != NULL) {
            func_80253838_de(NULL, record->frameBuffers[j]);
        }
    }
    record->ready = 0;
    record->displayLists = NULL;
    record->fifo = NULL;
    record->zBuffer = NULL;
    record->audioHeap = NULL;
    for (k = 2; k >= 0; k--) {
        record->frameBuffers[k] = NULL;
    }

    if (func_80265350_de() >= 6 * megabyte) {
        bufferBytes = 0x54600;
        memoryEnd = func_80265350_de() | 0x80000000;
        D_800DE850 = 3;
        zBuffer = func_80253530_de(NULL, memoryEnd - megabyte, 0x54600, D_800DCD00_de);
        frameBuffers = func_80253530_de(NULL, memoryEnd - 2 * megabyte, D_800DE850 * bufferBytes,
                                                D_800DCD0C);
        Resmgr_FillMemory(frameBuffers->data, 0, 0xFD200);
        Resmgr_FillMemory(zBuffer->data, 0, 0x54600);
        record->zBuffer = zBuffer;
        record->frameBuffers[0] = frameBuffers;
        D_801536E8 = record->zBuffer->data;
        for (i = 0; i < D_800DE850; i++) {
            D_8014D468_de[i] = (u8 *)frameBuffers->data + i * bufferBytes;
        }
    } else {
        bufferBytes = 0x1ECC0;
        memoryEnd = 0x80400000;
        buffers = func_80253530_de(NULL, memoryEnd - (D_800DE850 + 1) * bufferBytes,
                                           (D_800DE850 + 1) * bufferBytes, D_800DCD1C);
        record->frameBuffers[0] = buffers;
        for (i = 0; i < D_800DE850; i++) {
            D_8014D468_de[i] = (u8 *)buffers->data + bufferBytes * i;
        }
        D_801536E8 = (u8 *)buffers->data + bufferBytes * i;
    }
    for (i = 0; i < D_800DE850; i++) {
        Resmgr_FillMemory(D_8014D468_de[i], 0, bufferBytes);
    }
    Resmgr_FillMemory(D_801536E8, 0, bufferBytes);

    record->displayLists = Scene_AllocateResource(0, (D_800E28A4 + D_800DE858) * 2 * sizeof(Gfx), 0x23, D_800DCD3C);
    record->fifo = Scene_AllocateResource(0, 0x8000, 0x23, D_800DCD4C);
    record->audioHeap = Scene_AllocateResource(0, 0x22000, 0x23, D_800DCD54);
    D_8014D424 = 0x8000;
    D_8014D45C = 0x22000;
    D_8014D460 = record->displayLists->data;
    D_8014D42C = D_8014D460 + D_800E28A4;
    D_8014D464 = D_8014D42C + D_800DE858;
    D_8014D430_de = D_8014D464 + D_800E28A4;
    D_8014D428 = record->fifo->data;
    D_8014D420_de = (s32)record->audioHeap->data;
    for (i = 0; i < D_800DE850; i++) {
    }
    record->ready = 1;
    return 1;
}
