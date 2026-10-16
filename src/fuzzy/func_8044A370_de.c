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
extern void func_8044A170_de(void *), func_8025E3F0_de(void *);
extern void func_80255CA0_de(void *, s32, s32), func_80255D14_de(void *, void *);
extern void func_80253908_de(s32), func_80253838_de(s32, void *);
extern void *func_8025343C_de(s32, s32, s32, char *);
extern void func_802A001C_de(void *, s32, s32);
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
