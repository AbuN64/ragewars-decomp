#include "include_asm.h"

/* Menu event handler registry: eleven 12-byte records of {event id, sub id 0x17, handler address
   in the func_8041DFC0-family menu code}, followed by a three-word tail. The handler addresses sit
   in each cartridge's own menu code, so only the tail words are cartridge-stable in some pairs;
   the tail differs per cartridge and the records keep the ids common to all of them. */
#if defined(VERSION_DE)
extern char D_0041DF50[];
extern char D_0041E100[];
extern char D_0041E280[];
extern char D_0041EC84[];
extern char D_0041ECB4[];
extern char D_0041ED78[];
extern char D_0041EDC0[];
extern char D_0041EE08[];
extern char D_0041EED0[];
extern char D_0041EFAC[];
unsigned int D_auto_rodata_unresolved_800E39C4[35] = {
    0x00000E06, 0x00000017, (unsigned int)D_0041DF50, 0x00000E03, 0x00000017, (unsigned int)D_0041EC84, 0x00000E08, 0x00000017,
    (unsigned int)D_0041ECB4, 0x00000002, 0x00000017, (unsigned int)D_0041EDC0, 0x00000001, 0x00000017, (unsigned int)D_0041ED78, 0x00000007,
    0x00000017, (unsigned int)D_0041E100, 0x00000008, 0x00000017, (unsigned int)D_0041E280, 0x00000005, 0x00000017, (unsigned int)D_0041EE08,
    0x00000006, 0x00000017, (unsigned int)D_0041EED0, 0x0000000A, 0x00000017, (unsigned int)D_0041EFAC, 0x00000000, 0x00000000,
    0x00000000, 0x00000023, 0x3E0F5C29,
};
#elif defined(VERSION_EU)
extern char D_0041E3A0[];
extern char D_0041E550[];
extern char D_0041E6E0[];
extern char D_0041F138[];
extern char D_0041F168[];
extern char D_0041F22C[];
extern char D_0041F274[];
extern char D_0041F2BC[];
extern char D_0041F384[];
extern char D_0041F460[];
unsigned int D_auto_rodata_unresolved_800E39C4[35] = {
    0x00000E06, 0x00000017, (unsigned int)D_0041E3A0, 0x00000E03, 0x00000017, (unsigned int)D_0041F138, 0x00000E08, 0x00000017,
    (unsigned int)D_0041F168, 0x00000002, 0x00000017, (unsigned int)D_0041F274, 0x00000001, 0x00000017, (unsigned int)D_0041F22C, 0x00000007,
    0x00000017, (unsigned int)D_0041E550, 0x00000008, 0x00000017, (unsigned int)D_0041E6E0, 0x00000005, 0x00000017, (unsigned int)D_0041F2BC,
    0x00000006, 0x00000017, (unsigned int)D_0041F384, 0x0000000A, 0x00000017, (unsigned int)D_0041F460, 0x00000000, 0x00000000,
    0x00000000, 0x1D800013, 0x4B132F10,
};
#elif defined(VERSION_EU_X)
extern char D_0041E3A0[];
extern char D_0041E550[];
extern char D_0041E6E0[];
extern char D_0041F138[];
extern char D_0041F168[];
extern char D_0041F22C[];
extern char D_0041F274[];
extern char D_0041F2BC[];
extern char D_0041F384[];
extern char D_0041F460[];
unsigned int D_auto_rodata_unresolved_800E39C4[35] = {
    0x00000E06, 0x00000017, (unsigned int)D_0041E3A0, 0x00000E03, 0x00000017, (unsigned int)D_0041F138, 0x00000E08, 0x00000017,
    (unsigned int)D_0041F168, 0x00000002, 0x00000017, (unsigned int)D_0041F274, 0x00000001, 0x00000017, (unsigned int)D_0041F22C, 0x00000007,
    0x00000017, (unsigned int)D_0041E550, 0x00000008, 0x00000017, (unsigned int)D_0041E6E0, 0x00000005, 0x00000017, (unsigned int)D_0041F2BC,
    0x00000006, 0x00000017, (unsigned int)D_0041F384, 0x0000000A, 0x00000017, (unsigned int)D_0041F460, 0x00000000, 0x00000000,
    0x00000000, 0x00000021, 0x0000001F,
};
#elif defined(VERSION_US)
extern char D_0041DFC0[];
extern char D_0041E170[];
extern char D_0041E2F0[];
extern char D_0041ECF4[];
extern char D_0041ED24[];
extern char D_0041EDE8[];
extern char D_0041EE30[];
extern char D_0041EE78[];
extern char D_0041EF40[];
extern char D_0041F01C[];
unsigned int D_auto_rodata_unresolved_800E39C4[35] = {
    0x00000E06, 0x00000017, (unsigned int)D_0041DFC0, 0x00000E03, 0x00000017, (unsigned int)D_0041ECF4, 0x00000E08, 0x00000017,
    (unsigned int)D_0041ED24, 0x00000002, 0x00000017, (unsigned int)D_0041EE30, 0x00000001, 0x00000017, (unsigned int)D_0041EDE8, 0x00000007,
    0x00000017, (unsigned int)D_0041E170, 0x00000008, 0x00000017, (unsigned int)D_0041E2F0, 0x00000005, 0x00000017, (unsigned int)D_0041EE78,
    0x00000006, 0x00000017, (unsigned int)D_0041EF40, 0x0000000A, 0x00000017, (unsigned int)D_0041F01C, 0x00000000, 0x00000000,
    0x00000000, 0x54000004, 0x00000066,
};
#elif defined(VERSION_US_REV1)
extern char D_0041DFC0[];
extern char D_0041E170[];
extern char D_0041E2F0[];
extern char D_0041ECF4[];
extern char D_0041ED24[];
extern char D_0041EDE8[];
extern char D_0041EE30[];
extern char D_0041EE78[];
extern char D_0041EF40[];
extern char D_0041F01C[];
unsigned int D_auto_rodata_unresolved_800E39C4[35] = {
    0x00000E06, 0x00000017, (unsigned int)D_0041DFC0, 0x00000E03, 0x00000017, (unsigned int)D_0041ECF4, 0x00000E08, 0x00000017,
    (unsigned int)D_0041ED24, 0x00000002, 0x00000017, (unsigned int)D_0041EE30, 0x00000001, 0x00000017, (unsigned int)D_0041EDE8, 0x00000007,
    0x00000017, (unsigned int)D_0041E170, 0x00000008, 0x00000017, (unsigned int)D_0041E2F0, 0x00000005, 0x00000017, (unsigned int)D_0041EE78,
    0x00000006, 0x00000017, (unsigned int)D_0041EF40, 0x0000000A, 0x00000017, (unsigned int)D_0041F01C, 0x00000000, 0x00000000,
    0x00000000, 0x00000020, 0x00000193,
};
#endif

#if defined(VERSION_US)
unsigned int data_unresolved_800DE6B0[7] = {
    0x00000092, 0x00000000, 0x00000023, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29,
};
#endif

#if defined(VERSION_EU_X)
unsigned int data_unresolved_800EB230[7] = {
    0x00000096, 0x00000000, 0x00000023, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29,
};
#endif

#if defined(VERSION_EU)
unsigned int data_unresolved_800F0070[7] = {
    0x00000092, 0x00000000, 0x00000023, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29,
};
#endif

#if defined(VERSION_DE)
unsigned int data_unresolved_800DFA00[7] = {
    0x00000090, 0x00000000, 0x00000023, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29, 0x3E0F5C29,
};
#endif
