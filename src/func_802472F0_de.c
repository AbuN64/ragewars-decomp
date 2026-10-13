#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802624A0.h"
#include "types.h"




extern void **func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern void func_80261670_de(void *, s32, s32, s32, s32 *, void *);
extern s32 func_802624D8_de(void *);
extern void func_8026193C_de(void *, Vec3 *, f32 *, void *);
extern void *func_80262564_de(void *);
extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);
extern f32 func_80273EE4_de(f32, f32, f32);


extern void func_80272898_de(Matrix_func_80213CF8_de *, Vec3 *, Vec3 *);
extern void func_80253754_de(s32, s32);


extern struct Shape_func_8021A2D4_de_2 D_8011FE88;

extern f32 D_800D2988;


extern char D_800C3930_de;









void func_802472F0_de(void *arg0) {
    Vec3 first;
    Vec3 second;
    Vec3 saved;
    Vec3 moved;
    Matrix_func_80213CF8_de matrix;
    s32 active;
    f32 first_value;
    f32 second_value;
    void **resource;
    void *track0;
    void *track1;
    f32 value;

    if (D_8011FE88.field_0 == 4) {
        if ((s8)((Actor36 *)arg0)->currentTrack.active == 0)
            ((Actor36 *)arg0)->currentTrack.blending = 1;
        if ((s8)((Actor36 *)arg0)->previousTrack.active == 0)
            ((Actor36 *)arg0)->previousTrack.blending = 1;
        if ((s8)((Actor36 *)arg0)->currentTrack.active == 0 && !(((Actor36 *)arg0)->flags & 0x400))
            return;
        if (!(((Actor36 *)arg0)->flags & 0x2000))
            return;
    }

    resource = func_8025193C_de(0, ((Actor36 *)arg0)->animationKey, ((Actor36 *)arg0)->animationKey,
        ((((Actor36 *)arg0)->animationCount * 4) + 0xF) & ~7, 4, 0, 0,
        &D_800C3930_de + 4, 0);
    if (resource == 0)
        return;

    track0 = &((Actor36 *)(arg0))->currentTrack;
    track1 = &((Actor36 *)(arg0))->previousTrack;
    func_80261670_de(track0, (s32)*resource, ((Actor36 *)arg0)->animationKey, 1, &active, track1);
    if (func_802624D8_de(track0) != 0) {
        void *entry;
        func_8026193C_de(track0, &first, &first_value, arg0);
        value = first_value;
        saved = first;
        if (active != 0 && ((Anim *)track1)->current != -1) {
            u16 count;
            entry = func_80262564_de(track0);
            if (((AnimationBlendEntry *)entry)->frames != 0) {
                ((Actor36 *)arg0)->flags |= 0x400;
                count = ((AnimationBlendEntry *)entry)->frames;
                ((Actor36 *)arg0)->blendTime = 0.0f;
                ((Actor36 *)arg0)->blendFrames = count;
                ((Actor36 *)arg0)->blendStart = ((AnimationBlendEntry *)entry)->start;
                ((Actor36 *)arg0)->blendEnd = ((AnimationBlendEntry *)entry)->end;
            } else {
                ((Actor36 *)arg0)->flags &= ~0x400;
            }
        }
        if (((Actor36 *)arg0)->flags & 0x400) {
            func_80261670_de(track1, (s32)*resource, ((Actor36 *)arg0)->animationKey, 0, 0, 0);
            if (func_802624D8_de(track1) != 0) {
                f32 time;
                f32 end;
                time = ((Actor36 *)arg0)->blendTime + D_800D2988;
                end = (f32)((Actor36 *)arg0)->blendFrames;
                ((Actor36 *)arg0)->blendTime = time;
                if (end < time) {
                    ((Actor36 *)arg0)->flags &= ~0x400;
                } else {
                    f32 a = (f32)((Actor36 *)arg0)->blendEnd;
                    f32 b = (f32)((Actor36 *)arg0)->blendStart;
                    f32 t = time / (end + D_800D2988);
                    ((Actor36 *)arg0)->blend = (((a + D_800C3948_de + b) * t * t * t) +
                        ((((&D_800C3948_de)[1] - a) - (2.0f * b)) * t * t) + (b * t));
                    func_8026193C_de(&((Actor36 *)(arg0))->previousTrack, &second, &second_value, arg0);
                    func_80271FC8_de(&saved, ((Actor36 *)arg0)->blend, &second, &first);
                    value = func_80273EE4_de(((Actor36 *)arg0)->blend, second_value, first_value);
                }
                func_802624A8_de(track1);
            } else {
                ((Actor36 *)arg0)->flags &= ~0x400;
            }
        }
        func_802624A8_de(track0);
        if (((Actor36 *)arg0)->flags & 0x20000) {
            ((Actor36 *)arg0)->heading -= value;
            func_80274020_de(&((Actor36 *)(arg0))->heading);
            saved.z = saved.y;
            saved.y = 0.0f;
            func_802736D4_de(&matrix, ((Actor36 *)arg0)->heading);
            func_80272898_de(&matrix, &saved, &moved);
            ((Actor36 *)arg0)->position.x += moved.x * ((Actor36 *)arg0)->scaleX;
            ((Actor36 *)arg0)->position.z += moved.z * ((Actor36 *)arg0)->scaleZ;
        } else if (!(((Actor36 *)arg0)->flags & 0x300000) && ((Actor36 *)arg0)->ownerId == 0x137) {
            ((Actor36 *)arg0)->heading -= value;
            func_80274020_de(&((Actor36 *)(arg0))->heading);
        }
    }
    func_80253754_de(0, (s32)resource);
}
