#include "include_asm.h"
#include "COMMON/OBJRECV5.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "WEAPONS/8022F3E8_3.H"
#include "WEAPONS/GAME_SESSION.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"

/* Checks accumulated opponent scores and updates the completion flag. */






extern int func_8022A5A0_de(Root *,ObjRecAt16E0V1 *);

/* Reports whether a team's points reached the point target (none when it is 0); in a trial it records
   in humanWon whether that team is the human side's and, when it is not, keeps looking. */


/* Ends a match when its conditions are met, unless a menu or pause is up (func_80245784_de,
   func_80245798_de), the match is locked at 0x1C of the rules D_801468A0 or the game D_8014561C disallows
   it at 0xCC9: outside a cutscene (func_80442A28_de) the time limit at 0x14 of the rules counts down by
   the frame time while func_8022C650_de says the clock runs and ends the match when it expires (clearing
   humanWon at 0xA8 of the rules in trial kind 3); outside a cutscene a score limit reached through func_80228070_de
   ends it while the rules' limit at 0x18 is set and 0x54 is clear; and when D_80146938 asks, it counts
   the active players among the first eight and how many of them are out, ending the match once all
   are out, directly or, when a mode 14 player takes part, only after the rules' round count at 0x9C
   reaches 3, marking humanWon. */
















extern s32 func_80245798_de(void);

extern s32 func_80442A28_de(GameSession *);

extern s32 func_8022C650_de(World_func_802283B8_de *);

extern void func_8022A748_de(World_func_802283B8_de *);

extern s32 func_80228070_de(World_func_802283B8_de *);

static inline SharedPlayerRecV2 *player_at(World_func_802283B8_de *world, u32 index) {
    SharedPlayerRecV2 *player;
    s32 count;

    player = 0;
    count = 0;
    if (index < 8U) {
        player = world->players;
        if (player != 0) {
            do {
                if (count == (s32) index) {
                    return player;
                }
                player = player->views16E0.view16E0_2.next;
                count += 1;
            } while (player != 0);
        }
    }
    return player;
}

extern s32 D_8014687C;

extern void *func_8025CC6C_de(void);

extern s32 func_8025CA24_de(void *, void *);

extern void func_8024BE3C_de(void *arg0);

extern void func_80246E44_de(char *);





extern void func_8024ADD0_de(void *arg0, CVector3 *arg1, s32 arg2);

extern void func_80253754_de(s32 arg0, s32 arg1);

/* Draws the per-player overlays for one view between func_8026D980_de and func_8026D9D0_de: for each player
   in the list from 0x20 it draws the scope model 0xC84 or 0xC85 (by the zoom mode at 0x120C) at the
   player's view matrix while zoomed in at 0x11FC, the player's display through func_8022F770_de when it
   belongs to this view and is enabled at 0x1210, and in team games (0x24 or 0x78 of D_801468A0) a
   teammate marker through func_80229D28_de for every other player on the viewing player's team. */





extern void *func_802392EC_de(s32);

extern s32 func_8028B21C_de(struct Shared_World *, s32);

extern void *func_8028C198_de(char *, s32);

extern void func_8026DF30_de(void *, void *, char *, s32, s32);


extern void func_80229D28_de(void *);

extern HudGlobals D_801462DE;
extern GameSession D_8014561C;
extern GameRules D_801468A0[];


extern s32 D_800CD730;

extern s32 D_80140FF8;








s32 func_802281F0_de(Root *root) {
    GameRules *initial=D_801468A0; GameRules *state;
 ObjRecAt16E0V1 *node; int i,sum,skip; unsigned char *settings;
 if(initial->totalScoreTarget==0) return 0;
 node=root->unk20; state=initial;
 if(node) { settings=(unsigned char *)state-0x5D8; }
 for(;node;node=node->unk16E0) {
  skip=func_8022A5A0_de(root,node);
  sum=0;
  for(i=0;i<8;i++) {
   if(i!=skip) {
    sum+=node->unk5D8->score[i];
    if(sum>=state->totalScoreTarget) {
     { unsigned char trialKind=settings[0xD]; if(trialKind) {
      if(node->unk5D4<4) {state->humanWon=1;return 1;}
      state->humanWon=0;
      if(trialKind==1) continue;
     }
     } return 1;
    }
   }
  }
 }
 return 0;
}

s32 func_802282EC_de(struct World *world) {
    GameRules *target;
    GameRules *rules;
    Settings580 *settings;
    Settings580 *trial;
    s32 humanTeam;
    s32 i;
    s32 team;
    s32 kind;

    target = &D_8014561C.rules;
    if (target->pointTarget == 0) {
        return 0;
    }
    i = 0;
    settings = &D_8014561C.settings;
    humanTeam = 0xFF;
    if (settings->trialKind != 0) {
        for (; settings->roster[i].active == 0; i++) {
        }
        humanTeam = D_8014561C.settings.roster[i].team;
    }
    for (team = 0; team < 5; team++) {
        rules = &D_8014561C.rules;
        if (rules->teamPoints[team] >= rules->pointTarget) {
            if (team == humanTeam) {
                rules->humanWon = 1;
                return 1;
            }
            trial = &D_8014561C.settings;
            kind = trial->trialKind;
            rules->humanWon = 0;
            if (kind == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void func_802283B8_de(World_func_802283B8_de *world) {
    SharedPlayerRecV2 *player;
    GameRules *rules;
    GameSession *game;
    GameRules *limits;
    s32 i;
    s32 active;
    s32 out;
    s32 special;

    if (func_80245784_de() == 0 && func_80245798_de() == 0) {
        rules = &D_8014561C.rules;
        if (rules->locked != 0 || D_8014561C.settings.allowed == 0) {
            return;
        }
        if (func_80442A28_de(&D_8014561C) == 0 && rules->timeLimit > 0.0f && D_8014561C.paused == 0) {
            if (func_8022C650_de(world) != 0) {
                rules->timeLimit -= D_800D2988;
            }
            if (rules->timeLimit <= 0.0f && rules->locked == 0) {
                rules->timeLimit = 0.0f;
                if (D_8014561C.settings.trialKind == 3) {
                    rules->humanWon = 0;
                }
                func_8022A748_de(world);
            }
        }
        game = &D_8014561C;
        if (func_80442A28_de(game) == 0 && func_80228070_de(world) != 0) {
            limits = &game->rules;
            if (limits->locked == 0 && game->paused == 0 && limits->scoreLimit > 0 && limits->sudden == 0) {
                func_8022A748_de(world);
            }
        }
        if (D_80146938 != 0) {
            active = 0;
            out = 0;
            special = 0;
            for (i = 0; i < 8; i++) {
                player = player_at(world, i);
                if (player != 0 && player->views5D8.view5D8_2.controls->display != 0) {
                    active++;
                    if (player->views5E4.view5E4_3.alive == 0) {
                        out++;
                    }
                    if (player->views5D8.view5D8_2.controls->kind == 0xE) {
                        special = 1;
                    }
                }
            }
            if (out == active) {
                if (special) {
                    limits = &D_8014561C.rules;
                    if (limits->rounds >= 3) {
                        limits->humanWon = 1;
                        func_8022A748_de(world);
                    }
                } else {
                    D_80146948 = 1;
                    func_8022A748_de(world);
                }
            }
        }
    }
}

void func_802285E8_de(char *arg0) {
    char *actor;

    if (D_8014687C == 11 || D_8014687C == 8) {
        return;
    }
    actor = ((ObjRecAt20V2 *)(arg0))->unk20;
    while (actor != 0) {
        if (func_80245798_de() != 0 || ((ObjRecV5 *)(actor))->unk5EA == 0) {
            void *work;

            work = func_8025CC6C_de();
            func_8025CA24_de(work, ((ObjRecV5 *)(actor))->unk11BC.v0);
            ((ObjRecV5 *)(actor))->unk11BC.v1 = 0;
            work = func_8025CC6C_de();
            func_8025CA24_de(work, ((ObjRecV5 *)(actor))->unk11C0.v0);
            ((ObjRecV5 *)(actor))->unk11C0.v1 = 0;
        } else if (D_80146894 == 0) {
            void *owner = ((ObjRecV5 *)(actor))->unk5DC;
            s32 blocked;

            if (owner == 0) {
                blocked = 0;
            } else {
                blocked = ((View *)(owner))->unk564 != 0;
            }
            if (blocked == 0) {
                Block *base;
                s32 old_value;
                s32 new_value;
                f32 saved_value;

                base = &((ObjRecV5 *)(actor))->unk2E8;
                old_value = ((ActorRecAt86C *)actor)->value86C;
                saved_value = D_800D2988;
                ((ActorRecAt86C *)actor)->flags |= 0x200;
                base->value = 0x10;
                base->flags &= 0xFFFDFFFF;
                func_8024BE3C_de(base);
                if (((ObjRecV5 *)(actor))->unk11D8 <= 0.0f) {
                    func_80246E44_de((char *)base);
                }
                new_value = ((ObjRecV5 *)(actor))->unk86C;
                D_800D2988 = saved_value;
                if (old_value != new_value) {
                    ((ObjRecV5 *)(actor))->unk10E = 0;
                }
                ((ObjRecV6 *)(actor))->unk2F0 = ((ObjRecV5 *)(actor))->unk8;
                ((ObjRecV6 *)(actor))->unk354 = ((ObjRecV5 *)(actor))->unk6C;
                ((ObjRecV6 *)(actor))->unk2FC = ((ObjRecV5 *)(actor))->unk14;
                ((ObjRecV6 *)(actor))->unk344 = ((ObjRecV5 *)(actor))->unk5C;
                ((ObjRecV6 *)(actor))->unk3E8 &= ~0x200;
            }
        }
        actor = ((ObjRecV5 *)(actor))->unk16E0;
    }
}

void func_80228798_de(void *arg0, void *view) {
    void *node;

    node = ((func_80228774_S1 *)(arg0))->unk20;
    if (node != 0) {
        do {
            void *owner;

            owner = ((ObjRecAt16E0V2 *)(node))->unk5DC;
            if (owner != 0) {
                if (owner == view) {
                    void *actor;

                    actor = &((ObjRecAt16E0V2 *)(node))->unk2E8;
                    if (((func_80207B5C_S2 *)(owner))->unk24 == 0) {
                        if (((ObjRecAt1D8V3 *)(actor))->unk100 & 0x40000) {
                            void *resource;

                            resource = func_8025193C_de(
                                0, ((ObjRecAt1D8V3 *)(actor))->unkC4,
                                ((ObjRecAt1D8V3 *)(actor))->unkC4,
                                ((ObjRecAt1D8V3 *)(actor))->unkD0,
                                4, 0, 0, &D_800C2BC0_de, 1);
                            if (resource != 0) {
                                void *linked;
                                void *temp;

                                linked = ((ObjRecAt1D8V3 *)(actor))->unk1D8;
                                func_8024B4F4_de(actor, (s32)func_8028FDB4_de(*(void **)resource, 0));
                                temp = ((func_80228774_S5 *)(linked))->unk5DC;
                                if (temp != 0) {
                                    CVector3 delta;

                                    delta.x = ((ObjRecAt128 *)(temp))->unk128 -
                                              ((ObjRecAt1D8V3 *)(actor))->unk8;
                                    delta.y = 0.0f;
                                    delta.z = ((ObjRecAt130 *)(((func_80228774_S5 *)(linked))->unk5DC))->unk130 -
                                              ((ObjRecAt1D8V3 *)(actor))->unk10;
                                    func_8024ADD0_de(actor, &delta, 1);
                                }
                                func_80253754_de(0, (s32)resource);
                            }
                        }
                    } else {
                        goto generic;
                    }
                } else if (owner != 0) {
generic:
                    if (((ObjRecAt16E0V2 *)(node))->unk100 & 0x40000) {
                        void *resource;

                        resource = func_8025193C_de(
                            0, ((ObjRecAt16E0V2 *)(node))->unkC4,
                            ((ObjRecAt16E0V2 *)(node))->unkC4,
                            ((ObjRecAt16E0V2 *)(node))->unkD0,
                            4, 0, 0, &D_800C2BC0_de, 1);
                        if (resource != 0) {
                            func_8024B4F4_de(node, (s32)func_8028FDB4_de(*(void **)resource, 0));
                            func_80253754_de(0, (s32)resource);
                        }
                    }
                }
            }
            node = ((ObjRecAt16E0V2 *)(node))->unk16E0;
        } while (node != 0);
    }
}

void func_80228958_de(ObjRecAt20V2 *game, s32 view) {
    char *player;
    GameRules *match;
    s32 team;
    s32 zoomed;
    s32 model;

    match = D_801468A0;
    team = -1;
    if (match->teams != 0 || match->teamRule != 0) {
        team = ((struct Record *) ((struct OwnerRecAt5D8V2 *) func_802392EC_de(view))->settings)->team;
    }
    func_8026D980_de();
    for (player = game->unk20; player != 0; player = ((ObjectLinks16E4 *)(player))->unk_16E0) {
        zoomed = 0;
        if (((ObjectLinks16E4 *)(player))->unk_11FC > 0.0f) {
            zoomed = 1;
        }
        if (zoomed) {
            if (((ObjectLinks16E4 *)(player))->unk_120C != 0) {
                model = func_8028B21C_de(&D_8011FE88, 0xC84);
            } else {
                model = func_8028B21C_de(&D_8011FE88, 0xC85);
            }
            if (model != -1) {
                func_8026DF30_de(func_8028C198_de(&D_8011FE88, model), player + 0x1600, &D_800D0EF8, 0, -1);
            }
        }
        if (((ObjectLinks16E4 *)(player))->unk_5DC != 0 && ((ObjectLinks16E4 *)(player))->unk_1210 != 0 && ((ObjectLinks16E4 *)(player))->unk_5DC == view) {
            func_8022F770_de(player + 0x2E8, (char *)player + 0x458);
        }
        if ((D_801468A0->teams != 0 || D_801468A0->teamRule != 0)
            && ((struct Record *) ((ObjectLinks16E4 *) player)->unk_5D8)->team == team && func_802392EC_de(view) != player) {
            func_80229D28_de(player);
        }
    }
    func_8026D9D0_de();
}

void func_80228AF4_de(void *arg0, ViewState *viewState) {
    f32 x;
    f32 y;
    f32 center_x;
    f32 center_y;
    f32 scale_x;
    f32 scale_y;
    f32 position;
    HudGlobals *hud;

    if (func_80245784_de() != 0) {
        return;
    }
    if (func_80245798_de() != 0) {
        return;
    }
    hud = &D_801462DE;
    func_802A9234_de(hud->fade);
    if (((HudState *)&hud->state)->timer <= 0.0f) {
        return;
    }

    position = ((HudState *)&hud->state)->timer * D_800C2BDC_de;
    x = (f32)(s32)(position * D_800C2BE0_de);
    scale_x = viewState->width / (f32)D_800E28D0;
    position -= x * ((D_800C7470_Pair *)&D_800C2BE0_de)->second;
    scale_y = viewState->height / (f32)((struct IntPair *)&D_800E28D0)->field_4;
    if ((x < D_800C2BE8_de) && (position < D_800C2BEC_de) &&
        ((D_800CD730 % 15U) < 5U)) {
        return;
    }

    if (D_80140FF8 == 1) {
        if (D_800E28D8 == 0) {
            center_x = (f32)D_800E28D0 * D_800C2BF0_de;
            scale_x *= D_800C2BF4_de;
            center_y = D_800C2BF8_de[0];
            scale_y *= D_800C2BF4_de;
        } else {
            center_y = D_800C2C00_de[0];
            center_x = (f32)D_800E28D0 * D_800C2BF8_de[1];
        }
    } else {
        center_x = (f32)D_800E28D0 * D_800C2C00_de[1];
        center_y = (f32)(((struct IntPair *)&D_800E28D0)->field_4 - 10) * D_800C2C00_de[1];
    }

    func_802A822C_de((s32)x, center_x - (scale_x * D_800C2C08_de),
                   center_y, scale_x, scale_y, 1, 1, 0);
    func_802A822C_de((s32)position, center_x + (2.0f * scale_x),
                   center_y, scale_x, scale_y, 1, 0, 2);
    func_802A84F8_de();
    func_802A8F28_de(&D_800C2BD8_de,
                  (s32)(center_x - (scale_x * ((D_800C7470_Pair *)&D_800C2C08_de)->second)),
                  (s32)(center_y - (scale_y * D_800C2C10_de[0])),
                  0xFF, 0, 0, scale_x, scale_y);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#define EUF(p, t, o) (*(t *)((u8 *)(p) + (o)))
extern f32 D_800C2EB4_eu;
extern void func_8025DF34_de(s32), Camera_PostScreenMessage(void *, void *, void *);
extern void func_80273198_de(void *, void *), func_80271F34_de(void *, void *, void *);
extern void func_80273448_de(void *, f32, f32, f32), func_80273D6C_de(void *), func_8027027C_de(void *, void *);
/* Pulse of the player's ring effect: with the timer at 0x11FC running it only plays sound 0x578 and re-shows the text of the
   active language, otherwise it rebuilds the ring matrix at 0x1600 from the vectors at 0x1458/0x1470/0x1200 first. */
void func_80228E60_eu(u8 *player, s32 flag) {
    u8 mtx[0x40];
    f32 vec[3];
    void *ui;
    char *text;

    if (EUF(player, s32, 0x147C) == 0) {
        return;
    }
    if (EUF(player, f32, 0x11FC) > 0.0f) {
        EUF(player, f32, 0x11FC) = 0.0f;
        func_8025DF34_de(0x578);
        ui = EUF(player, void *, 0x5DC);
        if (ui == 0) {
            return;
        }
        text = D_800E0EC4[((u8 *)&D_80145088)[0x17C1]];
    } else {
        EUF(player, s32, 0x1200) = EUF(player, s32, 0x1458);
        EUF(player, s32, 0x1204) = EUF(player, s32, 0x145C);
        EUF(player, s32, 0x1208) = EUF(player, s32, 0x1460);
        EUF(player, s32, 0x120C) = flag;
        EUF(player, f32, 0x11FC) = D_800C2EB4_eu;
        func_80273198_de(mtx, player + 0x1470);
        func_80271F9C_de((void *)vec, (void *)(player + 0x1470), 5.12f);
        func_80271F34_de(vec, vec, player + 0x1200);
        func_80273448_de(mtx, vec[0], vec[1], vec[2]);
        func_80273D6C_de(mtx);
        func_8027027C_de(mtx, player + 0x1600);
        func_8025DF34_de(0x578);
        ui = EUF(player, void *, 0x5DC);
        if (ui == 0) {
            return;
        }
        text = flag ? D_800E0ED4[((u8 *)&D_80145088)[0x17C1]] : D_800E0EE4[((u8 *)&D_80145088)[0x17C1]];
    }
    Camera_PostScreenMessage(&D_80145088, ui, text);
}
#else
INCLUDE_ASM("span_1000", func_80228E60_eu);
#endif
#endif
