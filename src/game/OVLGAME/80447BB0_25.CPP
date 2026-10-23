#include "COMMON/OBJECTSTATE96.H"
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
#include "SYSTEM/80255C40_7.H"
#include "WEAPONS/80213ED4.H"

extern char D_8010F328[];

extern char D_801462C8[];

extern char D_801468A0[];

extern void func_80253908_de(s32);

extern void func_80253838_de(void *arg0, void *arg1);

extern void func_80226950_de(ObjectPool *, s32);
extern s32 D_800C9684[];
extern void func_80448EF4_de(void *actor, s32 character, s32 active);



/* Resets a 0x44-byte record: clears it through func_802A001C_de, initialises the two lists at offsets
   0xC and 0x20 through func_80255CA0_de with 0x16DC and 0x16E0, and clears the words at 0 to 8 and
   0x34 to 0x40. */

/* Refreshes every instance owned by the holder and clears their pending flag. */



void func_80220A80_de(Shared_ActorView *, Shared_ActorView *);

                 /* extern */
void func_80245864_de(void *);

                            /* extern */

                            /* extern */
                           /* extern */
                           /* extern */
                    /* extern */
s32 func_802934F8_de(void);

                            /* extern */
void func_804491E8_de(Shared_ActorView *);

/* Sets the byte at offset 0x78 of the object at 0x5D8 of an actor, calls func_80448EF4_de with the
   actor, its second argument and one, then func_80214178_de on offsets 0x2E8 and 0x458 with two and
   func_8021B1E4_de with D_80146898, zero and one. */







void func_804499B0_de(ObjectPool *pool, s32 count, s32 force_active) {
    extern void func_802A6F68_de(RecordRecAtE8 *);
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

    func_80255CA0_de(&pool->active_queue, 0x16DC, 0x16E0);
    func_80255CA0_de(&pool->object_queue, 0x16DC, 0x16E0);
    func_80264854_de(0);
    func_80253908_de(0);
    global = D_801462C8;

    if (pool->allocation != 0) {
        func_80253838_de(0, pool->allocation);
        pool->allocation = 0;
        pool->objects = 0;
        pool->count = 0;
    }

    if (count == 0) {
        return;
    }

    func_80226950_de(pool, count);
    for (i = 0; i < pool->count; i++) {
        func_80255D14_de(&pool->active_queue, pool->objects + i * 0x16E8);
    }

    for (i = 0; i < pool->count; i++) {
        entry = global + 0xD0 + i * 0x96;
        if (((ObjectState96 *)(entry))->unk_95 != 0) {
            ((ObjectState96 *)(entry))->unk_78 = 0;
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
            object = pool->objects + object_offset;
            ((struct Shared_ActorView *)(object))->remote = ((ObjectState96 *)(entry))->unk_91;
            ((struct Shared_ActorView *)(object))->actorState = 0;
            if (((struct Shared_ActorView *)(object))->remote != 0) {
                func_8026367C_de(object + 0x688, D_8010EEB8);
                ((struct Shared_ActorView *)(object))->mode = ((ObjectState96 *)(entry))->unk_7F;
            } else {
                func_8026367C_de(object + 0x688, D_8010F328 + attribute_offset);
                ((struct Shared_ActorView *)(object))->mode = i;
            }
            owner = ((struct Shared_ActorView *)(object))->owner;
            ((struct Shared_ActorView *)(object))->controls = (Shared_ControlView *)entry;
            object_id = ((ObjectState96 *)(entry))->unk_81;
            ((struct Shared_ActorView *)(object))->field11BC = 0;
            ((struct Shared_ActorView *)(object))->field11C0 = 0;
            ((struct Shared_ActorView *)(object))->spawn = 0;
            ((struct Shared_ActorView *)(object))->field5F0 = 0;
            ((struct Shared_ActorView *)(object))->field864 = 0;
            ((struct Shared_ActorView *)(object))->field868 = 0;
            ((struct Shared_ActorView *)(object))->self = object;
            ((struct Shared_ActorView *)(object))->id = object_id;
            Nav_InitPlayerState(owner, object);
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
            func_802A6F68_de(&((Shared_ActorView *)object)->record);
            if (((ObjectState96 *)(entry))->unk_78 != 0) {
                func_80448EF4_de(object, ((ObjectState96 *)(entry))->unk_80, 1);
                func_80255ED8_de(&pool->active_queue, object);
                func_80255CB8_de(&pool->object_queue, object);
            }
            player_index += 2;
            attribute_offset += 0x224;
            entry_offset += 0x96;
            object_offset += 0x16E8;
            if (++i < pool->count) {
                goto initialize_object;
            }
    } else {
        object = pool->objects;
        roster_index = ((ObjectState96 *)(entry))->unk_7F;
        ((struct Shared_ActorView *)(object))->remote = ((ObjectState96 *)(entry))->unk_91;
        ((struct Shared_ActorView *)(object))->actorState = 0;
        if (((struct Shared_ActorView *)(object))->remote != 0) {
            func_8026367C_de(object + 0x688, D_8010EEB8);
            ((struct Shared_ActorView *)(object))->mode = ((ObjectState96 *)(entry))->unk_7F;
        } else {
            func_8026367C_de(object + 0x688, D_8010F328 + roster_index * 0x224);
            ((struct Shared_ActorView *)(object))->mode = roster_index;
        }
        owner = ((struct Shared_ActorView *)(object))->owner;
        ((struct Shared_ActorView *)(object))->controls = (Shared_ControlView *)entry;
        object_id = ((ObjectState96 *)(entry))->unk_81;
        ((struct Shared_ActorView *)(object))->field11BC = 0;
        ((struct Shared_ActorView *)(object))->field11C0 = 0;
        ((struct Shared_ActorView *)(object))->spawn = 0;
        ((struct Shared_ActorView *)(object))->field5F0 = 0;
        ((struct Shared_ActorView *)(object))->field864 = 0;
        ((struct Shared_ActorView *)(object))->field868 = 0;
        ((struct Shared_ActorView *)(object))->self = object;
        ((struct Shared_ActorView *)(object))->id = object_id;
        Nav_InitPlayerState(owner, object);
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
        func_802A6F68_de(&((Shared_ActorView *)object)->record);
        func_80448EF4_de(object, ((ObjectState96 *)(entry))->unk_80, force_active);
        func_80255ED8_de(&pool->active_queue, object);
        func_80255CB8_de(&pool->object_queue, object);
    }

initialized:
    state = D_801468A0;
    ((IntegerState88 *)(state))->unk_74 = 1;
    ((IntegerState88 *)(state))->unk_84 = 3;
}

void func_80449DB0_de(struct RecordCode80447BB0 *record) {
    func_802A001C_de(record, 0, 0x44);
    func_80255CA0_de(&record->listC, 0x16DC, 0x16E0);
    func_80255CA0_de(&record->list20, 0x16DC, 0x16E0);
    record->word0 = 0;
    record->word4 = 0;
    record->word8 = 0;
    record->word34 = 0;
    record->word38 = 0;
    record->word3C = 0;
    record->word40 = 0;
}

                         /* extern */

void func_80449E18_de(ObjectPool *pool) {
    void *temp_a0;
    s32 temp_v0;
    struct IntPair *temp_v1;
    struct IntPair *temp_v1_2;
    Shared_ActorView *var_s0;
    if ((func_802934F8_de() != 0) && (func_80264B6C_de() != 0)) {
        func_80264B8C_de();
        func_80264B7C_de();
    }
    var_s0 = pool->object_queue.head;
    if (var_s0 != 0) {
        do {
            func_804491E8_de(var_s0);
            temp_v0 = Scene_FindFloorPolygon(&D_8011FE88, &var_s0->position);
            var_s0->weapon.model = temp_v0;
            var_s0->modelId = temp_v0;
            func_80220A80_de(var_s0, var_s0);
            temp_a0 = var_s0->message;
            if (temp_a0 != 0) {
                func_80245864_de(temp_a0);
            }
            temp_v1 = var_s0->model;
            temp_v1->field_4 = temp_v1->field_4 & ~4;
            temp_v1_2 = var_s0->model;
            temp_v1_2->field_4 = temp_v1_2->field_4 & ~4;
            var_s0 = var_s0->next;
        } while (var_s0 != 0);
    }
}
void func_80449EE4_de(char *player, s32 slot, RecordCode80447BB080449EE4 *record) {
    extern void func_802A6F68_de(RecordRecAtE8 *);
    s32 i;
    s32 computer;
    u8 team;

    computer = record->computer;
    ((Shared_ActorView *)player)->actorState = 0;
    ((Shared_ActorView *)player)->remote = computer;
    if (computer != 0) {
        func_8026367C_de(player + 0x688, D_8010EEB8);
        ((Shared_ActorView *)player)->mode = record->slot;
    } else {
        func_8026367C_de(player + 0x688, D_8010F328 + slot * 0x224);
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
    Nav_InitPlayerState((s32)((Shared_ActorView *)player)->owner, player);
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
    func_802A6F68_de(&((Shared_ActorView *)player)->record);
}

void func_8044A020_de(struct ActorCode80447BB0 *actor, s32 character) {
    actor->part->active = 1;
    func_80448EF4_de(actor, character, 1);
    func_80214178_de(&actor->firstEffect, &actor->secondEffect, 2);
    func_8021B1E4_de(actor, D_80146898, 0, 1);
}
