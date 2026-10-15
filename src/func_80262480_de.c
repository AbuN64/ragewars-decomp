#include "span_1000/code_802624A0.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "types.h"

s32 func_80253754_de(s32, s32);

unsigned int func_8026049C_de(void *object);

void *func_8028FDB4_de(void *arg0, int arg1);

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

void func_802624A8_de(void *arg0) {
    func_80253754_de(0, (((struct func_8022BC04_S3 *) ((s8 *) arg0))->unk10));
    (((struct func_8022BC04_S3 *) ((s8 *) arg0))->unk10) = 0;
}

s32 func_802624D8_de(void *arg0) {
    func_8020D0CC_S2 *arg0_record = arg0;
    void *temp = arg0_record->unk10;
    if (temp == 0) {
        return 0;
    }
    return func_802532F4_de(temp) != 0;
}

void func_80262504_de(void *arg0, void *arg1) {
    Six *result = (Six *)func_8028FDB4_de((void *)func_8026049C_de(arg0), 6);

    *(Six *)arg1 = *result;
}
