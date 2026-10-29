
#if defined(VERSION_US_REV1)
extern char addrLow_Link_DispatchTriggerAudio[];
extern char addrLow_Link_PlayTriggerSoundCallback[];
extern char addrLow_Link_PlayTriggerSound[];
unsigned int g_ResourcesEncodedWordsBlock68[3] = {
    (unsigned int)addrLow_Link_PlayTriggerSoundCallback, (unsigned int)addrLow_Link_PlayTriggerSound, (unsigned int)addrLow_Link_DispatchTriggerAudio,
};
#endif
