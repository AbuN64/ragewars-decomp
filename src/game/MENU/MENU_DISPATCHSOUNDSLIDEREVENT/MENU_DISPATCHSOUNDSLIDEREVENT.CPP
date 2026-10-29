

/* 8042FBEC_8.CPP */
#if defined(VERSION_EU)
unsigned char g_MenuDispatchsoundslidereventTrailingBytes[4] = { 0x24, 0x05, 0x06, 0x40 };
#endif

/* MenuDispatchSoundSliderEventTrailingWord.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_804396BC_us_rev1_padding_1A76BC */
unsigned int g_MenuDispatchsoundslidereventEncodedWords[1] = {
    0x0C10E784,
};
#endif
