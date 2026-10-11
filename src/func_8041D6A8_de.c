#include "common/types_1dc8418c21db.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"
/* Fills the player record screen for the selected record D_80102B00[index]: shows the record's
   name in item 0x1F3 and its rank text from func_80424DE8_de in item 0x1F2, and formats into the
   screen's text buffers the record's counters at 0x70, 0x6C and 0x74, the value func_80426004_de
   reports and the byte at 0x17 for items 0x1FD, 0x1F4, 0x1F6, 0x1F9 and 0x1FA, making each item
   visible through func_8040E8D8_de. */

#if defined(VERSION_DE)
enum { PROFILE_RESOURCE_498 = 494, PROFILE_RESOURCE_499 = 495, PROFILE_RESOURCE_500 = 496, PROFILE_RESOURCE_502 = 498, PROFILE_RESOURCE_505 = 501, PROFILE_RESOURCE_506 = 502, PROFILE_RESOURCE_509 = 505 };
#elif defined(VERSION_EU_X)
enum { PROFILE_RESOURCE_498 = 502, PROFILE_RESOURCE_499 = 503, PROFILE_RESOURCE_500 = 504, PROFILE_RESOURCE_502 = 507, PROFILE_RESOURCE_505 = 509, PROFILE_RESOURCE_506 = 511, PROFILE_RESOURCE_509 = 513 };
#else
enum { PROFILE_RESOURCE_498 = 498, PROFILE_RESOURCE_499 = 499, PROFILE_RESOURCE_500 = 500, PROFILE_RESOURCE_502 = 502, PROFILE_RESOURCE_505 = 505, PROFILE_RESOURCE_506 = 506, PROFILE_RESOURCE_509 = 509 };
#endif

/* The hub spells D_800E3590 as the menu block; this unit keeps its ProfileStatisticsScreen view
   because it reads the 0x32-byte text buffers from 0x110 up, which the hub only pads over. */
extern Record_func_80433914_de D_80102B00[];
extern char D_800DD508_de[];
extern char D_800DD50C[];

/* func_8040EC30_de is the hub's Item* lookup; this unit keeps the Label view for its text member. */
extern void func_802A0C08_de(char *, char *, s32);
extern char *func_80424DE8_de(s32);
extern s32 func_80426004_de(s32);

void func_8041D6A8_de(void) {
    Label *item;
    s32 score;

    item = (Label *) func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_499);
    func_8040E8D8_de(item, 1);
    item->text = D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].name;
    item = (Label *) func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_498);
    func_8040E8D8_de(item, 1);
    item->text = func_80424DE8_de(((ProfileStatisticsScreen *) D_800E3590)->index);
    item = (Label *) func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_509);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->kills, D_800DD508_de, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.kills);
    item->text = ((ProfileStatisticsScreen *) D_800E3590)->kills;
    item = (Label *) func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_500);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->wins, D_800DD508_de, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.wins);
    item->text = ((ProfileStatisticsScreen *) D_800E3590)->wins;
    item = (Label *) func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_502);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->deaths, D_800DD508_de, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.deaths);
    item->text = ((ProfileStatisticsScreen *) D_800E3590)->deaths;
    score = func_80426004_de(((ProfileStatisticsScreen *) D_800E3590)->index);
    item = (Label *) func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_505);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->score, D_800DD50C, score);
    item->text = ((ProfileStatisticsScreen *) D_800E3590)->score;
    item = (Label *) func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_506);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->count, D_800DD50C, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].count);
    item->text = ((ProfileStatisticsScreen *) D_800E3590)->count;
}

