#include "common.h"

#include "zlib/inffast.h"
#include "zlib/infutil.h"

/* simplify the use of the inflate_huft type with some defines */
#define base more.Base
#define next more.Next
#define exop word.what.Exop
#define bits word.what.Bits

/* macros for bit input with no checking and for returning unused bytes */
#define GRABBITS(j) {while(k<(j)){b|=((u32)NEXTBYTE)<<k;k+=8;}}
#define UNGRAB {n+=(c=k>>3);p-=c;k&=7;}

/* Called with number of bytes left to write in window at least 258
   (the maximum string length) and number of input bytes available
   at least ten.  The ten bytes are six bytes for the longest length/
   distance pair plus four bytes for overloading the bit buffer. */
#if 0
s32 inflate_fast(u32 bl, u32 bd, inflate_huft *tl, inflate_huft *td, inflate_blocks_statef *s, z_stream *z) {
    inflate_huft *t;      /* temporary pointer */
    u32 e;               /* extra bits or operation */
    u32 b;              /* bit buffer */
    u32 k;               /* bits in bit buffer */
    u8 *p;             /* input data pointer */
    u32 n;               /* bytes available there */
    u8 *q;             /* output window write pointer */
    u32 m;               /* bytes to end of window or read pointer */
    u32 ml;              /* mask for literal/length tree */
    u32 md;              /* mask for distance tree */
    u32 c;               /* bytes to copy */
    u32 d;               /* distance back to copy from */
    u8 *r;             /* copy source pointer */

    /* load input, output, bit values */
    LOAD

    /* initialize masks */
    // There's a register allocation issue here that I cannot for the life of me cannot make sense of
    // And, to rub it in, it matches on decomp.me :/ (similar to adler32, interestingly)
    // https://decomp.me/scratch/zrjMi
    ml = inflate_mask[bl];
    md = inflate_mask[bd];

    /* do until not enough input or output space for fast loop */
    do {                          /* assume called with m >= 258 && n >= 10 */
        /* get literal/length code */
        GRABBITS(20)                /* max bits for literal/length code */
        if ((e = (t = tl + ((u32)b & ml))->exop) == 0) {
            DUMPBITS(t->bits)
            *q++ = (u8)t->base;
            m--;
            continue;
        }
        do {
            DUMPBITS(t->bits)
            if (e & 16) {
                /* get extra bits for length */
                e &= 15;
                c = t->base + ((u32)b & inflate_mask[e]);
                DUMPBITS(e)

                /* decode distance base of block to copy */
                GRABBITS(15);           /* max bits for distance code */
                e = (t = td + ((u32)b & md))->exop;
                do {
                    DUMPBITS(t->bits)
                    if (e & 16) {
                        /* get extra bits to add to distance base */
                        e &= 15;
                        GRABBITS(e)         /* get extra bits (up to 13) */
                        d = t->base + ((u32)b & inflate_mask[e]);
                        DUMPBITS(e)

                        /* do the copy */
                        m -= c;
                        if ((u32)(q - s->window) >= d) {     /* offset before dest */
                            r = q - d;
                            *q++ = *r++;  c--;        /* minimum count is three, */
                            *q++ = *r++;  c--;        /*  so unroll loop a little */
                        }
                        else {                        /* else offset after destination */
                            e = d - (u32)(q - s->window); /* bytes from offset to end */
                            r = s->end - e;           /* pointer to offset */
                            if (c > e) {               /* if source crosses, */
                                c -= e;                 /* copy to end of window */
                                do {
                                *q++ = *r++;
                                } while (--e);
                                r = s->window;          /* copy rest from start of window */
                            }
                        }
                        do {                        /* copy all or what's left */
                            *q++ = *r++;
                        } while (--c);
                        break;
                    }
                    else if ((e & 64) == 0)
                    e = (t = t->next + ((u32)b & inflate_mask[e]))->exop;
                    else {
                        UNGRAB
                        UPDATE
                        return Z_DATA_ERROR;
                    }
                } while (1);
                break;
            }
            if ((e & 64) == 0) {
                if ((e = (t = t->next + ((u32)b & inflate_mask[e]))->exop) == 0) {
                    DUMPBITS(t->bits)
                    *q++ = (u8)t->base;
                    m--;
                    break;
                }
            }
            else if (e & 32) {
                UNGRAB
                UPDATE
                return Z_STREAM_END;
            }
            else {
                UNGRAB
                UPDATE
                return Z_DATA_ERROR;
            }
        } while (1);
    } while (m >= 258 && n >= 10);

    /* not enough input or output--restore pointers and return */
    UNGRAB
    UPDATE
    return Z_OK;
}
#else
INCLUDE_ASM("asm/nonmatchings/zlib/inffast", inflate_fast);
#endif

INCLUDE_ASM("asm/nonmatchings/zlib/inffast", fake_func_800290D8);
