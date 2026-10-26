#include "COMMON/ACTORRECAT260.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "sdk/PFS/80443868_2.H"
#include "GFX/TEXT/802A8A94_5.H"

extern void Ovlgame_PlacePlayerForRound(void *player);
/* Forwards arg1's word at 0x1C to Ovlgame_PlacePlayerForRound and always reports success. */



/* Pulses the caption intensity on a 512-step triangle wave and redraws the caption sprite centred on the entry, dropped one full line or a short line when the wide-layout flag is clear. */



/* When team sync is enabled, copies a player's team flag from its actor (byte 0x8F of the record at
   0x5D8) into D_801468A0 if it is 1; then resumes the script D_8011FAC0 through Ovlgame_ResetMatchControllerState in mode
   1 or else clears the actor's word at 0x5D0; returns 1. Matched through a local pointer to
   D_801468A0 and the team byte held in a local. */










#include "COMMON/GAME_SESSION.H"

extern void Ovlgame_ResetMatchControllerState(char *);

/* Advances the actor inactivity timer and reports pending menu state. */
s32 func_8022B178_de(void *);

 /* extern */


/* Points a field's text at D_800D7BE8 when the option D_801468F4 is set and at D_800D7BE4 otherwise, and returns
   zero: the label an option menu shows for that option. */





/* Sets the byte at offset 0x8E of the object reached through offset 0x1C of the second argument
   and then offset 0x5D8, and returns one. */






s32 Items_SetNestedItemFlag(void *unused, struct RootRecAt1C *root) {
    root->middle->leaf->flag = 1;
    return 1;
}

s32 Items_RespawnItemPlayer(void *unused0, StateRecAt1C *arg1) {
    Ovlgame_PlacePlayerForRound(arg1->unk1C);
    return 1;
}

void Items_DrawPulsingMenuSprite(ObjRecAt1CV1 *arg0, CaptionEntry *arg1, s32 arg2, MenuStyle *arg3) {
    s32 phase;
    s32 amount;
    s32 half;
    s32 drop;
    f32 scale;
    f32 sx;
    phase = arg0->unk1C = (arg0->unk1C + 0x14) % 512;
    if (phase >= 0x100) {
        amount = (s32) ((f32) (0x200 - phase) * arg3->alpha * arg3->fade);
    } else {
        amount = (s32) ((f32) phase * arg3->alpha * arg3->fade);
    }
    OnScreen_SetupSpriteMode(amount);
    drop = 0x50;
    half = arg1->width >> 1;
    if (D_800E28D8 == 0) {
        drop = 0x2D;
    }
    sx = arg1->scaleX;
    scale = *(&D_800DE740 + 1);
    OnScreen_DrawSpriteResource(arg0->unk14, 0, arg1->x - (half * 8), arg1->y + drop,
                  sx * scale, arg1->scaleY * scale, 1);
}

int Items_ResumePlayerFromMenu(int unused, PlayerRecAt1C *player) {
    CGameStatus *sync = &D_801462C8.counters;
    int team;

    if (sync->m_bFragTagOn != 0) {
        team = player->actor->info->unk8F;
        if (team == 1) {
            sync->m_FragTagMode = team;
        }
    }
    if (D_80145070 == 1) {
        Ovlgame_ResetMatchControllerState(&D_8011FAC0);
    } else {
        player->actor->waiting = 0;
    }
    return 1;
}

s32 Items_UpdatePlayerRespawnDelay(StateRecAt1C *arg0) {
    CGameStatus *state;
    s32 temp_v0;
    s32 var_v0;
    ActorCode80443868804438BC *temp_s0;
    temp_s0 = arg0->unk1C;
    if ((temp_s0->unk1450 == 0) && (func_8022B178_de(temp_s0) != 0)) {
        temp_v0 = temp_s0->unk1340 + 1;
        temp_s0->unk1340 = temp_v0;
        if (temp_v0 >= 0x4C) {
            Ovlgame_PlacePlayerForRound(arg0->unk1C);
            return 1;
        }
    }
    var_v0 = 0;
    state = &D_801462C8.counters;
    if (state->round || state->elapsed || state->state) var_v0 = 1;
    return var_v0;
}

s32 Items_SelectFragTagLabel(struct FieldRecAt14 *field) {
    if (D_801462C8.counters.m_bFragTagOn != 0) {
        field->text = D_800D7BE8;
    } else {
        field->text = D_800D7BE4;
    }
    return 0;
}
