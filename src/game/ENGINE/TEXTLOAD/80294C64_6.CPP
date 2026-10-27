#include "COMMON/RESIDENTSTATE.H"
#include "TEXTURE/80294C64_10.H"
#include "TEXTURE/80294C64_6.H"

#if defined(VERSION_US_REV1)
void TextLoad_CloseArtsendTexturePreview(void) { TextLoad_ReleaseArtsendTextureResource(); }
#endif
