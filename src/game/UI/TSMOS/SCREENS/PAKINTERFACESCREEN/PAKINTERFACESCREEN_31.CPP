#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_44.H"

/* Marks entry i of the 150-byte records D_80146410 and sets the words at offsets 0x6C and 0x58
   of entry i of the 2920-byte records D_800E54A4 points to to 2. */



void PAKInterface_EnablePlayerPanel(s32 index) {
    struct EntryRecAt6C *entry;

    D_801462C8.playerSettings[index].enabled = 1;
    entry = (struct EntryRecAt6C *)((char *)D_800E54A4 + index * 0xB68);
    entry->second = 2;
    entry->first = 2;
}
