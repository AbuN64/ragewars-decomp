#include "COMMON/GFX.H"
#include "abi.h"
#include "COMMON/VECTOR4F.H"
#include "MENU/TEAMMENU.H"
#include "MENU/RESET_STORAGE.H"
#include "TYPES.H"
#include "gbi.h"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/TRIPLE.H"
#include "MENU/TEAM/80217388_4.H"
#include "MENU/TEAM/80217388_7.H"

/** Reset the weapon menu: closed, no cursor or hover, and its thirty-six slots fanned 30 degrees apart. */
void func_8021836C_de(CBarrel *menu) {
    s32 i;

    menu->m_Mode = 0;
    menu->m_Time = 0;
    menu->m_Alpha = 0;
    menu->m_Rot = 0;
    menu->m_Glow = 0;
    menu->m_Selected = -1;
    menu->m_QuickSelect = 1;
    menu->m_DisplaySlot = -1;
    menu->CurrentWeaponListSize = 0;
    menu->m_UnderwaterWhenSetup = 0;
    menu->m_WheelIndexLastFrame = -1;
    for (i = 0; i < 36; i++) {
        menu->m_WeaponList[i].m_Rot = -(i * D_800C224C_de);
        menu->m_WeaponList[i].m_Spin = 0;
        menu->m_WeaponList[i].m_Scale = D_800C913C_de;
    }
}

void func_802183E8_de(s32 arg0, s32 arg1, s32 arg2) {
    Gfx *cmd;

    Text_SetupSpriteMode(0xFF);
    gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP);
    func_80217928_de((CBarrel *)arg0, arg1, arg2);
}

/** Preserve the empty hook at VRAM 0x80218464. */
void func_80218464_de(void) {
}









s32 func_8021846C_de(void *resetTimerStorage, void *resetOwnerStorage) {
    f32 temp_f1;

    temp_f1 = ((ResetTimerStorage *)(resetTimerStorage))->unk4;
    if (temp_f1 > 0.0f) {
        ((ResetTimerStorage *)(resetTimerStorage))->unk4 = temp_f1 - D_800D2988;
        return 0;
    }
    if (((ResetFlagsStorage *)((((ResetOwnerStorage *)(resetOwnerStorage))->unk698)))->unkB0 & 0x8000) {
        return 0;
    }
    ((ResetTimerStorage *)(resetTimerStorage))->unk37C = -1;
    return 1;
}





f32 func_802184C0_de(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    func_80274020_de(&arg0);
    func_80274020_de(&arg1);
    if (arg2 > 0) {
        if (arg1 < arg0) {
            arg1 += D_800C2250_de;
        }
    } else if (arg1 > arg0) {
        arg1 -= D_800C2254_de;
    }
    f3 = arg1 - arg0;
    f1 = f3 * arg3 * D_800D2988;
    f2 = f1;
    if (f1 < 0.0f) {
        f2 = -f1;
    }
    if (f3 < 0.0f) {
        if (-f3 < f2) {
            goto clamp;
        }
    } else if (f3 < f2) {
clamp:
        f1 = f3;
    }
    return f1;
}
