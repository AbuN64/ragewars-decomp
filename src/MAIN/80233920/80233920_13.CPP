#include "shared/gameplay_camera.h"
#include "span_1000/code_80233920.h"
#include "TYPES.H"
typedef void (*FuncPtr)(void);

extern FuncPtr D_800CB380_de[][2];




void func_802390F4_de(void *arg0, s16 arg1) {
    FuncPtr fn;

    ((GameplayCamera *)arg0)->unk14 = arg1;
    ((GameplayCamera *)arg0)->unk18 = 0;
    ((GameplayCamera *)arg0)->state = 0;
    ((GameplayCamera *)arg0)->stateCounter = 0;
    fn = D_800CB380_de[((GameplayCamera *)arg0)->unk14][0];
    if (fn != 0) {
        fn();
    }
}
