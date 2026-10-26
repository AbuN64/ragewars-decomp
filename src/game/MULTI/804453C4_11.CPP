#include "COMMON/MENURECAT20V1.H"
#include "MULTI/804453C4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "MULTI/804453C4_11.H"

#if !(defined(VERSION_US))
/* Deletes the final character of the selected player's text entry: resets its cursor and, when the entry holds characters, decrements the count and length and clears the character at the new end. */







extern TextEntryRecAtC D_800E63C0[];

/* Copies a player label with spaces for empty characters and refreshes the entry. */




#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void func_80442384_de(s32,EntryRecAt1C *,s32), func_80444F30_eu(void *);
#else
extern void func_80442384_de(s32,EntryRecAt1C *,s32), Items_SetDefaultPlayerName(void *);
#endif

extern s32 Player_GetPlayerIndex(void *table, void *player);
extern u8 D_80145040[];
/* Returns 1 when any of the words at 0x28, 0x1C or 0x20 of D_801468A0 is nonzero, else 0. */




s32 func_80445D6C_de(s32 unused, EntryRecAt1C *arg1) {
    s32 i;
    s32 count;

    i = Player_GetPlayerIndex(D_80145040, arg1->unk1C);
    count = D_800E63C0[i].count;
    D_800E63C0[i].cursor = 0;
    if (count == 0) {
        return 0;
    }
    D_800E63C0[i].count = count - 1;
    D_800E63C0[i].length--;
    D_800E63C0[i].text[D_800E63C0[i].length] = 0;
    return 0;
}

s32 func_80445E04_de(s32 arg0, EntryRecAt1C *arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    u8 *var_a2;
    u8 *var_v1;
    u8 var_v0;
    ObjRecAt5D8 *temp_s1;

    temp_s1 = arg1->unk1C;
    temp_v0 = Player_GetPlayerIndex(D_80145040, temp_s1);
    var_a2 = (temp_v0 * 0x18) + D_800E20AC;
    var_v1 = (temp_v0 * 0x96) + (D_80145040 + 0x13DC);
    var_a1 = 0;
    var_a0 = 0;
    do {
        var_v0 = *var_a2;
        var_a2 += 1;
        if (var_v0 == 0) {
            var_v0 = 0x20;
        } else {
            var_a1 += 1;
        }
        *var_v1 = var_v0;
        var_a0 += 1;
        var_v1 += 1;
    } while (var_a0 < 8);
    *var_v1 = 0;
    if (var_a1 == 0) {
        
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_80444F30_eu
#else
Items_SetDefaultPlayerName
#endif
(temp_s1->unk5D8);
    }
    func_80442384_de(arg0, arg1, arg2);
    return 1;
}

s32 func_80445EF4_de(void) {
    CGameStatus *s = &D_801462C8.counters;
    s32 ret;

    ret = 0;
    if (s->round != 0 || s->elapsed != 0 || s->state != 0) {
        ret = 1;
    }
    return ret;
}
#endif
