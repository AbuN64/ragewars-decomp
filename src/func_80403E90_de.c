#include "span_16E000/code_80403BCC.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
/* Refreshes the cached directory of the Controller Pak on channel ch: when the directory buffer
   exists it reads the state of each of the 16 notes through osPfsFileState (func_80446A20_de),
   retrying a failure once and clearing the cached note when it does not exist (5), then reads the
   free space through func_80446C60_de into the buffer on success and returns that result. */







extern OSPfs D_8014D280[];
extern PakDirectory *D_800E2854;

extern s32 func_80446A20_de(OSPfs *pfs, s32 file_no, NoteState *state);
extern s32 func_80446C60_de(OSPfs *pfs, s32 *free);

s32 func_80403E90_de(s32 ch) {
    s32 i;
    s32 result;
    s32 free;

    if (D_800E2854 != 0) {
        for (i = 0; i < 16; i++) {
            result = func_80446A20_de(&D_8014D280[ch], i, &D_800E2854[ch].notes[i]);
            if (result != 0 && result != 5) {
                result = func_80446A20_de(&D_8014D280[ch], i, &D_800E2854[ch].notes[i]);
            }
            if (result == 5) {
                D_800E2854[ch].notes[i].file_size = 0;
                D_800E2854[ch].notes[i].game_code = 0;
                D_800E2854[ch].notes[i].company_code = 0;
                D_800E2854[ch].notes[i].ext_name[0] = 0;
                D_800E2854[ch].notes[i].game_name[0] = 0;
            }
        }
    }
    result = func_80446C60_de(&D_8014D280[ch], &free);
    if (result == 0) {
        D_800E2854[ch].free = free;
    }
    return result;
}

extern u8 D_8010FC00[];
extern OSPfs D_8014D280[];
static inline void *pak27(s32 ch) {return ((u8 *)D_8014D280)+ch*0x68;}
s32 func_80404018_de(s32 ch) {
    s32 tries;
    s32 result;
    void *pfs;
    OSPfs *base;
    if(D_8010FBE3[ch*4] != 0) {
        D_80153500[ch]=-2;
        return 0;
    }
    tries=0;
    do {
        pfs=pak27(ch);
        result=func_80446F60_de(D_8010FC00,pfs,ch);
        switch(result) {
        case 0: case 2:
            D_80153500[ch]=-5;
            break;
        case 1:
            D_80153500[ch]=-2;
            break;
        case 4: case 11:
            D_80153500[ch]=-3;
            break;
        case 10:
            D_80153500[ch]=-4;
            break;
        }
        if(D_80153500[ch]==-5) goto ready;
        if(D_80153500[ch]==-2) break;
        tries++;
    } while(tries<4);
    goto finish;
ready:
    D_801534F0[ch]=3;
    if(func_80403E90_de(ch)!=0) D_80153500[ch]=-4;
    else D_80153500[ch]=0;
finish:
    return D_80153500[ch]==0 || D_80153500[ch]==-4;
}
