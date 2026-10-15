/* Maps an id from 1 to 33 to the address of its data block, returning 0 for any other id. */
#include "types.h"

extern char D_0041C5EC[];
extern char D_0041DF24[];
extern char D_0041F118[];
extern char D_00420E00[];
extern char D_00421A88[];
extern char D_00421E00[];
extern char D_0042247C[];
extern char D_0042359C[];
extern char D_00423930[];
extern char D_00423B88[];
extern char D_00424528[];
extern char D_00429058[];
extern char D_004290E8[];
extern char D_0042931C[];
extern char D_00429B74[];
extern char D_0042BCB0[];
extern char D_0042DB38[];
extern char D_0042DFF0[];
extern char D_00435C54[];
extern char D_00435F70[];
extern char D_0043630C[];
extern char D_00436634[];
extern char D_00436FE4[];
extern char D_00437454[];
extern char D_00437868[];
extern char D_00437B98[];
extern char D_0043905C[];
extern char D_00439390[];
extern char D_0043962C[];
extern char D_00439938[];
extern char D_0043A014[];
extern char D_0043C1D0[];

void *func_8043C500_us_rev1(s32 id) {
    switch (id) {
    case 1:
        return D_00435F70;
    case 31:
        return D_0043630C;
    case 32:
        return D_00436634;
    case 7:
        return D_00420E00;
    case 8:
        return D_0043C1D0;
    case 10:
        return D_00429058;
    case 15:
        return D_004290E8;
    case 3:
        return D_00424528;
    case 4:
        return D_0042359C;
    case 6:
        return D_00439390;
    case 5:
        return D_00436FE4;
    case 11:
        return D_00423930;
    case 12:
        return D_00437454;
    case 13:
        return D_0043962C;
    case 16:
        return D_0041DF24;
    case 17:
        return D_0042DB38;
    case 18:
        return D_0043905C;
    case 9:
        return D_00437868;
    case 30:
        return D_00437B98;
    case 20:
        return D_0042BCB0;
    case 21:
        return D_00429B74;
    case 23:
        return D_0041F118;
    case 14:
        return D_0042931C;
    case 19:
        return D_00435C54;
    case 22:
        return D_00423B88;
    case 24:
        return D_00439938;
    case 25:
        return D_0042247C;
    case 27:
        return D_00421E00;
    case 26:
        return D_0042DFF0;
    case 29:
        return D_0041C5EC;
    case 28:
        return D_00421A88;
    case 33:
        return D_0043A014;
    default:
        return 0;
    }
}
