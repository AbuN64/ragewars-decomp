#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/8043D54C.H"
#include "OVLGAME/SHAREDRECAT224.H"
#include "TYPES.H"

/* note: Clears eight status bytes and selects the first available profile. */
void func_8025E384_de(void);
unsigned int Render_IsAButtonPressed(void *);
extern s32 D_8010F328;
extern s32 D_80146302;
extern struct SharedRecAt148 D_80142622[];










void Ovlgame_SelectConfirmingController(func_80250BD4_S1 *arg0) {
    Shared_func_8043DEDC_S3 *settings;
    s8 *status;
    s32 *profile;
    s32 i;

    i = 7;
    status = (s8 *)&D_80142622[0];
    for (; i >= 0; i--) {
        ((SharedRecAt148 *)status)->unk148 = 0;
        status -= 0x96;
    }
    i = 0;
    settings = (Shared_func_8043DEDC_S3 *)&D_80146302;
    for (; i < 4; i++) {
        profile = (s32 *)((char *)&D_8010F328 + i * 0x224);
        if (Render_IsAButtonPressed(profile) != 0) {
            settings->unk78 = 1;
            settings->unk7F = i;
            arg0->unk20 = profile;
            break;
        }
    }
    func_8025E384_de();
}
