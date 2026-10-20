#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
extern const u8 D_800C88F0[];
static inline u64 divideWords(u32 n1, u32 n0, u32 d1, u32 d0) {
 u32 n2, q0, q1, b, bm; u64 quotient;
  if (d1 == 0)
    {
      if (d0 > n1)
	{
	  

	  {
 u32 x = d0;
 u32 shift;
 shift = x < 0x10000 ? (x < 0x100 ? 0 : 8) : (x < 0x1000000 ? 16 : 24);
 bm = 32 - (D_800C88F0[x >> shift] + shift);
 }

	  if (bm != 0)
	    {
	      

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (32 - bm));
	      n0 = n0 << bm;
	    }

	  {
 u32 dh, dl, qh, ql, rh, rl, product;
 dh = d0 >> 16;
 dl = d0 & 0xffff;
 rh = n1 % dh;
 qh = n1 / dh;
 product = qh * dl;
 rh = (rh << 16) | (n0 >> 16);
 if (rh < product) {
  qh--; rh += d0;
  if (rh >= d0)
   if (rh < product) { qh--; rh += d0; }
 }
 rh -= product;
 rl = rh % dh;
 ql = rh / dh;
 product = ql * dl;
 rl = (rl << 16) | (n0 & 0xffff);
 if (rl < product) {
  ql--; rl += d0;
  if (rl >= d0)
   if (rl < product) { ql--; rl += d0; }
 }
 rl -= product;
 q0 = (qh << 16) | ql;
 n0 = rl;
 }
	  q1 = 0;

	  
	}
      else
	{
	  

	  if (d0 == 0)
	    d0 = 1 / d0;	

	  {
 u32 x = d0;
 u32 shift;
 shift = x < 0x10000 ? (x < 0x100 ? 0 : 8) : (x < 0x1000000 ? 16 : 24);
 bm = 32 - (D_800C88F0[x >> shift] + shift);
 }

	  if (bm == 0)
	    {
	      

	      n1 -= d0;
	      q1 = 1;
	    }
	  else
	    {
	      

	      b = 32 - bm;

	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      {
 u32 dh, dl, qh, ql, rh, rl, product;
 dh = d0 >> 16;
 dl = d0 & 0xffff;
 rh = n2 % dh;
 qh = n2 / dh;
 product = qh * dl;
 rh = (rh << 16) | (n1 >> 16);
 if (rh < product) {
  qh--; rh += d0;
  if (rh >= d0)
   if (rh < product) { qh--; rh += d0; }
 }
 rh -= product;
 rl = rh % dh;
 ql = rh / dh;
 product = ql * dl;
 rl = (rl << 16) | (n1 & 0xffff);
 if (rl < product) {
  ql--; rl += d0;
  if (rl >= d0)
   if (rl < product) { ql--; rl += d0; }
 }
 rl -= product;
 q1 = (qh << 16) | ql;
 n1 = rl;
 }
	    }

	  

	  {
 u32 dh, dl, qh, ql, rh, rl, product;
 dh = d0 >> 16;
 dl = d0 & 0xffff;
 rh = n1 % dh;
 qh = n1 / dh;
 product = qh * dl;
 rh = (rh << 16) | (n0 >> 16);
 if (rh < product) {
  qh--; rh += d0;
  if (rh >= d0)
   if (rh < product) { qh--; rh += d0; }
 }
 rh -= product;
 rl = rh % dh;
 ql = rh / dh;
 product = ql * dl;
 rl = (rl << 16) | (n0 & 0xffff);
 if (rl < product) {
  ql--; rl += d0;
  if (rl >= d0)
   if (rl < product) { ql--; rl += d0; }
 }
 rl -= product;
 q0 = (qh << 16) | ql;
 n0 = rl;
 }

	  
	}

      
    }


  else
    {
      if (d1 > n1)
	{
	  

	  q0 = 0;
	  q1 = 0;

	  
	  
	}
      else
	{
	  

	  {
 u32 x = d1;
 u32 shift;
 shift = x < 0x10000 ? (x < 0x100 ? 0 : 8) : (x < 0x1000000 ? 16 : 24);
 bm = 32 - (D_800C88F0[x >> shift] + shift);
 }
	  if (bm == 0)
	    {
	      

	      
	      if (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		}
	      else
		q0 = 0;

	      q1 = 0;

	      
	    }
	  else
	    {
	      u32 m1, m0;
	      

	      b = 32 - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      {
 u32 dh, dl, qh, ql, rh, rl, product;
 dh = d1 >> 16;
 dl = d1 & 0xffff;
 rh = n2 % dh;
 qh = n2 / dh;
 product = qh * dl;
 rh = (rh << 16) | (n1 >> 16);
 if (rh < product) {
  qh--; rh += d1;
  if (rh >= d1)
   if (rh < product) { qh--; rh += d1; }
 }
 rh -= product;
 rl = rh % dh;
 ql = rh / dh;
 product = ql * dl;
 rl = (rl << 16) | (n1 & 0xffff);
 if (rl < product) {
  ql--; rl += d1;
  if (rl >= d1)
   if (rl < product) { ql--; rl += d1; }
 }
 rl -= product;
 q0 = (qh << 16) | ql;
 n1 = rl;
 }
	      { u64 product = (u64)q0 * d0; m1 = product >> 32; m0 = product; }

	      if (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		}

	      q1 = 0;

	      
	      
	    }
	}
    }


 quotient = ((u64)q1 << 32) | q0;
 return quotient;
}
static inline u64 negate(u64 x) { return -x; }
s64 func_802C0230_de(s64 u, s64 v) {
 s32 negative = 0;
 u64 numerator = u, denominator = v;
 u64 quotient;
 if (u < 0) { negative = ~negative; numerator = -numerator; }
 if (v < 0) { negative = ~negative; denominator = -denominator; }
 quotient = divideWords(numerator >> 32, numerator, denominator >> 32, denominator);
 if (negative) quotient = -quotient;
 return quotient;
}
#else
#if !(defined(VERSION_US))
INCLUDE_ASM("span_1000", func_802C0230_de);
#endif
#if defined(VERSION_US)
INCLUDE_ASM("span_1000", func_802C0164);
#endif
#endif
