#include "span_1000/code_80208000.h"
#include "span_1000/code_802106E0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80212C90.h"
#include "TYPES.H"

void func_80212C90_de(AiTarget *arg0) {
    AiController *temp_s0;
    temp_s0 = arg0->player->controller;
    ((CloseAttackBrain *)temp_s0)->state = 0;
    func_80209988_de(temp_s0);
    temp_s0->unk2FC = 0;
}

extern s32 func_80209874_de(void *, s32);
extern void func_80211020_de(void *);
extern void func_80209948_de(s32 *, s32);
extern void func_80208410_de(void *);
extern void func_80208EB0_de(s32 *);
extern char D_80145040;






void func_80212CC4_de(AiTarget *arg0) {
    AiController *rec;
    void *v0;

    rec = arg0->player->controller;
    v0 = func_8022A83C_de(&D_80145040);
    if (v0 == 0 || v0 != (void *)rec->player) {
        func_80209874_de(rec, 2);
        return;
    }
    rec = arg0->player->controller;
    func_80211020_de(rec);
    func_80209948_de(rec, rec->mode);
    func_80208410_de(rec);
    func_80208EB0_de(rec);
}
