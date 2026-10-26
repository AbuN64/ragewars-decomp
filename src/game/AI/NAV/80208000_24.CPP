#include "COMMON/ACTORREC.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "AI/NAV/80208000_24.H"

s32 Nav_ShouldSeekUnclaimedTeamMarker(void **);
s32 Nav_EvaluateCaptureFlagMarkerSearch(void **arg0) {
    if (D_801462C8.counters.m_bCTFOn != 0) {
        Nav_ShouldSeekUnclaimedTeamMarker(arg0);
    }
    return 1;
}
