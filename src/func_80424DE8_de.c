#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80423280.h"
/* Count achievements, store the rank, and select its version-specific title. */
extern Record_func_80433914_de D_80102B00[];
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
