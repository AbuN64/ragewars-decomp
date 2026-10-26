#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/UNUSED.H"
#include "MENU/80403BCC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "stddef.h"
#include "TYPES.H"
#include "MENU/PAK/80403BCC_8.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

/* Loads a page-aligned resource into the selected device slot and reports the result. */






extern s8 D_8010BBB8;


extern s32 *Cache_AllocateResource(s32, s32, s32, void *);


extern void func_80253908_de(s32);

extern void func_8025476C_de(s32);

extern s32 func_8025477C_de(void);

extern void Control_ReadControllerStates(void);

extern void Control_ReleasePakLock(void);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern s32 func_80447AF0_de(Device *, s32, s32, s32, s32, s32);

/* For a player slot whose state D_801534F0 is 3, writes its score (the first word of its 0x204-byte
   record in D_800E2854 divided by 256, or 0 when the flag D_80153500 is set) and returns the flag;
   other states return -2. */




/* Refreshes a controller slot and resolves its pending device state. */
void Control_ReadControllerStates();

 /* extern */
 /* extern */
void Control_ReleasePakLock();

 /* extern */
void Pak_UpdateStatus(s32);

 /* extern */
s32 func_80447F30_de(void *);

/* Reports the address of the field at offset 0xE of entry j in record i of the table D_800E2854
   points to, returning zero, or returns -2 when record i's state in D_801534F0 is not 3. */







/* Reports the address of the field at offset 0xA of entry j in record i of the table D_800E2854
   points to, returning zero, or returns -2 when record i's state in D_801534F0 is not 3. */







/* Reports through the third argument the size in 256-byte units, per Pak_BytesToPakPages, of entry j of
   record i in the table D_800E2854 points to, returning zero, or returns -2 when record i's state in
   D_801534F0 is not 3. */







extern s32 Pak_BytesToPakPages(s32);

extern PakDirectory *D_800E2854;

extern Device D_8014D280[];

s32 Pak_ReadNoteData(s32 slot, s32 noteIndex, s32 destination, s32 length)
{
  s32 size;
  s32 *buf;
  s32 zero;
  s32 one;
  s32 addr;
  s32 result;
  size = (length + 0xFF) & (~0xFF);
  one = 1;
  zero = 0;
  if (D_801534F0[slot] != 3)
  {
    return -2;
  }
  if (func_8025477C_de() == 0)
  {
    func_8025476C_de(one);
  }
  buf = Cache_AllocateResource(0, size, 0x23, g_pakReadScratchNoteName);
  addr = *buf;
  ((void (*)(s32))Control_AcquireControllerLock)(1);
  Control_ReadControllerStates();
  result = D_80153500[slot];
  D_8010BBB8 = 2;
  if (result == 0)
  {
    result = func_80447AF0_de(&D_8014D280[slot], noteIndex, zero, zero, size, addr);
    if (result != zero)
    {
      result = -1;
    }
    if (result == 0)
    {
      func_802BD3A0_de(destination, addr, length);
    }
  }
  Control_ReleasePakLock();
  func_80253908_de(zero);
  if (buf != ((void *) 0))
  {
    Cache_ReleaseResource(0, buf);
  }
  return result;
}

/* Counts empty Controller Pak note slots on channel ch when the pak is ready and returns its error status, or -2 when not ready. */
s32 Pak_CountFreeNotes(s32 ch, s32 *count) {
    s32 i;

    if (D_801534F0[ch] != 3) {
        return -2;
    }
    *count = 0;
    if (D_80153500[ch] == 0) {
        for (i = 0; i < 16; i++) {
            if (D_800E2854[ch].notes[i].file_size == 0) {
                (*count)++;
            }
        }
    }
    return D_80153500[ch];
}

int Pak_GetFreePages(int slot, int *score) {
    if (D_801534F0[slot] != 3) {
        return -2;
    }
    if (D_80153500[slot] == 0) {
        *score = D_800E2854[slot].free / 256;
    } else {
        *score = 0;
    }
    return D_80153500[slot];
}

s32 Pak_RepairIdIfNeeded(s32 channel) {
    s32 channelOffset;
    s32 result;
    channelOffset = channel * 4;
    if (D_801534F0[channel] != 3) {
        return -2;
    }
    ((void (*)(s32))Control_AcquireControllerLock)(1);
    Control_ReadControllerStates();
    result = D_80153500[channel];
    D_8010BBB8 = 2;
    if (result == -4) {
        result = func_80447F30_de(&D_8014D280[channel]);
        if (result != 0) {
            result = -1;
        }
        Pak_UpdateStatus(channel);
    }
    Control_ReleasePakLock();
    return result;
}

s32 Pak_RepairId(s32 channel) {
    s32 result;
    if (D_801534F0[channel] != 3) {
        return -2;
    }
    ((void (*)(s32))Control_AcquireControllerLock)(1);
    Control_ReadControllerStates();
    D_8010BBB8 = 2;
    result = func_80447F30_de(&D_8014D280[channel]);
    if (result != 0) {
        result = -1;
    }
    Pak_UpdateStatus(channel);
    Control_ReleasePakLock();
    return result;
}

s32 Pak_GetNoteGameName(s32 index, s32 entry, char **out) {
    if (D_801534F0[index] != 3) {
        return -2;
    }
    *out = D_800E2854[index].notes[entry].game_name;
    return 0;
}

s32 Pak_GetNoteExtension(s32 index, s32 entry, char **out) {
    if (D_801534F0[index] != 3) {
        return -2;
    }
    *out = D_800E2854[index].notes[entry].ext_name;
    return 0;
}

s32 Pak_GetNotePageCount(s32 index, s32 entry, s32 *out) {
    if (D_801534F0[index] != 3) {
        return -2;
    }
    *out = Pak_BytesToPakPages(D_800E2854[index].notes[entry].file_size);
    return 0;
}
