#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022BA90.h"
extern void *D_800D052C[];






int func_8022BEDC_de(void *arg0) {
    short index = ((Shared_ActorView *)arg0)->selectedAction;
    return ((WeaponInfo *)D_800D052C[index])->capacity > 0;
}
