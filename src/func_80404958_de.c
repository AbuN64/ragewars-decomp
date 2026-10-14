#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"
/* Saves data as a Controller Pak note on channel ch and verifies it: refuses with -2 unless the pak
   is ready, then up to four times writes the note through func_804042F0_de with the D_800D36DC
   company code, reads it back into a temporary buffer through an inlined note read, and stops when
   the bytes compare equal or deletes the note through func_80404858_de and retries, returning the
   write result. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern u8 *D_800E25C4[], *D_800E25C4[];
#endif



extern OSPfs_func_80403E90_de D_8014D280[];
extern u8 D_8010BBB8;

extern char D_800DCCD0[];
extern char D_800DCCE8_de[];

extern void **func_8025343C_de(s32, s32, s32, char *);
extern void func_80253908_de(s32);
extern void func_80253838_de(s32, void *);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(s32);

extern void func_80263740_de(void);
extern void func_8026454C_de(void);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
extern s32 func_80265444_de(void *a, void *b, s32 size);
extern s32 func_80447AF0_de(OSPfs_func_80403E90_de *pfs, s32 file_no, s32 flag, s32 offset, s32 size, void *data);
extern s32 func_804042F0_de(s32 ch, s32 size, void *data, u8 *game_name, s32 *file_no, u8 *ext_name,
                         u8 *company, u8 *code);
extern s32 func_80404858_de(s32 ch, s32 index);

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
    func_80263740_de();
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

s32 func_80404958_de(s32 ch, s32 size, void *data, u8 *name, u8 *ext, u8 *code) {
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
        if (func_80404858_de(ch, file_no) != 0) {
            break;
        }
    }
    func_80253908_de(0);
    if (handle != 0) {
        func_80253838_de(0, handle);
    }
    return result;
}
