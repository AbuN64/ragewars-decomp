#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef struct RoomRecord {Vec3 position;u16 flags;}RoomRecord;
typedef struct RoomPortal {u16 first,second;u8 kind;}RoomPortal;
typedef struct RoomBuffer {s32 stride,count;u8 data[1];}RoomBuffer;
typedef struct Node8020BC50 {s32 key;f32 value;s32 state,fieldC;struct Node8020BC50 *next;s32 field14;f32 extra,cost,estimate,total;s32 open,goal;struct Node8020BC50 *parent;}Node8020BC50;
typedef struct Graph {RoomBuffer *points;s32 pointCount;RoomBuffer *edges;s32 edgeCount;u32 field10,field14;s32 result;f32 value;u32 field20;Node8020BC50 *nodes;}Graph;
extern f32 D_800C1D80_de,D_800C1D84_de,D_800C1D88_de;
extern f32 func_8020C2E8_de(void *,void *);
extern f32 func_802726F8_de(f32 *,f32 *);
static void *roomRecord35(RoomBuffer *table,s32 index){return table->data+index*table->stride;}
static inline s32 hasOpen35(Graph *g,s32 status){Node8020BC50 *n=g->nodes;while(n){if(n->open==status)return 1;n=n->next;}return 0;}
static inline Node8020BC50 *choose35(Graph *g,s32 status,f32 initial,f32 sentinel){Node8020BC50 *n=g->nodes,*best=0;f32 minimum=initial;while(n){if(n->open==status&&(n->total<minimum||minimum==sentinel)){best=n;minimum=n->total;}n=n->next;}if(best)best->open=0;return best;}
static inline Node8020BC50 *find35(Graph *g,s32 key){Node8020BC50 *n=g->nodes;while(n){if(n->key==key)return n;n=n->next;}return 0;}
static inline s32 neighbors35(Graph *arg0, Node8020BC50 *node,s32 *out,s32 *ids) {
 s32 temp_t1=node->key,var_a3=0,var_t0=0; s32 *var_a0_3=out,*var_a1=ids; RoomBuffer *temp_v1;RoomPortal *temp_v1_2;
        if (arg0->edgeCount > 0) {

            do {
                temp_v1 = arg0->edges;
                temp_v1_2=roomRecord35(temp_v1,var_a3);
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
            } while (var_a3 < arg0->edgeCount);
        }
return var_t0;
}
void func_8020C5A0_de(Graph *arg0, Node8020BC50 *arg1) {
    s32 sp10[64];
    s32 sp110[64];
    s32 *sp210;
    RoomRecord *temp_fp;
    RoomRecord *temp_s2;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0f;
    f32 var_fv0f;
    f32 var_fv0f_2;
    f32 var_fv0f_3;
    RoomBuffer *temp_a0;
    RoomBuffer *temp_a0_3;
    RoomBuffer *temp_v1;
    RoomBuffer *temp_v1_3;
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
    RoomPortal *temp_a0_4;
    RoomPortal *temp_v1_2;
    Node8020BC50 *var_a0;
    Node8020BC50 *var_a1_2;
    Node8020BC50 *var_s0;
    Node8020BC50 *var_v1;
    Node8020BC50 *var_v1_2;

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
        temp_fp=roomRecord35(temp_a0,temp_a1);
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
                temp_s2=roomRecord35(temp_v1_3,temp_a0_2);
                var_s0=find35(arg0,temp_a0_2);
                temp_a0_3 = arg0->edges;
                temp_a0_4=roomRecord35(temp_a0_3,sp110[var_s1_2]);
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
                        if (temp_s2->flags & 0x400) {
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
