#include "COMMON/ITEMRECAT20V1.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_61.H"

/* When slot i of the 12-byte records at offset 0x2DF8 of the table D_800E54A4 points to is set,
   passes the 400-byte record i of D_80102B00 to Player_InitializeProfile, marks the slot done with 2 and calls
   func_80433BCC_de with -1. */






extern struct PlayerRecord D_80102B00[];
extern void Player_InitializeProfile(struct PlayerRecord *);
extern void PAKInterface_RelabelSlotRows(s32);

void Frontend_ResetLinkedLocalProfile(s32 index) {
    if (D_800E54A4->links[index].state == 1) {
        Player_InitializeProfile(&D_80102B00[index]);
        D_800E54A4->links[index].state = 2;
        PAKInterface_RelabelSlotRows(-1);
    }
}
