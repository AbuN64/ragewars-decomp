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

void func_802183E8_de(s32 menu, s32 arg1, s32 player) {
    Gfx *cmd;

    OnScreen_SetupSpriteMode(0xFF);
    gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP);
    func_80217928_de((CBarrel *)menu, arg1, player);
}

/** Preserve the empty hook at VRAM 0x80218464. */
void func_80218464_de(void) {
}









s32 func_8021846C_de(void *resetTimerStorage, void *resetOwnerStorage) {
    f32 closeDelay;

    closeDelay = ((ResetTimerStorage *)(resetTimerStorage))->unk4;
    if (closeDelay > 0.0f) {
        ((ResetTimerStorage *)(resetTimerStorage))->unk4 = closeDelay - D_800D2988;
        return 0;
    }
    if (((ResetFlagsStorage *)((((ResetOwnerStorage *)(resetOwnerStorage))->unk698)))->unkB0 & 0x8000) {
        return 0;
    }
    ((ResetTimerStorage *)(resetTimerStorage))->unk37C = -1;
    return 1;
}





f32 func_802184C0_de(f32 currentAngle, f32 targetAngle, s32 turnDirection, f32 approachRate) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    GraphU64_WrapPeriodicValue(&currentAngle);
    GraphU64_WrapPeriodicValue(&targetAngle);
    if (turnDirection > 0) {
        if (targetAngle < currentAngle) {
            targetAngle += D_800C2250_de;
        }
    } else if (targetAngle > currentAngle) {
        targetAngle -= D_800C2254_de;
    }
    f3 = targetAngle - currentAngle;
    f1 = f3 * approachRate * D_800D2988;
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
