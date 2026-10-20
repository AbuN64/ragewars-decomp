#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"

extern NameEntryMenu *D_800E54A4;
extern void *func_8041B7FC_de(s32, s32);

/* Advances the selected name character, wrapping past Z to a space. */
void func_80434E34_de(s32 arg0) {
    u8 value;

    D_800E54A4->flags[arg0] = 0;
    func_8041B7FC_de(D_800E54A4->unk4, arg0);
    if (D_800E54A4->entries[arg0].name[D_800E54A4->entries[arg0].cursor].available == 0) {
        D_800E54A4->entries[arg0].name[D_800E54A4->entries[arg0].cursor].available = 0x41;
    }
    value = D_800E54A4->entries[arg0].name[D_800E54A4->entries[arg0].cursor].available;
    value++;
    if (value >= 0x5B) {
        value = 0x20;
    }
    D_800E54A4->entries[arg0].name[D_800E54A4->entries[arg0].cursor].available = value;
}
