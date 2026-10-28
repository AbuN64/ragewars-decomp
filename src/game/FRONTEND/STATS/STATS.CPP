#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/FRONTEND_ACCUMULATEPLAYERSTATISTICS.H"

extern s8 D_80102B0D[][400];
extern RecRecAt4 g_playerSettings[];

/* Adds the current record's deltas to both running totals of each player still in play, capping each at 99999. */
void Frontend_AccumulatePlayerStatistics(void) {
    s32 i;
    s32 v;
    RecRecAt4 *rec;

    for (i = 0; i < 4; i++) {
        if (D_80102B0D[i][0] >= 0) {
            rec = &g_playerSettings[i];
            v = D_800FEB6C[i][0] + rec->unk4;
            if (v > 99999) {
                D_800FEB6C[i][0] = 99999;
            } else {
                D_800FEB6C[i][0] = v;
            }
            v = D_800FEB74[i][0] + rec->unk2;
            if (v > 99999) {
                D_800FEB74[i][0] = 99999;
            } else {
                D_800FEB74[i][0] = v;
            }
        }
    }
}
