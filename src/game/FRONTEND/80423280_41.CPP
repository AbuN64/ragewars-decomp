#include "TYPES.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/RESULTSOPTIONSSCREEN.H"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "ACHIEVE/80424E30_3.H"

extern s32 Defs_TestBit(void *, s32);
void Frontend_SelectSuggestedTrial(void) {
    CGameStatus *state;
    Shared_Game *config;
    Preset *preset;
    s32 value, choice, i;
    D_800E4690->selection = D_8015402C;
    if (D_800E4690->selection >= 37) D_800E4690->selection = 0;
    if (Defs_TestBit(D_800E4690->owned, D_800E4690->selection) != 0) {
        state = &D_801462C8.counters;
        if (state->humanWon != 0) {
            /* The counters alias Game+0x5D8 in every version. */
            { void *whole = (u8 *)state - 0x5D8; config = whole; }
            switch (config->controllerMode) {
            case 1:
                preset = Achieve_CopyPreset(D_800E4690->selection, 0, config->slots[D_800E4690->player].kind);
                break;
            case 2:
                preset = Achieve_CopyPreset(D_800E4690->selection, 1, 0);
                break;
            case 3:
                preset = Achieve_CopyPreset(D_800E4690->selection, 3, 0);
                break;
            case 4:
                preset = Achieve_CopyPreset(D_800E4690->selection, 2, 0);
                break;
            default:
                preset = Achieve_CopyPreset(D_800E4690->selection, 0, D_801462C8.playerSettings[D_800E4690->player].character);
                break;
            }
            choice = 0;
            if ((value = preset->bytes[1]) > 0) {
                choice = value - 1;
            } else {
                for (i = 0; i < 3; i++) {
                    if ((value = (preset->bytes + i)[2]) > 0) {
                        choice = value - 1;
                        break;
                    }
                }
            }
            if (choice >= 37) choice = 0;
            D_800E4690->selection = choice;
        }
    }
}
