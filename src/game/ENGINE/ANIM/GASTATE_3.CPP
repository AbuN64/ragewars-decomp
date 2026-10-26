#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MANAGER.H"
#include "TYPES.H"
#include "SCENE/802508E0_7.H"
#include "SCENE/802508E0_9.H"
#include "SYSTEM/8025E5B0_9.H"
#include "RENDER_4/8028FD2C_6.H"




/** Initialize the compact record fields written by the VRAM 0x802624A0 leaf. */
void func_80262480_de(void *record) {
    ObjRecAt10V1 *record_record = record;
    record_record->unk4 = -1;
    record_record->unk6 = 0;
    record_record->unk0 = 0;
    record_record->unk8 = 0;
    record_record->unkA = 0;
    record_record->unkB = 1;
    record_record->unk10 = 0;
}

void func_802624A8_de(void *animationState) {
    Cache_UnlockResource(0, (struct Node80253610 *)(((struct func_8022BC04_S3 *) ((s8 *) animationState))->unk10));
    (((struct func_8022BC04_S3 *) ((s8 *) animationState))->unk10) = 0;
}

s32 func_802624D8_de(void *animationState) {
    func_8020D0CC_S2 *arg0_record = animationState;
    void *temp = arg0_record->unk10;
    if (temp == 0) {
        return 0;
    }
    return func_802532F4_de(temp) != 0;
}

void func_80262504_de(void *animationState, Six *recordOut) {
    Six *result = (Six *)SetN64_GetPackSection((void *)func_8026049C_de(animationState), 6);

    *recordOut = *result;
}
