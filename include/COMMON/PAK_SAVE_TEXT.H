#ifndef COMMON_PAK_SAVE_TEXT_H
#define COMMON_PAK_SAVE_TEXT_H
#include "COMMON/ITEMRECAT20V1.H"
/* Localized Controller Pak note metadata and result dialog resources. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern struct MenuSettings D_801462C8;
extern char *D_800E25A4[], *D_800E25B4[], *D_800E25D4[];
extern char D_0044FC6C[], D_0044FDF8[], D_0044FE88[];
static __inline__ char *rw_pak_save_name(void) { return D_800E25A4[D_801462C8.language]; }
static __inline__ char *rw_pak_save_code(void) { return D_800E25D4[D_801462C8.language]; }
/* Note titles are indexed through the menu settings view, the game code straight from its table:
 * both shapes are what the PAL save code compiles from (Pak_SaveControllerRecord, Pak_SaveSnapshotAndClose). */
static __inline__ struct MenuSettings *rw_pak_settings(void) { return &D_801462C8; }
#define RW_PAK_RECORD_TITLE (D_800E25A4[rw_pak_settings()->language])
#define RW_PAK_SNAPSHOT_TITLE (D_800E25B4[rw_pak_settings()->language])
#define RW_PAK_GAME_CODE (D_800E25D4[D_801462C8.language])
static __inline__ char *rw_pak_no_space_dialog(void) { return D_0044FC6C; }
static __inline__ char *rw_pak_save_success_dialog(void) { return D_0044FDF8; }
static __inline__ char *rw_pak_save_error_dialog(void) { return D_0044FE88; }
#else
extern char *D_800D36D4, *D_800D36E0;
extern char D_0044E99C[], D_0044EB28[], D_0044EBB8[];
static __inline__ char *rw_pak_save_name(void) { return D_800D36D4; }
static __inline__ char *rw_pak_save_code(void) { return D_800D36E0; }
/* Controller Pak note header strings, four pointers in a row: "RAGE WARS", "TUROK 2", company "51",
 * game code "NRWE". The titles are read as members of this view; a member read through the getter is
 * a cheap reg+offset load that expand_call passes straight into its argument register. */
typedef struct PakNoteHeader {
    char *recordTitle;   /* D_800D36D4 */
    char *snapshotTitle; /* D_800D36D8 */
    char *companyCode;   /* D_800D36DC */
    char *gameCode;      /* D_800D36E0 */
} PakNoteHeader;
static __inline__ PakNoteHeader *rw_pak_note_header(void) { return (PakNoteHeader *)&D_800D36D4; }
#define RW_PAK_RECORD_TITLE (rw_pak_note_header()->recordTitle)
#define RW_PAK_SNAPSHOT_TITLE (rw_pak_note_header()->snapshotTitle)
#define RW_PAK_GAME_CODE (D_800D36E0)
static __inline__ char *rw_pak_no_space_dialog(void) { return D_0044E99C; }
static __inline__ char *rw_pak_save_success_dialog(void) { return D_0044EB28; }
static __inline__ char *rw_pak_save_error_dialog(void) { return D_0044EBB8; }
#endif
#endif
