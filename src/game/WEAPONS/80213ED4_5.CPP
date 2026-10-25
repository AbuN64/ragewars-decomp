#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"

extern s32 func_8024E924_de(void *arg0);




s32 Weapons_GetImpactSlot(void *arg0)
{
    char *actor = arg0;
    CGameStatus *audio;
    s32 type;

    type = func_8024E924_de(actor);
    switch (type) {
    case 1:
    case 2:
        return 0;
    case 3:
    case 4:
        return 1;
    case 5:
    case 6:
        return 2;
    case 7:
    case 8:
        return 3;
    case 9:
    case 10:
    case 100:
    case 102:
    case 1120:
    case 1121:
    case 1122:
    case 1123:
    case 1126:
        if (*(u8 *)actor == 1) {
            if ((((ObjectLinks1230 *)(actor))->unk_100 & 0x300000) != 0) {
                if ((((ObjectLinks1230 *)(actor))->unk_122C & 0x18400) != 0) {
                    return 9;
                }
                audio = &D_801462C8.counters;
                if (audio->enabled != 0 &&
                    ((struct ObjRecAt80 *) ((ObjectLinks1230 *) actor)->unk_5D8)->unk80 == 0xB &&
                    audio->timer > 0) {
                    return 9;
                }
            }
        }
        return 4;
    case 11:
    case 12:
        return 5;
    case 13:
    case 14:
        return 6;
    case 15:
    case 16:
        return 7;
    case 17:
    case 18:
        return 8;
    case 19:
    case 20:
    case 103:
        return 9;
    default:
        return 3;
    }
}
