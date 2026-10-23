#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VIEWFLAGS.H"
#include "CAMERA/80233920.H"

/** Copy the three-word vector at source offset 0x260. */
void *func_802390D0_de(void *destination, void *source) {
    ObjRecAt260 *source_record = source;

    Triple *out = destination;
    *out =
        source_record->unk260;
    return destination;
}
