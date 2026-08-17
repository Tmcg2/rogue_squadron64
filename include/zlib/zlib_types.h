#ifndef ZLIB_TYPES_H
#define ZLIB_TYPES_H

#include "PR/ultratypes.h"

typedef void *(*alloc_func)(void *opaque, u32 items, u32 size);
typedef void   (*free_func)(void *opaque, void *address);

struct internal_state;

typedef struct z_stream_s {
    u8    *next_in;  /* next input byte */
    u32     avail_in;  /* number of bytes available at next_in */
    u32    total_in;  /* total nb of input bytes read so far */

    u8    *next_out; /* next output byte should be put there */
    u32     avail_out; /* remaining free space at next_out */
    u32    total_out; /* total nb of bytes output so far */

    char     *msg;      /* last error message, NULL if no error */
    struct internal_state *state; /* not visible by applications */

    alloc_func zalloc;  /* used to allocate the internal state */
    free_func  zfree;   /* used to free the internal state */
    void     *opaque;  /* private data object passed to zalloc and zfree */

    s32     data_type;  /* best guess about the data type: ascii or binary */
    u32   adler;      /* adler32 value of the uncompressed data */
    u32   reserved;   /* reserved for future use */
} z_stream;

/* ===========================================================================
 * Internal compression state.
 */

#define LENGTH_CODES 29
/* number of length codes, not counting the special END_BLOCK code */

#define LITERALS  256
/* number of literal bytes 0..255 */

#define L_CODES (LITERALS+1+LENGTH_CODES)
/* number of Literal or Length codes, including the END_BLOCK code */

#define D_CODES   30
/* number of distance codes */

#define BL_CODES  19
/* number of codes used to transfer the bit lengths */

#define HEAP_SIZE (2*L_CODES+1)
/* maximum heap size */

#define MAX_BITS 15
/* All codes must not exceed MAX_BITS bits */

#define INIT_STATE    42
#define BUSY_STATE   113
#define FINISH_STATE 666
/* Stream status */


/* Data structure describing a single value and its code string. */
typedef struct ct_data_s {
    union {
        u16  freq;       /* frequency count */
        u16  code;       /* bit string */
    } fc;
    union {
        u16  dad;        /* father node in Huffman tree */
        u16  len;        /* length of bit string */
    } dl;
} ct_data;

#define Freq fc.freq
#define Code fc.code
#define Dad  dl.dad
#define Len  dl.len

typedef struct static_tree_desc_s  static_tree_desc;

typedef struct tree_desc_s {
    ct_data *dyn_tree;           /* the dynamic tree */
    s32     max_code;            /* largest code with non zero frequency */
    static_tree_desc *stat_desc; /* the corresponding static tree */
} tree_desc;

typedef u16 Pos;
typedef Pos Posf;
typedef unsigned IPos;

/* A Pos is an index in the character window. We use short instead of s32 to
 * save space in the various tables. IPos is used only for parameter passing.
 */

typedef struct internal_state {
    z_stream *strm;      /* pointer back to this zlib stream */
    s32   status;        /* as the name implies */
    u8 *pending_buf;  /* output still pending */
    u8 *pending_out;  /* next pending byte to output to the stream */
    s32   pending;       /* nb of bytes in the pending buffer */
    s32   noheader;      /* suppress zlib header and adler32 */
    u8  data_type;     /* UNKNOWN, BINARY or ASCII */
    u8  method;        /* STORED (for zip only) or DEFLATED */
    s32   last_flu16;    /* value of flu16 param for previous deflate call */

                /* used by deflate.c: */

    u32  w_size;        /* LZ77 window size (32K by default) */
    u32  w_bits;        /* log2(w_size)  (8..16) */
    u32  w_mask;        /* w_size - 1 */

    u8 *window;
    /* Sliding window. Input bytes are read into the second half of the window,
     * and move to the first half later to keep a dictionary of at least wSize
     * bytes. With this organization, matches are limited to a distance of
     * wSize-MAX_MATCH bytes, but this ensures that IO is always
     * performed with a length multiple of the block size. Also, it limits
     * the window size to 64K, which is quite useful on MSDOS.
     * To do: use the user input buffer as sliding window.
     */

    u32 window_size;
    /* Actual size of window: 2*wSize, except when the user input buffer
     * is directly used as sliding window.
     */

    Posf *prev;
    /* Link to older string with same hash index. To limit the size of this
     * array to 64K, this link is maintained only for the last 32K strings.
     * An index in this array is thus a window index modulo 32K.
     */

    Posf *head; /* Heads of the hash chains or NIL. */

    u32  ins_h;          /* hash index of string to be inserted */
    u32  hash_size;      /* number of elements in hash table */
    u32  hash_bits;      /* log2(hash_size) */
    u32  hash_mask;      /* hash_size-1 */

    u32  hash_shift;
    /* Number of bits by which ins_h must be shifted at each input
     * step. It must be su8 that after MIN_MATCH steps, the oldest
     * byte no longer takes part in the hash key, that is:
     *   hash_shift * MIN_MATCH >= hash_bits
     */

    u32 block_start;
    /* Window position at the beginning of the current output block. Gets
     * negative when the window is moved backwards.
     */

    u32 match_length;           /* length of best match */
    IPos prev_match;             /* previous match */
    s32 match_available;         /* set if previous match exists */
    u32 strstart;               /* start of string to insert */
    u32 match_start;            /* start of matching string */
    u32 lookahead;              /* number of valid bytes ahead in window */

    u32 prev_length;
    /* Length of the best match at previous step. Matches not greater than this
     * are discarded. This is used in the lazy match evaluation.
     */

    u32 max_chain_length;
    /* To speed up deflation, hash chains are never searched beyond this
     * length.  A higher limit improves compression ratio but degrades the
     * speed.
     */

    u32 max_lazy_match;
    /* Attempt to find a better match only when the current match is strictly
     * smaller than this value. This mechanism is used only for compression
     * levels >= 4.
     */
#   define max_insert_length  max_lazy_match
    /* Insert new strings in the hash table only if the match length is not
     * greater than this length. This saves time but degrades compression.
     * max_insert_length is used only for compression levels <= 3.
     */

    s32 level;    /* compression level (1..9) */
    s32 strategy; /* favor or force Huffman coding*/

    u32 good_match;
    /* Use a faster search when the previous match is longer than this */

    s32 nice_match; /* Stop searching when current match exceeds this */

                /* used by trees.c: */
    /* Didn't use ct_data typedef below to supress compiler warning */
    struct ct_data_s dyn_ltree[HEAP_SIZE];   /* literal and length tree */
    struct ct_data_s dyn_dtree[2*D_CODES+1]; /* distance tree */
    struct ct_data_s bl_tree[2*BL_CODES+1];  /* Huffman tree for bit lengths */

    struct tree_desc_s l_desc;               /* desc. for literal tree */
    struct tree_desc_s d_desc;               /* desc. for distance tree */
    struct tree_desc_s bl_desc;              /* desc. for bit length tree */

    u16 bl_count[MAX_BITS+1];
    /* number of codes at each bit length for an optimal tree */

    s32 heap[2*L_CODES+1];      /* heap used to build the Huffman trees */
    s32 heap_len;               /* number of elements in the heap */
    s32 heap_max;               /* element of largest frequency */
    /* The sons of heap[n] are heap[2*n] and heap[2*n+1]. heap[0] is not used.
     * The same heap array is used to build all trees.
     */

    u8 depth[2*L_CODES+1];
    /* Depth of each subtree used as tie breaker for trees of equal frequency
     */

    u8 *l_buf;          /* buffer for literals or lengths */

    u32  lit_bufsize;
    /* Size of match buffer for literals/lengths.  There are 4 reasons for
     * limiting lit_bufsize to 64K:
     *   - frequencies can be kept in 16 bit counters
     *   - if compression is not successful for the first block, all input
     *     data is still in the window so we can still emit a stored block even
     *     when input comes from standard input.  (This can also be done for
     *     all blocks if lit_bufsize is not greater than 32K.)
     *   - if compression is not successful for a file smaller than 64K, we can
     *     even emit a stored file instead of a stored block (saving 5 bytes).
     *     This is applicable only for zip (not gzip or zlib).
     *   - creating new Huffman trees less frequently may not provide fast
     *     adaptation to changes in the input data statistics. (Take for
     *     example a binary file with poorly compressible code followed by
     *     a highly compressible string table.) Smaller buffer sizes give
     *     fast adaptation but have of course the overhead of transmitting
     *     trees more frequently.
     *   - I can't count above 4
     */

    u32 last_lit;      /* running index in l_buf */

    u16 *d_buf;
    /* Buffer for distances. To simplify the code, d_buf and l_buf have
     * the same number of elements. To use different lengths, an extra flag
     * array would be necessary.
     */

    u32 opt_len;        /* bit length of current block with optimal trees */
    u32 static_len;     /* bit length of current block with static trees */
    u32 compressed_len; /* total bit length of compressed file */
    u32 matches;       /* number of string matches in current block */
    s32 last_eob_len;   /* bit length of EOB code for last block */

#ifdef DEBUG
    u32 bits_sent;      /* bit length of the compressed data */
#endif

    u16 bi_buf;
    /* Output buffer. bits are inserted starting at the bottom (least
     * significant bits).
     */
    s32 bi_valid;
    /* Number of valid bits in bi_buf.  All bits above the last valid bit
     * are always zero.
     */

} deflate_state;

#endif
