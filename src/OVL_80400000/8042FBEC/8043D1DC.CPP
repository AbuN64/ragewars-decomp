#include "common/data.h"
#include "common/reset_storage.h"
#include "TYPES.H"
#include "span_166000/code_8043D1DC.h"

s32 func_8043DCA4_de(ResetFourStorage *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    switch (temp_v0) {
    case 2:
    default:
        if (D_80142235 != 0) {
            arg0->unk14 = &D_800D3D14;
        } else {
            arg0->unk14 = &D_800D3D18;
        }
        break;
    case 3:
        if (D_80142236 != 0) {
            arg0->unk14 = &D_800D3D1C;
        } else {
            arg0->unk14 = &D_800D3D20;
        }
        break;
    case 4:
        if (D_80142237 != 0) {
            arg0->unk14 = &D_800D3D24;
        } else {
            arg0->unk14 = &D_800D3D28;
        }
        break;
    case 5:
        if (D_80142238 != 0) {
            arg0->unk14 = &D_800D3D2C;
        } else {
            arg0->unk14 = &D_800D3D30;
        }
        break;
    case 6:
        if (D_80142239 != 0) {
            arg0->unk14 = &D_800D3D34;
        } else {
            arg0->unk14 = &D_800D3D38;
        }
        break;
    case 7:
        if (D_8014223A != 0) {
            arg0->unk14 = &D_800D3D3C;
        } else {
            arg0->unk14 = &D_800D3D40;
        }
        break;
    case 8:
        if (D_8014223B != 0) {
            arg0->unk14 = &D_800D3D44;
        } else {
            arg0->unk14 = &D_800D3D48;
        }
        break;
    case 9:
        if (D_8014223D != 0) {
            arg0->unk14 = &D_800D3D4C;
        } else {
            arg0->unk14 = &D_800D3D50;
        }
        break;
    }
    return 0;
}
