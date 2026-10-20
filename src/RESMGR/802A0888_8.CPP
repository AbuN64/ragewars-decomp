#include "COMMON/MESSAGESEMAPHORE.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "TYPES.H"
#include "RESMGR/802A0888_8.H"
#include "RESMGR/802A0888_9.H"
#include "MENU/GFX/80414480_3.H"
#include "SCENE/802508E0_13.H"

/* Formats its arguments into the shared buffer D_8014D0D0 and writes the text to the stream through func_802A0F50_de in runs, emitting the one-byte D_800CAEF0 before every newline, returning the number of bytes written. */

extern unsigned char D_8014D0D0;

extern char D_800CAEF0;

extern void func_802A0F50_de(const unsigned char *data, s32 size, s32 count, void *stream);

/* Initializes and dispatches the resource on the first guarded call. */
extern s32 D_800D2B84;

extern s32 D_801011B8;

extern s32 func_8025305C_de(s32 arg0);

extern s32 func_8025637C_de(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);

extern s32 D_002A1158;

extern s32 D_002A1188;

extern s32 D_002A1198;

extern s32 D_002A11EC;

extern s32 D_002A11F4;

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


static inline void clear_resource_state(void) {
    D_800CD940_de[0] = 0;
    D_800CD940_de[3] = 0;
    D_800CD940_de[4] = 0;
}

typedef void (*FuncPtr)(void);

extern FuncPtr D_800CD924_de;

extern FuncPtr D_800CD928_de;

extern s32 (*D_800CD92C_de)(s32, s32, s32);

/** Pass the variadic tail address to the formatter and retain its result. */
s32 func_802A0C08_de(void *arg0, s32 arg1, ...) {
    s32 result;
    char *args;

    args = __builtin_next_arg(arg1);
    result = func_80414CCC_de(arg0, arg1, (s32)args);
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

void func_802A0D38_de(void) {
    s32 v0;
    s32 one;
    s32 *p;

    if (increment_guard(guard_address()) != 0) {
        return;
    }
    D_800D2B84 = 0x12345678;
    one = 1;
    if (read_resource_word(&D_800CD940_de[4]) != one) {
        p = &D_800CD940_de[2];
#if defined(VERSION_DE)
        p[0] = 0x8BB01;
#elif defined(VERSION_EU_X)
        p[0] = 0x90385;
#else
        p[0] = 0x8B245;
#endif
        v0 = func_8025305C_de(read_resource_word(&D_800CD940_de[2]));
        write_resource_word(&D_800CD940_de[0],v0);
        func_8025637C_de(&D_801011B8, 0x200000, read_resource_word(&D_800CD940_de[2]), v0);
        write_resource_word(&D_800CD940_de[3],0);
        p[2]=one;
    }
    func_802A1050_de((s32) &D_002A1158, (s32) &D_002A1188, (s32) &D_002A1198, (s32) &D_002A11EC, (s32) &D_002A11F4, (s32) &D_002A1220, (s32) &D_002A1230);
}

void func_802A0E34_de(void) {
    D_800D2B80--;
    if (D_800CD940_de[0] != 0) {
        func_802547E4_de(D_800CD940_de[0]);
    }
    clear_resource_state();
}

void func_802A0E8C_de(void) {
    D_800CD924_de();
}

void func_802A0EB0_de(void) {
    D_800CD928_de();
}

s32 func_802A0ED4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 lo;
    s32 result;

    lo = arg1 * arg2;
    if (lo == 0) {
        return 0;
    }
    result = D_800CD92C_de(arg3, arg0, lo);
    return result / arg1;
}
