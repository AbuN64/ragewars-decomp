#include "include_asm.h"
#include "COMMON/EXTERNS_15.H"
#include "TYPES.H"
#include "IO/EXTERNS.H"
#include "IO/80200568.H"
#include "IO/80200800.H"
#include "IO/io_hostmemory.H"

void func_80200F98_de(s32 address, s32 value, u32 count)
{
  u32 new_var;
  u32 byte;
  unsigned char new_var2;
  u32 word;
  new_var2 = value & 0xFF;
  while ((count != 0) && ((address & 3) != 0))
  {
    func_80200C28_de(address++, new_var2);
    count--;
  }

  if (count >= 4)
  {
    byte = new_var2;
    new_var = byte;
    word = (((byte << 24) | (byte << 16)) | (new_var << 8)) | new_var;
    do
    {
      func_80200568_de(address, word);
      count -= 4;
      address += 4;
    }
    while (count >= 4);
  }
  while (count)
  {
    func_80200C28_de(address++, new_var2);
    count--;
  }

}

void func_80201064_de(s32 address, s32 port, s32 count) {
    s32 remaining, source, value;
    source = port;
    remaining = count - 1;
    if (count != 0) {
        do {
            value = func_80200800_de(source++);
            func_80200C28_de(address++, value & 0xFF);
            remaining--;
        } while (remaining != -1);
    }
}

#ifdef NON_MATCHING
#include "IO/DEBUG_MEMORY.H"
extern void func_80200610_de(void);
extern u8 D_8F0F3130[];
extern void func_80200F98_de(s32, s32, u32);
extern void func_80201064_de(s32, s32, s32);
extern void func_80200D18_de(u32, u32, u32);
extern void func_80200880_de(u32, u32, u32);
extern void func_80200B14_de(u32, u32, u32);

/* Split the debugger's memory transfer at permission boundaries. */
void func_802010D8_de(u32 mode) {
    u32 address, remaining, chunk, flags, port = 0xB1FE0000;
    s32 i;
    func_80200610_de();
    address = func_802005A0_de(0xB1FFFFF4);
    remaining = func_802005A0_de(0xB1FFFFF8);
    if (address > 0xEFFFFFFF) address += (u32)D_8F0F3130;
    while (remaining != 0) {
        for (i = 0; i < 48; i++) {
            if (address >= D_800F2D00[i].first && address <= D_800F2D00[i].last) break;
        }
        if (i < 48) {
            flags = D_800F2D00[i].flags;
            chunk = D_800F2D00[i].last - address + 1;
        } else {
            flags = 0;
            chunk = 0x1000 - (address & 0xFFF);
        }
        if (remaining < chunk) chunk = remaining;
        if ((flags & mode) == 0) {
            if (mode == 1) func_80200F98_de(port, 0, chunk);
        } else if (flags & 4) {
            if (mode == 1) func_80201064_de(port, address, chunk);
            else func_80201064_de(address, port, chunk);
        } else if (mode == 1) {
            func_80200D18_de(port, address, chunk);
        } else if (flags & 8) {
            func_80200B14_de(port, address, chunk);
        } else {
            func_80200880_de(port, address, chunk);
        }
        port += chunk;
        address += chunk;
        remaining -= chunk;
    }
}
#else
INCLUDE_ASM("span_1000", func_802010D8_de);
#endif

extern s32 func_802005A0_de(s32 address);

/* Copy the block the debugger host announced (address at 0xB1FFFFF4, byte size at 0xB1FFFFF8) from its
 * 0xB1xxxxxx window onto the matching 0xB0xxxxxx address one word at a time, once the host signals ready at
 * 0xB0000010; the word index doubles as the ready poll result. */
void Io_CopyHostBlockToCart(void) {
    u32 address;
    u32 size;
    u32 index;

    address = func_802005A0_de(0xB1FFFFF4) & 0xB1FFFFFC;
    size = func_802005A0_de(0xB1FFFFF8) & 0x01FFFFFC;
    func_80200568_de(0xB1FFFFFC, 0);
    while ((index = func_802005A0_de(0xB0000010)) == 0) {
        func_802005DC_de(500);
    }
    index = 0;
    if (size >> 2 != 0) {
        do {
            func_80200568_de((address & 0xB07FFFFF) + index * 4, func_802005A0_de(address + index * 4));
        } while (++index < size >> 2);
    }
    func_802005DC_de(2000);
    func_80200568_de(0xB1FFFFF4, 0);
}
