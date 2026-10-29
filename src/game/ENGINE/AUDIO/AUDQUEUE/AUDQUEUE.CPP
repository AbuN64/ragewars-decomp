#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LISTNODE.H"
#include "AUDIO/AUDIO_INSERTCHANNELLINK.H"

void Audio_InsertChannelLink(void **listHead, Field_void_4 *channelLink) {
    *(void **)channelLink = *listHead;
    channelLink->value = listHead;
    ((Field_void_4 *)((*listHead)))->value = channelLink;
    *listHead = channelLink;
}
