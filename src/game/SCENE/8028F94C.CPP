#include "include_asm.h"
#include "COMMON/WORLDSORTENTRY.H"
#include "SCENE/8028F94C.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "SDK/AUDIO_2/802BF400.H"
#include "SDK/SCHED/8028DF6C_7.H"
#include "sdk/libgultra/libasm_802BD1A8_3.h"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
/** Return the address 0x78 bytes into the supplied object. */
void *func_8028F94C_de(void *object) {
    ObjRecAt78V2 *record = object;
    return &record->unk78;
}
