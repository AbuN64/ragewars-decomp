#include "span_1000/code_80225D10.h"
#include "abi.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "gbi.h"
#include "gfx.h"
#include "n64sdk.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8022AE90.h"
#include "span_1000/code_8026AC38.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"
#include "common/unused.h"


/* Draws the marker over a player that is alive at 0x5E4: loads the player's matrix from its table at
   0x1640 (the first entry while func_802A23B4_de reports a shared view, otherwise the entry for the current
   view D_800D297C), sets the render and geometry modes, fills the five vertices of a green pyramid in
   D_800FE9F8 and emits them with its four triangles. Adapted from func_8021C698_de with the pyramid, the
   colour and the matrix selection changed. */
extern s32 D_800D297C;


extern Gfx *D_80110634;

extern s32 func_802A23B4_de(void);

extern void func_8026D8F8_de(void);

extern void func_8026925C_de(s32);

extern void func_80268CE0_de(s32);

/* Scales damage by ownership and player state and suppresses friendly damage when configured. */



extern f32 D_800C2CC4_de, D_800C7DB8, D_800C2CCC_de, D_800C7DC0, D_800C2CD4_de, D_800C7DC8, D_800C2CDC_de, D_800C2CE0_de;

extern u8 D_801462C8[];

extern void func_80253BBC_de(s32 arg0, void *arg1);

extern void func_8024B8C4_de(void *arg0);



extern s32 func_8024D160_de(void *arg0);

extern s32 func_80245908_de(void);



#if defined(VERSION_US_REV1)
extern s32 D_800D0EBC;
#endif

extern void func_8023942C_de(void *arg0);

extern void func_8021EEFC_de(void *arg0, void *arg1);


extern void func_80228AF4_de(void);

/* Returns the leading team: for each player in the list from 0x20 it adds the player's kills of the
   seven other players (the shorts at 0x3C of its stats at 0x5D8) to the total of its team byte at
   0x92, returning 0 at once for a player without a team (0xFF), then returns the first team 0 to 4
   with the highest total. */
s32 func_80229A80_de(void *game) {
    s32 total0;
    s32 total1;
    s32 total2;
    s32 total3;
    s32 total4;
    char *player;
    char *stats;
    s32 self;
    s32 other;
    s32 best;
    s32 leader;

    total4 = 0;
    total3 = 0;
    total2 = 0;
    total1 = 0;
    total0 = 0;
    for (player = ((struct ObjectPool *)(game))->object_queue.head; player != 0; player = (char *)((struct Shared_ActorView *)(player))->next) {
        self = (u32) (player - ((struct ObjectPool *)(game))->objects) / 0x16E8;
        for (other = 0; other < 8; other++) {
            if (other == self) {
                continue;
            }
            stats = (char *)((struct Shared_ActorView *)(player))->controls;
            switch (((Record *)(stats))->team) {
            case 0xFF:
                return 0;
            case 0:
                total0 += ((Stats *) stats)->kills[other];
                break;
            case 1:
                total1 += ((Stats *) stats)->kills[other];
                break;
            case 2:
                total2 += ((Stats *) stats)->kills[other];
                break;
            case 3:
                total3 += ((Stats *) stats)->kills[other];
                break;
            case 4:
                total4 += ((Stats *) stats)->kills[other];
                break;
            }
        }
    }
    do {
        best = leader = -1;
    } while (0);
    if (best < total0) {
        best = total0;
        leader = 0;
    }
    if (best < total1) {
        best = total1;
        leader = 1;
    }
    if (best < total2) {
        best = total2;
        leader = 2;
    }
    if (best < total3) {
        best = total3;
        leader = 3;
    }
    if (best < total4) {
        best = total4;
        leader = 4;
    }
    return leader;
}

/** Return the animation-table offset selected by the actor state. */
s32 func_80229C0C_de(void *arg0, s32 arg1) {
    s32 *types = &D_800CE47C;
    u16 type = ((struct Shared_ActorView *)(arg0))->kind;
    char *state;
    s32 offset;

    if (type == types[0]) {
        switch (D_80142850) {
        case 0:
            offset = 0x514;
            break;
        case 1:
            offset = 0x5DC;
            break;
        case 2:
            offset = 0x578;
            break;
        default:
            D_80142850 = 0;
            offset = 0x514;
            break;
        }
    } else if (type == types[-2]) {
        offset = 0x190;
    } else if (type == types[-1]) {
        offset = 0x3E8;
    } else {
        state = (char *)((struct Shared_ActorView *)(arg0))->controls;
        switch (((struct Shared_ControlView *)(state))->mode) {
        default:
            ((struct Shared_ControlView *)(state))->mode = 0;
        case 0:
            offset = 0;
            break;
        case 1:
            offset = 0x44C;
            break;
        case 2:
            offset = 0xC8;
            break;
        case 3:
            offset = 0x12C;
            break;
        case 4:
            offset = 0x4B0;
            break;
        case 5:
            offset = 0x64;
            break;
        case 6:
            offset = 0x258;
            break;
        case 7:
            offset = 0x384;
            break;
        case 8:
            offset = 0x320;
            break;
        case 9:
        case 15:
            offset = 0x2BC;
            break;
        case 10:
            offset = 0x1F4;
            break;
        case 11:
            offset = 0x640;
            break;
        case 12:
            offset = 0x6A4;
            break;
        case 13:
        case 16:
            offset = 0x708;
            break;
        case 14:
            offset = 0x76C;
            break;
        }
    }
    return arg1 + offset;
}

void func_80229D28_de(Player16C0 *player) {
    s32 green;
    s32 alpha;

    if (player->alive != 0) {
        if (func_802A23B4_de() != 0) {
            gSPMatrix(D_80110634++, (u32) &player->markers[0], G_MTX_LOAD);
        } else {
            gSPMatrix(D_80110634++, (u32) &player->markers[D_800D297C], G_MTX_LOAD);
        }
        gDPPipeSync(D_80110634++);
        func_8026D8F8_de();
        func_8026925C_de(0xE);
        func_80268CE0_de(0x1C);
        green = 200;
        alpha = 150;
        gSPGeometryMode(D_80110634++, G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | 0x80, 0);
        gSPGeometryMode(D_80110634++, 0, G_SHADE | G_SHADING_SMOOTH);
        D_800FE9F8[0].x = 0;
        D_800FE9F8[0].y = 0;
        D_800FE9F8[0].z = 0;
        D_800FE9F8[0].flag = 0;
        D_800FE9F8[0].s = 0;
        D_800FE9F8[0].t = 0;
        D_800FE9F8[0].r = 0;
        D_800FE9F8[0].g = green;
        D_800FE9F8[0].b = 0;
        D_800FE9F8[0].a = alpha;
        D_800FE9F8[1].x = 20;
        D_800FE9F8[1].y = 40;
        D_800FE9F8[1].z = 20;
        D_800FE9F8[1].flag = 0;
        D_800FE9F8[1].s = 0;
        D_800FE9F8[1].t = 0;
        D_800FE9F8[1].r = 0;
        D_800FE9F8[1].g = green;
        D_800FE9F8[1].b = 0;
        D_800FE9F8[1].a = alpha;
        D_800FE9F8[2].x = -20;
        D_800FE9F8[2].y = 40;
        D_800FE9F8[2].z = 20;
        D_800FE9F8[2].flag = 0;
        D_800FE9F8[2].s = 0;
        D_800FE9F8[2].t = 0;
        D_800FE9F8[2].r = 0;
        D_800FE9F8[2].g = green;
        D_800FE9F8[2].b = 0;
        D_800FE9F8[2].a = alpha;
        D_800FE9F8[3].x = -20;
        D_800FE9F8[3].y = 40;
        D_800FE9F8[3].z = -20;
        D_800FE9F8[3].flag = 0;
        D_800FE9F8[3].s = 0;
        D_800FE9F8[3].t = 0;
        D_800FE9F8[3].r = 0;
        D_800FE9F8[3].g = green;
        D_800FE9F8[3].b = 0;
        D_800FE9F8[3].a = alpha;
        D_800FE9F8[4].x = 20;
        D_800FE9F8[4].y = 40;
        D_800FE9F8[4].z = -20;
        D_800FE9F8[4].flag = 0;
        D_800FE9F8[4].s = 0;
        D_800FE9F8[4].t = 0;
        D_800FE9F8[4].r = 0;
        D_800FE9F8[4].g = green;
        D_800FE9F8[4].b = 0;
        D_800FE9F8[4].a = alpha;
        gSPVertex(D_80110634++, (u32) D_800FE9F8, 5, 0);
        gSP1Triangle(D_80110634++, 0, 1, 2, 0);
        gSP1Triangle(D_80110634++, 0, 1, 4, 0);
        gSP1Triangle(D_80110634++, 0, 2, 3, 0);
        gSP1Triangle(D_80110634++, 0, 3, 4, 0);
    }
}

void func_80229FA0_de(Obj_func_80229FA0_de *arg0, Damage_func_80229FA0_de *arg1) {
    extern func_80207B5C_S2 D_801468A0;
    f32 var_f0;
    f32 var_f1;
    u8 temp_v1;
    u8 temp_v1_2;
    Obj_func_80229FA0_de *temp_a2;
    Obj_func_80229FA0_de *temp_a2_2;
    Obj_func_80229FA0_de *var_a3;

    temp_a2 = arg1->unk0;
    var_a3 = 0;
    if (temp_a2 != 0) {
        temp_v1 = temp_a2->unk0;
        if (temp_v1 != 1) {
            if (temp_v1 == 2) {
                temp_a2_2 = temp_a2->unk12C;
                if ((temp_a2_2 != 0) && (temp_a2_2->unk0 == 1)) {
                    if (temp_a2_2->unk100 & 0x300000) {
                        var_a3 = temp_a2_2;
                        if (var_a3 == arg0) {
                            arg1->unk4 = (s32) ((f32) arg1->unk4 * D_800C2CC4_de * D_800C7DB8 * D_800C2CCC_de);
                        }
                    } else if (temp_a2_2->unkE4 == 0x40C) {
                        var_a3 = temp_a2_2->unk1D8;
                    }
                }
            }
        } else if (temp_a2->unk100 & 0x300000) {
            var_a3 = temp_a2->unk1D8;
        }
    } else {
        var_a3 = arg0;
    }
    if (var_a3 != 0) {
        if (var_a3->unk1450 != 0) {
            temp_v1_2 = var_a3->unk5D8->unk93;
            switch (temp_v1_2) { /* irregular */
            case 2:
                break;
            default:
                var_a3->unk5D8->unk93 = 0U;
                /* fallthrough */
            case 0:
                var_f1 = (f32) arg1->unk4 * D_800C7DC0;
                var_f1 *= D_800C2CD4_de;
                arg1->unk4 = (s32) (var_f1 * D_800C2CE0_de);
                break;
            case 1:
                var_f1 = (f32) arg1->unk4 * D_800C7DC8;
                var_f1 *= D_800C2CDC_de;
                arg1->unk4 = (s32) (var_f1 * D_800C2CE0_de);
                break;
            }
        }
        { func_80207B5C_S2 *state=&D_801468A0;
        if ((state->unk24 != 0) && (((unsigned char *)state)[-0x5B0] == 0) && ((var_a3->unk1450 == 0) || (arg0->unk1450 == 0)) && (arg0->unk5D8->unk92 == var_a3->unk5D8->unk92)) {
            arg1->unk4 = 0;
        }}
    }
}

void func_8022A170_de(void *arg0) {
    void *node;

    if (*(void **)arg0 != 0) {
        func_80253BBC_de(0, *(void **)arg0);
    }

    node = ((struct ObjectPool *)(arg0))->object_queue.head;
    if (node != 0) {
        u8 *base = D_801462C8;

        do {
            func_8024B8C4_de(node);
            func_8024B8C4_de(&((struct Shared_ActorView *)(node))->weapon);
            func_8022BC94_de(node, 0);
            if (base[0x1D] != 0) {
                func_8024B7E4_de(node, 1);
            }
            node = ((struct Shared_ActorView *)(node))->next;
        } while (node != 0);
    }
}

void func_8022A1FC_de(void *arg0, void *arg1) {
    void *node;
    int scale;
    s32 count1;
    s32 count2;
    char *entry;

    node = ((struct ObjectPool *)(arg0))->object_queue.head;
    if (node != 0) {
        do {
            ((ObjectLinks16E4_2 *)(node))->unk_70 = 0;
            ((ObjectLinks16E4_2 *)(node))->unk_358 = 0;
            if (func_8024D160_de(node) != 0) {
                if (node) {
                    count1 = ((IntegerState948 *)(arg1))->unk_944;
                } else {
                    count1 = ((IntegerState948 *)(arg1))->unk_944;
                }
                if (count1 != 0x200) {
                    scale = 4;
                    ((ObjectLinks148 *)(((s32)arg1 + count1 * scale)))->unk_144 = node;
                    ((IntegerState948 *)(arg1))->unk_944 = count1 + 1;
                }
                count1 = 0xB48;
                count2 = ((IntegerStateB4C *)arg1)->unk_B48;
                if (count2 != 0x80) {
                    ((struct ObjectLinks94C *) (entry = (char *) (((s32) arg1) + (count2 * 4))))->unk_948 = node;
                    ((IntegerStateB4C *)arg1)->unk_B48 = count2 + 1;
                }
            }
            node = ((ObjectLinks16E4_2 *)(node))->unk_16E0;
        } while (node != 0);
    }
}

void func_8022A2A0_de(void *arg0, void *arg1) {
    func_80228774_S1 *object;
    func_80207B5C_S2 *argument;
    func_8022A274_S2 *cur;

    func_8026D980_de();
    object = arg0;
    cur = object->unk20;
    if (cur != 0) {
        do {
            argument = arg1;
            if (cur->unk5DC != arg1 ||
                argument->unk24 == 1 ||
                func_80245908_de() != 0) {
                func_8021C9D8_de(cur, arg1);
            }
            cur = cur->unk16E0;
        } while (cur != 0);
    }
    func_8026D9D0_de();
}

/* Removes entity from list if owned by specific owner, with version-specific check. */
void func_8022A328_de(void *arg0, void *arg1) {
    func_80228774_S1 *object;
    func_80207B5C_S2 *argument;
    ObjRecAt16E0V3 *var_s0;

#if defined(VERSION_US_REV1)
    if (D_800D0EBC != 0) {
        object = arg0;
        object = arg0;
    var_s0 = object->unk20;
        if (var_s0 != 0) {
            do {
                argument = arg1;
                if (var_s0->unk5DC == arg1 &&
                    argument->unk24 == 0 &&
                    var_s0->unkE4 != D_800CE47C) {
                    func_8021CBD0_de(var_s0, arg1);
                }
                var_s0 = var_s0->unk16E0;
            } while (var_s0 != 0);
        }
    }
#else
    object = arg0;
    var_s0 = object->unk20;
    if (var_s0 != 0) {
        do {
            argument = arg1;
            if (var_s0->unk5DC == arg1 &&
                argument->unk24 == 0 &&
                var_s0->unkE4 != D_800CE47C) {
                func_8021CBD0_de(var_s0, arg1);
            }
            var_s0 = var_s0->unk16E0;
        } while (var_s0 != 0);
    }
#endif
}

/* Notifies the entity list associated with arg0 about arg1 and calls a handler for each owner. */
void func_8022A398_de(void *arg0, void *arg1) {
    Round *round = arg0;
    Shared_ActorView *var_s0;

#if defined(VERSION_US_REV1)
    if (D_800D0EBC != 0) {
#endif
        func_8023942C_de(arg1);
        var_s0 = round->players;
        if (var_s0 != 0) {
            do {
                if (var_s0->message == arg1) {
                    func_8021EEFC_de(var_s0, arg1);
                }
                var_s0 = var_s0->next;
            } while (var_s0 != 0);
        }
#if defined(VERSION_US_REV1)
    }
#endif
}

void func_8022A3F8_de(void) { func_80228AF4_de(); }

int func_8022A414_de(void *arg0) {
    Context *context = arg0;
    return (int)context->head;
}

void *func_8022A420_de(void *arg0) {
    extern GlobalState D_801468A0;
    GlobalState *base = &D_801468A0;
    Shared_ActorView *record;

    if (base->restricted != 0 && base->restrictionActive != 0) {
        return 0;
    }
    record = (void *)((struct Context *)arg0)->head;
    if (record != 0) {
        do {
            if (record->controls->transientFlag == 1) {
                return record;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}
