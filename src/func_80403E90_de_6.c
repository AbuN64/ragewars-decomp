#include "span_16E000/code_80403BCC.h"
#include "common/types_1dc8418c21db.h"
#include "stddef.h"
#include "types.h"

/* Loads a page-aligned resource into the selected device slot and reports the result. */






extern s8 D_8010BBB8;

extern char D_800DCCD0[];

extern s32 *func_8025343C_de(s32, s32, s32, void *);

extern void func_80253838_de(void *arg0, void *arg1);

extern void func_80253908_de(s32);

extern void func_8025476C_de(s32);

extern s32 func_8025477C_de(void);

extern void func_80263740_de(void);

extern void func_8026454C_de(void);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern s32 func_80447AF0_de(Device *, s32, s32, s32, s32, s32);

/* For a player slot whose state D_801534F0 is 3, writes its score (the first word of its 0x204-byte
   record in D_800E2854 divided by 256, or 0 when the flag D_80153500 is set) and returns the flag;
   other states return -2. */




/* Refreshes a controller slot and resolves its pending device state. */
void func_80263740_de();

 /* extern */
 /* extern */
void func_8026454C_de();

 /* extern */
void func_80404018_de(s32);

 /* extern */
s32 func_80447F30_de(void *);

/* Reports the address of the field at offset 0xE of entry j in record i of the table D_800E2854
   points to, returning zero, or returns -2 when record i's state in D_801534F0 is not 3. */







/* Reports the address of the field at offset 0xA of entry j in record i of the table D_800E2854
   points to, returning zero, or returns -2 when record i's state in D_801534F0 is not 3. */







/* Reports through the third argument the size in 256-byte units, per func_804057EC_de, of entry j of
   record i in the table D_800E2854 points to, returning zero, or returns -2 when record i's state in
   D_801534F0 is not 3. */







extern s32 func_804057EC_de(s32);

s32 func_80404F58_de(s32 slot, s32 arg1, s32 arg2, s32 length)
{
    extern Device D_8014D280[];
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
  buf = func_8025343C_de(0, size, 0x23, D_800DCCD0);
  addr = *buf;
  ((void (*)(s32))func_802644FC_de)(1);
  func_80263740_de();
  result = D_80153500[slot];
  D_8010BBB8 = 2;
  if (result == 0)
  {
    result = func_80447AF0_de(&D_8014D280[slot], arg1, zero, zero, size, addr);
    if (result != zero)
    {
      result = -1;
    }
    if (result == 0)
    {
      func_802BD3A0_de(arg2, addr, length);
    }
  }
  func_8026454C_de();
  func_80253908_de(zero);
  if (buf != ((void *) 0))
  {
    func_80253838_de(0, buf);
  }
  return result;
}

/* Counts empty Controller Pak note slots on channel ch when the pak is ready and returns its error status, or -2 when not ready. */
s32 func_804050CC_de(s32 ch, s32 *count) {
    extern PakDirectoryRecAt4 *D_800E2854;
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

int func_80405160_de(int slot, int *score) {
    extern int *D_800E2854;
    if (D_801534F0[slot] != 3) {
        return -2;
    }
    if (D_80153500[slot] == 0) {
        *score = D_800E2854[slot * 0x81] / 256;
    } else {
        *score = 0;
    }
    return D_80153500[slot];
}

s32 func_804051D4_de(s32 arg0) {
    extern char D_8014D280[];
    s32 temp_s0;
    s32 var_s0;
    temp_s0 = arg0 * 4;
    if (D_801534F0[arg0] != 3) {
        return -2;
    }
    ((void (*)(s32))func_802644FC_de)(1);
    func_80263740_de();
    var_s0 = D_80153500[arg0];
    D_8010BBB8 = 2;
    if (var_s0 == -4) {
        var_s0 = func_80447F30_de((arg0 * 0x68) + D_8014D280);
        if (var_s0 != 0) {
            var_s0 = -1;
        }
        func_80404018_de(arg0);
    }
    func_8026454C_de();
    return var_s0;
}

s32 func_80405290_de(s32 arg0) {
    extern char D_8014D280[];
    s32 var_s0;
    if (D_801534F0[arg0] != 3) {
        return -2;
    }
    ((void (*)(s32))func_802644FC_de)(1);
    func_80263740_de();
    D_8010BBB8 = 2;
    var_s0 = func_80447F30_de((arg0 * 0x68) + D_8014D280);
    if (var_s0 != 0) {
        var_s0 = -1;
    }
    func_80404018_de(arg0);
    func_8026454C_de();
    return var_s0;
}

s32 func_80405338_de(s32 index, s32 entry, char **out) {
    extern struct RecordRecAt4V1 *D_800E2854;
    if (D_801534F0[index] != 3) {
        return -2;
    }
    *out = D_800E2854[index].entries[entry].data + 0xE;
    return 0;
}

s32 func_8040538C_de(s32 index, s32 entry, char **out) {
    extern struct RecordRecAt4V1 *D_800E2854;
    if (D_801534F0[index] != 3) {
        return -2;
    }
    *out = D_800E2854[index].entries[entry].data + 0xA;
    return 0;
}

s32 func_804053E0_de(s32 index, s32 entry, s32 *out) {
    extern struct RecordRecAt4V2 *D_800E2854;
    if (D_801534F0[index] != 3) {
        return -2;
    }
    *out = func_804057EC_de(D_800E2854[index].entries[entry].size);
    return 0;
}
