#ifndef COMMON_RENDERCOUNTERS_H
#define COMMON_RENDERCOUNTERS_H
#include "TYPES.H"
/* The session clock and round counters at D_801468A0. */
typedef struct CGameStatus_t {
    f32 ticks, seconds, m_GameTimeMinutes, m_GameTimeHours; /* +0..+C: func_80293C34_de */
    f32 countdown; /* +0x10: func_8043EE24_de counts it down by D_800D2988 */
    f32 timeLimit;
    s32 mode;
    s32 elapsed;
    s32 state;
    s32 teams;
    s32 round;
    s32 scores[5];
    s32 counts[5];
    s32 m_bFragTagOn;
    s32 m_FragTagLimit; /* +0x58: func_8042ED70_de stores its third argument here */
    s32 unk5C;
    s32 unk60;
    s32 m_FragTagSelectionType; /* +0x64: Render_StartRound stores 3 */
    s32 restrictionActive; /* +0x68 */
    s32 mask;
    s32 teamColour; /* +0x70: lw in func_8022CA14_de, lbu at +0x73 in func_80228FB8_de */
    s32 unk74;
    s32 m_bCTFOn;
    s32 unk7C;
    s32 m_CTFPlayerWithFlag;
    s32 unk84;
    s32 first, second;
    s32 kills; /* +0x90 */
    s32 unk94;
    s32 enabled; /* +0x98 */
    s32 unk9C;
    s32 timer; /* +0xA0 */
    s32 cooldown; /* +0xA4 */
    s32 humanWon;
    s32 transitionActive; /* +0xAC: func_80293CE4_de */
} CGameStatus;
#endif
