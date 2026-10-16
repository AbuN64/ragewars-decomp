#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8043E9A8.h"
#include "TYPES.H"

/* Starts a match from the menu: clears byte 0x1D and sets byte 0x1E of D_801462C8, clears the active byte 0x78 of its eight 150-byte status records, then gives the menu at 0x20 the first of the four 0x224-byte controller profiles of D_8010F328 that func_8026437C_de reports active, marking the settings D_80146302 at 0x78 and recording its index in D_801422C1, before calling func_8025E384_de, resetting D_8011FAC0 through func_8044DE7C_de and setting D_80154048. */








extern struct Globals_func_8043EA98_de D_801462C8;
extern struct Part D_80146302;

extern char D_8010F328[];
extern char D_8011FAC0[];
extern s32 D_80154048;

extern s32 func_8026437C_de(char *);
extern void func_8025E384_de(void);
extern void func_8044DE7C_de(char *, s32);

void func_8043EA98_de(void *arg0, struct ObjRecAt20V2 *menu) {
    struct Globals_func_8043EA98_de *globals;
    struct Part *settings;
    char *profile;
    s32 on;
    s32 i;

    globals = &D_801462C8;
    globals->flag1D = 0;
    globals->flag1E = 1;
    for (i = 7; i >= 0; i--) {
        globals->status[i].active = 0;
    }
    i = 0;
    settings = &D_80146302;
    /* FAKEMATCH: constant-holding local places the li */
    on = 1;
    for (profile = D_8010F328; i < 4; i++) {
        if (func_8026437C_de(profile) != 0) {
            settings->active = on;
            D_801422C1 = i;
            menu->unk20 = profile;
            break;
        }
        profile += 0x224;
    }
    func_8025E384_de();
    func_8044DE7C_de(D_8011FAC0, -1);
    D_80154048 = 1;
}
