#ifndef RW_PAK_LOAD_H
#define RW_PAK_LOAD_H
#include "span_16E000/code_80405454.h"
#include "shared/pak_menu.h"
#include "shared/func_804235A8_eu_layout.h"
extern struct Saved D_80153738;
extern Shared_MenuData D_80145040;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern struct Saved D_8015D488;
extern char *D_800E25A4[], *D_800E25B4[], *D_800E25C4[], *D_800E25D4[], *D_800E27B4[];
extern u8 *D_800E2994[];
extern struct List_func_80442574_de D_0044F954, D_0044F978, D_0044FAE0_eu, D_0044FB04, D_0044FB28, D_004501E8;
static __inline__ char *rw_pak_profile_name(Shared_Game *settings) { return D_800E25A4[settings->language]; }
static __inline__ char *rw_pak_block_name(Shared_Game *settings) { return D_800E25B4[settings->language]; }
static __inline__ char *rw_pak_company(Shared_Game *settings) { return D_800E25C4[settings->language]; }
static __inline__ char *rw_pak_game_code(Shared_Game *settings) { return D_800E25D4[settings->language]; }
static __inline__ char *rw_pak_invalid_name(Shared_Game *settings) { return D_800E27B4[settings->language]; }
static __inline__ u8 *rw_pak_note_text(Shared_Game *settings) { return D_800E2994[settings->language]; }
static __inline__ struct List_func_80442574_de *rw_pak_loaded_block_dialog(void) { return &D_0044F954; }
static __inline__ struct List_func_80442574_de *rw_pak_selected_block_dialog(void) { return &D_0044F978; }
static __inline__ struct List_func_80442574_de *rw_pak_loaded_profile_dialog(void) { return &D_0044FAE0_eu; }
static __inline__ struct List_func_80442574_de *rw_pak_selected_profile_dialog(void) { return &D_0044FB04; }
static __inline__ struct List_func_80442574_de *rw_pak_other_note_dialog(void) { return &D_0044FB28; }
static __inline__ struct List_func_80442574_de *rw_pak_load_error_dialog(void) { return &D_004501E8; }
static __inline__ struct Saved *rw_pak_loaded_profile(void) { return &D_8015D488; }
#else
extern struct Saved D_8014D488;
extern char *D_800D36D4, *D_800D36D8, *D_800D36E0, *D_800D3758;
extern u8 *D_800D37D0, *D_800D36DC;
extern struct List_func_80442574_de D_0044E684, D_0044E6A8, D_0044E810, D_0044E834, D_0044E858, D_0044EF18;
static __inline__ char *rw_pak_profile_name(Shared_Game *settings) { return D_800D36D4; }
static __inline__ char *rw_pak_block_name(Shared_Game *settings) { return D_800D36D8; }
static __inline__ char *rw_pak_company(Shared_Game *settings) { return (char *)D_800D36DC; }
static __inline__ char *rw_pak_game_code(Shared_Game *settings) { return D_800D36E0; }
static __inline__ char *rw_pak_invalid_name(Shared_Game *settings) { return D_800D3758; }
static __inline__ u8 *rw_pak_note_text(Shared_Game *settings) { return D_800D37D0; }
static __inline__ struct List_func_80442574_de *rw_pak_loaded_block_dialog(void) { return &D_0044E684; }
static __inline__ struct List_func_80442574_de *rw_pak_selected_block_dialog(void) { return &D_0044E6A8; }
static __inline__ struct List_func_80442574_de *rw_pak_loaded_profile_dialog(void) { return &D_0044E810; }
static __inline__ struct List_func_80442574_de *rw_pak_selected_profile_dialog(void) { return &D_0044E834; }
static __inline__ struct List_func_80442574_de *rw_pak_other_note_dialog(void) { return &D_0044E858; }
static __inline__ struct List_func_80442574_de *rw_pak_load_error_dialog(void) { return &D_0044EF18; }
static __inline__ struct Saved *rw_pak_loaded_profile(void) { return &D_8014D488; }
#endif
#endif
