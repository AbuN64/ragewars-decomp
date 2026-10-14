#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80447BB0.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"



extern char D_8010EEB8[];
extern char D_8010F328[];
extern char D_801462C8[];
extern char D_801468A0[];
extern s32 D_800C9684;


extern void func_80253908_de(s32);
extern void func_80253838_de(void *arg0, void *arg1);
extern void func_80226950_de(ObjectPool *, s32);
extern void func_8026367C_de(void *, void *);
extern void func_802097E8_de(void *, void *);
extern void func_8021A78C_de(void *);
extern void func_802A6F68_de(void *);
extern void func_80448EF4_de(void *, s32, s32);
extern void func_80255ED8_de(void *, void *);
extern void func_80255CB8_de(void *, void *);










void func_804499B0_de(ObjectPool *pool, s32 count, s32 force_active) {
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
            func_802097E8_de(owner, object);
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
            ((struct Shared_ActorView *)(object))->field13B4 = &D_800C9684;
            ((struct Shared_ActorView *)(object))->field11E8 = 0;
            func_8021A78C_de(object);
            ((struct Shared_ActorView *)(object))->field16D4 = 0;
            ((struct Shared_ActorView *)(object))->field16D8 = 0;
            func_802A6F68_de((char *)object + 0xD40);
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
        func_802097E8_de(owner, object);
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
        ((struct Shared_ActorView *)(object))->field13B4 = &D_800C9684;
        ((struct Shared_ActorView *)(object))->field11E8 = 0;
        func_8021A78C_de(object);
        ((struct Shared_ActorView *)(object))->field16D4 = 0;
        ((struct Shared_ActorView *)(object))->field16D8 = 0;
        func_802A6F68_de((char *)object + 0xD40);
        func_80448EF4_de(object, ((ObjectState96 *)(entry))->unk_80, force_active);
        func_80255ED8_de(&pool->active_queue, object);
        func_80255CB8_de(&pool->object_queue, object);
    }

initialized:
    state = D_801468A0;
    ((IntegerState88 *)(state))->unk_74 = 1;
    ((IntegerState88 *)(state))->unk_84 = 3;
}
