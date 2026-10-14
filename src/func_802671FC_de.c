#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "types.h"





                                                                                             



extern CallbackEntryRecAt4V2 D_800CC130[];

void func_802671FC_de(void *arg0, void *arg1, s32 arg2, Vec3 arg3, ResourceManagerState arg6) {
    if (D_800CC130[arg2].callback != 0) {
        D_800CC130[arg2].callback(arg0, arg1, arg2, arg3, arg6);
    }
}
