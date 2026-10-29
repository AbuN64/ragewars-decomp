#include "include_asm.h"

/* 800C90C0.CPP */
const unsigned int g_audio_UpdateMusicPlaybackConstantWords[10] = {
    0x3DCCCCCD, 0x3C23D70A, 0x46FFFE00, 0x3C23D70A, 0x3C23D70A, 0x3F333333, 0x46FFFE00, 0x46FFFE00,
    0x3DCCCCCD, 0x42700000,
};

/* 800C90E8.CPP */
/* ROM-grounded data: src/rw_pool_8025D844_C9CE8_us_rev1.c */
const unsigned int g_audio_InitializeMusicPlayerConstantWords[2] = {
    0x3F800000, 0x42FA0000,
};

/* 800C90F0.CPP */
/* ROM-grounded data: src/rw_pool_8025D928_C9CF0_us_rev1.c */
const unsigned int g_audio_UpdateMusicFadeConstantWords[1] = {
    0x3C888889,
};
