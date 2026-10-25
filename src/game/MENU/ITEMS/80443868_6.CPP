#include "COMMON/ACTORRECAT260.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_13.H"
#include "TYPES.H"
#include "sdk/PFS/80443868_6.H"
#include "SYSTEM_3/80265370.H"

/* Sets bit 24 of the flag word at offset 0x120 of the object at offset 0xC of a record when
   D_801468F4 is set, and clears it otherwise. */






/* Marks the attached actor visible, clears its subpart visibility bits, and applies the paused-state flag. */





s32 func_80443B3C_de(Shared_DebugWidget *field, Shared_MenuHandle *holder) {
    s32 player = Weapons_GetPlayerIndex(&D_80145040, holder->owner);
    /* D_80146398 is the hub's func_8041F2A0_Config array (0x96-byte records); index player*150 then reads the record's first halfword */
    s32 value = *(s16 *) &D_80146398[player];
    char *text;

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    text = field->inner->text[D_80145040.object.language];
    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EED80, value);
#else
    text = *field->inner->text;
    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800DE700, value);
#endif
    return 0;
}

/* Does nothing. Nothing in the cartridge image calls it or stores its address as a word. */
extern s32 D_801468F4[];
void func_80443BCC_de(void) {
}

void func_80443BD4_de(struct RecordRecAtCV3 *record) {
    if (D_801468F4[0] != 0) {
        record->target->flags |= 0x01000000;
    } else {
        record->target->flags &= ~0x01000000;
    }
}

void func_80443C14_de(ObjectRecAt1C *object) {
 if(object->parent) object->parent->unk85C=1;
 object->actor->flags1c0 |= 0x01800000;
 object->actor->flags1c0 &= 0xFEFFFFFF;
 object->actor->flags58 |= 0x01800000;
 object->actor->flags210 &= 0xFE7FFFFF;
 object->actor->flags238 &= 0xFE7FFFFF;
 object->actor->flags260 &= 0xFE7FFFFF;
 if(D_801468F4[0]) {object->actor->flags120 |= 0x01000000; return;}
 object->actor->flags120 &= 0xFEFFFFFF;
}
