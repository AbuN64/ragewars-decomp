#include "shared/preview_model_image.h"
#include "types.h"

/* Shows the model preview of the screen D_800E53C0 when its model id at 0x32C is set: shows item
   the version-specific preview item of the screen window with alpha 0xAF and D_800D3500 at 0x38, then sets up the view at 0x20
   of the screen through func_80439B5C_de with mode 0, a uniform D_800DDAFC_de scale and the offset
   (0, D_800DDB04, D_800DDB08_de), through func_80439BE0_de with a zero vector, through func_80439C30_de
   with (0, D_800DDB00, 0), and loads the model through func_80439C80_de. */

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

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
extern void func_80439B5C_de(void *, s32, Vec3, Vec3);
extern void func_80439BE0_de(void *, Vec3);
extern void func_80439C30_de(void *, Vec3);
extern void func_80439C80_de(void *, s32);

void func_8042CE74_de(void) {
    struct Item *item;
    Vec3 scale;
    Vec3 offset;
    Vec3 angle;
    Vec3 position;

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

