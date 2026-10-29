#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"
#include "COMMON/OSTHREAD_S.H"
#include "../../include/libultra/debug/assert.h"

/* 802BFD80.CPP */
#if defined(VERSION_DE)
unsigned char g_AudioAssertTrailingBytes[8] = { 0xAC, 0x82, 0x00, 0x00, 0xAC, 0x82, 0x00, 0x04 };
#endif

/* 802BFD40.CPP */
void __assert(const char *unused0, const char *unused1, s32 unused2) {
}

#if defined(VERSION_US)
char s_AudioAssertRlayTMText[8] =
    "rlay_t\022m";
#endif
