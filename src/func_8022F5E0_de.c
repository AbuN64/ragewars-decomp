#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022F3E8.h"
#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_80291054.h"







extern void *D_800D052C[];




extern void func_80271F9C_de(void *, void *, f32);
extern void func_80272CB0_de(void *, f32, f32, f32);
extern void func_802732D0_de(char *, f32 *);
extern void func_80226DD0_de(char *, Matrix *);
extern void func_80226C60_de(char *object, Vector4f *output);
extern void func_80274244_de(void *, void *);
extern void func_80273448_de(char *, f32, f32, f32);
extern void func_80273D6C_de(void *);
extern void func_8026F620_de(void *, void *, void *);







void func_8022F5E0_de(char *arg0) {
    Vec3 sp10;
    Matrix sp20;
    Vec3 sp60;
    Vec3 sp70;
    Matrix sp80;
    Matrix spC0;
    Vector4f sp100;
    char *object;
    char *orientation;

    object = ((ObjectLinks1DC *)(arg0))->unk_1D8;
    sp70 = ((struct ObjectState44 *) D_800D052C[((ObjectState630 *) object)->unk_62E])->unk_38;
    if (D_800CA040_de != 0) {
        sp70.x = -sp70.x;
    }
    if (D_800CA044 != 0) {
        sp70.y = -sp70.y;
    }
    if (D_800CA048 != 0) {
        sp70.z = -sp70.z;
    }
    func_80271F9C_de(&sp60, &((ObjectLinks1DC *)(arg0))->unk_50, 0.1f);
    func_80272CB0_de(&sp80, sp60.x, sp60.y, sp60.z);
    func_80271F9C_de(&sp70, &sp70, -10.24f);
    if (((ObjectState630 *)(object))->unk_5DC.v0 != 0) {
        func_802732D0_de(((ObjectState630 *)(object))->unk_5DC.v1 + 0x160, &sp10);
        func_80274244_de((Vector4f *)(((ObjectState630 *)(object))->unk_5DC.v1 + 0x140),
                      &sp20);
    } else {
        func_80226DD0_de(object, &spC0);
        func_80226C60_de(object, &sp100);
        func_802732D0_de((char *)&spC0, &sp10);
        func_80274244_de(&sp100, &sp20);
    }
    orientation = arg0 + 0x74;
    func_80273448_de(&sp80, sp70.x, sp70.y, sp70.z);
    func_80273D6C_de(&sp80);
    func_8026F620_de((Matrix *)orientation, &sp80, &sp20);
    func_80273448_de((Matrix *)orientation, sp10.x, sp10.y, sp10.z);
}

void func_8022F770_de(void *object, void *unused) {
    MarkerActor *actor=object;
    MarkerNode *node;
    s32 red, alpha;
    node=actor->node;
    if(node->active) {
        gSPMatrix(D_80110634++, (u32)&node->matrices[D_800D297C], G_MTX_LOAD);
        gDPPipeSync(D_80110634++);
        func_8026D8F8_de();
        func_8026925C_de(0xE);
        func_80268CE0_de(0x1C);
        red=200; alpha=150;
        gSPGeometryMode(D_80110634++, G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | 0x80, 0);
        gSPGeometryMode(D_80110634++, 0, G_SHADE | G_SHADING_SMOOTH);
        D_800FF1B0_de[0].x=1;
        D_800FF1B0_de[0].y=1;
        D_800FF1B0_de[0].z=0;
        D_800FF1B0_de[0].flag=0;
        D_800FF1B0_de[0].s=0;
        D_800FF1B0_de[0].t=0;
        D_800FF1B0_de[0].r=red;
        D_800FF1B0_de[0].g=0;
        D_800FF1B0_de[0].b=0;
        D_800FF1B0_de[0].a=red;
        D_800FF1B0_de[1].x=-1;
        D_800FF1B0_de[1].y=1;
        D_800FF1B0_de[1].z=0;
        D_800FF1B0_de[1].flag=0;
        D_800FF1B0_de[1].s=0;
        D_800FF1B0_de[1].t=0;
        D_800FF1B0_de[1].r=red;
        D_800FF1B0_de[1].g=0;
        D_800FF1B0_de[1].b=0;
        D_800FF1B0_de[1].a=red;
        D_800FF1B0_de[2].x=15;
        D_800FF1B0_de[2].y=1;
        D_800FF1B0_de[2].z=-1;
        D_800FF1B0_de[2].flag=0;
        D_800FF1B0_de[2].s=0;
        D_800FF1B0_de[2].t=0;
        D_800FF1B0_de[2].r=red;
        D_800FF1B0_de[2].g=0;
        D_800FF1B0_de[2].b=0;
        D_800FF1B0_de[2].a=alpha;
        D_800FF1B0_de[3].x=-15;
        D_800FF1B0_de[3].y=1;
        D_800FF1B0_de[3].z=-1;
        D_800FF1B0_de[3].flag=0;
        D_800FF1B0_de[3].s=0;
        D_800FF1B0_de[3].t=0;
        D_800FF1B0_de[3].r=red;
        D_800FF1B0_de[3].g=0;
        D_800FF1B0_de[3].b=0;
        D_800FF1B0_de[3].a=alpha;
        gSPVertex(D_80110634++, (u32)D_800FF1B0_de, 4, 0);
        gSP1Triangle(D_80110634++, 0, 1, 2, 0);
        gSP1Triangle(D_80110634++, 1, 2, 3, 0);
        if(node->extra) func_802A5498_de((u32)&node->extraMatrices[D_800D297C]);
    }
}
