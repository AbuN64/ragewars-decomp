#include "MENU/ITEMS/80444030_4.H"
#include "COMMON/OBJECTSTATE96.H"
#include "COMMON/GAME_SESSION.H"
#include "OVLGAME/80447BB0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/WORLD.H"
#include "COMMON/S1.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "AI/NAV/80208000_4.H"
#include "RENDER_2/802192C0_3.H"
#include "FX/802631D0.H"
#include "RESMGR/802A0888.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_3.H"
#include "WEAPONS/80213ED4.H"
#include "CINEMA/CINEMA.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

extern char D_8010F328[];

extern char D_801462C8[];

extern char D_801468A0[];

extern void func_80253908_de(s32);


extern void Player_AllocPlayerList(CPlayerPool *, s32);
extern s32 D_800C9684[];
extern void Player_ResetPlayerForRound(void *actor, s32 character, s32 active);



/* Resets a 0x44-byte record: clears it through XPlus_FillMemory, initialises the two lists at offsets
   0xC and 0x20 through func_80255CA0_de with 0x16DC and 0x16E0, and clears the words at 0 to 8 and
   0x34 to 0x40. */

/* Refreshes every instance owned by the holder and clears their pending flag. */



void Player_UpdatePlayerCamera(Shared_ActorView *, Shared_ActorView *);

                 /* extern */

                            /* extern */

                            /* extern */
                           /* extern */
                           /* extern */
                    /* extern */
s32 SetN64_IsModeThirteen(void);

                            /* extern */
void Player_InitActorHudState(Shared_ActorView *);

/* Sets the byte at offset 0x78 of the object at 0x5D8 of an actor, calls Player_ResetPlayerForRound with the
   actor, its second argument and one, then func_80214178_de on offsets 0x2E8 and 0x458 with two and
   Player_PlacePlayerAtSpawnPoint with g_playerSpawnSelector, zero and one. */







void Ovlgame_InitializePlayerPool(CPlayerPool *pool, s32 count, s32 force_active) {
    extern void ItemMenu_ResetEntries(CItemMenu *);
    s32 i;
    s32 j;
    s32 entry_offset;
    s32 attribute_offset;
    s32 player_index;
    s32 object_offset;
    s32 roster_index;
    u8 object_id;
    void *owner;
    char *object;
    char *entry;
    char *global;
    char *state;

    func_80255CA0_de(&pool->m_FreeList, 0x16DC, 0x16E0);
    func_80255CA0_de(&pool->m_ActiveList, 0x16DC, 0x16E0);
    Control_SetControllerMode(0);
    func_80253908_de(0);
    global = D_801462C8;

    if (pool->m_pmePlayers != 0) {
        Cache_ReleaseResource(0, pool->m_pmePlayers);
        pool->m_pmePlayers = 0;
        pool->m_Players = 0;
        pool->count = 0;
    }

    if (count == 0) {
        return;
    }

    Player_AllocPlayerList(pool, count);
    for (i = 0; i < pool->count; i++) {
        func_80255D14_de(&pool->m_FreeList, pool->m_Players + i * 0x16E8);
    }

    for (i = 0; i < pool->count; i++) {
        entry = global + 0xD0 + i * 0x96;
        if (((CPlayerOptions *)(entry))->talsetPosse != 0) {
            ((CPlayerOptions *)(entry))->active = 0;
        }
    }

    entry = global + 0x3A;
    if (((ObjectState1E_2 *)(global))->unk_1D != 0) {
        if (pool->count <= 0) {
            goto initialized;
        }
        i = 0;
        player_index = i;
        attribute_offset = i;
        entry_offset = 0xD0;
        object_offset = i;
initialize_object:
            entry = global + entry_offset;
            object = pool->m_Players + object_offset;
            ((struct Shared_ActorView *)(object))->remote = ((CPlayerOptions *)(entry))->isBot;
            ((struct Shared_ActorView *)(object))->actorState = 0;
            if (((struct Shared_ActorView *)(object))->remote != 0) {
                ContPad_InitControllerInput(object + 0x688, D_8010EEB8);
                ((struct Shared_ActorView *)(object))->mode = ((CPlayerOptions *)(entry))->controller;
            } else {
                ContPad_InitControllerInput(object + 0x688, D_8010F328 + attribute_offset);
                ((struct Shared_ActorView *)(object))->mode = i;
            }
            owner = ((struct Shared_ActorView *)(object))->owner;
            ((struct Shared_ActorView *)(object))->controls = (Shared_ControlView *)entry;
            object_id = ((CPlayerOptions *)(entry))->characterSkin;
            ((struct Shared_ActorView *)(object))->field11BC = 0;
            ((struct Shared_ActorView *)(object))->field11C0 = 0;
            ((struct Shared_ActorView *)(object))->spawn = 0;
            ((struct Shared_ActorView *)(object))->field5F0 = 0;
            ((struct Shared_ActorView *)(object))->field864 = 0;
            ((struct Shared_ActorView *)(object))->field868 = 0;
            ((struct Shared_ActorView *)(object))->self = object;
            ((struct Shared_ActorView *)(object))->id = object_id;
            Scaled_InitPlayerState(owner, object);
            ((struct Shared_ActorView *)(object))->special = 0;
            ((struct Shared_ActorView *)(object))->projectileBase = player_index;
            ((struct Shared_ActorView *)(object))->projectileIndex = 0;
            ((struct Shared_ActorView *)(object))->field122C = 0;
            ((struct Shared_ActorView *)(object))->field11CC = 0;
            ((struct Shared_ActorView *)(object))->field1218 = 0;
            for (j = 0; j < 8; j++) {
                ((Shared_ActorView *)object)->reset12CC[j] = 0;
                ((Shared_ActorView *)object)->reset12F4[j] = 0;
            }
            ((struct Shared_ActorView *)(object))->field1338 = -1;
            ((struct Shared_ActorView *)(object))->field12C4 = 0;
            ((struct Shared_ActorView *)(object))->field12C8 = 0;
            ((struct Shared_ActorView *)(object))->field1334 = 0;
            ((struct Shared_ActorView *)(object))->field13B4 = D_800C9684;
            ((struct Shared_ActorView *)(object))->field11E8 = 0;
            func_8021A78C_de(object);
            ((struct Shared_ActorView *)(object))->field16D4 = 0;
            ((struct Shared_ActorView *)(object))->field16D8 = 0;
            ItemMenu_ResetEntries(&((Shared_ActorView *)object)->record);
            if (((CPlayerOptions *)(entry))->active != 0) {
                Player_ResetPlayerForRound(object, ((CPlayerOptions *)(entry))->character, 1);
                func_80255ED8_de(&pool->m_FreeList, object);
                func_80255CB8_de(&pool->m_ActiveList, object);
            }
            player_index += 2;
            attribute_offset += 0x224;
            entry_offset += 0x96;
            object_offset += 0x16E8;
            if (++i < pool->count) {
                goto initialize_object;
            }
    } else {
        object = pool->m_Players;
        roster_index = ((CPlayerOptions *)(entry))->controller;
        ((struct Shared_ActorView *)(object))->remote = ((CPlayerOptions *)(entry))->isBot;
        ((struct Shared_ActorView *)(object))->actorState = 0;
        if (((struct Shared_ActorView *)(object))->remote != 0) {
            ContPad_InitControllerInput(object + 0x688, D_8010EEB8);
            ((struct Shared_ActorView *)(object))->mode = ((CPlayerOptions *)(entry))->controller;
        } else {
            ContPad_InitControllerInput(object + 0x688, D_8010F328 + roster_index * 0x224);
            ((struct Shared_ActorView *)(object))->mode = roster_index;
        }
        owner = ((struct Shared_ActorView *)(object))->owner;
        ((struct Shared_ActorView *)(object))->controls = (Shared_ControlView *)entry;
        object_id = ((CPlayerOptions *)(entry))->characterSkin;
        ((struct Shared_ActorView *)(object))->field11BC = 0;
        ((struct Shared_ActorView *)(object))->field11C0 = 0;
        ((struct Shared_ActorView *)(object))->spawn = 0;
        ((struct Shared_ActorView *)(object))->field5F0 = 0;
        ((struct Shared_ActorView *)(object))->field864 = 0;
        ((struct Shared_ActorView *)(object))->field868 = 0;
        ((struct Shared_ActorView *)(object))->self = object;
        ((struct Shared_ActorView *)(object))->id = object_id;
        Scaled_InitPlayerState(owner, object);
        ((struct Shared_ActorView *)(object))->special = 0;
        ((struct Shared_ActorView *)(object))->projectileBase = roster_index * 2;
        ((struct Shared_ActorView *)(object))->projectileIndex = 0;
        ((struct Shared_ActorView *)(object))->field122C = 0;
        ((struct Shared_ActorView *)(object))->field11CC = 0;
        ((struct Shared_ActorView *)(object))->field1218 = 0;
        for (j = 0; j < 8; j++) {
            ((Shared_ActorView *)object)->reset12CC[j] = 0;
            ((Shared_ActorView *)object)->reset12F4[j] = 0;
        }
        ((struct Shared_ActorView *)(object))->field1338 = -1;
        ((struct Shared_ActorView *)(object))->field12C4 = 0;
        ((struct Shared_ActorView *)(object))->field12C8 = 0;
        ((struct Shared_ActorView *)(object))->field1334 = 0;
        ((struct Shared_ActorView *)(object))->field13B4 = D_800C9684;
        ((struct Shared_ActorView *)(object))->field11E8 = 0;
        func_8021A78C_de(object);
        ((struct Shared_ActorView *)(object))->field16D4 = 0;
        ((struct Shared_ActorView *)(object))->field16D8 = 0;
        ItemMenu_ResetEntries(&((Shared_ActorView *)object)->record);
        Player_ResetPlayerForRound(object, ((CPlayerOptions *)(entry))->character, force_active);
        func_80255ED8_de(&pool->m_FreeList, object);
        func_80255CB8_de(&pool->m_ActiveList, object);
    }

initialized:
    state = D_801468A0;
    ((IntegerState88 *)(state))->unk_74 = 1;
    ((IntegerState88 *)(state))->unk_84 = 3;
}

void Ovlgame_ResetMenuPool(struct RecordCode80447BB0 *record) {
    XPlus_FillMemory(record, 0, 0x44);
    func_80255CA0_de(&record->m_FreeList, 0x16DC, 0x16E0);
    func_80255CA0_de(&record->m_ActiveList, 0x16DC, 0x16E0);
    record->m_pmePlayers = 0;
    record->m_Players = 0;
    record->word8 = 0;
    record->m_bEnteredAdonSaveLocation = 0;
    record->m_bAdonSaveLocationMenuEnabled = 0;
    record->m_TeamTriangleTimer = 0;
    record->m_TriangleSpin = 0;
}

                         /* extern */

void Player_RefreshActivePlayerSceneState(CPlayerPool *pool) {
    void *message;
    s32 temp_v0;
    struct IntPair *model;
    struct IntPair *temp_v1_2;
    Shared_ActorView *actor;
    if ((SetN64_IsModeThirteen() != 0) && (Control_IsSnapshotActive() != 0)) {
        Control_RestoreActorSnapshot();
        Control_DeactivateActorSnapshot();
    }
    actor = pool->m_ActiveList.head;
    if (actor != 0) {
        do {
            Player_InitActorHudState(actor);
            temp_v0 = Scene_FindFloorPolygon(&g_world, &actor->position);
            actor->weapon.model = temp_v0;
            actor->modelId = temp_v0;
            Player_UpdatePlayerCamera(actor, actor);
            message = actor->message;
            if (message != 0) {
                Cinema_UpdateSequenceTrack(message);
            }
            model = actor->model;
            model->field_4 = model->field_4 & ~4;
            temp_v1_2 = actor->model;
            temp_v1_2->field_4 = temp_v1_2->field_4 & ~4;
            actor = actor->next;
        } while (actor != 0);
    }
}
void Player_InitializePlayerFromRecord(char *player, s32 slot, RecordCode80447BB080449EE4 *record) {
    extern void ItemMenu_ResetEntries(CItemMenu *);
    s32 i;
    s32 computer;
    u8 team;

    computer = record->computer;
    ((Shared_ActorView *)player)->actorState = 0;
    ((Shared_ActorView *)player)->remote = computer;
    if (computer != 0) {
        ContPad_InitControllerInput(player + 0x688, D_8010EEB8);
        ((Shared_ActorView *)player)->mode = record->slot;
    } else {
        ContPad_InitControllerInput(player + 0x688, D_8010F328 + slot * 0x224);
        ((Shared_ActorView *)player)->mode = slot;
    }
    ((Shared_ActorView *)player)->controls = (void *)record;
    team = record->team;
    ((Shared_ActorView *)player)->field11BC = 0;
    ((Shared_ActorView *)player)->field11C0 = 0;
    ((Shared_ActorView *)player)->spawn = 0;
    ((Shared_ActorView *)player)->field5F0 = 0;
    ((Shared_ActorView *)player)->field864 = 0;
    ((Shared_ActorView *)player)->field868 = 0;
    ((Shared_ActorView *)player)->self = player;
    player[3] = team;
    Scaled_InitPlayerState((s32)((Shared_ActorView *)player)->owner, player);
    ((Shared_ActorView *)player)->special = 0;
    ((Shared_ActorView *)player)->projectileBase = slot * 2;
    ((Shared_ActorView *)player)->projectileIndex = 0;
    ((Shared_ActorView *)player)->field122C = 0;
    ((Shared_ActorView *)player)->field11CC = 0;
    ((Shared_ActorView *)player)->field1218 = 0;
    for (i = 0; i < 8; i++) {
        ((Shared_ActorView *)player)->reset12CC[i] = 0;
        ((Shared_ActorView *)player)->reset12F4[i] = 0;
    }
    ((Shared_ActorView *)player)->field1338 = -1;
    ((Shared_ActorView *)player)->field12C4 = 0;
    ((Shared_ActorView *)player)->field12C8 = 0;
    ((Shared_ActorView *)player)->field1334 = 0;
    ((Shared_ActorView *)player)->field13B4 = D_800C9684;
    ((Shared_ActorView *)player)->field11E8 = 0;
    func_8021A78C_de(player);
    ((Shared_ActorView *)player)->field16D4 = 0;
    ((Shared_ActorView *)player)->field16D8 = 0;
    ItemMenu_ResetEntries(&((Shared_ActorView *)player)->record);
}

void Player_ActivatePlayerAtSpawn(struct ActorCode80447BB0 *actor, s32 character) {
    actor->part->active = 1;
    Player_ResetPlayerForRound(actor, character, 1);
    Nav_RequestActorState(&actor->firstEffect, &actor->secondEffect, 2);
    Player_PlacePlayerAtSpawnPoint(actor, D_8011FAC0.selector, 0, 1);
}
