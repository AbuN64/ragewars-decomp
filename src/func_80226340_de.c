#include "shared/gameplay_transition.h"
#include "common/unused.h"
#include "span_1000/code_80233920.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80225D10.h"
#include "types.h"

/* Runs a player's hold on a carried object: while the player has a view at 0x5DC, one frame in five
   on average it tints the view through func_802391AC_de with a random alpha below 7.5 and plays effect
   D_80145088 at the view's position; the hold time at 0x1D4 counts down by the frame time D_800D2988,
   and once it runs out or the hold flag at 0x5E4 is clear the player drops flag 0x800000, is released
   through func_802227F4_de, and lets go of the object at 0x13D8 through func_80216488_de (flags 0x30200 when
   the object is a carried actor with option 0x200, 0x4600 otherwise) before forgetting it and applying
   the result through func_80219A40_de. */









extern f32 D_800D2988;
#include "shared/menu_match_globals.h"

extern void func_802394BC_de(char *, f32, f32, f32, f32, s32, Triple);
extern void func_802227F4_de(SharedPlayer_func_80226340_de *, SharedPlayer_func_80226340_de *, s32);
extern void func_80216488_de(Slot *, Held *, s32, f32, s32, s32);
extern void func_80219A40_de(SharedPlayer_func_80226340_de *, char *, Slot *);

void func_80226340_de(SharedPlayer_func_80226340_de *player) {
    Slot hit;
    View_func_80226340_de *view;
    Held *owner;
    f32 alpha;
    s32 level;

    if (player->views5DC.view5DC_2.view != 0 && 80.0f < func_80274564_de(100.0f)) {
        view = player->views5DC.view5DC_2.view;
        alpha = func_80274564_de(7.5f);
        level = (u32) alpha;
        func_802391AC_de(view, 0xFF, 0xFF, 0, 0, (u8) level, 3, 7);
        func_802394BC_de(&D_80145088, 0.0f, 204.79999f, 0.0f, 512.0f, 0, view->position);
    }
    player->views1C.view1D4_21.holdTime -= D_800D2988;
    if (player->views1C.view1D4_21.holdTime <= 0.0f || player->views5E4.view5E4_4.holding == 0) {
        owner = 0;
        if (player->views13D8.view13D8_1.held->type == 1 && (player->views13D8.view13D8_1.held->flags & 0x300000)) {
            owner = player->views13D8.view13D8_1.held;
        }
        player->views1C.view100_9.flags &= ~0x800000;
        func_802227F4_de(player, player, 2);
        if (owner->options & 0x200) {
            func_80216488_de(&hit, player->views13D8.view13D8_1.held, 0x30200, 25.599998f, 0x80, 0);
        } else {
            func_80216488_de(&hit, player->views13D8.view13D8_1.held, 0x4600, 25.599998f, 0x80, 0);
        }
        player->views13D8.view13D8_1.held = 0;
        func_80219A40_de(player, player->views1C.view170_16.body, &hit);
    }
}

extern char D_800CE7E4;
extern f32 D_800C2B48_de[];






extern void **D_80103FCC;
extern char D_80103FD0;


extern void func_802231D4_de(void *, void *, void *);
extern void func_8021CF28_de(Shared_Quad *, void *, void **, Shared_Quad *);
extern f32 func_802726F8_de(f32 *, f32 *);
extern s32 func_802444A4_de(void *, Vec3, Vec3, void *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_80271AA8_de(Vec3 *);

extern void func_80274870_de(f32 *, f32, f32);










void func_80226548_de(void *arg0, void *arg1) {
    Shared_Quad sp20;
    Shared_Quad sp30;
    Vec3 sp40;
    void *sp50;
    f32 sp54;
    f32 *position;
    f32 temp_f1;

    func_802231D4_de(arg0, arg1, &D_800CE7E4);
    if (((Shared_ActorView *)arg0)->targeting != 0) {
        func_8021CF28_de(&sp20, arg0, &sp50, &sp30);
        if (sp50 != 0) {
            position = &((Shared_ActorView *)arg0)->position.vector.x;
            if (!(D_800C2B48_de[1] < func_802726F8_de(position, &((Shared_ActorView *)sp50)->position.vector.x))) {
                if (func_802444A4_de(arg0, ((Shared_ActorView *)arg0)->position.vector,
                                     ((Shared_ActorView *)sp50)->position.vector,
                                     &D_80103FD0) == 0 ||
                    *D_80103FCC == sp50) {
                    func_80271F68_de(&sp40, &((Shared_ActorView *)sp50)->position.vector, (Vec3 *)position);
                    sp54 = func_80271AA8_de(&sp40);
                    func_80274020_de(&sp54);
                    func_80274020_de(&((LevelActor *)arg1)->yaw);
                    temp_f1 = ((LevelActor *)arg1)->yaw;
                    if (D_800C2B50_de < temp_f1) {
                        if (sp54 < D_800C2B54_de) {
                            sp54 += D_800C2B58_de;
                        } else {
                            goto positive;
                        }
                    } else {
positive:
                        temp_f1 = sp54;
                        if (D_800C2B5C_de < temp_f1 &&
                            ((LevelActor *)arg1)->yaw < D_800C2B60_de) {
                            ((LevelActor *)arg1)->yaw =
                                ((LevelActor *)arg1)->yaw + D_800C2B64_de;
                        }
                    }
                    func_80274870_de(&((LevelActor *)arg1)->yaw, sp54, D_800C9FEC);
                }
            }
        }
    }
}
