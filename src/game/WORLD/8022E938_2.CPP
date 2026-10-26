#include "COMMON/RESOURCELOADSTATE.H"
#include "WORLD/8022E938.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"

extern void Player_SetProfileValue14(void *, u8);
extern void Player_SetProfileValue15(void *, u8);
extern void Player_SetProfileValue16(void *, u8);
extern void Player_SetProfileProgress(void *, s32);
extern void Player_SetProfileSlotValue(void *, s32, s32);
extern void Weapons_SetAchievementFlag7(s32, s32);
extern void Weapons_SetAchievementFlag2F(s32, s32);






void Player_InitializeProfile(void *arg0) {
    u8 *object = (u8 *)arg0;
    s32 i;
    u8 *cursor;

    XPlus_FillMemory((s32)object, 0, 8);
    object[0xE] = 0;
    Player_SetProfileValue14(object, 0);
    Player_SetProfileValue15(object, 0);
    Player_SetProfileValue16(object, 0);
    Player_SetProfileProgress(object, 0);
    Player_SetProfileSlotValue(object, 0, 2);
    Player_SetProfileSlotValue(object, 1, 2);
    Player_SetProfileSlotValue(object, 2, 2);
    Player_SetProfileSlotValue(object, 3, 2);
    Player_SetProfileSlotValue(object, 4, 2);
    Player_SetProfileSlotValue(object, 5, 2);
    Player_SetProfileSlotValue(object, 6, 2);
    Player_SetProfileSlotValue(object, 7, 2);
    Player_SetProfileSlotValue(object, 8, 2);
    Player_SetProfileSlotValue(object, 9, 2);
    Player_SetProfileSlotValue(object, 0xA, 2);
    Player_SetProfileSlotValue(object, 0x11, 2);
    Player_SetProfileSlotValue(object, 0x12, 2);
    object[0x17] = 0;
    object[0xF] = 0;
    ((ObjCode8022E938 *)object)->totals[2] = 0;
    ((ObjCode8022E938 *)object)->totals[0] = 0;
    ((ObjCode8022E938 *)object)->totals[1] = 0;
    object[0x25] = 0;
    ((ObjCode8022E938 *)object)->state = 0;
    object[0xC] = 0;
    ((ObjCode8022E938 *)object)->fieldD = -1;
    XPlus_FillMemory((s32)((char *)object + 0x26), 0, 0x24);
    XPlus_FillMemory((s32)((char *)object + 0x7D), 0, 1);
    XPlus_FillMemory((s32)((char *)object + 0x51), 0, 3);
    XPlus_FillMemory((s32)((char *)object + 0x125), 0, 0x64);
    Weapons_SetAchievementFlag7((s32)object, 0);
    Weapons_SetAchievementFlag7((s32)object, 5);
    Weapons_SetAchievementFlag7((s32)object, 7);
    XPlus_FillMemory((s32)((char *)object + 0x57), 0, 0x14);
    XPlus_FillMemory((s32)((char *)object + 0x54), 0, 3);
    XPlus_FillMemory((s32)((char *)object + 0x4A), 0, 7);
    XPlus_FillMemory((s32)((char *)object + 0x78), 0, 1);
    XPlus_FillMemory((s32)((char *)object + 0x79), 0, 2);
    Weapons_SetAchievementFlag2F((s32)object, 0);
    Weapons_SetAchievementFlag2F((s32)object, 2);
    Weapons_SetAchievementFlag2F((s32)object, 3);
    Weapons_SetAchievementFlag2F((s32)object, 4);
    XPlus_FillMemory((s32)((char *)object + 0x7B), 0, 2);
    XPlus_FillMemory((s32)((char *)object + 0x7E), 0, 5);
    XPlus_FillMemory((s32)((char *)object + 0x88), 0, 5);
    XPlus_FillMemory((s32)((char *)object + 0x8D), 0, 5);
    XPlus_FillMemory((s32)((char *)object + 0x83), 0, 5);
    i = 0x23;
    cursor = object + 0x8C;
    do {
        ((ObjCode8022E938 *)object)->counters[i] = 0;
        i--;
        cursor -= 4;
    } while (i >= 0);
    XPlus_FillMemory((s32)((char *)object + 0x124), 0, 1);
    object[0x18A] = 1;
    object[0x18B] = 0x86;
    object[0x189] = 0;
    object[0x18C] = 0x84;
    object[0x18D] = 0;
}
