#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SHAREDPLAYER.H"
#include "MENU/TEAMMENU.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

s32 Cteamselect_TryConfirmTeamChoice(void *menu, void *player) {
    if (((((struct ObjRecAtB0 *) ((s8 *) ((struct ObjectLinks69C *) ((s8 *) player))->unk_698))->unkB0) & 0x8000) && ((((struct Record *) ((s8 *) ((struct ObjectLinks69C *) ((s8 *) player))->unk_5D8))->team) != 0xFF)) {
        (((struct Object6C *) ((s8 *) menu))->value) = -1;
        return 1;
    }
    return 0;
}
extern void Cteamselect_InitTeamChoices(void *arg0, s32 arg1, void *arg2);
extern s32 Cteamselect_GetFourWayStickSlot(void *object);
void Cteamselect_UpdateTeamChoiceInput(char *menu, void *player) {
    s32 flags;
    s32 state;
    s32 result;
    s32 value;
    char *entry;
    flags = ((struct ObjRecAtB0 *) ((ObjectLinks11BC *) player)->unk_698)->unkB0 & 0x8000;
    state = *(s32 *)menu;
    if ((state == 0) || (state == 3)) {
        if ((D_801462C8.counters.teams != 0) &&
            (((struct Record *) ((ObjectLinks11BC *) player)->unk_5D8)->team == 0xFF)) {
            Cteamselect_InitTeamChoices((void *)menu, flags, player);
            *(s32 *)menu = 1;
        } else {
            return;
        }
    }
    ((ObjectLinks11BC *)(player))->unk_670 = D_800C22C8_de;
    ((ObjectLinks11BC *)(player))->unk_11B4 = 1;
    ((ObjectLinks11BC *)(player))->unk_11B8 = 1;
    result = Cteamselect_GetFourWayStickSlot(player);
    if (result != ((IntegerState74 *)(menu))->unk_70) {
        if (result != -1) {
            entry = (char *)menu + result * 0x14;
            value = ((Entry *)(entry))->team;
            if (((Entry *)(entry))->enabled != 0) {
                if ((s16)value < 0) {
                    ((IntegerState74 *)(menu))->unk_70 = -1;
                    return;
                }
                if (result != ((IntegerState74 *)(menu))->unk_6C) {
                    ((IntegerState74 *)(menu))->unk_6C = result;
                }
                ((struct Record *) ((ObjectLinks11BC *) player)->unk_5D8)->team = value;
            } else {
                return;
            }
        }
        ((IntegerState74 *)(menu))->unk_70 = result;
    }
}
