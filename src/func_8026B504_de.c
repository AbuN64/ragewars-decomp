#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8026AC38.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"



/* Sets the lighting for a model: when lighting toward the player is enabled and the model is flagged 0x8000, it aims the static light's direction D_800D1610 from the model's position at the current player and emits one light with it, returning 1; otherwise it emits the given light block, if any, and returns 0. */




extern Gfx *D_80110634;
extern s32 D_80110620;

extern signed char D_800D1610[3];
extern char D_80145040;
extern void func_80270700_de(f32 *matrix, void *model);
extern void func_802732D0_de(f32 *matrix, Vec3 *position);
extern char *func_8022A414_de(void *players);
extern void func_80271F68_de(Vec3 *out, void *a, Vec3 *b);
extern void func_8027207C_de(Vec3 *v);

s32 func_8026B504_de(void *model, void *lights, s32 *flags) {
    Vec3 direction;
    Vec3 position;
    f32 matrix[4][4];

    if (D_80110620 != 0 && (*flags & 0x8000)) {
        func_80270700_de((f32 *)matrix, model);
        func_802732D0_de((f32 *)matrix, &position);
        func_80271F68_de(&direction, func_8022A414_de(&D_80145040) + 0x6E8, &position);
        func_8027207C_de(&direction);
        {
            Gfx *cmd;
            Gfx *light;
            Gfx *ambient;

            D_800D1610[0] = direction.x * D_800C4668_de;
            D_800D1610[1] = direction.y * D_800C4668_de;
            D_800D1610[2] = direction.z * D_800C4668_de;
            cmd = D_80110634++;
            gSPMoveWord(cmd, G_MW_NUMLIGHT, 0, 0x18);
            gSPMoveMem(D_80110634++, G_MV_LIGHT, 48, 16, (unsigned int)(D_800D1610 - 8));
            gSPMoveMem(D_80110634++, G_MV_LIGHT, 72, 16, (unsigned int)(D_800D1610 - 0x10));
        }
        return 1;
    }
    if (lights != 0) {
        gSPMoveWord(D_80110634++, G_MW_NUMLIGHT, 0, 0x18);
        gSPMoveMem(D_80110634++, G_MV_LIGHT, 48, 16, (unsigned int)((char *)lights + 8));
        gSPMoveMem(D_80110634++, G_MV_LIGHT, 72, 16, (unsigned int)lights);
    }
    return 0;
}
