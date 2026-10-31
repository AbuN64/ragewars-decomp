#include "FRONTEND/JOIN_RANDOMIZEJOINREQUESTENTRIES.H"
#include "COMMON/MENULISTSCREEN.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "SCENE/CACHE_FREEMEMORY.H"
#if defined(VERSION_DE)
enum { MENU_RESOURCE = 908 };
#elif defined(VERSION_EU)
enum { MENU_RESOURCE = 914 };
#elif defined(VERSION_EU_X)
enum { MENU_RESOURCE = 918 };
#elif defined(VERSION_US)
enum { MENU_RESOURCE = 914 };
#elif defined(VERSION_US_REV1)
enum { MENU_RESOURCE = 914 };
#endif
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const float k_joinCycleRankFloatOne[1] = {
    1.0f,
};
#endif
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#endif
