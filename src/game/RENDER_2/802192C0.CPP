#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "RENDER_2/OBJECTSTATE8E.H"
#include "COMMON/OBJECTSTATE18.H"
#include "TYPES.H"
#include "gbi.h"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/EXTERNS_15.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "particle/80271B18_3.H"

/* Steps an animation cursor one frame: looks up the clip in D_8011FE88, keeps the previous frame,
   and moves forward in states 1 and 2 or backward in states 3 and 4; at either end a looping clip
   (mode 1) wraps and a ping-pong clip (mode 0) reverses direction. */






extern Clip *Scene_GetPlatformRoute(char *, s32);

void func_802192C0_de(Cursor *cursor) {
    Clip *clip;
    s32 frames;
    s32 state;

    clip = Scene_GetPlatformRoute(&g_world, cursor->clip);
    frames = clip->frames;
    state = cursor->state;
    cursor->previous = cursor->frame;
    switch (state) {
    case 1:
    case 2:
        {
            cursor->state = 1;
            if (++cursor->frame == frames) {
                switch (clip->mode) {
                case 1:
                    cursor->frame = 0;
                    break;
                case 0:
                    cursor->frame = frames - 2;
                    cursor->state = 3;
                    break;
                }
            }
        }
        break;
    case 3:
    case 4:
        {
            cursor->state = 3;
            if (--cursor->frame < 0) {
                switch (clip->mode) {
                case 0:
                    cursor->frame = 1;
                    cursor->state = 1;
                    break;
                case 1:
                    cursor->frame = frames - 1;
                    break;
                }
            }
        }
    }
}

extern s16 func_8028D28C_de(char *arg0);


void func_802193C8_de(Struct802193C8 *cursorState, s8 initialState) {
    cursorState->field0 = 1;
    cursorState->field1 = initialState;
    cursorState->field2 = func_8028D28C_de(&g_world);
    cursorState->field4 = 0;
}

extern void *Scene_GetPlatformRoutePoint(char *a, unsigned char b, short c);





void *func_80219408_de(Cursor *cursor) {
    return Scene_GetPlatformRoutePoint(&g_world, cursor->clip, cursor->frame);
}

extern void *Scene_GetPlatformRoutePoint(char *a, unsigned char b, short c);





void func_80219434_de(Cursor *cursor) {
    Scene_GetPlatformRoutePoint(&g_world, cursor->clip, cursor->previous);
}

/** Initialize the compact state record to its default values. */
void func_80219460_de(CompactAnimationState *record) {
    record->active = 1;
    record->state = 0;
    record->cursor = 0;
    record->flags = 0;
    record->clip = -1;
}

void func_80219480_de(void) {
    char pad[0x10];
}

#include "COMMON/GAME_SESSION.H"
extern s32 D_800E28D8;

extern s32 D_800C94E8_de;
extern char D_800CBC90;



extern void SetN64_ClearDepthRect(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);
extern void TranslateMatrix(char *object, f32 x, f32 y, f32 z);
extern void SwapMatrixUpForward(void *object);
extern void CopyMatrix(f32 *arg0, f32 *arg1);
extern void func_802735A8_de(void *arg0, s32 arg1, f32 arg2, f32 arg3);
extern void GraphU64_ConvertMatrixToFixed(void *arg0, void *arg1);
extern void Geometry_QueueDirectModel(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);







void func_80219490_de(char *object, char *camera) {
    f32 first[16];
    f32 second[16];
    s32 output[4];
    Gfx *command;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    char *matrix;

    Geometry_InvalidateMaterialKeys();
    if (((AnimationSprite *)(object))->model == 0 || ((AnimationSprite *)(object))->active == 0) {
        return;
    }

    Geometry_SetColorDither(0xC0);
    func_8026E378_de(1, 0x20);

    command = g_displayListCursor++;
    gDPSetTexturePersp(command, G_TP_PERSP);
    command = g_displayListCursor++;
    gDPSetTextureFilter(command, G_TF_BILERP);
    Geometry_BeginModelBatch();

    x = ((GameplayCamera *)(camera))->viewLeft;
    y = ((GameplayCamera *)(camera))->viewTop;
    z = ((GameplayCamera *)(camera))->viewHeight + y;
    w = ((GameplayCamera *)(camera))->viewWidth + x;
    SetN64_ClearDepthRect(&D_8011FAC0, (s32)x, (s32)w, (s32)y, (s32)z, 0);

    func_80272CB0_de(first, ((AnimationSprite *)(object))->scaleX,
                   ((AnimationSprite *)(object))->scaleY, ((AnimationSprite *)(object))->scaleZ);
    YawMatrix(first, ((AnimationSprite *)(object))->yaw);
    PitchMatrix(first, ((AnimationSprite *)(object))->pitch);
    TranslateMatrix((char *)first, ((AnimationSprite *)(object))->position.x,
                   ((AnimationSprite *)(object))->position.y, ((AnimationSprite *)(object))->position.z);
    SwapMatrixUpForward(first);

    matrix = (char *)second;
    CopyMatrix(second, first);
    if (D_800E28D8 == 2) {
        func_802735A8_de(matrix, D_800C94E8_de, D_800C22D0_de, D_800C22D0_de);
    }
    {
        s32 offset = (D_800D297C << 6) + 0x10;
        GraphU64_ConvertMatrixToFixed(matrix, object + offset);
    }
    GraphU64_TransformPoint(first, object + 0xA8, output);
    {
        s32 offset = (D_800D297C << 6) + 0x10;
        Geometry_QueueDirectModel(((AnimationSprite *)(object))->model, (s32)(object + offset),
                       (s32)&D_800CBC90, 0, -1);
    }
    Geometry_FlushModelBatch();
    Geometry_SetColorDither(0);
    func_8026E378_de(0, 0x20);
}

#include "COMMON/GAMEPLAY_REACTIONS.H"
#include "RENDER_2/802192C0.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/GAMEPLAY_REACTIONS.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_800D3A40[], *D_800D3A44[], *D_800D3A48[], *D_800D3A54[], *D_800D3A58[];
static inline char *reactionText(char **text, MenuSettings *settings) { return text[settings->language]; }
#else
extern char *D_800D3A40, *D_800D3A44, *D_800D3A48, *D_800D3A54, *D_800D3A58;
static inline char *reactionText(char *text, MenuSettings *settings) { return text; }
#endif
extern void SetN64_CopyString(char *,const char *);
extern void Sky_PostScaledScreenMessage(void *,void *,char *,f32);
static inline void nextMessage(s32 *next) {
    (*next)++;
    *next %= 4;
}

void Player_PostKillMessages(Shared_ReactionPlayer *a,Shared_ReactionPlayer *b,Shared_ReactionInteraction *unused) {
    MenuSettings *settings = &D_80145088.settings;
    MatchModes *modes;
    if (!settings->local) return;
    if (a!=b) {
        if (!a->unk5D8->unk8F) return;
        modes = &D_80145088.modes;
        if (modes->tag) {
            SetN64_CopyString(a->messages[a->messageNext], reactionText(D_800D3A40, settings));
            SetN64_CopyString(a->messages[a->messageNext]+10, b->unk5D8->name);
            if (a->owner) Sky_PostScaledScreenMessage(&D_80145088,a->owner,a->messages[a->messageNext],1.5f);
            nextMessage(&a->messageNext);
            SetN64_CopyString(b->messages[b->messageNext], reactionText(D_800D3A44, settings));
            SetN64_CopyString(b->messages[b->messageNext]+11, a->unk5D8->name);
            if (b->owner) Sky_PostScaledScreenMessage(&D_80145088,b->owner,b->messages[b->messageNext],1.5f);
        } else {
            if (!modes->captureFlag) return;
            SetN64_CopyString(a->messages[a->messageNext], reactionText(D_800D3A48, settings));
            SetN64_CopyString(a->messages[a->messageNext]+10, b->unk5D8->name);
            if (a->owner) Sky_PostScaledScreenMessage(&D_80145088,a->owner,a->messages[a->messageNext],1.5f);
            nextMessage(&a->messageNext);
            SetN64_CopyString(a->messages[a->messageNext], reactionText(D_800D3A54, settings));
            if (a->owner) Sky_PostScaledScreenMessage(&D_80145088,a->owner,a->messages[a->messageNext],1.5f);
            nextMessage(&a->messageNext);
            SetN64_CopyString(b->messages[b->messageNext], reactionText(D_800D3A44, settings));
            SetN64_CopyString(b->messages[b->messageNext]+11, a->unk5D8->name);
            if (b->owner) Sky_PostScaledScreenMessage(&D_80145088,b->owner,b->messages[b->messageNext],1.5f);
            nextMessage(&b->messageNext);
            SetN64_CopyString(b->messages[b->messageNext], reactionText(D_800D3A58, settings));
            if (b->owner) Sky_PostScaledScreenMessage(&D_80145088,b->owner,b->messages[b->messageNext],1.5f);
        }
    }
    nextMessage(&b->messageNext);
}
