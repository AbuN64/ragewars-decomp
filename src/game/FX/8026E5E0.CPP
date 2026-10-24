
/* Attachment event dispatch. Reference logic/order adapted to current symbols and shared types. */
#include "FX/EXTERNS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "FX/ATTACHMENT_EFFECT_ARGS.H"
#include "COMMON/OBJRECAT4V7.H"
#include "FX/8026E5E0.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "TYPES.H"
#include "particle/80271B18_3.H"

extern char D_8011D8D0;
extern void func_80271F9C_de(void *, void *, f32);
extern void func_8024E79C_de(void *, Triple, Triple *, s32 *, s32, s32);
extern struct Shape_typemap_165 func_80271818_de(Triple *);
#include "particle/8027A0F4_8.H"
extern void func_80265E10_de(void *, void *, s32, s32, Triple, AttachmentEffectArgs);

void Fx_DispatchAttachmentEffects(func_8026E5E0_S1 *arg0, s32 arg1, struct MatrixF *arg2, func_8026E5E0_S3 *actor, AttachmentTable *arg4) {
    Triple pos;
    Triple mapped;
    Triple zero;
    struct Shape_typemap_165 rotation;
    AttachmentEffectArgs params;
    s32 room;
    f32 temp_f0;
    f32 lifetime;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 var_s2;
    u16 temp_a0;
    u32 temp_v1;
    u8 *node;
    ObjRecAt4V7 *var_s3;

    arg1 = arg1 - 1;
    if (arg1 != -1) {
        do {
            var_s3 = (void *)&arg0->unkC;
            if (var_s3->unk0 & actor->unk2E0) {
                temp_a0 = var_s3->unk4;
                node = arg4->bytes + temp_a0 * arg4->stride;
                temp_s0 = (*node == 5) * 2;
                func_80272898_de(&arg2[temp_a0], arg0, &pos);
                func_80271F9C_de(&pos, &pos, 0.000015258789f);
                var_s2 = 0;
                temp_v1 = var_s3->unk0;
                switch (temp_v1) {                  /* irregular */
#if !defined(VERSION_DE)
                case 0x2:
                    func_80216288_de(actor, 0x51, pos, temp_s0);
                    break;
                case 0x8:
                    func_80216288_de(actor, 0x5C, pos, temp_s0);
                    break;
#endif
                case 0x1:
                case 0x4:
                case 0x10:
                case 0x20:
                    break;
                case 0x40:
                    actor->unk248 = pos;
                    temp_a0_2 = *actor->unk18;
                    if (((temp_a0_2 == 1) && (actor->unk1A4 == 0x21)) || ((temp_a0_2 == 0xB) && (actor->unk1D8->unk650 == 0x26))) {
                        func_8024E79C_de(actor, pos, &mapped, &room, 0, 1);
                        rotation = func_80271818_de(&actor->unk254);
                        zero.x = 0;
                        zero.y = 0;
                        zero.z = 0;
                        if (actor->unk1B0 <
#if defined(VERSION_US)
                            D_800C4960_eu
#elif defined(VERSION_EU)
                            D_800C4960_eu
#elif defined(VERSION_EU_X)
                            D_800C4960_eu
#elif defined(VERSION_DE)
                            D_800C46B0
#else
                            D_800C4960_eu
#endif
                        ) {
                            func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0xE6, *(CVector3 *)&zero, *(CQuatern *)&rotation, *(CVector3 *)&mapped, 0, -1, temp_s0 | 1);
                        }
                        func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)actor, (struct EffectActor *)actor, 0, 0, 0x8A, *(CVector3 *)&zero, *(CQuatern *)&rotation, *(CVector3 *)&mapped, 0, -1, temp_s0 | 1);
                    }
                    break;
                case 0x80:
                    func_80216288_de(actor, 0xAC, pos, temp_s0);
                    break;
                case 0x100:
                    func_80216288_de(actor, 0xAD, pos, temp_s0);
                    break;
                case 0x200:
                    func_80216288_de(actor, 0xAE, pos, temp_s0);
                    break;
                case 0x400:
                    func_80216288_de(actor, 0xAF, pos, temp_s0);
                    break;
                case 0x800:
                    func_80216288_de(actor, 0xB0, pos, temp_s0);
                    break;
                case 0x1000:
                    func_80216288_de(actor, 0xB1, pos, temp_s0);
                    break;
                case 0x2000:
                    func_80216288_de(actor, 0xB2, pos, temp_s0);
                    break;
                case 0x4000:
                    func_80216288_de(actor, 0xB3, pos, temp_s0);
                    break;
                case 0x8000:
                    func_80216288_de(actor, 0xB4, pos, temp_s0);
                    break;
                case 0x10000:
                    func_80216288_de(actor, 0xB5, pos, temp_s0);
                    break;
                case 0x20000:
                    func_80216288_de(actor, 0xB6, pos, temp_s0);
                    break;
                case 0x40000:
                    func_80216288_de(actor, 0xB7, pos, temp_s0);
                    break;
                case 0x80000:
                    func_80216288_de(actor, 0xB8, pos, temp_s0);
                    break;
                case 0x100000:
                    func_80216288_de(actor, 0xB9, pos, temp_s0);
                    break;
                case 0x200000:
                    func_80216288_de(actor, 0xBA, pos, temp_s0);
                    break;
                case 0x400000:
                    func_80216288_de(actor, 0xBB, pos, temp_s0);
                    break;
                case 0x20000000:
                    func_80216288_de(actor, 0x1E9, pos, temp_s0);
                    break;
                case 0x40000000:
                    func_80216288_de(actor, 0x1EA, pos, temp_s0);
                    break;
                case 0x80000000:
                    func_80216288_de(actor, 0x1EB, pos, temp_s0);
                    break;
                case 0x8000000:
                    func_80216288_de(actor, 0x11C, pos, temp_s0);
                    break;
                case 0x10000000:
                    actor->unk260 = pos;
                    break;
                case 0x800000:
                    var_s2 = 5;
                    break;
                case 0x1000000:
                    var_s2 = 0xA;
                    break;
                case 0x2000000:
                    var_s2 = 0xF;
                    break;
                case 0x4000000:
                    var_s2 = 0x14;
                    break;
                }
                if (var_s2 != 0) {
                    temp_f0 = func_8024BF24_de(actor);
                    params.fields.lifeRange = var_s2 << 8;
                    params.fields.countRange = 0;
                    params.fields.countBase = 0;
                    params.fields.modifier = 0;
                    params.fields.chance = 0;
#if defined(VERSION_US)
                    lifetime = D_800C4964_eu;
#elif defined(VERSION_EU)
                    lifetime = D_800C4964_eu;
#elif defined(VERSION_EU_X)
                    lifetime = D_800C4964_eu;
#elif defined(VERSION_DE)
                    lifetime = D_800C46B4;
#else
                    lifetime = D_800C4964_eu;
#endif
                    lifetime /= temp_f0;
#if defined(VERSION_US)
                    lifetime *= D_800C4968_eu;
#elif defined(VERSION_EU)
                    lifetime *= D_800C4968_eu;
#elif defined(VERSION_EU_X)
                    lifetime *= D_800C4968_eu;
#elif defined(VERSION_DE)
                    lifetime *= D_800C46B8;
#else
                    lifetime *= D_800C4968_eu;
#endif
                    params.fields.lifeBase = (s16)(s32)lifetime;
                    func_80265E10_de(actor, actor, 3, -1, pos, params);
                }
            }
            arg0++;
            arg1 -= 1;
        } while (arg1 != -1);
    }
}
