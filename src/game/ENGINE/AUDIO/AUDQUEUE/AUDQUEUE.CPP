#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LISTNODE.H"
#include "AUDIO/AUDIO_INSERTCHANNELLINK.H"

void Audio_InsertChannelLink(void **arg0, Field_void_4 *arg1) {
    *(void **)arg1 = *arg0;
    arg1->value = arg0;
    ((Field_void_4 *)((*arg0)))->value = arg1;
    *arg0 = arg1;
}
