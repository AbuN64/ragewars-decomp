#include "DATA/REST_SOURCE_RECORDS.H"
extern char __osThreadTail[];
extern char g_audioDiskTransferLinkTable[];

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#ifdef VERSION_DE
RestOsstartthreadEncodedWordsLayout422 k_OsstartthreadEncodedWords = {
    { (void *)&__osThreadTail, (void *)&__osThreadTail, 0, 0 },
    "?s33",
    16.0f,
};
#endif
#ifdef VERSION_EU_X
extern char __osThreadTail[];
void *k_OsstartthreadEncodedWords[6] = {
    __osThreadTail, __osThreadTail, 0, 0,
    0, 0,
};
#endif
#ifdef VERSION_EU
void * k_OsstartthreadEncodedWords[6] = {
    (void *)&__osThreadTail, (void *)&__osThreadTail, 0, 0, (void *)((char *)&g_audioDiskTransferLinkTable + 1748), (void *)((char *)&g_audioDiskTransferLinkTable + 24),
};
#endif
#endif
