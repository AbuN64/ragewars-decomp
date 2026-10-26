#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/GFX.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/RESULTS.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "CAMERA/80233920_7.H"
#include "RENDER_4/8028FD2C_15.H"

/* Draws one view of the game world: after the per-frame setup (func_802909F0_de) it runs the world, player,
 * effect, particle, object and translucent passes for the view in order, skipping the player and effect
 * passes in the alternate HUD mode (Cinema_IsSequenceInWindow) and running the extra passes only when func_802934F8_de
 * allows; when debug flag 0x200 is set it then clears the view's rectangle at 0x29C..0x2A8 to the far
 * depth with a fill-rectangle command. */


extern Gfx *g_displayListCursor;
extern char D_80145040;
extern s32 D_801462C8;

extern void func_80289084_de(char *, char *);
extern s32 Cinema_IsSequenceInWindow(void);
extern void func_80228798_de(void *, char *);
extern s32 func_802934F8_de(void);
extern void func_8022A2A0_de(void *, char *);
extern void Scene_DrawOpaqueActors(char *, char *);
extern void func_802A5180_de(void *, char *);
extern void SetN64_DrawVisibleEffects(char *, char *);
extern void Scene_DrawTransparentObjects(char *, char *);
extern void func_80228958_de(ObjRecAt20V2 *, char *);
extern void func_8023B3F8_de(char *, char *);
extern void Scene_DrawWorldParticles(char *, char *);
extern void Fx_DrawLinkedGeometry(void *, char *);
extern void Sky_DrawObjectFlares(char *);
extern void func_8022A328_de(void *, char *);
extern void Geometry_SetModePreset(s32);







void Camera_DrawWorldViewLayers(char *view, char *world) {
    f32 right;

    func_802909F0_de();
    func_80289084_de(world, view);
    if (Cinema_IsSequenceInWindow() == 0) {
        func_80228798_de(&D_80145040, view);
    }
    if (func_802934F8_de() != 0) {
        func_8022A2A0_de(&D_80145040, view);
    }
    Scene_DrawOpaqueActors(world, view);
    func_802A5180_de(&D_801379C0, view);
    if (Cinema_IsSequenceInWindow() == 0) {
        SetN64_DrawVisibleEffects(world + 0x11778, view);
    }
    Scene_DrawTransparentObjects(world, view);
    func_80228958_de(&D_80145040, view);
    func_8023B3F8_de(view + 0x570, view);
    Scene_DrawWorldParticles(world, view);
    Fx_DrawLinkedGeometry(&D_801379C0, view);
    Sky_DrawObjectFlares(view);
    if (Cinema_IsSequenceInWindow() == 0 && func_802934F8_de() != 0) {
        func_8022A328_de(&D_80145040, view);
    }
    if (D_801462C8 & 0x200) {
        gDPPipeSync(g_displayListCursor++);
        gDPSetCycleType(g_displayListCursor++, G_CYC_1CYCLE);
        gDPSetBlendColor(g_displayListCursor++, 255, 255, 255, 255);
        gDPSetPrimDepth(g_displayListCursor++, 65535, 65535);
        gDPSetDepthSource(g_displayListCursor++, G_ZS_PRIM);
        Geometry_SetModePreset(0x16);
        {
            Gfx *_g;

            right = ((GameplayCamera *)(view))->viewLeft + ((GameplayCamera *)(view))->viewWidth;
            gDPFillRectangle((Gfx *)(g_displayListCursor++), ((GameplayCamera *)(view))->viewLeft, ((GameplayCamera *)(view))->viewTop, right, ((GameplayCamera *)(view))->viewTop + ((GameplayCamera *)(view))->viewHeight);
        }
    }
}
