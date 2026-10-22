#include "COMMON/OBJRECAT20V1.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

void func_80290A00_de(void *arg0) {
    Frame *view = arg0;
    view->direction.x = 0.0f;
    view->direction.y = 0.0f;
}

void func_80290A0C_de(void *schedule) {}


void func_80290A14_de(void *arg0, void *arg1) {
    Frame *view = arg0;
    CVector3 *direction = arg1;
    view->direction = *direction;
    func_8027207C_de(&view->direction.x);
}
