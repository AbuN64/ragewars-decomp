#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TYPES.H"
#include "sdk/os.h"

void func_802567A4_de(void *arg0) {
    (((struct MenuRules *) ((s8 *) arg0))->locked) = 0;
    osCreateMesgQueue(arg0, arg0 + 0x18, 1);
}
