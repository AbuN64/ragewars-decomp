#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/UNUSED.H"
#include "AUDIO_4/802BFE60.H"

/** Return the global word at D_800D92A4. */

int func_802BAD70_de(void) {
    return D_800D92A4;
}

extern void *D_800D5270;




/** Return offset 0x14 from the supplied object or the default global object. */
unsigned int func_802BAD80_de(void *object) {
    func_80205494_S3 *object_record;
    if (object == 0) {
        object = D_800D5270;
    }
    object_record = object;
    return object_record->unk14;
}
