#include "COMMON/LEVEL.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_10.H"
#include "COMMON/PPDECOM_UNPACKRESOURCE.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "OVLGAME/SCENE_DISPATCHANDRECYCLEQUEUEDTRIGGERS.H"
#include "SYSTEM/LIST.H"
#include "SYSTEM/LIST.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "ENGINE/SCENE_LOADLEVELRESOURCES.H"

/* Spawns the pickups of a level: between Cinema_ClearPlaybackFlag and Cinema_SetPlaybackFlag it passes every item of both item tables whose kind is 1, 2, 4 or 10 to Scene_DispatchEnabledEntityTrigger. */







extern s32 Scene_GetIndexedModelResource(s32, s32);

void Scene_DispatchSelectedEntityKinds(Level *level) {
    s32 i;
    s32 n;
    ItemOvlSceneDispatchSelectedEntityKinds *item;

    Cinema_ClearPlaybackFlag();
    n = level->counts[0];
    for (i = 0; i < n; i++) {
        item = &level->items[0][i];
        if (item->kind == 1 || item->kind == 4 || item->kind == 2 || item->kind == 10) {
            Scene_DispatchEnabledEntityTrigger(level, item);
        }
    }
    n = level->counts[1];
    for (i = 0; i < n; i++) {
        item = &level->items[1][i];
        if (item->kind == 1 || item->kind == 4 || item->kind == 2 || item->kind == 10) {
            Scene_DispatchEnabledEntityTrigger(level, item);
        }
    }
    Cinema_SetPlaybackFlag();
}

void Scene_DispatchAndRecycleQueuedTriggers(OwnerCode8044E2B8 *arg0) {
    EntryOvlSceneDispatchAndRecycleQueuedTriggers *entry;
    EntryOvlSceneDispatchAndRecycleQueuedTriggers *next;

    entry = arg0->active;
    while (entry != 0) {
        next = entry->next;
        Link_DispatchTrigger(entry->handle);
        func_80255ED8_de(&arg0->active, entry);
        func_80255CB8_de(&arg0->spare, entry);
        entry = next;
    }
}

void Scene_RelocateParticleEffectData(s32 arg0, void ***arg1) {
    void *obj;
    GroupCode8044E2B8 *group;
    Piece *piece;
    s32 base;
    s32 count;
    s32 i;

    if (Ppdecom_UnpackResource(arg1, 0) != 0) {
        obj = **arg1;
        group = SetN64_GetPackSection(obj, 2);
        count = group->count;
        piece = group->pieces;
        i = 0;
        base = (s32) SetN64_GetPackSection(obj, i);
        if (count > 0) {
            do {
                if (piece[i].tag == -1) {
                    piece[i].tag = 0;
                } else {
                    piece[i].tag = Scene_GetIndexedModelResource(arg0, piece[i].tag);
                }
                piece[i].unk18 = base + piece[i].unk18;
                piece[i].unk1C = base + piece[i].unk1C;
                piece[i].unk20 = base + piece[i].unk20;
                piece[i].unk24 = base + piece[i].unk24;
                piece[i].unk28 = base + piece[i].unk28;
                piece[i].unk2C = base + piece[i].unk2C;
                piece[i].unk30 = base + piece[i].unk30;
                piece[i].unk34 = base + piece[i].unk34;
                piece[i].unk38 = base + piece[i].unk38;
                i++;
            } while (i < count);
        }
    }
}

void Scene_ScaleDefinitionFields(s32 unused0, void ***arg1) {
    f32 scale;
    void *obj;
    Ent *ent;
    s32 count;
    s32 i;

    scale = D_800C5304_de;
    if (Ppdecom_UnpackResource(arg1, 0) != 0) {
        obj = **arg1;
        count = *(s32 *) obj;
        for (i = 0; i < count; i++) {
            ent = SetN64_GetPackSection(obj, i);
            switch (ent->kind) {
            case 1:
                ent->unk28 = ent->unk28 * scale;
                ent->unk30 = ent->unk30 * scale;
                ent->unk34 = ent->unk34 * scale;
                ent->unk50 = ent->unk50 * scale;
                ent->unk54 = ent->unk54 * scale;
                ent->unk58 = ent->unk58 * scale;
                break;
            case 11:
                ent->unkEC = ent->unkEC * scale;
                ent->unkF0 = ent->unkF0 * scale;
                break;
            case 0:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                break;
            }
        }
    }
}

void Scene_ResolveFrameItemReferences(OwnerCode8044E2B8 *arg0, void ***arg1) {
    void *obj;
    FrameCode8044E2B8 *frame;
    BankCode8044E2B8 *bank;
    struct EntryRecAt0V3 *items;
    struct EntryRecAt0V3 *item;
    SlotRecAt0V2 *slot;
    s32 count;
    s32 inner;
    s32 i;
    s32 j;
    s32 index;

    if (Ppdecom_UnpackResource(arg1, 0) != 0) {
        obj = **arg1;
        count = *(s32 *) obj;
        for (i = 0; i < count; i++) {
            frame = SetN64_GetPackSection(SetN64_GetPackSection(obj, i), 1);
            inner = frame->count;
            j = 0;
            if (j < inner) {
                slot = frame->slots;
                do {
                    index = slot->item;
                    if (index != -1) {
                        bank = SetN64_GetPackSection(arg0->unk6C, 2);
                        items = bank->items;
                        if ((index < 0) || (index >= bank->count)) {
                            item = 0;
                        } else {
                            item = &items[index];
                        }
                        slot->item = (s32) item;
                    } else {
                        slot->item = 0;
                    }
                    slot++;
                    j++;
                } while (j < inner);
            }
        }
        arg0->unk7C = obj;
    }
}
