#include "types.h"
void func_802BF928_de(f32 *data,s32 count,s32 sign,f32 *cosines,f32 *sines,s32 *reverse) {
    s32 i,j,k,width,groups,total,step;
    f32 *current,*a,*b,*c,*s;
    f32 temp,real,imag,co,si;
    current = data;
    for (i = 0; i < count; i++,reverse++,current += 2) {
        if (i < *reverse) {
            temp = current[0];
            current[0] = data[*reverse * 2];
            data[*reverse * 2] = temp;
            temp = current[1];
            current[1] = data[*reverse * 2 + 1];
            data[*reverse * 2 + 1] = temp;
        }
    }
    width = 2;
    groups = 1;
    total = count << 1;
    count >>= 1;
    while (count > 0) {
        c = cosines;
        s = sines;
        step = width * 2;
        for (j = 0; j < groups; j++) {
            co = *c;
            si = (f32)sign * *s;
            a = data + j * 2;
            for (k = j * 2; k < total; k += step,a += step) {
                b = data + k + width;
                real = co * b[0] - si * b[1];
                imag = co * b[1] + si * b[0];
                b[0] = a[0] - real;
                b[1] = a[1] - imag;
                a[0] = a[0] + real;
                a[1] = a[1] + imag;
            }
            s += count;
            c += count;
        }
        count >>= 1;
        groups <<= 1;
        width <<= 1;
    }
}
