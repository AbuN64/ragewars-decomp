#include "COMMON/WORLD.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"

/* Handles a player's death: stops the body's motion at 0x1C to 0x24 and runs func_8044A07C_de; in a
   single player game (D_801462E5) a player with limited lives at 0x1450 gets the death menu for its
   profile slot 0 to 3 on its view, and when D_80146938 asks and the player is out of a team game, once
   every active player among the first eight is out the team is revived through Ovlgame_PlacePlayerForRound (every
   active player in mode 2 when the mode 14 leader is down, and the leader in modes below 3); in
   multiplayer the view shows the respawn menu, D_45047C when the player has a respawn count at 0x5EA
   or D_450DA8 otherwise. */









extern char D_0044F82C_de;
extern char D_00450178;
extern char D_00450AD0;
extern char D_00450AF4;
extern char D_00450B18;
extern char D_00450B3C;
extern char D_80145040;

extern void Ovlgame_ReleaseObjectHandles(void *);
extern void Pak_OpenDialog(char *, char *, SharedPlayer *, void *, s32);
extern SharedPlayer *Player_GetPlayerByIndex(char *, s32);
extern void Ovlgame_PlacePlayerForRound(SharedPlayer *);

void Player_ResetPlayerAfterDeath(SharedPlayer *player, BodyRecAt1C *body) {
    SharedPlayer *other;
    SharedPlayer *leader;
    s32 i;
    s32 active;
    s32 out;

    body->motion[0] = 0;
    body->motion[1] = 0;
    body->motion[2] = 0;
    Ovlgame_ReleaseObjectHandles(player);
    if (D_801462C8.local != 0) {
        if (player->views1450.view1450_2.infinite == 0) {
            switch (player->views1C.view5D4_46.slot) {
            case 0:
                Pak_OpenDialog(player->views5DC.view5DC_2.view->menu, &D_00450AD0, player, player->views5E8.view698_36.controller, 0);
                break;
            case 1:
                Pak_OpenDialog(player->views5DC.view5DC_2.view->menu, &D_00450AF4, player, player->views5E8.view698_36.controller, 0);
                break;
            case 2:
                Pak_OpenDialog(player->views5DC.view5DC_2.view->menu, &D_00450B18, player, player->views5E8.view698_36.controller, 0);
                break;
            case 3:
                Pak_OpenDialog(player->views5DC.view5DC_2.view->menu, &D_00450B3C, player, player->views5E8.view698_36.controller, 0);
                break;
            }
        }
        if (D_801462C8.counters.enabled != 0 && player->views5D8.view5D8_2.controls->team == 0 && player->views5D8.view5D8_2.controls->active != 0) {
            active = 0;
            out = 0;
            leader = 0;
            for (i = 0; i < 8; i++) {
                other = Player_GetPlayerByIndex(&D_80145040, i);
                if (other != 0) {
                    if (other->views5D8.view5D8_2.controls->active != 0) {
                        active++;
                        if (other->views5E4.view5E4_3.alive == 0) {
                            out++;
                        }
                    }
                    if (other->views5D8.view5D8_2.controls->mode == 0xE) {
                        leader = other;
                    }
                }
            }
            if (out == active) {
                if (D_801462C8.counters.m_nTalsetLives == 2 && leader->views5E4.view5E4_3.alive == 0) {
                    for (i = 0; i < 8; i++) {
                        other = Player_GetPlayerByIndex(&D_80145040, i);
                        if (other != 0 && other->views5D8.view5D8_2.controls->active != 0) {
                            Ovlgame_PlacePlayerForRound(other);
                        }
                    }
                }
                if (D_801462C8.counters.m_nTalsetLives < 3) {
                    Ovlgame_PlacePlayerForRound(leader);
                }
            }
        }
    } else if (player->views5DC.view5DC_2.view != 0) {
        if (player->views5E8.view5EA_3.respawns != 0) {
            Pak_OpenDialog(player->views5DC.view5DC_2.view->menu, &D_0044F82C_de, player, player->views5E8.view698_36.controller, 0);
        } else {
            Pak_OpenDialog(player->views5DC.view5DC_2.view->menu, &D_00450178, player, player->views5E8.view698_36.controller, 0);
        }
    }
}

extern s32 D_800C9FE4;
extern s32 D_800CD6E0_de;
extern void *D_800FE9F0;
extern u8 D_800FEAD8[];


extern char D_0022ECCC;

extern void *Scene_GetModelRecordByIndexPointer(Shared_World *, u16 *);
extern s32 func_80245618_de(s32 arg0, void *arg1, VoidCallback arg2);
extern void *Scene_FindActorDefinition(Shared_World *arg0, s32 arg1, s32 arg2);






void Player_TryStartPlayerSequence(ObjectLinks854 *playerActor, void *arg1, s32 sequenceType)
{
    s32 enabled;
    u32 resource_flags;
    void *resource;
    s32 i;

    enabled = 1;
    resource_flags = 0;

    if (playerActor->unk_14 != 0) {
        resource = Scene_GetModelRecordByIndexPointer(&g_world, playerActor->unk_14);
        if (resource != 0) {
            resource_flags = ((ObjectState108 *)(resource))->resourceFlagBits;
        }
    }

    if (g_world.visibilityEnabled != 0) {
        enabled = 0;
    }
    if (playerActor->unk_664 & 0x8000) {
        enabled = 0;
    }
    if (g_world.visibilityEnabled != 0) {
        enabled = 0;
    }
    if (D_80145048 >= 2) {
        enabled = 0;
    }
    if (sequenceType == 12) {
        enabled = 0;
    }
    if (playerActor->unk_664 & 0x8000) {
        enabled = 0;
    }
    if (resource_flags & 0x1000000) {
        enabled = 0;
    }
    if ((resource_flags & 0x80000) &&
        (sequenceType != 20) && (sequenceType != 40) && (sequenceType != 30)) {
        enabled = 0;
    }

    playerActor->unk_850 = enabled;
    if (enabled != 0) {
        if (sequenceType == 50) {
            void *data;

            data = playerActor->unk_5DC;
            D_800C9FE4 = 1;
            if (data != 0) {
                for (i = 0; i < 4; i++) {
                    D_800FEAD8[i] = ((struct ObjectState521 *) (((u8 *) playerActor->unk_5DC) + i))->unk_520;
                }
            }
        }
        D_800CD6E0_de = 0;
        D_800FE9F0 = playerActor;
        func_80245618_de(sequenceType, 0, (VoidCallback)&D_0022ECCC);
    }

    resource = Scene_FindActorDefinition(&g_world, -1, 0xC45);
    if (resource != 0) {
        playerActor->unk_50 = ((ObjectState108 *)(resource))->unk_FC;
        playerActor->unk_54 = ((ObjectState108 *)(resource))->unk_100;
        playerActor->unk_58 = ((ObjectState108 *)(resource))->unk_104;
    }
}
