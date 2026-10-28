#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

typedef void (*FuncPtr)(void);

extern FuncPtr D_800CB380_de[][2];




void Gsky_SetGameplayMode(void *gameplayCamera, s16 requestedMode) {
    FuncPtr fn;

    ((GameplayCamera *)gameplayCamera)->mode = requestedMode;
    ((GameplayCamera *)gameplayCamera)->elapsed = 0;
    ((GameplayCamera *)gameplayCamera)->state = 0;
    ((GameplayCamera *)gameplayCamera)->stateCounter = 0;
    fn = D_800CB380_de[((GameplayCamera *)gameplayCamera)->mode][0];
    if (fn != 0) {
        ((void (*)(void *))fn)(gameplayCamera);
    }
}
