#include "TYPES.H"

/* Leading integer word of the target-facing distance limit pair; Playerai_UpdateTargetFacing
   (PLAYERAI_INITIALIZEPLAYERHEALTH.CPP) only reads the f32 1024.0f right after it. */
s32 g_playerTargetFacingDistanceLimitInt = 1024;
