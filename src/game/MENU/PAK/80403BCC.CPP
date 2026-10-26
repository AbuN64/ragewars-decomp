#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/LONE/D_8010FC00.H"
#include "MENU/80403BCC.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/RECORDRECAT1C.H"
#include "MENU/PAK/80403BCC.H"
#include "sdk/PFS/80447BB0_9.H"

/* Refreshes the cached directory of the Controller Pak on channel ch: when the directory buffer
   exists it reads the state of each of the 16 notes through osPfsFileState (func_80446A20_de),
   retrying a failure once and clearing the cached note when it does not exist (5), then reads the
   free space through func_80446C60_de into the buffer on success and returns that result. */







extern OSPfs D_8014D280[];

extern PakDirectory *D_800E2854;

extern s32 func_80446A20_de(OSPfs *pfs, s32 file_no, NoteState *state);

extern s32 func_80446C60_de(OSPfs *pfs, s32 *free);

static inline void *pak27(s32 ch) {return ((u8 *)D_8014D280)+ch*0x68;}

extern u8 D_8010BBB8;

extern PakRecord D_80153330[];

s32 func_802B7FD8_de(OSMesgQueue *mq, OSPfs *pfs, int channel);

extern s32 Pak_UpdateStatus(s32);

extern u8 D_800DE80C[];

extern void Control_ReadControllerStates(void);

extern void Control_ReleasePakLock(void);

extern s32 XPlus_UppercaseCharacter(s32 c);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern s32 func_80445F80_de(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name,
                         s32 size, s32 *file_no);

extern s32 func_80447AF0_de(OSPfs *pfs, s32 file_no, s32 flag, s32 offset, s32 size, void *data);

static inline void func_804042F0_encode(u8 *dst, u8 *src, s32 n) {
    s32 i;
    s32 j;

    for (i = 0; i < n; i++) {
        src[i] = XPlus_UppercaseCharacter(src[i]);
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

extern s32 func_804042F0_de(s32 ch, s32 size, void *data, u8 *game_name, s32 *file_no, u8 *ext_name,
                         u8 *company, u8 *code);

s32 Pak_RefreshNotes(s32 ch) {
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

s32 Pak_UpdateStatus(s32 ch) {
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
    if(Pak_RefreshNotes(ch)!=0) D_80153500[ch]=-4;
    else D_80153500[ch]=0;
finish:
    return D_80153500[ch]==0 || D_80153500[ch]==-4;
}

void func_804041F0_de(void) {
    s32 channel;
    s32 present;
    PakRecord *record;
    Control_AcquireControllerLock(1);
    Control_ReadControllerStates();
    D_8010BBB8 = 2;
    for (channel = 0; channel < 4; channel++) {
        record = &D_80153330[channel];
        if (D_8010FBE3[channel * 4] != 0) {
            present = 0;
            record->present = 0;
        } else {
            record->present = func_802B7FD8_de(D_8010FC00, record->pak, channel) == 0;
            present = record->present;
        }
        if (present) D_801534F0[channel] = 2;
        else if (Pak_UpdateStatus(channel) != 0) D_801534F0[channel] = 3;
        else D_801534F0[channel] = 1;
    }
    Control_ReleasePakLock();
}

s32 func_804042F0_de(s32 ch, s32 size, void *data, u8 *game_name, s32 *file_no, u8 *ext_name, u8 *company, u8 *code);

s32 func_804042F0_de(s32 ch, s32 size, void *data, u8 *game_name, s32 *file_no, u8 *ext_name,
                  u8 *company, u8 *code) {
    extern s32 func_80446580_de(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name);
    extern s32 Pak_UpdateStatus(s32 ch);
    s32 result;
    u8 name[16];
    u8 ext[4];
    u16 company_code;
    u32 game_code;
    OSPfs *pfs;
    s32 offset;

    if (D_801534F0[ch] != 3) {
        return -2;
    }
    ((void (*)(s32))Control_AcquireControllerLock)(1);
    Control_ReadControllerStates();
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
        Pak_UpdateStatus(ch);
    }
    Control_ReleasePakLock();
    return result;
}
