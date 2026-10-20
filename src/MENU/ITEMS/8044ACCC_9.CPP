#include "include_asm.h"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJB.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"

/* Initializes camera transforms, viewport state, clipping records, and resource lists. */

 
void func_80238EB8_de(void *);                               /* extern */
void func_802390F4_de(void *, s32);                         /* extern */
void func_802393D8_de(void *);                            /* extern */
void func_80239C20_de(void *);                            /* extern */
void func_802727D8_de(void *);                            /* extern */
void func_80442544_de(void *);                    /* extern */


extern s32 D_800E28D0, D_800E28D4;
extern struct IntPair D_80103220;






/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x20, 0x24], gap at: 0x18. */
void func_8044A170_de(State_func_8044A170_de *arg0) {
    f32 temp_f21;
    f32 zero;
    s16 temp_a0;
    s32 var_a1;
    Floats *temp_v0;
    Floats *temp_v0_2;
    Floats *temp_v0_3;
    Floats *temp_v0_4;
    Floats *temp_v0_5;

    func_80238EB8_de(((void *)&((GameplayCamera *)arg0)->unk24));
    func_802727D8_de(((void *)&((GameplayCamera *)arg0)->unk160));
    func_802727D8_de(((void *)&((GameplayCamera *)arg0)->unk1E0));
    zero = 0.0f;
    temp_f21 = 1.0f;
    temp_v0 = ((void *)&((GameplayCamera *)arg0)->orientation);
    temp_v0->unk8 = zero;
    temp_v0->unk4 = zero;
    arg0->unk140 = zero;
    arg0->unk14C = temp_f21;
    func_802727D8_de(((void *)&((GameplayCamera *)arg0)->unk1A0));
    arg0->unk29C = (f32) D_800E28D0;
    arg0->unk2A0 = (f32) D_800E28D4;
    arg0->unk518 = -1;
    arg0->unk2A4 = zero;
    arg0->unk2A8 = zero;
    arg0->unk520 = 0;
    arg0->unk524 = 0;
    arg0->unk521 = 0;
    arg0->unk525 = 0;
    arg0->unk522 = 0;
    arg0->unk526 = 0;
    arg0->unk523 = 0;
    arg0->unk527 = 0;
    arg0->unk51C = temp_f21;
    arg0->unk53C = 0x3E3;
    arg0->unk540 = 0x3E3;
    arg0->unk548 = 0;
    arg0->unk7C = 0;
    arg0->unkC = temp_f21;
    arg0->unk10 = temp_f21;
    arg0->unk528 = (f32) 1024.0f;
    arg0->unk52C = (f32) 1024.0f;
    arg0->unk530 = (f32) 47.5f;
    arg0->unk534 = (f32) 47.5f;
    func_802393D8_de(arg0);
    temp_v0_2 = ((void *)&((GameplayCamera *)arg0)->padA0);
    arg0->unkF4 = zero;
    arg0->unkF8 = zero;
    temp_v0_2->unk8 = zero;
    temp_v0_2->unkC = zero;
    temp_v0_2->unk10 = zero;
    temp_v0_2->unk14 = temp_f21;
    temp_v0_3 = ((void *)&((GameplayCamera *)arg0)->unkB8);
    temp_v0_3->unk4 = zero;
    temp_v0_3->unk8 = zero;
    temp_v0_3->unkC = zero;
    temp_v0_3->unk10 = zero;
    temp_v0_4 = ((void *)&((GameplayCamera *)arg0)->unkCC);
    temp_v0_4->unk4 = zero;
    temp_v0_4->unk8 = zero;
    temp_v0_4->unkC = zero;
    temp_v0_4->unk10 = zero;
    temp_v0_5 = ((void *)&((GameplayCamera *)arg0)->unkE0);
    temp_v0_5->unk4 = zero;
    temp_v0_5->unk8 = zero;
    temp_v0_5->unkC = zero;
    temp_v0_5->unk10 = zero;
    func_802390F4_de(arg0, 0);
    temp_a0 = D_800E28D0 * 2;
    for (var_a1 = 0; var_a1 < 2; var_a1++) {
        ((Racer *)arg0)->viewports[var_a1].vscale[0] = temp_a0;
        ((Racer *)arg0)->viewports[var_a1].vscale[1] = temp_a0;
        ((Racer *)arg0)->viewports[var_a1].vscale[2] = 0x3FF;
        ((Racer *)arg0)->viewports[var_a1].vscale[3] = 0;
        ((Racer *)arg0)->viewports[var_a1].vtrans[0] = temp_a0;
        ((Racer *)arg0)->viewports[var_a1].vtrans[1] = temp_a0;
        ((Racer *)arg0)->viewports[var_a1].vtrans[2] = 0;
        ((Racer *)arg0)->viewports[var_a1].vtrans[3] = 0;
    }
    func_80442544_de(((void *)&((GameplayCamera *)arg0)->messageList));
    func_802727D8_de(((void *)&((GameplayCamera *)arg0)->unkE54));
    func_802727D8_de(((void *)&((GameplayCamera *)arg0)->unkE94));
    arg0->unk544 = 0;
    arg0->unk120 = 0;
    arg0->unk124 = 0x32;
    arg0->unk126 = 0;
    D_80103220.field_4 = 0;
    func_80255CA0_de(&((GameplayCamera *)arg0)->objects, 0, 4);
    func_80239C20_de(arg0);
}

#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct DraftListA370 { void *head, *tail; s32 count, a, b; } DraftListA370;
typedef struct DraftEntryA370 { void *next, *prev; s32 a, b, c; f32 value; DraftListA370 lists[3]; } DraftEntryA370;
typedef struct DraftActorA370 { void *next, *prev; s32 index; u8 rest[0xECC]; } DraftActorA370;
typedef struct DraftSmallA370 { u8 data[0x40]; } DraftSmallA370;
typedef struct DraftOwnerA370 {
    DraftActorA370 **handle, *actors; s32 count;
    DraftListA370 active, free;
    s32 word34, word38, word3C;
    u8 parts[8]; s32 word48; u8 rest[0xF18 - 0x4C];
    DraftSmallA370 **smallHandle, *small; s32 smallCount;
    DraftListA370 smallList;
    DraftEntryA370 entries[8];
    DraftListA370 entryList, spareList;
    s32 empty;
} DraftOwnerA370;
extern f32 D_800C32EC_de;
extern char D_800C32D4_de[], D_800C32DC_de[];
extern void func_8025E3F0_de(void *);
extern void func_80253908_de(s32), func_80253838_de(s32, void *);
extern void *func_8025343C_de(s32, s32, s32, char *);
void func_8044A370_de(DraftOwnerA370 *owner, s32 count)
{
    s32 i;
    f32 value;
    DraftEntryA370 *entry;
    if (count > 4) count = 4;
    owner->word34 = 0;
    owner->word38 = 0;
    owner->word48 = 0;
    func_8044A170_de(owner->parts);
    owner->word38 = 2;
    func_80255CA0_de(&owner->entryList, 0, 4);
    func_80255CA0_de(&owner->spareList, 0, 4);
    value = D_800C32EC_de;
    for (i = 0; i < 8; i++) {
        entry = &owner->entries[i];
        entry->a = entry->b = entry->c = 0;
        entry->value = value;
        entry->lists[0].tail = 0;
        entry->lists[0].count = entry->lists[0].a = entry->lists[0].b = 0;
        entry->lists[1].tail = 0;
        entry->lists[1].count = entry->lists[1].a = entry->lists[1].b = 0;
        entry->lists[2].tail = 0;
        entry->lists[2].count = entry->lists[2].a = entry->lists[2].b = 0;
        func_80255D14_de(&owner->entryList, entry);
    }
    func_80255CA0_de(&owner->active, 0, 4);
    func_80255CA0_de(&owner->free, 0, 4);
    func_80255CA0_de(&owner->smallList, 0, 4);
    owner->empty = 1;
    func_8025E3F0_de(owner->parts);
    func_80253908_de(0);
    if (owner->handle) {
        func_80253838_de(0, owner->handle);
        owner->handle = 0; owner->actors = 0; owner->count = 0;
    }
    func_80253908_de(0);
    if (owner->smallHandle) {
        func_80253838_de(0, owner->smallHandle);
        owner->smallHandle = 0; owner->small = 0; owner->smallCount = 0;
    }
    if (count) {
        owner->count = count;
        owner->handle = func_8025343C_de(0, count * 0xED8, 0x23, D_800C32D4_de);
        owner->actors = *owner->handle;
        func_802A001C_de(owner->actors, 0, count * 0xED8);
        for (i = 0; i < owner->count; i++) {
            owner->actors[i].index = i;
            func_80255D14_de(&owner->active, &owner->actors[i]);
        }
        func_8025E3F0_de(owner->actors);
        owner->empty = 0;
    }
    owner->smallCount = 16;
    owner->smallHandle = func_8025343C_de(0, 0x400, 0x23, D_800C32DC_de);
    owner->small = *owner->smallHandle;
    func_802A001C_de(owner->small, 0, 0x400);
    for (i = 0; i < owner->smallCount; i++) {
        func_80255D14_de(&owner->smallList, &owner->small[i]);
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8044A370_de);
#endif
