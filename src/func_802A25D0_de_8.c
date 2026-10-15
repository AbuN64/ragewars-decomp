#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802A25C4.h"
#include "types.h"
#include "span_1000/code_8022F3E8.h"





extern void func_80272CB0_de(void *, f32, f32, f32);
extern void func_802727D8_de(void *);
extern void func_802A31E8_de(Node438C *, Node438C *, void *, void *);
extern void func_8027027C_de(void *, s32);




void func_802A339C_de(void *arg0, void *arg1) {
    f32 matrix[16];
    Node438C *first;
    Node438C *next;
    State802A6DF8 *state = arg0;

    if (state->vertexCount < 2) {
        return;
    }

    first = state->vertices;
    next = first->next;
    if (first != 0) {
        func_80272CB0_de(matrix, first->a, first->b, first->c);
    } else {
        func_802727D8_de(matrix);
    }

    while (first != 0) {
        Node438C *a;
        Node438C *b;

        if (next == 0) {
            break;
        }
        a = first;
        b = next;
        if (first == 0) {
            goto no_pair;
        }
        if (first->position.x != next->position.x || first->position.y != next->position.y) {
            goto boundary;
        }
z_test:
        if (a->position.z != b->position.z) {
            goto boundary;
        }
        a = b;
        b = b->next;
        if (a == 0) {
            goto no_pair;
        }
        if (b == 0 || a->position.x != b->position.x || a->position.y != b->position.y) {
            goto boundary;
        }
        goto z_test;
boundary:
        if (a != 0 && b != 0) {
            func_802A31E8_de(a, b, arg1, matrix);
            goto apply;
        }
no_pair:
        {
            matrix[12] = first->position.x;
            matrix[13] = first->position.y;
            matrix[14] = first->position.z;
        }
apply:
        func_8027027C_de(matrix, (s32)first->matrices[D_800D297C]);
        first = next;
        next = first->next;
    }

    matrix[12] = first->position.x;
    matrix[13] = first->position.y;
    matrix[14] = first->position.z;
    func_8027027C_de(matrix, (s32)first->matrices[D_800D297C]);
}
