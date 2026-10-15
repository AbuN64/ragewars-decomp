#include "span_1000/code_8026AC38.h"
#include "abi.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/types_1dc8418c21db.h"
#include "gbi.h"
#include "n64sdk.h"
#include "span_1000/code_8026E1F8.h"
#include "types.h"

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

extern void func_80253754_de(s32 arg0, s32 arg1);

extern s32 D_80111318[];

extern Frame118 *D_8011BDC0;

extern u32 D_800E28A4;

extern void *func_8028FDB4_de(void *table, s32 index);

extern s32 func_8026B504_de(s32 matrix, s32 lights, void *material);

extern s32 func_80269A80_de(void *material, s32 pass);

extern s32 D_8010C564;

extern char D_801157D8;

extern void *func_8028FDB4_de(void *, s32);

extern void func_80253670_de(s32, s32);

extern void func_8026C484_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern void func_8026925C_de(s32 mode);

extern void *func_8028FDB4_de(void *arg0, s32 arg1);

extern void **func_80295EAC_de(void *arg0, s32 arg1);

void func_8026D844_de(void) {
    char local[64];

    func_8026D8F8_de();
    func_80272CB0_de(local, D_800C46AC_de, D_800C46AC_de, D_800C46AC_de);
    func_8026FC9C_de(local, &D_8010C520);
}

void func_8026D88C_de(void) {
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

void func_8026D914_de(s32 arg0) {
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
    extern void func_80253BBC_de(s32 arg0, s32 arg1);
    s32 temp_s0;
    s32 var_s1;

    func_8026BC60_de();
    var_s1 = 0;
    func_8026C020_de();
    if (D_80111310 > 0) {
        do {
            temp_s0 = D_80111318[var_s1];
            func_80253BBC_de(0, temp_s0);
            func_80253754_de(0, temp_s0);
            var_s1 += 1;
        } while (var_s1 < D_80111310);
    }
}

void func_8026DA4C_de(void **resource, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    extern void func_80253BBC_de(s32 heap, void **resource);
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
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

void func_8026DC24_de(void **a, s32 b, s32 c, void *d, s32 e, s32 f) {
    s32 temp_v1;
    s32 temp_v0;
    s32 var_s0;
    char *temp_v1_2;
    void *temp_a0;
    s32 *countp;
    s32 count;
    s32 *queue_countp;

    temp_a0 = *a;
    var_s0 = e;
    if (var_s0 == 0) {
        var_s0 = (s32)func_8028FDB4_de(temp_a0, 0);
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
        temp_v1 = temp_v0 * 0x10;
        temp_v0 += 1;
        *queue_countp = temp_v0;
        temp_v1_2 = temp_v1 + &D_801157D8;
        ((struct MeasuredRecAt0V1 *)(temp_v1_2))->value = b;
        ((struct MeasuredRecAtCV1 *)(temp_v1_2))->value = c;
        ((struct MeasuredRecAt4V1 *)(temp_v1_2))->value = d;
        ((struct MeasuredRecAt8V1 *)(temp_v1_2))->value = var_s0;
    }
}

void func_8026DD50_de(void **resource, s32 unused, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    extern void func_80253BBC_de(s32 heap, void **resource);
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
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

void func_8026DF30_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8026C484_de(arg0, arg1, arg2, arg3, arg4, 1);
}

void func_8026DF58_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8026C484_de(arg0, arg1, arg2, arg3, arg4, 0);
}

void func_8026DF7C_de(void *shared, s32 mode, void **resource, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    extern void func_80253BBC_de(s32 heap, void **resource);
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (func_80269A80_de(shared, pass) == 0) {
        return;
    }
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    if (mode != -1) {
        func_8026925C_de(mode);
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
