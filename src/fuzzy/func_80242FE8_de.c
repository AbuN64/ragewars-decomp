#include "types.h"
#include "shared/func_8044DA54_de_closed.h"

void func_802433DC_de(s32 *, void *);

void func_80242FE8_de(s32 *param_1, void *param_2) {
    u32 *puVar2;
    s32 iVar3;
    u32 uVar4;
    u32 uVar5;
    u32 *puVar6;
    float *pfVar7;
    s16 *psVar8;
    s16 *psVar9;
    u32 uVar10;
    u32 *puVar11;
    s32 iVar12;
    u32 uVar13;
    u8 bVar1;
    u32 scratch[0x100];
    char *auStack_448 = (char *)scratch;
    float *afStack_448 = (float *)&auStack_448[0];
    u32 *auStack_430 = (u32 *)&auStack_448[0x18];
    struct {
        float *local_48;
        s32 local_44;
        float *local_40;
    } tri;
    f32 local_38;
    f32 local_34;
    f32 local_30;

    puVar2 = (u32 *)func_8028FDB4_de(param_2, 0);
    iVar12 = *param_1;
    param_1[0x18] = *puVar2;
    iVar3 = param_1[0x17];
    uVar13 = *puVar2 & 4;
    if (iVar3 == 1) {
        uVar13 = 1;
    } else if ((0 < iVar3) && (iVar3 < 9) && (6 < iVar3)) {
        uVar13 = 1;
    }
    puVar2 = (u32 *)func_8028FDB4_de(param_2, 1);
    puVar11 = puVar2 + 1;
    while (1) {
        bVar1 = *(u8 *)puVar2;
        switch (bVar1) {
        case 1: {
            psVar8 = (s16 *)((puVar11[0] & 0xffffff) + param_1[0x29]);
            psVar9 = psVar8 + 2;
            uVar10 = (u32)((puVar2[0] >> 0xc) & 0xff);
            iVar3 = ((puVar2[0] & 0xfe) >> 1) - uVar10;
            pfVar7 = afStack_448 + iVar3 * 8;
            puVar6 = auStack_430 + iVar3 * 8;
            do {
                puVar6[1] = (u32)psVar8;
                local_38 = (f32)(s32)*psVar8;
                local_34 = (f32)(s32)psVar9[-1];
                local_30 = (f32)(s32)*psVar9;
                *pfVar7 = ((f32 *)param_1)[0x19] * (f32)(s32)*psVar8 +
                          ((f32 *)param_1)[0x1d] * (f32)(s32)psVar9[-1] +
                          ((f32 *)param_1)[0x21] * (f32)(s32)*psVar9 + ((f32 *)param_1)[0x25];
                *puVar6 = ((u32)(*(u32 *)(iVar12 + 0x18) - (*(u32 *)pfVar7 & 0x7fffffff)) >> 31)
                          << (*(u32 *)pfVar7 >> 31);
                ((f32 *)puVar6)[-5] = (((f32 *)param_1)[0x1a] * local_38 + ((f32 *)param_1)[0x1e] * local_34 +
                                   ((f32 *)param_1)[0x22] * local_30 + ((f32 *)param_1)[0x26]);
                *puVar6 |= ((u32)(*(u32 *)(iVar12 + 0x18) - (puVar6[-5] & 0x7fffffff)) >> 31)
                           << (2 + (puVar6[-5] >> 31));
                psVar8 = psVar8 + 8;
                uVar10 = uVar10 - 1;
                psVar9 = psVar9 + 8;
                pfVar7 = pfVar7 + 8;
                ((f32 *)puVar6)[-4] = (((f32 *)param_1)[0x1b] * local_38 + ((f32 *)param_1)[0x1f] * local_34 +
                                   ((f32 *)param_1)[0x23] * local_30 + ((f32 *)param_1)[0x27]);
                uVar4 = puVar6[-4];
                uVar5 = *puVar6 | ((~(uVar4 >> 31) & ((*(u32 *)(iVar12 + 0x18) - uVar4) >> 31)) << 4);
                *puVar6 = uVar5 | (((uVar4 >> 31) & (((u32)param_1[0x13] - (uVar4 & 0x7fffffff)) >> 31)) << 5);
                puVar6 = puVar6 + 8;
            } while (uVar10 != 0);
            break;
        }
        case 6: {
            uVar4 = (puVar11[0] & 0xfe0000) >> 0xc;
            tri.local_48 = (float *)(&auStack_448[0] + uVar4);
            uVar5 = (puVar11[0] & 0xfe00) >> 4;
            tri.local_44 = (s32)(&auStack_448[0] + uVar5);
            uVar10 = (u32)(u8)(puVar11[0] >> 1);
            tri.local_40 = afStack_448 + uVar10 * 8;
            if (((*(u32 *)((s32)auStack_430 + uVar4) &
                  *(u32 *)((s32)auStack_430 + uVar5) & auStack_430[uVar10 * 8]) == 0) &&
                (func_802433DC_de(param_1, &tri), pfVar7 = tri.local_48, uVar13 != 0)) {
                tri.local_48 = tri.local_40;
                tri.local_40 = pfVar7;
                func_802433DC_de(param_1, &tri);
            }
            /* fall through */
        }
        case 5: {
            uVar4 = (puVar2[0] & 0xfe0000) >> 0xc;
            tri.local_48 = (float *)(&auStack_448[0] + uVar4);
            uVar5 = (puVar2[0] & 0xfe00) >> 4;
            tri.local_44 = (s32)(&auStack_448[0] + uVar5);
            uVar10 = (u32)(u8)(puVar2[0] >> 1);
            tri.local_40 = afStack_448 + uVar10 * 8;
            if (((*(u32 *)((s32)auStack_430 + uVar4) & *(u32 *)((s32)auStack_430 + uVar5) &
                  auStack_430[uVar10 * 8]) == 0) &&
                (func_802433DC_de(param_1, &tri), pfVar7 = tri.local_48, uVar13 != 0)) {
                tri.local_48 = tri.local_40;
                tri.local_40 = pfVar7;
                func_802433DC_de(param_1, &tri);
            }
            break;
        }
        default:
            break;
        }
        puVar11 = puVar11 + 2;
        puVar2 = puVar2 + 2;
        if (bVar1 == 0xdf) {
            return;
        }
    }
}
