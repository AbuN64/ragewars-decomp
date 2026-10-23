#include "COMMON/EXTERNS_3.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_11.H"
#include "SDK/AUDIO_2/802BF400.H"
#include "sdk/os.h"




extern Field_void_4 *D_800D8440;

void *osViGetCurrentFramebuffer(void) {
    void *result = func_802BCF30_de();
    void *saved = D_800D8440->value;
    __osRestoreInt(result);
    return saved;
}
