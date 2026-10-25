#include "include_asm.h"
#include "ANIM/RAY180.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/WORLD.H"
#include "COMMON/OUTPUT.H"
#include "COMMON/OBJB.H"
#include "COMMON/TRIPLE.H"
#include "ANIM/802412C0_7.H"
#include "RENDER_4/8028FD2C_6.H"

extern void Rsp_MultiplyAffineMatrices(void *, void *, void *);


extern void *func_8028B2F8_de(Shared_World *, u16 *);

extern void func_80240CAC_de(QueryE0 *arg0);

/** Swap two pairs of words. */
void func_80243814_de(Hit8 *arg0, Hit8 *arg1) {
    Hit8 temporary = *arg0;
    *arg0 = *arg1;
    *arg1 = temporary;
}

s32 func_80243850_de(Hit8 *a, Hit8 *b) {
    s32 order;
    order = 1;
    if ((a->t) < (b->t)) {
        order = -1;
    }
    return order;
}

void func_80243874_de(void *contextAddress) {
    void *temp_a1;
    void **temp_s0;
    void *temp_s0_2;
    s32 *temp_v0;
    s32 temp_s1;
    s32 index;

    temp_a1 = ((ContextB0 *)contextAddress)->element;
    temp_s0 = ((ElementE8 *)temp_a1)->resource;
    if (temp_s0 != 0) {
        Rsp_MultiplyAffineMatrices(&((ContextB0 *)contextAddress)->transform, &((ElementE8 *)temp_a1)->transform, (char *) contextAddress + 0xC);
        temp_s0_2 = *temp_s0;
        ((ContextB0 *)contextAddress)->vertices = Render_GetPackSection(temp_s0_2, 0);
        temp_v0 = Render_GetPackSection(temp_s0_2, 2);
        temp_s1 = *temp_v0;
        index = 0;
        if (temp_s1 > 0) {
            do {
                Anim_TraceMeshDisplayList(contextAddress, Render_GetPackSection((void *) temp_v0, index));
                index += 1;
            } while (index < temp_s1);
        }
    }
}

void func_80243920_de(ActorB0 *actor) {
    extern s32 func_8023E8D4_de(ActorB0 *, QueryE0 *, s32);
    QueryE0 query;
    u8 *data;
    s32 *flags;
    void *resource;
    s32 i;
    f32 height;

    data = actor->data;
    flags = actor->flags;
    if (data != 0) {
        resource = func_8028B2F8_de(&D_8011FE88, (u16 *)data);
        if (resource != 0) {
          if ((*flags & 8) != 0) {
           if ((*flags & 0x100000) == 0) {
            query.word14 = 3;
            for (i = 0; i < 3; i++) {
                query.vectors[2 - i].x = ((CollisionBuildTriangle *)data)->fields.v[i]->x;
                query.vectors[2 - i].y = ((CollisionBuildTriangle *)data)->fields.v[i]->ceiling +
                                         actor->height;
                query.vectors[2 - i].z = ((CollisionBuildTriangle *)data)->fields.v[i]->z;
            }
            func_80240CAC_de(&query);
            height = query.result.y;
            if ((0.10000000149011612f) < height) {
                query.word0 = 5;
                query.word4 = ((MotionSurface *)flags)->materialResponse;
                query.word8 = ((MotionSurface *)flags)->materialKind;
                query.input = 0;
                query.index = -1;
                query.word10 = 0;
                if ((((Shared_Surface *)resource)->flags & 0x400000) != 0) {
                    query.wordC = 7;
                } else if ((((Shared_Surface *)resource)->flags52 & 0x80) != 0) {
                    query.wordC = 8;
                } else {
                    query.wordC = 1;
                }
                func_8023E8D4_de(actor, &query, 1);
            }
           }
          }
        }
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C36B4[3] = {
    0x08000F00, 0x00000000, 0x0C6D5F44,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C3A74[3] = {
    0x4F000000, 0x47800000, 0x4F000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3784[3] = {
    0xBF350481, 0x434CCCCC, 0x3F800000,
};
#endif
