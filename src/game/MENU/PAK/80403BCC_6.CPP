#include "MENU/PAK/pak_note_search.H"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/LONE/D_80152789.H"
#include "include_asm.h"
#include "stddef.h"
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

extern u8 D_800DE80C[0x42];

extern void Render_ReadControllerStates(void);

extern void Render_ReleasePakLock(void);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern s32 func_80445F80_de(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name,
                         s32 size, s32 *file_no);

extern s32 func_80447AF0_de(OSPfs *pfs, s32 file_no, s32 flag, s32 offset, s32 size, void *data);

/* Inline copy of func_80405648_de: decodes the n pak font codes at src into dst as text (codes from
   0x42 up become '~', leading zero codes blanks), trims trailing blanks and terminates dst. */
static inline void Pak_DecodeNoteName(u8 *src, u8 *dst, s32 n) {
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
extern u8 *D_800E25C4[], *D_800E25C4[];
#endif

extern char g_pakReadScratchNoteName[];

extern char g_pakWriteScratchNoteName[];

extern void **Scene_AllocateResource(s32, s32, s32, char *);

extern void func_80253908_de(s32);


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
    handle = Scene_AllocateResource(0, blocks, 0x23, g_pakReadScratchNoteName);
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
    Render_ReleasePakLock();
    func_80253908_de(0);
    if (handle != 0) {
        Scene_ReleaseResource(0, handle);
    }
    return result;
}

extern s32 func_804042F0_de(s32 ch, s32 size, void *data, u8 *game_name, s32 *file_no, u8 *ext_name, u8 *company, u8 *code);

/* Reports note index of the Controller Pak on channel ch from the cached directory: refuses with -2
   unless the pak is ready, clears the exists flag for an empty slot, and otherwise returns its size
   in 256-byte blocks, its company and game codes as terminated byte strings, and its game name and
   extension decoded from pak font codes with trailing blanks trimmed. */
s32 Pak_ReadNoteInfo(s32 ch, s32 index, s32 *exists, u8 *name, u8 *ext, s32 *size, u8 *company,
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
    Pak_DecodeNoteName(D_800E2854[ch].notes[index].game_name, name, 17);
    Pak_DecodeNoteName(D_800E2854[ch].notes[index].ext_name, ext, 4);
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
    Render_ReleasePakLock();
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
    handle = Scene_AllocateResource(0, blocks, 0x23, g_pakWriteScratchNoteName);
    buf = *handle;
    for (tries = 0; tries < 4; tries++) {
        result = func_804042F0_de(ch, size, data, name, &file_no, ext, RW_LOCALIZED_TEXT(D_800D36DC, D_800E25C4, D_800E25C4, g_languageIndex), code);
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
        Scene_ReleaseResource(0, handle);
    }
    return result;
}


/* Inline copy of Pak_GetNoteGameName: points *gameName at note's encoded game name in the cached
   directory of channel's pak and returns 0, or returns -2 (leaving *gameName untouched) unless that
   pak is ready. */
static inline s32 Pak_PeekNoteGameName(s32 channel, s32 note, u8 **gameName) {
    if (D_801534F0[channel] != 3) {
        return -2;
    }
    *gameName = D_800E2854[channel].notes[note].game_name;
    return 0;
}

/* Searches the 16 notes of the Controller Pak on channel for one whose decoded game name equals name:
   stores its index in *noteIndex (when given) and returns 1, or returns 0 when none matches. */
s32 Pak_FindNoteByName(void *name, s32 channel, s32 *noteIndex) {
    u8 decodedName[16];
    u8 *encodedName;
    s32 note;

    for (note = 0; note < 16; note++) {
        Pak_PeekNoteGameName(channel, note, &encodedName);
        Pak_DecodeNoteName(encodedName, decodedName, 16);
        if (Resmgr_CompareStrings(decodedName, name) == 0) {
            if (noteIndex != NULL) {
                *noteIndex = note;
            }
            return 1;
        }
    }
    return 0;
}
