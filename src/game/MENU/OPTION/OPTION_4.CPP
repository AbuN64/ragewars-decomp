#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#if defined(VERSION_EU_X)
#include "TYPES.H"
extern char *D_800D3D14;
extern char *D_800D3D18;
extern char *D_800D3D1C;
extern char *D_800D3D20;
extern char *D_800D3D24;
extern char *D_800D3D28;
extern char *D_800D3D2C;
extern char *D_800D3D30;
extern char *D_800D3D34;
extern char *D_800D3D38;
extern char *D_800D3D3C;
extern char *D_800D3D40;
extern char *D_800D3D44;
extern char *D_800D3D48;
extern char *D_800D3D4C;
extern char *D_800D3D50;
/* Picks the label of option row 2..9 from its on/off flag (the eu-x twin of Items_SelectOptionRowLabel, without the language table). */
typedef struct { s32 id; u8 pad4[0x10]; char **text; } OptionRowEux;
s32 Menu_UpdateOptionToggleLabel(OptionRowEux *row) {
    switch (row->id) {
    case 2:
    default:
        if (D_801462C8.menuToggles[0] != 0) {
            row->text = &D_800D3D14;
        } else {
            row->text = &D_800D3D18;
        }
        break;
    case 3:
        if (D_801462C8.menuToggles[1] != 0) {
            row->text = &D_800D3D1C;
        } else {
            row->text = &D_800D3D20;
        }
        break;
    case 4:
        if (D_801462C8.menuToggles[2] != 0) {
            row->text = &D_800D3D24;
        } else {
            row->text = &D_800D3D28;
        }
        break;
    case 5:
        if (D_801462C8.menuToggles[3] != 0) {
            row->text = &D_800D3D2C;
        } else {
            row->text = &D_800D3D30;
        }
        break;
    case 6:
        if (D_801462C8.menuToggles[4] != 0) {
            row->text = &D_800D3D34;
        } else {
            row->text = &D_800D3D38;
        }
        break;
    case 7:
        if (D_801462C8.menuToggles[5] != 0) {
            row->text = &D_800D3D3C;
        } else {
            row->text = &D_800D3D40;
        }
        break;
    case 8:
        if (D_801462C8.menuToggles[6] != 0) {
            row->text = &D_800D3D44;
        } else {
            row->text = &D_800D3D48;
        }
        break;
    case 9:
        if (D_801462C8.menuToggles[8] != 0) {
            row->text = &D_800D3D4C;
        } else {
            row->text = &D_800D3D50;
        }
        break;
    }
    return 0;
}
#endif
