#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TYPES.H"
#include "sdk/os.h"

void func_802567A4_de(void *menuRules) {
    (((struct MenuRules *) ((s8 *) menuRules))->locked) = 0;
    osCreateMesgQueue(menuRules, menuRules + 0x18, 1);
}
