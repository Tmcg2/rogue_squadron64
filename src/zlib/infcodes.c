#include "common.h"

#include "zlib/infcodes.h"
#include "zlib/infutil.h"
#include "zlib/zutil.h"

/* simplify the use of the inflate_huft type with some defines */
#define base more.Base
#define next more.Next
#define exop word.what.Exop
#define bits word.what.Bits

inflate_codes_statef *inflate_codes_new(u32 bl, u32 bd, inflate_huft *tl, inflate_huft *td, z_stream *z) {
    inflate_codes_statef *c;

    if ((c = (inflate_codes_statef *) ZALLOC(z,1,sizeof(struct inflate_codes_state))) != Z_NULL) {
        c->mode = START;
        c->lbits = (u8)bl;
        c->dbits = (u8)bd;
        c->ltree = tl;
        c->dtree = td;
    }
    return c;
}

s32 inflate_codes(inflate_blocks_statef *s, z_stream *z, s32 r) {
    u32 j;               /* temporary storage */
    inflate_huft *t;      /* temporary pointer */
    u32 e;               /* extra bits or operation */
    u32 b;              /* bit buffer */
    u32 k;               /* bits in bit buffer */
    u8 *p;             /* input data pointer */
    u32 n;               /* bytes available there */
    u8 *q;             /* output window write pointer */
    u32 m;               /* bytes to end of window or read pointer */
    u8 *f;             /* pointer to copy strings from */
    inflate_codes_statef *c = s->sub.decode.codes;  /* codes state */

    /* copy input/output information to locals (UPDATE macro restores) */
    LOAD

    /* process input and output based on current state */
    while (1) switch (c->mode) {             /* waiting for "i:"=input, "o:"=output, "x:"=nothing */
        case START:         /* x: set up for LEN */
        if (m >= 258 && n >= 10) {
            UPDATE
            r = inflate_fast(c->lbits, c->dbits, c->ltree, c->dtree, s, z);
            LOAD
            if (r != Z_OK) {
                c->mode = r == Z_STREAM_END ? WASH : BADCODE;
                break;
            }
        }
        c->sub.code.need = c->lbits;
        c->sub.code.tree = c->ltree;
        c->mode = LEN;
        case LEN:           /* i: get length/literal/eob next */
            j = c->sub.code.need;
            NEEDBITS(j)
            t = c->sub.code.tree + ((u32)b & inflate_mask[j]);
            DUMPBITS(t->bits)
            e = (u32)(t->exop);
            if (e == 0) {               /* literal */
                c->sub.lit = t->base;
                c->mode = LIT;
                break;
            }
            if (e & 16) {               /* length */
                c->sub.copy.get = e & 15;
                c->len = t->base;
                c->mode = LENEXT;
                break;
            }
            if ((e & 64) == 0) {        /* next table */
                c->sub.code.need = e;
                c->sub.code.tree = t->next;
                break;
            }
            if (e & 32) {               /* end of block */
                c->mode = WASH;
                break;
            }
            c->mode = BADCODE;        /* invalid code */
            r = Z_DATA_ERROR;
            LEAVE
        case LENEXT:        /* i: getting length extra (have base) */
            j = c->sub.copy.get;
            NEEDBITS(j)
            c->len += (u32)b & inflate_mask[j];
            DUMPBITS(j)
            c->sub.code.need = c->dbits;
            c->sub.code.tree = c->dtree;
            c->mode = DIST;
        case DIST:          /* i: get distance next */
            j = c->sub.code.need;
            NEEDBITS(j)
            t = c->sub.code.tree + ((u32)b & inflate_mask[j]);
            DUMPBITS(t->bits)
            e = (u32)(t->exop);
            if (e & 16) {               /* distance */
                c->sub.copy.get = e & 15;
                c->sub.copy.dist = t->base;
                c->mode = DISTEXT;
                break;
            }
            if ((e & 64) == 0) {        /* next table */
                c->sub.code.need = e;
                c->sub.code.tree = t->next;
                break;
            }
            c->mode = BADCODE;        /* invalid code */
            r = Z_DATA_ERROR;
            LEAVE
        case DISTEXT:       /* i: getting distance extra */
            j = c->sub.copy.get;
            NEEDBITS(j)
            c->sub.copy.dist += (u32)b & inflate_mask[j];
            DUMPBITS(j)
            c->mode = COPY;
        case COPY:          /* o: copying bytes in window, waiting for space */
            f = (u32)(q - s->window) < c->sub.copy.dist ?
            s->end - (c->sub.copy.dist - (q - s->window)) :
            q - c->sub.copy.dist;
            while (c->len) {
                NEEDOUT
                OUTBYTE(*f++)
                if (f == s->end)
                f = s->window;
                c->len--;
            }
            c->mode = START;
            break;
        case LIT:           /* o: got literal, waiting for output space */
            NEEDOUT
            OUTBYTE(c->sub.lit)
            c->mode = START;
            break;
        case WASH:          /* o: got eob, possibly more output */
            FLUSH
            if (s->read != s->write)
            LEAVE
            c->mode = END;
        case END:
            r = Z_STREAM_END;
            LEAVE
        case BADCODE:       /* x: got error */
            r = Z_DATA_ERROR;
            LEAVE
        default:
            r = Z_STREAM_ERROR;
            LEAVE
    }
}

void inflate_codes_free(inflate_codes_statef *c, z_stream *z) {
    ZFREE(z, c);
}

INCLUDE_ASM("asm/nonmatchings/zlib/infcodes", fake_func_80028D58);

// DO NOT DELTE ME I AM REQUIRED FOR MATCHING
const u32 rodata_junk_infcodes[] = {
    0x0A446174,
    0x61207265,
    0x00000000,
    0x20000000,
};

// Most of this is junk, this is really the string "f5" with a bunch of leftover linker junk following it.
const u8 another_zlib_version[] = {
    0x66, 0x35, 0x00, 0x65, 0x61, 0x64, 0x20, 0x72
};
