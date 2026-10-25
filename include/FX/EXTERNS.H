#ifndef FX_EXTERNS_H
#define FX_EXTERNS_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
struct ControllerInput;
struct Player;
extern void Fx_BuildControllerState(struct ControllerInput *input, struct Player *player);


extern f32 D_800C46B0;
extern f32 D_800C46B4;
extern f32 D_800C46B8;
extern f32 func_8024BF24_de(void *);
#endif
