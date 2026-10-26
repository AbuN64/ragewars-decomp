#include "COMMON/MODEL_RENDER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/LONE/D_800CC384.H"
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







extern Gfx *g_displayListCursor;

extern s32 D_8010C568;

extern s32 D_8010C56C;



extern s32 D_8010C57C;


extern s32 D_8010C584;

extern s32 D_8011064C;




#include "COMMON/DISPLAY.H"



extern s32 Geometry_ApplyMaterialLighting(void *matrix, void *lights, void *material);

extern s32 Geometry_SetupMaterial(void *material, s32 pass);


extern ObjRecAtCV2 D_801157D8[];


extern void Cache_LockResource(s32, s32);

extern void func_8026C484_de(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);

extern void Geometry_SetModePreset(s32 mode);


extern void **func_80295EAC_de(void *arg0, s32 arg1);

void func_8026D844_de(void) {
    char local[64];

    func_8026D8F8_de();
    func_80272CB0_de(local, D_800C46AC_de, D_800C46AC_de, D_800C46AC_de);
    func_8026FC9C_de(local, &D_8010C520);
}

void Geometry_SelectEffectModes(void) {
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

void Geometry_SetColorDither(s32 arg0) {
    if (D_80110620 == 0) gDPSetColorDither(g_displayListCursor++, arg0) else gDPSetColorDither(g_displayListCursor++, G_CD_NOISE);
}

void Geometry_BeginModelBatch(void) {
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

void Geometry_FlushModelBatch(void) {
    s32 temp_s0;
    s32 i;

    func_8026BC60_de();
    i = 0;
    func_8026C020_de();
    if (D_80111310 > 0) {
        do {
            temp_s0 = D_80111318[i];
            Cache_MarkResourceInUse(0, temp_s0);
            Cache_UnlockResource(0, temp_s0);
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

    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    Cache_MarkResourceInUse(0, resource);
    if (segment != 0) { gSPSegment(g_displayListCursor++, 1, matrix); } else { gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = SetN64_GetPackSection(header, 0);
    }
    gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
    parts = SetN64_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = SetN64_GetPackSection(parts, i);
        material = SetN64_GetPackSection(part, 0);
        if (i == 0) {
            Geometry_ApplyMaterialLighting(matrix, lights, material);
        }
        if (Geometry_SetupMaterial(material, pass) != 0) {
            Gfx *cmd;
            void *list = SetN64_GetPackSection(part, 1);

            cmd = g_displayListCursor++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

void Geometry_QueueModelInstance(void **a, void *b, s32 c, void *d, void *e, s32 f) {
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
        var_s0 = SetN64_GetPackSection(temp_a0, 0);
    }
    if ((D_8011064C != (s32)a) || (D_8010C564 != f) || (D_80110640 == 0x20)) {
        func_8026BC60_de();
        if (D_80111310 != 0x100) {
            Cache_LockResource(0, (s32)a);
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

    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    Cache_MarkResourceInUse(0, resource);
    if (segment != 0) { gSPSegment(g_displayListCursor++, 1, matrix); } else { gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = SetN64_GetPackSection(header, 0);
    }
    gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
    parts = SetN64_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = SetN64_GetPackSection(parts, i);
        material = SetN64_GetPackSection(part, 0);
        if (i == 0) {
            Geometry_ApplyMaterialLighting(matrix, lights, material);
        }
        if ((((unsigned char *)material)[6] & 0x38) == 0x38 && Geometry_SetupMaterial(material, pass) != 0) {
            Gfx *cmd;
            void *list = SetN64_GetPackSection(part, 1);

            cmd = g_displayListCursor++;
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

    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (Geometry_SetupMaterial(shared, pass) == 0) {
        return;
    }
    if (segment != 0) { gSPSegment(g_displayListCursor++, 1, matrix); } else { gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD); }
    if (mode != -1) {
        Geometry_SetModePreset(mode);
    }
    Cache_MarkResourceInUse(0, resource);
    header = *resource;
    base = textures;
    if (base == 0) {
        base = SetN64_GetPackSection(header, 0);
    }
    gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
    parts = SetN64_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = SetN64_GetPackSection(parts, i);
        material = SetN64_GetPackSection(part, 0);
        if (i == 0) {
            Geometry_ApplyMaterialLighting(matrix, lights, material);
        }
        {
            Gfx *cmd;
            void *list = SetN64_GetPackSection(part, 1);

            cmd = g_displayListCursor++;
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

    temp_v0 = SetN64_GetPackSection(*arg0, 2);
    count = *(s32 *)temp_v0;
    for (i = 0; i < count; i++) {
        rec = SetN64_GetPackSection(SetN64_GetPackSection(temp_v0, i), 0);
        if (((ResourceSectionReference *)rec)->resource == 0) {
            continue;
        }
        result = func_80295EAC_de(&((ResourceSectionReference *)rec)->resource, -1);
        if (result == 0) {
            continue;
        }
        Cache_UnlockResource(0, result);
    }
}
