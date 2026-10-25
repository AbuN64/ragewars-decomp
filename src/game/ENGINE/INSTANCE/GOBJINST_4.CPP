#include "COMMON/WORLD.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/OBJRECAT5F14.H"
#include "ENGINE/INSTANCE/GOBJINST_4.H"
#include "GAME/CODE_8027302C.H"
#include "SCENE/802508E0_4.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"
#include "RENDER_4/8028FD2C_6.H"
#include "SCENE/802508E0_9.H"


extern void func_80261670_de(void *, s32, s32, s32, s32 *, void *);

extern s32 func_802624D8_de(void *);

extern void func_8026193C_de(void *, CVector3 *, f32 *, void *);

extern void *func_80262564_de(void *);

extern void func_80271FC8_de(CVector3 *, f32, CVector3 *, CVector3 *);

extern f32 func_80273EE4_de(f32, f32, f32);


extern f32 D_800D2988;

extern char D_800C3930_de;

/* Fires the effect events of an object's animation that fall within a frame window: only for the object's
 * own animation at 0x104 or an object flagged 0x4000000; each event whose frame lies in [from, to) is
 * placed from its local point through the object's matrix when it names no bone, otherwise through its
 * bone matrix (or at the object's position when it has none), and for models 0x44E, 0x451 and 0x453 an
 * effect flagged 4 fires only if its bone's hit box shares the object's mask; each fired event spawns its
 * effect through func_80265E10_de and is counted in D_800D06BC. */











extern Entry802AB8DC D_800CC134[];

extern CROMEventEntry *func_80262598_de(void *);

extern s32 func_802625C4_de(void *);

extern s32 *func_8024BFD4_de(char *, s8);

extern void Rsp_ConvertMatrixToFloat(f32 *, char *);

extern void func_80265E10_de(char *, char *, u16, s32, CVector3, struct IntPair);

/* Returns an actor's aiming orientation: a controlled actor turns a quarter turn about the vertical from its
 * weapon's orientation at 0x140, or from the player's own orientation from Weapons_BuildPlayerOrientation when unarmed; an
 * actor of kind 4 composes a pitch from 0x294 with a yaw from its heading 0x6C and applies them to its body
 * orientation from Turret_BuildPlaneRot; any other actor turns its orientation at 0x5C by its heading. Quaternions
 * are composed through func_80274098_de, keeping the latest sine in D_80115DEC. */



extern f32 D_80115DEC;

extern void func_80274098_de(CQuatern *, CQuatern *, CQuatern *);

extern void Weapons_BuildPlayerOrientation(void *, CQuatern *);

extern void Turret_BuildPlaneRot(CQuatern *, void *, void *);

/* Returns an actor's aim with auto-aim applied: with no assist cone the actor's aiming orientation from
 * func_8024796C_de is returned unchanged; otherwise, of the live entities other than the actor (not flagged 1,
 * with a body at 0x174), the one whose aim point (half its height above its top) lies most nearly along the
 * aim direction from the given point, within the cone (in degrees, halved), pulls the aim toward it by an
 * angle that fades with the fourth root of how far off-axis it is. The applied correction is also written
 * to the optional assist quaternion (identity when nothing is in range). */





extern char *D_8011CA18[];

extern CQuatern func_8024796C_de(char *);

extern void func_80274244_de(CQuatern *, f32 *);

extern f32 Particle_GetActorHeight(char *);

extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);


extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);

extern f32 func_802B72B0_de(f32);

extern s32 *func_8024BFD4_de(char *arg0, s8 arg1);

extern void func_80271F68_de(CVector3 *out, CVector3 *a, CVector3 *b);

extern void func_80272018_de(CVector3 *out, CVector3 *a, CVector3 *b);


extern void func_80271F9C_de(CVector3 *out, CVector3 *in, f32 scale);

/* Sways a model part: from the frame count D_800D2978, a per-part phase ((flags & 0x38) * 50, plus 40
 * unless flag 4 is set) and the part's time divided by 113, it reads a 120-step sine table at D_800D0720 to
 * build a rotation axis and angle for the part's sway mode (2: about a wobbling z/y axis, 0x82: doubled
 * about a wobbling x/y axis, 0x40: doubled about a fully wobbling axis, 1: 0.7 of the swing about y) and
 * applies that rotation to the part's matrix about its own origin; other modes leave it unchanged. */





extern SineTable D_800D0720;

extern s32 D_800D2978;

extern void func_8027302C(f32 *, f32 *);

extern void func_80271F9C_de(CVector3 *, CVector3 *, f32);

extern void func_80273448_de(f32 *, f32, f32, f32);

extern void func_80272D00_de(f32 *, f32, f32, f32, f32);

extern void func_8026F620_de(f32 *, f32 *, f32 *);

void func_802472F0_de(void *actor) {
    CVector3 first;
    CVector3 second;
    CVector3 saved;
    CVector3 moved;
    MatrixF matrix;
    s32 active;
    f32 first_value;
    f32 second_value;
    void **resource;
    void *track0;
    void *track1;
    f32 value;

    if (D_8011FE88.mode == 4) {
        if ((s8)((Actor36 *)actor)->currentTrack.active == 0)
            ((Actor36 *)actor)->currentTrack.blending = 1;
        if ((s8)((Actor36 *)actor)->previousTrack.active == 0)
            ((Actor36 *)actor)->previousTrack.blending = 1;
        if ((s8)((Actor36 *)actor)->currentTrack.active == 0 && !(((Actor36 *)actor)->flags & 0x400))
            return;
        if (!(((Actor36 *)actor)->flags & 0x2000))
            return;
    }

    resource = Scene_RequestResource(0, ((Actor36 *)actor)->animationKey, ((Actor36 *)actor)->animationKey,
        ((((Actor36 *)actor)->animationCount * 4) + 0xF) & ~7, 4, 0, 0,
        &D_800C3930_de + 4, 0);
    if (resource == 0)
        return;

    track0 = &((Actor36 *)(actor))->currentTrack;
    track1 = &((Actor36 *)(actor))->previousTrack;
    func_80261670_de(track0, (s32)*resource, ((Actor36 *)actor)->animationKey, 1, &active, track1);
    if (func_802624D8_de(track0) != 0) {
        void *entry;
        func_8026193C_de(track0, &first, &first_value, actor);
        value = first_value;
        saved = first;
        if (active != 0 && ((Anim *)track1)->current != -1) {
            u16 count;
            entry = func_80262564_de(track0);
            if (((AnimationBlendEntry *)entry)->frames != 0) {
                ((Actor36 *)actor)->flags |= 0x400;
                count = ((AnimationBlendEntry *)entry)->frames;
                ((Actor36 *)actor)->blendTime = 0.0f;
                ((Actor36 *)actor)->blendFrames = count;
                ((Actor36 *)actor)->blendStart = ((AnimationBlendEntry *)entry)->start;
                ((Actor36 *)actor)->blendEnd = ((AnimationBlendEntry *)entry)->end;
            } else {
                ((Actor36 *)actor)->flags &= ~0x400;
            }
        }
        if (((Actor36 *)actor)->flags & 0x400) {
            func_80261670_de(track1, (s32)*resource, ((Actor36 *)actor)->animationKey, 0, 0, 0);
            if (func_802624D8_de(track1) != 0) {
                f32 time;
                f32 end;
                time = ((Actor36 *)actor)->blendTime + D_800D2988;
                end = (f32)((Actor36 *)actor)->blendFrames;
                ((Actor36 *)actor)->blendTime = time;
                if (end < time) {
                    ((Actor36 *)actor)->flags &= ~0x400;
                } else {
                    f32 a = (f32)((Actor36 *)actor)->blendEnd;
                    f32 b = (f32)((Actor36 *)actor)->blendStart;
                    f32 t = time / (end + D_800D2988);
                    ((Actor36 *)actor)->blend = (((a + D_800C3948_de + b) * t * t * t) +
                        ((((&D_800C3948_de)[1] - a) - (2.0f * b)) * t * t) + (b * t));
                    func_8026193C_de(&((Actor36 *)(actor))->previousTrack, &second, &second_value, actor);
                    func_80271FC8_de(&saved, ((Actor36 *)actor)->blend, &second, &first);
                    value = func_80273EE4_de(((Actor36 *)actor)->blend, second_value, first_value);
                }
                func_802624A8_de(track1);
            } else {
                ((Actor36 *)actor)->flags &= ~0x400;
            }
        }
        func_802624A8_de(track0);
        if (((Actor36 *)actor)->flags & 0x20000) {
            ((Actor36 *)actor)->heading -= value;
            func_80274020_de(&((Actor36 *)(actor))->heading);
            saved.z = saved.y;
            saved.y = 0.0f;
            func_802736D4_de(&matrix, ((Actor36 *)actor)->heading);
            Particle_TransformPoint(&matrix, &saved, &moved);
            ((Actor36 *)actor)->position.x += moved.x * ((Actor36 *)actor)->scaleX;
            ((Actor36 *)actor)->position.z += moved.z * ((Actor36 *)actor)->scaleZ;
        } else if (!(((Actor36 *)actor)->flags & 0x300000) && ((Actor36 *)actor)->ownerId == 0x137) {
            ((Actor36 *)actor)->heading -= value;
            func_80274020_de(&((Actor36 *)(actor))->heading);
        }
    }
    Scene_UnlockResource(0, resource);
}

void func_802476C8_de(char *obj, void *anim, f32 from, f32 to) {
    CVector3 pos;
    CVector3 local;
    f32 matrix[16];
    CROMEventEntry *events;
    s32 count;
    s32 i;
    s32 checkMask;
    s32 fire;
    s32 *resource;
    struct Shape_typemap_13 *table;

    if (!(((struct ObjectLinks180 *) obj)->unk_100 & 0x4000000) && anim != obj + 0x104) {
        return;
    }
    switch (((struct ObjectLinks180 *) obj)->unk_E4) {
    case 0x44E:
    case 0x451:
    case 0x453:
        checkMask = 1;
        break;
    default:
        checkMask = 0;
        break;
    }
    table = 0;
    events = func_80262598_de(anim);
    count = func_802625C4_de(anim);
    resource = 0;
    for (i = 0; i < count; i++) {
        if (from <= (f32)events[i].frame && (f32)events[i].frame < to) {
            fire = 1;
            if (events[i].bone == -1) {
                local.x = events[i].local.x;
                local.y = events[i].local.z;
                local.z = events[i].local.y;
                Particle_TransformPoint(obj + 0x74, &local, &pos);
            } else {
                if (checkMask && (D_800CC134[events[i].effect].offset & 4)) {
                    if (resource == 0) {
                        resource = func_8024BFD4_de(obj, ((struct ObjectLinks180 *) obj)->unk_1);
                        if (resource == 0) {
                            goto masked;
                        }
                        table = Render_GetPackSection(*resource, 5);
                    }
                    fire = ((struct Shape_typemap_3 *) (((char *) table) + ((events[i].bone * table->field_0) + 0x74)))->field_0 & ((struct ObjectLinks180 *) obj)->unk_17C;
                }
            masked:
                if (fire == 0) {
                    continue;
                }
                if (((struct ObjectLinks180 *) obj)->unk_B8 != 0) {
                    Rsp_ConvertMatrixToFloat(matrix, ((struct ObjectLinks180 *) obj)->unk_B8 + (events[i].bone << 6));
                    Particle_TransformPoint(matrix, &events[i].local, &pos);
                } else {
                    pos = ((struct ObjectLinks180 *) obj)->unk_8;
                }
            }
            if (fire != 0) {
                func_80265E10_de(obj, obj, events[i].effect, -1, pos, events[i].params);
                D_800D06BC++;
            }
        }
    }
    if (resource != 0) {
        Scene_UnlockResource(0, resource);
    }
}

CQuatern func_8024796C_de(char *actor) {
    CQuatern result;
    CQuatern pitch;
    CQuatern yaw;
    CQuatern both;
    CQuatern base;
    CQuatern own;
    char *player;
    char *weapon;
    f32 angle;
    f32 sine;

    if (((LevelActor *)actor)->flags & 0x300000) {
        player = ((LevelActor *)actor)->controller;
        weapon = ((Shared_ActorView *)player)->message;
        if (weapon != 0) {
            angle = 1.5707964f;
            D_80115DEC = func_802B7130_de(angle);
            yaw.x = 0.0f;
            yaw.y = D_80115DEC;
            yaw.z = 0.0f;
            yaw.w = func_802B6560_de(angle);
            func_80274098_de(&result, &yaw, &((SharedRecAt564V1 *)weapon)->orientation);
        } else {
            angle = 1.5707964f;
            Weapons_BuildPlayerOrientation(player, &own);
            D_80115DEC = func_802B7130_de(angle);
            yaw.x = 0.0f;
            yaw.y = D_80115DEC;
            yaw.z = 0.0f;
            yaw.w = func_802B6560_de(angle);
            func_80274098_de(&result, &yaw, &own);
        }
    } else if (((LevelActor *)actor)->definition->kind == 4) {
        sine = func_802B7130_de(((LevelActor *)actor)->pitch * 0.5f);
        pitch.x = sine;
        pitch.y = 0.0f;
        pitch.z = 0.0f;
        angle = ((LevelActor *)actor)->pitch * 0.5f;
        D_80115DEC = sine;
        pitch.w = func_802B6560_de(angle);
        sine = func_802B7130_de((((LevelActor *)actor)->yaw + 3.1415927f) * 0.5f);
        yaw.x = 0.0f;
        yaw.y = sine;
        yaw.z = 0.0f;
        angle = (((LevelActor *)actor)->yaw + 3.1415927f) * 0.5f;
        D_80115DEC = sine;
        yaw.w = func_802B6560_de(angle);
        func_80274098_de(&both, &pitch, &yaw);
        Turret_BuildPlaneRot(&base, actor, (char *)actor + 0x170);
        func_80274098_de(&result, &both, &base);
    } else {
        sine = func_802B7130_de((((LevelActor *)actor)->yaw + 3.1415927f) * 0.5f);
        yaw.x = 0.0f;
        yaw.y = sine;
        yaw.z = 0.0f;
        angle = (((LevelActor *)actor)->yaw + 3.1415927f) * 0.5f;
        D_80115DEC = sine;
        yaw.w = func_802B6560_de(angle);
        func_80274098_de(&result, &yaw, &((LevelActor *)actor)->rotation);
    }
    return result;
}

CQuatern func_80247BB4_de(char *actor, CVector3 point, CQuatern *assist, f32 cone) {
    CVector3 dir;
    CVector3 local;
    CVector3 aim;
    CVector3 axis;
    CVector3 best;
    CVector3 center;
    CQuatern base;
    CQuatern turn;
    CQuatern result;
    f32 matrix[16];
    char *entity;
    char *target;
    s32 count;
    s32 i;
    f32 bestDot;
    f32 dot;
    f32 angle;

    local.x = 0.0f;
    local.y = 0.0f;
    local.z = 1.0f;
    base = func_8024796C_de(actor);
    if (cone == 0.0f) {
        if (assist != 0) {
            assist->x = assist->y = assist->z = 0.0f;
            assist->w = 1.0f;
        }
        return base;
    }
    func_80274244_de(&base, matrix);
    Particle_TransformPoint(matrix, &local, &aim);
    i = 0;
    target = 0;
    bestDot = func_802B6560_de(cone * 0.008726647f);
    count = D_8011FE88.registeredCount;
    for (; i < count; i++) {
        entity = D_8011CA18[i];
        if (entity == actor || (((LevelActor *)(entity))->flags & 1) || ((LevelActor *)(entity))->active == 0) {
            continue;
        }
        center = ((LevelActor *)(entity))->position0;
        center.y += ((LevelActor *)(entity))->eyeHeight;
        center.y += Particle_GetActorHeight(entity) * 0.5f;
        func_80271F68_de(&dir, &center, &point);
        func_8027207C_de(&dir);
        dot = aim.x * dir.x + aim.y * dir.y + aim.z * dir.z;
        if (bestDot < dot) {
            bestDot = dot;
            best = dir;
            target = entity;
        }
    }
    if (target != 0) {
        func_80272018_de(&axis, &aim, &best);
        func_8027207C_de(&axis);
        angle = func_802745D0_de(bestDot);
        angle *= func_802B72B0_de(func_802B72B0_de(1.0f - angle / (cone * 0.008726647f)));
        angle *= 0.5f;
        D_80115DEC = func_802B7130_de(angle);
        turn.x = axis.x * D_80115DEC;
        turn.y = axis.y * D_80115DEC;
        turn.z = axis.z * D_80115DEC;
        turn.w = func_802B6560_de(angle);
        func_80274098_de(&result, &base, &turn);
        if (assist != 0) {
            *assist = turn;
        }
        return result;
    }
    if (assist != 0) {
        assist->x = assist->y = assist->z = 0.0f;
        assist->w = 1.0f;
    }
    return base;
}

void func_80247F18_de(char *arg0, char *arg1, char *arg2, CVector3 arg3,
                   CVector3 arg6, s32 arg9) {
    CVector3 sp10;
    CVector3 sp20;
    CVector3 sp30;
    s32 *temp_v0;
    s32 *temp_v0_2;
    s32 var_a0;
    s32 var_v1;
    char *var_a1;

    if (arg1[0x34] != 0x3C) {
      if (arg1[0x12] < 0x17) {
       temp_v0 = func_8024BFD4_de(arg0, arg0[1]);
       if (temp_v0 != 0) {
        temp_v0_2 = Render_GetPackSection((void *)*temp_v0, 5);
        var_a1 = (char *)temp_v0_2 + ((arg9 * *temp_v0_2) + 8);
        var_a0 = arg9;
        if ((((u8 *)var_a1)[0x65] & 3) == 3) {
            Scene_UnlockResource(0, temp_v0);
            return;
        }
        var_v1 = 0;
        do {
            *(arg1 + var_v1 + 0x14) = var_a0;
            var_a0 = var_a1[0x64];
            var_v1++;
            if (var_a0 != -1) {
                var_a1 = (char *)temp_v0_2 + ((var_a0 * *temp_v0_2) + 8);
            }
        } while (var_v1 < 4);
        Scene_UnlockResource(0, temp_v0);
        arg1[0x12] = 0x19;
        sp20.x = ((Matrix *)arg2)->m[12];
        sp20.y = ((Matrix *)arg2)->m[13];
        sp20.z = ((Matrix *)arg2)->m[14];
        func_80271F68_de(&arg3, &arg3, &sp20);
        func_80272018_de(&sp10, &arg3, &arg6);
        func_8027207C_de(&sp10);
        func_8027207C_de(&arg3);
        func_8027207C_de(&arg6);
        func_80272018_de(&sp30, &sp10, &arg3);
        func_80271F9C_de(&sp10, &sp10,
                      (sp30.x * arg6.x) + (sp30.y * arg6.y) +
                          (sp30.z * arg6.z));
        func_8027207C_de(&sp10);
        ((Field_Vec_18 *)(arg1))->value = sp10;
       }
      }
    }
}

void func_802480F0_de(s32 time, s32 flags, f32 *matrix) {
    f32 rotation[16];
    f32 inverse[16];
    CVector3 origin;
    CVector3 axis;
    u32 t;
    f32 angle;
    f32 flip;
    s32 mode;

    t = D_800D2978;
    t += (flags & 0x38) * 50;
    t += (u32)(time & 0xFFFF) / 113;
    if (!(flags & 4)) {
        t += 40;
    }
    axis.x = 0.0f;
    axis.z = 0.0f;
    axis.y = 1.0f;
    mode = flags & 0xC3;
    if (mode == 2) {
        axis.z = 1.0f;
        axis.x = 0.0f;
        angle = D_800D0720.value[t % 120] - 0.5f;
        axis.y = D_800D0720.value[(t + 12) % 120];
    } else if (mode == 0x82) {
        axis.x = 1.0f;
        axis.z = 0.0f;
        angle = D_800D0720.value[t % 120] - 0.5f;
        axis.y = D_800D0720.value[(t + 12) % 120];
        angle *= 2.0f;
    } else if (mode == 0x40) {
        angle = D_800D0720.value[(t + 30) % 120] - 0.5f;
        axis.x = D_800D0720.value[(t + 12) % 120];
        axis.y = D_800D0720.value[(t + 42) % 120];
        axis.z = D_800D0720.value[(t + 110) % 120];
        angle *= 2.0f;
    } else if (mode == 1) {
        angle = D_800D0720.value[(t + 70) % 120] - 0.5f;
        angle *= 0.7f;
    } else {
        return;
    }
    func_8027207C_de(&axis);
    origin.x = matrix[12];
    origin.y = matrix[13];
    origin.z = matrix[14];
    func_8027302C(inverse, matrix);
    flip = -1.0f;
    func_80271F9C_de(&origin, &origin, flip);
    func_80273448_de(inverse, origin.x, origin.y, origin.z);
    func_80272D00_de(rotation, angle, axis.x, axis.y, axis.z);
    func_8026F620_de(matrix, inverse, rotation);
    func_80271F9C_de(&origin, &origin, flip);
    func_80273448_de(matrix, origin.x, origin.y, origin.z);
}
