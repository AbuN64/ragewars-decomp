#include "include_asm.h"
#include "sdk/libgultra.h"
#include "sdk/VOICE_START_AND_PARAMETER_UPDATE_VIEWS.H"

/** Store the supplied halfword at offset 0x16. */
void alSynSetPriority(void *unused, void *object, unsigned short value) {
    AudioVoicePriorityView *record = object;
    record->priority = value;
}

#if defined(VERSION_US)
char s_SynsetpriorityNCurrText[8] =
    "\020m_nCurr";
#endif
