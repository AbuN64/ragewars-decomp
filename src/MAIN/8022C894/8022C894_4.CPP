#include "span_1000/code_8022C894.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "span_1000/code_8022D56C.h"
#include "span_1000/code_8022D944.h"
#include "TYPES.H"

extern void func_8022D57C_de(void);


extern s32 func_8024E7DC_de(void *);

extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);

extern f32 func_80271AA8_de(Vec3 *arg0);

extern void func_80218464_de();

extern void func_80225F44_de(void);

extern void func_802227F4_de(void *arg0, void *arg1, int arg2);

void func_8022D60C_de(void) { func_8022D57C_de(); }

void func_8022D628_de(void *a, void *b) { func_80225B98_de(a, b, 0x32); }

void func_8022D644_de(void) { func_8022D57C_de(); }

void func_8022D660_de(void *a, void *b) { func_80225B98_de(a, b, 0x1E); }

void func_8022D67C_de(void) { func_8022D57C_de(); }

void func_8022D698_de(void *a, void *b) { func_80225B98_de(a, b, 0x28); }

void func_8022D6B4_de(void) { func_8022D57C_de(); }

void func_8022D6D0_de(void *a, void *b) { func_80225B98_de(a, b, 0xB); }

void func_8022D6EC_de(void) { func_8022D57C_de(); }

void func_8022D708_de(void *a, void *b) { func_80225B98_de(a, b, 0xC); }

void func_8022D724_de(void) { func_8022D57C_de(); }

void func_8022D740_de(void *a, void *b) { func_80225B98_de(a, b, 0xD); }

void func_8022D75C_de(void) { func_8022D57C_de(); }

void func_8022D778_de(void *a, void *b) { func_80225B98_de(a, b, 0xE); }

void func_8022D794_de(void) { func_8022D57C_de(); }

void func_8022D7B0_de(void *a, void *b) { func_80225B98_de(a, b, 0xF); }

void func_8022D7CC_de(void) { func_8022D57C_de(); }

void func_8022D7E8_de(void *a, void *b) { func_80225B98_de(a, b, 0x14); }

void func_8022D804_de(void) { func_8022D57C_de(); }

void func_8022D820_de(void *a, void *b) { func_80225B98_de(a, b, 0x46); }

void func_8022D83C_de(void) { func_8022D57C_de(); }

void func_8022D858_de(void *a, void *b) { func_80225B98_de(a, b, 0x3C); }

void func_8022D874_de(void) { func_8022D57C_de(); }

void func_8022D890_de(void *a, void *b) { func_80225B98_de(a, b, 0x47); }

/** Thin wrapper around func_8022D57C_de. */
void func_8022D8AC_de(void) {
    func_8022D57C_de();
}

/** Thin wrapper around func_80225B98_de with a fixed third argument. */
void func_8022D8C8_de(void *a, void *b) {
    func_80225B98_de(a, b, 0x48);
}

/** Thin wrapper around func_8022D57C_de. */
void func_8022D8E4_de(void) {
    func_8022D57C_de();
}

/** Thin wrapper around func_80225B98_de with a fixed third argument. */
void func_8022D900_de(void *a, void *b) {
    func_80225B98_de(a, b, 0x49);
}

/** Thin wrapper around func_8022D57C_de. */
void func_8022D91C_de(void) {
    func_8022D57C_de();
}

/** Thin wrapper around func_80225B98_de with a fixed third argument. */
void func_8022D938_de(void *a, void *b) {
    func_80225B98_de(a, b, 0x4A);
}

/** Thin wrapper around func_8022D57C_de. */
void func_8022D954_de(void) {
    func_8022D57C_de();
}

void func_8022D970_de(void *arg0, void *arg1) {
    char *o = (char *)arg0;
    char *a1 = (char *)arg1;
    s32 temp_v0;
    Vec3 sp10;
    Vec3 sp20;

    temp_v0 = func_8024E7DC_de(arg1);
    ((Shared_ActorView *)o)->effectModel = (void *)temp_v0;
    if (temp_v0 != 0) {
        ((Shared_ActorView *)o)->modelState = 0;
        ((Shared_ActorView *)o)->effectPosition.x = ((LevelActor *)a1)->position0.x;
        ((Shared_ActorView *)o)->effectPosition.y = ((LevelActor *)a1)->position0.y;
        ((Shared_ActorView *)o)->effectPosition.z = ((LevelActor *)a1)->position0.z;
        sp10.x = ((ModelBlend *)temp_v0)->effectOffset.x;
        sp10.y = ((ModelBlend *)temp_v0)->effectOffset.y;
        sp10.z = ((ModelBlend *)temp_v0)->effectOffset.z;
        func_80271F68_de(&sp20, &sp10, &((Shared_ActorView *)o)->effectPosition);
        sp20.y = 0.0f;
        ((Shared_ActorView *)o)->modelDistance = func_80271AA8_de(&sp20);
    }
}

void func_8022DA04_de(void *arg0) {
    struct Player *player = arg0;
    func_80218464_de(&player->weaponBusy);
    player->locked = 0;
}

void func_8022DA30_de(void *arg0, void *arg1) {
    struct SharedPlayer *a0 = arg0;
    void *a1 = arg1;

    func_80225F44_de();
    if (a0->views5E8.view6C0_51.unk6C0 != 0.0f) {
        func_802227F4_de(a0, a1, 0x25);
    }
}

void func_8022DA84_de(void *arg0) {
    struct Player *player = arg0;
    func_80218464_de(&player->weaponBusy);
    player->locked = 0;
}

void func_8022DAB0_de(void *arg0, void *arg1) {
    struct SharedPlayer *a0 = arg0;
    void *a1 = arg1;

    func_80225F44_de();
    if (a0->views5E8.view6C0_51.unk6C0 == 0.0f) {
        func_802227F4_de(a0, a1, 0x24);
    }
}

void func_8022DB04_de(Actor126 *actor, Object126 *arg1) {
    Object126 *object;
    f32 angle;
    f32 object_angle;
    f32 sine;
    f32 cosine;

    actor->flags |= 0x800000;
    actor->value1D4 = D_800C2DC8_de;
    if (actor->state652 == 15) {
        object = arg1;
        object_angle = object->angle;
        angle = D_800C2DCC_de;
        sine = func_802B7130_de(object_angle + angle);
        cosine = func_802B6560_de(object->angle + angle);
        sine *= D_800C7EC0;
        cosine *= D_800C7EC0;
        object->x += sine;
        object->y += cosine;
        object->angle += actor->offset728;
        actor->offset728 = 0.0f;
    }
}
