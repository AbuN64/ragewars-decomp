#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECORDRECATCV1.H"
#include "TYPES.H"
#include "COMMON/MENURECAT24.H"

/* Returns D_800E28C8 when D_8015375C is set, otherwise the signed byte at offset 4 of the object
   at offset 0x20 of a record. */




extern s32 D_8015375C;

s32 Pak_GetMenuChannel(struct Shared_PakMenu *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->owner->unk4;
}
