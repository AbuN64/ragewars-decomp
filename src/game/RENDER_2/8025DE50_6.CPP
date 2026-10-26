#include "include_asm.h"
#include "COMMON/STATERECAT34.H"
#include "TYPES.H"
#include "AUDIO_2/802591C0.H"
#include "RENDER_2/8025DE50_6.H"
#include "COMMON/AUDIO_CONTEXT.H"

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_8025E0F4_de);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_8025E110_de);
#endif

#if !(defined(VERSION_DE))

/* Return the existing owner-count result to callers that test it. */
s32 func_8025E0F4_de(s32 owner)
{
    return Audio_CountSoundVoices((char *)&D_8010C080, owner);
}
#endif
