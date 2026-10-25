#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/MANAGER.H"
#include "COMMON/MESSAGESEMAPHORE.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "TYPES.H"
#include "RESMGR/resmgr_stream_io.H"
#include "RESMGR/resmgr_stream_callbacks.H"
#include "MENU/GFX/80414480_3.H"
#include "SCENE/802508E0_13.H"

/* Formats its arguments into the shared buffer D_8014D0D0 and writes the text to the stream through func_802A0F50_de in runs, emitting the one-byte D_800CAEF0 before every newline, returning the number of bytes written. */

extern unsigned char D_8014D0D0;

extern char D_800CAEF0;

extern void func_802A0F50_de(const unsigned char *data, s32 size, s32 count, void *stream);

/* Initializes and dispatches the resource on the first guarded call. */
extern s32 D_800D2B84;

extern struct CartridgeReadWorker D_801011B8;

extern Record *func_8025305C_de(s32 arg0);

extern void func_8025637C_de(struct CartridgeReadWorker *worker, u32 source, s32 bytes, void *destination);

/* Callable open entry in the low-address resource callback table. */
extern s32 D_002A1158(const void *name, const void *mode);

extern s32 D_002A1188;

extern s32 D_002A1198(s32 handle, void *destination, s32 bytes);

extern s32 D_002A11EC;

/* Callable seek entry in the low-address resource callback table. */
extern s32 D_002A11F4(s32 handle, s32 offset, s32 origin);

extern s32 D_002A1220;

extern s32 D_002A1230;

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
s32 func_802A0C08_de(void *goal, s32 arg1, ...) {
    s32 result;
    char *args;

    args = __builtin_next_arg(arg1);
    result = func_80414CCC_de(goal, arg1, (s32)args);
    D_800CD918 = result;
    return result;
}

s32 func_802A0C38_de(void *stream, const char *format, ...) {
    unsigned char *run;
    unsigned char *p;
    s32 length;
    s32 total;

    func_80414CCC_de(&D_8014D0D0, format, __builtin_next_arg(format));
    run = &D_8014D0D0;
    p = run;
    length = 0;
    total = 0;
    for (; *p != 0; p++, length++) {
        if (*p == '\n') {
            if (length > 0) {
                func_802A0F50_de(run, 1, length, stream);
                total += length;
                length = 0;
                run = p;
            }
            func_802A0F50_de(&D_800CAEF0, 1, 1, stream);
            total++;
        }
    }
    if (length > 0) {
        func_802A0F50_de(run, 1, length, stream);
        total += length;
    }
    return total;
}

void Resmgr_InitializeStreams(void) {
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
        v0 = func_8025305C_de(read_resource_word(&D_800CD940_de.size));
        write_resource_buffer(&D_800CD940_de.data, v0);
        func_8025637C_de(&D_801011B8, 0x200000, read_resource_word(&D_800CD940_de.size), v0);
        write_resource_word(&D_800CD940_de.opened,0);
        D_800CD940_de.ready = one;
    }
    func_802A1050_de(D_002A1158, (s32) &D_002A1188, D_002A1198, (s32) &D_002A11EC, D_002A11F4, (s32) &D_002A1220, (s32) &D_002A1230);
}

void Resmgr_ShutdownStreams(void) {
    D_800D2B80--;
    if (D_800CD940_de.data != 0) {
        func_802547E4_de(D_800CD940_de.data);
    }
    clear_resource_state();
}

/* Forward both open arguments and return the callback's stream handle. */
s32 Resmgr_OpenStream(const void *name, const void *mode) {
    return D_800CD924_de(name, mode);
}

void Resmgr_CloseStream(void) {
    D_800CD928_de();
}

s32 Resmgr_ReadStream(void *destination, s32 elementSize, s32 count, s32 handle) {
    s32 totalBytes;
    s32 result;

    totalBytes = elementSize * count;
    if (totalBytes == 0) {
        return 0;
    }
    result = D_800CD92C_de(handle, destination, totalBytes);
    return result / elementSize;
}
