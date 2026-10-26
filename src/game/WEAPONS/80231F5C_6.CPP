#include "COMMON/VECTOR4F.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "RENDER_2/8025DE50_5.H"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/** Check whether a human player in mode 1 may select a weapon; when refused play the refusal sound and post a notice. */




extern SettingsE D_801462C8;
extern char D_80102B00[][0x190];

extern int D_800D30BC;
extern int Player_GetProfileAchievementFlag(char *, int);
extern int Weapons_GetPlayerIndex(void *, PlayerRecAt1450V1 *);
extern void Sky_PostTargetedScreenMessage(void *, void *, int, int, float);

int Weapon_CheckSinglePlayerFirePermission(PlayerRecAt1450V1 *player) {
    SettingsE *rules;
    int result;

    if (player->shield > 0.0f) {
        return 0;
    }
    if (player->isBot != 0) {
        return 1;
    }
    rules = &D_801462C8;
    if (rules->players != 1) {
        return 1;
    }
    result = Player_GetProfileAchievementFlag(D_80102B00[player->character], player->weapon);
    if (result == 0) {
        SoundElement_PlayFlatSound(0xD4D);
        if (player->hud != 0) {
            Sky_PostTargetedScreenMessage((char *)rules - 0x1240, player->hud, D_800D30BC,
                          Weapons_GetPlayerIndex((char *)rules - 0x1288, player), D_800C8100);
        }
    }
    return result;
}
#endif
