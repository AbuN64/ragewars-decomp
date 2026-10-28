#include "TYPES.H"
#include "COMMON/EXTERNS_15.H"
#include "IO/80200800.H"
#include "include_asm.h"
#include "sdk/os.h"

int Libsn_ReadPortByte(int arg0) {
    u32 shift = (~arg0 & 3) << 3;
    u32 word = Libsn_ReadPortWord(arg0 & ~3);

    return (word >> shift) & 0xFF;
}

/* Signature follows the published cartridge word reader implementation. */


int Libsn_ReadTransferPortByte(int arg0) {
    int shift = (~arg0 & 3) << 3;
    return ((u32)Libsn_ReadPortWord(arg0 & -4) >> shift) & 0xFF;
}



void Libsn_ReadPortBuffer(s32 source, u8 *destination, u32 count) {
    while (count != 0 && (source & 3) != 0) {
        *destination++ = Libsn_ReadPortByte(source++);
        count--;
    }
    while (count >= 4) {
        u32 word = Libsn_ReadPortWord(source);
        *destination++ = word >> 24;
        *destination++ = word >> 16;
        *destination++ = word >> 8;
        *destination++ = word;
        source += 4;
        count -= 4;
    }
    while (count != 0) {
        *destination++ = Libsn_ReadPortByte(source++);
        count--;
    }
}

extern s32 D_800C8140_de;
extern u8 D_800F2CE0[],D_800F2CC0[];

struct OSIoMesg;
struct Opaque_OSMesgQueue;
extern s32 Io_StartPeripheralDma(struct OSIoMesg *,s32,s32,u32,void *,u32,struct Opaque_OSMesgQueue *);
void Libsn_ReadPortBufferWithDma(u32 address,u8 *out,u32 count) {
 s32 status = -(D_800C8140_de == 0); u32 word;
 while(count!=0 && (address&3)!=0) { *out++=Libsn_ReadTransferPortByte(address++); count--; }
 while(count>3) {
  if(count>=16 && ((((u32)out&15)==0) & (status!=-1))) {
   status=Io_StartPeripheralDma(D_800F2CE0,1,0,address,out,count,D_800F2CC0);
   if(status!=-1) { osRecvMesg(D_800F2CC0,0,1); count=0; }
  } else {
   word=Libsn_ReadPortWord(address);
   *out++=word>>24; *out++=word>>16; *out++=word>>8; *out++=word;
   address+=4; count-=4;
  }
 }
 while(count!=0) { *out++=Libsn_ReadTransferPortByte(address++); count--; }
}
