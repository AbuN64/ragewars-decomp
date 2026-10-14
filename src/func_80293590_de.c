#include "span_1000/code_80291054.h"
#include "span_1000/code_80293A04.h"



/** Reset three large-offset fields and mark the record active. */
void func_80293590_de(void *arg0) {
    struct GameSession *session = arg0;
    session->phase = 1;
    session->timer = 0;
    session->pad26DC0 = 0;
}
