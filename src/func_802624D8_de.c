#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_802624A0.h"
#include "types.h"






s32 func_802624D8_de(void *arg0) {
    func_8020D0CC_S2 *arg0_record = arg0;
    void *temp = arg0_record->unk10;
    if (temp == 0) {
        return 0;
    }
    return func_802532F4_de(temp) != 0;
}
