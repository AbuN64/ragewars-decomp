#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/LONE/D_8010FC00.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_12.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"
extern void Scene_ReleaseResource(void *arg0, void *arg1);

/* Releases the save buffer and clears its global state. */
extern void func_80253908_de(int);


extern int D_800E2850;

extern int D_800E2854;

extern int *D_800DE808;

extern void Render_ReadControllerStates(void);

extern u8 D_8010BBB8;

extern u8 D_8010FBE3[];

extern u8 D_80153330[];


extern s32 func_802B7FD8_de(u8 *a0, u8 *a1, s32 a2);

extern s32 Pak_UpdateStatus(s32 a0);

extern void func_8026454C_de(void);

void Pak_AllocateScratchBuffer(void) {
    struct Shape_typemap_165 *block;
    s32 buffer;

    block = Scene_AllocateResource(0, 0x810, 0x23, &g_pakPakStateNoteName);
    buffer = block->field_0;
    D_800DE808 = (s32 *)block;
    D_800E2854 = buffer;
    Resmgr_FillMemory((void *)buffer, 0, 0x810);
    D_800E2850 = 1;
}

void func_80404DDC_de(void) {
    func_80253908_de(0);
    if (D_800DE808) {
        Scene_ReleaseResource(0, D_800DE808);
        D_800DE808 = 0;
        D_800E2854 = 0;
    }
    D_800E2850 = 0;
}

/* Probes the Controller Pak slot for kind and records its state: 2 when the probe succeeds, otherwise 3 or 1 depending on Pak_UpdateStatus. */
void Pak_ProbeStatus(s32 kind)
{
    u8 *cur;
    s32 ready;

    ((void (*)(s32))func_802644FC_de)(1);
    Render_ReadControllerStates();
    D_8010BBB8 = 2;

    cur = D_80153330 + kind * 112;
    if (D_8010FBE3[kind * 4] != 0) {
        cur[0] = 0;
        ready = 0;
    } else {
        cur[0] = func_802B7FD8_de(D_8010FC00, cur + 8, kind) == 0;
        ready = cur[0];
    }

    if (ready != 0) {
        D_801534F0[kind] = 2;
    } else if (Pak_UpdateStatus(kind) != 0) {
        D_801534F0[kind] = 3;
    } else {
        D_801534F0[kind] = 1;
    }
    func_8026454C_de();
}

/* Returns entry i of D_80153500 when entry i of the state table D_801534F0 is 3, otherwise -2. */



s32 Pak_GetStatus(s32 index) {
    if (D_801534F0[index] != 3) {
        return -2;
    }
    return D_80153500[index];
}

/* Returns whether entry i of the word table D_801534F0 equals 2. */


s32 func_80404F3C_de(s32 index) {
    return D_801534F0[index] == 2;
}
