#include "include_asm.h"
#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "SCENE/802508E0_9.H"
#include "RENDER_4/8028FD2C_6.H"



extern s32 Render_LocatePackSection(s32, s32, s32, s32 *);




f32 func_8024BEDC_de(void *target) {
    float temp_f12 = ((LevelActor *)target)->scale.x;
    float temp_f1 = ((LevelActor *)target)->scale.y;
    float temp_f0 = ((LevelActor *)target)->scale.z;
    return func_802B72B0_de(((temp_f12 * temp_f12) + (temp_f1 * temp_f1) + (temp_f0 * temp_f0)) * (0.3333333432674408f));
}

f32 func_8024BF24_de(void *arg0) {
    f32 result;
    void **temp_s0;

    result = D_800C3B5C;
    if (((LevelActor *)arg0)->flags & 0x40000) {
        temp_s0 = Scene_RequestResource(0, ((LevelActor *)arg0)->resource, ((LevelActor *)arg0)->resource, ((LevelActor *)arg0)->resourceFlags, 4, 0, 0, &D_800C3AE8_de, 1);
        if (temp_s0 != 0) {
            result = RW_BITS_TO_FLOAT((s32) ((ActorResourceHeader *)Render_GetPackSection(*temp_s0, 0))->particleScale);
            Scene_UnlockResource(0, temp_s0);
        }
    }
    return result;
}

void **func_8024BFD4_de(MenuPanelRoot *actor, s32 arg1) {
    void **resource;

    if (arg1 < 0) {
        return 0;
    }
    if (arg1 != actor->selected) {
        resource = Scene_RequestResource(0, actor->resource,
                                 actor->resource, actor->resourceSize,
                                 0, 0, 0, &D_800C3B28, 1);
        if (resource != 0) {
            actor->selectedResource = Render_LocatePackSection((s32)*resource,
                                                actor->resource,
                                                arg1 % *(s32 *)*resource,
                                                &actor->window);
            actor->selected = arg1;
            Scene_UnlockResource(0, resource);
        }
    }
    if (actor->selectedResource != 0) {
        return Scene_RequestResource(0, actor->selectedResource,
                             actor->selectedResource, actor->window,
                             0, 0, &D_0026D814, &D_800C3B3C, 0);
    }
    return 0;
}

#if defined(VERSION_EU_X)
void func_8024C134_eu_x(void) {
}
#endif

#if defined(VERSION_EU_X)
void func_8024C13C_eu_x(void) {
}
#endif

#if defined(VERSION_EU)
void func_8024C104_eu(void) {
}
#endif

#if defined(VERSION_EU)
void func_8024C10C_eu(void) {
}
#endif
