#include "COMMON/VIEWFLAGS.H"
#include "COMMON/GAMEPLAY_CAMERA.H"

extern float k_cameraFadeResetValue;



/** Reset the object fields from 0xFC through 0x118. */
void Gsky_ResetFadeState(void *cameraStorage) {
    GameplayCamera *state = cameraStorage;
    float value = k_cameraFadeResetValue;
    state->fadeMode = 0;
    state->fadeState = 0;
    state->fadeParameterOne = 0;
    state->fadeParameterTwo = 0;
    state->fadeParameterThree = 0;
    state->fadeParameterFour = 0;
    state->fadeScalarOne = value;
    state->fadeScalarTwo = value;
}
