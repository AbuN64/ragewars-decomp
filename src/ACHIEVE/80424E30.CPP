#include "include_asm.h"

INCLUDE_RODATA("data_800C", rodata_func_80423828_de_19_800E16C8);

#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct AchieveRecord { u8 pad0[0x78]; u8 active; u8 pad79[0x17]; u8 team; u8 pad92[5]; } AchieveRecord;
typedef struct AchieveCounters { u8 pad0[0x96]; } AchieveCounters;
extern u8 D_80142369[][0x96];
extern s32 D_800FEB70[][100];
extern u8 D_800FEB26[];
extern s8 D_8014222C;
extern s8 D_8014222D;
extern AchieveRecord D_80146398[];
extern s32 D_800FF140_de[];
extern s8 D_801462C8[];
void func_80424C50_de(s32 arg0, s32 arg1) {
    s32 count;
    s32 i;
    s32 eligible;
    s32 value;
    if (D_80142369[arg0][0] == 1) {
        return;
    }
    if (D_800FEB70[arg0][0] + 1 > 99999) {
        D_800FEB70[arg0][0] = 99999;
    } else {
        D_800FEB70[arg0][0] = D_800FEB70[arg0][0] + 1;
    }
    eligible = 1;
    if (D_8014222C > 0 || D_8014222D > 0) {
        count = 0;
        for (i = 0; i < 8; i++) {
            if (D_80146398[i].active == 1) {
                if (D_80146398[i].team != D_80146398[i].active) {
                    if (D_800FF140_de[i] >= 0x4C) {
                        count++;
                    }
                }
            }
        }
        if (count < 2) {
            eligible = 0;
        }
    } else {
        eligible = 0;
    }
    if (eligible == 1) {
        if (D_801462C8[0x24] >= 10 || D_801462C8[0x25] >= 10) {
            value = D_800FEB26[arg1 + arg0 * 400] + 1;
            if (value >= 6) {
                D_800FEB26[arg1 + arg0 * 400] = 5;
            } else {
                D_800FEB26[arg1 + arg0 * 400] = value;
            }
        }
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_80424C50_de);
#endif


#ifdef NON_MATCHING
/* Count achievements, store the rank, and select its version-specific title. */
extern Profile D_80102B00[];

extern s32 func_80265650_de(s32 bits, s32 index);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern char *D_800D3200[];
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern char *D_800E1254[];
extern char *D_800E1264[];
extern char *D_800E1274[];
extern char *D_800E1284[];
extern char *D_800E1294[];
extern char *D_800E12A4[];
extern char *D_800E12B4[];
extern char *D_800E12C4[];
extern char *D_800E12D4[];
extern char *D_800E12E4[];
extern char *D_800E12F4[];
extern char *D_800E1304[];
extern char *D_800E1314[];
extern char *D_800E1324[];
extern char *D_800E1334[];
extern char *D_800E1344[];
extern char *D_800E1354[];
extern char *D_800E1364[];
extern char *D_800E1374_eu[];
extern char *D_800E1384[];
#endif

char *func_80424DE8_de(s32 index) {
    s32 count;
    s32 i;
    char *text;
    s32 rank;
    if (index >= 4) {
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        return (D_800D3200[0]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        return ((D_800E1254)[D_80152789]);
#endif
    }
    count = 0;
    i = 0;
    do {
        if (func_80265650_de((s32)D_80102B00[index].achievementFlags, i) == 1) {
            count++;
        }
        i++;
    } while (i < 50);
    switch (count) {
    case 0:
    case 1:
        rank = 0;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[0]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1254)[D_80152789]);
#endif
        break;
    case 2:
    case 3:
        rank = 1;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[1]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1264)[D_80152789]);
#endif
        break;
    case 4:
    case 5:
        rank = 2;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[2]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1274)[D_80152789]);
#endif
        break;
    case 6:
    case 7:
        rank = 3;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[3]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1284)[D_80152789]);
#endif
        break;
    case 8:
    case 9:
        rank = 4;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[4]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1294)[D_80152789]);
#endif
        break;
    case 10:
    case 11:
        rank = 5;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[5]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E12A4)[D_80152789]);
#endif
        break;
    case 12:
    case 13:
        rank = 6;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[6]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E12B4)[D_80152789]);
#endif
        break;
    case 14:
    case 15:
        rank = 7;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[7]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E12C4)[D_80152789]);
#endif
        break;
    case 16:
    case 17:
        rank = 8;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[8]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E12D4)[D_80152789]);
#endif
        break;
    case 18:
    case 19:
        rank = 9;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[9]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E12E4)[D_80152789]);
#endif
        break;
    case 20:
    case 21:
        rank = 10;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[10]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E12F4)[D_80152789]);
#endif
        break;
    case 22:
    case 23:
    case 24:
        rank = 11;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[11]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1304)[D_80152789]);
#endif
        break;
    case 25:
    case 26:
    case 27:
        rank = 12;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[12]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1314)[D_80152789]);
#endif
        break;
    case 28:
    case 29:
    case 30:
        rank = 13;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[13]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1324)[D_80152789]);
#endif
        break;
    case 31:
    case 32:
    case 33:
        rank = 14;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[14]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1334)[D_80152789]);
#endif
        break;
    case 34:
    case 35:
    case 36:
        rank = 15;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[15]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1344)[D_80152789]);
#endif
        break;
    case 37:
    case 38:
    case 39:
        rank = 16;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[16]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1354)[D_80152789]);
#endif
        break;
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
        rank = 17;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[17]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1364)[D_80152789]);
#endif
        break;
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
        rank = 18;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[18]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1374_eu)[D_80152789]);
#endif
        break;
    default:
        rank = 19;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
        text = (D_800D3200[19]);
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
        text = ((D_800E1384)[D_80152789]);
#endif
        break;
    }
    D_80102B00[index].rank = rank;
    return text;
}
#else
INCLUDE_ASM("ovl_80400000", func_80424DE8_de);
#endif
