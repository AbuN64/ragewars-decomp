#include "COMMON/FORMAT.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "DATA_OVERLAY_LAYOUTS.H"
#include "TYPES.H"



/* 800C2000.CPP */
#if defined(VERSION_US)
#if defined(VERSION_US)
struct {
    f32 g_patrolGoalArrivalDistance;
    u8 alignmentFill4[12];
    f32 g_objectChaseRouteDistanceLimit;
    f32 g_objectChaseArrivalDistance;
    u8 alignmentFill24[8];
    f32 g_timedJumpRouteArrivalDistance;
    u8 alignmentFill36[12];
} g_NavUpdatepatrolrouteWords2 __attribute__((aligned(4))) = {
    102.399994f,
    { 0x52, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x0, 0x8, 0x0, 0x1c },
    102.399994f,
    51.1999969f,
    { 0x65, 0x72, 0x46, 0x78, 0x5f, 0x74, 0x54, 0x0 },
    102.399994f,
    { 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7 }
};
typedef char g_NavUpdatepatrolrouteWords2SizeCheck[(sizeof(g_NavUpdatepatrolrouteWords2) == 48) ? 1 : -1];
#endif
#endif

/* 800C2374.CPP */
#if defined(VERSION_EU)
#if defined(VERSION_EU)
struct {
    u8 alignmentFill[12];
} g_NavUpdatepatrolrouteWords3 __attribute__((aligned(4))) = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x0B, 0x28, 0x00 }
};
#endif
#endif

/* 802192C0_10.CPP */
#if defined(VERSION_EU_X)
const float g_NavUpdatepatrolrouteWords1[4] = {
    0.05f, 0.3f, -0.7071f, 0.7071f,
};
#endif
