#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#if defined(VERSION_US_REV1)
/* Selects a field's text according to its type and option byte. */
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
#include "MENU/OPTION_TEXT_TYPE.H"


s32 Ovlgame_SelectToggleRowText(func_8043DD30_S1 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    switch (temp_v0) {
    case 2:
    default:
        if (D_801462C8.menuToggles[0] != 0) {
            arg0->unk14 = &D_800D3D14;
        } else {
            arg0->unk14 = &D_800D3D18;
        }
        break;
    case 3:
        if (D_801462C8.menuToggles[1] != 0) {
            arg0->unk14 = &D_800D3D1C;
        } else {
            arg0->unk14 = &D_800D3D20;
        }
        break;
    case 4:
        if (D_801462C8.menuToggles[2] != 0) {
            arg0->unk14 = &D_800D3D24;
        } else {
            arg0->unk14 = &D_800D3D28;
        }
        break;
    case 5:
        if (D_801462C8.menuToggles[3] != 0) {
            arg0->unk14 = &D_800D3D2C;
        } else {
            arg0->unk14 = &D_800D3D30;
        }
        break;
    case 6:
        if (D_801462C8.menuToggles[4] != 0) {
            arg0->unk14 = &D_800D3D34;
        } else {
            arg0->unk14 = &D_800D3D38;
        }
        break;
    case 7:
        if (D_801462C8.menuToggles[5] != 0) {
            arg0->unk14 = &D_800D3D3C;
        } else {
            arg0->unk14 = &D_800D3D40;
        }
        break;
    case 8:
        if (D_801462C8.menuToggles[6] != 0) {
            arg0->unk14 = &D_800D3D44;
        } else {
            arg0->unk14 = &D_800D3D48;
        }
        break;
    case 9:
        if (D_801462C8.menuToggles[8] != 0) {
            arg0->unk14 = &D_800D3D4C;
        } else {
            arg0->unk14 = &D_800D3D50;
        }
        break;
    }
    return 0;
}
#endif
