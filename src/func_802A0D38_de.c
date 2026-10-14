#include "span_1000/code_802A0AC4.h"
#include "types.h"
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
