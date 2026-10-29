
#if !(defined(VERSION_EU) || defined(VERSION_US))
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_DE)
unsigned int g_pfsSplitTextJumpWord[1] = { 0x08111B44U };
#elif defined(VERSION_EU_X)
unsigned int g_pfsSplitTextJumpWord[1] = { 0x08107699U };
#elif defined(VERSION_US_REV1)
unsigned int g_pfsSplitTextJumpWord[1] = { 0x081075A5U };
#endif
#endif
