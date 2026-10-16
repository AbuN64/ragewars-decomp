#include "TYPES.H"
#include "span_1000/code_80291054.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_804251F4.h"
#include "shared/func_80425674_de_layout.h"
#include "common/unused.h"
#include "shared/func_8042854C_de_closed.h"
#include "span_16E000/code_8043A0A4.h"
extern s32 func_80265650_de(void *, s32);
extern Preset *func_80425C70_de(s32, s32, s32);
void func_80427F10_de(void) {
    RenderCounters *state;
    Shared_Game *config;
    Preset *preset;
    s32 value, choice, i;
    D_800E4690->selection = D_8015402C;
    if (D_800E4690->selection >= 37) D_800E4690->selection = 0;
    if (func_80265650_de(D_800E4690->owned, D_800E4690->selection) != 0) {
        state = &D_801468A0;
        if (state->humanWon != 0) {
            /* The counters alias Game+0x5D8 in every version. */
            { void *whole = (u8 *)state - 0x5D8; config = whole; }
            switch (config->controllerMode) {
            case 1:
                preset = func_80425C70_de(D_800E4690->selection, 0, config->slots[D_800E4690->player].kind);
                break;
            case 2:
                preset = func_80425C70_de(D_800E4690->selection, 1, 0);
                break;
            case 3:
                preset = func_80425C70_de(D_800E4690->selection, 3, 0);
                break;
            case 4:
                preset = func_80425C70_de(D_800E4690->selection, 2, 0);
                break;
            default:
                preset = func_80425C70_de(D_800E4690->selection, 0, D_80142358[D_800E4690->player * 150]);
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
