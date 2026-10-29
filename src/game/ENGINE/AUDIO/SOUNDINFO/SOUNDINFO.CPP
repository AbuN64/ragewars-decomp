#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BOX_CONTACT.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SOUNDINFO.H"
#include "COMMON/STREAM.H"
#include "GAME/SOUNDINFO.H"

short SoundInfo_GetGroup(void *soundDescriptor) {
    return ((SoundDescriptor *)soundDescriptor)->group;
}

short SoundInfo_GetSample(void *desc) {
    return ((SoundDescriptor *)desc)->sample;
}

/** Return the signed byte at offset four in the supplied object. */
int SoundInfo_GetPriority(void *object) {
    return ((SoundDescriptor *)object)->priority;
}

/** Return the signed byte at offset five. */
int SoundInfo_GetMode(SoundDescriptor *note) {
    return note->mode;
}

/** Return the signed halfword at offset eight. */
int SoundInfo_GetPitchPresetId_de(char *object) {
    return ((SoundDescriptor *)object)->pitchPresetId;
}

short SoundInfo_GetPreset(void *soundDescriptor) {
    return ((SoundDescriptor *)soundDescriptor)->preset;
}

/** Return the upper two bits of the halfword at object offset 6. */
unsigned int SoundInfo_GetPan(void *soundDescriptor) {
    return ((SoundDescriptor *)soundDescriptor)->flags >> 14;
}

signed char SoundInfo_GetPitch(void *desc) {
    return ((SoundDescriptor *)desc)->pitch;
}

/** Read the signed object byte at offset 0xF. */
signed char SoundInfo_GetByteF_de(void *object) {
    return ((SoundDescriptor *)object)->fieldF;
}

/** Return the signed halfword stored at offset 0x10. */
int SoundInfo_GetYaw(void *object) {
    return ((SoundDescriptor *)object)->yaw;
}

unsigned short SoundInfo_GetFlags(void *soundDescriptor) {
    return ((SoundDescriptor *)soundDescriptor)->flags & 0x3FFF;
}

short SoundInfo_GetX(SoundDescriptor *controller) {
    return controller->x;
}

/** Return the signed halfword at offset 0x14 in the supplied object. */
int SoundInfo_GetY(SoundDescriptor *object) {
    return object->y;
}

/** Return the signed halfword at offset twelve. */
int SoundInfo_GetHalfwordC_de(void *soundDescriptor) {
    return ((SoundDescriptor *)soundDescriptor)->fieldC;
}

#if defined(VERSION_US)
unsigned int func_8025E59C_de_padding_5F148[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int k_SoundinfoEncodedWords[1] = {
    0x00115041,
};
#endif

#if defined(VERSION_EU)
unsigned char g_SoundinfoTrailingBytes[8] = { 0x02, 0x02, 0x80, 0x21, 0x0C, 0x0A, 0xF5, 0x90 };
#endif

