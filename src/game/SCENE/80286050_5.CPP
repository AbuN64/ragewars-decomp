#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/SCENERECAT10C0.H"
#include "SCENE/80286050.H"
#include "SCENE/802508E0_4.H"
#include "particle/80271B18_3.H"
#include "RENDER_4/8028FD2C_6.H"

extern DraftStreamPair D_801031F8;
extern char D_00285160[];
extern s32 func_8028FE3C_de(void *, s32, s32, s32 *);
extern void **func_80254408_de(s32, void *, s32, s32, void *, void *, void *);
extern void func_80253670_de(void *, Node80253610 *);
extern void func_80253754_de(void *, Node80253610 *);

void func_80288470_de(DraftStreamWorld *world)
{
    s32 xCount, firstX, count;
    DraftStreamCell *cells;
    DraftStreamViewer *viewers, *viewer;
    DraftStreamTable *table;
    f32 *xLow, *xHigh, *zLow, *zHigh;
    DraftStreamCell *cell;
    DraftStreamHandle *resource;
    DraftStreamEntry *entry;
    s32 zCount, lastX, firstZ, lastZ;
    s32 x, z, row, loaded, size, visible, slot;

    viewers = (void *)D_80140FE8_de.object;
    if (viewers) {
        firstX = count = 0;
        table = func_8028FDB4_de(world->grid, 0);
        firstZ=0;
        xLow = table->data.coordinates;
        xCount = table->count;
        table = func_8028FDB4_de(world->grid, 1);
        xHigh = table->data.coordinates;
        lastX = xCount - 1;
        table = func_8028FDB4_de(world->grid, 2);
        zLow = table->data.coordinates;
        zCount = table->count;
        table = func_8028FDB4_de(world->grid, 3);
        zHigh = table->data.coordinates;
        table = func_8028FDB4_de(world->grid, 4);
        lastZ = zCount - 1;
        cells = table->data.cells;
        while (firstX < xCount && xHigh[firstX] < D_801031F0.min.x) firstX++;
        while (lastX >= 0 && D_801031F8.second < xLow[lastX]) lastX--;
        while (firstZ < zCount && zHigh[firstZ] < D_801031F8.first) firstZ++;
        while (lastZ >= 0 && D_800FF200.second < zLow[lastZ]) lastZ--;
        entry = world->entries;
        { s32 focusX,focusZ;
        if (world->specialEnabled == 1) {
            focusX = (s32)((viewers->position.x - world->originX) / world->cellX);
            focusZ = (s32)((viewers->position.z - world->originZ) / world->cellZ);
        } else focusZ = focusX = -1;
        if (focusX < 0 || focusX >= xCount || focusZ < 0 || focusZ >= zCount) world->specialPresent = 0;
        else {
            world->specialPresent = 1;
            world->special = (void *)func_80254408_de(0, world->specialTable, focusX + focusZ * xCount + 1,
                world->resourceKey, world, D_00285160, D_800C5220_de);
            func_80253670_de(0, (void *)world->special);
            func_80296020_de(world->specialState, focusX, focusZ, world->special->data, &viewers->position);
        }
        }
        z = firstZ;
        if(z<=lastZ) {
        row = z * xCount;
        do {
            for (x = firstX, slot=x+row; x <= lastX; x++,slot=x+row) {
                        cell = &cells[slot];
                if (cell->occupied) continue;
                visible = 0;
                for (viewer = viewers; viewer; viewer = viewer->next) {
                    if (viewer->minimum.x < cell->maxX && cell->minX < viewer->maximum.x &&
                        cell->maxZ > viewer->minimum.z && cell->minZ < viewer->maximum.z) {
                        visible = 1;
                        break;
                    }
                }
                if (visible) {
                    loaded = func_8028FE3C_de(world->table, world->key, slot, &size);
                    resource = func_8025193C_de(0, loaded, loaded, size, 8, world,
                                              D_0028798C, D_800C5210_de, 0);
                    if (resource) {
                        if (resource->data->count) {
                            entry->resource = resource;
                            entry->cell = cell;
                            entry->x = x;
                            entry->z = z;
                            entry++;
                            count++;
                            if (count == 128) goto finished;
                        } else func_80253754_de(0,(void *)resource);
                    }
                }
            }
            row+=xCount; z++;
        } while(z<=lastZ);
        }
finished:
        world->entryCount = count;
        world->activeCount = count;
    }
}

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
typedef struct SceneBuffer { s32 stride,count; u8 data[0]; } SceneBuffer;
typedef struct SceneHandle { s32 *data; s32 rest[3]; } SceneHandle;
typedef struct SceneCell { u8 pad0[16]; s32 loaded; } SceneCell;
typedef struct SceneProp { u8 pad0[0x20]; SceneHandle *resource; u8 pad24[4]; u32 matrix[16]; u8 pad68[0x70]; u16 flags; u8 padDA[14]; } SceneProp;
typedef struct ScenePoint { s16 x,y,z; } ScenePoint;
typedef struct SceneWorld { u8 pad0[0x30]; s32 id; u8 pad34[0x30]; s32 catalog; s32 *grid; u8 pad6C[0x1C]; s32 *packed; u8 pad8C[0x6C]; SceneHandle *handle; u8 padFC[0x1B200]; f32 maximumHeight; } SceneWorld;
extern Gfx *D_80110634;
extern char D_0028798C[],D_800C5210_de[],D_800C522C_de[];
extern void func_8026D980_de(void),func_8026D9D0_de(void);
extern SceneHandle *func_8025343C_de(s32,s32,u32,void *);
extern s32 func_80250A64_de(SceneProp *);
extern s32 func_80250A8C_de(SceneProp *);
extern SceneHandle **func_80250B24_de(SceneProp *,s32,s32,SceneHandle **);
extern void func_802504B0_de(SceneProp *,s32);
extern SceneHandle *func_802507AC_de(SceneProp *,s32);
extern void func_80270910_de(f32 *,u32 *);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
static inline u32 *sceneMatrix(SceneProp *prop) { return prop->matrix; }
void func_80288938_de(SceneWorld *arg0) {
    f32 sp28[16];
    CVector3 position;
    CVector3 transformed;
    SceneHandle *sp88[3000];
    SceneProp *sp2F68[512];
    s32 sp3768;
    s32 sp376C;
    s32 sp3770;
    s32 sp3774;
    s32 sp3778;
    SceneCell *sp377C;
    s32 sp3780;
    SceneProp **sp3784;
    Gfx *sp3788;
    s32 sp378C;
    Gfx *temp_a1;
    Gfx *temp_a1_2;
    Gfx *temp_a1_3;
    Gfx *temp_a2;
    Gfx *temp_a2_2;
    Gfx *temp_a3;
    Gfx *temp_v0;
    SceneHandle *temp_v0_3;
    SceneHandle *temp_v0_5;
    f32 temp_fv0f;
    f32 var_fv0;
    SceneHandle **var_fp;
    s32 temp_a2_3;
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 *temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_t5;
    s32 temp_t5_2;
    s32 temp_v0_2;
    s32 *temp_v1;
    s32 var_s0;
    s32 var_s5;
    s32 var_s7;
    SceneBuffer *temp_s2;
    s8 *temp_v0_4;
    SceneProp *var_s1;
    SceneHandle *temp_v0_6;

    var_fp = sp88;
    sp3784 = sp2F68;
    sp3770 = 0;
    sp3788 = D_80110634;
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RNX, FRUSTRATIO_2);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RNY, FRUSTRATIO_2);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RPX, (u16)-FRUSTRATIO_2);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RPY, (u16)-FRUSTRATIO_2);
    func_8026D980_de();
    sp376C = ((SceneBuffer *)func_8028FDB4_de(arg0->grid, 0))->count;
    temp_s0 = ((SceneBuffer *)func_8028FDB4_de(arg0->grid, 2))->count;
    temp_s0_2 = temp_s0 - 1;
    sp377C = (void *)((u8 *)func_8028FDB4_de(arg0->grid, 4) + 8);
    sp3778 = temp_s0_2;
    sp3774 = sp376C - 1;
    if (temp_s0_2 >= 0) {
        sp378C = 0;
        do {
            var_s7 = 0;
            if (sp3774 >= 0) {
                do {
                    temp_a2_3 = var_s7 + sp378C;
                    if (sp377C[temp_a2_3].loaded == 0) {
                        temp_v0_2 = func_8028FE3C_de(arg0->catalog, arg0->id, temp_a2_3, &sp3768);
                        temp_v0_3 = func_8025193C_de(0, temp_v0_2, temp_v0_2, sp3768, 4, arg0, D_0028798C, D_800C5210_de, 1);
                        if (temp_v0_3 != 0) {
                            temp_s0_3 = temp_v0_3->data;
                            if (*temp_s0_3 != 0) {
                                func_80253670_de(0, temp_v0_3);
                                *var_fp = temp_v0_3;
                                var_fp++;
                                temp_v0_4 = func_8028FDB4_de(temp_s0_3, 0);
                                var_s5 = 0;
                                temp_t5_2 = ((SceneBuffer *)(void *)temp_v0_4)->count;
                                sp3780 = temp_t5_2;
                                if (temp_t5_2 > 0) {
                                    var_s1 = (void *)(temp_v0_4 + 8);
                                    do {
                                        if (!(var_s1->flags & 0x40)) {
                                            var_s1->resource = temp_v0_3;
                                            if ((var_s1->flags & 4) || (func_80250A64_de(var_s1) < 0)) {
                                                *sp3784 = var_s1;
                                                sp3784++;
                                            } else {
                                                temp_s0_4 = func_80250A64_de(var_s1);
                                                var_fp = func_80250B24_de(var_s1, temp_s0_4, func_80250A8C_de(var_s1), var_fp);
                                                func_802504B0_de(var_s1,0);
                                            }
                                            temp_v0_5 = func_802507AC_de(var_s1, func_80250A8C_de(var_s1));
                                            if (temp_v0_5 != 0) {
                                                var_s0 = 0;
                                                temp_s2 = func_8028FDB4_de(temp_v0_5->data, 0);
                                                temp_s6 = temp_s2->count;
                                                func_80270910_de(sp28, sceneMatrix(var_s1));
                                                if (temp_s6 > 0) {
                                                    do {
                                                        temp_lo = var_s0 * temp_s2->stride;
                                                        position.x = (f32) ((ScenePoint *)(void *)((u8 *)temp_s2 + (temp_lo + 8)))->x;
                                                        position.y = (f32) ((ScenePoint *)(void *)((u8 *)temp_s2 + (temp_lo + 8)))->y;
                                                        position.z = (f32) ((ScenePoint *)(void *)((u8 *)temp_s2 + (temp_lo + 8)))->z;
                                                        func_80272898_de(sp28, &position, &transformed);
                                                        var_fv0 = transformed.y;
                                                        temp_fv0f = arg0->maximumHeight;
                                                        if (!(var_fv0 <= temp_fv0f)) {
                                                            var_fv0 = temp_fv0f;
                                                        }
                                                        var_s0 += 1;
                                                        arg0->maximumHeight = var_fv0;
                                                    } while (var_s0 < temp_s6);
                                                }
                                                func_80253754_de(0, temp_v0_5);
                                            }
                                        }
                                        var_s5 += 1;
                                        var_s1++;
                                    } while (var_s5 < sp3780);
                                }
                            }
                            func_80253754_de(0, temp_v0_3);
                        }
                    }
                    var_s7 += 1;
                } while (sp3774 >= var_s7);
            }
            sp378C += sp376C;
            temp_t5 = sp3770 + 1;
            sp3770 = temp_t5;
        } while (sp3778 >= temp_t5);
    }
    *var_fp = 0;
    *sp3784 = 0;
    sp3784++;
    func_8026D9D0_de();
    var_fp++;
    temp_s3 = (u8 *)var_fp - (u8 *)sp88;
    temp_s0_5 = ((temp_s3 + 7) & ~7) + 0x18;
    temp_s5 = (u8 *)sp3784 - (u8 *)sp2F68;
    temp_s6 = temp_s0_5;
    temp_s0_5 += ((temp_s5 + 7) & ~7);
    temp_a1_3 = D_80110634;
    D_80110634++;
    gSPEndDisplayList(temp_a1_3);
    
    temp_s1 = (u8 *)D_80110634 - (u8 *)sp3788;
    temp_v0_6 = func_8025343C_de(0, temp_s0_5 + ((temp_s1 + 7) & ~7), 3U, D_800C522C_de);
    arg0->handle = temp_v0_6;
    temp_v1 = temp_v0_6->data;
    arg0->packed = temp_v1;
    *temp_v1 = 3;
    arg0->packed[1] = 0x18;
    arg0->packed[2] = temp_s6;
    arg0->packed[3] = temp_s0_5;
    func_802BD3A0_de(func_8028FDB4_de(arg0->packed, 0), sp88, temp_s3);
    func_802BD3A0_de(func_8028FDB4_de(arg0->packed, 1), sp2F68, temp_s5);
    func_802BD3A0_de(func_8028FDB4_de(arg0->packed, 2), sp3788, temp_s1);
    D_80110634 = sp3788;
}
#else
INCLUDE_ASM("span_1000", func_80288938_de);
#endif
