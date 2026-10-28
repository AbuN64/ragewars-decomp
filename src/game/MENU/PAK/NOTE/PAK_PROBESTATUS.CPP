#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/LONE/D_8010FC00.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_12.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

/* Releases the save buffer and clears its global state. */
extern void Cache_DrainAndCompactResources(int);





extern void Control_ReadControllerStates(void);

extern u8 D_8010BBB8;


extern u8 D_80153330[];


extern s32 osMotorInit(u8 *a0, u8 *a1, s32 a2);

extern s32 Note_UpdateStatus(s32 a0);

extern void Control_ReleasePakLock(void);

void Note_AllocateScratchBuffer(void) {
    struct Shape_typemap_165 *block;
    s32 buffer;

    block = Cache_AllocateResource(0, 0x810, 0x23, &g_pakPakStateNoteName);
    buffer = block->field_0;
    D_800DE808 = (s32 *)block;
    D_800E2854 = buffer;
    XPlus_FillMemory((void *)buffer, 0, 0x810);
    D_800E2850 = 1;
}

void Note_FreeScratchBuffer(void) {
    Cache_DrainAndCompactResources(0);
    if (D_800DE808) {
        Cache_ReleaseResource(0, D_800DE808);
        D_800DE808 = 0;
        D_800E2854 = 0;
    }
    D_800E2850 = 0;
}

/* Probes the Controller Pak slot for kind and records its state: 2 when the probe succeeds, otherwise 3 or 1 depending on Note_UpdateStatus. */
void Note_ProbeStatus(s32 kind)
{
    u8 *cur;
    s32 ready;

    ((void (*)(s32))Control_AcquireControllerLock)(1);
    Control_ReadControllerStates();
    D_8010BBB8 = 2;

    cur = D_80153330 + kind * 112;
    if (D_8010FBE3[kind * 4] != 0) {
        cur[0] = 0;
        ready = 0;
    } else {
        cur[0] = osMotorInit(D_8010FC00, cur + 8, kind) == 0;
        ready = cur[0];
    }

    if (ready != 0) {
        g_controllerPakChannelStates[kind] = 2;
    } else if (Note_UpdateStatus(kind) != 0) {
        g_controllerPakChannelStates[kind] = 3;
    } else {
        g_controllerPakChannelStates[kind] = 1;
    }
    Control_ReleasePakLock();
}

/* Returns entry i of g_controllerPakChannelStatuses when entry i of the state table g_controllerPakChannelStates is 3, otherwise -2. */



s32 Note_GetStatus(s32 index) {
    if (g_controllerPakChannelStates[index] != 3) {
        return -2;
    }
    return g_controllerPakChannelStatuses[index];
}

/* Returns whether entry i of the word table g_controllerPakChannelStates equals 2. */


s32 Note_IsChannelReady(s32 index) {
    return g_controllerPakChannelStates[index] == 2;
}
