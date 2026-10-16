#include "span_16E000/menu_ui_providers.h"
#include "shared/world.h"
#include "span_16E000/code_804221A0.h"
#include "types.h"
/* Event callback for the match setup screen D_800E4518: on event 1 with the screen in state 1 it
   advances it, and once it reaches state 2 either goes back (choice 0: resets the mode, shows the
   item and queues sound 0x259 past D_8015402C) or starts the match (choice 1: picks the arena,
   clears the pause word, then either sets the mode from the settings and active human players or
   stops the match objects and calls func_8042DEA0_de). Returns zero. */






extern struct Screen_func_80422960_de *D_800E4518;

extern struct LevelActor *D_800E2830;

extern s32 D_8015402C;




extern s32 func_8043C308_de(struct Screen_func_80422960_de *);
extern void func_8043C080_de(struct Screen_func_80422960_de *);
extern void func_8043C2A4_de(struct Screen_func_80422960_de *);
extern void func_8040C428_de(s32);
extern void func_8040E8D8_de(void *, s32);
extern void func_804030E0_de(s32);
extern void func_8029973C_de(void);
extern s32 func_8025E2C4_de(void);
extern s32 func_802744D4_de(void);

extern void func_802A230C_de(void);
extern void func_8044A370_de(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
extern void func_8042DEA0_de(void);




s32 func_80422960_de(void *item, s32 arg1, s32 event) {
    s32 state;
    s32 humans;
    s32 i;
    Shared_Game *settings;
    u8 *player;
    s32 *pause;

    if (event == 1) {
        state = func_8043C308_de(D_800E4518);
        if (state != event) {
            return 0;
        }
        func_8043C080_de(D_800E4518);
        func_8043C2A4_de(D_800E4518);
        if (func_8043C308_de(D_800E4518) != 2) {
            return 0;
        }
        if (D_800E4518->choice != 0 && D_800E4518->choice != state) {
            return 0;
        }
        if (D_800E4518->choice == 0) {
            func_8040C428_de(0);
            func_8040E8D8_de(item, 1);
            func_804030E0_de(D_8015402C + 0x259);
            D_800E2830->resourceHandle = -1;
            D_800E2830->motionIndex = state;
        } else {
            func_8029973C_de();
            if (D_800E4518->arena == 0 && func_8025E2C4_de() != 0) {
                func_8025E2D4_de(func_802744D4_de() % 4 + 0x38);
            } else {
                func_8025E2D4_de(D_800E4518->arena);
            }
            pause = &D_80145088.status[7];
            *pause = 0;
            if (D_800E4518->mode == -1) {
                humans = 0;
                i = 0;
                player = (u8 *)pause - 0x5CC;
                do {
                    if (((Shared_Game *)player)->playerSettings[i].locked == 0 && ((Shared_Game *)player)->playerSettings[i].enabled == 1) {
                        humans++;
                    }
                    i++;
                } while (i < 4);
                settings = &D_801462C8;
                if (settings->reserved580 == 2 && humans >= 2) {
                    func_8040C428_de(1);
                } else {
                    func_8040C428_de(settings->reserved580);
                }
                func_802A230C_de();
                return 0;
            }
            func_8044A370_de((u8 *)pause - 0x180C, 0);
            func_804499B0_de((u8 *)pause - 0x1854, 0, 0);
            func_80286AA8_de(&D_8011FE88, 0, 0);
            func_8042DEA0_de();
        }
    }
    return 0;
}
