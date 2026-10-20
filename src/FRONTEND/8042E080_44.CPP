#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_44.H"

/* Marks entry i of the 150-byte records D_80146410 and sets the words at offsets 0x6C and 0x58
   of entry i of the 2920-byte records D_800E54A4 points to to 2. */


extern u8 D_80146410[];
extern struct EntryRecAt6C *D_800E54A4;

void func_804350CC_de(s32 index) {
    struct EntryRecAt6C *entry;

    D_80146410[index * 150] = 1;
    entry = &D_800E54A4[index];
    entry->second = 2;
    entry->first = 2;
}
