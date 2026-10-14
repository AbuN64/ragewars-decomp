#include "common/unused.h"
#include "span_1000/code_8027A0F4.h"
#include "span_1000/code_8028308C.h"

#include "shared/particle_attachment.h"

/* Transform the measured attachment position and direction into the target frame. */
extern ParticleAttachmentState D_801041F0;



extern void func_80270910_de(f32 *out, void *in);
extern void func_8026EF58_de(f32 *out, f32 *m);
extern void func_80272898_de(void *, void *, void *);
extern void func_8027207C_de(f32 *);
extern void func_80272B38_de(void *matrix, void *input, void *output);


void func_80283C1C_de(void *arg0, f32 *arg1, s32 arg2) {
    f32 source[16];
    f32 matrix[16];
    Vec3 direction;
    void *actor;
    s32 mode;
    Shared_ParticleTarget *current;
    f32 *matrix_ptr;
    SceneState *scene;
    Vec3 *direction_ptr;

    actor = arg0;
    mode = arg2;
    current = D_801041F0.current;
    if (arg1 != 0) {
        func_8026EF58_de(matrix, arg1);
    } else {
        func_80270910_de(source,
            &current->drawMatrices[D_801041F0.frame]);
        func_8026EF58_de(matrix, source);
    }
    matrix_ptr = matrix;
    scene = &D_801001F8;
    func_80272898_de(matrix_ptr, scene, &((Shared_Particle *)actor)->attachmentPosition);
    direction_ptr = &direction;
    direction = scene->direction;
    func_8027207C_de((f32 *)direction_ptr);
    func_80272B38_de(matrix_ptr, direction_ptr, &((Shared_Particle *)actor)->inst.velocity);
    ((Shared_Particle *)actor)->target = current;
    ((Shared_Particle *)actor)->flags |= 0x10000;
    ((Shared_Particle *)actor)->unk1D1 = scene->actor_byte;
    if (((Shared_Particle *)actor)->inst.type == 0x56 && mode == 2) {
        ((Shared_Particle *)actor)->flags |= 0x04000000;
    }
}
