#include "include_asm.h"
#include "COMMON/SETTINGSRECAT24.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "DATA/OVLDAT9/800E5320.H"

extern func_8042CE54_S1 *D_800E53C0;


extern void *func_8040EC30_de(void *arg0, u16 arg1);
extern void func_8040E8D8_de(void *arg0, s32 arg1);


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
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[2]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[4]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[6]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[8]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[10]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[12]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[14]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[16]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[18]);
        func_8040E8D8_de(resource, 0);
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

#ifdef NON_MATCHING
#include "FRONTEND/PREVIEW_MODEL_IMAGE.H"
#include "TYPES.H"

/* Shows the model preview of the screen D_800E53C0 when its model id at 0x32C is set: shows item
   the version-specific preview item of the screen window with alpha 0xAF and D_800D3500 at 0x38, then sets up the view at 0x20
   of the screen through func_80439B5C_de with mode 0, a uniform D_800DDAFC_de scale and the offset
   (0, D_800DDB04, D_800DDB08_de), through func_80439BE0_de with a zero vector, through func_80439C30_de
   with (0, D_800DDB00, 0), and loads the model through func_80439C80_de. */

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} CVector3;

struct Item {
    char pad[0x10];
    u8 alpha;
    char pad11[0x38 - 0x11];
    s32 image;
};

struct Screen {
    char pad[0x20];
    char view[0xE0 - 0x20];
    void *window;
    char padE4[0x32C - 0xE4];
    s32 model;
};

extern struct Screen *D_800E53C0;

extern f32 D_800DDAFC_de;
extern f32 D_800DDB00, D_800DDB04, D_800DDB08_de;

extern struct Item *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(struct Item *, s32);
extern void func_80439B5C_de(void *, s32, CVector3, CVector3);
extern void func_80439BE0_de(void *, CVector3);
extern void func_80439C30_de(void *, CVector3);
extern void func_80439C80_de(void *, s32);

void func_8042CE74_de(void) {
    struct Item *item;
    CVector3 scale;
    CVector3 offset;
    CVector3 angle;
    CVector3 position;

    if (D_800E53C0->model != -1) {
        #if defined(VERSION_DE)
        item = func_8040EC30_de(D_800E53C0->window, 0x263);
#elif defined(VERSION_EU_X)
        item = func_8040EC30_de(D_800E53C0->window, 0x26C);
#else
        item = func_8040EC30_de(D_800E53C0->window, 0x268);
#endif
        func_8040E8D8_de(item, 1);
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
        func_80439B5C_de(D_800E53C0->view, 0, scale, offset);
        func_80439BE0_de(D_800E53C0->view, angle);
        func_80439C30_de(D_800E53C0->view, position);
        func_80439C80_de(D_800E53C0->view, D_800E53C0->model);
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8042CE74_de);
#endif
