#include "include_asm.h"
#include "COMMON/LONE/D_800E28D4.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/LABEL.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

/* Enables mode 1 through func_802A23C4_de, places the menu model at (17, -10, -50) with uniform scale 0.14, zero rotation and a (0, 5, 0) offset, then issues request 0xE78 through Render_PlayFlatSound; returns zero. */





/* The hub spells D_800E3590 as the padded menu block; this unit reaches the model name at +0x08
 * through its own view, so each use casts back to it. */
extern void func_80439B5C_de(char *model, s32 arg1, CVector3 scale, CVector3 position);
extern void func_80439BE0_de(char *model, CVector3 rotation);
extern void func_80439C30_de(char *model, CVector3 offset);

s32 func_8041DBCC_de(void) {
    CVector3 scale;
    CVector3 position;
    CVector3 rotation;
    CVector3 offset;

    func_802A23C4_de(1);
    scale.x = 0.14f;
    scale.y = 0.14f;
    scale.z = 0.14f;
    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = 0.0f;
    offset.x = 0.0f;
    offset.y = 5.0f;
    offset.z = 0.0f;
    position.x = 17.0f;
    position.y = -10.0f;
    position.z = -50.0f;
    func_80439B5C_de(((MenuRecAt8 *) D_800E3590)->model, 0, scale, position);
    func_80439BE0_de(((MenuRecAt8 *) D_800E3590)->model, rotation);
    func_80439C30_de(((MenuRecAt8 *) D_800E3590)->model, offset);
    Render_PlayFlatSound(0xE78);
    return 0;
}

#include "gbi.h"
#include "COMMON/VIDEO_DIMENSIONS.H"
extern s32 Frontend_GetModelRecordCount(struct Record_func_80439C80_de *record);
extern void func_804399D0(struct Record_func_80439C80_de *record);
extern Gfx *D_80110634;
extern s32 D_800E28D0;
/* Draw callback of the menu block: on draw event 1 in state 3 it clears the fill mode D_800D15E0, sets the fill
 * colour D_800D15E4 to opaque white, scissors the display list to the full screen and, when the block record at
 * +0x08 holds a model, draws it once in fill mode 1 at alpha 210, then restores the fill state. Returns zero. */
s32 Frontend_DrawMenuBlockModel(void *window, void *item, s32 event) {
    if (event == 1 && D_800E3590->unk216 == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        gDPSetScissor(D_80110634++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
        if (Frontend_GetModelRecordCount(&D_800E3590->record) != 0) {
            D_800D15E0 = 1;
            D_800D15E4[3] = 210.0f;
            func_804399D0(&D_800E3590->record);
            D_800D15E0 = 0;
            D_800D15E4[3] = 255.0f;
        }
    }
    return 0;
}
