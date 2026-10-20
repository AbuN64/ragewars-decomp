#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/UNSIGNED_QUOTIENT.H"

/* Number of leading zero bits of a nonzero word: pick the highest nonzero
 * byte, then count the bits it needs. */
#define LEADING_ZEROS(zeros, x)                                                   \
    {                                                                             \
        u32 shift_, top_, bits_;                                                  \
        if ((x) < 0x10000) {                                                      \
            shift_ = ((x) < 0x100) ? 0 : 8;                                       \
        } else {                                                                  \
            shift_ = ((x) < 0x1000000) ? 16 : 24;                                 \
        }                                                                         \
        bits_ = shift_;                                                           \
        for (top_ = (x) >> shift_; top_ != 0; top_ >>= 1) {                       \
            bits_++;                                                              \
        }                                                                         \
        (zeros) = 32 - bits_;                                                     \
    }

/* Divide hi:lo by d (top bit set, hi < d) in two 16-bit digit steps, each
 * estimated from the divisor's high half and corrected at most twice.
 * quotient receives the 32-bit quotient and hi the remainder. */
#define DIVIDE_WORDS(quotient, hi, lo, d)                                         \
    {                                                                             \
        u32 dHigh_, dLow_, qHigh_, qLow_, r_, m_;                                 \
        dHigh_ = (d) >> 16;                                                       \
        dLow_ = (d) & 0xFFFF;                                                     \
        qHigh_ = (hi) / dHigh_;                                                   \
        r_ = (hi) % dHigh_;                                                       \
        m_ = qHigh_ * dLow_;                                                      \
        r_ = (r_ << 16) | ((lo) >> 16);                                           \
        if (r_ < m_) {                                                            \
            qHigh_--;                                                             \
            r_ += (d);                                                            \
            if (r_ >= (d) && r_ < m_) {                                           \
                qHigh_--;                                                         \
                r_ += (d);                                                        \
            }                                                                     \
        }                                                                         \
        r_ -= m_;                                                                 \
        qLow_ = r_ / dHigh_;                                                      \
        r_ = r_ % dHigh_;                                                         \
        m_ = qLow_ * dLow_;                                                       \
        r_ = (r_ << 16) | ((lo) & 0xFFFF);                                        \
        if (r_ < m_) {                                                            \
            qLow_--;                                                              \
            r_ += (d);                                                            \
            if (r_ >= (d) && r_ < m_) {                                           \
                qLow_--;                                                          \
                r_ += (d);                                                        \
            }                                                                     \
        }                                                                         \
        r_ -= m_;                                                                 \
        (quotient) = (qHigh_ << 16) | qLow_;                                      \
        (hi) = r_;                                                                \
    }

/* Unsigned 64-bit division by normalised long division on 32-bit words. */
u64 func_802C0DA0_de(u64 numerator, u64 divisor) {
    u32 n2, n1, n0;
    u32 d1, d0;
    u32 q1, q0;
    u32 zeros, rest;
    u64 product;

    n1 = numerator >> 32;
    n0 = numerator;
    d1 = divisor >> 32;
    d0 = divisor;
    if (d1 == 0) {
        if (d0 > n1) {
            /* One quotient word. */
            LEADING_ZEROS(zeros, d0);
            if (zeros != 0) {
                d0 <<= zeros;
                n1 = (n1 << zeros) | (n0 >> (32 - zeros));
                n0 <<= zeros;
            }
            DIVIDE_WORDS(q0, n1, n0, d0);
            q1 = 0;
        } else {
            /* Two quotient words. */
            if (d0 == 0) {
                d0 = 1 / d0; /* divide by zero on purpose */
            }
            LEADING_ZEROS(zeros, d0);
            if (zeros == 0) {
                /* n1 >= d0 and d0 has its top bit set: the high word is 1. */
                n1 -= d0;
                q1 = 1;
            } else {
                rest = 32 - zeros;
                d0 <<= zeros;
                n2 = n1 >> rest;
                n1 = (n1 << zeros) | (n0 >> rest);
                n0 <<= zeros;
                DIVIDE_WORDS(q1, n2, n1, d0);
                n1 = n2;
            }
            DIVIDE_WORDS(q0, n1, n0, d0);
        }
    } else if (d1 > n1) {
        /* The divisor exceeds the numerator. */
        q0 = 0;
        q1 = 0;
    } else {
        /* One quotient word, estimated from the top 64 bits. */
        LEADING_ZEROS(zeros, d1);
        if (zeros == 0) {
            q0 = (n1 > d1 || n0 >= d0) ? 1 : 0;
        } else {
            rest = 32 - zeros;
            d1 = (d1 << zeros) | (d0 >> rest);
            d0 <<= zeros;
            n2 = n1 >> rest;
            n1 = (n1 << zeros) | (n0 >> rest);
            n0 <<= zeros;
            DIVIDE_WORDS(q0, n2, n1, d1);
            product = (u64)q0 * d0;
            if ((u32)(product >> 32) > n2 || ((u32)(product >> 32) == n2 && (u32)product > n0)) {
                q0--;
            }
        }
        q1 = 0;
    }
    return ((u64)q1 << 32) | q0;
}
#else
INCLUDE_ASM("span_1000", func_802C0DA0_de);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802C1254);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", rodata_unresolved_802C1604);
#endif
