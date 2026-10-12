#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef struct ParticleActionPair { s16 upper, lower; s32 last; } ParticleActionPair;
typedef struct ParticleActions { ParticleActionPair parameters[14]; u16 models[14], effects[14], sounds[14]; } ParticleActions;
typedef struct Shared_ParticleDesc { s32 flags; u8 reserved4[0x14]; ParticleActions *actions; } Shared_ParticleDesc;
typedef struct ParticleBone { f32 words[16]; } ParticleBone;
typedef struct Shared_ParticleTarget Shared_ParticleTarget;
struct Shared_ParticleTarget {
    u8 kind; u8 reserved1[0x17]; s32 *category;
    u8 reserved1C[0x9C]; ParticleBone *bones;
    u8 reservedBC[0x44]; s32 flags;
    u8 reserved104[0x6C]; u32 state;
    u8 reserved174[0x114]; void (*callback)(Shared_ParticleTarget *, u32 *, void *);
    u8 reserved28C[0x1158]; s32 extraUses;
};
typedef struct Shared_ParticleInstance {
    u8 reserved0[4]; u16 type; u8 reserved6[2]; Vec3 pos;
    s32 unk14; void *category; Vec3 velocity; u8 reserved28[0x28];
} Shared_ParticleInstance;
typedef struct Shared_Particle {
    Shared_ParticleInstance inst; Vec3 attachmentPosition; s32 flags;
    u8 reserved60[0xB8]; Shared_ParticleDesc *desc;
    u8 reserved11C[0x18]; Shared_ParticleTarget *target; s32 handle;
    u8 reserved13C[0x44]; Vec3 rot;
    u8 reserved18C[0x2C]; s8 mode0, unk1B9; u8 reserved1BA[0x17]; s8 unk1D1;
    u8 reserved1D2[7]; u8 drawWhenHidden; u8 reserved1DA[6]; f32 scale;
} Shared_Particle;
typedef struct Shared_CollisionResult {
    Shared_ParticleTarget *actor; s32 reserved4; Vec3 origin; s32 bone;
    u8 reserved18[0x66]; u8 mode; u8 reserved7F[0x59]; Vec3 direction;
    u8 reservedE4[0xC]; Vec3 point;
} Shared_CollisionResult;
typedef struct ParticleEffect { u32 flags; s32 data; } ParticleEffect;
extern Shared_CollisionResult D_801041F0;
extern Vec3 D_801001F8, D_801042C8;
extern s32 D_80100204;
extern u8 D_80100207;
extern Shared_CollisionResult *D_80103FCC;
extern ParticleEffect D_800CC134[];
extern Shared_Particle *D_8013D538;
extern u8 D_8011026D, D_801462E5;
extern char D_801379C0, D_8013B1A8, D_8011D8D0;
s32 func_8024E2C4_de(void *);
s32 func_80216108_de(void *);
void func_80270910_de(f32 *, ParticleBone *);
void func_80247F18_de(void *, void *, void *, Vec3, Vec3, s32);
void func_8026EF58_de(f32 *, f32 *);
void func_80272898_de(f32 *, Vec3 *, Vec3 *);
void func_8027207C_de(Vec3 *);
void func_80272B38_de(f32 *, Vec3 *, Vec3 *);
void func_80284178_de(void *);
void func_802A42F4_de(void *, void *);
s32 func_8024E140_de(void *);
void func_80265E10_de(void *, void *, u16, s32, Vec3, ParticleActionPair);
void func_80279B40_de(void *, s32, s32, s32);
void func_8025DE54_de(s32, Vec3, s32, void *);
void func_802737F0_de(f32 *, f32);
void func_80284570_de(void *, void *);
void func_8027CCA0_eu(Shared_Particle *actor) {
    ParticleActionPair primary, secondary;
    f32 boneMatrix[32];
    f32 matrix[16];
    Vec3 direction;
    s32 handle, mode, enabled, hasMatrix, action, special;
    u16 model, effect, sound, extraEffect, type;
    Shared_ParticleTarget *source, *owner, *hit;
    Shared_Particle *otherParticle;
    void *other;
    ParticleActions *actions;
    Shared_ParticleDesc *definition;
    Shared_CollisionResult *context;
    s32 draw; s32 *bone;
    owner=0;
    source=D_801041F0.actor;
    special=0;
    enabled=1;
    hasMatrix=0;
    definition=actor->desc;
    if (func_8024E2C4_de(source)) mode=actor->unk1B9;
    else mode=actor->mode0;
    if (!actor->inst.unk14) actor->inst.unk14=0;
    context=&D_801041F0; bone=&context->bone;
    if (*bone!=-1) {
        action=func_80216108_de(source);
        if (action!=9) {
            action=context->mode;
            if (actor->inst.type==13) action=4;
            owner=context->actor;
            if (owner->flags&0x3000000) {
                hasMatrix=1;
                func_80270910_de(boneMatrix, &owner->bones[*bone]);
                if (owner->flags&0x1000000) {
                    func_80247F18_de(owner, &owner->state, boneMatrix, D_801001F8, D_801042C8, *bone);
                }
                if (owner->flags&0x2000000) {
                    type=actor->inst.type;
                    if (type==0x12a || type==0x132) {
                        if (*owner->category==11) {
                            special=owner->extraUses<1;
                            if (special) owner->extraUses++;
                        }
                    }
                    if (actor->inst.type==0x56 || actor->inst.type==2 || actor->inst.type==0x126 || actor->inst.type==15 ||
                        special || (actor->inst.type==11 && (D_8011026D&3)==1)) {
                        other=D_801041F0.actor;
                        func_8026EF58_de(matrix, boneMatrix);
                        func_80272898_de(matrix, &D_801001F8, &actor->attachmentPosition);
                        direction=D_801042C8;
                        func_8027207C_de(&direction);
                        func_80272B38_de(matrix, &direction, &actor->inst.velocity);
                        actor->flags|=0x10000;
                        actor->target=other;
                        actor->unk1D1=D_80100207;
                        if (actor->inst.type==0x56 && action==2) actor->flags|=0x4000000;
                        if (actor->drawWhenHidden) {
                            func_80284178_de(actor);
                            func_802A42F4_de(&D_801379C0, actor);
                        }
                        handle=actor->handle;
                        if (handle) { func_80268C7C_de(&D_8013B1A8, handle); actor->handle=0; }
                    }
                }
            }
        }
    } else action=func_80216108_de(source);
    if (action==5) { action=4; actor->flags|=2; }
    if (func_80284068_de(actor) && action<6 && action>=4) action=6;
    actions=definition->actions;
    model=actions->models[action]; effect=actions->effects[action];
    primary.upper=actions->parameters[action].upper; primary.lower=actions->parameters[action].lower; primary.last=actions->parameters[action].last;
    sound=definition->actions->sounds[action];
    if (source->kind==1) {
        owner=source;
        if (owner->callback) owner->callback(owner, &owner->state, actor);
        if (func_8024E140_de(owner)) enabled=0;
        if (owner->state&2) enabled=0;
    }
    if (effect!=0xffff) {
        if (D_800CC134[effect].flags&4) {
            if (actor->inst.type==0x56) primary.lower=primary.lower*actor->scale;
        }
        other=source;
        if (D_800CC134[effect].flags&2) other=actor;
        func_80265E10_de(other, actor, effect, -1, D_801001F8, primary);
    }
    if (action!=4) {
        draw=1;
        if (D_801462E5) {
            draw=*source->category!=11;
            if (mode==actor->unk1B9) draw=0;
        }
        if (draw) {
            actions=definition->actions;
            extraEffect=actions->effects[4];
            if (extraEffect!=0xffff) {
                secondary=actions->parameters[4];
                if (D_800CC134[extraEffect].flags&4) {
                    other=source;
                    if (D_800CC134[extraEffect].flags&2) other=actor;
                    func_80265E10_de(other, actor, extraEffect, -1, D_801001F8, secondary);
                }
            }
        }
    }
    if (model!=0xffff) func_80279B40_de(actor, model, -8, enabled);
    if (sound!=0xffff) func_8025DE54_de(sound, D_801001F8, 0, actor);
    if (!(actor->flags&0x30000)) {
        if (actor->inst.type==0x3ef && D_8013D538 && owner->bones && D_8013D538->inst.type==0x41e && action!=9) {
            D_8013D538->rot=D_80103FCC->point;
            if (!hasMatrix) func_80270910_de(boneMatrix, &owner->bones[*bone]);
            func_802737F0_de(boneMatrix, 3.141593f);
            hit=D_80103FCC->actor;
            if (hit->kind==1) {
                if (*hit->category==2) func_80270910_de(boneMatrix, &owner->bones[*bone]);
                hit=D_80103FCC->actor;
                if (hit->kind==1 && (hit->flags&0x300000 || *hit->category==2)) {
                    otherParticle=D_8013D538;
                    source=D_801041F0.actor;
                    func_8026EF58_de(matrix,boneMatrix);
                    func_80272898_de(matrix,&D_801001F8,&otherParticle->attachmentPosition);
                    direction=D_801042C8;
                    func_8027207C_de(&direction);
                    func_80272B38_de(matrix,&direction,&otherParticle->inst.velocity);
                    otherParticle->target=source;
                    otherParticle->flags|=0x10000;
                    otherParticle->unk1D1=D_80100207;
                    if (otherParticle->inst.type==0x56 && action==2) otherParticle->flags|=0x4000000;
                }
            }
        }
        if (mode==1 || (effect!=0xffff && D_800CC134[effect].flags&1)) {
            func_80284570_de(&D_8011D8D0, actor);
            func_80284434_de(actor);
        }
    }
}
