#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802192C0.h"
#include "span_1000/code_8026AC38.h"
#include "types.h"
#include "n64sdk.h"
#include "gbi.h"
#include "shared/gameplay_camera.h"

/* Steps an animation cursor one frame: looks up the clip in D_8011FE88, keeps the previous frame,
   and moves forward in states 1 and 2 or backward in states 3 and 4; at either end a looping clip
   (mode 1) wraps and a ping-pong clip (mode 0) reverses direction. */






extern Clip *func_8028D218_de(char *, s32);

void func_802192C0_de(Cursor *cursor) {
    Clip *clip;
    s32 frames;
    s32 state;

    clip = func_8028D218_de(&D_8011FE88, cursor->clip);
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


void func_802193C8_de(Struct802193C8 *arg0, s8 arg1) {
    arg0->field0 = 1;
    arg0->field1 = arg1;
    arg0->field2 = func_8028D28C_de(&D_8011FE88);
    arg0->field4 = 0;
}

extern void *func_8028D244_de(char *a, unsigned char b, short c);





void *func_80219408_de(void *arg0) {
    func_8028D244_de(&D_8011FE88, ((Cursor *)(arg0))->clip, ((Cursor *)(arg0))->frame);
}

extern void *func_8028D244_de(char *a, unsigned char b, short c);





void func_80219434_de(void *arg0) {
    func_8028D244_de(&D_8011FE88, ((Cursor *)(arg0))->clip, ((Cursor *)(arg0))->previous);
}

/** Initialize the compact state record to its default values. */
void func_80219460_de(void *record) {
    ((CompactAnimationState *)(record))->active = 1;
    ((CompactAnimationState *)record)->state = 0;
    ((CompactAnimationState *)(record))->cursor = 0;
    ((CompactAnimationState *)(record))->flags = 0;
    ((CompactAnimationState *)(record))->clip = -1;
}

void func_80219480_de(void) {
    char pad[0x10];
}

extern Gfx *D_80110634;
extern s32 D_8011FAC0;
extern s32 D_800E28D8;

extern s32 D_800C94E8_de;
extern s32 D_800D297C;
extern char D_800CBC90;


extern void func_8026D914_de(s32 arg0);
extern void func_8026E378_de(s32 arg0, s32 arg1);

extern void func_80291BE8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);
extern void func_80272CB0_de(void *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_80273A98_de(void *arg0, f32 arg1);
extern void func_802738C0_de(void *arg0, f32 arg1);
extern void func_80273448_de(char *object, f32 x, f32 y, f32 z);
extern void func_80273D6C_de(void *object);
extern void func_8027302C(f32 *arg0, f32 *arg1);
extern void func_802735A8_de(void *arg0, s32 arg1, f32 arg2, f32 arg3);
extern void func_8027027C_de(void *arg0, void *arg1);
extern void func_80272898_de(void *arg0, void *arg1, void *arg2);
extern void func_8026DF30_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);







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

    func_8026D8F8_de();
    if (((AnimationSprite *)(object))->model == 0 || ((AnimationSprite *)(object))->active == 0) {
        return;
    }

    func_8026D914_de(0xC0);
    func_8026E378_de(1, 0x20);

    command = D_80110634++;
    gDPSetTexturePersp(command, G_TP_PERSP);
    command = D_80110634++;
    gDPSetTextureFilter(command, G_TF_BILERP);
    func_8026D980_de();

    x = ((Shared_func_80234FDC_S2 *)(camera))->unk2A4;
    y = ((Shared_func_80234FDC_S2 *)(camera))->unk2A8;
    z = ((Shared_func_80234FDC_S2 *)(camera))->unk2A0 + y;
    w = ((Shared_func_80234FDC_S2 *)(camera))->unk29C + x;
    func_80291BE8_de(&D_8011FAC0, (s32)x, (s32)w, (s32)y, (s32)z, 0);

    func_80272CB0_de(first, ((AnimationSprite *)(object))->scaleX,
                   ((AnimationSprite *)(object))->scaleY, ((AnimationSprite *)(object))->scaleZ);
    func_80273A98_de(first, ((AnimationSprite *)(object))->yaw);
    func_802738C0_de(first, ((AnimationSprite *)(object))->pitch);
    func_80273448_de((char *)first, ((AnimationSprite *)(object))->position.x,
                   ((AnimationSprite *)(object))->position.y, ((AnimationSprite *)(object))->position.z);
    func_80273D6C_de(first);

    matrix = (char *)second;
    func_8027302C(second, first);
    if (D_800E28D8 == 2) {
        func_802735A8_de(matrix, D_800C94E8_de, D_800C22D0_de, D_800C22D0_de);
    }
    {
        s32 offset = (D_800D297C << 6) + 0x10;
        func_8027027C_de(matrix, object + offset);
    }
    func_80272898_de(first, object + 0xA8, output);
    {
        s32 offset = (D_800D297C << 6) + 0x10;
        func_8026DF30_de(((AnimationSprite *)(object))->model, (s32)(object + offset),
                       (s32)&D_800CBC90, 0, -1);
    }
    func_8026D9D0_de();
    func_8026D914_de(0);
    func_8026E378_de(0, 0x20);
}
