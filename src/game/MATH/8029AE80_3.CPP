#include "COMMON/CALLBACK.H"
#include "MATH/8029AE80.H"
#include "TYPES.H"
#include "MATH/math_controller_events.H"


void Smos_SendControllerButtonEvent(s16 arg0, s16 arg1, s32 arg2) {
    ControllerEvent m;

    m.source = 4;
    m.device = arg0;
    m.kind = 1;
    m.control = arg1;
    m.reserved08 = 0;
    m.pressed = arg2 != 0;
    m.x = 0;
    m.y = 0;
    m.z = 0;
    Smos_DispatchControllerEvent(&m);
}

void Smos_SendControllerStickEvent(s16 arg0, s32 arg1, s32 arg2) {
    ControllerEvent m;

    m.source = 4;
    m.kind = 3;
    m.control = 0x162;
    m.x = arg1 * 0x64;
    m.device = arg0;
    m.reserved08 = 0;
    m.pressed = 0;
    m.y = arg2 * 0x64;
    m.z = 0;
    Smos_DispatchControllerEvent(&m);
}
