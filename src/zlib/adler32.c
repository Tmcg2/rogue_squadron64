#include "common.h"

#include "PR/ultratypes.h"

#if 0
// This matches when compiling with GCC 2.7.2 SN 0001 on decompme, but doesn't match when compiled locally :(
#define BASE 65521L /* largest prime smaller than 65536 */
#define NMAX 5552
/* NMAX is the largest n such that 255n(n+1)/2 + (n+1)(BASE-1) <= 2^32-1 */

#define DO1(buf,i)  {s1 += buf[i]; s2 += s1;}
#define DO2(buf,i)  DO1(buf,i); DO1(buf,i+1);
#define DO4(buf,i)  DO2(buf,i); DO2(buf,i+2);
#define DO8(buf,i)  DO4(buf,i); DO4(buf,i+4);
#define DO16(buf)   DO8(buf,0); DO8(buf,8);
 
u32 adler32(u32 adler, u8* buf, u32 len) {
    u32 s1 = adler & 0xffff;
    u32 s2 = (adler >> 16) & 0xffff;
    s32 k;

    if (buf == ((void*)0)) return 1L;

    while (len > 0) {
        k = len < NMAX ? len : NMAX;
        len -= k;
        while (k >= 16) {
            DO16(buf);
	    buf += 16;
            k -= 16;
        }
        if (k != 0) do {
            s1 += *buf++;
	    s2 += s1;
        } while (--k);
        s1 %= BASE;
        s2 %= BASE;
    }
    return (s2 << 16) | s1;
}
#else
INCLUDE_ASM("asm/nonmatchings/zlib/adler32", adler32);
#endif

INCLUDE_ASM("asm/nonmatchings/zlib/adler32", fake_func_80026B98);
