

/* 802BFD80_11.CPP */
#if defined(VERSION_EU)
unsigned char g_AudioAssertTrailingBytesBlock1[8] = { 0x08, 0x0A, 0xD8, 0x00, 0xA4, 0x46, 0x00, 0x0A };
#endif

/* AUDIO_ASSERT_RETAINED_INSTRUCTION_WORD.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802B374C_eu_x[1] = { 0x00C08821U };
#endif
