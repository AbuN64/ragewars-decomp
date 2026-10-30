#include "DATA_OVERLAY_LAYOUTS.H"


#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E3A7F_remaining_E4680_unclaimed_E4DAC_unclaimed_E4DBC */
extern char g_characterPreviewTextReferenceShared5[];
void *g_GMenuplayerscissorrectsEncodedWords[1] = {
    (void *)(g_characterPreviewTextReferenceShared5 + 8),
};

#if defined(VERSION_US_REV1)
OverlayScissorRect g_menuPlayerScissorRects[4] = {
    { 18, 15, 52, 94 }, { 232, 15, 267, 94 }, { 18, 128, 52, 206 }, { 232, 128, 267, 206 }
};
#endif
#endif
