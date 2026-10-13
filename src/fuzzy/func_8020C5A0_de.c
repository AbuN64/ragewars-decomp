#include "span_1000/code_8020AF9C.h"
extern f32 D_800C1D80_de,D_800C1D84_de,D_800C1D88_de;
extern f32 func_8020C2E8_de(void *,void *);
extern f32 func_802726F8_de(f32 *,f32 *);

static inline s32 hasOpen35(NavigationGraph *g,s32 status){NavigationSearchNode *n=g->nodes;while(n){if(n->open==status)return 1;n=n->next;}return 0;}
static inline NavigationSearchNode *choose35(NavigationGraph *g,s32 status,f32 initial,f32 sentinel){NavigationSearchNode *n=g->nodes,*best=0;f32 minimum=initial;while(n){if(n->open==status&&(n->total<minimum||minimum==sentinel)){best=n;minimum=n->total;}n=n->next;}if(best)best->open=0;return best;}
static inline NavigationSearchNode *find35(NavigationGraph *g,s32 key){NavigationSearchNode *n=g->nodes;while(n){if(n->key==key)return n;n=n->next;}return 0;}
static inline s32 neighbors35(NavigationGraph *arg0, NavigationSearchNode *node,s32 *out,s32 *ids) {
 s32 temp_t1=node->key,var_a3=0,var_t0=0; s32 *var_a0_3=out,*var_a1=ids; NavigationBuffer *temp_v1;NavigationPortal *temp_v1_2;
        if (arg0->portalCount > 0) {

            do {
                temp_v1 = arg0->portals;
                temp_v1_2=navigationRecord(temp_v1,var_a3);
                if (temp_v1_2->first == temp_t1) {
                    var_t0 += 1;
                    *var_a0_3 = temp_v1_2->second;
                    *var_a1 = var_a3;
                    var_a1++;
                    var_a0_3++;
                }
                if (temp_v1_2->second == temp_t1) {
                    var_t0 += 1;
                    *var_a0_3 = temp_v1_2->first;
                    *var_a1 = var_a3;
                    var_a1++;
                    var_a0_3++;
                }
                var_a3 += 1;
            } while (var_a3 < arg0->portalCount);
        }
return var_t0;
}
void func_8020C5A0_de(NavigationGraph *arg0, NavigationSearchNode *arg1) {
    s32 sp10[64];
    s32 sp110[64];
    s32 *sp210;
    NavigationPoint *temp_fp;
    NavigationPoint *temp_s2;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0f;
    f32 var_fv0f;
    f32 var_fv0f_2;
    f32 var_fv0f_3;
    NavigationBuffer *temp_a0;
    NavigationBuffer *temp_a0_3;
    NavigationBuffer *temp_v1;
    NavigationBuffer *temp_v1_3;
    s32 *var_a0_2;
    s32 *var_a0_3;
    s32 *var_a1;
    s32 *var_v1_3;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_t1;
    s32 temp_v1_5;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s4;
    s32 var_t0;
    s32 var_v0,one;
    s32 var_v0_2;
    u8 temp_a0_5;
    s32 temp_v1_4;
    NavigationPortal *temp_a0_4;
    NavigationPortal *temp_v1_2;
    NavigationSearchNode *var_a0;
    NavigationSearchNode *var_a1_2;
    NavigationSearchNode *var_s0;
    NavigationSearchNode *var_v1;
    NavigationSearchNode *var_v1_2;

    arg1->cost = 0.0f;
    temp_fv0 = func_8020C2E8_de(arg0,arg1);
    one=1;temp_fs0f = D_800C1D80_de;
    sp210=sp10;
    arg1->estimate = temp_fv0;
    arg1->parent = 0;
    arg1->open=one;
    arg1->total = (arg1->cost + temp_fv0);
loop_1:
 if(hasOpen35(arg0,one)){
 var_a0=choose35(arg0,one,D_800C1D84_de,temp_fs0f);
        temp_a0 = arg0->points;
        temp_a1 = var_a0->key;
        temp_fp=navigationRecord(temp_a0,temp_a1);
        if (var_a0->goal != 0) {
            arg0->result = temp_a1;
            return;
        }
        var_s1_2 = 0;
        var_a0_2=sp110;
        var_v1_3=sp10;
        do {
            *var_v1_3 = -1;
            *var_a0_2 = -1;
            var_a0_2++;
            var_s1_2 += 1;
            var_v1_3++;
        } while (var_s1_2 < 0x40);
var_t0=neighbors35(arg0,var_a0,sp10,sp110);
        var_s1_2 = 0;
        if (var_t0 > 0) {
            var_s4 = 0;
            do {
                temp_v1_3 = arg0->points;
                temp_a0_2 = sp210[var_s1_2];
                var_a1_2 = arg0->nodes;
                temp_s2=navigationRecord(temp_v1_3,temp_a0_2);
                var_s0=find35(arg0,temp_a0_2);
                temp_a0_3 = arg0->portals;
                temp_a0_4=navigationRecord(temp_a0_3,sp110[var_s1_2]);
                temp_v1_4 = temp_a0_4->kind;
                if (temp_v1_4 != 4) {
                    if (temp_v1_4 < 5) {
                        var_v0_2 = 0;
                        if (temp_v1_4 != 1) {

                        } else {
                            goto block_35;
                        }
                    } else {
                        var_v0_2 = 0;
                        if (temp_v1_4 == 7) {
                            goto block_35;
                        }
                    }
                } else {
block_35:
                    var_v0_2 = 1;
                }
                if ((var_v0_2 != 0) || (temp_a0_4->first == var_a0->key)) {
                    temp_a0_5 = temp_a0_4->kind;
                    if ((temp_a0_5 != 0xA) && (temp_a0_5 != 0xB)) {
                        if (temp_a0_5 == 9) {
                            var_fv0f_2 = 0.0f;
                        } else {
                            var_fv0f_2 = func_802726F8_de(&temp_s2->position.x,&temp_fp->position.x);
                        }
                        var_fv0f_3 = var_fv0f_2 + var_s0->extra;
                        if (temp_s2->attributes.halves.flags & 0x400) {
                            var_fv0f_3 += D_800C1D88_de;
                        }
                        if (var_fv0f_3 < 0.0f) {
                            var_fv0f_3 = 0.0f;
                        }
                        temp_v1_5 = var_s0->open;
                        temp_fv0f = var_a0->cost + var_fv0f_3;
                        if (((temp_v1_5 ^ 2) == 0) || ((temp_v1_5 ^ 1) == 0)) {
                            if (!(var_s0->cost <= temp_fv0f)) {
                                goto block_51;
                            }
                        } else {
block_51:
                            var_s0->parent = var_a0;
                            var_s0->cost = temp_fv0f;
                            temp_fv0_3 = func_8020C2E8_de(arg0, var_s0);
                            var_s0->estimate = temp_fv0_3;
                            var_s0->total = (var_s0->cost + temp_fv0_3);
                            if ((var_s0->open ^ 2) == 0) {
                                var_s0->open = 0;
                            }
                            if ((var_s0->open ^ one) != 0) {
                                var_s0->open=one;
                            }
                        }
                    }
                }
                var_s1_2 += 1;
                var_s4 += 4;
            } while (var_s1_2 < var_t0);
        }
        var_a0->open = 2;
        goto loop_1;
    }
}
