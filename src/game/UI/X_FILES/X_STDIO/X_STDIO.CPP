#include "COMMON/INTEGERSTATE14_2.H"
#include "COMMON/UNUSED.H"
#include "stdarg.h"
#include "TYPES.H"
#include "MENU/GFX/GFX_FORMATARGUMENTLIST.H"
#include "include_asm.h"
#include "COMMON/LONE/X_STDIO.H"
#include "COMMON/MESSAGESEMAPHORE.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/MANAGER.H"
#include "RESMGR/resmgr_stream_io.H"
#include "RESMGR/resmgr_stream_callbacks.H"
#include "SCENE/CACHE_FREEMEMORY.H"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/STATEPAIR.H"
#include "X_STDIO/X_STDIO.H"

/* 802A0888_6.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)

u8 *XStdio_FormatScratchBuffer(u8 *fmt0, ...) {
    va_list args;
    va_start(args, fmt0);
    D_800CD918 = Gfx_FormatArgumentList((u8 *)&D_8014D0D0, fmt0, args);
    va_end(args);
    return (u8 *)&D_8014D0D0;
}
#endif

/* 802A0888_7.CPP */
#if defined(VERSION_DE) || defined(VERSION_EU)
#include "stdarg.h"

int *XStdio_FormatGermanScratchBuffer(int format, ...) {
    va_list args;
    va_start(args, format);
    D_800CD918 = Gfx_FormatArgumentList(&D_8014D0D0, format, (int)args);
    va_end(args);
    return &D_8014D0D0;
}
#endif

#if !(defined(VERSION_US))

s32 XStdio_PrintText(s32 fmt0, ...) {
    char *args;

    args = __builtin_next_arg(fmt0);
    D_800CD918 = Gfx_FormatArgumentList(&D_8014D0D0, fmt0, (s32) args);
    if (D_800CD91C != 0) {
        ((s32 (*)(s32 *)) D_800CD91C)(&D_8014D0D0);
    }
    return D_800CD918;
}

s32 XStdio_PrintTextWithArguments(s32 arg0, s32 arg1, s32 fmt0, ...) {
    char *args;

    args = __builtin_next_arg(fmt0);
    D_800CD918 = Gfx_FormatArgumentList(&D_8014D0D0, fmt0, (s32) args);
    ((s32 (*)(s32 *, s32, s32)) D_800CD920_de)(&D_8014D0D0, arg0, arg1);
    return D_800CD918;
}
#endif

/* resmgr_stream_io.CPP */
/* Formats its arguments into the shared buffer D_8014D0D0 and writes the text to the stream through XStdio_WriteStreamNoop in runs, emitting the one-byte D_800CAEF0 before every newline, returning the number of bytes written. */



/* Initializes and dispatches the resource on the first guarded call. */

extern struct CartridgeReadWorker D_801011B8;


extern void func_8025637C_de(struct CartridgeReadWorker *worker, u32 source, s32 bytes, void *destination);

/* Callable open entry in the low-address resource callback table. */


/* Callable seek entry in the low-address resource callback table. */

inline static s32 *guard_address(void) {
    return &D_800D2B80;
}

inline static s32 increment_guard(s32 *counter) {
    s32 current = *counter;
    s32 previous = current;
    current++;
    *counter = current;
    return previous;
}

static inline s32 read_resource_word(s32 *word) {
    return *word;
}

static inline void write_resource_word(s32 *word, s32 value) {
    *word = value;
}

static inline void write_resource_buffer(u8 **buffer, void *allocation) {
    *buffer = allocation;
}

static inline void clear_resource_state(void) {
    D_800CD940_de.data = 0;
    D_800CD940_de.opened = 0;
    D_800CD940_de.ready = 0;
}

typedef void (*FuncPtr)(void);

extern ResourceOpenCallback D_800CD924_de;

extern FuncPtr D_800CD928_de;

extern ResourceReadCallback D_800CD92C_de;

/** Pass the variadic tail address to the formatter and retain its result. */
s32 XStdio_FormatBuffer(void *goal, s32 fmt0, ...) {
    s32 result;
    char *args;

    args = __builtin_next_arg(fmt0);
    result = Gfx_FormatArgumentList(goal, fmt0, (s32)args);
    D_800CD918 = result;
    return result;
}

s32 XStdio_PrintStream(void *stream, const char *format, ...) {
    unsigned char *run;
    unsigned char *p;
    s32 length;
    s32 total;

    Gfx_FormatArgumentList((u8 *)&D_8014D0D0, format, __builtin_next_arg(format));
    run = (u8 *)&D_8014D0D0;
    p = run;
    length = 0;
    total = 0;
    for (; *p != 0; p++, length++) {
        if (*p == '\n') {
            if (length > 0) {
                XStdio_WriteStreamNoop(run, 1, length, stream);
                total += length;
                length = 0;
                run = p;
            }
            XStdio_WriteStreamNoop(&D_800CAEF0, 1, 1, stream);
            total++;
        }
    }
    if (length > 0) {
        XStdio_WriteStreamNoop(run, 1, length, stream);
        total += length;
    }
    return total;
}

void XStdio_InitializeStreams(void) {
    void *v0;
    s32 one;

    if (increment_guard(guard_address()) != 0) {
        return;
    }
    D_800D2B84 = 0x12345678;
    one = 1;
    if (read_resource_word(&D_800CD940_de.ready) != one) {
#if defined(VERSION_DE)
        D_800CD940_de.size = 0x8BB01;
#elif defined(VERSION_EU_X)
        D_800CD940_de.size = 0x90385;
#else
        D_800CD940_de.size = 0x8B245;
#endif
        v0 = Cache_AllocateMemory(read_resource_word(&D_800CD940_de.size));
        write_resource_buffer(&D_800CD940_de.data, v0);
        func_8025637C_de(&D_801011B8, 0x200000, read_resource_word(&D_800CD940_de.size), v0);
        write_resource_word(&D_800CD940_de.opened,0);
        D_800CD940_de.ready = one;
    }
    XStdio_SetStreamCallbacks((ResourceOpenCallback)&D_002A1158, (s32) &D_002A1188, (ResourceReadCallback)&D_002A1198, (s32) &D_002A11EC, (ResourceSeekCallback)&D_002A11F4, (s32) &D_002A1220, (s32) &D_002A1230);
}

void XStdio_ShutdownStreams(void) {
    D_800D2B80--;
    if (D_800CD940_de.data != 0) {
        Cache_FreeMemory(D_800CD940_de.data);
    }
    clear_resource_state();
}

/* Forward both open arguments and return the callback's stream handle. */
s32 XStdio_OpenStream(const void *name, const void *mode) {
    return D_800CD924_de(name, mode);
}

void XStdio_CloseStream(void) {
    D_800CD928_de();
}

s32 XStdio_ReadStream(void *destination, s32 elementSize, s32 count, s32 handle) {
    s32 totalBytes;
    s32 result;

    totalBytes = elementSize * count;
    if (totalBytes == 0) {
        return 0;
    }
    result = D_800CD92C_de(handle, destination, totalBytes);
    return result / elementSize;
}

/* resmgr_stream_callbacks.CPP */


extern ResourceSeekCallback D_800CD934_de;
extern FuncPtr D_800CD938_de;
extern FuncPtr D_800CD93C_de;


/* Allocates the resource once and marks its five-word state ready. */


/** Return the constant false result used by callers at VRAM 0x802A1F50. */
s32 XStdio_WriteStreamNoop(const unsigned char *data, s32 size, s32 count, void *stream) {
    return 0;
}

/** Return the zero status used by callers. */
int func_802A0F58_de(void) {
    return 0;
}

/* Forward every seek argument and return the configured callback status. */
s32 XStdio_SeekStream(s32 handle, s32 offset, s32 origin) {
    return D_800CD934_de(handle, offset, origin);
}

void XStdio_QueryStreamPosition(void) {
    D_800CD938_de();
}

void XStdio_QueryStreamEnd(void) {
    extern FuncPtr D_800CD93C_de;
    D_800CD93C_de();
}

s32 XStdio_ReadCharacter(s32 arg0) {
    u8 sp10;
    s32 result;

    if (D_800CD92C_de(arg0, &sp10, 1) != 0) {
        result = sp10;
    } else {
        result = -1;
    }
    return result;
}

int func_802A1004_de(void) {
    return 0;
}

s32 *XStdio_FormatScratchArgumentList(s32 fmt0, s32 arg1) {
    D_800CD918 = Gfx_FormatArgumentList(&D_8014D0D0, fmt0, arg1);
    return &D_8014D0D0;
}

void XStdio_SetStreamCallbacks(ResourceOpenCallback arg0, s32 arg1, ResourceReadCallback arg2, s32 arg3, ResourceSeekCallback arg4, FuncPtr arg5, FuncPtr arg6) {
    D_800CD924_de = arg0;
    D_800CD928_de = (FuncPtr)arg1;
    D_800CD92C_de = arg2;
    D_800CD930_de = arg3;
    D_800CD934_de = arg4;
    D_800CD938_de = arg5;
    D_800CD93C_de = arg6;
}

void XStdio_LoadMemoryStream(void) {
    void *buffer;
    IntegerState14_2 *stream;
    if (D_800CD940_de.ready != 1) {
#if defined(VERSION_DE)
        D_800CD940_de.size = 0x8BB01;
        buffer = Cache_AllocateMemory(0x8BB01);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        D_800CD940_de.size = 0x8B245;
        buffer = Cache_AllocateMemory(0x8B245);
#elif defined(VERSION_EU_X)
        D_800CD940_de.size = 0x90385;
        buffer = Cache_AllocateMemory(0x90385);
#endif
        D_800CD940_de.data = buffer;
        func_8025637C_de(&D_801011B8, 0x200000, D_800CD940_de.size, buffer);
        stream = &D_800CD940_de;
        stream->opened = 0;
        D_800CD940_de.ready = 1;
    }
}

void XStdio_FreeMemoryStream(void) {
    if (D_800CD940_de.data != 0) {
        Cache_FreeMemory(D_800CD940_de.data);
    }
    D_800CD940_de.data = 0;
    D_800CD940_de.opened = 0;
    D_800CD940_de.ready = 0;
}

/* Reset the memory stream and return its single valid handle. */
s32 XStdio_OpenMemoryStream(const void *name, const void *mode) {
    const u8 *modeCursor = mode;
    while (*modeCursor != 0) {
        modeCursor++;
    }
    modeCursor++;
    D_800CD940_de.cursor = 0;
    D_800CD940_de.opened = 1;
    return 1;
}

/** Clear the global word at VRAM 0x800D2BBC. */

void XStdio_CloseMemoryStream(void) {
    D_800CD940_de.opened = 0;
}

s32 XStdio_ReadMemoryStream(s32 handle, void *destination, s32 bytes) {
    IntegerState14_2 *stream = &D_800CD940_de;
    XPlus_CopyBytes(destination, stream->data + stream->cursor, bytes);
    stream->cursor = stream->cursor + bytes;
    return 1;
}

/** Return the false result used by callers at VRAM 0x802A21EC. */
int XStdio_WriteMemoryStreamNoop(void) {
    return 0;
}

s32 XStdio_SeekMemoryStream(s32 handle, s32 offset, s32 origin) {

    if (origin == 0) {
        D_800CD940_de.cursor = 0;
    }
    D_800CD940_de.cursor = D_800CD940_de.cursor + offset;
    return 0;
}

/** Return the first global state word. */
unsigned int XStdio_TellMemoryStream(void) {
    return D_800CD940_de.cursor;
}

/* resmgr_stream_status.CPP */
int XStdio_IsMemoryStreamAtEnd(void) {
    return D_800CD940_de.cursor == D_800CD940_de.size;
}

/** Store two values in the paired global words. */
void XStdio_SetTextOutputCallbacks(int first, int second) {
    D_800CD91C = first;
    D_800CD920_de = second;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802A11A4[3] = {
    0x43000000, 0x10000B00, 0x00000000,
};
#endif
