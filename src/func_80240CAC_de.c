#include "span_1000/code_802412C0.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023EEF0.h"


extern void func_80271F68_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2);
extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_8027207C_de(Vec3 *out);




void func_80240CAC_de(void *arg0) {
    QueryE0 *object = arg0;
    Vec3 sp10;
    Vec3 sp20;
    Vec3 *temp_s1;
    Vec3 *temp_s0;

    temp_s1 = &object->vectors[1];
    func_80271F68_de(&sp10, temp_s1, &object->vectors[0]);
    func_80271F68_de(&sp20, &object->vectors[2], temp_s1);
    temp_s0 = &object->result;
    func_80272018_de(temp_s0, &sp20, &sp10);
    func_8027207C_de(temp_s0);
}
