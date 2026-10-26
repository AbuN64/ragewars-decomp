#include "include_asm.h"
#include "COMMON/EXTERNS_15.H"
#include "TYPES.H"
#include "IO/EXTERNS.H"
#include "IO/80200568.H"
#include "IO/80200800.H"
#include "IO/io_hostmemory.H"

void Libsn_FillPortBytes(s32 address, s32 value, u32 count)
{
  u32 new_var;
  u32 byte;
  unsigned char new_var2;
  u32 word;
  new_var2 = value & 0xFF;
  while ((count != 0) && ((address & 3) != 0))
  {
    Libsn_WritePortByte(address++, new_var2);
    count--;
  }

  if (count >= 4)
  {
    byte = new_var2;
    new_var = byte;
    word = (((byte << 24) | (byte << 16)) | (new_var << 8)) | new_var;
    do
    {
      Libsn_WritePortWord(address, word);
      count -= 4;
      address += 4;
    }
    while (count >= 4);
  }
  while (count)
  {
    Libsn_WritePortByte(address++, new_var2);
    count--;
  }

}

void Libsn_CopyPortBytes(s32 address, s32 port, s32 count) {
    s32 remaining, source, value;
    source = port;
    remaining = count - 1;
    if (count != 0) {
        do {
            value = Libsn_ReadPortByte(source++);
            Libsn_WritePortByte(address++, value & 0xFF);
            remaining--;
        } while (remaining != -1);
    }
}

#include "IO/DEBUG_MEMORY.H"
extern void Libsn_EnumerateMemoryRanges(void);
extern u8 D_8F0F3130[];
extern void Libsn_FillPortBytes(s32, s32, u32);
extern void Libsn_CopyPortBytes(s32, s32, s32);
extern void Libsn_WritePortBuffer(u32, u32, u32);
extern void Libsn_ReadPortBuffer(u32, u32, u32);
extern void Libsn_CopyPortToWordMemory(u32, u32, u32);

/* Split the debugger's memory transfer at permission boundaries. */
void Libsn_TransferHostMemoryRanges(u32 mode) {
    u32 address, remaining, chunk, flags, port;
    u32 i;
    Libsn_EnumerateMemoryRanges();
    port = 0xB1FE0000;
    address = Libsn_ReadPortWord(0xB1FFFFF4);
    remaining = Libsn_ReadPortWord(0xB1FFFFF8);
    if (address > 0xEFFFFFFF) address += (u32)D_8F0F3130;
    while (remaining != 0) {
        i = 0;
        while (address < D_800F2D00[i].first || address > D_800F2D00[i].last) i++;
        if (i >= 48) {
            flags = 0;
            chunk = 0x1000 - (address & 0xFFF);
        } else {
            flags = D_800F2D00[i].flags;
            chunk = (D_800F2D00[i].last + 1) - address;
        }
        if (remaining < chunk) chunk = remaining;
        if ((flags & mode) == 0) {
            if (mode == 1) Libsn_FillPortBytes(port, 0, chunk);
        } else if (flags & 4) {
            if (mode == 1) Libsn_CopyPortBytes(port, address, chunk);
            else Libsn_CopyPortBytes(address, port, chunk);
        } else if (mode == 1) {
            Libsn_WritePortBuffer(port, address, chunk);
        } else if (flags & 8) {
            Libsn_CopyPortToWordMemory(port, address, chunk);
        } else {
            Libsn_ReadPortBuffer(port, address, chunk);
        }
        port += chunk;
        address += chunk;
        remaining -= chunk;
    }
}

extern s32 Libsn_ReadPortWord(s32 address);

/* Copy the block the debugger host announced (address at 0xB1FFFFF4, byte size at 0xB1FFFFF8) from its
 * 0xB1xxxxxx window onto the matching 0xB0xxxxxx address one word at a time, once the host signals ready at
 * 0xB0000010; the word index doubles as the ready poll result. */
void Libsn_CopyHostBlockToCart(void) {
    u32 address;
    u32 size;
    u32 index;

    address = Libsn_ReadPortWord(0xB1FFFFF4) & 0xB1FFFFFC;
    size = Libsn_ReadPortWord(0xB1FFFFF8) & 0x01FFFFFC;
    Libsn_WritePortWord(0xB1FFFFFC, 0);
    while ((index = Libsn_ReadPortWord(0xB0000010)) == 0) {
        Libsn_SpinDelay(500);
    }
    index = 0;
    if (size >> 2 != 0) {
        do {
            Libsn_WritePortWord((address & 0xB07FFFFF) + index * 4, Libsn_ReadPortWord(address + index * 4));
        } while (++index < size >> 2);
    }
    Libsn_SpinDelay(2000);
    Libsn_WritePortWord(0xB1FFFFF4, 0);
}
