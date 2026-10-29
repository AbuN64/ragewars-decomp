
#if defined(VERSION_US_REV1)
extern char addrLow_Device_EnableTriggerActor[];
extern char addrLow_Link_ClearActorStateBit[];
unsigned int g_SeqplayerEncodedWordsBlock1[3] = {
    (unsigned int)addrLow_Device_EnableTriggerActor, (unsigned int)addrLow_Link_ClearActorStateBit, 0x00000000,
};
#endif
