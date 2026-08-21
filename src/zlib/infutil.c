#include "common.h"

#include "zlib/zlib.h"
#include "zlib/infutil.h"
#include "zlib/forward_declares.h"

/* And'ing with mask[n] masks the lower n bits */
u32 inflate_mask[17] = {
    0x0000,
    0x0001, 0x0003, 0x0007, 0x000f, 0x001f, 0x003f, 0x007f, 0x00ff,
    0x01ff, 0x03ff, 0x07ff, 0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff
};

// DO NOT DELETE ME I AM REQUIRED FOR MATCHING
u32 data_junk_infutil[] = {
    0xAE200004,
    0xAE200008,
    0x0800E3DD,
};

/* copy as much as possible from the sliding window to the output area */
s32 inflate_flush(inflate_blocks_statef *s, z_stream *z, s32 r) {
    u32 n;
    u8 *p;
    u8 *q;

    /* local copies of source and destination pointers */
    p = z->next_out;
    q = s->read;

    /* compute number of bytes to copy as far as end of window */
    n = (u32)((q <= s->write ? s->write : s->end) - q);
    if (n > z->avail_out) n = z->avail_out;
    if (n && r == Z_BUF_ERROR) r = Z_OK;

    /* update counters */
    z->avail_out -= n;
    z->total_out += n;

    /* update check information */
    if (s->checkfn != Z_NULL) z->adler = s->check = (*s->checkfn)(s->check, q, n);

    /* copy as far as end of window */
    zmemcpy(p, q, n);
    p += n;
    q += n;

    /* see if more to copy at beginning of window */
    if (q == s->end) {
        /* wrap pointers */
        q = s->window;
        if (s->write == s->end) s->write = s->window;

        /* compute bytes to copy */
        n = (u32)(s->write - q);
        if (n > z->avail_out) n = z->avail_out;
        if (n && r == Z_BUF_ERROR) r = Z_OK;

        /* update counters */
        z->avail_out -= n;
        z->total_out += n;

        /* update check information */
        if (s->checkfn != Z_NULL) z->adler = s->check = (*s->checkfn)(s->check, q, n);

        /* copy */
        zmemcpy(p, q, n);
        p += n;
        q += n;
    }

    /* update pointers */
    z->next_out = p;
    s->read = q;

    /* done */
    return r;
}

extern u8 another_zlib_version[];

u8 *func_main_80029CC0(void) {
    return &another_zlib_version;
}
