#include "COMMON/MODEL_RENDER.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/UNUSED.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/OBJECTSTATE18.H"
#include "abi.h"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "gbi.h"
#include "COMMON/OBJRECAT4V7.H"
#include "TYPES.H"
#include "RENDER_4/8026AC38_2.H"
#include "RENDER_4/8026AC38_3.H"
#include "RENDER_4/8028FD2C_6.H"
#include "SCENE/802508E0_9.H"

extern void func_80272CB0_de(void *, float, float, float);

extern void func_8026FC9C_de(void *, void *);

extern float D_800C46AC_de;

extern char D_8010C520;

extern s32 D_800CC380;

extern s32 D_80110620;

extern s32 D_800CC384;

extern int D_800CC364;

extern Gfx *D_80110634;

extern s32 D_8010C568;

extern s32 D_8010C56C;

extern s32 D_8010C570;

extern s32 D_8010C578;

extern s32 D_8010C57C;

extern s32 D_80110640;

extern s32 D_8010C584;

extern s32 D_8011064C;

extern s32 D_80111310;


extern s32 D_80111318[];

#include "COMMON/DISPLAY.H"

extern u32 D_800E28A4;


extern s32 func_8026B504_de(void *matrix, void *lights, void *material);

extern s32 func_80269A80_de(void *material, s32 pass);

extern s32 D_8010C564;

extern ObjRecAtCV2 D_801157D8[];


extern void func_80253670_de(s32, s32);

extern void func_8026C484_de(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);

extern void Render_SetModePreset(s32 mode);


extern void **func_80295EAC_de(void *arg0, s32 arg1);

void func_8026D844_de(void) {
    char local[64];

    func_8026D8F8_de();
    func_80272CB0_de(local, D_800C46AC_de, D_800C46AC_de, D_800C46AC_de);
    func_8026FC9C_de(local, &D_8010C520);
}

void Render_SelectEffectModes(void) {
    if (D_800CC380 != 0 || D_80110620 != 0) {
        D_800CC384 = 0x10000;
        D_800CC388 = 0xC4000000;
        D_800CC38C = 0xC8000000;
        return;
    }
    D_800CC384 = 0;
    D_800CC388 = 0x0C080000;
    D_800CC38C = 0x0C080000;
}

/** Reset two global indices to minus one. */
void func_8026D8F8_de(void) {
    D_800CC364 = -1;
    D_800CC360 = -1;
}

void Render_SetColorDither(s32 arg0) {
    if (D_80110620 == 0) gDPSetColorDither(D_80110634++, arg0) else gDPSetColorDither(D_80110634++, G_CD_NOISE);
}

void func_8026D980_de(void) {
    D_8011064C = 0;
    D_80110640 = 0;
    D_8010C578 = 0;
    D_8010C570 = 0;
    D_80111310 = 0;
    D_8010C56C = 0;
    D_8010C568 = 0;
    D_8010C584 = 0;
    D_8010C57C = 0;
}

void func_8026D9D0_de(void) {
    s32 temp_s0;
    s32 i;

    func_8026BC60_de();
    i = 0;
    func_8026C020_de();
    if (D_80111310 > 0) {
        do {
            temp_s0 = D_80111318[i];
            func_80253BBC_de(0, temp_s0);
            func_80253754_de(0, temp_s0);
            i += 1;
        } while (i < D_80111310);
    }
}

void func_8026DA4C_de(void **resource, void *matrix, s32 segment, void *lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    func_80253BBC_de(0, resource);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = func_8028FDB4_de(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = func_8028FDB4_de(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        material = func_8028FDB4_de(part, 0);
        if (i == 0) {
            func_8026B504_de(matrix, lights, material);
        }
        if (func_80269A80_de(material, pass) != 0) {
            Gfx *cmd;
            void *list = func_8028FDB4_de(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

void Render_QueueModelInstance(void **a, void *b, s32 c, void *d, void *e, s32 f) {
    s32 temp_v0;
    void *var_s0;
    ObjRecAtCV2 *temp_v1_2;
    void *temp_a0;
    s32 *countp;
    s32 count;
    s32 *queue_countp;

    temp_a0 = *a;
    var_s0 = e;
    if (var_s0 == 0) {
        var_s0 = func_8028FDB4_de(temp_a0, 0);
    }
    if ((D_8011064C != (s32)a) || (D_8010C564 != f) || (D_80110640 == 0x20)) {
        func_8026BC60_de();
        if (D_80111310 != 0x100) {
            func_80253670_de(0, (s32)a);
            countp = &D_80111310;
            count = *countp;
            D_80111318[count] = (s32)a;
            *countp = count + 1;
            goto block_7;
        }
    } else {
block_7:
        D_8011064C = (s32)a;
        D_8010C564 = f;
        queue_countp = &D_80110640;
        temp_v0 = *queue_countp;
        temp_v1_2 = &D_801157D8[temp_v0];
        temp_v0 += 1;
        *queue_countp = temp_v0;
        temp_v1_2->unk0 = b;
        temp_v1_2->unkC = c;
        temp_v1_2->unk4 = d;
        temp_v1_2->unk8 = var_s0;
    }
}

void func_8026DD50_de(void **resource, s32 unused, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    func_80253BBC_de(0, resource);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = func_8028FDB4_de(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = func_8028FDB4_de(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        material = func_8028FDB4_de(part, 0);
        if (i == 0) {
            func_8026B504_de(matrix, lights, material);
        }
        if ((((unsigned char *)material)[6] & 0x38) == 0x38 && func_80269A80_de(material, pass) != 0) {
            Gfx *cmd;
            void *list = func_8028FDB4_de(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

void func_8026DF30_de(s32 model, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    func_8026C484_de(model, arg1, arg2, arg3, arg4, 1);
}

void func_8026DF58_de(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    func_8026C484_de(arg0, arg1, arg2, arg3, arg4, 0);
}

void func_8026DF7C_de(void *shared, s32 mode, void **resource, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (func_80269A80_de(shared, pass) == 0) {
        return;
    }
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    if (mode != -1) {
        Render_SetModePreset(mode);
    }
    func_80253BBC_de(0, resource);
    header = *resource;
    base = textures;
    if (base == 0) {
        base = func_8028FDB4_de(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = func_8028FDB4_de(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        material = func_8028FDB4_de(part, 0);
        if (i == 0) {
            func_8026B504_de(matrix, lights, material);
        }
        {
            Gfx *cmd;
            void *list = func_8028FDB4_de(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

void func_8026E158_de(void **arg0) {
    void *temp_v0;
    s32 count;
    s32 i;
    void *rec;
    s32 result;

    temp_v0 = func_8028FDB4_de(*arg0, 2);
    count = *(s32 *)temp_v0;
    for (i = 0; i < count; i++) {
        rec = func_8028FDB4_de(func_8028FDB4_de(temp_v0, i), 0);
        if (((ResourceSectionReference *)rec)->resource == 0) {
            continue;
        }
        result = func_80295EAC_de(&((ResourceSectionReference *)rec)->resource, -1);
        if (result == 0) {
            continue;
        }
        func_80253754_de(0, result);
    }
}
