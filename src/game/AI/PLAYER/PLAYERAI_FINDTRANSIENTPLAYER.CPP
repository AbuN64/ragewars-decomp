#include "COMMON/OBJRECV5.H"
#include "abi.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/OBJECTSTATE96.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/UNUSED.H"
#include "RENDER/802192C0_6.H"

/* Draws the marker over a player that is alive at 0x5E4: loads the player's matrix from its table at
   0x1640 (the first entry while Tsmos_IsFrontendActive reports a shared view, otherwise the entry for the current
   view D_800D297C), sets the render and geometry modes, fills the five vertices of a green pyramid in
   D_800FE9F8 and emits them with its four triangles. Adapted from Player_DrawRedMarkerPrism with the pyramid, the
   colour and the matrix selection changed. */
extern s32 D_800D297C;


extern Gfx *g_displayListCursor;

extern s32 Tsmos_IsFrontendActive(void);


extern void Geometry_SetModePreset(s32);

extern void Geometry_SetCombineMode(s32);

/* Scales damage by ownership and player state and suppresses friendly damage when configured. */



extern f32 D_800C2CC4_de, D_800C7DB8, D_800C2CCC_de, D_800C7DC0, D_800C2CD4_de, D_800C7DC8, D_800C2CDC_de, D_800C2CE0_de;


extern void Cache_MarkResourceInUse(s32 arg0, void *arg1);

extern void Gobjinst_RotatePoseMatrixBuffers(void *arg0);



extern s32 func_8024D160_de(void *arg0);




#if defined(VERSION_US_REV1)
#endif

extern void Gsky_LoadProjectionMatrix(void *arg0);

extern void func_8021EEFC_de(void *arg0, void *arg1);


extern void Player_DrawMatchCountdown(void *, void *);

/* Returns the leading team: for each player in the list from 0x20 it adds the player's kills of the
   seven other players (the shorts at 0x3C of its stats at 0x5D8) to the total of its team byte at
   0x92, returning 0 at once for a player without a team (0xFF), then returns the first team 0 to 4
   with the highest total. */
s32 func_80229A80_de(struct CPlayerPool_t *game) {
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
    for (player = game->m_ActiveList.head; player != 0; player = (char *)((struct Shared_ActorView *)(player))->next) {
        self = (u32) (player - game->m_Players) / 0x16E8;
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
s32 func_80229C0C_de(struct Shared_ActorView *player, s32 baseSoundId) {
    s32 *types = &D_800CE47C;
    u16 type = player->kind;
    char *state;
    s32 offset;

    if (type == types[0]) {
        switch (D_801462C8.counters.m_nFragTagSkin) {
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
            D_801462C8.counters.m_nFragTagSkin = 0;
            offset = 0x514;
            break;
        }
    } else if (type == types[-2]) {
        offset = 0x190;
    } else if (type == types[-1]) {
        offset = 0x3E8;
    } else {
        state = (char *)player->controls;
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
    return baseSoundId + offset;
}

void func_80229D28_de(Player16C0 *player) {
    s32 green;
    s32 alpha;

    if (player->alive != 0) {
        if (Tsmos_IsFrontendActive() != 0) {
            gSPMatrix(g_displayListCursor++, (u32) &player->markers[0], G_MTX_LOAD);
        } else {
            gSPMatrix(g_displayListCursor++, (u32) &player->markers[D_800D297C], G_MTX_LOAD);
        }
        gDPPipeSync(g_displayListCursor++);
        Geometry_InvalidateMaterialKeys();
        Geometry_SetModePreset(0xE);
        Geometry_SetCombineMode(0x1C);
        green = 200;
        alpha = 150;
        gSPGeometryMode(g_displayListCursor++, G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | 0x80, 0);
        gSPGeometryMode(g_displayListCursor++, 0, G_SHADE | G_SHADING_SMOOTH);
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
        gSPVertex(g_displayListCursor++, (u32) D_800FE9F8, 5, 0);
        gSP1Triangle(g_displayListCursor++, 0, 1, 2, 0);
        gSP1Triangle(g_displayListCursor++, 0, 1, 4, 0);
        gSP1Triangle(g_displayListCursor++, 0, 2, 3, 0);
        gSP1Triangle(g_displayListCursor++, 0, 3, 4, 0);
    }
}

void func_80229FA0_de(Obj_func_80229FA0_de *damagedPlayer, Damage_func_80229FA0_de *damagePacket) {
    f32 var_f0;
    f32 scaledDamage;
    u8 sourceKind;
    u8 difficulty;
    Obj_func_80229FA0_de *damageSource;
    Obj_func_80229FA0_de *projectileOwner;
    Obj_func_80229FA0_de *creditedPlayer;

    damageSource = damagePacket->unk0;
    creditedPlayer = 0;
    if (damageSource != 0) {
        sourceKind = damageSource->unk0;
        if (sourceKind != 1) {
            if (sourceKind == 2) {
                projectileOwner = damageSource->unk12C;
                if ((projectileOwner != 0) && (projectileOwner->unk0 == 1)) {
                    if (projectileOwner->unk100 & 0x300000) {
                        creditedPlayer = projectileOwner;
                        if (creditedPlayer == damagedPlayer) {
                            damagePacket->unk4 = (s32) ((f32) damagePacket->unk4 * D_800C2CC4_de * D_800C7DB8 * D_800C2CCC_de);
                        }
                    } else if (projectileOwner->unkE4 == 0x40C) {
                        creditedPlayer = projectileOwner->unk1D8;
                    }
                }
            }
        } else if (damageSource->unk100 & 0x300000) {
            creditedPlayer = damageSource->unk1D8;
        }
    } else {
        creditedPlayer = damagedPlayer;
    }
    if (creditedPlayer != 0) {
        if (creditedPlayer->unk1450 != 0) {
            difficulty = creditedPlayer->unk5D8->unk93;
            switch (difficulty) { /* irregular */
            case 2:
                break;
            default:
                creditedPlayer->unk5D8->unk93 = 0U;
                /* fallthrough */
            case 0:
                scaledDamage = (f32) damagePacket->unk4 * D_800C7DC0;
                scaledDamage *= D_800C2CD4_de;
                damagePacket->unk4 = (s32) (scaledDamage * D_800C2CE0_de);
                break;
            case 1:
                scaledDamage = (f32) damagePacket->unk4 * D_800C7DC8;
                scaledDamage *= D_800C2CDC_de;
                damagePacket->unk4 = (s32) (scaledDamage * D_800C2CE0_de);
                break;
            }
        }
        { CGameStatus *state=(&D_801462C8.counters);
        if ((state->teams != 0) && (((unsigned char *)state)[-0x5B0] == 0) && ((creditedPlayer->unk1450 == 0) || (damagedPlayer->unk1450 == 0)) && (damagedPlayer->unk5D8->unk92 == creditedPlayer->unk5D8->unk92)) {
            damagePacket->unk4 = 0;
        }}
    }
}

void func_8022A170_de(struct CPlayerPool_t *playerPool) {
    void *node;

    if (*(void **)playerPool != 0) {
        Cache_MarkResourceInUse(0, *(void **)playerPool);
    }

    node = playerPool->m_ActiveList.head;
    if (node != 0) {
        u8 *base = (u8 *)&D_801462C8;

        do {
            Gobjinst_RotatePoseMatrixBuffers(node);
            Gobjinst_RotatePoseMatrixBuffers(&((struct Shared_ActorView *)(node))->weapon);
            func_8022BC94_de(node, 0);
            if (base[0x1D] != 0) {
                Gobjinst_BuildAnimatedPose(node, 1);
            }
            node = ((struct Shared_ActorView *)(node))->next;
        } while (node != 0);
    }
}

void func_8022A1FC_de(struct CPlayerPool_t *playerPool, void *world) {
    void *node;
    int scale;
    s32 count1;
    s32 count2;
    char *entry;

    node = playerPool->m_ActiveList.head;
    if (node != 0) {
        do {
            ((ObjectLinks16E4_2 *)(node))->unk_70 = 0;
            ((ObjectLinks16E4_2 *)(node))->unk_358 = 0;
            if (func_8024D160_de(node) != 0) {
                if (node) {
                    count1 = ((IntegerState948 *)(world))->itemCount1;
                } else {
                    count1 = ((IntegerState948 *)(world))->itemCount1;
                }
                if (count1 != 0x200) {
                    scale = 4;
                    ((ObjectLinks148 *)(((s32)world + count1 * scale)))->unk_144 = node;
                    ((IntegerState948 *)(world))->itemCount1 = count1 + 1;
                }
                count1 = 0xB48;
                count2 = ((IntegerStateB4C *)world)->itemCount2;
                if (count2 != 0x80) {
                    ((struct ObjectLinks94C *) (entry = (char *) (((s32) world) + (count2 * 4))))->unk_948 = node;
                    ((IntegerStateB4C *)world)->itemCount2 = count2 + 1;
                }
            }
            node = ((ObjectLinks16E4_2 *)(node))->unk_16E0;
        } while (node != 0);
    }
}

void func_8022A2A0_de(void *world, void *view) {
    func_80228774_S1 *object;
    func_80207B5C_S2 *argument;
    func_8022A274_S2 *cur;

    Geometry_BeginModelBatch();
    object = world;
    cur = object->unk20;
    if (cur != 0) {
        do {
            argument = view;
            if (cur->unk5DC != view ||
                argument->unk24 == 1 ||
                Cinema_IsSequenceFlagTwoSet() != 0) {
                Player_DrawPlayerModel(cur, view);
            }
            cur = cur->unk16E0;
        } while (cur != 0);
    }
    Geometry_FlushModelBatch();
}

/* Removes entity from list if owned by specific owner, with version-specific check. */
void func_8022A328_de(void *world, void *view) {
    func_80228774_S1 *object;
    func_80207B5C_S2 *argument;
    ObjRecAt16E0V3 *viewPlayer;

#if defined(VERSION_US_REV1)
    if (D_800D0EBC != 0) {
        object = world;
        object = world;
    viewPlayer = object->unk20;
        if (viewPlayer != 0) {
            do {
                argument = view;
                if (viewPlayer->unk5DC == view &&
                    argument->unk24 == 0 &&
                    viewPlayer->unkE4 != D_800CE47C) {
                    Player_DrawHeldWeapon(viewPlayer, view);
                }
                viewPlayer = viewPlayer->unk16E0;
            } while (viewPlayer != 0);
        }
    }
#else
    object = world;
    viewPlayer = object->unk20;
    if (viewPlayer != 0) {
        do {
            argument = view;
            if (viewPlayer->unk5DC == view &&
                argument->unk24 == 0 &&
                viewPlayer->unkE4 != D_800CE47C) {
                Player_DrawHeldWeapon(viewPlayer, view);
            }
            viewPlayer = viewPlayer->unk16E0;
        } while (viewPlayer != 0);
    }
#endif
}

/* Notifies the entity list associated with arg0 about arg1 and calls a handler for each owner. */
void func_8022A398_de(void *roundContext, void *entity) {
    Round *round = roundContext;
    Shared_ActorView *viewPlayer;

#if defined(VERSION_US_REV1)
    if (D_800D0EBC != 0) {
#endif
        Gsky_LoadProjectionMatrix(entity);
        viewPlayer = round->players;
        if (viewPlayer != 0) {
            do {
                if (viewPlayer->message == entity) {
                    func_8021EEFC_de(viewPlayer, entity);
                }
                viewPlayer = viewPlayer->next;
            } while (viewPlayer != 0);
        }
#if defined(VERSION_US_REV1)
    }
#endif
}

void func_8022A3F8_de(void *arg0, void *viewState) { Player_DrawMatchCountdown(arg0, viewState); }

int Playerai_GetFirstPlayer(void *world) {
    Context *context = world;
    return (int)context->head;
}

void *Playerai_FindTransientPlayer(struct Context *context) {
    CGameStatus *base = (&D_801462C8.counters);
    Shared_ActorView *record;

    if (base->m_bFragTagOn != 0 && base->m_FragTagFlipTimer != 0) {
        return 0;
    }
    record = (void *)context->head;
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
