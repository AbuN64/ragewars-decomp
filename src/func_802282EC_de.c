#include "span_1000/code_80225D10.h"
#include "span_1000/code_80225D10.h"
#include "common/unused.h"
#include "types.h"

/* Reports whether a team's points reached the point target (none when it is 0); in a trial it records
   in humanWon whether that team is the human side's and, when it is not, keeps looking. */
extern Game1330_2 D_8014561C;

s32 func_802282EC_de(struct World *world) {
    RulesAC_2 *target;
    RulesAC_2 *rules;
    Settings580 *settings;
    Settings580 *trial;
    s32 humanTeam;
    s32 i;
    s32 team;
    s32 kind;

    target = &D_8014561C.rules;
    if (target->pointTarget == 0) {
        return 0;
    }
    i = 0;
    settings = &D_8014561C.settings;
    humanTeam = 0xFF;
    if (settings->trialKind != 0) {
        for (; settings->roster[i].active == 0; i++) {
        }
        humanTeam = D_8014561C.settings.roster[i].team;
    }
    for (team = 0; team < 5; team++) {
        rules = &D_8014561C.rules;
        if (rules->teamPoints[team] >= rules->pointTarget) {
            if (team == humanTeam) {
                rules->humanWon = 1;
                return 1;
            }
            trial = &D_8014561C.settings;
            kind = trial->trialKind;
            rules->humanWon = 0;
            if (kind == 0) {
                return 1;
            }
        }
    }
    return 0;
}
