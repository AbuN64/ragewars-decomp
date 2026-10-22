#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BOX_CONTACT.H"
#include "TYPES.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "GAME_2/80240650.H"

s32 func_80240660_de(void *arg0, Triple t, s32 arg4, s32 arg5, void *arg6) {
    char unused[0xB60];
    *(Triple *)arg6 = t;
    return 1;
}

s32 func_80240698_de(void *arg0, s32 arg1, CVector3 t, s32 arg5, s32 arg6, void *arg7) {
    struct Model *model = arg0;
    CVector3 *output = arg7;
    Triple unused1;
    Triple unused2;
    *output = t;
    return model->flags;
}
