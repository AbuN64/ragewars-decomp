#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"
/* Writes a note to the Controller Pak on channel ch: refuses with -2 unless the pak is ready,
   takes the controller lock and, when the pak has no pending error, converts the extension and
   game name to pak font codes, allocates the note rounded up to whole 256-byte blocks through
   osPfsAllocateFile (func_80445F80_de), writes the data through osPfsReadWriteFile (func_80447AF0_de),
   deletes the note again if the write fails, refreshes the pak state through func_80404018_de and
   returns 0 or -1. */





extern OSPfs_func_80403E90_de D_8014D280[];
extern u8 D_8010BBB8;
extern u8 D_800DE80C[];


extern void func_80263740_de(void);
extern void func_8026454C_de(void);
extern s32 func_802A05A0_de(s32 c);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
extern s32 func_80445F80_de(OSPfs_func_80403E90_de *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name,
                         s32 size, s32 *file_no);
extern s32 func_80447AF0_de(OSPfs_func_80403E90_de *pfs, s32 file_no, s32 flag, s32 offset, s32 size, void *data);
extern s32 func_80446580_de(OSPfs_func_80403E90_de *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name);
extern s32 func_80404018_de(s32 ch);

static inline void func_804042F0_encode(u8 *dst, u8 *src, s32 n) {
    s32 i;
    s32 j;

    for (i = 0; i < n; i++) {
        src[i] = func_802A05A0_de(src[i]);
        for (j = 0; j < 0x42; j++) {
            if (src[i] == D_800DE80C[j]) {
                dst[i] = j;
                break;
            }
        }
        if (j == 0x42) {
            dst[i] = 0;
        }
    }
}

s32 func_804042F0_de(s32 ch, s32 size, void *data, u8 *game_name, s32 *file_no, u8 *ext_name,
                  u8 *company, u8 *code) {
    s32 result;
    u8 name[16];
    u8 ext[4];
    u16 company_code;
    u32 game_code;
    OSPfs_func_80403E90_de *pfs;
    s32 offset;

    if (D_801534F0[ch] != 3) {
        return -2;
    }
    ((void (*)(s32))func_802644FC_de)(1);
    func_80263740_de();
    result = D_80153500[ch];
    D_8010BBB8 = 2;
    if (result == 0) {
        func_804042F0_encode(ext, ext_name, 4);
        size = (size + 0xFF) & ~0xFF;
        func_802BD3A0_de(name, game_name, 16);
        func_804042F0_encode(name, game_name, 16);
        pfs = &D_8014D280[ch];
        company_code = (company[0] << 8) | company[1];
        game_code = (code[0] << 24) | (code[1] << 16) | (code[2] << 8) | code[3];
        result = func_80445F80_de(pfs, company_code, game_code, name, ext, size, file_no);
        if (result != 0) {
            result = -1;
        }
        offset = 0;
        if (result == 0) {
            result = func_80447AF0_de(pfs, *file_no, 1, offset, size, data);
            if (result != 0) {
                func_80446580_de(pfs, company_code, game_code, name, ext);
                result = -1;
            }
        }
        func_80404018_de(ch);
    }
    func_8026454C_de();
    return result;
}
