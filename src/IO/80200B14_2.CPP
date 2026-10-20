#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "IO/EXTERNS.H"
#include "TYPES.H"
#include "IO/80200568.H"
#include "sdk/os.h"

void func_80200CA0_de(s32 arg0, unsigned char arg1)
{
  int new_var;
  s32 temp_s2;
  new_var = ((~arg0) & 3) * 8;
  arg0 = arg0 & (~3);
  temp_s2 = new_var;
  func_80200568_de(arg0, (func_802005A0_de(arg0) & (~(0xFF << temp_s2))) | (new_var = (arg1 & 0xFF) << temp_s2));
}

#ifdef NON_MATCHING
#include "COMMON/EXTERNS_15.H"
#include "TYPES.H"

extern void func_80200C28_de(s32 address, s32 value);
extern void func_80200568_de(s32 address, s32 value);

/* Copy an arbitrary byte buffer to a PI range, packing big-endian words. */
void func_80200D18_de(s32 address, const u8 *source, u32 length)
{
  u32 word;
  while ((length != 0) && ((address & 3) != 0))
  {
    func_80200C28_de(address++, *(source++));
 do { } while (0);
    length--;
  }

  if (length >= 4)
  {
    do
    {
      word = (((((u32) source[0]) << 24) | (((u32) source[1]) << 16)) | (((u32) source[2]) << 8)) | source[3];
      func_80200568_de(address, word);
      address += 4;
      source += 4;
      length -= 4;
    }
    while (length >= 4);
  }
  while (length != 0)
  {
    func_80200C28_de(address++, *(source++));
    length--;
  }

}
#else
INCLUDE_ASM("span_1000", func_80200D18_de);
#endif

#ifdef NON_MATCHING
#include "IO/EXTERNS.H"
#include "COMMON/EXTERNS_18.H"
extern s32 D_800C8140_de;
struct OSIoMesg;
extern struct OSIoMesg D_800F2CE0;
extern OSMesgQueue D_800F2CC0;
extern void func_80200CA0_de(s32, u8);
extern s32 func_802B8CF0_de(struct OSIoMesg *, s32, s32, u32, void *, u32, OSMesgQueue *);

/* Write an arbitrary byte stream to the device, using DMA when aligned
 * and falling back to byte/word writes if the DMA request is unavailable. */
void func_80200E04_de(u32 address, u8 *source, u32 remaining) {
    s32 dmaResult = -(D_800C8140_de == 0);
    while (remaining != 0 && (address & 3) != 0) {
        func_80200CA0_de(address++, *source++);
        remaining--;
    }
    while (remaining >= 4) {
        if (remaining < 16 || ((u32)source & 15) != 0 || dmaResult == -1) {
            func_80200568_de(address, ((u32)source[0] << 24) |
                ((u32)source[1] << 16) | ((u32)source[2] << 8) | source[3]);
            address += 4;
            source += 4;
            remaining -= 4;
        } else {
            dmaResult = func_802B8CF0_de(&D_800F2CE0, 1, 1, address,
                source, remaining, &D_800F2CC0);
            if (dmaResult != -1) {
                func_802BB2A0_de(&D_800F2CC0, 0, 1);
                remaining = 0;
            }
        }
    }
    while (remaining != 0) {
        func_80200CA0_de(address++, *source++);
        remaining--;
    }
}
#else
INCLUDE_ASM("span_1000", func_80200E04_de);
#endif
