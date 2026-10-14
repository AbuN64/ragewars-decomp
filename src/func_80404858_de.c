#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"
/* Deletes note index of the Controller Pak on channel ch: refuses with -2 unless the pak state is
   ready (3), takes the pak lock, and when the pak has no pending error deletes the note named by
   the cached directory entry's company code, game code, game name and extension through
   osPfsDeleteFile (func_80446580_de), mapping any failure to -1 and refreshing the directory through
   func_80404018_de; releases the lock and returns the result. */









extern OSPfs_func_80403E90_de D_8014D280[];
extern PakDirectory *D_800E2854;
extern u8 D_8010BBB8;


extern void func_80263740_de(void);
extern void func_8026454C_de(void);
extern s32 func_80446580_de(OSPfs_func_80403E90_de *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name);
extern void func_80404018_de(s32 ch);

s32 func_80404858_de(s32 ch, s32 index) {
    s32 result;

    if (D_801534F0[ch] != 3) {
        return -2;
    }
    ((void (*)(s32))func_802644FC_de)(1);
    func_80263740_de();
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
        func_80404018_de(ch);
    }
    func_8026454C_de();
    return result;
}
