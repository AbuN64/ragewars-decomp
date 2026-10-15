#include "shared/func_80286080_de_closed.h"
#include "span_C76B0/data.h"

#include "common/unused.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "types.h"
#include "span_16E000/code_80423280.h"
/* Writes the heading of the results screen D_800E4690 into item 0x153: in one-player mode the
   label 0x69 followed by the name of the character in the player's status record; in three-player
   mode the label 0x3D with the stage's best time as minutes and seconds in item 0x156 (the record's
   time when set, else the stage default from func_80425C70_de) and the heading D_800D34DC; in
   four-player mode the heading D_800D34D8. */

/* The results screen item and phrase ids renumber on the de cartridge: its heading item is 0x151,
   its name phrase 0x6B, its time phrase 0x3F and its time item 0x154. eu and eu-x use heading
   strings this unit cannot name, so those cartridges keep their own screen code. */
#if defined(VERSION_DE)
enum { HEADING_ITEM = 0x151, NAME_PHRASE = 0x6B, TIME_PHRASE = 0x3F, TIME_ITEM = 0x154 };
#else
enum { HEADING_ITEM = 0x153, NAME_PHRASE = 0x69, TIME_PHRASE = 0x3D, TIME_ITEM = 0x156 };
#endif

extern struct ResultsHeadingScreen *D_800E4690;
extern struct ResultsHeadingRecord D_80102B00[];
extern struct ResultsHeadingCharacter D_800DFA6C[];

extern void func_802A025C_de(char *, char *);
extern s32 func_8041F140_de(s32);
extern void func_802A0C08_de(char *, char *, ...);
extern struct ResultsHeadingStage *func_80425C70_de(s32, s32, s32);

void func_80427B08_de(void) {
    Shared_Game *settings;
    struct Label *item;
    s32 time;
    u8 best;
    char buffer[32];

    /* the hub lookup returns its Item view; the Label view names the text pointer this unit writes */
    ((struct Label *) func_8040EC30_de(D_800E4690->window, HEADING_ITEM))->text = D_800E4690->heading;
    settings = &D_801462C8;
    switch (settings->controllerMode) {
    case 1:
        func_802A025C_de(D_800E4690->heading, func_80411D78_de(NAME_PHRASE));
        func_8042E9B4_de(D_800E4690->heading, D_800DD9BC,
                      D_800DFA6C[func_8041F140_de(settings->playerSettings[D_800E4690->record].character)].name->text);
        break;
    case 3:
        func_802A025C_de(D_800E4690->time, func_80411D78_de(TIME_PHRASE));
        item = (struct Label *) func_8040EC30_de(D_800E4690->window, TIME_ITEM);
        func_8040E8D8_de(item, 1);
        item->text = D_800E4690->time;
        time = D_80102B00[D_800E4690->record].times[D_800E4690->stage];
        if (time > 0) {
            func_802A0C08_de(buffer, D_800DD9C8, time / 60, time % 60);
        } else {
            best = func_80425C70_de(D_800E4690->stage, 3, 0)->time;
            func_802A0C08_de(buffer, D_800DD9C8, (u8)(best / 60), (u8)(best % 60));
        }
        func_8042E9B4_de(D_800E4690->time, D_800DD9D0_de, buffer);
        func_802A025C_de(D_800E4690->heading, D_800D34DC);
        break;
    case 4:
        func_802A025C_de(D_800E4690->heading, D_800D34D8);
        break;
    }
}
