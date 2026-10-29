#include "include_asm.h"
#include "COMMON/OWNERRECAT8V2.H"
#include "ANIM/COLLISION_EMPTYEUXHOOK.H"

/* 8023A284_30.CPP */
#if defined(VERSION_DE)
unsigned char g_AcceptsTrailingBytes[8] = { 0x3C, 0x01, 0x80, 0x10, 0xAC, 0x22, 0xFF, 0xCC };
#endif

/* 8023CFB0.CPP */
#if defined(VERSION_US)
void Collision_EmptyUsHook(void) {}
#endif

#if defined(VERSION_US)
char k_AcceptsEncodedBytes[8] =
    "lerl\000\000\000\224";
#endif

/* 8023CFB0_2.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void Collision_EmptyEuXHook(void) { }
#endif

/* 8023CFB0_4.CPP */
#if defined(VERSION_EU)
/** Perform no operation. */
void Collision_EmptyEuHook(void) {
}
#endif
