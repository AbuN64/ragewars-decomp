#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

typedef void (*FuncPtr)(void);

extern FuncPtr D_800CB380_de[][2];




void func_802390F4_de(void *gameplayCamera, s16 arg1) {
    FuncPtr fn;

    ((GameplayCamera *)gameplayCamera)->unk14 = arg1;
    ((GameplayCamera *)gameplayCamera)->unk18 = 0;
    ((GameplayCamera *)gameplayCamera)->state = 0;
    ((GameplayCamera *)gameplayCamera)->stateCounter = 0;
    fn = D_800CB380_de[((GameplayCamera *)gameplayCamera)->unk14][0];
    if (fn != 0) {
        fn();
    }
}
