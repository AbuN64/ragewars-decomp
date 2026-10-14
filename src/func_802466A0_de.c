#include "common/unused.h"
#include "shared/particle_lighting.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80245980.h"
#include "types.h"
/* Spawns and initializes an actor with model, transforms, collision body, effects and default bounds. */









extern World_func_802466A0_de D_8011FE88;
extern char *D_80140F84;

extern void *D_800CB440_de[];
extern char D_800CA8C4_de;
extern void D_0024A7A0();
extern s32 func_8028B21C_de(void *, s32);
extern void func_80246184_de(char *);
extern Vector4f func_8024D870_de(char *);
extern void func_80262480_de(char *);
extern void func_8024B65C_de(char *, s32);
extern void func_802727D8_de(char *);
#if defined(VERSION_EU)
extern void func_80213ACC_eu(char *, char *, void *);
#elif defined(VERSION_EU_X)
extern void func_80213ACC_eu_x(char *, char *, void *);
#elif defined(VERSION_US)
extern void func_80213AAC_us(char *, char *, void *);
#elif defined(VERSION_US_REV1)
extern void func_80213AAC_us_rev1(char *, char *, void *);
#else
extern void func_80213AAC_de(char *, char *, void *);
#endif
extern void func_802193C8_de(char *, s32, char *);
extern void func_80246BE8_de(char *, s32, s32, s32);
extern s32 func_80250BF0_de(void);




static inline void *body_setup(char *obj) {
    u32 kind;
    s32 i;
    char *player;

    kind = *((LevelActor *)obj)->definition;
    if (kind >= 15) {
        return 0;
    }
    if (kind == 11) {
        for (i = 0; i < D_80145048; i++) {
            player = D_80140F84 + i * 0x16E8;
            if (player == obj) {
                return 0;
            }
            if (player + 0x2E8 == obj) {
                return &D_800CA8C4_de;
            }
        }
    }
    return D_800CB440_de[kind];
}

void func_802466A0_de(char *obj, s32 model, s32 kind, s32 unused, u32 *info, s32 effect, s32 owner, f32 heading,
                   Vec3 pos, s32 flags, Vec3 extent, Vec3 offset) {
    s32 lean;
    s32 delay;
    World_func_802466A0_de *world;

    ((LevelActor *)obj)->flags &= ~0x40000;
    if (model == -1) {
        model = func_8028B21C_de(&D_8011FE88, kind);
        if (model == -1) {
            return;
        }
    }
    func_80246184_de(obj);
    *(u8 *)obj = 1;
    ((LevelActor *)obj)->modelIndex = model;
    ((LevelActor *)obj)->definition = info;
    ((LevelActor *)obj)->model = owner;
    ((LevelActor *)obj)->yaw = heading;
    ((LevelActor *)obj)->position0 = pos;
    ((LevelActor *)obj)->flags = flags;
    ((LevelActor *)obj)->scale = extent;
    ((LevelActor *)obj)->position1 = offset;
    ((LevelActor *)obj)->type = kind;
    ((LevelActor *)obj)->rotation = func_8024D870_de(obj);
    ((LevelActor *)obj)->eyeHeight = 0;
    ((LevelActor *)obj)->stateE6 = 0;
    ((LevelActor *)obj)->stateE7 = 0;
    ((LevelActor *)obj)->state139 = 0;
    ((LevelActor *)obj)->state138 = 0;
    ((LevelActor *)obj)->renderFlags = 0x17800074;
    func_80262480_de((char *)obj + 0x104);
    func_80262480_de((char *)obj + 0x118);
    func_8024B65C_de(obj, 0);
    ((LevelActor *)obj)->flags = (((LevelActor *)obj)->flags & ~0x400) | 0x2100;
    func_802727D8_de((char *)obj + 0x74);
    ((LevelActor *)obj)->fieldB4 = 0;
    ((LevelActor *)obj)->fieldB8 = 0;
    ((LevelActor *)obj)->shadow = 0;
    ((LevelActor *)obj)->state13B = 0;
    ((LevelActor *)obj)->flags |= 0x10000;
    ((LevelActor *)obj)->flags |= 0x20000;
    if (*((LevelActor *)obj)->definition == 0 || (((LevelActor *)obj)->flags & 1)) {
        ((LevelActor *)obj)->flags &= ~0x20000;
    }
    lean = 0;
    delay = 0;
    
#if defined(VERSION_EU)
func_80213ACC_eu
#elif defined(VERSION_EU_X)
func_80213ACC_eu_x
#elif defined(VERSION_US)
func_80213AAC_us
#elif defined(VERSION_US_REV1)
func_80213AAC_us_rev1
#else
func_80213AAC_de
#endif
(obj, obj + 0x170, body_setup(obj));
    if (((LevelActor *)obj)->collisionEnabled != 0) {
        lean = -((LevelActor *)obj)->lean;
    }
    ((LevelActor *)obj)->controller = 0;
    if (effect != -1) {
        func_802193C8_de(obj + 0x204, effect, (char *)obj + 0x8);
    }
    world = &D_8011FE88;
    func_80246BE8_de(obj, world->gravity, world->radius, lean);
    if (delay != 0) {
        ((LevelActor *)obj)->animationTime = delay;
        ((LevelActor *)obj)->flags &= ~0x400;
    }
    ((LevelActor *)obj)->flags2E4 = func_80250BF0_de() << 10;
    if (((LevelActor *)obj)->flags & 8) {
        ((LevelActor *)obj)->update = D_0024A7A0;
        ((LevelActor *)obj)->lighting[0] = D_800D0EF8;
        ((LevelActor *)obj)->lighting[1] = D_800D0EF8;
    }
}
