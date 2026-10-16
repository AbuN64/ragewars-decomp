#include "span_1000/code_80290980.h"
#include "span_1000/code_80291054.h"
#include "TYPES.H"

void func_80290A00_de(void *arg0) {
    RenderView *view = arg0;
    view->direction.x = 0.0f;
    view->direction.y = 0.0f;
}

void func_80290A0C_de(void) {}

extern void func_8027207C_de(f32 *direction);

void func_80290A14_de(void *arg0, void *arg1) {
    RenderView *view = arg0;
    Vec3 *direction = arg1;
    view->direction = *direction;
    func_8027207C_de(&view->direction.x);
}
