#ifndef RW_PAK_SAVE_TEXT_H
#define RW_PAK_SAVE_TEXT_H
#include "common/types_1dc8418c21db.h"
/* Localized Controller Pak note metadata and result dialog resources. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern struct MenuSettings D_801462C8;
extern char *D_800E25A4[], *D_800E25D4[];
extern char D_0044FC6C[], D_0044FDF8[], D_0044FE88[];
static __inline__ char *rw_pak_save_name(void) { return D_800E25A4[D_801462C8.language]; }
static __inline__ char *rw_pak_save_code(void) { return D_800E25D4[D_801462C8.language]; }
static __inline__ char *rw_pak_no_space_dialog(void) { return D_0044FC6C; }
static __inline__ char *rw_pak_save_success_dialog(void) { return D_0044FDF8; }
static __inline__ char *rw_pak_save_error_dialog(void) { return D_0044FE88; }
#else
extern char *D_800D36D4, *D_800D36E0;
extern char D_0044E99C[], D_0044EB28[], D_0044EBB8[];
static __inline__ char *rw_pak_save_name(void) { return D_800D36D4; }
static __inline__ char *rw_pak_save_code(void) { return D_800D36E0; }
static __inline__ char *rw_pak_no_space_dialog(void) { return D_0044E99C; }
static __inline__ char *rw_pak_save_success_dialog(void) { return D_0044EB28; }
static __inline__ char *rw_pak_save_error_dialog(void) { return D_0044EBB8; }
#endif
#endif
