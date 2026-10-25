#include "include_asm.h"
#include "COMMON/SETTINGSRECAT24.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "DATA/OVLDAT9/800E5320.H"
#include "FRONTEND/8040B45C_33.H"

extern func_8042CE54_S1 *D_800E53C0;


extern void Frontend_SetWidgetFlag08(void *arg0, s32 arg1);


/** Load four banks of ten resources, then activate the two resources used by the set. */
void func_8042CC74_de(void)
{
    s32 bank;
    s32 offset;
    void *resource;

    bank = 0;
    offset = 0;
    do {
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[0]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[2]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[4]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[6]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[8]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[10]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[12]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[14]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[16]);
        Frontend_SetWidgetFlag08(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[18]);
        Frontend_SetWidgetFlag08(resource, 0);
        offset += 0x28;
        bank++;
    } while (bank < 4);

#if defined(VERSION_DE)
    func_8042D418_de(0x264);
    func_8042D418_de(0x269);
#elif defined(VERSION_EU_X)
    func_8042D418_de(0x26D);
    func_8042D418_de(0x272);
#else
    func_8042D418_de(0x269);
    func_8042D418_de(0x26E);
#endif
}

#include "FRONTEND/PREVIEW_MODEL_IMAGE.H"
/* Shows the model preview of the screen D_800E53C0 when its model id at 0x32C is set: shows the
   version-specific preview item of the screen window with alpha 0xAF and the preview image, then sets up the
   view at 0x20 of the screen through func_80439B5C_de with mode 0, a uniform D_800DDAFC_de scale and the
   offset (0, D_800DDB04, D_800DDB08_de), through func_80439BE0_de with a zero vector, through
   func_80439C30_de with (0, D_800DDB00, 0), and loads the model through func_80439C80_de. */
typedef struct PreviewScreen {
    char pad0[0x20];
    char view[0xE0 - 0x20];
    void *window;
    char padE4[0x32C - 0xE4];
    s32 model;
} PreviewScreen;
#define PREVIEW_SCREEN ((PreviewScreen *)D_800E53C0)
extern f32 D_800DDAFC_de;
extern f32 D_800DDB00, D_800DDB04, D_800DDB08_de;
extern void func_80439B5C_de(void *, s32, CVector3, CVector3);
extern void func_80439BE0_de(void *, CVector3);
extern void func_80439C30_de(void *, CVector3);
extern void func_80439C80_de(void *, s32);
void func_8042CE74_de(void) {
    struct MenuWidget *item;
    CVector3 scale;
    CVector3 offset;
    CVector3 angle;
    CVector3 position;
    if (PREVIEW_SCREEN->model != -1) {
#if defined(VERSION_DE)
        item = func_8040EC30_de(PREVIEW_SCREEN->window, 0x263);
#elif defined(VERSION_EU_X)
        item = func_8040EC30_de(PREVIEW_SCREEN->window, 0x26C);
#else
        item = func_8040EC30_de(PREVIEW_SCREEN->window, 0x268);
#endif
        Frontend_SetWidgetFlag08(item, 1);
        item->alpha = 0xAF;
        item->image = previewModelImage();
        scale.x = D_800DDAFC_de;
        scale.y = D_800DDAFC_de;
        scale.z = D_800DDAFC_de;
        angle.x = 0;
        angle.y = 0;
        angle.z = 0;
        position.x = 0;
        position.y = D_800DDB00;
        position.z = 0;
        offset.x = 0;
        offset.y = D_800DDB04;
        offset.z = D_800DDB08_de;
        func_80439B5C_de(PREVIEW_SCREEN->view, 0, scale, offset);
        func_80439BE0_de(PREVIEW_SCREEN->view, angle);
        func_80439C30_de(PREVIEW_SCREEN->view, position);
        func_80439C80_de(PREVIEW_SCREEN->view, PREVIEW_SCREEN->model);
    }
}
