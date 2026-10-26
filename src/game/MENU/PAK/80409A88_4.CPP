#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECORDRECATCV1.H"
#include "TYPES.H"
#include "COMMON/PAK_MENU.H"
#include "COMMON/MENURECAT24.H"

/* Latches D_80153784 to one when the record's team value (D_800E28C8 when D_8015375C is set, otherwise the signed byte at offset 4 of the object at 0x20) is not -1 and both func_802645D0_de and Pak_CheckStatusPrompt accept it, then returns D_80153784. */




extern s32 D_8015375C;
extern s32 Pak_CheckStatusPrompt(struct Shared_PakMenu *, s32, s32);

static inline s32 Pak_GetMenuChannel(struct Shared_PakMenu *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->owner->unk4;
}

s32 Pak_CheckMenuPakChange(struct Shared_PakMenu *record) {
    if (D_80153784 == 0) {
        if (Pak_GetMenuChannel(record) != -1) {
            if (Control_PeekPakChange(Pak_GetMenuChannel(record)) != 0) {
                if (Pak_CheckStatusPrompt(record, Pak_GetMenuChannel(record), 0) != 0) {
                    D_80153784 = 1;
                }
            }
        }
    }
    return D_80153784;
}
