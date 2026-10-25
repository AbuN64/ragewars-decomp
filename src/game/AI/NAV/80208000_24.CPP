#include "COMMON/ACTORREC.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "AI/NAV/80208000_24.H"

s32 func_8020EA10_de(void **);
s32 func_8020EAB4_de(void **arg0) {
    if (D_801462C8.counters.m_bCTFOn != 0) {
        func_8020EA10_de(arg0);
    }
    return 1;
}
