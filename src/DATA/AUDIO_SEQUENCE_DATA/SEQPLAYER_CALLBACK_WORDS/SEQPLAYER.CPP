#include "DATA/REST_SOURCE_RECORDS.H"

#if defined(VERSION_US_REV1)
extern char addrLow_Device_EnableTriggerActor[];
extern char addrLow_Link_ClearActorStateBit[];
void * g_SeqplayerEncodedWordsBlock1[3] = {
    (void *)(addrLow_Device_EnableTriggerActor), (void *)(addrLow_Link_ClearActorStateBit), 0,
};
#endif
