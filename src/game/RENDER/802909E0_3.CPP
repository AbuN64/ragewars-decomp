#include "COMMON/OBJRECAT20V1.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

void func_80290A00_de(void *frame) {
    Frame *view = frame;
    view->direction.x = 0.0f;
    view->direction.y = 0.0f;
}

void func_80290A0C_de(void *schedule) {}


void func_80290A14_de(void *frame, void *arg1) {
    Frame *view = frame;
    CVector3 *direction = arg1;
    view->direction = *direction;
    Particle_NormalizeVec3(&view->direction.x);
}
