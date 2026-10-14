#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042BD40.h"
#include "types.h"
/* Reports why a match ended: time running out on a timed match, the score limit (func_80228070_de),
   the rule set's own target (func_802282EC_de for rule set 0, the Frag Tag limit func_802281F0_de for
   rule set 1), or otherwise whether the last-player-standing check reached its end. */
enum MatchEnd {
    MATCH_END_TIME_UP,
    MATCH_END_SCORE_LIMIT,
    MATCH_END_TAG_LIMIT,
    MATCH_END_POINT_TARGET
};
extern Game_func_8042D060_de D_8014561C;
extern World D_80145040;
extern s32 D_8014DD98;
extern s32 func_80228070_de(World *world);
extern s32 func_802281F0_de(World *world);
extern s32 func_802282EC_de(World *world);
s32 func_8042D060_de(void) {
    SettingsRecAt24 *settings;
    settings = &D_8014561C.settings;
    if (settings->timeSetting > 0 && D_8014561C.rules.timeLeft == 0.0f) {
        return MATCH_END_TIME_UP;
    }
    if (func_80228070_de(&D_80145040) != 0) {
        return MATCH_END_SCORE_LIMIT;
    }
    switch (D_8014DD98) {
    case 0:
        if (func_802282EC_de(&D_80145040) != 0) {
            return MATCH_END_POINT_TARGET;
        }
        break;
    case 1:
        if (func_802281F0_de(&D_80145040) != 0) {
            return MATCH_END_TAG_LIMIT;
        }
        break;
    }
    return D_8014561C.rules.lastStanding == 1;
}
