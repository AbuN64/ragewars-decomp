#include "COMMON/VIEWFLAGS.H"
#include "COMMON/OBJB.H"

extern float D_800C8630;



/** Reset the object fields from 0xFC through 0x118. */
void func_802393D8_de(void *arg0) {
    State_func_8044A170_de *state = arg0;
    float value = D_800C8630;
    state->unkFC = 0;
    state->unk100 = 0;
    state->unk104 = 0;
    state->unk108 = 0;
    state->unk10C = 0;
    state->unk118 = 0;
    state->unk110 = value;
    state->unk114 = value;
}
