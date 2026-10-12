#include "types.h"
#include "n64sdk.h"
extern f64 D_800C56D8_de,D_800C56E0_de,D_800C56E8_de,D_800C56F0_de,D_800C56F8_de;
extern f64 D_800C5700_de,D_800C5708_de,D_800C5710_de,D_800C5718_de,D_800C5720_de,D_800C5728_de,D_800C5730_de,D_800C5738_de;
f64 func_8029AD38_de(f64 value) {
 union { f64 value; struct { u32 high,low; } words; } bits;
 s32 exponent; f64 x,denominator,square,numerator,correction;
 if(value<=D_800C56E0_de) return D_800C56D8_de;
 if(value==D_800C56E0_de) { exponent=0; x=D_800C56E0_de; }
 else {
  bits.value=value;
  exponent=((bits.words.high>>20)&0x7ff)-0x3fe;
  bits.words.high=(bits.words.high&0x800fffff)|0x3fe00000;
  x=bits.value;
 }
 if(D_800C56E8_de<x) {
  denominator=x*D_800C56F0_de;
  x=x-D_800C56F0_de; x=x-D_800C56F0_de;
  denominator+=D_800C56F0_de;
 } else {
  x=x-D_800C56F8_de;
  denominator=x*D_800C56F8_de;
  exponent--;
  denominator+=D_800C56F8_de;
 }
 x=x/denominator; square=x*x;
 numerator=(square*D_800C5700_de+D_800C5708_de)*square;
 denominator=((square-D_800C5710_de)*square+D_800C5718_de)*square;
 numerator=(numerator-D_800C5720_de)*square;
 denominator=denominator-D_800C5728_de;
 correction=x*(numerator/denominator);
 return (exponent*D_800C5730_de+(x+correction))+exponent*D_800C5738_de;
}
