/* __floatdidf: converts a signed 64-bit integer to double as its high word times 2^32 plus its
   unsigned low word; drafted from the GCC 2.7.2.3 libgcc2.c section L_floatdidf, each signed word
   adding its 2^32 correction. This object is built with -mfp32 (see the Makefile), under which the
   unchanged reference section is byte-identical. The 2^32 and 2^16 coefficients are the cartridge's
   own constants (already covered as data at 0x800CD350/0x800CD358/0x800CD360), so the code loads
   them by reference instead of emitting a constant pool. */
typedef int SItype;
typedef long long DItype;
typedef double DFtype;

extern double D_800C8100_de; /* 2^32 */
extern double D_800C8108_de; /* 2^16, HIGH_HALFWORD_COEFF */
extern double D_800C8110_de; /* 2^32 */

DFtype func_802C6970_us_rev1(DItype u)
{
  DFtype d, low;
  SItype negate = 0;

  if (u < 0)
    u = -u, negate = 1;

  d = (SItype) (u >> 32);
  if ((SItype) (u >> 32) < 0)
    d += D_800C8100_de;
  d *= D_800C8108_de;
  d *= D_800C8108_de;
  low = (SItype) u;
  if ((SItype) u < 0)
    low += D_800C8110_de;
  d += low;

  return (negate ? -d : d);
}
