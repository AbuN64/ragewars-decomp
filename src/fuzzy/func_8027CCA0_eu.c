#include "shared/particle_lifecycle.h"
extern ParticleAttachmentState D_801041F0;
extern Vec3 D_801001F8, D_801042C8;
extern s32 D_80100204;
extern u8 D_80100207;
extern ParticleAttachmentState *D_80103FCC;
extern Entry802AB8DC D_800CC134[];
extern LiveParticle *D_8013D538;
extern u8 D_8011026D, D_801462E5;
extern char D_801379C0, D_8013B1A8, D_8011D8D0;
s32 func_8024E2C4_de(void *);
s32 func_80216108_de(void *);
void func_80270910_de(f32 *, void *);
void func_80247F18_de(void *, void *, void *, Vec3, Vec3, s32);
void func_8026EF58_de(f32 *, f32 *);
void func_80272898_de(f32 *, Vec3 *, Vec3 *);
void func_8027207C_de(Vec3 *);
void func_80272B38_de(f32 *, Vec3 *, Vec3 *);
void func_80284178_de(void *);
void func_802A42F4_de(void *, void *);
s32 func_8024E140_de(void *);
void func_80265E10_de(void *, void *, u16, s32, Vec3, struct IntPair);
void func_80279B40_de(void *, s32, s32, s32);
void func_8025DE54_de(s16, Vec3, s32, void *);
void func_802737F0_de(f32 *, f32);
void func_80284570_de(void *, void *);
static __inline__ void attachParticle(Shared_Particle *particle, f32 *transform, s32 action) {
    f32 localTransform[16];
    f32 inverse[16];
    Vec3 direction;
    Shared_ParticleTarget *attached;
    ParticleAttachmentState *scene;
    attached=D_801041F0.current;
    if (transform) func_8026EF58_de(inverse, transform);
    else {
        func_80270910_de(localTransform, &attached->drawMatrices[D_801041F0.frame]);
        func_8026EF58_de(inverse, localTransform);
    }
    scene=&D_801041F0;
    func_80272898_de(inverse, &scene->origin, &particle->attachmentPosition);
    direction=scene->direction;
    func_8027207C_de(&direction);
    func_80272B38_de(inverse, &direction, &particle->inst.velocity);
    particle->flags|=0x10000;
    particle->target=attached;
    particle->unk1D1=scene->frameBytes[3];
    if (particle->inst.type==0x56 && action==2) particle->flags|=0x4000000;
}
void func_8027CCA0_eu(LiveParticle *actor) {
    ParticleActionPair primary, secondary;
    f32 boneMatrix[16];
    s32 handle, mode, enabled, hasMatrix, action, special;
    s32 model, effect, sound, extraEffect; u16 type;
    Shared_ParticleTarget *source, *owner, *hit;
    void *other;
    struct Shared_ParticleEvents *actions;
    struct Shared_ParticleEvents *extraActions;
    struct Shared_ParticleDesc *definition;
    ParticleAttachmentState *context;
    s32 draw; s32 *bone;
    owner=0;
    source=D_801041F0.current;
    special=0;
    enabled=1;
    hasMatrix=0;
    definition=actor->particle.desc;
    if (func_8024E2C4_de(source)) mode=actor->particle.unk1B9;
    else mode=actor->particle.mode0;
    if (!actor->particle.inst.unk14) actor->particle.inst.unk14=0;
    bone=&D_801041F0.frame;
    if (*bone!=-1) {
        action=func_80216108_de(source);
        if (action!=9) {
            action=D_801041F0.mode;
            if (actor->particle.inst.type==13) action=4;
            owner=D_801041F0.current;
            if (owner->flags&0x3000000) {
                context=&D_801041F0;
                hasMatrix=1;
                func_80270910_de(boneMatrix, &owner->bones[context->frame]);
                if (owner->flags&0x1000000) {
                    func_80247F18_de(owner, &owner->unk170, boneMatrix, context->origin, context->direction, context->frame);
                }
                if (owner->flags&0x2000000) {
                    type=actor->particle.inst.type;
                    if (type==0x12a || type==0x132) {
                        if (*owner->category==11) {
                            special=owner->extraUses<1;
                            if (special) owner->extraUses++;
                        }
                    }
                    if (actor->particle.inst.type==0x56 || actor->particle.inst.type==2 || actor->particle.inst.type==0x126 || actor->particle.inst.type==15 ||
                        special || (actor->particle.inst.type==11 && (D_8011026D&3)==1)) {
                        attachParticle(&actor->particle, boneMatrix, action);
                        if (actor->particle.drawWhenHidden) {
                            func_80284178_de(actor);
                            func_802A42F4_de(&D_801379C0, actor);
                        }
                        handle=actor->particle.handle;
                        if (handle) { func_80268C7C_de(&D_8013B1A8, handle); actor->particle.handle=0; }
                    }
                }
            }
        }
    } else action=func_80216108_de(source);
    if (action==5) { action=4; actor->particle.flags|=2; }
    if (func_80284068_de(actor) && action<6 && action>=4) action=6;
    actions=definition->events;
    model=actions->particles[action]; effect=actions->effects[action];
    primary.words=actions->parameters[action];
    sound=definition->events->sounds[action];
    if (source->kind==1) {
        owner=source;
        if (owner->callback) owner->callback(owner, &owner->unk170, actor);
        if (func_8024E140_de(owner)) enabled=0;
        if (owner->unk170&2) enabled=0;
    }
    if (effect!=0xffff) {
        if (D_800CC134[effect].offset&4) {
            if (actor->particle.inst.type==0x56) primary.control.lower=primary.control.lower*actor->scale;
        }
        other=source;
        if (D_800CC134[effect].offset&2) other=actor;
        func_80265E10_de(other, actor, effect, -1, D_801001F8, primary.words);
    }
    if (action!=4) {
        draw=1;
        if (D_801462E5) {
            draw=*source->category!=11;
            if (mode==actor->particle.unk1B9) draw=0;
        }
        if (draw) {
            extraActions=definition->events;
            extraEffect=extraActions->effects[4];
            if (extraEffect!=0xffff) {
                secondary.words=extraActions->parameters[4];
                if (D_800CC134[extraEffect].offset&4) {
                    other=source;
                    if (D_800CC134[extraEffect].offset&2) other=actor;
                    func_80265E10_de(other, actor, extraEffect, -1, D_801001F8, secondary.words);
                }
            }
        }
    }
    if (model!=0xffff) func_80279B40_de(actor, model, -8, enabled);
    if (sound!=0xffff) func_8025DE54_de((s16)sound, D_801001F8, 0, actor);
    if (!(actor->particle.flags&0x30000)) {
        if (actor->particle.inst.type==0x3ef && D_8013D538 && owner->bones && D_8013D538->particle.inst.type==0x41e && action!=9) {
            D_8013D538->particle.rot=D_80103FCC->point;
            if (!hasMatrix) func_80270910_de(boneMatrix, &owner->bones[D_80100204]);
            func_802737F0_de(boneMatrix, 3.141593f);
            hit=D_80103FCC->current;
            if (hit->kind==1) {
                if (*hit->category==2) func_80270910_de(boneMatrix, &owner->bones[D_80100204]);
                hit=D_80103FCC->current;
                if (hit->kind==1 && (hit->flags&0x300000 || *hit->category==2)) {
                    attachParticle(&D_8013D538->particle, boneMatrix, action);
                }
            }
        }
        if (mode==1 || (effect!=0xffff && D_800CC134[effect].offset&1)) {
            func_80284570_de(&D_8011D8D0, actor);
            func_80284434_de(actor);
        }
    }
}
